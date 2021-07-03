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

			m_FragilityCurvDict->Add("1111","22222222.xlsx");

			m_FragilityCurvDict->Add("단경간_-_-_일반_-_-_-_X_-_X", "PB301201_00000_0000.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_일반_-_-_-_X_-_O", "PB301201_00000_0001.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_일반_-_-_-_O_-_X", "PB301201_00000_0100.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_일반_-_-_-_O_-_O", "PB301201_00000_0101.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_탄성_-_-_-_X_-_X", "PB301201_00100_0000.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_탄성_-_-_-_X_-_O", "PB301201_00100_0001.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_탄성_-_-_-_O_-_X", "PB301201_00100_0100.xlsx");
			m_FragilityCurvDict->Add("단경간_-_-_탄성_-_-_-_O_-_O", "PB301201_00100_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_X_X_X", "PB301203_00000_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_X_X_O", "PB301203_00000_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_X_O_X", "PB301203_00000_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_X_O_O", "PB301203_00000_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_O_X_X", "PB301203_00000_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_O_X_O", "PB301203_00000_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_O_O_X", "PB301203_00000_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_X_O_O_O", "PB301203_00000_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_X_X_X", "PB301203_00000_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_X_X_O", "PB301203_00000_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_X_O_X", "PB301203_00000_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_X_O_O", "PB301203_00000_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_O_X_X", "PB301203_00000_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_O_X_O", "PB301203_00000_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_O_O_X", "PB301203_00000_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_C_O_O_O_O", "PB301203_00000_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_X_X_X", "PB301203_00001_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_X_X_O", "PB301203_00001_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_X_O_X", "PB301203_00001_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_X_O_O", "PB301203_00001_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_O_X_X", "PB301203_00001_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_O_X_O", "PB301203_00001_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_O_O_X", "PB301203_00001_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_X_O_O_O", "PB301203_00001_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_X_X_X", "PB301203_00001_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_X_X_O", "PB301203_00001_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_X_O_X", "PB301203_00001_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_X_O_O", "PB301203_00001_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_O_X_X", "PB301203_00001_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_O_X_O", "PB301203_00001_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_O_O_X", "PB301203_00001_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_말뚝_S_O_O_O_O", "PB301203_00001_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_X_X_X", "PB301203_00010_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_X_X_O", "PB301203_00010_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_X_O_X", "PB301203_00010_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_X_O_O", "PB301203_00010_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_O_X_X", "PB301203_00010_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_O_X_O", "PB301203_00010_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_O_O_X", "PB301203_00010_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_X_O_O_O", "PB301203_00010_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_X_X_X", "PB301203_00010_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_X_X_O", "PB301203_00010_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_X_O_X", "PB301203_00010_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_X_O_O", "PB301203_00010_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_O_X_X", "PB301203_00010_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_O_X_O", "PB301203_00010_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_O_O_X", "PB301203_00010_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_C_O_O_O_O", "PB301203_00010_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_X_X_X", "PB301203_00011_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_X_X_O", "PB301203_00011_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_X_O_X", "PB301203_00011_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_X_O_O", "PB301203_00011_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_O_X_X", "PB301203_00011_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_O_X_O", "PB301203_00011_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_O_O_X", "PB301203_00011_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_X_O_O_O", "PB301203_00011_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_X_X_X", "PB301203_00011_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_X_X_O", "PB301203_00011_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_X_O_X", "PB301203_00011_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_X_O_O", "PB301203_00011_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_O_X_X", "PB301203_00011_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_O_X_O", "PB301203_00011_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_O_O_X", "PB301203_00011_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_일반_확대_S_O_O_O_O", "PB301203_00011_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_X_X_X", "PB301203_00100_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_X_X_O", "PB301203_00100_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_X_O_X", "PB301203_00100_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_X_O_O", "PB301203_00100_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_O_X_X", "PB301203_00100_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_O_X_O", "PB301203_00100_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_O_O_X", "PB301203_00100_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_X_O_O_O", "PB301203_00100_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_X_X_X", "PB301203_00100_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_X_X_O", "PB301203_00100_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_X_O_X", "PB301203_00100_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_X_O_O", "PB301203_00100_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_O_X_X", "PB301203_00100_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_O_X_O", "PB301203_00100_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_O_O_X", "PB301203_00100_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_C_O_O_O_O", "PB301203_00100_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_X_X_X", "PB301203_00101_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_X_X_O", "PB301203_00101_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_X_O_X", "PB301203_00101_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_X_O_O", "PB301203_00101_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_O_X_X", "PB301203_00101_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_O_X_O", "PB301203_00101_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_O_O_X", "PB301203_00101_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_X_O_O_O", "PB301203_00101_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_X_X_X", "PB301203_00101_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_X_X_O", "PB301203_00101_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_X_O_X", "PB301203_00101_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_X_O_O", "PB301203_00101_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_O_X_X", "PB301203_00101_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_O_X_O", "PB301203_00101_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_O_O_X", "PB301203_00101_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_말뚝_S_O_O_O_O", "PB301203_00101_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_X_X_X", "PB301203_00110_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_X_X_O", "PB301203_00110_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_X_O_X", "PB301203_00110_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_X_O_O", "PB301203_00110_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_O_X_X", "PB301203_00110_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_O_X_O", "PB301203_00110_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_O_O_X", "PB301203_00110_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_X_O_O_O", "PB301203_00110_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_X_X_X", "PB301203_00110_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_X_X_O", "PB301203_00110_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_X_O_X", "PB301203_00110_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_X_O_O", "PB301203_00110_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_O_X_X", "PB301203_00110_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_O_X_O", "PB301203_00110_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_O_O_X", "PB301203_00110_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_C_O_O_O_O", "PB301203_00110_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_X_X_X", "PB301203_00111_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_X_X_O", "PB301203_00111_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_X_O_X", "PB301203_00111_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_X_O_O", "PB301203_00111_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_O_X_X", "PB301203_00111_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_O_X_O", "PB301203_00111_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_O_O_X", "PB301203_00111_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_X_O_O_O", "PB301203_00111_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_X_X_X", "PB301203_00111_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_X_X_O", "PB301203_00111_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_X_O_X", "PB301203_00111_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_X_O_O", "PB301203_00111_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_O_X_X", "PB301203_00111_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_O_X_O", "PB301203_00111_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_O_O_X", "PB301203_00111_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_단주_탄성_확대_S_O_O_O_O", "PB301203_00111_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_X_X_X", "PB301203_01000_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_X_X_O", "PB301203_01000_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_X_O_X", "PB301203_01000_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_X_O_O", "PB301203_01000_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_O_X_X", "PB301203_01000_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_O_X_O", "PB301203_01000_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_O_O_X", "PB301203_01000_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_X_O_O_O", "PB301203_01000_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_X_X_X", "PB301203_01000_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_X_X_O", "PB301203_01000_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_X_O_X", "PB301203_01000_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_X_O_O", "PB301203_01000_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_O_X_X", "PB301203_01000_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_O_X_O", "PB301203_01000_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_O_O_X", "PB301203_01000_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_C_O_O_O_O", "PB301203_01000_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_X_X_X", "PB301203_01001_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_X_X_O", "PB301203_01001_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_X_O_X", "PB301203_01001_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_X_O_O", "PB301203_01001_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_O_X_X", "PB301203_01001_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_O_X_O", "PB301203_01001_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_O_O_X", "PB301203_01001_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_X_O_O_O", "PB301203_01001_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_X_X_X", "PB301203_01001_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_X_X_O", "PB301203_01001_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_X_O_X", "PB301203_01001_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_X_O_O", "PB301203_01001_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_O_X_X", "PB301203_01001_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_O_X_O", "PB301203_01001_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_O_O_X", "PB301203_01001_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_말뚝_S_O_O_O_O", "PB301203_01001_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_X_X_X", "PB301203_01010_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_X_X_O", "PB301203_01010_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_X_O_X", "PB301203_01010_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_X_O_O", "PB301203_01010_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_O_X_X", "PB301203_01010_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_O_X_O", "PB301203_01010_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_O_O_X", "PB301203_01010_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_X_O_O_O", "PB301203_01010_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_X_X_X", "PB301203_01010_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_X_X_O", "PB301203_01010_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_X_O_X", "PB301203_01010_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_X_O_O", "PB301203_01010_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_O_X_X", "PB301203_01010_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_O_X_O", "PB301203_01010_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_O_O_X", "PB301203_01010_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_C_O_O_O_O", "PB301203_01010_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_X_X_X", "PB301203_01011_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_X_X_O", "PB301203_01011_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_X_O_X", "PB301203_01011_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_X_O_O", "PB301203_01011_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_O_X_X", "PB301203_01011_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_O_X_O", "PB301203_01011_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_O_O_X", "PB301203_01011_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_X_O_O_O", "PB301203_01011_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_X_X_X", "PB301203_01011_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_X_X_O", "PB301203_01011_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_X_O_X", "PB301203_01011_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_X_O_O", "PB301203_01011_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_O_X_X", "PB301203_01011_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_O_X_O", "PB301203_01011_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_O_O_X", "PB301203_01011_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_일반_확대_S_O_O_O_O", "PB301203_01011_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_X_X_X", "PB301203_01100_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_X_X_O", "PB301203_01100_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_X_O_X", "PB301203_01100_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_X_O_O", "PB301203_01100_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_O_X_X", "PB301203_01100_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_O_X_O", "PB301203_01100_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_O_O_X", "PB301203_01100_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_X_O_O_O", "PB301203_01100_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_X_X_X", "PB301203_01100_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_X_X_O", "PB301203_01100_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_X_O_X", "PB301203_01100_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_X_O_O", "PB301203_01100_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_O_X_X", "PB301203_01100_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_O_X_O", "PB301203_01100_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_O_O_X", "PB301203_01100_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_C_O_O_O_O", "PB301203_01100_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_X_X_X", "PB301203_01101_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_X_X_O", "PB301203_01101_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_X_O_X", "PB301203_01101_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_X_O_O", "PB301203_01101_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_O_X_X", "PB301203_01101_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_O_X_O", "PB301203_01101_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_O_O_X", "PB301203_01101_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_X_O_O_O", "PB301203_01101_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_X_X_X", "PB301203_01101_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_X_X_O", "PB301203_01101_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_X_O_X", "PB301203_01101_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_X_O_O", "PB301203_01101_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_O_X_X", "PB301203_01101_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_O_X_O", "PB301203_01101_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_O_O_X", "PB301203_01101_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_말뚝_S_O_O_O_O", "PB301203_01101_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_X_X_X", "PB301203_01110_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_X_X_O", "PB301203_01110_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_X_O_X", "PB301203_01110_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_X_O_O", "PB301203_01110_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_O_X_X", "PB301203_01110_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_O_X_O", "PB301203_01110_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_O_O_X", "PB301203_01110_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_X_O_O_O", "PB301203_01110_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_X_X_X", "PB301203_01110_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_X_X_O", "PB301203_01110_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_X_O_X", "PB301203_01110_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_X_O_O", "PB301203_01110_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_O_X_X", "PB301203_01110_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_O_X_O", "PB301203_01110_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_O_O_X", "PB301203_01110_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_C_O_O_O_O", "PB301203_01110_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_X_X_X", "PB301203_01111_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_X_X_O", "PB301203_01111_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_X_O_X", "PB301203_01111_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_X_O_O", "PB301203_01111_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_O_X_X", "PB301203_01111_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_O_X_O", "PB301203_01111_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_O_O_X", "PB301203_01111_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_X_O_O_O", "PB301203_01111_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_X_X_X", "PB301203_01111_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_X_X_O", "PB301203_01111_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_X_O_X", "PB301203_01111_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_X_O_O", "PB301203_01111_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_O_X_X", "PB301203_01111_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_O_X_O", "PB301203_01111_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_O_O_X", "PB301203_01111_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이하_다주_탄성_확대_S_O_O_O_O", "PB301203_01111_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_X_X_X", "PB301203_10000_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_X_X_O", "PB301203_10000_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_X_O_X", "PB301203_10000_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_X_O_O", "PB301203_10000_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_O_X_X", "PB301203_10000_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_O_X_O", "PB301203_10000_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_O_O_X", "PB301203_10000_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_X_O_O_O", "PB301203_10000_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_X_X_X", "PB301203_10000_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_X_X_O", "PB301203_10000_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_X_O_X", "PB301203_10000_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_X_O_O", "PB301203_10000_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_O_X_X", "PB301203_10000_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_O_X_O", "PB301203_10000_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_O_O_X", "PB301203_10000_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_C_O_O_O_O", "PB301203_10000_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_X_X_X", "PB301203_10001_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_X_X_O", "PB301203_10001_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_X_O_X", "PB301203_10001_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_X_O_O", "PB301203_10001_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_O_X_X", "PB301203_10001_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_O_X_O", "PB301203_10001_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_O_O_X", "PB301203_10001_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_X_O_O_O", "PB301203_10001_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_X_X_X", "PB301203_10001_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_X_X_O", "PB301203_10001_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_X_O_X", "PB301203_10001_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_X_O_O", "PB301203_10001_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_O_X_X", "PB301203_10001_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_O_X_O", "PB301203_10001_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_O_O_X", "PB301203_10001_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_말뚝_S_O_O_O_O", "PB301203_10001_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_X_X_X", "PB301203_10010_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_X_X_O", "PB301203_10010_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_X_O_X", "PB301203_10010_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_X_O_O", "PB301203_10010_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_O_X_X", "PB301203_10010_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_O_X_O", "PB301203_10010_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_O_O_X", "PB301203_10010_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_X_O_O_O", "PB301203_10010_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_X_X_X", "PB301203_10010_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_X_X_O", "PB301203_10010_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_X_O_X", "PB301203_10010_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_X_O_O", "PB301203_10010_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_O_X_X", "PB301203_10010_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_O_X_O", "PB301203_10010_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_O_O_X", "PB301203_10010_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_C_O_O_O_O", "PB301203_10010_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_X_X_X", "PB301203_10011_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_X_X_O", "PB301203_10011_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_X_O_X", "PB301203_10011_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_X_O_O", "PB301203_10011_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_O_X_X", "PB301203_10011_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_O_X_O", "PB301203_10011_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_O_O_X", "PB301203_10011_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_X_O_O_O", "PB301203_10011_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_X_X_X", "PB301203_10011_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_X_X_O", "PB301203_10011_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_X_O_X", "PB301203_10011_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_X_O_O", "PB301203_10011_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_O_X_X", "PB301203_10011_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_O_X_O", "PB301203_10011_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_O_O_X", "PB301203_10011_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_일반_확대_S_O_O_O_O", "PB301203_10011_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_X_X_X", "PB301203_10100_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_X_X_O", "PB301203_10100_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_X_O_X", "PB301203_10100_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_X_O_O", "PB301203_10100_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_O_X_X", "PB301203_10100_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_O_X_O", "PB301203_10100_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_O_O_X", "PB301203_10100_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_X_O_O_O", "PB301203_10100_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_X_X_X", "PB301203_10100_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_X_X_O", "PB301203_10100_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_X_O_X", "PB301203_10100_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_X_O_O", "PB301203_10100_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_O_X_X", "PB301203_10100_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_O_X_O", "PB301203_10100_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_O_O_X", "PB301203_10100_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_C_O_O_O_O", "PB301203_10100_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_X_X_X", "PB301203_10101_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_X_X_O", "PB301203_10101_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_X_O_X", "PB301203_10101_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_X_O_O", "PB301203_10101_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_O_X_X", "PB301203_10101_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_O_X_O", "PB301203_10101_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_O_O_X", "PB301203_10101_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_X_O_O_O", "PB301203_10101_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_X_X_X", "PB301203_10101_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_X_X_O", "PB301203_10101_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_X_O_X", "PB301203_10101_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_X_O_O", "PB301203_10101_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_O_X_X", "PB301203_10101_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_O_X_O", "PB301203_10101_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_O_O_X", "PB301203_10101_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_말뚝_S_O_O_O_O", "PB301203_10101_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_X_X_X", "PB301203_10110_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_X_X_O", "PB301203_10110_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_X_O_X", "PB301203_10110_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_X_O_O", "PB301203_10110_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_O_X_X", "PB301203_10110_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_O_X_O", "PB301203_10110_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_O_O_X", "PB301203_10110_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_X_O_O_O", "PB301203_10110_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_X_X_X", "PB301203_10110_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_X_X_O", "PB301203_10110_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_X_O_X", "PB301203_10110_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_X_O_O", "PB301203_10110_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_O_X_X", "PB301203_10110_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_O_X_O", "PB301203_10110_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_O_O_X", "PB301203_10110_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_C_O_O_O_O", "PB301203_10110_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_X_X_X", "PB301203_10111_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_X_X_O", "PB301203_10111_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_X_O_X", "PB301203_10111_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_X_O_O", "PB301203_10111_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_O_X_X", "PB301203_10111_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_O_X_O", "PB301203_10111_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_O_O_X", "PB301203_10111_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_X_O_O_O", "PB301203_10111_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_X_X_X", "PB301203_10111_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_X_X_O", "PB301203_10111_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_X_O_X", "PB301203_10111_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_X_O_O", "PB301203_10111_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_O_X_X", "PB301203_10111_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_O_X_O", "PB301203_10111_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_O_O_X", "PB301203_10111_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_단주_탄성_확대_S_O_O_O_O", "PB301203_10111_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_X_X_X", "PB301203_11000_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_X_X_O", "PB301203_11000_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_X_O_X", "PB301203_11000_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_X_O_O", "PB301203_11000_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_O_X_X", "PB301203_11000_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_O_X_O", "PB301203_11000_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_O_O_X", "PB301203_11000_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_X_O_O_O", "PB301203_11000_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_X_X_X", "PB301203_11000_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_X_X_O", "PB301203_11000_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_X_O_X", "PB301203_11000_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_X_O_O", "PB301203_11000_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_O_X_X", "PB301203_11000_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_O_X_O", "PB301203_11000_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_O_O_X", "PB301203_11000_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_C_O_O_O_O", "PB301203_11000_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_X_X_X", "PB301203_11001_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_X_X_O", "PB301203_11001_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_X_O_X", "PB301203_11001_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_X_O_O", "PB301203_11001_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_O_X_X", "PB301203_11001_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_O_X_O", "PB301203_11001_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_O_O_X", "PB301203_11001_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_X_O_O_O", "PB301203_11001_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_X_X_X", "PB301203_11001_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_X_X_O", "PB301203_11001_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_X_O_X", "PB301203_11001_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_X_O_O", "PB301203_11001_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_O_X_X", "PB301203_11001_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_O_X_O", "PB301203_11001_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_O_O_X", "PB301203_11001_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_말뚝_S_O_O_O_O", "PB301203_11001_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_X_X_X", "PB301203_11010_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_X_X_O", "PB301203_11010_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_X_O_X", "PB301203_11010_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_X_O_O", "PB301203_11010_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_O_X_X", "PB301203_11010_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_O_X_O", "PB301203_11010_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_O_O_X", "PB301203_11010_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_X_O_O_O", "PB301203_11010_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_X_X_X", "PB301203_11010_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_X_X_O", "PB301203_11010_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_X_O_X", "PB301203_11010_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_X_O_O", "PB301203_11010_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_O_X_X", "PB301203_11010_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_O_X_O", "PB301203_11010_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_O_O_X", "PB301203_11010_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_C_O_O_O_O", "PB301203_11010_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_X_X_X", "PB301203_11011_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_X_X_O", "PB301203_11011_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_X_O_X", "PB301203_11011_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_X_O_O", "PB301203_11011_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_O_X_X", "PB301203_11011_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_O_X_O", "PB301203_11011_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_O_O_X", "PB301203_11011_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_X_O_O_O", "PB301203_11011_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_X_X_X", "PB301203_11011_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_X_X_O", "PB301203_11011_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_X_O_X", "PB301203_11011_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_X_O_O", "PB301203_11011_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_O_X_X", "PB301203_11011_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_O_X_O", "PB301203_11011_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_O_O_X", "PB301203_11011_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_일반_확대_S_O_O_O_O", "PB301203_11011_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_X_X_X", "PB301203_11100_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_X_X_O", "PB301203_11100_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_X_O_X", "PB301203_11100_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_X_O_O", "PB301203_11100_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_O_X_X", "PB301203_11100_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_O_X_O", "PB301203_11100_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_O_O_X", "PB301203_11100_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_X_O_O_O", "PB301203_11100_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_X_X_X", "PB301203_11100_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_X_X_O", "PB301203_11100_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_X_O_X", "PB301203_11100_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_X_O_O", "PB301203_11100_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_O_X_X", "PB301203_11100_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_O_X_O", "PB301203_11100_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_O_O_X", "PB301203_11100_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_C_O_O_O_O", "PB301203_11100_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_X_X_X", "PB301203_11101_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_X_X_O", "PB301203_11101_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_X_O_X", "PB301203_11101_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_X_O_O", "PB301203_11101_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_O_X_X", "PB301203_11101_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_O_X_O", "PB301203_11101_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_O_O_X", "PB301203_11101_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_X_O_O_O", "PB301203_11101_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_X_X_X", "PB301203_11101_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_X_X_O", "PB301203_11101_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_X_O_X", "PB301203_11101_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_X_O_O", "PB301203_11101_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_O_X_X", "PB301203_11101_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_O_X_O", "PB301203_11101_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_O_O_X", "PB301203_11101_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_말뚝_S_O_O_O_O", "PB301203_11101_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_X_X_X", "PB301203_11110_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_X_X_O", "PB301203_11110_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_X_O_X", "PB301203_11110_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_X_O_O", "PB301203_11110_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_O_X_X", "PB301203_11110_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_O_X_O", "PB301203_11110_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_O_O_X", "PB301203_11110_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_X_O_O_O", "PB301203_11110_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_X_X_X", "PB301203_11110_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_X_X_O", "PB301203_11110_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_X_O_X", "PB301203_11110_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_X_O_O", "PB301203_11110_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_O_X_X", "PB301203_11110_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_O_X_O", "PB301203_11110_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_O_O_X", "PB301203_11110_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_C_O_O_O_O", "PB301203_11110_1111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_X_X_X", "PB301203_11111_0000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_X_X_O", "PB301203_11111_0001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_X_O_X", "PB301203_11111_0010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_X_O_O", "PB301203_11111_0011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_O_X_X", "PB301203_11111_0100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_O_X_O", "PB301203_11111_0101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_O_O_X", "PB301203_11111_0110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_X_O_O_O", "PB301203_11111_0111.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_X_X_X", "PB301203_11111_1000.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_X_X_O", "PB301203_11111_1001.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_X_O_X", "PB301203_11111_1010.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_X_O_O", "PB301203_11111_1011.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_O_X_X", "PB301203_11111_1100.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_O_X_O", "PB301203_11111_1101.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_O_O_X", "PB301203_11111_1110.xlsx");
			m_FragilityCurvDict->Add("다경간_5m이상_다주_탄성_확대_S_O_O_O_O", "PB301203_11111_1111.xlsx");


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