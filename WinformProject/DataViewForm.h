#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "CommConst.h"
#include "FragilityDataSet.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// DataViewForm에 대한 요약입니다.
	/// </summary>
	public ref class DataViewForm : public System::Windows::Forms::Form
	{

	private:
		ProjectDataSetBinder^ m_dataSet;

	public:
		DataViewForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		DataViewForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~DataViewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cboDataName;
	protected:

	private: System::Windows::Forms::DataGridView^ dgvViewData;
	private: System::Windows::Forms::Label^ label1;
	protected:


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
			this->cboDataName = (gcnew System::Windows::Forms::ComboBox());
			this->dgvViewData = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvViewData))->BeginInit();
			this->SuspendLayout();
			// 
			// cboDataName
			// 
			this->cboDataName->FormattingEnabled = true;
			this->cboDataName->Location = System::Drawing::Point(183, 12);
			this->cboDataName->Name = L"cboDataName";
			this->cboDataName->Size = System::Drawing::Size(308, 23);
			this->cboDataName->TabIndex = 0;
			this->cboDataName->SelectedIndexChanged += gcnew System::EventHandler(this, &DataViewForm::cboDataName_SelectedIndexChanged);
			// 
			// dgvViewData
			// 
			this->dgvViewData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvViewData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvViewData->Location = System::Drawing::Point(12, 52);
			this->dgvViewData->Name = L"dgvViewData";
			this->dgvViewData->RowHeadersWidth = 51;
			this->dgvViewData->RowTemplate->Height = 27;
			this->dgvViewData->Size = System::Drawing::Size(993, 458);
			this->dgvViewData->TabIndex = 1;
			this->dgvViewData->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataViewForm::dgvViewData_CellDoubleClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Select Data";
			// 
			// DataViewForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1017, 522);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvViewData);
			this->Controls->Add(this->cboDataName);
			this->Name = L"DataViewForm";
			this->Text = L"DataViewForm";
			this->Load += gcnew System::EventHandler(this, &DataViewForm::DataViewForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvViewData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DataViewForm_Load(System::Object^ sender, System::EventArgs^ e) {


		//cboDataName 초기화
		array<String^>^ strArr = gcnew array<String^>(18);
		strArr[0] = "Bridge List";
		strArr[1] = "Define Component";
		strArr[2] = "Fragility Curve Parameter";
		strArr[3] = "Soil Amplification Facor";
		strArr[4] = "Seismic Source Data";
		strArr[5] = "traffic carrying capacity";//traffic carrying capacity - TrafficCarryingParamData
		strArr[6] = "repair cost ratio parameter";//repair cost ratio parameter - RepairCostRatioParamData
		strArr[7] = "define OD Zone";//define OD Zone - ODZoneParamData
		strArr[8] = "define input demand meta";//define input demand meta - InputDemandMetaParamData
		strArr[9] = "POI connectivity data";//POI connectivity data - POIConnectivityData
		strArr[10] = "connectivity zone define data";//POI connectivity zone define data - POIConnectivityZoneData
		strArr[11] = "envirionment link data";//envirionment link data - EnvironmentData
		strArr[12] = "node control type for NeXTA input";//node control type for NeXTA input - NodeControlTypes
		strArr[13] = "link type for NeXTA input";//link type for NeXTA input - LinkTypes
		strArr[14] = "intensity measure data";//intensity measure data - IntensityMeasureData
		strArr[15] = "recurrence periods data";//recurrence periods data - RecurrencePeriodData
		strArr[16] = "damage state data";//damage state data - DamageStateData
		strArr[17] = "traffic scenario sample";//traffic scenario sample - TrafficScenarioSamples
	
		this->cboDataName->Items->AddRange(strArr);
	}


	private: System::Void cboDataName_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Debug::WriteLine("=============================>SelectedIndex:"+ this->cboDataName->SelectedIndex);


		/*
		Dictionary<String^, DataTable^>^ dicSeismicSourceDictionary = this->m_dataSet->SeismicSourceDictionary;
		Debug::WriteLine(String::Format("========>Count[{0}]", dicSeismicSourceDictionary->Count));
		if (dicSeismicSourceDictionary->Count > 0) {
			List<String^>^ list = gcnew List<String^>(dicSeismicSourceDictionary->Keys);
			String^ sSourceName = list[0];//SeismicSourceDictionary 에서 첫번째 값을 가져옴.
			Debug::WriteLine(String::Format("========>sSourceName[{0}]", sSourceName));
		}
		*/


		if (this->cboDataName->SelectedIndex == 0) {

			//array<String^>^ columns = { CommConst::GRID_COMP_CLASS_COL1, CommConst::GRID_COMP_CLASS_COL2 };
			//DataTable^ newTable = NewTable(columns);
		
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->BridgeList;

		}
		else if (this->cboDataName->SelectedIndex == 1) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->NetworkCompnentData;
		}
		else if (this->cboDataName->SelectedIndex == 2) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->FragParameterData;
		}
		else if (this->cboDataName->SelectedIndex == 3) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->SoilAmpData;
		}
		else if (this->cboDataName->SelectedIndex == 4) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->SeismicSourceData;
		}
		else if (this->cboDataName->SelectedIndex == 5) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->TrafficCarryingParamData;
		}
		else if (this->cboDataName->SelectedIndex == 6) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->RepairCostRatioParamData;
		}
		else if (this->cboDataName->SelectedIndex == 7) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->ODZoneParamData;
		}
		else if (this->cboDataName->SelectedIndex == 8) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->InputDemandMetaParamData;
		}
		else if (this->cboDataName->SelectedIndex == 9) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->POIConnectivityData;
		}
		else if (this->cboDataName->SelectedIndex == 10) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->POIConnectivityZoneData;
		}
		else if (this->cboDataName->SelectedIndex == 11) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->EnvironmentData;
		}
		else if (this->cboDataName->SelectedIndex == 12) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->NodeControlTypes;
		}
		else if (this->cboDataName->SelectedIndex == 13) {
			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = m_dataSet->LinkTypes;
		}
		else if (this->cboDataName->SelectedIndex == 14) {

			//property array<String^>^ IntensityMeasureData {
			DataTable^ dt = NewTable(m_dataSet->IntensityMeasureData);

			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = dt;
		}
		else if (this->cboDataName->SelectedIndex == 15) {

			DataTable^ dt = NewTable(m_dataSet->RecurrencePeriodData);

			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = dt;
		}
		else if (this->cboDataName->SelectedIndex == 16) {

			DataTable^ dt = NewTable(m_dataSet->DamageStateData);

			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = dt;
		}
		else if (this->cboDataName->SelectedIndex == 17) {

			DataTable^ dt = NewTable(m_dataSet->TrafficScenarioSamples);

			this->dgvViewData->DataSource = nullptr;
			this->dgvViewData->DataSource = dt;
		}


	}

	private: System::Data::DataTable^ NewTable(array<String^>^ columns) {
		DataTable^ table = gcnew DataTable();
		for each (String ^ col in columns) {
			table->Columns->Add(gcnew DataColumn(col));
		}
		return table;
	}



	private: System::Void dgvViewData_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	
		int columnIndex = e->ColumnIndex; 
		if (columnIndex == -1) { 
			return; 
		} 
		int rowIndex = e->RowIndex;	
		//Debug::WriteLine(String::Format("========>columnIndex[{0}]", columnIndex));
		//Debug::WriteLine(String::Format("========>rowIndex[{0}]", rowIndex));

		//Seismic Source Data
		if (this->cboDataName->SelectedIndex == 4) {

			//Debug::WriteLine(String::Format("========>Column Name[{0}]", this->dgvViewData->Columns[columnIndex]->Name));
			if (this->dgvViewData->Columns[columnIndex]->Name == "Name") {
				//Debug::WriteLine(String::Format("========>start    SeismicSourceDictionary ....."));

				String^ strVal = this->dgvViewData->Rows[rowIndex]->Cells[columnIndex]->Value->ToString();
				//Debug::WriteLine(String::Format("========>Value [{0}]", strVal));

				DataTable^ dt = this->m_dataSet->SeismicSourceDictionary[strVal];
				this->dgvViewData->DataSource = nullptr;
				this->dgvViewData->DataSource = dt;
			}
		}

	}


};
}
