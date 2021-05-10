#pragma once
#include "PolyObject.h"
#include "ShapeProperty.h"
#include "ShapeNode.h"
#include "DBFColumnInfo.h"

/* -------------------------------------------------------------------- */
/*      Shape types (nSHPType)                                          */
/* -------------------------------------------------------------------- */
#define SHPT_NULL	0
#define SHPT_POINT	1
#define SHPT_ARC	3
#define SHPT_POLYGON	5
#define SHPT_MULTIPOINT	8
#define SHPT_POINTZ	11
#define SHPT_ARCZ	13
#define SHPT_POLYGONZ	15
#define SHPT_MULTIPOINTZ 18
#define SHPT_POINTM	21
#define SHPT_ARCM	23
#define SHPT_POLYGONM	25
#define SHPT_MULTIPOINTM 28
#define SHPT_MULTIPATCH 31

using namespace System;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Data::OleDb;
using namespace System::IO;

namespace WinformProject {
	/// <summary>
	/// Shaep files(shp, shx, dbf) data class
	/// </summary>
	[Serializable]
	public ref class Shape : ICloneable
	{
	public:
		String^									m_strSHPPath;				//Name of SHP file
		String^									m_strSHXPath;				//Name of SHX file

		int										m_nRecords;					// Number of Record
		int										m_nShapeType;				/* SHPT_* */
		MBR										m_MBR;						// Minimum Bounding Rectangle

		array<GeoPoint>^						m_pSHPPoints;				// Real GeoPoint for SHPT_POINT
		array<PolyObject>^						m_pSHPPolyObjects;			// Real PolyObject for SHPT_ARC, SHPT_POLYGON, SHPT_MULTIPOINT
		array<ShapeProperty^>^					m_SHPProperties;			// feature link properties
		Dictionary<String^, int>^				m_SHPPropertiesIndexes;		// link properties index map<linkID, link property index>
		Dictionary<String^, ShapeNode^>^		m_SHPNodes;					// nodes<nodePoint(x, y), nodeInfo>
		Dictionary<String^, array<String^>^>^	m_SHPLinkMap;				// linkMap<linkID, nodeID>
		Dictionary<String^, array<ShapeNode^>^>^ m_SHPZones;				// zoneMap<zoneID, ShapeNodes>

		bool									m_bOpen;					// To check whether SHP is Opened or not

		// Apparance 
		int										m_lineType;					// SHP LineType
		int										m_lineWidth;				// SHP LineWidth

		// Display 
		double									m_lfMainRatio;				// 전체 화면 대 지도 비율
		double									m_lfZoomFactor;				// 확대/축소 비율
		GeoPoint								m_geoCenterPoint;			// 지도 중심 점
		System::Drawing::Point					m_scrCenterPoint;			// 화면 중심 점
	private:
		virtual Object^ C() sealed = ICloneable::Clone{
			return this->Clone();
		}
	public:
		Shape() {
			m_SHPZones = gcnew Dictionary<String^, array<ShapeNode^>^>();
			m_SHPPropertiesIndexes = gcnew Dictionary<String^, int>();
		}

		// change byte ordering
		void SwapWord(int _length, void* _pWord) {
			int i;
			unsigned char temp;

			for (i = 0; i < _length / 2; i++)
			{
				temp = ((unsigned char *)_pWord)[i];
				((unsigned char *)_pWord)[i] = ((unsigned char *)_pWord)[_length - i - 1];
				((unsigned char *)_pWord)[_length - i - 1] = temp;
			}
		}

		// file open
		bool Open(String^ _filename) {
			int tmp, i, j;

			tmp = _filename->Length - 4;
			String^ _withoutExtension = _filename->Substring(0, _filename->LastIndexOf(L".shp"));
			String^ _pureFilename = System::IO::Path::GetFileNameWithoutExtension(_filename);
			String^ _shxFilename = _withoutExtension + L".shx";
			String^ _dbfFilename = _withoutExtension + L".dbf";

			// 3가지 파일(shp, shx, dbf)을 모두 읽기
			BinaryReader^ fpSHP = nullptr;
			BinaryReader^ fpSHX = nullptr;
			BinaryReader^ fpDBF = nullptr;
			try
			{
				//open SHP/SHX/DBF file
				fpSHP = gcnew BinaryReader(File::Open(_filename, FileMode::Open));
				fpSHX = gcnew BinaryReader(File::Open(_shxFilename, FileMode::Open));
				fpDBF = gcnew BinaryReader(File::Open(_dbfFilename, FileMode::Open));

				/*
				1. 0 (길이:1바이트) : 정확한 dBase III+ 파일인지 여부(03h이면 메모파일이 없는 DBF파일이고, 83h이면 메모파일이 있는 DBF 파일)
				2. 1-3 (3) : YYMMDD 형식의 최종 갱신 일자.
				3. 4-7 (4) : 테이블 내의 전체 레코드 개수.
				4. 8-9 (2) : 헤더의 바이트 수.
				5. 10-11 (2) : 레코드의 바이트 수.
				6. 12-14 (3) : 예약된 바이트(건너뛰면 됩니다).
				7. 15-27 (13) : LAN을 위한 dBase III+를 위해 예약된 바이트(역시 건너뜁니다).
				8. 28-31 (4) : 예약된 바이트(건너뛰면 됩니다).
				9. 32-n (n*32) : 각각의 컬럼들을 설명하기 위한 32바이트.
				10. n+1 (1) : 헤더의 끝을 알리는 0Dh.

				1번에서 8번까지는 전체 DBF 파일에 대한 정보이고, 9번은 각 컬럼별 정보가 되겠는데요, 이것은 다음과 같습니다.

				1. 0-10 (11) : ASCII 형식의 컬럼명(이후는 00h로 채워집니다).
				2. 11 (1) : ASCII 형식의 컬럼 타입(C/D/L/M/N 중의 하나입니다).
				3. 12-15 (4) : 컬럼 항목의 주소(잘 쓰이지 않으므로 건너뜁니다).
				4. 16 (1) : 컬럼값의 최대 길이.
				5. 17 (1) : 컬럼의 개수라는데, 역시 건너뛰어도 무방합니다.
				6. 18-19 (2) : LAN을 위한 dBase III+를 위해 예약된 바이트(건너뜁니다).
				7. 20 (1) : 작업 영역의 ID(건너뜁니다).
				8. 21-22 (2) : LAN을 위한 dBase III+를 위해 예약된 바이트(건너뜁니다).
				9. 23 (1) : SET FIELDS 플래그(건너뜁니다).
				10. 24-31 (8) : 예약된 바이트(건너뜁니다).

				출처: https://inthelife.tistory.com/456
				*/

				if (fpDBF != nullptr) {
					// read dbf(properties)
					fpDBF->BaseStream->Seek(4L, SeekOrigin::Begin);
					int recordCount = fpDBF->ReadUInt32(); // Get record(row) count
					int headerSize = fpDBF->ReadUInt16();
					int recordSize = fpDBF->ReadUInt16();
					int columnCount = (headerSize - 32) / 32;
					array<DBFColumnInfo>^ columns = gcnew array<DBFColumnInfo>(columnCount);

					// get column information as such as the number of columns.
					for (int i = 0; i < columnCount; i++)
					{
						fpDBF->BaseStream->Seek(32 + (i * 32), SeekOrigin::Begin);
						DBFColumnInfo columnInfo;
						columnInfo.Name = System::Text::Encoding::Default->GetString(fpDBF->ReadBytes(11))->Replace("\0", "");
						columnInfo.Type = fpDBF->ReadByte();
						fpDBF->ReadInt32();
						columnInfo.MaxLength = fpDBF->ReadByte();
						columnInfo.Count = fpDBF->ReadByte();
						columns[i] = columnInfo;
					}
					Debug::WriteLine(String::Format("header size = {0:d}", headerSize));
					Debug::WriteLine(String::Format("record count = {0:d}", recordCount));
					Debug::WriteLine(String::Format("one record size = {0:d}", recordSize));
					Debug::WriteLine(String::Format("column count = {0:d}", columnCount));
					if (recordCount > 0) {
						// init properties
						m_SHPProperties = gcnew array<ShapeProperty^>(recordCount);
						fpDBF->BaseStream->Seek(headerSize, SeekOrigin::Begin);
						for (int i = 0; i < m_SHPProperties->Length; i++)
						{
							// there is a data.
							if (fpDBF->ReadByte() == 0x20) {
								ShapeProperty^ p = gcnew ShapeProperty();
								for each(DBFColumnInfo colInfo in columns)
								{
									if (colInfo.Name == "LENGTH") {
										String^ value = System::Text::Encoding::Default->GetString(fpDBF->ReadBytes(colInfo.MaxLength))->Replace(" ", "");
										double doubleValue = double::Parse(value) / 1000; //m단위를 km단위로 변환
										String^ stringValue = String::Format("{0}", doubleValue);
										p->SetProperty(colInfo.Name, doubleValue);
									}
									else {
										String^ value = System::Text::Encoding::Default->GetString(fpDBF->ReadBytes(colInfo.MaxLength))->Replace(" ", "");
										p->SetProperty(colInfo.Name, value);
									}
								}
								m_SHPProperties[i] = p;
							}
							// create link index map
							m_SHPPropertiesIndexes->Add(m_SHPProperties[i]->ID, i);
						}
					}
				}

				if (fpSHP == nullptr || fpSHX == nullptr)
				{
					Debug::WriteLine(L"SHP File Error!!");
					return false;
				}

				// 파일을 읽었다면, 그냥 기존 파일데이터를 사용
				if (m_bOpen) {
					return true;
				}

				/*
					// reference
					// 구조정보: http://blog.naver.com/PostView.nhn?blogId=ilsan_ilsan&logNo=221491473647&parentCategoryNo=&categoryNo=153&viewDate=&isShowPopularPosts=false&from=postView
					// GeoJSON converter: https://mygeodata.cloud/converter/shp-to-geojson
					.shp: 공간 정보
					.shx: shp의 인덱스 정보
					.dbf: 속성 정보

					// struct
							 .shp     .shx     .dbf
					header    100     100      32
					rec 1
					rec 2
					rec 3
				*/

				/* Now read a Header of SHP/SHX */
				/*
					#################################################
					SHP file structure
					#################################################
					File Header(100Byte)
					Record Header(8Byte)
					Record Contents(가변Byte)
					Record Header(8Byte)
					Record Contents(가변Byte)
					.
					Record Header(8Byte)
					Record Contents(가변Byte)

					======================================================
					File Header
					======================================================
					Position   Field        Value       Type    Byte Order
					------------------------------------------------------
					Byte 0     File Code    9994        Integer Big
					Byte 4     Unused       0           Integer Big
					Byte 8     Unused       0           Integer Big
					Byte 12    Unused       0           Integer Big
					Byte 16    Unused       0           Integer Big
					Byte 20    Unused       0           Integer Big
					Byte 24    File Length  File Length Integer Big
					Byte 28    Version      1000        Integer Little
					Byte 32    Shape Type   Shape Type  Integer Little
					Byte 36    Bounding Box Xmin        Double  Little
					Byte 44    Bounding Box Ymin        Double  Little
					Byte 52    Bounding Box Xmax        Double  Little
					Byte 60    Bounding Box Ymax        Double  Little
					Byte 68*   Bounding Box Zmin        Double  Little
					Byte 76*   Bounding Box Zmax        Double  Little
					Byte 84*   Bounding Box Mmin        Double  Little
					Byte 92*   Bounding Box Mmax        Double  Little
					------------------------------------------------------
					* Unused, with value 0.0, if not Measured or Z type

					======================================================
					Record Header
					======================================================
					Position   Field        Value       Type    Byte Order
					------------------------------------------------------
					Byte 0     Record Number  Record Number  Integer Big   : Record Number는 dbf에 들어있는 각 객체와 속성정보 사이를 연결하는 키값
					Byte 4     Content Length Content Length Integer Big
					------------------------------------------------------

					======================================================
					Record Contents
					======================================================
					Position   Field        Value       Type    Byte Order
					------------------------------------------------------
					Byte 0     Shape Type   5          Integer   Little
					Byte 4     Box          Box	       Double    Little
					Byte 36    NumParts     NumParts   Integer   Little
					Byte 40    NumPoints    NumPoints  Integer   Little
					Byte 44    Parts        Parts      Integer   Little
					Byte X     Points       Points     Point     Little
					------------------------------------------------------
					* X = 44 + (4 * NumParts)

					#################################################
					SHX file structure
					#################################################
					======================================================
					File Header
					======================================================
					* SHX header same 100-byte header as the .SHP file

					======================================================
					Record Contents
					======================================================
					Position   Field        Value       Type    Byte Order
					------------------------------------------------------
					Byte 0     Offset         Offset         Integer   Big
					Byte 4     Content Length Content Length Integer   Big
					------------------------------------------------------
				*/

				fpSHX->BaseStream->Seek(24L, SeekOrigin::Begin);
				tmp = fpSHX->ReadInt32(); // Get File size & Number of records
				SwapWord(4, &tmp); // Byte Order Changing

				int m_nFileSize = tmp * 2;	// get file size
				m_nRecords = (m_nFileSize - 100) / 8;	//get a number of records

				// get shp type
				fpSHP->BaseStream->Seek(32L, SeekOrigin::Begin);
				m_nShapeType = fpSHP->ReadInt32();


				// get a MBR 
				m_MBR.xmin = fpSHP->ReadDouble();
				m_MBR.ymin = fpSHP->ReadDouble();
				m_MBR.xmax = fpSHP->ReadDouble();
				m_MBR.ymax = fpSHP->ReadDouble();

				// Check a invalid shp type
				if (!(m_nShapeType == SHPT_POINT || m_nShapeType == SHPT_ARC || m_nShapeType == SHPT_POLYGON || m_nShapeType == SHPT_MULTIPOINT))
				{
#ifdef DEBUG
					Debug::WriteLine(L"Invalid SHP Type.\nThis program only support Point, Arc, Polygon & MultiPoint SHP Type.");
#endif // DEBUG
					return false;
				}

				m_SHPNodes = gcnew Dictionary<String^, ShapeNode^>();
				m_SHPLinkMap = gcnew Dictionary<String^, array<String^>^>();
				// real routine of feature reading(point, arc, polygon, multipoint)
				switch (m_nShapeType)
				{
					// 포인트를 읽어들인다.
				case SHPT_POINT:
					m_pSHPPoints = gcnew array<GeoPoint>(m_nRecords);

					for (i = 0; i < m_nRecords; ++i)
					{
						fpSHX->BaseStream->Seek(100 + i * 8, SeekOrigin::Begin);
						tmp = fpSHX->ReadInt32();
						SwapWord(4, &tmp);
						tmp = tmp * 2;

						fpSHP->BaseStream->Seek(tmp + 12, SeekOrigin::Begin);
						m_pSHPPoints[i].x = fpSHP->ReadDouble();
						m_pSHPPoints[i].y = fpSHP->ReadDouble();
					}
					break;

					// 폴리라인과 폴리곤을 읽어들인다.
				case SHPT_ARC:
				case SHPT_POLYGON:
					m_pSHPPolyObjects = gcnew array<PolyObject>(m_nRecords);
					for (i = 0; i < m_nRecords; ++i)
					{
						fpSHX->BaseStream->Seek(100 + i * 8, SeekOrigin::Begin);
						tmp = fpSHX->ReadInt32();
						SwapWord(4, &tmp);
						tmp = tmp * 2;

						fpSHP->BaseStream->Seek(tmp + 12, SeekOrigin::Begin);
						//get MBR
						m_pSHPPolyObjects[i].MBR.xmin = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.ymin = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.xmax = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.ymax = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].nNumParts = fpSHP->ReadInt32(); //get parts number
						m_pSHPPolyObjects[i].nNumPoints = fpSHP->ReadInt32(); //get points number

						m_pSHPPolyObjects[i].arrParts = gcnew array<int>(m_pSHPPolyObjects[i].nNumParts);
						m_pSHPPolyObjects[i].arrPoints = gcnew array<GeoPoint>(m_pSHPPolyObjects[i].nNumPoints);

						for (j = 0; j < m_pSHPPolyObjects[i].nNumParts; ++j) {
							m_pSHPPolyObjects[i].arrParts[j] = fpSHP->ReadInt32();
						}

						for (j = 0; j < m_pSHPPolyObjects[i].nNumPoints; ++j) {
							m_pSHPPolyObjects[i].arrPoints[j].x = fpSHP->ReadDouble();
							m_pSHPPolyObjects[i].arrPoints[j].y = fpSHP->ReadDouble();
						}

						/// generate node information
						// link's start point and end point are nodes
						array<GeoPoint>^ tempGeoPoints = gcnew array<GeoPoint>(2); // [0] = startGeoPoint, [1] = endGeoPoint
						tempGeoPoints[0] = m_pSHPPolyObjects[i].arrPoints[0];
						tempGeoPoints[1] = m_pSHPPolyObjects[i].arrPoints[m_pSHPPolyObjects[i].nNumPoints - 1];

						// 시작과 끝에 연결된 link를 찾아야하므로 노드별로 2번 실행
						for (j = 0; j < tempGeoPoints->Length; j++)
						{
							// 노드의 위치를 key 값으로 node를 등록
							String^ key = String::Format("{0} {1}", tempGeoPoints[j].x, tempGeoPoints[j].y);

							// 등록된 노드가 없을 경우 새로 추가
							if (!m_SHPNodes->ContainsKey(key)) {
								ShapeNode^ node = gcnew ShapeNode();
								String^ nodeID = String::Format("{0}", m_SHPNodes->Count + 1);
								node->ID = nodeID;
								GeoPoint _location = { tempGeoPoints[j].x, tempGeoPoints[j].y };
								node->Location = _location;
								m_SHPNodes->Add(key, node);

								// TODO: zone을 추가(현재는 특별한 기능이 없어서 노드와 존을 노드아이디 기준으로 1:1 맵핑 
								array<ShapeNode^>^ nodes = { node };
								m_SHPZones->Add(nodeID, nodes);
							}
							// connected link 목록에 연결된 link index 추가
							m_SHPNodes[key]->AddConnectedLinkIndex(i);
							Debug::WriteLine(String::Format("LinkIndex={0} Key={1} NodeID={2} LinkCount={3}", i, key, m_SHPNodes[key]->ID, m_SHPNodes[key]->ConnectedLinkIndexes->Length));
						}
						Debug::WriteLine(String::Format("Node count={0}", m_SHPNodes->Count));
					}
					/// add link's nodes
					for each (KeyValuePair<String^, ShapeNode^>^ pair in m_SHPNodes)
					{
						// node
						ShapeNode^ nodeInfo = pair->Value;

						Debug::WriteLine(String::Format("NODE: ID={0}", nodeInfo->ID));
						// node에 연결된 link 찾기
						for each (int linkIndex in nodeInfo->ConnectedLinkIndexes)
						{
							// 연결된 link의 node를 업데이트 
							if (m_SHPProperties[linkIndex]->Nodes[0] == nullptr) {
								m_SHPProperties[linkIndex]->Nodes[0] = nodeInfo;
							}
							else {
								m_SHPProperties[linkIndex]->Nodes[1] = nodeInfo;
							}
							Debug::WriteLine(String::Format("\tLINK: IDX={0}, ID={1}, NODES={2} ~ {3}"
								, linkIndex, m_SHPProperties[linkIndex]->GetProperty(ShapeProperty::PropertyType::LINK_ID)
								, (m_SHPProperties[linkIndex]->Nodes[0] != nullptr) ? m_SHPProperties[linkIndex]->Nodes[0]->ID : ""
								, (m_SHPProperties[linkIndex]->Nodes[1] != nullptr) ? m_SHPProperties[linkIndex]->Nodes[1]->ID : ""));
						}
					}
					// Debug log ///////////////////////////////////
					i = 0;
					for each (ShapeProperty^ prop in m_SHPProperties)
					{
						Debug::WriteLine(String::Format("LINK: IDX={0}, ID={1}, NODES={2} ~ {3}"
							, i++, prop->GetProperty(ShapeProperty::PropertyType::LINK_ID)
							, (prop->Nodes[0] != nullptr) ? prop->Nodes[0]->ID : ""
							, (prop->Nodes[1] != nullptr) ? prop->Nodes[1]->ID : ""));
					}
					////////////////////////////////////////////////
					break;

					// 다중점을 읽어들인다.
				case SHPT_MULTIPOINT:
					m_pSHPPolyObjects = gcnew array<PolyObject>(m_nRecords);

					for (i = 0; i < m_nRecords; ++i)
					{
						fpSHX->BaseStream->Seek(100 + i * 8, SeekOrigin::Begin);
						tmp = fpSHX->ReadInt64();
						SwapWord(4, &tmp);
						tmp = tmp * 2;

						fpSHP->BaseStream->Seek(tmp + 12, SeekOrigin::Begin);
						//get MBR
						m_pSHPPolyObjects[i].MBR.xmin = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.ymin = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.xmax = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].MBR.ymax = fpSHP->ReadDouble();
						m_pSHPPolyObjects[i].nNumPoints = fpSHP->ReadInt32(); //get points number

						m_pSHPPolyObjects[i].arrPoints = gcnew array<GeoPoint>(m_pSHPPolyObjects[i].nNumPoints);

						for (j = 0; j < m_pSHPPolyObjects[i].nNumPoints; ++j) {
							m_pSHPPolyObjects[i].arrPoints[j].x = fpSHP->ReadDouble();
							m_pSHPPolyObjects[i].arrPoints[j].y = fpSHP->ReadDouble();
						}
					}
					break;
				}

				m_geoCenterPoint.x = (m_MBR.xmax + m_MBR.xmin) / 2;
				m_geoCenterPoint.y = (m_MBR.ymax + m_MBR.ymin) / 2;

				m_bOpen = true;
			}
			catch (Exception^ e)
			{
				throw e;
			}
			finally
			{
				if (fpSHX != nullptr) {
					fpSHX->Close();
				}
				if (fpSHP != nullptr) {
					fpSHP->Close();
				}
				if (fpDBF != nullptr) {
					fpDBF->Close();
				}
			}
			return true;
		}

		virtual Shape^ Clone() {
			Shape^ shape = gcnew Shape();
			shape->m_bOpen = this->m_bOpen;
			shape->m_geoCenterPoint = this->m_geoCenterPoint;
			shape->m_strSHPPath = this->m_strSHPPath;
			shape->m_strSHXPath = this->m_strSHXPath;
			shape->m_nRecords = this->m_nRecords;
			shape->m_nShapeType = this->m_nShapeType;
			shape->m_MBR = this->m_MBR;
			shape->m_pSHPPoints = this->m_pSHPPoints;
			shape->m_pSHPPolyObjects = this->m_pSHPPolyObjects;
			shape->m_SHPProperties = this->m_SHPProperties;
			shape->m_SHPNodes = this->m_SHPNodes;
			shape->m_SHPLinkMap = this->m_SHPLinkMap;
			shape->m_SHPZones = this->m_SHPZones;
			shape->m_SHPPropertiesIndexes = this->m_SHPPropertiesIndexes;
			shape->m_bOpen = this->m_bOpen;
			shape->m_lineType = this->m_lineType;
			shape->m_lineWidth = this->m_lineWidth;
			shape->m_lfMainRatio = this->m_lfMainRatio;
			shape->m_lfZoomFactor = this->m_lfZoomFactor;
			shape->m_geoCenterPoint = this->m_geoCenterPoint;
			shape->m_scrCenterPoint = this->m_scrCenterPoint;
			return shape;
		}
	};
}
