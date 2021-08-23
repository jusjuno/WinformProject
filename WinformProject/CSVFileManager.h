#pragma once
#include "FileUtil.h"

using namespace System;
using namespace System::IO;
using namespace System::Data;
using namespace System::Windows::Forms;

/// <summary>
/// CSV ���� ���� �� ���� Ŭ����
/// </summary>
ref class CSVFileManager
{
private:
	String^ LF = Environment::NewLine;
	bool	m_isWriteColumnNames;
	bool	m_isVertical;
	String^ m_delimiter;
	String^ m_filePath;
	FileUtil^ m_fileUtil;
public:	
	// csv ���� �� �б� �� column name�� ������ ���� ����
	property bool IsWriteColumnNames {
		bool get() {
			return this->m_isWriteColumnNames;
		}
		void set(bool value) {
			this->m_isWriteColumnNames = value;
		}
	}
	// ��/���� �ٲ㼭 ����, �б� ����
	property bool IsVertical {
		bool get() {
			return this->m_isVertical;
		}
		void set(bool value) {
			this->m_isVertical = value;
		}
	}
	// delimiter
	property String^ Delimiter {
		String^ get() {
			return this->m_delimiter;
		}
	}
	// �б�, ���� ���� ���
	property String^ FilePath {
		String^ get() {
			return this->m_filePath;
		}
	}
public:
	static array<String^>^ Parse(String^ value, String^ delimiter) {
		return value->Split(delimiter->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
	}

	static array<String^>^ CSVParse(String^ value, String^ delimiter) {
		return value->Split(delimiter->ToCharArray());
	}

public:
	CSVFileManager(String^ filePath) {
		this->m_filePath = filePath;
		this->m_delimiter = ",";
		this->m_isWriteColumnNames = true;
		this->m_isVertical = false;
		this->m_fileUtil = gcnew FileUtil();
	}

	String^ Read() {
		return this->m_fileUtil->Read(m_filePath);
	}

	// ���� ����
	bool Write(array<String^>^ columnNames, DataTable^ table) {
		String^ contents = GenerateData(columnNames, table);
		if (String::IsNullOrEmpty(contents)) {
			return false;
		}
		return this->m_fileUtil->WriteText(this->m_filePath, contents);
	}

	// Datatable�� �����͸� csv�� String���� ����
	String^ GenerateData(array<String^>^ columnNames, DataTable^ table) {
		String^ data = "";

		if (columnNames->Length < 1) {
			return data;
		}

		int columnSize = columnNames->Length;
		if (!IsVertical) {
			// generate column name
			if (m_isWriteColumnNames) {
				for (int i = 0; i < columnSize; i++) {
					data += columnNames[i];
					if (i + 1 == columnSize) {
						data = data + LF;
					}
					else {
						data += this->m_delimiter;
					}
				}
			}

			// generate data
			for each (DataRow^ row in table->Rows)
			{
				for (int i = 0; i < columnSize; i++)
				{
					if (!row->IsNull(i)) {
						data += row[i];
					}

					if (i + 1 == columnSize) {
						data += LF;
					}
					else {
						data += this->m_delimiter;
					}
				}
			}
		}
		else {
			for (int i = 0; i < columnSize; i++) {
				// generate column name
				if (this->m_isWriteColumnNames) {
					data += columnNames[i];
				}
				// generate data
				for (int rowCnt = 0; rowCnt < table->Rows->Count; rowCnt++)
				{
					DataRow^ row = table->Rows[rowCnt];
					if (!row->IsNull(i)) {
						if (m_isWriteColumnNames) {
							data += this->m_delimiter;
						}
						data += row[i];
					}
					if (rowCnt + 1 < table->Rows->Count) {
						data += this->m_delimiter;
					}
				}
				data += LF;
			}
		}
		
		return data;
	}


	//Į���� ���� CSV���� ����
	bool Write(DataTable^ table) {
		String^ contents = GenerateData(table);
		if (String::IsNullOrEmpty(contents)) {
			return false;
		}
		return this->m_fileUtil->WriteText(this->m_filePath, contents);
	}

	// Datatable�� �����͸� csv�� String���� ����
	String^ GenerateData(DataTable^ table) {
		String^ data = "";

		if (table->Columns->Count < 1) {
			return data;
		}

		int columnSize = table->Columns->Count;
		if (!IsVertical) {

			// generate data
			for each (DataRow ^ row in table->Rows)
			{
				for (int i = 0; i < columnSize; i++)
				{
					if (!row->IsNull(i)) {
						data += row[i];
					}

					if (i + 1 == columnSize) {
						data += LF;
					}
					else {
						data += this->m_delimiter;
					}
				}
			}
		}
		else {
			for (int i = 0; i < columnSize; i++) {
				// generate data
				for (int rowCnt = 0; rowCnt < table->Rows->Count; rowCnt++)
				{
					DataRow^ row = table->Rows[rowCnt];
					if (!row->IsNull(i)) {
						if (m_isWriteColumnNames) {
							data += this->m_delimiter;
						}
						data += row[i];
					}
					if (rowCnt + 1 < table->Rows->Count) {
						data += this->m_delimiter;
					}
				}
				data += LF;
			}
		}

		return data;
	}


};