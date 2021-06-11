#pragma once
#include "Alert.h"
#include "Shape.h"
#include "CommConst.h"
#include "FileDlgUtil.h"
#include "ExcelUtil.h"
#include "ProjectDataSetBinder.h"
#include "NetworkComponent.h"
#include "FragilityCompList.h"

namespace WinformProject {
	using namespace Microsoft::Office::Interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NewProjectForm에 대한 요약입니다.
	/// 프로젝트 생성 폼
	/// </summary>
	[Serializable]
	public ref class NewProjectForm : public System::Windows::Forms::Form
	{
	private:
//		static String^ DEFAULT_PATH = "c:\\sample\\sample3";
		static String^ DEFAULT_PATH = "c:\\sample";
	private: System::Windows::Forms::Button^ btnFindClassFile;

	private: System::Windows::Forms::TextBox^ tbClassFilePath;
	private: System::Windows::Forms::Label^ lblClassFilePath;


		   ProjectDataSetBinder^ m_dataSetBinder;
	public:
		NewProjectForm()
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSetBinder = gcnew ProjectDataSetBinder();
		}
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~NewProjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblShapeFilePath;
	protected:
	public:
		property ProjectDataSet^ ReturnDataSet {
			ProjectDataSet^ get() {
				return this->m_dataSetBinder->DataSet;
			}
		}

//	private: System::Windows::Forms::Label^ label6;
//	private: System::Windows::Forms::TextBox^ tbSoilAmpFilePath;
//	private: System::Windows::Forms::Button^ btnFindSoilAmpFile;


	private: System::Windows::Forms::TextBox^  tbShapeFilePath;
	private: System::Windows::Forms::Button^  btnFindShapeFile;
	private: System::Windows::Forms::Button^ btnFindListFile;

	private: System::Windows::Forms::TextBox^ tbListFilePath;
	private: System::Windows::Forms::Label^ lblListFilePath;





	private: System::Windows::Forms::Button^  btnFindNetworkFile;
	private: System::Windows::Forms::TextBox^  tbNetworkFilePath;
	private: System::Windows::Forms::Label^ lblNetworkFilePath;

	private: System::Windows::Forms::ProgressBar^  newProgress;
	private: System::Windows::Forms::Label^ lblFragCurParamFilePath;

	private: System::Windows::Forms::TextBox^  tbFragCurParamFilePath;
	private: System::Windows::Forms::Label^ lblSoilAmpFilePath;

	private: System::Windows::Forms::TextBox^ tbSoilAmpFilePath;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker;
	private: System::Windows::Forms::Button^  btnFindFragParamFile;
	private: System::Windows::Forms::Button^ btnFindSoilAmpFile;
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tbName;
	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->lblShapeFilePath = (gcnew System::Windows::Forms::Label());
			this->tbShapeFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnFindShapeFile = (gcnew System::Windows::Forms::Button());
			this->btnFindListFile = (gcnew System::Windows::Forms::Button());
			this->tbListFilePath = (gcnew System::Windows::Forms::TextBox());
			this->lblListFilePath = (gcnew System::Windows::Forms::Label());
			this->btnFindNetworkFile = (gcnew System::Windows::Forms::Button());
			this->tbNetworkFilePath = (gcnew System::Windows::Forms::TextBox());
			this->lblNetworkFilePath = (gcnew System::Windows::Forms::Label());
			this->newProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->btnFindFragParamFile = (gcnew System::Windows::Forms::Button());
			this->tbFragCurParamFilePath = (gcnew System::Windows::Forms::TextBox());
			this->lblFragCurParamFilePath = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->lblSoilAmpFilePath = (gcnew System::Windows::Forms::Label());
			this->tbSoilAmpFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnFindSoilAmpFile = (gcnew System::Windows::Forms::Button());
			this->btnFindClassFile = (gcnew System::Windows::Forms::Button());
			this->tbClassFilePath = (gcnew System::Windows::Forms::TextBox());
			this->lblClassFilePath = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(534, 392);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(120, 43);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &NewProjectForm::btnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(407, 392);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 43);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &NewProjectForm::btnCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Name";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(129, 32);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(524, 25);
			this->tbName->TabIndex = 3;
			this->tbName->Text = L"New Project";
			this->tbName->TextChanged += gcnew System::EventHandler(this, &NewProjectForm::tbName_TextChanged);
			this->tbName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NewProjectForm::tbName_KeyDown);
			// 
			// lblShapeFilePath
			// 
			this->lblShapeFilePath->AutoSize = true;
			this->lblShapeFilePath->Location = System::Drawing::Point(14, 85);
			this->lblShapeFilePath->Name = L"lblShapeFilePath";
			this->lblShapeFilePath->Size = System::Drawing::Size(76, 15);
			this->lblShapeFilePath->TabIndex = 4;
			this->lblShapeFilePath->Text = L"Shape File";
			// 
			// tbShapeFilePath
			// 
			this->tbShapeFilePath->Location = System::Drawing::Point(199, 80);
			this->tbShapeFilePath->Name = L"tbShapeFilePath";
			this->tbShapeFilePath->Size = System::Drawing::Size(361, 25);
			this->tbShapeFilePath->TabIndex = 1;
			// 
			// btnFindShapeFile
			// 
			this->btnFindShapeFile->Location = System::Drawing::Point(566, 78);
			this->btnFindShapeFile->Name = L"btnFindShapeFile";
			this->btnFindShapeFile->Size = System::Drawing::Size(88, 28);
			this->btnFindShapeFile->TabIndex = 6;
			this->btnFindShapeFile->Text = L"Find";
			this->btnFindShapeFile->UseVisualStyleBackColor = true;
			this->btnFindShapeFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindShapeFile_Click);
			// 
			// btnFindListFile
			// 
			this->btnFindListFile->Location = System::Drawing::Point(566, 122);
			this->btnFindListFile->Name = L"btnFindListFile";
			this->btnFindListFile->Size = System::Drawing::Size(88, 28);
			this->btnFindListFile->TabIndex = 9;
			this->btnFindListFile->Text = L"Find";
			this->btnFindListFile->UseVisualStyleBackColor = true;
			this->btnFindListFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindListFile_Click);
			// 
			// tbListFilePath
			// 
			this->tbListFilePath->Location = System::Drawing::Point(199, 122);
			this->tbListFilePath->Name = L"tbListFilePath";
			this->tbListFilePath->Size = System::Drawing::Size(361, 25);
			this->tbListFilePath->TabIndex = 2;
			// 
			// lblListFilePath
			// 
			this->lblListFilePath->AutoSize = true;
			this->lblListFilePath->Location = System::Drawing::Point(14, 127);
			this->lblListFilePath->Name = L"lblListFilePath";
			this->lblListFilePath->Size = System::Drawing::Size(103, 15);
			this->lblListFilePath->TabIndex = 7;
			this->lblListFilePath->Text = L"Bridge List File";
			// 
			// btnFindNetworkFile
			// 
			this->btnFindNetworkFile->Location = System::Drawing::Point(566, 162);
			this->btnFindNetworkFile->Name = L"btnFindNetworkFile";
			this->btnFindNetworkFile->Size = System::Drawing::Size(88, 28);
			this->btnFindNetworkFile->TabIndex = 12;
			this->btnFindNetworkFile->Text = L"Find";
			this->btnFindNetworkFile->UseVisualStyleBackColor = true;
			this->btnFindNetworkFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindNetworkFile_Click);
			// 
			// tbNetworkFilePath
			// 
			this->tbNetworkFilePath->Location = System::Drawing::Point(199, 163);
			this->tbNetworkFilePath->Name = L"tbNetworkFilePath";
			this->tbNetworkFilePath->Size = System::Drawing::Size(361, 25);
			this->tbNetworkFilePath->TabIndex = 3;
			// 
			// lblNetworkFilePath
			// 
			this->lblNetworkFilePath->AutoSize = true;
			this->lblNetworkFilePath->Location = System::Drawing::Point(14, 168);
			this->lblNetworkFilePath->Name = L"lblNetworkFilePath";
			this->lblNetworkFilePath->Size = System::Drawing::Size(163, 15);
			this->lblNetworkFilePath->TabIndex = 10;
			this->lblNetworkFilePath->Text = L"Network component File";
			// 
			// newProgress
			// 
			this->newProgress->Location = System::Drawing::Point(14, 367);
			this->newProgress->Name = L"newProgress";
			this->newProgress->Size = System::Drawing::Size(639, 17);
			this->newProgress->TabIndex = 13;
			// 
			// btnFindFragParamFile
			// 
			this->btnFindFragParamFile->Location = System::Drawing::Point(566, 203);
			this->btnFindFragParamFile->Name = L"btnFindFragParamFile";
			this->btnFindFragParamFile->Size = System::Drawing::Size(88, 28);
			this->btnFindFragParamFile->TabIndex = 16;
			this->btnFindFragParamFile->Text = L"Find";
			this->btnFindFragParamFile->UseVisualStyleBackColor = true;
			this->btnFindFragParamFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindFragParamFile_Click);
			// 
			// tbFragCurParamFilePath
			// 
			this->tbFragCurParamFilePath->Location = System::Drawing::Point(199, 205);
			this->tbFragCurParamFilePath->Name = L"tbFragCurParamFilePath";
			this->tbFragCurParamFilePath->Size = System::Drawing::Size(361, 25);
			this->tbFragCurParamFilePath->TabIndex = 4;
			// 
			// lblFragCurParamFilePath
			// 
			this->lblFragCurParamFilePath->AutoSize = true;
			this->lblFragCurParamFilePath->Location = System::Drawing::Point(14, 210);
			this->lblFragCurParamFilePath->Name = L"lblFragCurParamFilePath";
			this->lblFragCurParamFilePath->Size = System::Drawing::Size(180, 15);
			this->lblFragCurParamFilePath->TabIndex = 14;
			this->lblFragCurParamFilePath->Text = L"Fragility curve paramer File";
			// 
			// lblSoilAmpFilePath
			// 
			this->lblSoilAmpFilePath->AutoSize = true;
			this->lblSoilAmpFilePath->Location = System::Drawing::Point(14, 248);
			this->lblSoilAmpFilePath->Name = L"lblSoilAmpFilePath";
			this->lblSoilAmpFilePath->Size = System::Drawing::Size(144, 15);
			this->lblSoilAmpFilePath->TabIndex = 17;
			this->lblSoilAmpFilePath->Text = L"Soil amplification File";
			// 
			// tbSoilAmpFilePath
			// 
			this->tbSoilAmpFilePath->Location = System::Drawing::Point(199, 246);
			this->tbSoilAmpFilePath->Name = L"tbSoilAmpFilePath";
			this->tbSoilAmpFilePath->Size = System::Drawing::Size(361, 25);
			this->tbSoilAmpFilePath->TabIndex = 5;
			// 
			// btnFindSoilAmpFile
			// 
			this->btnFindSoilAmpFile->Location = System::Drawing::Point(566, 246);
			this->btnFindSoilAmpFile->Name = L"btnFindSoilAmpFile";
			this->btnFindSoilAmpFile->Size = System::Drawing::Size(88, 28);
			this->btnFindSoilAmpFile->TabIndex = 19;
			this->btnFindSoilAmpFile->Text = L"Find";
			this->btnFindSoilAmpFile->UseVisualStyleBackColor = true;
			this->btnFindSoilAmpFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindSoilAmpFile_Click);
			// 
			// btnFindClassFile
			// 
			this->btnFindClassFile->Location = System::Drawing::Point(564, 324);
			this->btnFindClassFile->Name = L"btnFindClassFile";
			this->btnFindClassFile->Size = System::Drawing::Size(88, 28);
			this->btnFindClassFile->TabIndex = 22;
			this->btnFindClassFile->Text = L"Find";
			this->btnFindClassFile->UseVisualStyleBackColor = true;
			this->btnFindClassFile->Visible = false;
			this->btnFindClassFile->Click += gcnew System::EventHandler(this, &NewProjectForm::btnFindClassFile_Click);
			// 
			// tbClassFilePath
			// 
			this->tbClassFilePath->Location = System::Drawing::Point(197, 324);
			this->tbClassFilePath->Name = L"tbClassFilePath";
			this->tbClassFilePath->Size = System::Drawing::Size(361, 25);
			this->tbClassFilePath->TabIndex = 21;
			this->tbClassFilePath->Visible = false;
			// 
			// lblClassFilePath
			// 
			this->lblClassFilePath->AutoSize = true;
			this->lblClassFilePath->Location = System::Drawing::Point(12, 329);
			this->lblClassFilePath->Name = L"lblClassFilePath";
			this->lblClassFilePath->Size = System::Drawing::Size(149, 15);
			this->lblClassFilePath->TabIndex = 20;
			this->lblClassFilePath->Text = L"Component class File";
			this->lblClassFilePath->Visible = false;
			// 
			// NewProjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 437);
			this->Controls->Add(this->btnFindClassFile);
			this->Controls->Add(this->tbClassFilePath);
			this->Controls->Add(this->lblClassFilePath);
			this->Controls->Add(this->btnFindSoilAmpFile);
			this->Controls->Add(this->tbSoilAmpFilePath);
			this->Controls->Add(this->lblSoilAmpFilePath);
			this->Controls->Add(this->btnFindFragParamFile);
			this->Controls->Add(this->tbFragCurParamFilePath);
			this->Controls->Add(this->lblFragCurParamFilePath);
			this->Controls->Add(this->newProgress);
			this->Controls->Add(this->btnFindNetworkFile);
			this->Controls->Add(this->tbNetworkFilePath);
			this->Controls->Add(this->lblNetworkFilePath);
			this->Controls->Add(this->btnFindListFile);
			this->Controls->Add(this->tbListFilePath);
			this->Controls->Add(this->lblListFilePath);
			this->Controls->Add(this->btnFindShapeFile);
			this->Controls->Add(this->tbShapeFilePath);
			this->Controls->Add(this->lblShapeFilePath);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->MaximumSize = System::Drawing::Size(682, 484);
			this->MinimumSize = System::Drawing::Size(682, 484);
			this->Name = L"NewProjectForm";
			this->Text = L"New";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NewProjectForm::NewProjectForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &NewProjectForm::NewProjectForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		// delegate update progress bar
		delegate void UpdateProgressDelegate(int value);
		UpdateProgressDelegate^ updateProgress;

	private:
		// read shape file.
		System::Void ReadShapeFile() {
			try {
				this->m_dataSetBinder->ShapeData = gcnew Shape();
				this->m_dataSetBinder->ShapeData->Open(this->m_dataSetBinder->ShapeFilePath);
			}
			catch (Exception^ ex) {
				Debug::WriteLine(ex);
				throw gcnew Exception(L"Can not read shape file.");
			}
		}

		// read components class file.
		System::Void ReadComponentsClassFile() {
			try {
				System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(this->m_dataSetBinder->ClassFilePath
					, CommConst::GRID_COMP_CLASS_COL1, CommConst::GRID_COMP_CLASS_COL2
				);
				this->m_dataSetBinder->ComponentClassData = dt;
			}
			catch (Exception^ ex) {
				throw gcnew Exception(L"Can not read component class file.");
			}
		}

		// read list file.
		System::Void ReadListFile() {
			try {
				Dictionary<String^, String^>^ m_CompDict = gcnew Dictionary<String^, String^>();
				//m_CompDict->Add("PSC Beam_단경간_-_-_일반_-_-_-_X_-_X", "PB301201_00000_0000");

				DataTable^ tmpDt = gcnew DataTable();
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL01));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL02));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL03));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL04));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL05));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL06));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL07));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL08));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL09));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL10));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL11));
				tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_BRIDGE_LIST_COL12));
	

				CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSetBinder->ListFilePath);
				String^ output = csv->Read();

				if (!String::IsNullOrEmpty(output)) {
					array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
					int outputRowCount = dataArray->Length;
					Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));

					DataRow^ row = nullptr;
					for (int i = 0; i < outputRowCount; i++)
					{
						String^ outputLineData = dataArray[i];
						Debug::WriteLine("=================>outputLineData:" + outputLineData);

						if (i > 0) {//첫번째 행은 컬럼명이라 무시
							array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");

							row = tmpDt->NewRow();
							row[CommConst::DT_BRIDGE_LIST_COL01] = StringUtil::nullToString(values[0], "-");
							row[CommConst::DT_BRIDGE_LIST_COL02] = StringUtil::nullToString(values[1], "-");
							row[CommConst::DT_BRIDGE_LIST_COL03] = StringUtil::nullToString(values[2], "-");
							row[CommConst::DT_BRIDGE_LIST_COL04] = StringUtil::nullToString(values[3], "-");
							row[CommConst::DT_BRIDGE_LIST_COL05] = StringUtil::nullToString(values[4], "-");
							row[CommConst::DT_BRIDGE_LIST_COL06] = StringUtil::nullToString(values[5], "-");
							row[CommConst::DT_BRIDGE_LIST_COL07] = StringUtil::nullToString(values[6], "-");
							row[CommConst::DT_BRIDGE_LIST_COL08] = StringUtil::nullToString(values[7], "-");
							row[CommConst::DT_BRIDGE_LIST_COL09] = StringUtil::nullToString(values[8], "-");
							row[CommConst::DT_BRIDGE_LIST_COL10] = StringUtil::nullToString(values[9], "-");
							row[CommConst::DT_BRIDGE_LIST_COL11] = StringUtil::nullToString(values[10], "-");
							row[CommConst::DT_BRIDGE_LIST_COL12] = StringUtil::nullToString(values[11], "-");

							String^ sKey = StringUtil::nullToString(values[0], "-")
								+ "_" + StringUtil::nullToString(values[1], "-")
								+ "_" + StringUtil::nullToString(values[2], "-")
								+ "_" + StringUtil::nullToString(values[3], "-")
								+ "_" + StringUtil::nullToString(values[4], "-")
								+ "_" + StringUtil::nullToString(values[5], "-")
								+ "_" + StringUtil::nullToString(values[6], "-")
								+ "_" + StringUtil::nullToString(values[7], "-")
								+ "_" + StringUtil::nullToString(values[8], "-")
								+ "_" + StringUtil::nullToString(values[9], "-")
								+ "_" + StringUtil::nullToString(values[10], "-");

							String^ sValue = StringUtil::nullToString(values[11], "")->Replace(".xlsx", "")->Replace(".csv", "")->Replace(".xls", "");
							m_CompDict->Add(sKey, sValue);

							tmpDt->Rows->Add(row);
						}
					}//for end ... row

					/**************************************************/
					this->m_dataSetBinder->BridgeList = tmpDt;
					/**************************************************/

					/**************************************************/
					//Fragility 딕셔러리 초기화
					this->m_dataSetBinder->FragilityCompDict = m_CompDict;
					/**************************************************/
	
				}

			}
			catch (Exception^ ex) {
				throw gcnew Exception(L"Can not read component class file.");
			}
		}


		// read network components file.
		System::Void ReadNetworkComponentsFile() {
			try {
				NetworkComponent^ nc = gcnew NetworkComponent();
				nc->ReadFile(this->m_dataSetBinder->NetworkFilePath);
				this->m_dataSetBinder->NetworkCompnentData = nc->Data;
			}
			catch (Exception^ ex) {
				throw gcnew Exception(L"Can not read network component file.");
			}
		}
		// read fragility curve parameter file.
		System::Void ReadFragilityCurveParamFile() {
			try {
				System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(this->m_dataSetBinder->FragParamFilePath
					, CommConst::GRID_FRAG_CURVE_PARAM_COL1, CommConst::GRID_FRAG_CURVE_PARAM_COL2, CommConst::GRID_FRAG_CURVE_PARAM_COL3
					, CommConst::GRID_FRAG_CURVE_PARAM_COL4, CommConst::GRID_FRAG_CURVE_PARAM_COL5, CommConst::GRID_FRAG_CURVE_PARAM_COL6
					, CommConst::GRID_FRAG_CURVE_PARAM_COL7, CommConst::GRID_FRAG_CURVE_PARAM_COL8, CommConst::GRID_FRAG_CURVE_PARAM_COL9
				);
				this->m_dataSetBinder->FragParameterData = dt;
			}
			catch (Exception^ ex) {
				throw gcnew Exception(L"Can not read fragility curve parameter file.");
			}
		}

		// read soil amplification factor file.
		System::Void ReadSoilAmpFile() {
			try {
				System::Data::DataTable^ st = ExcelUtil::ExcelToDataTable(this->m_dataSetBinder->SoilAmpFilePath
					, CommConst::GRID_SOIL_AMP_COL1, CommConst::GRID_SOIL_AMP_COL2, CommConst::GRID_SOIL_AMP_COL3
					, CommConst::GRID_SOIL_AMP_COL4, CommConst::GRID_SOIL_AMP_COL5, CommConst::GRID_SOIL_AMP_COL6
				);
				this->m_dataSetBinder->SoilAmpData = st;
			}
			catch (Exception ^ ex) {
				throw gcnew Exception(L"Can not read soil amplification factor file.");
			}
		}


		void SetDefaultNodeControlTypes() {
			array<String^>^ columns = { "control_type_name", "control_type" };
			DataTable^ newTable = gcnew DataTable();
			// define fields
			for each (String^ col in columns)
			{
				newTable->Columns->Add(gcnew DataColumn(col));
			}
			DataRow^ newRow = nullptr;
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "unknown_control";
			newRow[columns[1]] = "0";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "no_control";
			newRow[columns[1]] = "1";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "yield_sign";
			newRow[columns[1]] = "2";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "2way_stop_sign";
			newRow[columns[1]] = "3";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "4way_stop_sign";
			newRow[columns[1]] = "4";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "pretimed_signal";
			newRow[columns[1]] = "5";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "actuated_signal";
			newRow[columns[1]] = "6";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "roundabout";
			newRow[columns[1]] = "100";
			newTable->Rows->Add(newRow);

			this->m_dataSetBinder->NodeControlTypes = newTable;
		}
		
		void SetDefaultLinkTypes() {
			array<String^>^ columns = { "link_type", "link_type_name", "type_code", "default_lane_capacity", "default_speed_limit"
				, "default_number_of_lanes" };		
			DataTable^ newTable = gcnew DataTable();
			// define fields
			for each (String^ col in columns)
			{
				newTable->Columns->Add(gcnew DataColumn(col));
			}
			DataRow^ newRow = nullptr;
			newRow = newTable->NewRow(); // create new row
			int colIndex = 0;
			newRow[columns[colIndex++]] = "1";
			newRow[columns[colIndex++]] = "Freeway";
			newRow[columns[colIndex++]] = "f";
			newRow[columns[colIndex++]] = "1800";
			newRow[columns[colIndex++]] = "65";
			newRow[columns[colIndex++]] = "3";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "2";
			newRow[columns[colIndex++]] = "Highway/Expressway";
			newRow[columns[colIndex++]] = "h";
			newRow[columns[colIndex++]] = "1450";
			newRow[columns[colIndex++]] = "50";
			newRow[columns[colIndex++]] = "3";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "3";
			newRow[columns[colIndex++]] = "Principal arterial";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "1000";
			newRow[columns[colIndex++]] = "40";
			newRow[columns[colIndex++]] = "3";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "4";
			newRow[columns[colIndex++]] = "Major arterial";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "900";
			newRow[columns[colIndex++]] = "35";
			newRow[columns[colIndex++]] = "3";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "5";
			newRow[columns[colIndex++]] = "Minor arterial";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "850";
			newRow[columns[colIndex++]] = "30";
			newRow[columns[colIndex++]] = "2";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "6";
			newRow[columns[colIndex++]] = "Collector";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "650";
			newRow[columns[colIndex++]] = "25";
			newRow[columns[colIndex++]] = "1";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "7";
			newRow[columns[colIndex++]] = "Local";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "600";
			newRow[columns[colIndex++]] = "20";
			newRow[columns[colIndex++]] = "1";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "8";
			newRow[columns[colIndex++]] = "Mountain road";
			newRow[columns[colIndex++]] = "a";
			newRow[columns[colIndex++]] = "300";
			newRow[columns[colIndex++]] = "45";
			newRow[columns[colIndex++]] = "2";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "9";
			newRow[columns[colIndex++]] = "Ramp";
			newRow[columns[colIndex++]] = "r";
			newRow[columns[colIndex++]] = "1300";
			newRow[columns[colIndex++]] = "30";
			newRow[columns[colIndex++]] = "2";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "10";
			newRow[columns[colIndex++]] = "Zonal connector";
			newRow[columns[colIndex++]] = "c";
			newRow[columns[colIndex++]] = "2000";
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "2";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "Transit link";
			newRow[columns[colIndex++]] = "t";
			newRow[columns[colIndex++]] = "1000";
			newRow[columns[colIndex++]] = "40";
			newRow[columns[colIndex++]] = "1";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "200";
			newRow[columns[colIndex++]] = "Walking link";
			newRow[columns[colIndex++]] = "w";
			newRow[columns[colIndex++]] = "1000";
			newRow[columns[colIndex++]] = "5";
			newRow[columns[colIndex++]] = "1";
			newTable->Rows->Add(newRow);
			this->m_dataSetBinder->LinkTypes = newTable;
		}
		// 필수값 체크
		bool ValidateRequired() {
			if (String::IsNullOrEmpty(tbName->Text)) {
				Alert::Error("project name is required.");
				tbName->Focus();
				return false;
			}
			return true;
		}
		void CreateProject() {
			if (!ValidateRequired()) {
				return;
			}
			// 중복 실행 방지를 위해 컴포넌트 비활성화
			SetEnableComponents(false);
			backgroundWorker->RunWorkerAsync();
		}
		void AddProgressValue(int value) {
			SetProgressValue(newProgress->Value + value);
		}
		void SetProgressValue(int value) {
			// progress value의 최대/최소 값을 체크
			if (value > newProgress->Maximum) {
				newProgress->Value = newProgress->Maximum;
			}
			else if (value < newProgress->Minimum) {
				newProgress->Value = newProgress->Minimum;
			}
			else {
				newProgress->Value = value;
			}
		}
		void UpdateProgress(int value) {
			SetProgressValue(value);
		}
		System::Void backgroundWorkerDoWork(Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
			updateProgress = gcnew UpdateProgressDelegate(this, &NewProjectForm::UpdateProgress);
			int totalProgressStep = 10;
			int progressValue = 0;
			this->m_dataSetBinder->ProjectName = tbName->Text;
			this->m_dataSetBinder->ShapeFilePath = tbShapeFilePath->Text;
			this->m_dataSetBinder->ClassFilePath = tbClassFilePath->Text;
			this->m_dataSetBinder->ListFilePath = tbListFilePath->Text;
			this->m_dataSetBinder->NetworkFilePath = tbNetworkFilePath->Text;
			this->m_dataSetBinder->FragParamFilePath = tbFragCurParamFilePath->Text;
			this->m_dataSetBinder->SoilAmpFilePath = tbSoilAmpFilePath->Text;
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			/* Read Shape file */
			this->ReadShapeFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			/* Read components class file */
			/*
			this->ReadComponentsClassFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);
			*/

			/* Read List file */
			this->ReadListFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);


			//* Read network components file */
			this->ReadNetworkComponentsFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			/* Read fragility curve parameter file */
			this->ReadFragilityCurveParamFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			/* Read soil amplification factor file */
			this->ReadSoilAmpFile();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			// set intensity measure data datasource
			this->m_dataSetBinder->IntensityMeasureData[0] = "PGA";
			this->m_dataSetBinder->IntensityMeasureData[1] = "SA";
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			// set recurrence periods datasource
			this->m_dataSetBinder->RecurrencePeriodData[0] = "50";
			this->m_dataSetBinder->RecurrencePeriodData[1] = "100";
			this->m_dataSetBinder->RecurrencePeriodData[2] = "475";
			this->m_dataSetBinder->RecurrencePeriodData[3] = "1000";
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);

			// set damage state datasource
			this->m_dataSetBinder->DamageStateData[0] = "0";
			this->m_dataSetBinder->DamageStateData[1] = "1";
			this->m_dataSetBinder->DamageStateData[2] = "2";
			this->m_dataSetBinder->DamageStateData[3] = "3";
			this->m_dataSetBinder->DamageStateData[4] = "4";
			this->m_dataSetBinder->DamageStateData[5] = "Most probable";
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);
			
			// set node control types
			SetDefaultNodeControlTypes();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);
			
			// set link types
			SetDefaultLinkTypes();
			progressValue += 10;
			backgroundWorker->ReportProgress(progressValue);
			
			// set same all class params
			this->m_dataSetBinder->SeismicSourceData->Columns->Add(gcnew DataColumn(CommConst::GRID_SEISMIC_SOURCES_LIST_COL1));
			this->m_dataSetBinder->SeismicSourceData->Columns->Add(gcnew DataColumn(CommConst::GRID_SEISMIC_SOURCES_LIST_COL2));

			this->m_dataSetBinder->TrafficCarryingParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_TRAFFIC_CARRYING_COL1));
			this->m_dataSetBinder->TrafficCarryingParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_TRAFFIC_CARRYING_COL2));
			this->m_dataSetBinder->TrafficCarryingParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_TRAFFIC_CARRYING_COL3));
			this->m_dataSetBinder->TrafficCarryingParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_TRAFFIC_CARRYING_COL4));
			this->m_dataSetBinder->TrafficCarryingParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_TRAFFIC_CARRYING_COL5));
			this->m_dataSetBinder->IsSameAllTrafficCarryingParam = true;

			this->m_dataSetBinder->RepairCostRatioParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_REPAIR_COST_RATIO_COL1));
			this->m_dataSetBinder->RepairCostRatioParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_REPAIR_COST_RATIO_COL2));
			this->m_dataSetBinder->RepairCostRatioParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_REPAIR_COST_RATIO_COL3));
			this->m_dataSetBinder->RepairCostRatioParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_REPAIR_COST_RATIO_COL4));
			this->m_dataSetBinder->RepairCostRatioParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_REPAIR_COST_RATIO_COL5));
			this->m_dataSetBinder->IsSameAllRepairCostRatioParam = true;

/*
			this->m_dataSetBinder->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL1));
			this->m_dataSetBinder->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL2));
			this->m_dataSetBinder->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL3));
			this->m_dataSetBinder->IsDefaultODZoneParam = true;
*/

			this->m_dataSetBinder->InputDemandMetaParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_INPUT_DEMAND_META_COL1));
			this->m_dataSetBinder->InputDemandMetaParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_INPUT_DEMAND_META_COL2));
			this->m_dataSetBinder->IsDefaultInputDemandMetaParam = true;


		}
		System::Void backgroundWorkerProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			if (newProgress->InvokeRequired) {
				array<Object^>^ args = { e->ProgressPercentage };
				newProgress->Invoke(updateProgress, args);
			}
			else {
				UpdateProgress(e->ProgressPercentage);
			}
		}
		System::Void backgroundWorkerRunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			if (e->Cancelled)    //Messages for the events
			{
				SetProgressValue(0);
				this->m_dataSetBinder = gcnew ProjectDataSetBinder();
				Alert::Error("Fail");
			}
			else
			{
				SetProgressValue(100);
				this->DialogResult = ::DialogResult::OK;
				this->Visible = false;
			}

			// process 종료 후 성공 여부와 상관없이 컴포넌트 활성화
			SetEnableComponents(true);
		}
		void SetEnableComponents(bool enable) {
			tbName->ReadOnly = !enable;
			tbShapeFilePath->ReadOnly = !enable;
			tbClassFilePath->ReadOnly = !enable;
			tbListFilePath->ReadOnly = !enable;
			tbNetworkFilePath->ReadOnly = !enable;
			tbFragCurParamFilePath->ReadOnly = !enable;
			tbSoilAmpFilePath->ReadOnly = !enable;
			btnFindShapeFile->Enabled = enable;
			btnFindClassFile->Enabled = enable;
			btnFindNetworkFile->Enabled = enable;
			btnFindFragParamFile->Enabled = enable;
			btnFindSoilAmpFile->Enabled = enable;
			btnCancel->Enabled = enable;
			btnOK->Enabled = enable;
		}

	private: System::Void NewProjectForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// initialize
		newProgress->Value = 0;
		this->m_dataSetBinder->IntensityMeasureData = gcnew array<String^>(2);
		this->m_dataSetBinder->RecurrencePeriodData = gcnew array<String^>(4);
		this->m_dataSetBinder->DamageStateData = gcnew array<String^>(6);

		// set backgroundWorker work handler
		backgroundWorker->DoWork += gcnew DoWorkEventHandler(this, &NewProjectForm::backgroundWorkerDoWork);
		backgroundWorker->WorkerReportsProgress = true;
		// set backgroundWorker progress changed handler
		backgroundWorker->ProgressChanged += gcnew ProgressChangedEventHandler(this, &NewProjectForm::backgroundWorkerProgressChanged);
		// set backgroundWorker work completed handler
		backgroundWorker->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &NewProjectForm::backgroundWorkerRunWorkerCompleted);

		this->tbName->Focus();
	}
			 
	// 생성
	private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
		CreateProject();
	}
			 
	// 취소
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = ::DialogResult::Cancel;
		this->Close();
	}
			 
	// shape 파일 찾기
	private: System::Void btnFindShapeFile_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ filename = CFileDlgUtil::GetShapeFile();
//		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbShapeFilePath->Text = filename;
		}
	}
			 
	// component class 파일 찾기
	private: System::Void btnFindClassFile_Click(System::Object^  sender, System::EventArgs^  e) {
//		String^ filename = CFileDlgUtil::GetShapeFile();
		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbClassFilePath->Text = filename;
		}
	}

	//Bridge List 파일 찾기
	private: System::Void btnFindListFile_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filename = CFileDlgUtil::GetCsvFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbListFilePath->Text = filename;
		}
	}


	// network component 파일 찾기
	private: System::Void btnFindNetworkFile_Click(System::Object^  sender, System::EventArgs^  e) {
//		String^ filename = CFileDlgUtil::GetShapeFile();
		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbNetworkFilePath->Text = filename;
		}
	}
	
	// fragility cureve paramter 파일 찾기
	private: System::Void btnFindFragParamFile_Click(System::Object^  sender, System::EventArgs^  e) {
//		String^ filename = CFileDlgUtil::GetShapeFile();
		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbFragCurParamFilePath->Text = filename;
		}
	}
			 // 프로젝트 명으로 dialog의 title을 변경
	private: System::Void tbName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->Text = String::IsNullOrEmpty(tbName->Text) ? "New" : tbName->Text;
	}
			 // 프로젝트 명 작성 중 엔터 클릭 시 프로젝트 생성
	private: System::Void tbName_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
		{
			CreateProject();
		}
	}
	private: System::Void NewProjectForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (backgroundWorker->IsBusy) {
			Alert::Info("프로젝트 생성 중에는 창을 닫을 수 없습니다.");
			e->Cancel = true;	
		}
	}

		   // Soil amplification factor 파일 찾기
	private: System::Void btnFindSoilAmpFile_Click(System::Object^ sender, System::EventArgs^ e) {
		//		String^ filename = CFileDlgUtil::GetShapeFile();
		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			tbSoilAmpFilePath->Text = filename;
		}
	}

};
}
