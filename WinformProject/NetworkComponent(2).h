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
		literal int COL_SOIL_TYPE = 6;
		literal int COL_FUNDAMENTAL_PERIOD = 7;

	private:
		DataTable^					m_dataTable;
		DataTable^					m_componentClassdataTable;
		array<Drawing::Color>^		m_componentColors;


	public:
		// Data
		property DataTable^ Data {
			System::Data::DataTable^ get() {
				return this->m_dataTable;
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
		}

		// read from file
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

			array<DataRow^>^ componentDataRows;
			int bridgeIndex = 0;
			int tunnelIndex = 0;
			int slopIndex = 0;
			int retainingIndex = 0;

			for (int i = 0; i < this->m_dataTable->Rows->Count; i++) {
				DataRow^ newRow = this->m_dataTable->Rows[i];


/*
				if (value == "BRIDGE") {
					//if(int::Parse(newRow[column]->ToString) < 101 ){
					if (int::Parse(newRow[1]->ToString) < 101) {
							componentDataRows[bridgeIndex] = newRow;
						bridgeIndex ++;
					}
				}

				if (value == "TUNNEL") {
					if (100< int::Parse(newRow[column]->ToString) < 201) {
						componentDataRows[tunnelIndex] = newRow;
						tunnelIndex++;
					}
				}

				if (value == "SLOP") {
					if (200 < int::Parse(newRow[column]->ToString) < 301) {
						componentDataRows[slopIndex] = newRow;
						slopIndex++;
					}
				}

				if (value == "RETAINING") {
					if (300 < int::Parse(newRow[column]->ToString)) {
						//componentDataRows = this->m_dataTable->Select(String::Format("[{0}]='{1}'", column, value));
						componentDataRows[retainingIndex] = newRow;
						retainingIndex++;
					}
				}
			}

*/

			return componentDataRows;
		}


/*
		array<ComponentClassInfo>^ GetNetworkComponentChartData() {
			// 클래스 단위로 데이터를 표시하기 위해 클래스 단위로 그룹핑 데이터 생성
			array<ComponentClassInfo>^ chartDatas = gcnew array<ComponentClassInfo>(m_componentClassdataTable->Rows->Count);
			Random^ rand = gcnew Random();
			int columnCount = GetColumnCount();

			// ClassID별로 데이터 생성
			for (int index = 0; index < m_componentClassdataTable->Rows->Count; index++)
			{
				DataRow^ classDataRow = m_componentClassdataTable->Rows[index];
				// Define chart data infomation.
				String^ classId = classDataRow[CommConst::GRID_COMP_CLASS_COL1]->ToString();
				chartDatas[index].name = classId;
				chartDatas[index].name2 = classDataRow[CommConst::GRID_COMP_CLASS_COL2]->ToString();
				// 기본으로 설정된 컬러값을 초과하면 랜덤으로 색상 지정 
				if (index < m_componentColors->Length) {
					chartDatas[index].color = m_componentColors[index];
				}
				else {
					chartDatas[index].color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
				}
				chartDatas[index].symbol = index + 1; // present symbol

				// find class's components
				array<DataRow^>^ componentDataRows = FindRows(NetworkComponent::COL_CLASS_ID, classId);
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
*/





		array<ComponentClassInfo>^ GetNetworkComponentChartData() {
			// 클래스 단위로 데이터를 표시하기 위해 클래스 단위로 그룹핑 데이터 생성
			array<ComponentClassInfo>^ chartDatas = gcnew array<ComponentClassInfo>(m_componentClassdataTable->Rows->Count);
			Random^ rand = gcnew Random();
			int columnCount = GetColumnCount();

			// ClassID별로 데이터 생성				
			//for (int index = 0; index < m_componentClassdataTable->Rows->Count; index++)

/*
			for (int i = 0; i < CommConst::TOTAL_NUMBER_CATEGORY_FACILITY; i++) {
				String^ name2 = "FACILITY_TYPE" + String::Format("{0}", i);
				chartDatas[i].name = String::Format("{0}",i);
				chartDatas[0].name2 = name2;
			}
*/
			chartDatas[0].name = "1";
			chartDatas[1].name = "2";
			chartDatas[2].name = "3";
			chartDatas[3].name = "4";		
			chartDatas[0].name2 = CommConst::FACILITY_TYPE1;
			chartDatas[1].name2 = CommConst::FACILITY_TYPE2;
			chartDatas[2].name2 = CommConst::FACILITY_TYPE3;
			chartDatas[3].name2 = CommConst::FACILITY_TYPE4;

			for (int index = 0; index < CommConst::TOTAL_NUMBER_CATEGORY_FACILITY; index++)
				{


/*
				DataRow^ classDataRow = m_componentClassdataTable->Rows[index];
				// Define chart data infomation.
				String^ classId = classDataRow[CommConst::GRID_COMP_CLASS_COL1]->ToString();
				chartDatas[index].name = classId;
				chartDatas[index].name2 = classDataRow[CommConst::GRID_COMP_CLASS_COL2]->ToString();
				// 기본으로 설정된 컬러값을 초과하면 랜덤으로 색상 지정 
				if (index < m_componentColors->Length) {
					chartDatas[index].color = m_componentColors[index];
				}
				else {
					chartDatas[index].color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
				}
				chartDatas[index].symbol = index + 1; // present symbol
*/

				String^ facilityID = chartDatas[index].name2;

				// find class's components
				//array<DataRow^>^ componentDataRows = FindRowsFacility(NetworkComponent::COL_CLASS_ID, classId);
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