#pragma once
#include "FragilityFile.h"
#include "FileUtil.h"
#include "CSVFileManager.h"

using namespace System;
using namespace System::Collections::Generic;



[Serializable]
public ref class FragilityDataSet
{

public:
	String^ sPath = "C:\\sample\\Fragility_Curve_Library\\";
	Dictionary<double, FragilityFile^>^ m_FragilityFileDict;


public:
	FragilityDataSet() {
		this->m_FragilityFileDict = gcnew Dictionary<double, FragilityFile^>();
	}

	FragilityDataSet(String^ sFragilityCurvFileName) {
		this->m_FragilityFileDict = gcnew Dictionary<double, FragilityFile^>();
		setFragilityCurvFile(sFragilityCurvFileName);
	}


public:
		
	property Dictionary<double, FragilityFile^>^ FragilityFileDict {
		Dictionary<double, FragilityFile^>^ get() {
			return this->m_FragilityFileDict;
		}
		void set(Dictionary<double, FragilityFile^>^ value) {
			this->m_FragilityFileDict = value;
		}
	}


	void setFragilityCurvFile(String^ sFragilityCurvFileName) {

		CSVFileManager^ csv = gcnew CSVFileManager(this->sPath + sFragilityCurvFileName + ".csv");
		String^ output = csv->Read();

		if (!String::IsNullOrEmpty(output)) {
			array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
			int outputRowCount = dataArray->Length;
			Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));


			bool isFind = false;
			FragilityFile^ fragilityFile = nullptr;

			for (int i = 0; i < outputRowCount; i++)
			{
				String^ outputLineData = dataArray[i];
				//Debug::WriteLine("=================>outputLineData:" + outputLineData);

				double dPGA = 0;
				double dSlight = 0;
				double dModerate = 0;
				double dSevere = 0;
				double dCollapse = 0;

				if (isFind) {
					array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");

					Double::TryParse(values[0], dPGA);
					Double::TryParse(values[1], dSlight);
					Double::TryParse(values[2], dModerate);
					Double::TryParse(values[3], dSevere);
					Double::TryParse(values[4], dCollapse);

					fragilityFile = gcnew FragilityFile();
					fragilityFile->FileName = sFragilityCurvFileName;
					fragilityFile->PGA = dPGA;
					fragilityFile->Slight = dSlight;
					fragilityFile->Moderate = dModerate;
					fragilityFile->Severe = dSevere;
					fragilityFile->Collapse = dCollapse;


					this->m_FragilityFileDict->Add(dPGA, fragilityFile);
				}

				if (outputLineData->IndexOf("PGA") >= 0) {
					isFind = true;
				}
			}
		}
	}
		

};
