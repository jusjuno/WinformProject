#pragma once
#include "CommConst.h"
#include "ProjectDataSetBinder.h"

using namespace System;
using namespace System::Data;
using namespace System::Diagnostics;

namespace WinformProject {
	/// <summary>
	/// soil amplification factor class
	/// </summary>
	public ref class SoilAmp
	{
	private:
		int soilTypeCount = CommConst::SOIL_TYPE_COUNT; // soil type A~E
		int colIndex = CommConst::COL_NATURAL_PERIOD;   //�ڿ��ֱⰡ �Ҵ�� Į����ȣ (0)
		double soilAmpFactor;
		int soilAmpDataCount;

		DataTable^					m_soilDataTable;

	public:
		SoilAmp() {
		}
		SoilAmp(DataTable^ parameterTable) {
			this->SetParameters(parameterTable);
		}
		property int SoilAmpFactor {
			int get() {
				return this->soilAmpFactor;
			}
		}
	public:
		// claculate amplification factor
		//soilType�� A~E �� 1~5 �� ��ȯ 
		//void CalcSoilAmpFactor(int compID) {
		double CalcSoilAmpFactor(int soilType, double naturalPeriod) {
			//=======================================
			// Natural Period�� ���� amp factor ���
			//=======================================
			// �����������(soil amplification factor)�� �������İ� �������� �����ֱ⿡ ���� �����Ǹ�,
			// �Էµ� �������� �����ֱ� �� �������Ŀ� ����, �������� (ex) "psha.xlsx"���� �ش� �Ǵ� ����
			// ������(interporation)���� ã�Ƴ���.

			double currentPeriod = 0;
			double prePeriod = 0;
			double currentFactor;
			double preFactor;
			double ratio = 0;

			for (int i = 0; i < this->soilAmpDataCount; i++)
			{
				DataRow^ currentSoilRow = this->m_soilDataTable->Rows[i];
				double::TryParse(currentSoilRow[colIndex]->ToString(), currentPeriod);
				if (naturalPeriod < currentPeriod) {
					DataRow^ preSoilRow = this->m_soilDataTable->Rows[i - 1];
					double::TryParse(preSoilRow[colIndex]->ToString(), prePeriod);
					ratio = (currentPeriod - naturalPeriod) / (currentPeriod - prePeriod);
					// factor ���
					double::TryParse(currentSoilRow[soilType]->ToString(), currentFactor);
					double::TryParse(preSoilRow[soilType]->ToString(), preFactor);
					this->soilAmpFactor = preFactor + (currentFactor - preFactor) * ratio;
					break;
				}
			}
			return this->soilAmpFactor;
		}

	private:
		void SetParameters(DataTable^ table) {
			this->soilAmpDataCount = table->Rows->Count;
			this->m_soilDataTable = table;
		}	
	};
}