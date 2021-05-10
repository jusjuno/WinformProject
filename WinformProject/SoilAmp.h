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
		int colIndex = CommConst::COL_NATURAL_PERIOD;   //자연주기가 할당된 칼럼번호 (0)
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
		//soilType은 A~E 를 1~5 로 변환 
		//void CalcSoilAmpFactor(int compID) {
		double CalcSoilAmpFactor(int soilType, double naturalPeriod) {
			//=======================================
			// Natural Period에 따른 amp factor 계산
			//=======================================
			// 지반증폭계수(soil amplification factor)는 지반형식과 구조물의 고유주기에 따라 결정되며,
			// 입력된 구조물의 고유주기 및 지반형식에 따라, 엑셀파일 (ex) "psha.xlsx"에서 해당 되는 값을
			// 보간법(interporation)으로 찾아낸다.

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
					// factor 계산
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