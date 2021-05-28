#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace WinformProject {

	public ref class FragilityDataSet
	{
	public:
		FragilityDataSet() {
		}
	public:
		static Dictionary<String^, String^>^ m_FragilityCurvDict;
		static DataTable^                    m_FragilityCurvData;

	public:
		static void setFragilityCurvDict() {
			FragilityDataSet::m_FragilityCurvDict = gcnew Dictionary<String^, String^>();

			m_FragilityCurvDict->Add("1111","2222222");
			m_FragilityCurvDict->Add("333333", "44444444");
			m_FragilityCurvDict->Add("단경간_-_-_일반_-_-_-_X_-_X", "PB301201_00000_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_X_X_X", "PB301203_00000_0001.xlsx");

			/*
			단경간_-_-_일반_-_-_-_X_-_X	PB301201_00000_0000.xlsx
단경간_-_-_일반_-_-_-_X_-_O	PB301201_00000_0001.xlsx
단경간_-_-_일반_-_-_-_O_-_X	PB301201_00000_0100.xlsx
단경간_-_-_일반_-_-_-_O_-_O	PB301201_00000_0101.xlsx
단경간_-_-_탄성_-_-_-_X_-_X	PB301201_00100_0000.xlsx
단경간_-_-_탄성_-_-_-_X_-_O	PB301201_00100_0001.xlsx
단경간_-_-_탄성_-_-_-_O_-_X	PB301201_00100_0100.xlsx
단경간_-_-_탄성_-_-_-_O_-_O	PB301201_00100_0101.xlsx
다경간_5m이하_단주_일반_말뚝_C_X_X_X_X	PB301203_00000_0000.xlsx
다경간_5m이하_단주_일반_말뚝_C_X_X_X_O	PB301203_00000_0001.xlsx

			*/
		}


		static void setFragilityCurvData() {
			FragilityDataSet::m_FragilityCurvData = gcnew DataTable();

			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL01, Type::GetType("System.String")));
			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL02, Type::GetType("System.String")));
			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL03, Type::GetType("System.Double")));
			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL04, Type::GetType("System.Double")));
			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL05, Type::GetType("System.Double")));
			FragilityDataSet::m_FragilityCurvData->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL06, Type::GetType("System.Double")));


			DataRow^ newRow = nullptr;


			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00000_1100.xlsx";
			newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.0001";
			newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 1.01097E-12;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 2.22045E-16;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0;
			FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "22222222.xlsx";
			newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.0001";
			newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 1.01097E-12;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 2.22045E-16;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0;
			newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0;
			FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

		
			/*
PGA(g)	Slight	Moderate	Severe	Collapse
0.0001	0	0	0	0
0.01	1.01097E-12	2.22045E-16	0	0
0.02	8.14646E-10	6.14842E-13	1.11022E-16	0
0.03	2.59146E-08	3.61315E-11	1.64313E-14	0
0.04	2.46427E-07	5.30214E-10	3.72258E-13	0
0.05	1.25991E-06	3.79129E-09	3.73268E-12	1.11022E-16
0.06	4.43621E-06	1.75446E-08	2.2759E-11	6.66134E-16
0.07	1.22071E-05	6.0787E-08	9.95209E-11	3.66374E-15


			*/
		}


		static property Dictionary<String^, String^>^ FragilityCurvDict {
			Dictionary<String^, String^>^ get() {
				return FragilityDataSet::m_FragilityCurvDict;
			}
		}

		static property DataTable^ FragilityCurvData {
			DataTable^ get() {
				return FragilityDataSet::m_FragilityCurvData;
			}
		}

	};
}