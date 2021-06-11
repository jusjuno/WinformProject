#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "NetworkComponent.h"
#include "FragilityCompList.h"
#include "FragilityDataSet.h"
#include "FragilityFile.h"
#include "FragilityCurve.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step3bForm에 대한 요약입니다.
	/// </summary>
	public ref class Step3bForm : public System::Windows::Forms::Form
	{

	private:
		ProjectDataSetBinder^ m_dataSet;

	public:

		Step3bForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();

			this->m_dataSet = dataSet;
	
		}


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step3bForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::DataGridView^ dgvFragilityData;
	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvFragilityData = (gcnew System::Windows::Forms::DataGridView());
			this->dgvNetworkComponent = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFragilityData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->dgvFragilityData, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvNetworkComponent, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1027, 529);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// dgvFragilityData
			// 
			this->dgvFragilityData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFragilityData->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvFragilityData->Location = System::Drawing::Point(3, 267);
			this->dgvFragilityData->Name = L"dgvFragilityData";
			this->dgvFragilityData->RowHeadersWidth = 51;
			this->dgvFragilityData->RowTemplate->Height = 27;
			this->dgvFragilityData->Size = System::Drawing::Size(1021, 259);
			this->dgvFragilityData->TabIndex = 3;
			this->dgvFragilityData->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step3bForm::dgvFragilityData_DataBindingComplete);
			// 
			// dgvNetworkComponent
			// 
			this->dgvNetworkComponent->AllowUserToAddRows = false;
			this->dgvNetworkComponent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvNetworkComponent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvNetworkComponent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvNetworkComponent->Location = System::Drawing::Point(3, 3);
			this->dgvNetworkComponent->MultiSelect = false;
			this->dgvNetworkComponent->Name = L"dgvNetworkComponent";
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dgvNetworkComponent->RowHeadersWidth = 51;
			this->dgvNetworkComponent->RowTemplate->Height = 23;
			this->dgvNetworkComponent->Size = System::Drawing::Size(1021, 258);
			this->dgvNetworkComponent->TabIndex = 2;
			this->dgvNetworkComponent->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step3bForm::dgvNetworkComponent_CellDoubleClick);
			this->dgvNetworkComponent->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step3bForm::dgvNetworkComponent_DataBindingComplete);
			// 
			// Step3bForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 529);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step3bForm";
			this->Text = L"Step3bForm";
			this->Load += gcnew System::EventHandler(this, &Step3bForm::Step3bForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFragilityData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Step3bForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		dgvNetworkComponent->DataSource = m_dataSet->NetworkCompnentData;



	}
	private: System::Void dgvNetworkComponent_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
		//Debug::WriteLine("dgvNetworkComponent CellDoubleClick!!!!");
		//Debug::WriteLine("e->RowIndex:"+ e->RowIndex);
		//Debug::WriteLine("Columns count:" + this->dgvNetworkComponent->Columns->Count);

		DataTable^ tmpDt = gcnew DataTable();
		tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL02));
		tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL03));
		tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL04));
		tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL05));
		tmpDt->Columns->Add(gcnew DataColumn(CommConst::DT_FRAG_CURV_DATA_COL06));

		
		DataGridViewRow^ row = this->dgvNetworkComponent->CurrentRow;
		String^ componentID = StringUtil::nullToString(row->Cells[NetworkComponent::COL_NETWORK_COMP_ID]->Value,"");

		FragilityDataSet^ fragilityDataSet = nullptr;
		if (m_dataSet->FragilityDataSetDictionary->ContainsKey(componentID)) {
			fragilityDataSet = m_dataSet->FragilityDataSetDictionary[componentID];
		}
		else {
			FragilityCurve^ fragilityCurve = gcnew FragilityCurve();
			fragilityDataSet = fragilityCurve->GetFragilityReadFile(m_dataSet, componentID);
		}		

		if (fragilityDataSet != nullptr) {
			DataRow^ row = nullptr;
			for each (KeyValuePair<double, FragilityFile^> ^ pair in fragilityDataSet->FragilityFileDict)
			{
				FragilityFile^ fragilityFile = pair->Value;
				row = tmpDt->NewRow();
				row[CommConst::DT_FRAG_CURV_DATA_COL02] = fragilityFile->PGA;
				row[CommConst::DT_FRAG_CURV_DATA_COL03] = fragilityFile->Slight;
				row[CommConst::DT_FRAG_CURV_DATA_COL04] = fragilityFile->Moderate;
				row[CommConst::DT_FRAG_CURV_DATA_COL05] = fragilityFile->Severe;
				row[CommConst::DT_FRAG_CURV_DATA_COL06] = fragilityFile->Collapse;
				tmpDt->Rows->Add(row);
			}
		}

		dgvFragilityData->DataSource = tmpDt;

	}

	

	private: System::Void dgvNetworkComponent_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Set grid row number and style
		int i = 1;
		for each (DataGridViewRow ^ row in dgvNetworkComponent->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvNetworkComponent->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvNetworkComponent->EnableHeadersVisualStyles = false;
	}

	private: System::Void dgvFragilityData_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Set grid row number and style
		int i = 1;
		for each (DataGridViewRow ^ row in dgvFragilityData->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvFragilityData->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvFragilityData->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvFragilityData->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvFragilityData->EnableHeadersVisualStyles = false;
	}



};
}
