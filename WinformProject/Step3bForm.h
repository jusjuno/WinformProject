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
	/// Step3bForm�� ���� ����Դϴ�.
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
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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


	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			// 
			// dgvNetworkComponent
			// 
			this->dgvNetworkComponent->AllowUserToAddRows = false;
			this->dgvNetworkComponent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvNetworkComponent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvNetworkComponent->Dock = System::Windows::Forms::DockStyle::Top;
			this->dgvNetworkComponent->Location = System::Drawing::Point(3, 3);
			this->dgvNetworkComponent->MultiSelect = false;
			this->dgvNetworkComponent->Name = L"dgvNetworkComponent";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgvNetworkComponent->RowHeadersWidth = 51;
			this->dgvNetworkComponent->RowTemplate->Height = 23;
			this->dgvNetworkComponent->Size = System::Drawing::Size(1021, 258);
			this->dgvNetworkComponent->TabIndex = 2;
			this->dgvNetworkComponent->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step3bForm::dgvNetworkComponent_CellDoubleClick);
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


		dgvNetworkComponent->DataSource = m_dataSet->NetworkCompnentData;



	}
	private: System::Void dgvNetworkComponent_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
		Debug::WriteLine("dgvNetworkComponent CellDoubleClick!!!!");
		Debug::WriteLine("e->RowIndex:"+ e->RowIndex);
		Debug::WriteLine("Columns count:" + this->dgvNetworkComponent->Columns->Count);

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

	

};
}
