#pragma once
using namespace System;
using namespace System::Windows::Forms;

/// <summary>
/// File dialog util class
/// </summary>
ref class CFileDlgUtil
{
public:
	// ���� ��������
	// ȣ�� �� ���̾�α� �߰� ���� �ϸ� ������ ������ ��θ� ���� 
	static String^ GetFile(String^ filter)
	{
		OpenFileDialog^ dlg = gcnew OpenFileDialog;
		//dlg->InitialDirectory = "C:\\";
		dlg->InitialDirectory = "C:\\sample";
		dlg->Filter = filter;
		dlg->FilterIndex = 2;
		dlg->RestoreDirectory = true;
		if (dlg->ShowDialog() == DialogResult::OK)
		{
			return dlg->FileName;
		}
		return L"";
	}

	// Shape ���ϸ� ��������
	static String^ GetShapeFile()
	{
		return GetFile(L"SHP Files (*.shp)|*.shp");
	}

	// Excel ���ϸ� ��������
	static String^ GetExcelFile()
	{
		return GetFile(L"Excel Files (*.xls,*,xlsx)|*.xls;*.xlsx");
	}

	// Excel ���ϸ� ��������
	static String^ GetCsvFile()
	{
		return GetFile(L"CSV Files (*.csv)|*.csv");
	}


	// Project ���� ���ϸ� ��������
	static String^ GetProjectDataFile()
	{
		return GetFile(L"Project data files (*.prd)|*.prd");
	}
};

