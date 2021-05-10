#pragma once
using namespace System;
using namespace System::Data;
using namespace Microsoft::Office::Interop;

/// <summary>
/// Excel util class
/// </summary>
public ref class ExcelUtil
{
public:
	// Convert excel to DataTable
	static System::Data::DataTable^ ExcelUtil::ExcelToDataTable(String^ filePath, ... array<String^>^ columns) {
		Excel::Workbook^ wb = nullptr;
		DataTable^ dt = gcnew DataTable();
		try {
			Excel::Application^ exApp = gcnew Excel::ApplicationClass();
			wb = exApp->Workbooks->Open(filePath, 0, true, 5, "", "", true, Excel::XlPlatform::xlWindows, "\t", false, false, 0, true, 1, 0);
			Excel::Worksheet^ exWs = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);
			DataRow^ row = nullptr;
			// define fields(columns)
			for each (String^ col in columns)
			{
				dt->Columns->Add(gcnew DataColumn(col));
			}

			int rowIndex = 1;
			int colIndex = 1;
			String^ cellValue;
			// ������ �����Ͱ� �ִ��� �𸣱� ������ row�� column�� �ݺ��Ͽ� row�� �����Ͱ� ���� ������ �ݺ��Ͽ� DataTable�� ���� 
			while (((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2 != nullptr)
			{
				while (((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2 != nullptr)
				{
					cellValue = ((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2->ToString();;
					if (colIndex == 1) {
						row = dt->NewRow(); // create new row
					}
					row[colIndex - 1] = cellValue;
					colIndex++;
				}
				if (colIndex > 1) {
					dt->Rows->Add(row);
				}
				rowIndex++;
				colIndex = 1;
			}
			return dt;
		}
		catch (Exception^ ex) {
			Debug::WriteLine(ex);
			throw gcnew Exception(L"Can not read file.");
		}
		finally{
			if (wb != nullptr) {
				wb->Close(false, filePath, nullptr);
			}
		};
	}

	// Convert excel to DataTable
	// columnRowIndex from 1
	// columnRowIndex ���� column ������ ������ŭ �����͸� ����-
	static System::Data::DataTable^ ExcelUtil::ExcelToDataTableUseColumnIndex(String^ filePath, int columnRowIndex) {
		Excel::Workbook^ wb = nullptr;
		DataTable^ dt = gcnew DataTable();
		try {
			Excel::Application^ exApp = gcnew Excel::ApplicationClass();
			wb = exApp->Workbooks->Open(filePath, 0, true, 5, "", "", true, Excel::XlPlatform::xlWindows, "\t", false, false, 0, true, 1, 0);
			Excel::Worksheet^ exWs = safe_cast<Excel::Worksheet^>(exApp->ActiveSheet);
			DataRow^ row = nullptr;

			int rowIndex = columnRowIndex; // 1
			int colIndex = 1;
			String^ cellValue;
			Object^ value;
			// ������ �����Ͱ� �ִ��� �𸣱� ������ row�� column�� �ݺ��Ͽ� row�� �����Ͱ� ���� ������ �ݺ��Ͽ� DataTable�� ����
			// check row data
			while (((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2 != nullptr)
			{
				// check column data
				while (((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2 != nullptr)
				{
					value = ((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)colIndex])->Value2;
					// define fields(columns)
					if (rowIndex == columnRowIndex) {
						Debug::WriteLine("Defind Column:" + value->ToString());
						dt->Columns->Add(gcnew DataColumn(value->ToString()));
					}
					colIndex++;
				}
				rowIndex++;
				colIndex = 1;
			}
			// columnRowIndex �������� �����ͷ� ���� 
			rowIndex = columnRowIndex + 1;

			// check row data
			while (((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)1])->Value2 != nullptr)
			{
				// check column data
				for (int col = 1; col <= dt->Columns->Count; col++)
				{
					if (col == 1) {
						row = dt->NewRow(); // create new row
						Debug::WriteLine("Add Row");
					}

					value = ((Excel::Range^)exWs->Cells[(System::Object^)rowIndex, (System::Object^)col])->Value2;
					if (value != nullptr) {
						cellValue = value->ToString();;
					}
					else {
						cellValue = "";
					}
					row[col - 1] = cellValue;
					Debug::WriteLine("    Add data:" + cellValue);
				}
				dt->Rows->Add(row);
				rowIndex++;
			}
			return dt;
		}
		catch (Exception^ ex) {
			Debug::WriteLine(ex);
			throw gcnew Exception(L"Can not read file.");
		}
		finally{
			if (wb != nullptr) {
				wb->Close(false, filePath, nullptr);
			}
		};
	}
};

