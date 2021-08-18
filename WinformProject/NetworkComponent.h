#pragma once
#include "CommonHeader.h"
#include "ComponentInfo.h"
#include "ComponentClassInfo.h"
#include "ProjectDataSetBinder.h"
#include "ExcelUtil.h"


using namespace System;
using namespace System::Data;
using namespace System::Diagnostics;

namespace WinformProject {
	/// <summary>
	/// NetworkComponent class
	/// </summary>
	public ref class NetworkComponent
	{
	public:
		// define network component grid column index
		literal int COL_NETWORK_COMP_ID = 0;
		literal int COL_CLASS_ID = 1;
		literal int COL_X = 2;
		literal int COL_Y = 3;
		literal int COL_LINK_ID = 4;
		literal int COL_RECONSTRUCTION_COST = 5;


		//literal int COL_SOIL_TYPE = 6;//토질형식
		//literal int COL_FUNDAMENTAL_PERIOD = 7;//고유주기

		//엑셀변경으로 추가
		literal int COL_UPPER_TYPE = 6;//상부형식
		literal int COL_CONTINUITY = 7;//연속성
		literal int COL_BRIDGE_HEIGHT = 8;//교고
		literal int COL_SPAN_LENGTH = 9;//경간장
		literal int COL_SPAN_COUNT = 10;//경간수
		literal int COL_CAR_BREADTH = 11;//차폭
		literal int COL_BOTTOM_TYPE = 12;//하부구조
		literal int COL_ELASTOMERIC_SHOE = 13;//교좌
		literal int COL_BRIDGE_FOUNDATION = 14;//기초
		literal int COL_SEISMIC_DESIGN_YN = 15;//내진설계여부
		literal int COL_OLD_BRIDGE = 16;//노후도(교각)
		literal int COL_OLD_SHOE = 17;//노후도(교좌)
		literal int COL_REPAIR_BRIDGE = 18;//보수보강(교각)
		literal int COL_REPAIR_SHOE = 19;//보수보강(교좌)
		literal int COL_GROUND_TYPE = 20;//지반종류
		literal int COL_SOIL_TYPE = 21;//토질형식
		literal int COL_FUNDAMENTAL_PERIOD = 22;//고유주기
	
		literal int COL_23 = 23;//터널분류
		literal int COL_24 = 24;//지진취약도 표준형식
		literal int COL_25 = 25;//토층 vs 범위	
		literal int COL_26 = 26;//노후도
		literal int COL_27 = 27;//구조물 분류	
		literal int COL_28 = 28;//지진취약도 표준형식1   
		literal int COL_29 = 29;//지진취약도 표준형식2 
		literal int COL_30 = 30;//구조물 지진피해   
		literal int COL_31 = 31;//입력지진파 산정	  
		literal int COL_32 = 32;//사면 경사도	      
		literal int COL_33 = 33;//사면 점착력       
		literal int COL_34 = 34;//교량명	          
		literal int COL_35 = 35;//시공자명	        
		literal int COL_36 = 36;//준공일자	        
		literal int COL_37 = 37;//설계활하중        
		literal int COL_38 = 38;//내진설계적용여부	
		literal int COL_39 = 39;//총길이/경간구성	  	
		literal int COL_40 = 40;//폭_계             	
		literal int COL_41 = 41;//(교량)대표경간형식	
		literal int COL_42 = 42;//(교량)대표받침종류
		literal int COL_43 = 43;//(교량)대표교각형식
		literal int COL_44 = 44;//(교량)대표교각기초
		literal int COL_45 = 45;//(터널)공법대표	  
		literal int COL_46 = 46;//(사면)높이	      
		literal int COL_47 = 47;//(사면)경사	      
		literal int COL_48 = 48;//(사면)구성재료	  
		literal int COL_49 = 49;//(옹벽)최대높이	  
		literal int COL_50 = 50;//(옹벽)재료        









	private:
		DataTable^					m_dataTable;
		DataTable^					m_componentClassdataTable;
		array<Drawing::Color>^		m_componentColors;


		Dictionary<String^, DataTable^>^ m_structureDamageStatus; //시설물 지진시나리오별 피해결과 저장


	public:
		// Data
		property DataTable^ Data {
			System::Data::DataTable^ get() {
				return this->m_dataTable;
			}
		}


		property Dictionary<String^, DataTable^>^ StructureDamageStatus {
			Dictionary<String^, DataTable^>^ get() {
				return this->m_structureDamageStatus;
			}
			void set(Dictionary<String^, DataTable^>^ value) {
				this->m_structureDamageStatus = value;
			}
		}

	






/*
	public:
		NetworkComponent() {
			m_dataTable = gcnew System::Data::DataTable();
		}
		NetworkComponent(ProjectDataSetBinder^ dataSet) {
			this->m_dataTable = dataSet->NetworkCompnentData;
		}
*/

	public:
		NetworkComponent() {
			init(nullptr);
		}
		NetworkComponent(ProjectDataSetBinder^ dataSet) {
			init(dataSet);

			this->m_structureDamageStatus = gcnew Dictionary<String^, DataTable^>();

		}


	private:
		void init(ProjectDataSetBinder^ dataSet) {
			if (dataSet != nullptr) {
				this->m_dataTable = dataSet->NetworkCompnentData;
				this->m_componentClassdataTable = dataSet->ComponentClassData;
			}
			else {
				this->m_dataTable = gcnew System::Data::DataTable();
				this->m_componentClassdataTable = gcnew System::Data::DataTable();
			}
			this->m_componentColors = gcnew array<Drawing::Color>(10);
			this->m_componentColors[0] = Drawing::Color::Red;
			this->m_componentColors[1] = Drawing::Color::AliceBlue;
			this->m_componentColors[2] = Drawing::Color::Aquamarine;
			this->m_componentColors[3] = Drawing::Color::DarkOrange;
			this->m_componentColors[4] = Drawing::Color::DarkGreen;
			this->m_componentColors[5] = Drawing::Color::DeepPink;
			this->m_componentColors[6] = Drawing::Color::LightSalmon;
			this->m_componentColors[7] = Drawing::Color::BurlyWood;
			this->m_componentColors[8] = Drawing::Color::DarkKhaki;
			this->m_componentColors[9] = Drawing::Color::DarkGoldenrod;
		}

	public:

		void ReadFile(String^ filepath) {
			this->m_dataTable = ExcelUtil::ExcelToDataTableUseColumnIndex(filepath, 1);

			//시설물 구분 세팅
			SetClassId();
		}

		/** 시설물 구분 세팅 **/
		void SetClassId() {
			
			DataTable^ dtNetComp = this->m_dataTable;
			for (int i = 0; i < dtNetComp->Rows->Count; i++) {

				/*CLASS ID*/
				String^ STR_CLASS_ID = "";
				
				
				String^ STR_6 = dtNetComp->Rows[i][NetworkComponent::COL_UPPER_TYPE]->ToString();//구조물분류


				String^ STR_23 = dtNetComp->Rows[i][NetworkComponent::COL_23]->ToString();//터널분류
				String^ STR_24 = dtNetComp->Rows[i][NetworkComponent::COL_24]->ToString();//지진취약도 표준형식
				String^ STR_25 = dtNetComp->Rows[i][NetworkComponent::COL_25]->ToString();//토층 vs 범위	
				String^ STR_26 = dtNetComp->Rows[i][NetworkComponent::COL_26]->ToString();//노후도
				String^ STR_27 = dtNetComp->Rows[i][NetworkComponent::COL_27]->ToString();//구조물 분류	
				String^ STR_28 = dtNetComp->Rows[i][NetworkComponent::COL_28]->ToString();//지진취약도 표준형식1   
				String^ STR_29 = dtNetComp->Rows[i][NetworkComponent::COL_29]->ToString();//지진취약도 표준형식2
				String^ STR_30 = dtNetComp->Rows[i][NetworkComponent::COL_30]->ToString();//구조물 지진피해           
				String^ STR_31 = dtNetComp->Rows[i][NetworkComponent::COL_31]->ToString();//입력지진파 산정	          
				String^ STR_32 = dtNetComp->Rows[i][NetworkComponent::COL_32]->ToString();//사면 경사도	              
				String^ STR_33 = dtNetComp->Rows[i][NetworkComponent::COL_33]->ToString();//사면 점착력               
				String^ STR_34 = dtNetComp->Rows[i][NetworkComponent::COL_34]->ToString();//교량명	                  
				String^ STR_35 = dtNetComp->Rows[i][NetworkComponent::COL_35]->ToString();//시공자명	                
				String^ STR_36 = dtNetComp->Rows[i][NetworkComponent::COL_36]->ToString();//준공일자	                
				String^ STR_37 = dtNetComp->Rows[i][NetworkComponent::COL_37]->ToString();//설계활하중                
				String^ STR_38 = dtNetComp->Rows[i][NetworkComponent::COL_38]->ToString();//내진설계적용여부	        
				String^ STR_39 = dtNetComp->Rows[i][NetworkComponent::COL_39]->ToString();//총길이/경간구성	          
				String^ STR_40 = dtNetComp->Rows[i][NetworkComponent::COL_40]->ToString();//폭_계                     
				String^ STR_41 = dtNetComp->Rows[i][NetworkComponent::COL_41]->ToString();//(교량)대표경간형식	      
				String^ STR_42 = dtNetComp->Rows[i][NetworkComponent::COL_42]->ToString();//(교량)대표받침종류	      
				String^ STR_43 = dtNetComp->Rows[i][NetworkComponent::COL_43]->ToString();//(교량)대표교각형식	      
				String^ STR_44 = dtNetComp->Rows[i][NetworkComponent::COL_44]->ToString();//(교량)대표교각기초        
				String^ STR_45 = dtNetComp->Rows[i][NetworkComponent::COL_45]->ToString();//(터널)공법대표	          
				String^ STR_46 = dtNetComp->Rows[i][NetworkComponent::COL_46]->ToString();//(사면)높이	              
				String^ STR_47 = dtNetComp->Rows[i][NetworkComponent::COL_47]->ToString();//(사면)경사	              
				String^ STR_48 = dtNetComp->Rows[i][NetworkComponent::COL_48]->ToString();//(사면)구성재료	          
				String^ STR_49 = dtNetComp->Rows[i][NetworkComponent::COL_49]->ToString();//(옹벽)최대높이	          
				String^ STR_50 = dtNetComp->Rows[i][NetworkComponent::COL_50]->ToString();//(옹벽)재료                
				


				/*
				String^ STR_23 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_23]->ToString();//터널분류
				String^ STR_24 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_24]->ToString();//지진취약도 표준형식
				String^ STR_25 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_25]->ToString();//토층 vs 범위
				String^ STR_26 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_26]->ToString();//노후도
				String^ STR_27 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_27]->ToString();//구조물 분류
				String^ STR_28 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_28]->ToString();//지진취약도 표준형식1
				String^ STR_29 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_29]->ToString();//지진취약도 표준형식2
				String^ STR_30 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_30]->ToString();//구조물 지진피해
				String^ STR_31 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_31]->ToString();//입력지진파 산정
				String^ STR_32 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_32]->ToString();//사면 경사도
				String^ STR_33 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_33]->ToString();//사면 점착력
				String^ STR_34 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_34]->ToString();//교량명
				String^ STR_35 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_35]->ToString();//시공자명
				String^ STR_36 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_36]->ToString();//준공일자
				String^ STR_37 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_37]->ToString();//설계활하중
				String^ STR_38 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_38]->ToString();//내진설계적용여부
				String^ STR_39 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_39]->ToString();//총길이/경간구성
				String^ STR_40 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_40]->ToString();//폭_계
				String^ STR_41 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_41]->ToString();//(교량)대표경간형식
				String^ STR_42 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_42]->ToString();//(교량)대표받침종류
				String^ STR_43 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_43]->ToString();//(교량)대표교각형식
				String^ STR_44 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_44]->ToString();//(교량)대표교각기초
				String^ STR_45 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_45]->ToString();//(터널)공법대표
				String^ STR_46 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_46]->ToString();//(사면)높이
				String^ STR_47 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_47]->ToString();//(사면)경사
				String^ STR_48 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_48]->ToString();//(사면)구성재료
				String^ STR_49 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_49]->ToString();//(옹벽)최대높이
				String^ STR_50 = dtNetComp->Rows[i]->ItemArray[NetworkComponent::COL_50]->ToString();//(옹벽)재료
				*/


				/******** 터널 *******/
				//if (!StringUtil::isNull(STR_23)) {//터널
				if (STR_6->ToString() ==  "Mined/Bored" || STR_6->ToString() == "Cut-and-cover") {//터널

					/*터널분류*/
					Debug::WriteLine("=================>STR_23[" + i + "]:" + STR_23);
					//if (STR_23->StartsWith("cut")) {
					if (STR_6->StartsWith("cut")) {
							STR_CLASS_ID += "CC1";
					}
					else {
						STR_CLASS_ID += "MB0";
					}

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*지진취약도 표준형식*/
					Debug::WriteLine("=================>STR_24[" + i + "]:" + STR_24);
					if (STR_24->StartsWith("PGV")) {
						STR_CLASS_ID += "1";
					}
					if (STR_24->StartsWith("PGA")) {
						STR_CLASS_ID += "2";
					}
					if (STR_24->StartsWith("PGV/")) {
						STR_CLASS_ID += "3";
					}

					
					/*토층 vs 범위	*/
					Debug::WriteLine("=================>STR_25[" + i + "]:" + STR_25);
					if (STR_25->StartsWith("Soil B")) {
						STR_CLASS_ID += "000B";
					}
					else if (STR_25->StartsWith("Soil C")) {
						STR_CLASS_ID += "000C";
					}
					else if (STR_25->StartsWith("Soil D")) {
						STR_CLASS_ID += "000D";
					}
					else {

						String^ strValue = StringUtil::nullToString(STR_25, "0");
						int iVal = Convert::ToInt32(strValue);
						if (iVal >= 250 && iVal < 350) {
							STR_CLASS_ID += "0001";
						}
						else if (iVal >= 350 && iVal < 450) {
							STR_CLASS_ID += "0002";
						}
						else if (iVal >= 450 && iVal < 550) {
							STR_CLASS_ID += "0003";
						}
						else if (iVal >= 550 && iVal < 650) {
							STR_CLASS_ID += "0004";
						}
						else if (iVal >= 650 && iVal < 750) {
							STR_CLASS_ID += "0005";
						}
						else if (iVal >= 750 && iVal < 850) {
							STR_CLASS_ID += "0006";
						}
						else if (iVal >= 850 && iVal < 950) {
							STR_CLASS_ID += "0007";
						}
						else {
							STR_CLASS_ID += "0000";
						}
						

					}
					
					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*노후도*/
					Debug::WriteLine("=================>STR_26[" + i + "]:" + STR_26);
					STR_CLASS_ID += STR_26;



				}
				/******** 사면,옹벽 *******/
				//else if (!StringUtil::isNull(STR_27)) {//사면,옹벽

				else if (STR_6->ToString() == "S" || STR_6->ToString() == "R") {//사면, 옹벽


					/*구조물 분류*/ 
					//S: 사면,	R: 옹벽
					Debug::WriteLine("=================>STR_27[" + i + "]:" + STR_27);
					//STR_CLASS_ID += STR_27;
					STR_CLASS_ID += STR_6;

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*지진취약도 표준형식1   */
					Debug::WriteLine("=================>STR_28[" + i + "]:" + STR_28);
					if (STR_28->StartsWith("PGA")) {
						STR_CLASS_ID += "0";
					}

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*지진취약도 표준형식2   */
					//0: Total displacement
					//1: Relative wall	displacement
					//2: Backfill settlement

					Debug::WriteLine("=================>STR_29[" + i + "]:" + STR_29);
					if (STR_29->StartsWith("Total")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_29->StartsWith("Relative")) {
						STR_CLASS_ID += "1";
					}
					else if (STR_29->StartsWith("Backfill")) {
						STR_CLASS_ID += "2";
					}

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*입력지진파 산정	 */
					Debug::WriteLine("=================>STR_31[" + i + "]:" + STR_31);
					STR_CLASS_ID += STR_31;

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*사면 경사도*/
					Debug::WriteLine("=================>STR_32[" + i + "]:" + STR_32);
					STR_CLASS_ID += STR_32;

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*사면 점착력*/
					Debug::WriteLine("=================>STR_33[" + i + "]:" + STR_33);
					STR_CLASS_ID += STR_33;

				}
				/******** 교량 *******/
				else {//교량

					/*상부구조*/
					String^ STR_UPPER_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_UPPER_TYPE]->ToString();
					Debug::WriteLine("=================>STR_UPPER_TYPE[" + i + "]:" + STR_UPPER_TYPE);
					if (STR_UPPER_TYPE->Equals("RC Slab")) {
						STR_CLASS_ID = "RS";
					}
					if (STR_UPPER_TYPE->Equals("Rahmen") || STR_UPPER_TYPE->Equals("RC Rahmen") || STR_UPPER_TYPE->Equals("RC 라멘")) {
						STR_CLASS_ID = "RR";
					}
					if (STR_UPPER_TYPE->Equals("PSC Beam")) {
						STR_CLASS_ID = "PB";
					}
					if (STR_UPPER_TYPE->Equals("PSC Box")) {
						STR_CLASS_ID = "PX";
					}
					if (STR_UPPER_TYPE->Equals("Steel Beam")) {
						STR_CLASS_ID = "SB";
					}
					if (STR_UPPER_TYPE->Equals("Steel Box")) {
						STR_CLASS_ID = "SX";
					}

					/*연속성*/
					String^ STR_CONTINUITY = dtNetComp->Rows[i][NetworkComponent::COL_CONTINUITY]->ToString();
					Debug::WriteLine("=================>STR_CONTINUITY[" + i + "]:" + STR_CONTINUITY);


					/*경간장*/
					String^ STR_SPAN_LENGTH = dtNetComp->Rows[i][NetworkComponent::COL_SPAN_LENGTH]->ToString();
					Debug::WriteLine("=================>STR_SPAN_LENGTH[" + i + "]:" + STR_SPAN_LENGTH);

					STR_SPAN_LENGTH = STR_SPAN_LENGTH->PadLeft(2, '0');
					STR_CLASS_ID += STR_SPAN_LENGTH;

					/*차폭*/
					String^ STR_CAR_BREADTH = dtNetComp->Rows[i][NetworkComponent::COL_CAR_BREADTH]->ToString();
					Debug::WriteLine("=================>STR_CAR_BREADTH[" + i + "]:" + STR_CAR_BREADTH);

					STR_CAR_BREADTH = STR_CAR_BREADTH->PadLeft(2, '0');
					STR_CLASS_ID += STR_CAR_BREADTH;

					/*경간수*/
					String^ STR_SPAN_COUNT = dtNetComp->Rows[i][NetworkComponent::COL_SPAN_COUNT]->ToString();
					Debug::WriteLine("=================>STR_SPAN_COUNT[" + i + "]:" + STR_SPAN_COUNT);

					STR_SPAN_COUNT = STR_SPAN_COUNT->PadLeft(2, '0');
					STR_CLASS_ID += STR_SPAN_COUNT;


					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*교고*/
					//5m, 15m -> 0, 1
					String^ STR_BRIDGE_HEIGHT = dtNetComp->Rows[i][NetworkComponent::COL_BRIDGE_HEIGHT]->ToString();
					Debug::WriteLine("=================>STR_BRIDGE_HEIGHT[" + i + "]:" + STR_BRIDGE_HEIGHT);
					if (STR_BRIDGE_HEIGHT->StartsWith("5m")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_BRIDGE_HEIGHT->StartsWith("15m")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*하부구조*/
					//단주, 다주 -> 0,1
					String^ STR_BOTTOM_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_BOTTOM_TYPE]->ToString();
					Debug::WriteLine("=================>STR_BOTTOM_TYPE[" + i + "]:" + STR_BOTTOM_TYPE);
					if (STR_BOTTOM_TYPE->StartsWith("단주")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_BOTTOM_TYPE->StartsWith("다주")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*교좌*/
					//일반, 탄성 -> 0,1
					String^ STR_ELASTOMERIC_SHOE = dtNetComp->Rows[i][NetworkComponent::COL_ELASTOMERIC_SHOE]->ToString();
					Debug::WriteLine("=================>STR_ELASTOMERIC_SHOE[" + i + "]:" + STR_ELASTOMERIC_SHOE);
					if (STR_ELASTOMERIC_SHOE->StartsWith("일반")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_ELASTOMERIC_SHOE->StartsWith("탄성")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*기초*/
					//말뚝, 확대 -> 0,1
					String^ STR_BRIDGE_FOUNDATION = dtNetComp->Rows[i][NetworkComponent::COL_BRIDGE_FOUNDATION]->ToString();
					Debug::WriteLine("=================>STR_BRIDGE_FOUNDATION[" + i + "]:" + STR_BRIDGE_FOUNDATION);
					if (STR_BRIDGE_FOUNDATION->StartsWith("말뚝")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_BRIDGE_FOUNDATION->StartsWith("확대")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*내진설계여부*/
					//O,X -> 1,0
					String^ STR_SEISMIC_DESIGN_YN = dtNetComp->Rows[i][NetworkComponent::COL_SEISMIC_DESIGN_YN]->ToString();
					Debug::WriteLine("=================>STR_SEISMIC_DESIGN_YN[" + i + "]:" + STR_SEISMIC_DESIGN_YN);
					if (STR_SEISMIC_DESIGN_YN->StartsWith("X")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_SEISMIC_DESIGN_YN->StartsWith("O")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";

					/*노후도(교각)*/
					//O,X -> 1,0
					String^ STR_OLD_BRIDGE = dtNetComp->Rows[i][NetworkComponent::COL_OLD_BRIDGE]->ToString();
					Debug::WriteLine("=================>STR_OLD_BRIDGE[" + i + "]:" + STR_OLD_BRIDGE);
					if (STR_OLD_BRIDGE->StartsWith("X")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_OLD_BRIDGE->StartsWith("O")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}


					/*노후도(교좌)*/
					//O,X -> 1,0
					String^ STR_OLD_SHOE = dtNetComp->Rows[i][NetworkComponent::COL_OLD_SHOE]->ToString();
					Debug::WriteLine("=================>STR_OLD_SHOE[" + i + "]:" + STR_OLD_SHOE);
					if (STR_OLD_SHOE->StartsWith("X")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_OLD_SHOE->StartsWith("O")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*보수보강(교각)*/
					//O,X -> 1,0
					String^ STR_REPAIR_BRIDGE = dtNetComp->Rows[i][NetworkComponent::COL_REPAIR_BRIDGE]->ToString();
					Debug::WriteLine("=================>STR_REPAIR_BRIDGE[" + i + "]:" + STR_REPAIR_BRIDGE);
					if (STR_REPAIR_BRIDGE->StartsWith("X")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_REPAIR_BRIDGE->StartsWith("O")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*보수보강(교좌)*/
					//O,X -> 1,0
					String^ STR_REPAIR_SHOE = dtNetComp->Rows[i][NetworkComponent::COL_REPAIR_SHOE]->ToString();
					Debug::WriteLine("=================>STR_REPAIR_SHOE[" + i + "]:" + STR_REPAIR_SHOE);
					if (STR_REPAIR_SHOE->StartsWith("X")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_REPAIR_SHOE->StartsWith("O")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*중간 언더바 추가*/
					STR_CLASS_ID += "_";


					/*지반종류*/
					String^ STR_GROUND_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_GROUND_TYPE]->ToString();
					Debug::WriteLine("=================>STR_GROUND_TYPE[" + i + "]:" + STR_GROUND_TYPE);
					if (STR_GROUND_TYPE->StartsWith("S2")) {
						STR_CLASS_ID += "2";
					}
					else if (STR_GROUND_TYPE->StartsWith("S3")) {
						STR_CLASS_ID += "3";
					}
					else if (STR_GROUND_TYPE->StartsWith("S4")) {
						STR_CLASS_ID += "4";
					}
					else if (STR_GROUND_TYPE->StartsWith("S5")) {
						STR_CLASS_ID += "5";
					}


					/*토질형식*/
					String^ STR_SOIL_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_SOIL_TYPE]->ToString();
					Debug::WriteLine("=================>STR_SOIL_TYPE[" + i + "]:" + STR_SOIL_TYPE);

					/*고유주기*/
					String^ STR_FUNDAMENTAL_PERIOD = dtNetComp->Rows[i][NetworkComponent::COL_FUNDAMENTAL_PERIOD]->ToString();
					Debug::WriteLine("=================>STR_FUNDAMENTAL_PERIOD[" + i + "]:" + STR_FUNDAMENTAL_PERIOD);

				}
		
				/*CLASS ID 세팅*/
				Debug::WriteLine("=======================================================================================");
				Debug::WriteLine("==============================================>STR_CLASS_ID[" + i + "]:" + STR_CLASS_ID);
				dtNetComp->Rows[i][NetworkComponent::COL_CLASS_ID] = STR_CLASS_ID;
				Debug::WriteLine("=======================================================================================");

			}
		}

		// read from =
		DataRow^ GetRow(int row) {
			return this->m_dataTable->Rows[row];
		}

		// get row
		String^ GetValue(int row, int column) {
			System::Data::DataRow^ r = this->m_dataTable->Rows[row];
			return r[column]->ToString();
		}

		// get row count
		int GetCount() {
			return this->m_dataTable->Rows->Count;
		}

		// get column count
		int GetColumnCount() {
			return this->m_dataTable->Columns->Count;
		}

		// get column name
		String^ GetColumnName(int column) {
			return this->m_dataTable->Columns[column]->ColumnName;
		}

		array<DataRow^>^ FindRows(String^ columnName, Object^ value) {
			return this->m_dataTable->Select(String::Format("[{0}]='{1}'", columnName, value));
		}

		array<DataRow^>^ FindRows(int column, Object^ value) {
			return FindRows(GetColumnName(column), value);
		}

		array<DataRow^>^ FindRows(String^ columnName1, Object^ value1, String^ columnName2, Object^ value2) {
			return this->m_dataTable->Select(String::Format("[{0}]='{1}' and [{2}]='{3}'", columnName1, value1, columnName2, value2));
		}

		array<DataRow^>^ FindRows(int column1, Object^ value1, int column2, Object^ value2) {
			return this->m_dataTable->Select(String::Format("[{0}]='{1}' and [{2}]='{3}'", GetColumnName(column1), value1, GetColumnName(column2), value2));
		}

		
		array<DataRow^>^ FindRowsFacility(int column, Object^ value) {

			int countFacility = 0;
			array<DataRow^>^ newDataRows = gcnew array<DataRow^>(this->m_dataTable->Rows->Count);

			for (int i = 0; i < this->m_dataTable->Rows->Count; i++) {
				DataRow^ newRow = this->m_dataTable->Rows[i];							   
				String^ ColumnName = this->m_dataTable->Columns[column]->ColumnName;

				if (value == "교량") {
					//int temp = int::Parse(newRow[ColumnName]->ToString());
					//if(temp < 101 ){
					String^ temp = newRow[ColumnName]->ToString();
					if (temp =="Steel Beam" || temp=="Steel Box" || temp == "PSC Beam" || temp == "PSC Box" || temp == "RC Slab" || temp == "RC 라멘") {
							newDataRows[countFacility++] = newRow;
						//countFacility++;
					}
				}

				if (value == "터널") {
					//int temp = int::Parse(newRow[ColumnName]->ToString());
					//if (100 < temp && temp < 201) {
					//	newDataRows[countFacility++] = newRow;
					//}
					String^ temp = newRow[ColumnName]->ToString();
					if (temp == "Mined/Bored" || temp == "Cut-and-cover") {
						newDataRows[countFacility++] = newRow;
					}
				}

				if (value == "사면") {
					//int temp = int::Parse(newRow[ColumnName]->ToString());
					//if (200 < temp && temp < 301) {
					//	newDataRows[countFacility++] = newRow;
					//}
					String^ temp = newRow[ColumnName]->ToString();
					if (temp == "S") {
						newDataRows[countFacility++] = newRow;
					}
				}

				if (value == "옹벽") {
					//int temp = int::Parse(newRow[ColumnName]->ToString());
					//if (300 < temp) {
					//	newDataRows[countFacility++] = newRow;
					//}
					String^ temp = newRow[ColumnName]->ToString();
					if (temp == "R") {
						newDataRows[countFacility++] = newRow;
					}
				}
			}

			array<DataRow^>^ componentDataRows = gcnew array<DataRow^>(countFacility);
			for (int i = 0; i < countFacility; i++) {
				componentDataRows[i] = newDataRows[i];
			}			
			return componentDataRows;
		}


		array<ComponentClassInfo>^ GetNetworkComponentChartData() {
			// 클래스 단위로 데이터를 표시하기 위해 클래스 단위로 그룹핑 데이터 생성
			//array<ComponentClassInfo>^ chartDatas = gcnew array<ComponentClassInfo>(m_componentClassdataTable->Rows->Count);
			array<ComponentClassInfo>^ chartDatas = gcnew array<ComponentClassInfo>(CommConst::TOTAL_NUMBER_CATEGORY_FACILITY);
			Random^ rand = gcnew Random();
			int columnCount = GetColumnCount();

			chartDatas[0].name = "1";
			chartDatas[1].name = "2";
			chartDatas[2].name = "3";
			chartDatas[3].name = "4";
			chartDatas[0].name2 = CommConst::FACILITY_TYPE1;
			chartDatas[1].name2 = CommConst::FACILITY_TYPE2;
			chartDatas[2].name2 = CommConst::FACILITY_TYPE3;
			chartDatas[3].name2 = CommConst::FACILITY_TYPE4;

			// ClassID별로 데이터 생성
			//for (int index = 0; index < m_componentClassdataTable->Rows->Count; index++)
			for (int index = 0; index < CommConst::TOTAL_NUMBER_CATEGORY_FACILITY; index++)
			{

/*
				DataRow^ classDataRow = m_componentClassdataTable->Rows[index];
				// Define chart data infomation.
				String^ classId = classDataRow[CommConst::GRID_COMP_CLASS_COL1]->ToString();
				chartDatas[index].name = classId;
				chartDatas[index].name2 = classDataRow[CommConst::GRID_COMP_CLASS_COL2]->ToString();
*/
				String^ facilityID = chartDatas[index].name2;


				// 기본으로 설정된 컬러값을 초과하면 랜덤으로 색상 지정 
				if (index < m_componentColors->Length) {
					chartDatas[index].color = m_componentColors[index];
				}
				else {
					chartDatas[index].color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
				}
				chartDatas[index].symbol = index + 1; // present symbol

				// find class's components
				//array<DataRow^>^ componentDataRows = FindRows(NetworkComponent::COL_CLASS_ID, classId);

				//array<DataRow^>^ componentDataRows = FindRowsFacility(NetworkComponent::COL_CLASS_ID, facilityID);
				array<DataRow^>^ componentDataRows = FindRowsFacility(NetworkComponent::COL_UPPER_TYPE, facilityID);


				int componentDataRowCount = componentDataRows->Length;
				chartDatas[index].dataX = gcnew array<double>(componentDataRowCount);
				chartDatas[index].dataY = gcnew array<double>(componentDataRowCount);
				chartDatas[index].attributes = gcnew array<ShapeChartAttribute^>(componentDataRowCount);
				// set class's components data
				for (int rowIndex = 0; rowIndex < componentDataRowCount; rowIndex++)
				{
					DataRow^ componentDataRow = componentDataRows[rowIndex];
					double x = 0.0;
					double y = 0.0;
					if (double::TryParse(componentDataRow[NetworkComponent::COL_X]->ToString(), x)
						&& double::TryParse(componentDataRow[NetworkComponent::COL_Y]->ToString(), y)) {
						chartDatas[index].dataX[rowIndex] = x;
						chartDatas[index].dataY[rowIndex] = y;
					}

					// set component attributes
					ShapeChartAttribute^ attributes;
					attributes = gcnew ShapeChartAttribute(AttributeType::Component, componentDataRow[NetworkComponent::COL_NETWORK_COMP_ID]->ToString());
					for (int colIndex = 0; colIndex < columnCount; colIndex++)
					{
						if (colIndex != NetworkComponent::COL_X && colIndex != NetworkComponent::COL_Y) {
							attributes->SetAttribute(GetColumnName(colIndex), componentDataRow[colIndex]);
						}
					}
					chartDatas[index].attributes[rowIndex] = attributes;
				}
			}
			return chartDatas;
		}

	};
}