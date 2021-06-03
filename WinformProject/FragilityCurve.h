#pragma once
#include "CustomMath.h"
#include "FragilityCompList.h"
#include "NetworkComponent.h"

using namespace System;
using namespace System::Data;
using namespace System::Diagnostics;

namespace WinformProject {
	/// <summary>
	/// fragility curve class
	/// </summary>
	public ref class FragilityCurve
	{
	private:
		int damageStateCount = CommConst::DAMAGE_STATE_COUNT + 1; // damage state 0~4
		Dictionary<String^, int>^ m_classIndexMap;
		array<array<double>^>^ m_aiParameters; // [class index][damage state 0~]
		array<array<double>^>^ m_bcParameters; // [class index][damage state 0~]
	public:
		FragilityCurve() {
		}
		FragilityCurve(DataTable^ parameterTable) {
			this->SetParameters(parameterTable);
		}
		property int DamageStateCount {
			int get() {
				return this->damageStateCount;
			}
		}
	public:
		// claculate fragility cureve
		static double CalculateFragilityValue(double Sa, double Ai, double Bc) {
			double lnAi = log(Ai);
			double value = CustomMath::LOGNORMSDIST(Sa, lnAi, Bc);
			Debug::WriteLine(String::Format("Sa={0}, Ai={1}, Bc={2}, value={3}", Sa, Ai, Bc, value));
			return value;
		}
	private:
		int GetClassIndex(String^ classID) {
			// ClassID와 같은 데이터 찾기
			if (!this->m_classIndexMap->ContainsKey(classID)) {
				Debug::WriteLine(String::Format("There are not fragility curve parameters of {0}.", classID));
				return -1;
			}
			return this->m_classIndexMap[classID];
		}
	public:
		void SetParameters(DataTable^ table) {
			this->m_classIndexMap = gcnew Dictionary<String^, int>();
			this->m_aiParameters = gcnew array<array<double>^>(table->Rows->Count);
			this->m_bcParameters = gcnew array<array<double>^>(table->Rows->Count);

			for (int i = 0; i < table->Rows->Count; i++)
			{
				DataRow^ row = table->Rows[i];
				String^ classID = row[CommConst::GRID_FRAG_CURVE_PARAM_COL1]->ToString();
				m_classIndexMap->Add(classID, i);
				m_aiParameters[i] = gcnew array<double>(damageStateCount);
				m_bcParameters[i] = gcnew array<double>(damageStateCount);
				for (int j = 0; j < damageStateCount; j++) 
				{
					// DS0은 모두 0
					if (j == 0) {
						m_aiParameters[i][j] = 0;
						m_bcParameters[i][j] = 0;
					}
					else {
						int colIndex = j * 2 - 1; // DS1 = 1(1), DS2 = 3(2), DS3 = 5(3), DS4 = 7(4)
						double::TryParse(row[colIndex]->ToString(), m_aiParameters[i][j]);
						double::TryParse(row[colIndex + 1]->ToString(), m_bcParameters[i][j]);
					}
				}
			}
		}
		double GetAi(String^ classID, int damageState) {
			int classIndex = GetClassIndex(classID);
			if (classIndex >= 0) {
				if (damageState < m_aiParameters[classIndex]->Length) {
					return m_aiParameters[classIndex][damageState];
				}
			}
			return 0;
		}
		double GetBc(String^ classID, int damageState) {
			int classIndex = GetClassIndex(classID);
			if (classIndex >= 0) {
				if (damageState < m_bcParameters[classIndex]->Length) {
					return m_bcParameters[classIndex][damageState];
				}
			}
			return 0;
		}	
		// damageState = 0, 1, 2, 3, 4
		double GetFragilityValue(String^ classID, int damageState, double Sa) {
			double Ai = GetAi(classID, damageState);
			double Bc = GetBc(classID, damageState);
			return FragilityCurve::CalculateFragilityValue(Sa, Ai, Bc);
		}
		// damageState 별 fragility value를 모두 리턴
		array<double>^ GetFragilityValues(String^ classID, double Sa) {
			array<double>^ dsArr = gcnew array<double>(DamageStateCount);
			for (int i = 0; i < DamageStateCount; i++)
			{
				dsArr[i] = GetFragilityValue(classID, i, Sa);
			}
			return dsArr;
		}

		
		// damageState = 0, 1, 2, 3, 4
		double GetFragilityValue(ProjectDataSetBinder^ m_dataSet, String^ componentID, int damageState, double Sa) {


			FragilityDataSet^ fragilityDataSet = nullptr;
			if (m_dataSet->FragilityDataSetDictionary->ContainsKey(componentID)) {
				fragilityDataSet = m_dataSet->FragilityDataSetDictionary[componentID];
			}
			else {
				fragilityDataSet = GetFragilityReadFile(m_dataSet, componentID);
			}



			//get Data
			if (fragilityDataSet != nullptr) {
				if (fragilityDataSet->FragilityFileDict->ContainsKey(Sa)) {
					FragilityFile^ m_FragilityFile = fragilityDataSet->FragilityFileDict[Sa];
					if (damageState == 1) {
						return m_FragilityFile->Slight;
					}
					else if (damageState == 2) {
						return m_FragilityFile->Moderate;
					}
					else if (damageState == 3) {
						return m_FragilityFile->Severe;
					}
					else if (damageState == 4) {
						return m_FragilityFile->Collapse;
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
			
		}
		// damageState 별 fragility value를 모두 리턴
		array<double>^ GetFragilityValues(ProjectDataSetBinder^ m_dataSet, String^ componentID, double Sa) {

			array<double>^ dsArr = gcnew array<double>(DamageStateCount);


			FragilityDataSet^ fragilityDataSet = nullptr;
			if (m_dataSet->FragilityDataSetDictionary->ContainsKey(componentID)) {
				fragilityDataSet = m_dataSet->FragilityDataSetDictionary[componentID];
			}
			else {
				fragilityDataSet = GetFragilityReadFile(m_dataSet, componentID);
			}

			if (fragilityDataSet != nullptr) {
				if (fragilityDataSet->FragilityFileDict->ContainsKey(Sa)) {
					FragilityFile^ m_FragilityFile = fragilityDataSet->FragilityFileDict[Sa];
					dsArr[0] = 0;
					dsArr[1] = m_FragilityFile->Slight;
					dsArr[2] = m_FragilityFile->Moderate;
					dsArr[3] = m_FragilityFile->Severe;
					dsArr[4] = m_FragilityFile->Collapse;
					return dsArr;
				}
				else {
					return dsArr;
				}
			}
			else {
				return dsArr;
			}
			
			/*
			for (int i = 0; i < DamageStateCount; i++)
			{
				dsArr[i] = GetFragilityValue(classID, i, Sa);
			}*/
			
		}


		FragilityDataSet^ GetFragilityReadFile(ProjectDataSetBinder^ m_dataSet, String^ componentID) {
			FragilityDataSet^ fragilityDataSet = nullptr;
			//파일 read
			Dictionary<String^, String^>^ fragilityCompDict = WinformProject::FragilityCompList::CompDict;

			String^ columnName = m_dataSet->NetworkCompnentData->Columns[NetworkComponent::COL_NETWORK_COMP_ID]->ColumnName;
			array<DataRow^>^ foundRows = m_dataSet->NetworkCompnentData->Select(String::Format("[{0}]='{1}'", columnName, componentID));
			if (foundRows->Length < 1) {
				return fragilityDataSet;
				//Alert::Error("No matching data file!");
			}

			String^ classID = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_CLASS_ID], "");
			String^ upperType = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_UPPER_TYPE], "-");
			String^ continuity = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_CONTINUITY], "-");
			String^ bridgeHeight = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_BRIDGE_HEIGHT], "-");
			String^ bottomType = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_BOTTOM_TYPE], "-");
			String^ elastomericShoe = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_ELASTOMERIC_SHOE], "-");
			String^ briddgeFoundation = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_BRIDGE_FOUNDATION], "-");
			String^ seismicDesignYn = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_SEISMIC_DESIGN_YN], "-");
			String^ oldBridge = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_OLD_BRIDGE], "-");
			String^ oldShoe = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_OLD_SHOE], "-");
			String^ repairBridge = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_REPAIR_BRIDGE], "-");
			String^ repairShoe = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_REPAIR_SHOE], "-");

			String^ selectComponentKey = upperType + "_" + continuity + "_" + bridgeHeight + "_" + bottomType + "_"
				+ elastomericShoe + "_" + briddgeFoundation + "_" + seismicDesignYn + "_"
				+ oldBridge + "_" + oldShoe + "_" + repairBridge + "_" + repairShoe;

			if (fragilityCompDict->ContainsKey(selectComponentKey)) {
				String^ sFragilityCurvFileName = fragilityCompDict[selectComponentKey];
				fragilityDataSet = gcnew FragilityDataSet(sFragilityCurvFileName);

				m_dataSet->FragilityDataSetDictionary->Add(componentID, fragilityDataSet);

				Debug::WriteLine("=================>count:" + fragilityDataSet->m_FragilityFileDict->Count);
			}
			else {
				return nullptr;
				//Alert::Error("No matching data file!");
			}
			return fragilityDataSet;
		}



	};
}