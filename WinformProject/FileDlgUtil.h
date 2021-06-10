#pragma once
using namespace System;
using namespace System::Windows::Forms;

/// <summary>
/// File dialog util class
/// </summary>
ref class CFileDlgUtil
{
public:
	// 파일 가져오기
	// 호출 시 다이얼로그 뜨고 선택 하면 선택한 파일의 경로를 리턴 
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

	// Shape 파일만 가져오기
	static String^ GetShapeFile()
	{
		return GetFile(L"SHP Files (*.shp)|*.shp");
	}

	// Excel 파일만 가져오기
	static String^ GetExcelFile()
	{
		return GetFile(L"Excel Files (*.xls,*,xlsx)|*.xls;*.xlsx");
	}

	// Excel 파일만 가져오기
	static String^ GetCsvFile()
	{
		return GetFile(L"CSV Files (*.csv)|*.csv");
	}


	// Project 저장 파일만 가져오기
	static String^ GetProjectDataFile()
	{
		return GetFile(L"Project data files (*.prd)|*.prd");
	}
};

