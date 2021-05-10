#pragma once
#include "ProjectDataSetBinder.h"
#include "DamageAnalyzer.h"
#include "NetworkComponent.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows;

namespace WinformProject {

	/// <summary>
	/// Recovery cost class
	/// </summary>
	public ref class RecoveryCost {
	private:
		ProjectDataSetBinder^		m_dataSet;
		DamageAnalyzer^				m_damageAnalyzer;
		NetworkComponent^			m_networkComponent;
	public:
		RecoveryCost(ProjectDataSetBinder^ dataSet) {
			this->m_dataSet = dataSet;
			this->m_damageAnalyzer = gcnew DamageAnalyzer(dataSet);

			this->estimatedTotalNetworkCost = 0;
			this->estimatedTotalTrafficCost = 0;
			this->resilienceIndicesECO = 0;
			this->resilienceIndicesCON = 0;
			this->resilienceIndicesENV = 0;
			this->m_networkComponent = gcnew NetworkComponent(dataSet);
		}
	private:
		double estimatedTotalNetworkCost;
		double estimatedTotalTrafficCost;

		double resilienceIndicesECO;
		double resilienceIndicesCON;
		double resilienceIndicesENV;

	public:
		property double EstimatedTotalNetworkCost {
			double get() {
				return this->estimatedTotalNetworkCost;
			}
			void set(double value) {
				this->estimatedTotalNetworkCost = value;
			}
		}
		property double EstimatedTotalTrafficCost {
			double get() {
				return this->estimatedTotalTrafficCost;
			}
			void set(double value) {
				this->estimatedTotalTrafficCost = value;
			}
		}
		property double EstimatedTotalCost {
			double get() {
				return this->estimatedTotalNetworkCost + this->estimatedTotalTrafficCost;
			}
		}
		property double ResilienceIndicesECO {
			double get() {
				return this->resilienceIndicesECO;
			}
			void set(double value) {
				this->resilienceIndicesECO = value;
			}
		}
		property double ResilienceIndicesCON {
			double get() {
				return this->resilienceIndicesCON;
			}
			void set(double value) {
				this->resilienceIndicesCON = value;
			}
		}
		property double ResilienceIndicesENV {
			double get() {
				return this->resilienceIndicesENV;
			}
			void set(double value) {
				this->resilienceIndicesENV = value;
			}
		}

	public:
		// get estimated total network(all components struct cost) cost
		long GetEstimatedTotalNetworkCost(String^ scenarioName, String^ recurrencePeriod, String^ sample) {
			long value = 0;
			DataTable^ dataTable = m_networkComponent->Data;
			for each (DataRow^ row in dataTable->Rows)
			{
				String^ componetID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
				String^ classID = row[NetworkComponent::COL_CLASS_ID]->ToString();
				String^ locationX = row[NetworkComponent::COL_X]->ToString();
				String^ locationY = row[NetworkComponent::COL_Y]->ToString();
				unsigned long long reConstructCost = 0;
				UInt64::TryParse(row[NetworkComponent::COL_RECONSTRUCTION_COST]->ToString(), reConstructCost);

				value += GetEstimatedTotalComponentStructCost(scenarioName, recurrencePeriod, sample, componetID);
			}
			return value;
		}

		// get estimated total component struct cost
		long GetEstimatedTotalComponentStructCost(String^ scenarioName, String^ recurrencePeriod, String^ sample, String^ componentID) {
				// 컴포넌트 정보 조회
			array<DataRow^>^ foundRows = m_networkComponent->FindRows(NetworkComponent::COL_NETWORK_COMP_ID, componentID);
			if (foundRows->Length < 1) {
				return 0;
			}
			String^ classID = foundRows[0][NetworkComponent::COL_CLASS_ID]->ToString();
			String^ locationX = foundRows[0][NetworkComponent::COL_X]->ToString();
			String^ locationY = foundRows[0][NetworkComponent::COL_Y]->ToString();
			unsigned long long reConstructCost = 0;
			UInt64::TryParse(foundRows[0][NetworkComponent::COL_RECONSTRUCTION_COST]->ToString(), reConstructCost);

			// 소스 데이터 조회
			DataTable^ seismicSource = m_dataSet->SeismicSourceDictionary[scenarioName];

			String^ filter = "[" + CommConst::GRID_SEISMIC_SOURCES_COL1 + "]='" + locationX + "' and [" + CommConst::GRID_SEISMIC_SOURCES_COL2 + "]='" + locationY + "'";
			foundRows = seismicSource->Select(filter);
			if (foundRows->Length < 1) {
				return 0;
			}
			
			int tmpIndex = -1;
			// recurrence 위치를 찾아서 seismic source 데이터에서의 recurrence 컬럼 위치를 찾는다.
			for (int i = 0; i < m_dataSet->RecurrencePeriodData->Length; i++)
			{
				if (recurrencePeriod == m_dataSet->RecurrencePeriodData[i]) {
					tmpIndex = i;
					break;
				}
			}
			long value = 0.0;
			if (tmpIndex > -1) {
				double sa = 0;
				Double::TryParse(foundRows[0][tmpIndex + 2]->ToString(), sa);
				value = reConstructCost * m_damageAnalyzer->GetTotalDirectDamageRate(classID, sa);
			}
			//CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1;
			//m_dataSet->m_repairCostRatioParams;
			//m_dataSet->RecurrencePeriodData->Length;

				return value;
		}
	};
}