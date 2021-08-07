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


		//literal int COL_SOIL_TYPE = 6;//��������
		//literal int COL_FUNDAMENTAL_PERIOD = 7;//�����ֱ�

		//������������ �߰�
		literal int COL_UPPER_TYPE = 6;//�������
		literal int COL_CONTINUITY = 7;//���Ӽ�
		literal int COL_BRIDGE_HEIGHT = 8;//����
		literal int COL_SPAN_LENGTH = 9;//�氣��
		literal int COL_SPAN_COUNT = 10;//�氣��
		literal int COL_CAR_BREADTH = 11;//����
		literal int COL_BOTTOM_TYPE = 12;//�Ϻα���
		literal int COL_ELASTOMERIC_SHOE = 13;//����
		literal int COL_BRIDGE_FOUNDATION = 14;//����
		literal int COL_SEISMIC_DESIGN_YN = 15;//�������迩��
		literal int COL_OLD_BRIDGE = 16;//���ĵ�(����)
		literal int COL_OLD_SHOE = 17;//���ĵ�(����)
		literal int COL_REPAIR_BRIDGE = 18;//��������(����)
		literal int COL_REPAIR_SHOE = 19;//��������(����)
		literal int COL_GROUND_TYPE = 20;//��������
		literal int COL_SOIL_TYPE = 21;//��������
		literal int COL_FUNDAMENTAL_PERIOD = 22;//�����ֱ�
	
		literal int COL_23 = 23;//�ͳκз�
		literal int COL_24 = 24;//������൵ ǥ������
		literal int COL_25 = 25;//���� vs ����	
		literal int COL_26 = 26;//���ĵ�
		literal int COL_27 = 27;//������ �з�	
		literal int COL_28 = 28;//������൵ ǥ������1   
		literal int COL_29 = 29;//������൵ ǥ������2 
		literal int COL_30 = 30;//������ ��������   
		literal int COL_31 = 31;//�Է������� ����	  
		literal int COL_32 = 32;//��� ��絵	      
		literal int COL_33 = 33;//��� ������       
		literal int COL_34 = 34;//������	          
		literal int COL_35 = 35;//�ð��ڸ�	        
		literal int COL_36 = 36;//�ذ�����	        
		literal int COL_37 = 37;//����Ȱ����        
		literal int COL_38 = 38;//�����������뿩��	
		literal int COL_39 = 39;//�ѱ���/�氣����	  	
		literal int COL_40 = 40;//��_��             	
		literal int COL_41 = 41;//(����)��ǥ�氣����	
		literal int COL_42 = 42;//(����)��ǥ��ħ����
		literal int COL_43 = 43;//(����)��ǥ��������
		literal int COL_44 = 44;//(����)��ǥ��������
		literal int COL_45 = 45;//(�ͳ�)������ǥ	  
		literal int COL_46 = 46;//(���)����	      
		literal int COL_47 = 47;//(���)���	      
		literal int COL_48 = 48;//(���)�������	  
		literal int COL_49 = 49;//(�˺�)�ִ����	  
		literal int COL_50 = 50;//(�˺�)���        









	private:
		DataTable^					m_dataTable;
		DataTable^					m_componentClassdataTable;
		array<Drawing::Color>^		m_componentColors;


		Dictionary<String^, DataTable^>^ m_structureDamageStatus; //�ü��� �����ó������� ���ذ�� ����


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

			//�ü��� ���� ����
			SetClassId();
		}

		/** �ü��� ���� ���� **/
		void SetClassId() {
			
			DataTable^ dtNetComp = this->m_dataTable;
			for (int i = 0; i < dtNetComp->Rows->Count; i++) {

				/*CLASS ID*/
				String^ STR_CLASS_ID = "";
				
				String^ STR_23 = dtNetComp->Rows[i][NetworkComponent::COL_23]->ToString();//�ͳκз�
				String^ STR_24 = dtNetComp->Rows[i][NetworkComponent::COL_24]->ToString();//������൵ ǥ������
				String^ STR_25 = dtNetComp->Rows[i][NetworkComponent::COL_25]->ToString();//���� vs ����	
				String^ STR_26 = dtNetComp->Rows[i][NetworkComponent::COL_26]->ToString();//���ĵ�
				String^ STR_27 = dtNetComp->Rows[i][NetworkComponent::COL_27]->ToString();//������ �з�	
				String^ STR_28 = dtNetComp->Rows[i][NetworkComponent::COL_28]->ToString();//������൵ ǥ������1   
				String^ STR_29 = dtNetComp->Rows[i][NetworkComponent::COL_29]->ToString();//������൵ ǥ������2
				String^ STR_30 = dtNetComp->Rows[i][NetworkComponent::COL_30]->ToString();//������ ��������           
				String^ STR_31 = dtNetComp->Rows[i][NetworkComponent::COL_31]->ToString();//�Է������� ����	          
				String^ STR_32 = dtNetComp->Rows[i][NetworkComponent::COL_32]->ToString();//��� ��絵	              
				String^ STR_33 = dtNetComp->Rows[i][NetworkComponent::COL_33]->ToString();//��� ������               
				String^ STR_34 = dtNetComp->Rows[i][NetworkComponent::COL_34]->ToString();//������	                  
				String^ STR_35 = dtNetComp->Rows[i][NetworkComponent::COL_35]->ToString();//�ð��ڸ�	                
				String^ STR_36 = dtNetComp->Rows[i][NetworkComponent::COL_36]->ToString();//�ذ�����	                
				String^ STR_37 = dtNetComp->Rows[i][NetworkComponent::COL_37]->ToString();//����Ȱ����                
				String^ STR_38 = dtNetComp->Rows[i][NetworkComponent::COL_38]->ToString();//�����������뿩��	        
				String^ STR_39 = dtNetComp->Rows[i][NetworkComponent::COL_39]->ToString();//�ѱ���/�氣����	          
				String^ STR_40 = dtNetComp->Rows[i][NetworkComponent::COL_40]->ToString();//��_��                     
				String^ STR_41 = dtNetComp->Rows[i][NetworkComponent::COL_41]->ToString();//(����)��ǥ�氣����	      
				String^ STR_42 = dtNetComp->Rows[i][NetworkComponent::COL_42]->ToString();//(����)��ǥ��ħ����	      
				String^ STR_43 = dtNetComp->Rows[i][NetworkComponent::COL_43]->ToString();//(����)��ǥ��������	      
				String^ STR_44 = dtNetComp->Rows[i][NetworkComponent::COL_44]->ToString();//(����)��ǥ��������        
				String^ STR_45 = dtNetComp->Rows[i][NetworkComponent::COL_45]->ToString();//(�ͳ�)������ǥ	          
				String^ STR_46 = dtNetComp->Rows[i][NetworkComponent::COL_46]->ToString();//(���)����	              
				String^ STR_47 = dtNetComp->Rows[i][NetworkComponent::COL_47]->ToString();//(���)���	              
				String^ STR_48 = dtNetComp->Rows[i][NetworkComponent::COL_48]->ToString();//(���)�������	          
				String^ STR_49 = dtNetComp->Rows[i][NetworkComponent::COL_49]->ToString();//(�˺�)�ִ����	          
				String^ STR_50 = dtNetComp->Rows[i][NetworkComponent::COL_50]->ToString();//(�˺�)���                



				/******** �ͳ� *******/
				if (!StringUtil::isNull(STR_23)) {//�ͳ�

					/*�ͳκз�*/
					Debug::WriteLine("=================>STR_23[" + i + "]:" + STR_23);
					if (STR_23->StartsWith("cut")) {
						STR_CLASS_ID += "CC1";
					}
					else {
						STR_CLASS_ID += "MB0";
					}

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*������൵ ǥ������*/
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

					
					/*���� vs ����	*/
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
					
					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*���ĵ�*/
					Debug::WriteLine("=================>STR_26[" + i + "]:" + STR_26);
					STR_CLASS_ID += STR_26;



				}
				/******** ���,�˺� *******/
				else if (!StringUtil::isNull(STR_27)) {//���,�˺�

					/*������ �з�*/ 
					//S: ���,	R: �˺�
					Debug::WriteLine("=================>STR_27[" + i + "]:" + STR_27);
					STR_CLASS_ID += STR_27;

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*������൵ ǥ������1   */
					Debug::WriteLine("=================>STR_28[" + i + "]:" + STR_28);
					STR_CLASS_ID += STR_28;

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*������൵ ǥ������2   */
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

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*�Է������� ����	 */
					Debug::WriteLine("=================>STR_31[" + i + "]:" + STR_31);
					STR_CLASS_ID += STR_31;

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*��� ��絵*/
					Debug::WriteLine("=================>STR_32[" + i + "]:" + STR_32);
					STR_CLASS_ID += STR_32;

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*��� ������*/
					Debug::WriteLine("=================>STR_33[" + i + "]:" + STR_33);
					STR_CLASS_ID += STR_33;

				}
				/******** ���� *******/
				else {//����

					/*��α���*/
					String^ STR_UPPER_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_UPPER_TYPE]->ToString();
					Debug::WriteLine("=================>STR_UPPER_TYPE[" + i + "]:" + STR_UPPER_TYPE);
					if (STR_UPPER_TYPE->Equals("RC Slab")) {
						STR_CLASS_ID = "RS";
					}
					if (STR_UPPER_TYPE->Equals("Rahmen") || STR_UPPER_TYPE->Equals("RC Rahmen") || STR_UPPER_TYPE->Equals("RC ���")) {
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

					/*���Ӽ�*/
					String^ STR_CONTINUITY = dtNetComp->Rows[i][NetworkComponent::COL_CONTINUITY]->ToString();
					Debug::WriteLine("=================>STR_CONTINUITY[" + i + "]:" + STR_CONTINUITY);


					/*�氣��*/
					String^ STR_SPAN_LENGTH = dtNetComp->Rows[i][NetworkComponent::COL_SPAN_LENGTH]->ToString();
					Debug::WriteLine("=================>STR_SPAN_LENGTH[" + i + "]:" + STR_SPAN_LENGTH);

					STR_SPAN_LENGTH = STR_SPAN_LENGTH->PadLeft(2, '0');
					STR_CLASS_ID += STR_SPAN_LENGTH;

					/*����*/
					String^ STR_CAR_BREADTH = dtNetComp->Rows[i][NetworkComponent::COL_CAR_BREADTH]->ToString();
					Debug::WriteLine("=================>STR_CAR_BREADTH[" + i + "]:" + STR_CAR_BREADTH);

					STR_CAR_BREADTH = STR_CAR_BREADTH->PadLeft(2, '0');
					STR_CLASS_ID += STR_CAR_BREADTH;

					/*�氣��*/
					String^ STR_SPAN_COUNT = dtNetComp->Rows[i][NetworkComponent::COL_SPAN_COUNT]->ToString();
					Debug::WriteLine("=================>STR_SPAN_COUNT[" + i + "]:" + STR_SPAN_COUNT);

					STR_SPAN_COUNT = STR_SPAN_COUNT->PadLeft(2, '0');
					STR_CLASS_ID += STR_SPAN_COUNT;


					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*����*/
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

					/*�Ϻα���*/
					//����, ���� -> 0,1
					String^ STR_BOTTOM_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_BOTTOM_TYPE]->ToString();
					Debug::WriteLine("=================>STR_BOTTOM_TYPE[" + i + "]:" + STR_BOTTOM_TYPE);
					if (STR_BOTTOM_TYPE->StartsWith("����")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_BOTTOM_TYPE->StartsWith("����")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*����*/
					//�Ϲ�, ź�� -> 0,1
					String^ STR_ELASTOMERIC_SHOE = dtNetComp->Rows[i][NetworkComponent::COL_ELASTOMERIC_SHOE]->ToString();
					Debug::WriteLine("=================>STR_ELASTOMERIC_SHOE[" + i + "]:" + STR_ELASTOMERIC_SHOE);
					if (STR_ELASTOMERIC_SHOE->StartsWith("�Ϲ�")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_ELASTOMERIC_SHOE->StartsWith("ź��")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*����*/
					//����, Ȯ�� -> 0,1
					String^ STR_BRIDGE_FOUNDATION = dtNetComp->Rows[i][NetworkComponent::COL_BRIDGE_FOUNDATION]->ToString();
					Debug::WriteLine("=================>STR_BRIDGE_FOUNDATION[" + i + "]:" + STR_BRIDGE_FOUNDATION);
					if (STR_BRIDGE_FOUNDATION->StartsWith("����")) {
						STR_CLASS_ID += "0";
					}
					else if (STR_BRIDGE_FOUNDATION->StartsWith("Ȯ��")) {
						STR_CLASS_ID += "1";
					}
					else {
						STR_CLASS_ID += "0";
					}

					/*�������迩��*/
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

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";

					/*���ĵ�(����)*/
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


					/*���ĵ�(����)*/
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

					/*��������(����)*/
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

					/*��������(����)*/
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

					/*�߰� ����� �߰�*/
					STR_CLASS_ID += "_";


					/*��������*/
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


					/*��������*/
					String^ STR_SOIL_TYPE = dtNetComp->Rows[i][NetworkComponent::COL_SOIL_TYPE]->ToString();
					Debug::WriteLine("=================>STR_SOIL_TYPE[" + i + "]:" + STR_SOIL_TYPE);

					/*�����ֱ�*/
					String^ STR_FUNDAMENTAL_PERIOD = dtNetComp->Rows[i][NetworkComponent::COL_FUNDAMENTAL_PERIOD]->ToString();
					Debug::WriteLine("=================>STR_FUNDAMENTAL_PERIOD[" + i + "]:" + STR_FUNDAMENTAL_PERIOD);

				}
		
				/*CLASS ID ����*/
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

				if (value == "����") {
					int temp = int::Parse(newRow[ColumnName]->ToString());
					if(temp < 101 ){
						newDataRows[countFacility++] = newRow;
						//countFacility++;
					}
				}

				if (value == "�ͳ�") {
					int temp = int::Parse(newRow[ColumnName]->ToString());
					if (100 < temp && temp < 201) {
						newDataRows[countFacility++] = newRow;
					}
				}

				if (value == "���") {
					int temp = int::Parse(newRow[ColumnName]->ToString());
					if (200 < temp && temp < 301) {
						newDataRows[countFacility++] = newRow;
					}
				}

				if (value == "�˺�") {
					int temp = int::Parse(newRow[ColumnName]->ToString());
					if (300 < temp) {
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
			// Ŭ���� ������ �����͸� ǥ���ϱ� ���� Ŭ���� ������ �׷��� ������ ����
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

			// ClassID���� ������ ����
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




				// �⺻���� ������ �÷����� �ʰ��ϸ� �������� ���� ���� 
				if (index < m_componentColors->Length) {
					chartDatas[index].color = m_componentColors[index];
				}
				else {
					chartDatas[index].color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
				}
				chartDatas[index].symbol = index + 1; // present symbol

				// find class's components
				//array<DataRow^>^ componentDataRows = FindRows(NetworkComponent::COL_CLASS_ID, classId);


				array<DataRow^>^ componentDataRows = FindRowsFacility(NetworkComponent::COL_CLASS_ID, facilityID);



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