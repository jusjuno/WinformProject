#pragma once
#include "FragilityFile.h"
#include "FileUtil.h"
#include "CSVFileManager.h"

using namespace System;
using namespace System::Collections::Generic;

namespace WinformProject {

	public ref class FragilityDataSet
	{
	public:
		FragilityDataSet() {
			this->m_FragilityFileDict = gcnew Dictionary<double, FragilityFile^>();
		}

		FragilityDataSet(String^ sFragilityCurvFileName) {
			this->m_FragilityFileDict = gcnew Dictionary<double, FragilityFile^>();
			setFragilityCurvFile(sFragilityCurvFileName);
		}


	public:
		static Dictionary<String^, String^>^ m_FragilityCurvDict;
		//static DataTable^                    m_FragilityCurvData;

		static String^ sPath = "C:\\sample\\Fragility_Curve_Library\\";
		Dictionary<double, FragilityFile^>^ m_FragilityFileDict;

	public:
		static void setFragilityCurvDict() {
			FragilityDataSet::m_FragilityCurvDict = gcnew Dictionary<String^, String^>();

			//m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_X_X_X", "PB301203_00111_0000.xlsx");
			//PSC Beam_다경간_5m이하_단주_일반_확대_C_O_X_X

			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_일반_-_-_-_X_-_X", "PB301201_00000_0000");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_일반_-_-_-_X_-_O", "PB301201_00000_0001");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_일반_-_-_-_O_-_X", "PB301201_00000_0100");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_일반_-_-_-_O_-_O", "PB301201_00000_0101");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_탄성_-_-_-_X_-_X", "PB301201_00100_0000");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_탄성_-_-_-_X_-_O", "PB301201_00100_0001");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_탄성_-_-_-_O_-_X", "PB301201_00100_0100");
			m_FragilityCurvDict->Add("PSC Beam_단경간_-_-_탄성_-_-_-_O_-_O", "PB301201_00100_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_X_X_X", "PB301203_00000_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_X_X_O", "PB301203_00000_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_X_O_X", "PB301203_00000_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_X_O_O", "PB301203_00000_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_O_X_X", "PB301203_00000_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_O_X_O", "PB301203_00000_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_O_O_X", "PB301203_00000_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_X_O_O_O", "PB301203_00000_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_X_X_X", "PB301203_00000_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_X_X_O", "PB301203_00000_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_X_O_X", "PB301203_00000_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_X_O_O", "PB301203_00000_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_O_X_X", "PB301203_00000_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_O_X_O", "PB301203_00000_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_O_O_X", "PB301203_00000_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_C_O_O_O_O", "PB301203_00000_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_X_X_X", "PB301203_00001_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_X_X_O", "PB301203_00001_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_X_O_X", "PB301203_00001_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_X_O_O", "PB301203_00001_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_O_X_X", "PB301203_00001_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_O_X_O", "PB301203_00001_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_O_O_X", "PB301203_00001_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_X_O_O_O", "PB301203_00001_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_X_X_X", "PB301203_00001_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_X_X_O", "PB301203_00001_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_X_O_X", "PB301203_00001_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_X_O_O", "PB301203_00001_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_O_X_X", "PB301203_00001_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_O_X_O", "PB301203_00001_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_O_O_X", "PB301203_00001_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_말뚝_S_O_O_O_O", "PB301203_00001_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_X_X_X", "PB301203_00010_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_X_X_O", "PB301203_00010_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_X_O_X", "PB301203_00010_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_X_O_O", "PB301203_00010_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_O_X_X", "PB301203_00010_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_O_X_O", "PB301203_00010_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_O_O_X", "PB301203_00010_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_X_O_O_O", "PB301203_00010_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_X_X_X", "PB301203_00010_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_X_X_O", "PB301203_00010_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_X_O_X", "PB301203_00010_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_X_O_O", "PB301203_00010_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_O_X_X", "PB301203_00010_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_O_X_O", "PB301203_00010_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_O_O_X", "PB301203_00010_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_C_O_O_O_O", "PB301203_00010_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_X_X_X", "PB301203_00011_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_X_X_O", "PB301203_00011_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_X_O_X", "PB301203_00011_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_X_O_O", "PB301203_00011_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_O_X_X", "PB301203_00011_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_O_X_O", "PB301203_00011_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_O_O_X", "PB301203_00011_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_X_O_O_O", "PB301203_00011_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_X_X_X", "PB301203_00011_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_X_X_O", "PB301203_00011_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_X_O_X", "PB301203_00011_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_X_O_O", "PB301203_00011_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_O_X_X", "PB301203_00011_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_O_X_O", "PB301203_00011_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_O_O_X", "PB301203_00011_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_일반_확대_S_O_O_O_O", "PB301203_00011_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_X_X_X", "PB301203_00100_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_X_X_O", "PB301203_00100_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_X_O_X", "PB301203_00100_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_X_O_O", "PB301203_00100_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_O_X_X", "PB301203_00100_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_O_X_O", "PB301203_00100_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_O_O_X", "PB301203_00100_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_X_O_O_O", "PB301203_00100_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_X_X_X", "PB301203_00100_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_X_X_O", "PB301203_00100_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_X_O_X", "PB301203_00100_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_X_O_O", "PB301203_00100_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_O_X_X", "PB301203_00100_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_O_X_O", "PB301203_00100_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_O_O_X", "PB301203_00100_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_C_O_O_O_O", "PB301203_00100_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_X_X_X", "PB301203_00101_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_X_X_O", "PB301203_00101_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_X_O_X", "PB301203_00101_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_X_O_O", "PB301203_00101_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_O_X_X", "PB301203_00101_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_O_X_O", "PB301203_00101_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_O_O_X", "PB301203_00101_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_X_O_O_O", "PB301203_00101_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_X_X_X", "PB301203_00101_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_X_X_O", "PB301203_00101_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_X_O_X", "PB301203_00101_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_X_O_O", "PB301203_00101_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_O_X_X", "PB301203_00101_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_O_X_O", "PB301203_00101_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_O_O_X", "PB301203_00101_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_말뚝_S_O_O_O_O", "PB301203_00101_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_X_X_X", "PB301203_00110_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_X_X_O", "PB301203_00110_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_X_O_X", "PB301203_00110_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_X_O_O", "PB301203_00110_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_O_X_X", "PB301203_00110_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_O_X_O", "PB301203_00110_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_O_O_X", "PB301203_00110_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_X_O_O_O", "PB301203_00110_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_X_X_X", "PB301203_00110_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_X_X_O", "PB301203_00110_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_X_O_X", "PB301203_00110_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_X_O_O", "PB301203_00110_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_O_X_X", "PB301203_00110_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_O_X_O", "PB301203_00110_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_O_O_X", "PB301203_00110_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_C_O_O_O_O", "PB301203_00110_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_X_X_X", "PB301203_00111_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_X_X_O", "PB301203_00111_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_X_O_X", "PB301203_00111_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_X_O_O", "PB301203_00111_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_O_X_X", "PB301203_00111_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_O_X_O", "PB301203_00111_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_O_O_X", "PB301203_00111_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_X_O_O_O", "PB301203_00111_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_X_X_X", "PB301203_00111_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_X_X_O", "PB301203_00111_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_X_O_X", "PB301203_00111_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_X_O_O", "PB301203_00111_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_O_X_X", "PB301203_00111_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_O_X_O", "PB301203_00111_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_O_O_X", "PB301203_00111_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_단주_탄성_확대_S_O_O_O_O", "PB301203_00111_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_X_X_X", "PB301203_01000_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_X_X_O", "PB301203_01000_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_X_O_X", "PB301203_01000_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_X_O_O", "PB301203_01000_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_O_X_X", "PB301203_01000_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_O_X_O", "PB301203_01000_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_O_O_X", "PB301203_01000_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_X_O_O_O", "PB301203_01000_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_X_X_X", "PB301203_01000_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_X_X_O", "PB301203_01000_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_X_O_X", "PB301203_01000_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_X_O_O", "PB301203_01000_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_O_X_X", "PB301203_01000_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_O_X_O", "PB301203_01000_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_O_O_X", "PB301203_01000_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_C_O_O_O_O", "PB301203_01000_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_X_X_X", "PB301203_01001_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_X_X_O", "PB301203_01001_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_X_O_X", "PB301203_01001_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_X_O_O", "PB301203_01001_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_O_X_X", "PB301203_01001_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_O_X_O", "PB301203_01001_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_O_O_X", "PB301203_01001_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_X_O_O_O", "PB301203_01001_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_X_X_X", "PB301203_01001_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_X_X_O", "PB301203_01001_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_X_O_X", "PB301203_01001_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_X_O_O", "PB301203_01001_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_O_X_X", "PB301203_01001_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_O_X_O", "PB301203_01001_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_O_O_X", "PB301203_01001_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_말뚝_S_O_O_O_O", "PB301203_01001_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_X_X_X", "PB301203_01010_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_X_X_O", "PB301203_01010_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_X_O_X", "PB301203_01010_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_X_O_O", "PB301203_01010_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_O_X_X", "PB301203_01010_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_O_X_O", "PB301203_01010_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_O_O_X", "PB301203_01010_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_X_O_O_O", "PB301203_01010_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_X_X_X", "PB301203_01010_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_X_X_O", "PB301203_01010_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_X_O_X", "PB301203_01010_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_X_O_O", "PB301203_01010_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_O_X_X", "PB301203_01010_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_O_X_O", "PB301203_01010_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_O_O_X", "PB301203_01010_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_C_O_O_O_O", "PB301203_01010_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_X_X_X", "PB301203_01011_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_X_X_O", "PB301203_01011_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_X_O_X", "PB301203_01011_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_X_O_O", "PB301203_01011_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_O_X_X", "PB301203_01011_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_O_X_O", "PB301203_01011_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_O_O_X", "PB301203_01011_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_X_O_O_O", "PB301203_01011_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_X_X_X", "PB301203_01011_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_X_X_O", "PB301203_01011_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_X_O_X", "PB301203_01011_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_X_O_O", "PB301203_01011_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_O_X_X", "PB301203_01011_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_O_X_O", "PB301203_01011_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_O_O_X", "PB301203_01011_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_일반_확대_S_O_O_O_O", "PB301203_01011_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_X_X_X", "PB301203_01100_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_X_X_O", "PB301203_01100_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_X_O_X", "PB301203_01100_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_X_O_O", "PB301203_01100_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_O_X_X", "PB301203_01100_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_O_X_O", "PB301203_01100_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_O_O_X", "PB301203_01100_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_X_O_O_O", "PB301203_01100_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_X_X_X", "PB301203_01100_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_X_X_O", "PB301203_01100_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_X_O_X", "PB301203_01100_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_X_O_O", "PB301203_01100_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_O_X_X", "PB301203_01100_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_O_X_O", "PB301203_01100_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_O_O_X", "PB301203_01100_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_C_O_O_O_O", "PB301203_01100_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_X_X_X", "PB301203_01101_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_X_X_O", "PB301203_01101_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_X_O_X", "PB301203_01101_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_X_O_O", "PB301203_01101_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_O_X_X", "PB301203_01101_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_O_X_O", "PB301203_01101_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_O_O_X", "PB301203_01101_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_X_O_O_O", "PB301203_01101_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_X_X_X", "PB301203_01101_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_X_X_O", "PB301203_01101_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_X_O_X", "PB301203_01101_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_X_O_O", "PB301203_01101_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_O_X_X", "PB301203_01101_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_O_X_O", "PB301203_01101_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_O_O_X", "PB301203_01101_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_말뚝_S_O_O_O_O", "PB301203_01101_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_X_X_X", "PB301203_01110_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_X_X_O", "PB301203_01110_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_X_O_X", "PB301203_01110_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_X_O_O", "PB301203_01110_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_O_X_X", "PB301203_01110_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_O_X_O", "PB301203_01110_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_O_O_X", "PB301203_01110_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_X_O_O_O", "PB301203_01110_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_X_X_X", "PB301203_01110_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_X_X_O", "PB301203_01110_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_X_O_X", "PB301203_01110_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_X_O_O", "PB301203_01110_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_O_X_X", "PB301203_01110_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_O_X_O", "PB301203_01110_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_O_O_X", "PB301203_01110_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_C_O_O_O_O", "PB301203_01110_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_X_X_X", "PB301203_01111_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_X_X_O", "PB301203_01111_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_X_O_X", "PB301203_01111_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_X_O_O", "PB301203_01111_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_O_X_X", "PB301203_01111_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_O_X_O", "PB301203_01111_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_O_O_X", "PB301203_01111_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_X_O_O_O", "PB301203_01111_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_X_X_X", "PB301203_01111_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_X_X_O", "PB301203_01111_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_X_O_X", "PB301203_01111_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_X_O_O", "PB301203_01111_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_O_X_X", "PB301203_01111_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_O_X_O", "PB301203_01111_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_O_O_X", "PB301203_01111_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이하_다주_탄성_확대_S_O_O_O_O", "PB301203_01111_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_X_X_X", "PB301203_10000_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_X_X_O", "PB301203_10000_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_X_O_X", "PB301203_10000_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_X_O_O", "PB301203_10000_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_O_X_X", "PB301203_10000_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_O_X_O", "PB301203_10000_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_O_O_X", "PB301203_10000_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_X_O_O_O", "PB301203_10000_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_X_X_X", "PB301203_10000_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_X_X_O", "PB301203_10000_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_X_O_X", "PB301203_10000_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_X_O_O", "PB301203_10000_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_O_X_X", "PB301203_10000_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_O_X_O", "PB301203_10000_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_O_O_X", "PB301203_10000_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_C_O_O_O_O", "PB301203_10000_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_X_X_X", "PB301203_10001_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_X_X_O", "PB301203_10001_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_X_O_X", "PB301203_10001_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_X_O_O", "PB301203_10001_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_O_X_X", "PB301203_10001_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_O_X_O", "PB301203_10001_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_O_O_X", "PB301203_10001_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_X_O_O_O", "PB301203_10001_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_X_X_X", "PB301203_10001_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_X_X_O", "PB301203_10001_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_X_O_X", "PB301203_10001_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_X_O_O", "PB301203_10001_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_O_X_X", "PB301203_10001_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_O_X_O", "PB301203_10001_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_O_O_X", "PB301203_10001_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_말뚝_S_O_O_O_O", "PB301203_10001_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_X_X_X", "PB301203_10010_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_X_X_O", "PB301203_10010_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_X_O_X", "PB301203_10010_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_X_O_O", "PB301203_10010_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_O_X_X", "PB301203_10010_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_O_X_O", "PB301203_10010_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_O_O_X", "PB301203_10010_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_X_O_O_O", "PB301203_10010_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_X_X_X", "PB301203_10010_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_X_X_O", "PB301203_10010_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_X_O_X", "PB301203_10010_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_X_O_O", "PB301203_10010_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_O_X_X", "PB301203_10010_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_O_X_O", "PB301203_10010_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_O_O_X", "PB301203_10010_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_C_O_O_O_O", "PB301203_10010_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_X_X_X", "PB301203_10011_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_X_X_O", "PB301203_10011_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_X_O_X", "PB301203_10011_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_X_O_O", "PB301203_10011_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_O_X_X", "PB301203_10011_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_O_X_O", "PB301203_10011_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_O_O_X", "PB301203_10011_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_X_O_O_O", "PB301203_10011_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_X_X_X", "PB301203_10011_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_X_X_O", "PB301203_10011_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_X_O_X", "PB301203_10011_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_X_O_O", "PB301203_10011_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_O_X_X", "PB301203_10011_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_O_X_O", "PB301203_10011_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_O_O_X", "PB301203_10011_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_일반_확대_S_O_O_O_O", "PB301203_10011_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_X_X_X", "PB301203_10100_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_X_X_O", "PB301203_10100_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_X_O_X", "PB301203_10100_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_X_O_O", "PB301203_10100_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_O_X_X", "PB301203_10100_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_O_X_O", "PB301203_10100_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_O_O_X", "PB301203_10100_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_X_O_O_O", "PB301203_10100_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_X_X_X", "PB301203_10100_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_X_X_O", "PB301203_10100_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_X_O_X", "PB301203_10100_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_X_O_O", "PB301203_10100_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_O_X_X", "PB301203_10100_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_O_X_O", "PB301203_10100_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_O_O_X", "PB301203_10100_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_C_O_O_O_O", "PB301203_10100_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_X_X_X", "PB301203_10101_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_X_X_O", "PB301203_10101_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_X_O_X", "PB301203_10101_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_X_O_O", "PB301203_10101_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_O_X_X", "PB301203_10101_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_O_X_O", "PB301203_10101_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_O_O_X", "PB301203_10101_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_X_O_O_O", "PB301203_10101_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_X_X_X", "PB301203_10101_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_X_X_O", "PB301203_10101_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_X_O_X", "PB301203_10101_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_X_O_O", "PB301203_10101_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_O_X_X", "PB301203_10101_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_O_X_O", "PB301203_10101_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_O_O_X", "PB301203_10101_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_말뚝_S_O_O_O_O", "PB301203_10101_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_X_X_X", "PB301203_10110_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_X_X_O", "PB301203_10110_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_X_O_X", "PB301203_10110_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_X_O_O", "PB301203_10110_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_O_X_X", "PB301203_10110_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_O_X_O", "PB301203_10110_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_O_O_X", "PB301203_10110_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_X_O_O_O", "PB301203_10110_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_X_X_X", "PB301203_10110_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_X_X_O", "PB301203_10110_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_X_O_X", "PB301203_10110_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_X_O_O", "PB301203_10110_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_O_X_X", "PB301203_10110_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_O_X_O", "PB301203_10110_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_O_O_X", "PB301203_10110_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_C_O_O_O_O", "PB301203_10110_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_X_X_X", "PB301203_10111_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_X_X_O", "PB301203_10111_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_X_O_X", "PB301203_10111_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_X_O_O", "PB301203_10111_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_O_X_X", "PB301203_10111_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_O_X_O", "PB301203_10111_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_O_O_X", "PB301203_10111_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_X_O_O_O", "PB301203_10111_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_X_X_X", "PB301203_10111_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_X_X_O", "PB301203_10111_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_X_O_X", "PB301203_10111_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_X_O_O", "PB301203_10111_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_O_X_X", "PB301203_10111_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_O_X_O", "PB301203_10111_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_O_O_X", "PB301203_10111_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_단주_탄성_확대_S_O_O_O_O", "PB301203_10111_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_X_X_X", "PB301203_11000_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_X_X_O", "PB301203_11000_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_X_O_X", "PB301203_11000_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_X_O_O", "PB301203_11000_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_O_X_X", "PB301203_11000_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_O_X_O", "PB301203_11000_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_O_O_X", "PB301203_11000_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_X_O_O_O", "PB301203_11000_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_X_X_X", "PB301203_11000_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_X_X_O", "PB301203_11000_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_X_O_X", "PB301203_11000_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_X_O_O", "PB301203_11000_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_O_X_X", "PB301203_11000_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_O_X_O", "PB301203_11000_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_O_O_X", "PB301203_11000_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_C_O_O_O_O", "PB301203_11000_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_X_X_X", "PB301203_11001_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_X_X_O", "PB301203_11001_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_X_O_X", "PB301203_11001_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_X_O_O", "PB301203_11001_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_O_X_X", "PB301203_11001_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_O_X_O", "PB301203_11001_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_O_O_X", "PB301203_11001_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_X_O_O_O", "PB301203_11001_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_X_X_X", "PB301203_11001_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_X_X_O", "PB301203_11001_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_X_O_X", "PB301203_11001_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_X_O_O", "PB301203_11001_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_O_X_X", "PB301203_11001_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_O_X_O", "PB301203_11001_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_O_O_X", "PB301203_11001_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_말뚝_S_O_O_O_O", "PB301203_11001_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_X_X_X", "PB301203_11010_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_X_X_O", "PB301203_11010_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_X_O_X", "PB301203_11010_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_X_O_O", "PB301203_11010_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_O_X_X", "PB301203_11010_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_O_X_O", "PB301203_11010_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_O_O_X", "PB301203_11010_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_X_O_O_O", "PB301203_11010_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_X_X_X", "PB301203_11010_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_X_X_O", "PB301203_11010_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_X_O_X", "PB301203_11010_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_X_O_O", "PB301203_11010_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_O_X_X", "PB301203_11010_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_O_X_O", "PB301203_11010_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_O_O_X", "PB301203_11010_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_C_O_O_O_O", "PB301203_11010_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_X_X_X", "PB301203_11011_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_X_X_O", "PB301203_11011_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_X_O_X", "PB301203_11011_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_X_O_O", "PB301203_11011_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_O_X_X", "PB301203_11011_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_O_X_O", "PB301203_11011_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_O_O_X", "PB301203_11011_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_X_O_O_O", "PB301203_11011_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_X_X_X", "PB301203_11011_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_X_X_O", "PB301203_11011_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_X_O_X", "PB301203_11011_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_X_O_O", "PB301203_11011_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_O_X_X", "PB301203_11011_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_O_X_O", "PB301203_11011_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_O_O_X", "PB301203_11011_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_일반_확대_S_O_O_O_O", "PB301203_11011_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_X_X_X", "PB301203_11100_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_X_X_O", "PB301203_11100_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_X_O_X", "PB301203_11100_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_X_O_O", "PB301203_11100_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_O_X_X", "PB301203_11100_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_O_X_O", "PB301203_11100_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_O_O_X", "PB301203_11100_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_X_O_O_O", "PB301203_11100_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_X_X_X", "PB301203_11100_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_X_X_O", "PB301203_11100_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_X_O_X", "PB301203_11100_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_X_O_O", "PB301203_11100_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_O_X_X", "PB301203_11100_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_O_X_O", "PB301203_11100_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_O_O_X", "PB301203_11100_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_C_O_O_O_O", "PB301203_11100_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_X_X_X", "PB301203_11101_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_X_X_O", "PB301203_11101_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_X_O_X", "PB301203_11101_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_X_O_O", "PB301203_11101_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_O_X_X", "PB301203_11101_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_O_X_O", "PB301203_11101_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_O_O_X", "PB301203_11101_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_X_O_O_O", "PB301203_11101_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_X_X_X", "PB301203_11101_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_X_X_O", "PB301203_11101_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_X_O_X", "PB301203_11101_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_X_O_O", "PB301203_11101_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_O_X_X", "PB301203_11101_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_O_X_O", "PB301203_11101_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_O_O_X", "PB301203_11101_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_말뚝_S_O_O_O_O", "PB301203_11101_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_X_X_X", "PB301203_11110_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_X_X_O", "PB301203_11110_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_X_O_X", "PB301203_11110_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_X_O_O", "PB301203_11110_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_O_X_X", "PB301203_11110_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_O_X_O", "PB301203_11110_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_O_O_X", "PB301203_11110_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_X_O_O_O", "PB301203_11110_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_X_X_X", "PB301203_11110_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_X_X_O", "PB301203_11110_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_X_O_X", "PB301203_11110_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_X_O_O", "PB301203_11110_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_O_X_X", "PB301203_11110_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_O_X_O", "PB301203_11110_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_O_O_X", "PB301203_11110_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_C_O_O_O_O", "PB301203_11110_1111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_X_X_X", "PB301203_11111_0000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_X_X_O", "PB301203_11111_0001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_X_O_X", "PB301203_11111_0010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_X_O_O", "PB301203_11111_0011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_O_X_X", "PB301203_11111_0100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_O_X_O", "PB301203_11111_0101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_O_O_X", "PB301203_11111_0110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_X_O_O_O", "PB301203_11111_0111");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_X_X_X", "PB301203_11111_1000");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_X_X_O", "PB301203_11111_1001");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_X_O_X", "PB301203_11111_1010");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_X_O_O", "PB301203_11111_1011");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_O_X_X", "PB301203_11111_1100");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_O_X_O", "PB301203_11111_1101");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_O_O_X", "PB301203_11111_1110");
			m_FragilityCurvDict->Add("PSC Beam_다경간_5m이상_다주_탄성_확대_S_O_O_O_O", "PB301203_11111_1111");






			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_X_X_X", "PX501203_00000_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_X_X_O", "PX501203_00000_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_X_O_X", "PX501203_00000_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_X_O_O", "PX501203_00000_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_O_X_X", "PX501203_00000_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_O_X_O", "PX501203_00000_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_O_O_X", "PX501203_00000_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_X_O_O_O", "PX501203_00000_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_X_X_X", "PX501203_00000_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_X_X_O", "PX501203_00000_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_X_O_X", "PX501203_00000_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_X_O_O", "PX501203_00000_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_O_X_X", "PX501203_00000_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_O_X_O", "PX501203_00000_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_O_O_X", "PX501203_00000_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_C_O_O_O_O", "PX501203_00000_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_X_X_X", "PX501203_00001_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_X_X_O", "PX501203_00001_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_X_O_X", "PX501203_00001_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_X_O_O", "PX501203_00001_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_O_X_X", "PX501203_00001_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_O_X_O", "PX501203_00001_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_O_O_X", "PX501203_00001_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_X_O_O_O", "PX501203_00001_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_X_X_X", "PX501203_00001_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_X_X_O", "PX501203_00001_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_X_O_X", "PX501203_00001_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_X_O_O", "PX501203_00001_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_O_X_X", "PX501203_00001_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_O_X_O", "PX501203_00001_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_O_O_X", "PX501203_00001_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_말뚝_S_O_O_O_O", "PX501203_00001_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_X_X_X", "PX501203_00010_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_X_X_O", "PX501203_00010_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_X_O_X", "PX501203_00010_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_X_O_O", "PX501203_00010_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_O_X_X", "PX501203_00010_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_O_X_O", "PX501203_00010_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_O_O_X", "PX501203_00010_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_X_O_O_O", "PX501203_00010_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_X_X_X", "PX501203_00010_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_X_X_O", "PX501203_00010_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_X_O_X", "PX501203_00010_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_X_O_O", "PX501203_00010_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_O_X_X", "PX501203_00010_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_O_X_O", "PX501203_00010_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_O_O_X", "PX501203_00010_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_C_O_O_O_O", "PX501203_00010_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_X_X_X", "PX501203_00011_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_X_X_O", "PX501203_00011_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_X_O_X", "PX501203_00011_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_X_O_O", "PX501203_00011_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_O_X_X", "PX501203_00011_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_O_X_O", "PX501203_00011_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_O_O_X", "PX501203_00011_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_X_O_O_O", "PX501203_00011_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_X_X_X", "PX501203_00011_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_X_X_O", "PX501203_00011_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_X_O_X", "PX501203_00011_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_X_O_O", "PX501203_00011_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_O_X_X", "PX501203_00011_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_O_X_O", "PX501203_00011_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_O_O_X", "PX501203_00011_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_일반_확대_S_O_O_O_O", "PX501203_00011_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_X_X_X", "PX501203_00100_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_X_X_O", "PX501203_00100_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_X_O_X", "PX501203_00100_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_X_O_O", "PX501203_00100_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_O_X_X", "PX501203_00100_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_O_X_O", "PX501203_00100_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_O_O_X", "PX501203_00100_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_X_O_O_O", "PX501203_00100_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_X_X_X", "PX501203_00100_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_X_X_O", "PX501203_00100_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_X_O_X", "PX501203_00100_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_X_O_O", "PX501203_00100_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_O_X_X", "PX501203_00100_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_O_X_O", "PX501203_00100_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_O_O_X", "PX501203_00100_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_C_O_O_O_O", "PX501203_00100_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_X_X_X", "PX501203_00101_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_X_X_O", "PX501203_00101_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_X_O_X", "PX501203_00101_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_X_O_O", "PX501203_00101_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_O_X_X", "PX501203_00101_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_O_X_O", "PX501203_00101_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_O_O_X", "PX501203_00101_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_X_O_O_O", "PX501203_00101_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_X_X_X", "PX501203_00101_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_X_X_O", "PX501203_00101_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_X_O_X", "PX501203_00101_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_X_O_O", "PX501203_00101_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_O_X_X", "PX501203_00101_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_O_X_O", "PX501203_00101_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_O_O_X", "PX501203_00101_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_말뚝_S_O_O_O_O", "PX501203_00101_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_X_X_X", "PX501203_00110_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_X_X_O", "PX501203_00110_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_X_O_X", "PX501203_00110_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_X_O_O", "PX501203_00110_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_O_X_X", "PX501203_00110_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_O_X_O", "PX501203_00110_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_O_O_X", "PX501203_00110_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_X_O_O_O", "PX501203_00110_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_X_X_X", "PX501203_00110_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_X_X_O", "PX501203_00110_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_X_O_X", "PX501203_00110_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_X_O_O", "PX501203_00110_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_O_X_X", "PX501203_00110_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_O_X_O", "PX501203_00110_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_O_O_X", "PX501203_00110_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_C_O_O_O_O", "PX501203_00110_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_X_X_X", "PX501203_00111_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_X_X_O", "PX501203_00111_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_X_O_X", "PX501203_00111_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_X_O_O", "PX501203_00111_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_O_X_X", "PX501203_00111_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_O_X_O", "PX501203_00111_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_O_O_X", "PX501203_00111_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_X_O_O_O", "PX501203_00111_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_X_X_X", "PX501203_00111_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_X_X_O", "PX501203_00111_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_X_O_X", "PX501203_00111_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_X_O_O", "PX501203_00111_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_O_X_X", "PX501203_00111_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_O_X_O", "PX501203_00111_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_O_O_X", "PX501203_00111_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_단주_탄성_확대_S_O_O_O_O", "PX501203_00111_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_X_X_X", "PX501203_01000_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_X_X_O", "PX501203_01000_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_X_O_X", "PX501203_01000_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_X_O_O", "PX501203_01000_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_O_X_X", "PX501203_01000_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_O_X_O", "PX501203_01000_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_O_O_X", "PX501203_01000_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_X_O_O_O", "PX501203_01000_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_X_X_X", "PX501203_01000_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_X_X_O", "PX501203_01000_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_X_O_X", "PX501203_01000_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_X_O_O", "PX501203_01000_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_O_X_X", "PX501203_01000_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_O_X_O", "PX501203_01000_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_O_O_X", "PX501203_01000_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_C_O_O_O_O", "PX501203_01000_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_X_X_X", "PX501203_01001_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_X_X_O", "PX501203_01001_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_X_O_X", "PX501203_01001_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_X_O_O", "PX501203_01001_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_O_X_X", "PX501203_01001_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_O_X_O", "PX501203_01001_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_O_O_X", "PX501203_01001_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_X_O_O_O", "PX501203_01001_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_X_X_X", "PX501203_01001_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_X_X_O", "PX501203_01001_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_X_O_X", "PX501203_01001_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_X_O_O", "PX501203_01001_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_O_X_X", "PX501203_01001_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_O_X_O", "PX501203_01001_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_O_O_X", "PX501203_01001_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_말뚝_S_O_O_O_O", "PX501203_01001_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_X_X_X", "PX501203_01010_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_X_X_O", "PX501203_01010_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_X_O_X", "PX501203_01010_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_X_O_O", "PX501203_01010_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_O_X_X", "PX501203_01010_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_O_X_O", "PX501203_01010_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_O_O_X", "PX501203_01010_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_X_O_O_O", "PX501203_01010_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_X_X_X", "PX501203_01010_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_X_X_O", "PX501203_01010_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_X_O_X", "PX501203_01010_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_X_O_O", "PX501203_01010_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_O_X_X", "PX501203_01010_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_O_X_O", "PX501203_01010_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_O_O_X", "PX501203_01010_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_C_O_O_O_O", "PX501203_01010_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_X_X_X", "PX501203_01011_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_X_X_O", "PX501203_01011_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_X_O_X", "PX501203_01011_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_X_O_O", "PX501203_01011_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_O_X_X", "PX501203_01011_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_O_X_O", "PX501203_01011_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_O_O_X", "PX501203_01011_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_X_O_O_O", "PX501203_01011_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_X_X_X", "PX501203_01011_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_X_X_O", "PX501203_01011_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_X_O_X", "PX501203_01011_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_X_O_O", "PX501203_01011_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_O_X_X", "PX501203_01011_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_O_X_O", "PX501203_01011_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_O_O_X", "PX501203_01011_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_일반_확대_S_O_O_O_O", "PX501203_01011_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_X_X_X", "PX501203_01100_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_X_X_O", "PX501203_01100_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_X_O_X", "PX501203_01100_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_X_O_O", "PX501203_01100_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_O_X_X", "PX501203_01100_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_O_X_O", "PX501203_01100_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_O_O_X", "PX501203_01100_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_X_O_O_O", "PX501203_01100_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_X_X_X", "PX501203_01100_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_X_X_O", "PX501203_01100_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_X_O_X", "PX501203_01100_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_X_O_O", "PX501203_01100_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_O_X_X", "PX501203_01100_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_O_X_O", "PX501203_01100_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_O_O_X", "PX501203_01100_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_C_O_O_O_O", "PX501203_01100_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_X_X_X", "PX501203_01101_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_X_X_O", "PX501203_01101_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_X_O_X", "PX501203_01101_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_X_O_O", "PX501203_01101_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_O_X_X", "PX501203_01101_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_O_X_O", "PX501203_01101_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_O_O_X", "PX501203_01101_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_X_O_O_O", "PX501203_01101_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_X_X_X", "PX501203_01101_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_X_X_O", "PX501203_01101_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_X_O_X", "PX501203_01101_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_X_O_O", "PX501203_01101_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_O_X_X", "PX501203_01101_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_O_X_O", "PX501203_01101_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_O_O_X", "PX501203_01101_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_말뚝_S_O_O_O_O", "PX501203_01101_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_X_X_X", "PX501203_01110_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_X_X_O", "PX501203_01110_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_X_O_X", "PX501203_01110_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_X_O_O", "PX501203_01110_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_O_X_X", "PX501203_01110_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_O_X_O", "PX501203_01110_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_O_O_X", "PX501203_01110_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_X_O_O_O", "PX501203_01110_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_X_X_X", "PX501203_01110_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_X_X_O", "PX501203_01110_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_X_O_X", "PX501203_01110_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_X_O_O", "PX501203_01110_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_O_X_X", "PX501203_01110_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_O_X_O", "PX501203_01110_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_O_O_X", "PX501203_01110_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_C_O_O_O_O", "PX501203_01110_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_X_X_X", "PX501203_01111_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_X_X_O", "PX501203_01111_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_X_O_X", "PX501203_01111_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_X_O_O", "PX501203_01111_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_O_X_X", "PX501203_01111_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_O_X_O", "PX501203_01111_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_O_O_X", "PX501203_01111_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_X_O_O_O", "PX501203_01111_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_X_X_X", "PX501203_01111_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_X_X_O", "PX501203_01111_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_X_O_X", "PX501203_01111_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_X_O_O", "PX501203_01111_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_O_X_X", "PX501203_01111_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_O_X_O", "PX501203_01111_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_O_O_X", "PX501203_01111_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이하_다주_탄성_확대_S_O_O_O_O", "PX501203_01111_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_X_X_X", "PX501203_10000_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_X_X_O", "PX501203_10000_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_X_O_X", "PX501203_10000_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_X_O_O", "PX501203_10000_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_O_X_X", "PX501203_10000_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_O_X_O", "PX501203_10000_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_O_O_X", "PX501203_10000_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_X_O_O_O", "PX501203_10000_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_X_X_X", "PX501203_10000_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_X_X_O", "PX501203_10000_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_X_O_X", "PX501203_10000_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_X_O_O", "PX501203_10000_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_O_X_X", "PX501203_10000_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_O_X_O", "PX501203_10000_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_O_O_X", "PX501203_10000_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_C_O_O_O_O", "PX501203_10000_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_X_X_X", "PX501203_10001_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_X_X_O", "PX501203_10001_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_X_O_X", "PX501203_10001_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_X_O_O", "PX501203_10001_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_O_X_X", "PX501203_10001_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_O_X_O", "PX501203_10001_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_O_O_X", "PX501203_10001_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_X_O_O_O", "PX501203_10001_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_X_X_X", "PX501203_10001_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_X_X_O", "PX501203_10001_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_X_O_X", "PX501203_10001_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_X_O_O", "PX501203_10001_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_O_X_X", "PX501203_10001_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_O_X_O", "PX501203_10001_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_O_O_X", "PX501203_10001_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_말뚝_S_O_O_O_O", "PX501203_10001_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_X_X_X", "PX501203_10010_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_X_X_O", "PX501203_10010_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_X_O_X", "PX501203_10010_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_X_O_O", "PX501203_10010_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_O_X_X", "PX501203_10010_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_O_X_O", "PX501203_10010_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_O_O_X", "PX501203_10010_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_X_O_O_O", "PX501203_10010_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_X_X_X", "PX501203_10010_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_X_X_O", "PX501203_10010_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_X_O_X", "PX501203_10010_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_X_O_O", "PX501203_10010_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_O_X_X", "PX501203_10010_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_O_X_O", "PX501203_10010_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_O_O_X", "PX501203_10010_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_C_O_O_O_O", "PX501203_10010_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_X_X_X", "PX501203_10011_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_X_X_O", "PX501203_10011_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_X_O_X", "PX501203_10011_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_X_O_O", "PX501203_10011_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_O_X_X", "PX501203_10011_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_O_X_O", "PX501203_10011_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_O_O_X", "PX501203_10011_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_X_O_O_O", "PX501203_10011_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_X_X_X", "PX501203_10011_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_X_X_O", "PX501203_10011_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_X_O_X", "PX501203_10011_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_X_O_O", "PX501203_10011_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_O_X_X", "PX501203_10011_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_O_X_O", "PX501203_10011_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_O_O_X", "PX501203_10011_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_일반_확대_S_O_O_O_O", "PX501203_10011_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_X_X_X", "PX501203_10100_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_X_X_O", "PX501203_10100_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_X_O_X", "PX501203_10100_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_X_O_O", "PX501203_10100_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_O_X_X", "PX501203_10100_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_O_X_O", "PX501203_10100_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_O_O_X", "PX501203_10100_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_X_O_O_O", "PX501203_10100_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_X_X_X", "PX501203_10100_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_X_X_O", "PX501203_10100_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_X_O_X", "PX501203_10100_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_X_O_O", "PX501203_10100_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_O_X_X", "PX501203_10100_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_O_X_O", "PX501203_10100_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_O_O_X", "PX501203_10100_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_C_O_O_O_O", "PX501203_10100_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_X_X_X", "PX501203_10101_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_X_X_O", "PX501203_10101_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_X_O_X", "PX501203_10101_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_X_O_O", "PX501203_10101_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_O_X_X", "PX501203_10101_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_O_X_O", "PX501203_10101_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_O_O_X", "PX501203_10101_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_X_O_O_O", "PX501203_10101_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_X_X_X", "PX501203_10101_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_X_X_O", "PX501203_10101_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_X_O_X", "PX501203_10101_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_X_O_O", "PX501203_10101_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_O_X_X", "PX501203_10101_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_O_X_O", "PX501203_10101_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_O_O_X", "PX501203_10101_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_말뚝_S_O_O_O_O", "PX501203_10101_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_X_X_X", "PX501203_10110_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_X_X_O", "PX501203_10110_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_X_O_X", "PX501203_10110_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_X_O_O", "PX501203_10110_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_O_X_X", "PX501203_10110_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_O_X_O", "PX501203_10110_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_O_O_X", "PX501203_10110_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_X_O_O_O", "PX501203_10110_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_X_X_X", "PX501203_10110_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_X_X_O", "PX501203_10110_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_X_O_X", "PX501203_10110_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_X_O_O", "PX501203_10110_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_O_X_X", "PX501203_10110_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_O_X_O", "PX501203_10110_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_O_O_X", "PX501203_10110_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_C_O_O_O_O", "PX501203_10110_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_X_X_X", "PX501203_10111_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_X_X_O", "PX501203_10111_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_X_O_X", "PX501203_10111_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_X_O_O", "PX501203_10111_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_O_X_X", "PX501203_10111_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_O_X_O", "PX501203_10111_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_O_O_X", "PX501203_10111_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_X_O_O_O", "PX501203_10111_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_X_X_X", "PX501203_10111_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_X_X_O", "PX501203_10111_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_X_O_X", "PX501203_10111_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_X_O_O", "PX501203_10111_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_O_X_X", "PX501203_10111_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_O_X_O", "PX501203_10111_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_O_O_X", "PX501203_10111_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_단주_탄성_확대_S_O_O_O_O", "PX501203_10111_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_X_X_X", "PX501203_11000_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_X_X_O", "PX501203_11000_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_X_O_X", "PX501203_11000_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_X_O_O", "PX501203_11000_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_O_X_X", "PX501203_11000_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_O_X_O", "PX501203_11000_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_O_O_X", "PX501203_11000_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_X_O_O_O", "PX501203_11000_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_X_X_X", "PX501203_11000_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_X_X_O", "PX501203_11000_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_X_O_X", "PX501203_11000_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_X_O_O", "PX501203_11000_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_O_X_X", "PX501203_11000_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_O_X_O", "PX501203_11000_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_O_O_X", "PX501203_11000_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_C_O_O_O_O", "PX501203_11000_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_X_X_X", "PX501203_11001_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_X_X_O", "PX501203_11001_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_X_O_X", "PX501203_11001_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_X_O_O", "PX501203_11001_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_O_X_X", "PX501203_11001_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_O_X_O", "PX501203_11001_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_O_O_X", "PX501203_11001_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_X_O_O_O", "PX501203_11001_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_X_X_X", "PX501203_11001_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_X_X_O", "PX501203_11001_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_X_O_X", "PX501203_11001_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_X_O_O", "PX501203_11001_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_O_X_X", "PX501203_11001_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_O_X_O", "PX501203_11001_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_O_O_X", "PX501203_11001_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_말뚝_S_O_O_O_O", "PX501203_11001_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_X_X_X", "PX501203_11010_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_X_X_O", "PX501203_11010_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_X_O_X", "PX501203_11010_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_X_O_O", "PX501203_11010_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_O_X_X", "PX501203_11010_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_O_X_O", "PX501203_11010_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_O_O_X", "PX501203_11010_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_X_O_O_O", "PX501203_11010_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_X_X_X", "PX501203_11010_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_X_X_O", "PX501203_11010_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_X_O_X", "PX501203_11010_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_X_O_O", "PX501203_11010_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_O_X_X", "PX501203_11010_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_O_X_O", "PX501203_11010_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_O_O_X", "PX501203_11010_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_C_O_O_O_O", "PX501203_11010_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_X_X_X", "PX501203_11011_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_X_X_O", "PX501203_11011_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_X_O_X", "PX501203_11011_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_X_O_O", "PX501203_11011_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_O_X_X", "PX501203_11011_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_O_X_O", "PX501203_11011_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_O_O_X", "PX501203_11011_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_X_O_O_O", "PX501203_11011_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_X_X_X", "PX501203_11011_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_X_X_O", "PX501203_11011_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_X_O_X", "PX501203_11011_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_X_O_O", "PX501203_11011_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_O_X_X", "PX501203_11011_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_O_X_O", "PX501203_11011_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_O_O_X", "PX501203_11011_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_일반_확대_S_O_O_O_O", "PX501203_11011_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_X_X_X", "PX501203_11100_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_X_X_O", "PX501203_11100_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_X_O_X", "PX501203_11100_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_X_O_O", "PX501203_11100_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_O_X_X", "PX501203_11100_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_O_X_O", "PX501203_11100_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_O_O_X", "PX501203_11100_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_X_O_O_O", "PX501203_11100_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_X_X_X", "PX501203_11100_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_X_X_O", "PX501203_11100_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_X_O_X", "PX501203_11100_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_X_O_O", "PX501203_11100_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_O_X_X", "PX501203_11100_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_O_X_O", "PX501203_11100_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_O_O_X", "PX501203_11100_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_C_O_O_O_O", "PX501203_11100_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_X_X_X", "PX501203_11101_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_X_X_O", "PX501203_11101_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_X_O_X", "PX501203_11101_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_X_O_O", "PX501203_11101_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_O_X_X", "PX501203_11101_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_O_X_O", "PX501203_11101_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_O_O_X", "PX501203_11101_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_X_O_O_O", "PX501203_11101_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_X_X_X", "PX501203_11101_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_X_X_O", "PX501203_11101_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_X_O_X", "PX501203_11101_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_X_O_O", "PX501203_11101_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_O_X_X", "PX501203_11101_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_O_X_O", "PX501203_11101_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_O_O_X", "PX501203_11101_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_말뚝_S_O_O_O_O", "PX501203_11101_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_X_X_X", "PX501203_11110_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_X_X_O", "PX501203_11110_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_X_O_X", "PX501203_11110_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_X_O_O", "PX501203_11110_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_O_X_X", "PX501203_11110_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_O_X_O", "PX501203_11110_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_O_O_X", "PX501203_11110_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_X_O_O_O", "PX501203_11110_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_X_X_X", "PX501203_11110_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_X_X_O", "PX501203_11110_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_X_O_X", "PX501203_11110_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_X_O_O", "PX501203_11110_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_O_X_X", "PX501203_11110_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_O_X_O", "PX501203_11110_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_O_O_X", "PX501203_11110_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_C_O_O_O_O", "PX501203_11110_1111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_X_X_X", "PX501203_11111_0000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_X_X_O", "PX501203_11111_0001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_X_O_X", "PX501203_11111_0010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_X_O_O", "PX501203_11111_0011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_O_X_X", "PX501203_11111_0100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_O_X_O", "PX501203_11111_0101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_O_O_X", "PX501203_11111_0110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_X_O_O_O", "PX501203_11111_0111");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_X_X_X", "PX501203_11111_1000");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_X_X_O", "PX501203_11111_1001");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_X_O_X", "PX501203_11111_1010");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_X_O_O", "PX501203_11111_1011");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_O_X_X", "PX501203_11111_1100");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_O_X_O", "PX501203_11111_1101");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_O_O_X", "PX501203_11111_1110");
			m_FragilityCurvDict->Add("PSC Box_다경간_5m이상_다주_탄성_확대_S_O_O_O_O", "PX501203_11111_1111");


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

		static property Dictionary<String^, String^>^ FragilityCurvDict {
			Dictionary<String^, String^>^ get() {
				return FragilityDataSet::m_FragilityCurvDict;
			}
		}


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
					Debug::WriteLine("=================>outputLineData:" + outputLineData);

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
		/*
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
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.0"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.01"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 4.966346445200998E-8; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 4.966346445200998E-8; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 4.966346445200998E-8; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.588341066622206E-11; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.02"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 9.892537324862607E-7; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 9.892537317091055E-7; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 9.892537317091055E-7; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.750768501869061E-9; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.03"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 4.916632575957449E-6; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 4.916632558416012E-6; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 4.916632558416012E-6; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.937616000979858E-8; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.04"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 1.436769283302618E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 1.43676926857017E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 1.436769268559068E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.245935096378275E-8; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.05"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 3.180398230559949E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 3.180398157787144E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 3.180398157742736E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.941072778066655E-7; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.06"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 5.943037471607537E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 5.943037212507984E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 5.943037212319258E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.237439128473852E-7; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.07"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 9.914736034714998E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 9.914735294791415E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 9.91473529415865E-5; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 8.060347981286853E-7; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.08"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 1.525564366642518E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 1.525564186290991E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 1.525564186116712E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.389193588163806E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.09"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 2.209854119720426E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 2.209853729431184E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 2.209853729010502E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.223652545207955E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.1"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 3.055196606620328E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 3.055195836598466E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 3.055195835682811E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.361036208682222E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.11"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 4.070334199742519E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 4.070332788596396E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 4.070332786765273E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.853376281088728E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.12"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 5.26218742447141E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 5.262184989456715E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 5.262184986033479E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 6.752515083086053E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.13"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 6.636112988224979E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 6.636108991271851E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 6.636108985224041E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 9.10965548639453E-6; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.14"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 8.196129335009616E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 8.1961230447641E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 8.196123034575059E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.197502445882126E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.15"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 9.94511177422348E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 9.945102224353753E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 9.945102207872248E-4; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.539762478797169E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.16"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.001188496035921705; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.001188494630328928; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.001188494627754941; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.942505533469863E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.17"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.00140167439305472; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.001401672379376458; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.001401672375477721; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.410338461833472E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.18"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.001634082358011831; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.001634079540822085; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.001634079535073766; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.947706594236266E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.19"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.001885695847361809; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.001885691987927324; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.001885691979651591; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.55888848794228E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.2"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.002156439660487599; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.002156434471183494; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.002156434459519828; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.247993194106403E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.21"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.002446195270038521; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.002446188408571296; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.002446188392443223; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 5.018959480163065E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.22"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.002754807516829336; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.002754798580294817; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.002754798558373512; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 5.87555656468286E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.23"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.003082090370127359; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.003082078888930225; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.003082078859595233; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 6.821386014932429E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.24"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.003427831889714907; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.003427817321375383; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.003427817282671464; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.859884530048156E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.25"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.003791798505205873; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.003791780228077124; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.003791780177668687; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 8.99432739058792E-5; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.26"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.004173738710409962; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.00417371601732896; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.004173715952450991; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.022783239977842E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.27"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.00457338625563634; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.004573358347529359; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.004573358264934978; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.15633641780577E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.28"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.004990462908294525; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.00499042888775621; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.004990428783661533; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.300373870078975E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.29"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.005424680841608972; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.005424639706473281; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.00542463957649928; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.455162799158805E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.3"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.00587574470240237; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.005875695339323251; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.005875695178434188; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.620956490204772E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.31"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.006343353401435948; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.006343294579490872; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.006343294381930541; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.797994792316349E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.32"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.006827201663497827; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.006827132027830939; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.006827131787055634; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 1.986504598526784E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.33"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.007326981369117332; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.00732689943463391; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.007326899143242914; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.186700321293866E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.34"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.007842382715276933; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.007842286860400404; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.007842286510063903; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.398784360878592E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.35"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.008373095218676395; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.008372983679180936; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.00837298326056506; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.622947564612232E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.36"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.008918808581861988; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.008918679444788552; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.008918678947478205; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 2.859369675560774E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.37"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.009479213439763698; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.009479064637428761; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.00947906404984829; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.108219769470955E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.38"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01005400200182775; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01005383130593396; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01005383061526521; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.369656679235166E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.39"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01064286860291173; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01064267361876569; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0106426728108644; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.643829406321241E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.4"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01124551017437904; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01124528833522452; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0112452873945342; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 3.930877518896203E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.41"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01186162664534188; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01186137520681361; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01186137411627717; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.23093153644527E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.42"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01249092128272591; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01249063731742745; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0124906360583983; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.544113300908314E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.43"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01313310097772039; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01313278136993293; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01313277992208294; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 4.870536334398156E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.44"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01378787648522924; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01378751792575335; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01378751626697966; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 5.210306183677237E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.45"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01445496262211057; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01445456160324492; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01445455970957553; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 5.563520751629135E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.46"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01513407842927458; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01513363123993431; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01513362908543157; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 5.930270616010256E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.47"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01582494730209353; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01582445002306995; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01582444757973342; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 6.310639335777022E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.48"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0165272970930259; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01652674559239074; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01652674283005793; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 6.704703745381565E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.49"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01724086018989902; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01724025011855258; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0172402470047994; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.112534237340148E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.5"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01796537357286743; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01796470036023432; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01796469686027371; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.53419503350949E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.51"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01870057885271684; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01869983770258801; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01869983377916796; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 7.969744445410759E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.52"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.01944622229286037; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.01944540817938245; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.01944540379268334; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 8.419235124011986E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.53"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02020205481710096; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02020116248091315; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02020115758844357; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 8.882714299339726E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.54"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02096783200498966; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02096685594950874; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02096685050600115; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 9.360224010319652E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.55"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02174331407639689; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02174224856424856; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02174224252155406; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 9.851801325190244E-4; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.56"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02252826586672651; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02252710491632368; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02252709822330663; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001035747855289147; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.57"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02332245679403575; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02332119417630193; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02332118677873331; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001087728344577819; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.58"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02412566081917903; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02412429005441766; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02412428189486866; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001141123939398024; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.59"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02493765639996583; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02493617075487187; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0249361617726068; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001195936561179442; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.6"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02575822644020744; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02575661892502237; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02575660905589166; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001252167731641049; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.61"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02658715823442639; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02658542160023318; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0265854107765657; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001309818589927732; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.62"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02742424340891603; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02742237014507425; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02742235829556993; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001368889909045042; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.63"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02826927785975559; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02826726019147374; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.02826724724109591; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0014293821116188; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.64"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02912206168831705; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.02911989157436089; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0291198774442286; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.00149129528500857; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.65"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.02998239913473902; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0299800682652739; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0299800528725543; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001554629195803063; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.66"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03085009850978664; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03084759830435203; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03084758156215331; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001619383303722347; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.67"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0317249721254672; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03172229373108122; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03172227554834507; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.00168555677495418; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.68"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03260683622472801; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03260397051412001; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03260395079551454; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001753148494945001; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.69"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03349551091052417; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03349244848049332; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03349242712630678; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001822157080673335; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.7"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03439082007451063; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03438755124440824; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03438752815044208; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001892580892422932; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.71"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03529259132557967; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0352891061359125; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03528908119337614; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.001964418045080502; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.72"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0362006559184379; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03619694412959165; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0361969172249963; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002037666418975939; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.73"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03711484868239719; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03711089977347665; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03711087078853046; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002112323670285998; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.74"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03803500795052477; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0380308111183081; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03803077992981199; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002188387241018749; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.75"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03896097548928387; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03895651964729021; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03895648612703373; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002265854368597579; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.76"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.03989259642877714; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.03988787020644374; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.03988783422110186; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002344722095060503; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.77"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04082971919369026; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04082471093565768; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04082467234668789; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002424987275891872; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.78"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04177219543501814; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0417668932005206; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04176685186406154; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002506646588501373; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.79"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04271987996264587; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04271427152500504; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04271422729177488; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002589696540366399; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.8"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04367263067884487; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04366670352506431; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0436666562402604; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002674133476849583; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.81"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04463030851273296; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04462404984319113; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04462399934639057; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002759953588707557; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.82"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04559277735574373; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04558617408398273; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04558612020904351; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002847152919301083; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.83"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04655990399813719; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0465529427507459; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04655288532570907; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.002935727371522398; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.84"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04753155806657925; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04752422518316796; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04752416403016056; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003025672714448; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.85"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0485076119628136; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.04849989349607808; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.04849982843121674; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003116984589730541; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.86"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.04948794080344085; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0494798225193127; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0494797533526091; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003209658517739685; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.87"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05047242236081615; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05046388973869918; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05046381627396555; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003303689903461953; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.88"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05146093700507379; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0514519752381622; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05145189727291809; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003399074042170292; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.89"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0524533676472818; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05244396164295911; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05244387896833941; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003495806124872053; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.9"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05344959968372725; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05343973406404374; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05343964646470754; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003593881243544803; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.91"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05444952094132933; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05443918004355503; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05443908729759559; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003693294396167634; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.92"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05545302162417538; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0554421895014278; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05544209138028353; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003794040491558291; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.93"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0564599942611735; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05644865468311742; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05644855095148391; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003896114354020792; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.94"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05747033365481184; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05745847010842815; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05745836052417153; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.003999510727814961; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.95"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0584839368310127; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05847153252143616; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05847141683550753; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004104224281451434; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.96"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.05950070299007307; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.05948774084149561; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.05948761879784641; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004210249611821587; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.97"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06052053345867391; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06050699611531171; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06050686745081051; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004317581248167015; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.98"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06154333164294489; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06152920147006795; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0615290659144181; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004426213655897489; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "0.99"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06256900298257288; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06255426206759433; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06255411934325315; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004536141240259903; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.0"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06359745490593106; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06358208505955529; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06358193488165423; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004647358349867453; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.01"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06462859678621942; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06461257954364608; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06461242161991186; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004759859280092481; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.02"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06566233989859403; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06564565652077713; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06564549055145484; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.00487363827632875; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.03"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06669859737827033; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06668122885322977; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06668105453100628; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.004988689537128937; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.04"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06773728417958073; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06771921122376562; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0677190282336948; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005105007217220109; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.05"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06877831703597043; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.06875952009567157; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06875932811510042; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005222585430406291; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.06"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.06982161442091149; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0698020736737212; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.06980187237221751; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005341418252356013; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.07"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07086709650971672; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07084679186603539; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07084658090531656; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005461499723286274; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.08"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07191468514223727; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07189359624682423; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07189337528068704; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005582823850540924; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.09"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07296430378642146; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0729424100199889; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07294217869424066; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005705384611071569; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.1"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07401587750272194; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07399315798356951; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07399291593596093; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005829175953822442; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.11"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07506933290932664; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07504576649501721; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07504551335517602; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.005954191802023899; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.12"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07612459814820172; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07610016343727445; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07609989882664006; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006080426055398654; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.13"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07718160285192385; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07715627818564454; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07715600171740489; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006207872592281092; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.14"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0782402781112862; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07821404157543344; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07821375285446171; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0063365252716574; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.15"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.07930055644366078; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.07927338587034552; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.07927308449313973; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006466377935125456; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.16"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08036237176209865; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08033424473161746; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08033393028623995; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006597424408779431; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.17"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08142565934515271; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08139655318787152; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08139622525389052; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006729658505022776; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.18"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08249035580740417; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08246024760567278; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08245990575410461; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006863074024309391; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.19"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0835563990706779; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08352526566077287; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08352490945402621; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.006997664756818618; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.2"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08462372833592949; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08459154631002529; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08459117530184564; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.00713342448406462; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.21"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08569228405578913; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08565902976395462; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08565864349937106; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007270346980444028; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.22"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08676200790774541; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08672765745996648; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0867272554752389; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007408426014722093; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.23"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08783284276795433; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08779737203617984; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08779695385874778; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007547655351461867; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.24"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08890473268565857; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08886811730586965; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08886768245430243; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007688028752397225; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.25"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.08997762285820196; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.08993983823250275; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.08993938621645053; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007829539977751692; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.26"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09105145960662628; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09101248090535538; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09101201122550179; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.007972182787505987; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.27"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09212619035183192; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0920859925156937; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09208550466370925; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008115950942615273; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.28"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09320176359129564; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09316032133350993; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09315981479200704; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008260838206177887; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.29"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09427812887632452; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.0942354166847935; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09423489092728288; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008406838344558553; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.3"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.0953552367898382; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09531122892933064; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09531068342017814; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008553945128465966; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.31"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09643303892466398; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09638770943901463; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09638714363339998; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008702152333987736; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.32"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09751148786233327; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09746481057665675; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09746422392053357; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.008851453743583605; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.33"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09859053715236582; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09854248567528459; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.0985418776053407; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009001843147039447; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.34"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.09967014129203117; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.09962068901791658; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.09962005896153654; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.00915331434238044; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.35"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1007502557065756; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1006993758178004; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1006987231930283; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009305861136749909; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.36"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1018308367299009; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1017785021991029; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1017778264146075; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009459477347249882; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.37"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1029118415856865; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1028580251780432; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1028573256330829; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009614156801748552; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.38"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1039932283689426; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1039379026444551; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1039371787288447; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009769893339653547; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.39"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1050749560279846; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1050180933437697; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1050173444378485; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.009926680812653335; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.4"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.106156984346817; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1060985568594079; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1060977823340085; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01008451308542711; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.41"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1072392739279174; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1071792535955714; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1071784528119901; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01024338403632635; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.42"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1083217861754129; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1082601447604256; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1082593170703934; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01040328755802463; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.43"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1094044832786341; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1093411923496596; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1093403370953147; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01056421755814279; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.44"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1104873281960436; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1104223591304195; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1104214756442805; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01072616795984458; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.45"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.111570284639524; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1115036086256014; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1115026962305423; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01088913270240849; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.46"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1126533170590219; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1125849050984983; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1125839631077236; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01105310574177263; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.47"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1137363906275346; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.113666213537791; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1136652412548129; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01121808105105732; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.48"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1148194712264339; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1147474996428737; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1147464963614895; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01138405262106331; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.49"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1159025254311173; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1158287298095079; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1158276948137792; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0115510144607476; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.5"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1169855204969812; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1169098711157959; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1169088036800279; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0117189605976782; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.51"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1180684243457022; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1179908913084642; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1179897906971873; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01188788507846721; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.52"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1191512055518275; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1190717587894534; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1190706242574046; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01205778196918461; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.53"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1202338333296595; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1201524426028027; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1201512733949088; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01222864535575173; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.54"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1213162775204317; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1212329124218248; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1212317077731864; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01240046934431683; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.55"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1223985085797647; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1223131385365615; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1223118976724379; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01257324806161168; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.56"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1234804975654038; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1233930918415186; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1233918139773135; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01274697565529158; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.57"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1245622161252194; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1244727438236643; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1244714281649133; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01292164629425725; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.58"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1256436364854741; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1255520665506941; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1255507122930521; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01309725416896206; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.59"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1267247314393463; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1266310326595507; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.126629638988781; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01327379349170258; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.6"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1278054743357012; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1277096153451918; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1277081814371558; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01345125849689368; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.61"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1288858390681091; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1287877883496042; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1287863133702523; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01362964344132979; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.62"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1299658000641001; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1298655259510546; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1298640090564176; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.013808942604432; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.63"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1310453322746528; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1309428029535726; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1309412432897548; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01398915028848055; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.64"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1321244111639088; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1320195946766609; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1320179913798332; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01417026081883592; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.65"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1332030126991089; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.133095876945226; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1330942291416203; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01435226854414538; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.66"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1342811133407477; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1341716260797262; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.134169932885631; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01453516783653831; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.67"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1353586900329361; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.135246818886529; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1352450794082852; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01471895309181016; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.68"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1364357201939733; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.136321432648475; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1363196459824735; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01490361872959397; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.69"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1375121817071177; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1373954451156435; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1373936103483225; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01508915919352138; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.7"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1385880529115555; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1384688344963131; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1384669507041572; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01527556895137325; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.71"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1396633125935603; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.139541579448114; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1395396456976538; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01546284249522002; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.72"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1407379399778421; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1406136590693695; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1406116744171819; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01565097434155148; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.73"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1418119147190765; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1416850528906161; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1416830163833258; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01583995903139812; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.74"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1428852168936151; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1427557408663071; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1427536515405884; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01602979113044262; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.75"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1439578269913685; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.143825703366686; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1438235602492659; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.0162204652291226; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.76"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1450297259078612; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1448949211698332; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1448927232774946; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01641197594272505; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.77"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1461008949364518; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.145963375453876; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.145961121793463; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01660431791147202; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.78"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1471713157607167; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1470310477893648; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1470287373577869; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01679748580059919; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.79"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1482409704469923; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1480979201318038; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1480955519160426; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01699147430042564; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.8"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1493098414370721; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1491639748143402; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1491615477914557; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01718627812641777; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.81"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1503779115410558; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1502291945406015; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1502267076777399; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01738189201924439; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.82"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1514451639303459; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1512935623776838; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1512910146320856; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01757831074482642; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.83"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1525115821307904; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1523570617492827; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1523544520682911; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01777552909437868; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.84"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1535771500159643; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1534196764289649; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1534170037500364; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01797354188444671; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.85"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1546418518005921; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1544813905335802; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1544786537842941; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01817234395693621; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.86"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1557056720341029; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.155542188516805; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1555393866148747; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01837193017913693; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.87"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1567685955943193; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1566020551628209; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.156599187016106; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01857229544374149; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.88"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1578306076812739; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1576609755801194; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1576580400866372; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01877343466885765; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.89"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1588916938111524; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1587189351954343; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1587159312433739; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01897534279801626; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.9"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1599518398103588; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1597759197477949; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.15977284621553; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01917801480017307; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.91"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.161011031809703; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1608319152827021; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1608287710388059; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01938144566970692; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.92"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1620692562387051; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1618869081464207; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1618836920496806; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01958563042641178; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.93"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.163126499820012; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1629408849803851; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1629375958798185; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01979056411548562; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.94"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1641827495639321; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1639938327157205; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1639904694505911; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.01999624180751377; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.95"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1652379927630744; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1650457385678711; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1650422999677055; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.02020265859844851; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.96"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1662922169870982; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1660965900313373; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1660930749159426; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.02040980960958504; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.97"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1673454100775672; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1671463748745168; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1671427820539987; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.02061768998753221; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.98"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1683975601429056; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1681950811346494; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1681914094094306; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.02082629490418177; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);

			newRow = FragilityDataSet::m_FragilityCurvData->NewRow();
			newRow[CommConst::DT_FRAG_CURV_DATA_COL01] = "PB301203_00111_0000.xlsx"; newRow[CommConst::DT_FRAG_CURV_DATA_COL02] = "1.99"; newRow[CommConst::DT_FRAG_CURV_DATA_COL03] = 0.1694486555534559; newRow[CommConst::DT_FRAG_CURV_DATA_COL04] = 0.1692426971128616; newRow[CommConst::DT_FRAG_CURV_DATA_COL05] = 0.1692389452737013; newRow[CommConst::DT_FRAG_CURV_DATA_COL06] = 0.02103561955667116; FragilityDataSet::m_FragilityCurvData->Rows->Add(newRow);


		}
		*/


		/*
		static property DataTable^ FragilityCurvData {
			DataTable^ get() {
				return FragilityDataSet::m_FragilityCurvData;
			}
		}
		*/

	};
}