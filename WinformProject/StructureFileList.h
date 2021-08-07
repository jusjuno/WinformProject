#pragma once
#include "StructureFile.h"
#include "FileUtil.h"
#include "CSVFileManager.h"

using namespace System;
using namespace System::Collections::Generic;



[Serializable]
public ref class StructureFileList
{

public:
	String^ sPath = "C:\\sample\\";//Structure_list_new.csv
	Dictionary<String^, StructureFile^>^ m_StructureFileDict;


public:
	StructureFileList() {
		this->m_StructureFileDict = gcnew Dictionary<String^, StructureFile^>();
	}

	StructureFileList(String^ sStructureFileName) {
		this->m_StructureFileDict = gcnew Dictionary<String^, StructureFile^>();
		setStructureFileData(sStructureFileName);
	}


public:

	property Dictionary<String^, StructureFile^>^ StructureFileDict {
		Dictionary<String^, StructureFile^>^ get() {
			return this->m_StructureFileDict;
		}
		void set(Dictionary<String^, StructureFile^>^ value) {
			this->m_StructureFileDict = value;
		}
	}


	void setStructureFileData(String^ sStructureFileName) {

		CSVFileManager^ csv = gcnew CSVFileManager(this->sPath + sStructureFileName + ".csv");
		String^ output = csv->Read();

		if (!String::IsNullOrEmpty(output)) {
			array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
			int outputRowCount = dataArray->Length;
			Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));


			bool isFind = false;
			StructureFile^ structureFile = nullptr;

			for (int i = 0; i < outputRowCount; i++)
			{
				String^ outputLineData = dataArray[i];
				//Debug::WriteLine("=================>outputLineData:" + outputLineData);

				String^ sType = "";
				double dMedian1 = 0;
				double dMedian2 = 0;
				double dMedian3 = 0;
				double dMedian4 = 0;
				double dDispersion = 0;

				/*
				double dPGA = 0;
				double dSlight = 0;
				double dModerate = 0;
				double dSevere = 0;
				double dCollapse = 0;
				*/

				if (isFind) {
					array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");

					/*
					String^ m_Type;
	double m_Median1;
	double m_Median2;
	double m_Median3;
	double m_Median4;
	double m_Dispersion
					*/
					Double::TryParse(values[1], dMedian1);
					Double::TryParse(values[2], dMedian2);
					Double::TryParse(values[3], dMedian3);
					Double::TryParse(values[4], dMedian4);
					Double::TryParse(values[5], dDispersion);

					structureFile = gcnew StructureFile();
					structureFile->Type = values[0];
					structureFile->Median1 = dMedian1;
					structureFile->Median2 = dMedian2;
					structureFile->Median3 = dMedian3;
					structureFile->Median4 = dMedian4;
					structureFile->Dispersion = dDispersion;

					if (!this->m_StructureFileDict->ContainsKey(values[0])) {
						this->m_StructureFileDict->Add(values[0], structureFile);
					}
					
				}

				if (outputLineData->IndexOf("Type") >= 0) {
					isFind = true;
				}
			}
		}
	}


};
