#pragma once
#include "FileUtil.h"
#include "CSVFileManager.h"
#include "ProjectDataSetBinder.h"
#include "OutputSummary.h"
#include "NetworkComponent.h"
#include <string>



using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::IO;
using namespace Microsoft::Office::Interop;


/// <summary>
/// UNIST Helper 클래스
/// </summary>
namespace WinformProject {
	public ref class UNISTHelper
	{
	private:
		FileUtil^ m_fileUtil;
		String^ m_basePath;
		ProjectDataSetBinder^ m_dataSet;
		String^ cvsTempFileName;

	public:
		UNISTHelper(ProjectDataSetBinder^ dataSet) {
			this->m_dataSet = dataSet;
			this->m_fileUtil = gcnew FileUtil();
			this->m_basePath = "C:\\sample\\UNIST\\";
			this->cvsTempFileName = "dummy.csv";

		}

		// create new datatable object by columns information
		DataTable^ NewTable(array<String^>^ columns) {
			DataTable^ table = gcnew DataTable();
			// define fields
			for each (String ^ col in columns)
			{
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}

		/*사용안함
			csv -> xlsx 로 넘어가면서 컬럼 분리가 안됨*/
		void ConvertCsvToXlsx(String^ filePath) {
			Excel::Workbook^ wb = nullptr;
			try {
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();

				wb = exApp->Workbooks->Open(m_basePath + cvsTempFileName, 0, true, 5, "", "", true, Excel::XlPlatform::xlWindows, "\t", false, false, 0, true, 1, 0);
				
				wb->SaveAs(m_basePath + filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not read file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};

		}

		//시설물별 손상단계(1~4단계)

		/*
		bool WriteBridgeFragilityCurve(String^ filename) {

			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {
				//파일 확인

				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);
				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.


				//Data 저장.
				DataTable^ dtNetComp = this->m_dataSet->NetworkCompnentData;
				for (int i = 0; i < dtNetComp->Rows->Count; i++) {
					//String^ sCompId = dtNetComp->Rows[i][NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					//String^ sClassId = dtNetComp->Rows[i][NetworkComponent::COL_CLASS_ID]->ToString();
					String^ sCompId = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ sClassId = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_CLASS_ID]->ToString();

					Debug::WriteLine("=================>sCompId[" + i + "]:" + sCompId);
					Debug::WriteLine("=================>sClassId["+i+"]:" + sClassId);

					//COL_CLASS_ID 별 FragParameterData
					array<DataRow^>^ foundRows = this->m_dataSet->FragParameterData->Select(String::Format("[{0}]='{1}'", CommConst::GRID_FRAG_CURVE_PARAM_COL1, sClassId));
					
					//for (int j = 0; j < foundRows->Length; j++) {
					//	DataRow^ tempRow = foundRows[j];
					//	String^ sFragCurveParam1 = foundRows[j][0]->ToString();
					//	String^ sFragCurveParam2 = foundRows[j][1]->ToString();
					//	String^ sFragCurveParam3 = foundRows[j][2]->ToString();
					//	String^ sFragCurveParam4 = foundRows[j][3]->ToString();
					//	String^ sFragCurveParam5 = foundRows[j][4]->ToString();
					//	String^ sFragCurveParam6 = foundRows[j][5]->ToString();
					//	String^ sFragCurveParam7 = foundRows[j][6]->ToString();
					//	String^ sFragCurveParam8 = foundRows[j][7]->ToString();
					//	String^ sFragCurveParam9 = foundRows[j][8]->ToString();
					//	Debug::WriteLine("=================>sFragCurveParam1:" + sFragCurveParam1);
					//	Debug::WriteLine("=================>sFragCurveParam2:" + sFragCurveParam2);
					//	Debug::WriteLine("=================>sFragCurveParam3:" + sFragCurveParam3);
					//	Debug::WriteLine("=================>sFragCurveParam4:" + sFragCurveParam4);
					//	Debug::WriteLine("=================>sFragCurveParam5:" + sFragCurveParam5);
					//	Debug::WriteLine("=================>sFragCurveParam6:" + sFragCurveParam6);
					//	Debug::WriteLine("=================>sFragCurveParam7:" + sFragCurveParam7);
					//	Debug::WriteLine("=================>sFragCurveParam8:" + sFragCurveParam8);
					//	Debug::WriteLine("=================>sFragCurveParam9:" + sFragCurveParam9);
					//}

					//AiParameters 세팅
					if (foundRows->Length > 0) {
						String^ sAiParameters1 = foundRows[0][1]->ToString();
						String^ sAiParameters2 = foundRows[0][3]->ToString();
						String^ sAiParameters3 = foundRows[0][5]->ToString();
						String^ sAiParameters4 = foundRows[0][7]->ToString();

						iExcelRow++;
						//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
						ws->Cells[iExcelRow, 1] = sAiParameters1;
						ws->Cells[iExcelRow, 2] = sAiParameters2;
						ws->Cells[iExcelRow, 3] = sAiParameters3;
						ws->Cells[iExcelRow, 4] = sAiParameters4;
					}


					
				}


				//row 수가 262개 보다 작으면
				int iExcelRow = dtNetComp->Rows->Count;
				Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
				for (int i = iExcelRow; iExcelRow <= CommConst::UNIST_RUN_REQ_ROWS; iExcelRow++) {
					//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
					ws->Cells[iExcelRow, 1] = "5";
					ws->Cells[iExcelRow, 2] = "5";
					ws->Cells[iExcelRow, 3] = "5";
					ws->Cells[iExcelRow, 4] = "5";
				}

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};


			return true;
		}

		*/



		bool WriteBridgeFragilityCurve(String^ filename) {

			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^> (CommConst::DAMAGE_STATE_COUNT);
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;


			DataTable^ dtNetComp = this->m_dataSet->NetworkCompnentData;
			for (int i = 0; i < dtNetComp->Rows->Count; i++) {
				newRow = newTable->NewRow(); // create new row
				// 시설물별 Class 확인
				String^ sCompId = dtNetComp->Rows[i][NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
				String^ sClassId = dtNetComp->Rows[i][NetworkComponent::COL_CLASS_ID]->ToString();

				// Class 정보(평균값 확인 및 시설물에 할당)
				array<DataRow^>^ foundRows = this->m_dataSet->FragParameterData->Select(String::Format("[{0}]='{1}'", CommConst::GRID_FRAG_CURVE_PARAM_COL1, sClassId));
				newRow[0] = foundRows[0][1]->ToString();
				newRow[1] = foundRows[0][3]->ToString();
				newRow[2] = foundRows[0][5]->ToString();
				newRow[3] = foundRows[0][7]->ToString();

				newTable->Rows->Add(newRow);
			}

			return csv->Write(newTable);

		}

		//시설물 위치.
		/*
		bool WriteLocationBr(String^ filename) {
			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {
				

				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				DataTable^ dtNetComp = this->m_dataSet->NetworkCompnentData;
				for (int i = 0; i < dtNetComp->Rows->Count; i++) {
					String^ sCompId = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ sClassId = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_CLASS_ID]->ToString();
					String^ sX = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_X]->ToString();
					String^ sY = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_Y]->ToString();
		
					Debug::WriteLine("=================>sCompId[" + i + "]:" + sCompId);
					Debug::WriteLine("=================>sClassId[" + i + "]:" + sClassId);
					Debug::WriteLine("=================>sX[" + i + "]:" + sX);
					Debug::WriteLine("=================>sY[" + i + "]:" + sY);

					iExcelRow++;
					//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
					ws->Cells[iExcelRow, 1] = sX;
					ws->Cells[iExcelRow, 2] = sY;

				}

				//row 수가 262개 보다 작으면
				int iExcelRow = dtNetComp->Rows->Count;
				Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
				for (int i = iExcelRow; iExcelRow <= CommConst::UNIST_RUN_REQ_ROWS; iExcelRow++) {
					//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
					ws->Cells[iExcelRow, 1] = "0";
					ws->Cells[iExcelRow, 2] = "0";
				}

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};


			return true;
		}
		*/


		bool WriteLocationBr(String^ filename) {

			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(2); // x coord, y coord
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;

			//Data 저장.
			DataTable^ dtNetComp = this->m_dataSet->NetworkCompnentData;
			for (int i = 0; i < dtNetComp->Rows->Count; i++) {
				newRow = newTable->NewRow(); // create new row

				String^ sCompId = dtNetComp->Rows[i][NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
				String^ sClassId = dtNetComp->Rows[i][NetworkComponent::COL_CLASS_ID]->ToString();
				String^ sX = dtNetComp->Rows[i][NetworkComponent::COL_X]->ToString();
				String^ sY = dtNetComp->Rows[i][NetworkComponent::COL_Y]->ToString();

				newRow[0] = sX;
				newRow[1] = sY;
				newTable->Rows->Add(newRow);
			}

			return csv->Write(newTable);
		}




		//지진 진원지 위치 좌표

		/*
		bool WriteLocationEq(String^ filename) {
			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {


				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				Dictionary<String^, DataTable^>^  dicSeismicSourceDictionary = this->m_dataSet->SeismicSourceDictionary;
				Debug::WriteLine(String::Format("========>Count[{0}]", dicSeismicSourceDictionary->Count));
				if (dicSeismicSourceDictionary->Count > 0) {
					List<String^>^ list = gcnew List<String^>(dicSeismicSourceDictionary->Keys);
					String^ sSourceName = list[0];//SeismicSourceDictionary 에서 첫번째 값을 가져옴.
					Debug::WriteLine(String::Format("========>sSourceName[{0}]", sSourceName));


					DataTable^ dtSeismicSourceContent = this->m_dataSet->SeismicSourceContentDictionary[sSourceName];
					int iRowCnt = dtSeismicSourceContent->Rows->Count;
					Debug::WriteLine(String::Format("========>iRowCnt[{0}]", iRowCnt));
					double dXCoord = 0.0;
					double dYCoord = 0.0;
					double dSumXCoord = 0.0;
					double dSumYCoord = 0.0;

					for (int i = 0; i < iRowCnt; i++) {
						Double::TryParse(dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL1]->ToString(), dXCoord);
						Double::TryParse(dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL2]->ToString(), dYCoord);
						//double^ d1000 = dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL6]->ToString();

						Debug::WriteLine(String::Format("========>dXCoord[{0}]", dXCoord));
						Debug::WriteLine(String::Format("========>dYCoord[{0}]", dYCoord));

						dSumXCoord += dXCoord;
						dSumYCoord += dYCoord;
						Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
						Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));
					}


					iExcelRow++;
					//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
					dSumXCoord = dSumXCoord / iRowCnt;
					dSumYCoord = dSumYCoord / iRowCnt;
					Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
					Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));

					//소숫점 3자리 반올림.
					dSumXCoord = Math::Round(dSumXCoord * 1000) / 1000;
					dSumYCoord = Math::Round(dSumYCoord * 1000) / 1000;
					Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
					Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));

					ws->Cells[iExcelRow, 1] = dSumXCoord.ToString();
					ws->Cells[iExcelRow, 2] = dSumYCoord.ToString();

				}
				

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};


			return true;
		}
		*/

		bool WriteLocationEq(String^ filename, String^ sSourceName) {
			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(2); // x coor 및 y coord
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = newTable->NewRow(); // create new row

			DataTable^ dtSeismicSourceContent = this->m_dataSet->SeismicSourceContentDictionary[sSourceName];
			int iRowCnt = dtSeismicSourceContent->Rows->Count;
			Debug::WriteLine(String::Format("========>iRowCnt[{0}]", iRowCnt));
			double dXCoord = 0.0;
			double dYCoord = 0.0;
			double dSumXCoord = 0.0;
			double dSumYCoord = 0.0;

			for (int i = 0; i < iRowCnt; i++) {
				Double::TryParse(dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL1]->ToString(), dXCoord);
				Double::TryParse(dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL2]->ToString(), dYCoord);
				//double^ d1000 = dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL6]->ToString();

				Debug::WriteLine(String::Format("========>dXCoord[{0}]", dXCoord));
				Debug::WriteLine(String::Format("========>dYCoord[{0}]", dYCoord));

				dSumXCoord += dXCoord;
				dSumYCoord += dYCoord;
				Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
				Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));
			}


			dSumXCoord = dSumXCoord / iRowCnt;
			dSumYCoord = dSumYCoord / iRowCnt;
			Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
			Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));

			//소숫점 3자리 반올림.
			dSumXCoord = Math::Round(dSumXCoord * 1000) / 1000;
			dSumYCoord = Math::Round(dSumYCoord * 1000) / 1000;
			Debug::WriteLine(String::Format("========>dSumXCoord[{0}]", dSumXCoord));
			Debug::WriteLine(String::Format("========>dSumYCoord[{0}]", dSumYCoord));


			newRow[0] = dSumXCoord.ToString();
			newRow[1] = dSumYCoord.ToString();
			newTable->Rows->Add(newRow);


		return csv->Write(newTable);

		}


		//지진 진원지 강도.

		/*
		bool WriteMEq(String^ filename) {

			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {


				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				Dictionary<String^, DataTable^>^ dicSeismicSourceDictionary = this->m_dataSet->SeismicSourceDictionary;
				Debug::WriteLine(String::Format("========>Count[{0}]", dicSeismicSourceDictionary->Count));
				if (dicSeismicSourceDictionary->Count > 0) {
					List<String^>^ list = gcnew List<String^>(dicSeismicSourceDictionary->Keys);
					String^ sSourceName = list[0];//SeismicSourceDictionary 에서 첫번째 값을 가져옴.
					Debug::WriteLine(String::Format("========>sSourceName[{0}]", sSourceName));


					DataTable^ dtSeismicSourceContent = this->m_dataSet->SeismicSourceContentDictionary[sSourceName];
					int iRowCnt = dtSeismicSourceContent->Rows->Count;
					Debug::WriteLine(String::Format("========>iRowCnt[{0}]", iRowCnt));
					double d1000Year = 0.0;
					double dSum1000Year = 0.0;

					for (int i = 0; i < iRowCnt; i++) {
						Double::TryParse(dtSeismicSourceContent->Rows[i][CommConst::GRID_SEISMIC_SOURCES_COL6]->ToString(), d1000Year);
					
						Debug::WriteLine(String::Format("========>d1000Year[{0}]", d1000Year));
			
						dSum1000Year += d1000Year;
						Debug::WriteLine(String::Format("========>dSum1000Year[{0}]", dSum1000Year));
					}


					iExcelRow++;
					//Debug::WriteLine("=================>iExcelRow:" + iExcelRow);
					dSum1000Year = dSum1000Year / iRowCnt;
					Debug::WriteLine(String::Format("========>dSum1000Year[{0}]", dSum1000Year));

					//소숫점 1자리 반올림.
					dSum1000Year = Math::Round(dSum1000Year * 10) / 10;
					Debug::WriteLine(String::Format("========>dSum1000Year[{0}]", dSum1000Year));

					ws->Cells[iExcelRow, 1] = dSum1000Year.ToString();

				}


				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};


			return true;
		}
		*/

		bool WriteMEq(String^ filename, String^ sSourceName, String^ recurrencePeriod) {

			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(1); // 1개의 진원지 지진강도
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = newTable->NewRow(); // create new row

			DataTable^ dtSeismicSourceContent = this->m_dataSet->SeismicSourceContentDictionary[sSourceName];
			int iRowCnt = dtSeismicSourceContent->Rows->Count;
			Debug::WriteLine(String::Format("========>iRowCnt[{0}]", iRowCnt));
			double intensity = 0.0;
			double aveageIntensity = 0.0;

			for (int i = 0; i < iRowCnt; i++) {
				Double::TryParse(dtSeismicSourceContent->Rows[i][recurrencePeriod]->ToString(), intensity);
				aveageIntensity += intensity;
			}

			//평균 및 소숫점 1자리 반올림.
			aveageIntensity = Math::Round(aveageIntensity / iRowCnt * 10) / 10;

			newRow[0] = aveageIntensity;
			newTable->Rows->Add(newRow);

			return csv->Write(newTable);
		}


		//도로시설물 복구일수는 피해규모에 따라 WinformProject에서는 0/7/150/450로 되어 있으며,
		//최대 복구기간 일수는 최대값+50 (예. 500=450+50)으로 셋팅

		/*
		bool WriteMaxday(String^ filename) {
			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {


				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				iExcelRow++;

				int iMaxDays = 450;
				int iRecoverDays = iMaxDays + 50;
				Debug::WriteLine(String::Format("=================>iRecoverDays[{0}]", iRecoverDays));
				ws->Cells[iExcelRow, 1] = iRecoverDays.ToString();

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};
			return true;
		}
		*/

		bool WriteMaxday(String^ filename) {
			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(1); // 1개의 max day
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = newTable->NewRow(); // create new row

			int additionalRecoveryDay = 20;
			int recoveryDayRefernce = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + additionalRecoveryDay;

			newRow[0] = recoveryDayRefernce;
			newTable->Rows->Add(newRow);

			return csv->Write(newTable);

		}


		//default값인 3000을 사용
		/*
		bool WriteNoSamples(String^ filename) {

			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {


				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				iExcelRow++;

				ws->Cells[iExcelRow, 1] = "3000";

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};

			return true;
		}
		*/

		bool WriteNoSamples(String^ filename) {
			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(1); // 1개의 max day
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = newTable->NewRow(); // create new row
			
			//default값인 3000을 사용
			int totalSampleNumber = 500;

			newRow[0] = totalSampleNumber;
			newTable->Rows->Add(newRow);

			return csv->Write(newTable);
		}



		/*
		bool WriteRestorationDays(String^ filename) {

			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;

			Excel::Workbook^ wb = nullptr;
			Excel::Worksheet^ ws = nullptr;

			int iExcelRow = 0;
			try {


				//엑셀 생성
				Excel::Application^ exApp = gcnew Excel::ApplicationClass();
				wb = exApp->Workbooks->Add(true);
				ws = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);

				exApp->DisplayAlerts = false;//덮어쓰기 메세지 없애기.

				//Data 저장.
				iExcelRow++;

				ws->Cells[iExcelRow, 1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
				ws->Cells[iExcelRow, 2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
				ws->Cells[iExcelRow, 3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
				ws->Cells[iExcelRow, 4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;

				//엑셀 파일 저장
				wb->SaveAs(filePath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Excel::XlSaveAsAccessMode::xlNoChange, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);

			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not write file.");
			}
			finally {
				if (wb != nullptr) {
					wb->Close(false, filePath, nullptr);
				}
			};

			return true;
		}
		*/


		bool WriteRestorationDays(String^ filename) {
			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			array<String^>^ columns = gcnew array<String^>(CommConst::DAMAGE_STATE_COUNT);
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = newTable->NewRow(); // create new row
		
			newRow[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
			newRow[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
			newRow[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
			newRow[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
			newTable->Rows->Add(newRow);

			return csv->Write(newTable);	
		}


		bool WriteOD(String^ filename, int ODindex) {
			// CSV파일 입출력 준비
			String^ filePath = m_basePath + filename;
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			DataTable^ dummyTable = this->m_dataSet->ODZoneParamData;
			DataRow^ dummyRow = dummyTable->Rows[ODindex - 1]; 

			DataTable^ newTable = dummyTable->Clone(); 
			DataRow^ newRow = newTable->NewRow(); // create new row

			newRow[0] = dummyRow[0];
			newRow[1] = dummyRow[1];
			newTable->Rows->Add(newRow);

			return csv->Write(newTable);
		}

		// read output  file

		/*
		System::Data::DataTable^ ReadOutputFile(String^ filename, String^ scenarioKey) {
			Debug::WriteLine("=================>filename:" + filename);
			String^ filePath = m_basePath + filename;
			int totalColumnNumber = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
			array<String^>^ columns = gcnew array<String^>(totalColumnNumber);
			for (int i = 0; i < totalColumnNumber; i++) {
				columns[i] = "A" + String::Format("{0}", i);
			}
			
			array<String^>^ columns = {
			"A001","A002","A003","A004","A005","A006","A007","A008","A009","A010"
			,"A011","A012","A013","A014","A015","A016","A017","A018","A019","A020"
			,"A021","A022","A023","A024","A025","A026","A027","A028","A029","A030"
			,"A031","A032","A033","A034","A035","A036","A037","A038","A039","A040"
			,"A041","A042","A043","A044","A045","A046","A047","A048","A049","A050"
			,"A051","A052","A053","A054","A055","A056","A057","A058","A059","A060"
			,"A061","A062","A063","A064","A065","A066","A067","A068","A069","A070"
			,"A071","A072","A073","A074","A075","A076","A077","A078","A079","A080"
			,"A081","A082","A083","A084","A085","A086","A087","A088","A089","A090"
			,"A091","A092","A093","A094","A095","A096","A097","A098","A099","A100"
			,"A101","A102","A103","A104","A105","A106","A107","A108","A109","A110"
			,"A111","A112","A113","A114","A115","A116","A117","A118","A119","A120"
			,"A121","A122","A123","A124","A125","A126","A127","A128","A129","A130"
			,"A131","A132","A133","A134","A135","A136","A137","A138","A139","A140"
			,"A141","A142","A143","A144","A145","A146","A147","A148","A149","A150"
			,"A151","A152","A153","A154","A155","A156","A157","A158","A159","A160"
			,"A161","A162","A163","A164","A165","A166","A167","A168","A169","A170"
			,"A171","A172","A173","A174","A175","A176","A177","A178","A179","A180"
			,"A181","A182","A183","A184","A185","A186","A187","A188","A189","A190"
			,"A191","A192","A193","A194","A195","A196","A197","A198","A199","A200"
			,"A201","A202","A203","A204","A205","A206","A207","A208","A209","A210"
			,"A211","A212","A213","A214","A215","A216","A217","A218","A219","A220"
			,"A221","A222","A223","A224","A225","A226","A227","A228","A229","A230"
			,"A231","A232","A233","A234","A235","A236","A237","A238","A239","A240"
			,"A241","A242","A243","A244","A245","A246","A247","A248","A249","A250" };

			System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(filePath, columns );
			
			return dt;
		}
		*/

		System::Data::DataTable^ ReadOutputFile(String^ filename, String^ scenarioKey) {

			String^ filePath = m_basePath + filename;
			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			String^ output = csv->Read();

			array<String^>^ dummyOutput = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
			String^ outputSummary = dummyOutput[0]; // 1줄만 생성되므로
			array<String^>^ trafficStatus = CSVFileManager::Parse(outputSummary, ",");

			this->m_dataSet->TrafficVolumeStatus->Add(scenarioKey, trafficStatus); //시나리오별 교통복구 현황 저장



			int totalColumnNumber = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
			array<String^>^ columns = gcnew array<String^>(totalColumnNumber);
			for (int i = 0; i < totalColumnNumber; i++) {
				columns[i] = "A" + String::Format("{0}", i);
			}

			System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(filePath, columns);


			return dt;
		}


	};

}