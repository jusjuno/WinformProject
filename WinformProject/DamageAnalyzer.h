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
		// ���� ���� Ȯ��(������Ʈ���̵�)
		double GetComponentTotalDirectDamageRate(String^ componentID, double Sa) {
			array<DataRow^>^ foundRows = m_networkComponent->FindRows(NetworkComponent::COL_NETWORK_COMP_ID, componentID);
			if (foundRows->Length < 1) {
				return 0;
			}
			String^ classID = foundRows[0][m_networkComponent->GetColumnName(NetworkComponent::COL_CLASS_ID)]->ToString();
			return GetTotalDirectDamageRate(classID, Sa);
		}
		// �� ���� ���� Ȯ��
		// ��� damage state�� ���� Ȯ�� ��
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
		// ���� ���� Ȯ��
		// Ư�� damage state�� ���� Ȯ��
		double GetDirectDamageRate(String^ damageState) {
			return 0;
		}
	};
}