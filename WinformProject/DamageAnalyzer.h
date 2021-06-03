#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "FragilityCurve.h"
#include "NetworkComponent.h"

using namespace System;
using namespace System::Data;
using namespace System::Diagnostics;

namespace WinformProject {
	/// <summary>
	/// fragility curve class
	/// </summary>
	public ref class DamageAnalyzer
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		FragilityCurve^				m_fragilityCurve;
//		static array<double>^		RCR = { 0, 0.02, 0.08, 0.25, 0.67, 0, 0, 0, 0 };
		static array<double>^ RCR = {	0,
										CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1,
										CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2,
										CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3,
										CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4 };
		NetworkComponent^			m_networkComponent;
	public:
		DamageAnalyzer(ProjectDataSetBinder^ dataSet) {
			this->m_dataSet = dataSet;
			this->m_fragilityCurve = gcnew FragilityCurve(this->m_dataSet->FragParameterData);
			this->m_networkComponent = gcnew NetworkComponent(dataSet);
		}
	public:
		// 직접 피해 확률(컴포넌트아이디)
		double GetComponentTotalDirectDamageRate(String^ componentID, double Sa) {
			array<DataRow^>^ foundRows = m_networkComponent->FindRows(NetworkComponent::COL_NETWORK_COMP_ID, componentID);
			if (foundRows->Length < 1) {
				return 0;
			}
			String^ classID = foundRows[0][m_networkComponent->GetColumnName(NetworkComponent::COL_CLASS_ID)]->ToString();
			return GetTotalDirectDamageRate(classID, Sa);
		}
		// 총 직접 피해 확률
		// 모든 damage state의 피해 확률 합
		/*
		double GetTotalDirectDamageRate(String^ classID, double Sa) {
			double totalDamageRate = 0.0;

			array<double>^ dsArr = m_fragilityCurve->GetFragilityValues(classID, Sa);

			for (int i = 0; i < dsArr->Length; i++)
			{
				double p1 = dsArr[i];
				double p2 = (i + 1 == dsArr->Length) ? 0 : dsArr[i + 1];
//				double rcr = (i == 0) ? 1 : RCR[i];
//				totalDamageRate += (p1 - p2) * rcr;
				totalDamageRate += (p1 - p2) * RCR[i];
			}

			return totalDamageRate;
		}
		*/

		double GetTotalDirectDamageRate(String^ classID, double Sa) {
			double totalDamageRate = 0.0;

			String^ columnName = m_dataSet->NetworkCompnentData->Columns[NetworkComponent::COL_CLASS_ID]->ColumnName;
			array<DataRow^>^ foundRows = m_dataSet->NetworkCompnentData->Select(String::Format("[{0}]='{1}'", columnName, classID));
			if (foundRows->Length < 1) {
				return totalDamageRate;
			}
			String^ componentID = StringUtil::nullToString(foundRows[0][NetworkComponent::COL_NETWORK_COMP_ID], "");

			//array<double>^ dsArr = m_fragilityCurve->GetFragilityValues(classID, Sa);
			array<double>^ dsArr = m_fragilityCurve->GetFragilityValues(this->m_dataSet, componentID, Sa);

			for (int i = 0; i < dsArr->Length; i++)
			{
				double p1 = dsArr[i];
				double p2 = (i + 1 == dsArr->Length) ? 0 : dsArr[i + 1];
				totalDamageRate += (p1 - p2) * RCR[i];
			}

			return totalDamageRate;
		}

		



		// 직접 피해 확률
		// 특정 damage state의 피해 확률
		double GetDirectDamageRate(String^ damageState) {
			return 0;
		}
	};
}