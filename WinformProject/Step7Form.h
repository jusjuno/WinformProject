#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "TrafficModule.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Step7Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step7Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step7Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
	public:
		Step7Form(ProjectDataSetBinder^ dataSet)
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
		~Step7Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
	private: System::Windows::Forms::DataGridView^  dgvTrafficCarryingCapacity;
	private: System::Windows::Forms::DataGridView^  dgvRepairCostRatio;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cboTrafficCarryingSameParam;
	private: System::Windows::Forms::ComboBox^  cboRepairCostRatioSameParam;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvTrafficCarryingCapacity = (gcnew System::Windows::Forms::DataGridView());
			this->dgvRepairCostRatio = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboTrafficCarryingSameParam = (gcnew System::Windows::Forms::ComboBox());
			this->cboRepairCostRatioSameParam = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTrafficCarryingCapacity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRepairCostRatio))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->dgvTrafficCarryingCapacity, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvRepairCostRatio, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboTrafficCarryingSameParam, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboRepairCostRatioSameParam, 1, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1549, 1142);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvTrafficCarryingCapacity
			// 
			this->dgvTrafficCarryingCapacity->AllowUserToAddRows = false;
			this->dgvTrafficCarryingCapacity->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvTrafficCarryingCapacity, 2);
			this->dgvTrafficCarryingCapacity->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvTrafficCarryingCapacity->Location = System::Drawing::Point(4, 38);
			this->dgvTrafficCarryingCapacity->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgvTrafficCarryingCapacity->Name = L"dgvTrafficCarryingCapacity";
			this->dgvTrafficCarryingCapacity->RowHeadersWidth = 62;
			this->dgvTrafficCarryingCapacity->RowTemplate->Height = 23;
			this->dgvTrafficCarryingCapacity->Size = System::Drawing::Size(1541, 529);
			this->dgvTrafficCarryingCapacity->TabIndex = 0;
			this->dgvTrafficCarryingCapacity->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step7Form::dgvTrafficCarryingCapacity_DataBindingComplete);
			// 
			// dgvRepairCostRatio
			// 
			this->dgvRepairCostRatio->AllowUserToAddRows = false;
			this->dgvRepairCostRatio->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvRepairCostRatio, 2);
			this->dgvRepairCostRatio->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvRepairCostRatio->Location = System::Drawing::Point(4, 609);
			this->dgvRepairCostRatio->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgvRepairCostRatio->Name = L"dgvRepairCostRatio";
			this->dgvRepairCostRatio->RowHeadersWidth = 62;
			this->dgvRepairCostRatio->RowTemplate->Height = 23;
			this->dgvRepairCostRatio->Size = System::Drawing::Size(1541, 529);
			this->dgvRepairCostRatio->TabIndex = 1;
			this->dgvRepairCostRatio->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step7Form::dgvRepairCostRatio_DataBindingComplete);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(4, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1362, 34);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Is the \"traffic carrying capacity - time\" relationship the same for all the";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(4, 571);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1362, 34);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Is the \"Repaire Cost Ratio\" array the same for all the";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboTrafficCarryingSameParam
			// 
			this->cboTrafficCarryingSameParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTrafficCarryingSameParam->FormattingEnabled = true;
			this->cboTrafficCarryingSameParam->Location = System::Drawing::Point(1374, 4);
			this->cboTrafficCarryingSameParam->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboTrafficCarryingSameParam->Name = L"cboTrafficCarryingSameParam";
			this->cboTrafficCarryingSameParam->Size = System::Drawing::Size(171, 26);
			this->cboTrafficCarryingSameParam->TabIndex = 4;
			this->cboTrafficCarryingSameParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step7Form::cboTrafficCarryingSameParam_SelectionChangeCommitted);
			// 
			// cboRepairCostRatioSameParam
			// 
			this->cboRepairCostRatioSameParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRepairCostRatioSameParam->FormattingEnabled = true;
			this->cboRepairCostRatioSameParam->Location = System::Drawing::Point(1374, 575);
			this->cboRepairCostRatioSameParam->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboRepairCostRatioSameParam->Name = L"cboRepairCostRatioSameParam";
			this->cboRepairCostRatioSameParam->Size = System::Drawing::Size(171, 26);
			this->cboRepairCostRatioSameParam->TabIndex = 5;
			this->cboRepairCostRatioSameParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step7Form::cboRepairCostRatioSameParam_SelectionChangeCommitted);
			// 
			// Step7Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1549, 1142);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Step7Form";
			this->Text = L"Step7Form";
			this->Load += gcnew System::EventHandler(this, &Step7Form::Step7Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTrafficCarryingCapacity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRepairCostRatio))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	public:
		void SetReadOnlyTrafficCarryingGrid() {
			int selectedIndex = cboTrafficCarryingSameParam->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			// Yes이면 default 값으로 변경하고 readonly로 변경
			if (selectedIndex == 0) {
				this->m_dataSet->IsSameAllTrafficCarryingParam = true;
				dgvTrafficCarryingCapacity->ReadOnly = true;
			}
			else {
				this->m_dataSet->IsSameAllTrafficCarryingParam = false;
				dgvTrafficCarryingCapacity->ReadOnly = false;
			}
		}
		void SetReadOnlyRepairCostRatioGrid() {
			int selectedIndex = cboRepairCostRatioSameParam->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			// Yes이면 default 값으로 변경하고 readonly로 변경
			if (selectedIndex == 0) {
				this->m_dataSet->IsSameAllRepairCostRatioParam = true;
				dgvRepairCostRatio->ReadOnly = true;
			}
			else {
				this->m_dataSet->IsSameAllRepairCostRatioParam = false;
				dgvRepairCostRatio->ReadOnly = false;
			}
		}
	private: System::Void Step7Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridViewCellStyle = gcnew DataGridViewCellStyle();
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		this->dgvTrafficCarryingCapacity->DataSource = this->m_dataSet->TrafficCarryingParamData;
		this->dgvRepairCostRatio->DataSource = this->m_dataSet->RepairCostRatioParamData;

		array<String^>^ arrYesOrNo = gcnew array<String^>(2);
		arrYesOrNo[0] = "Yes";
		arrYesOrNo[1] = "No";
		cboTrafficCarryingSameParam->Items->AddRange(arrYesOrNo);
		cboRepairCostRatioSameParam->Items->AddRange(arrYesOrNo);

		// 같은 값 사용여부에 따라 값 설정
		cboTrafficCarryingSameParam->SelectedIndex = (m_dataSet->IsSameAllTrafficCarryingParam) ? 0 : 1;
		cboRepairCostRatioSameParam->SelectedIndex = (m_dataSet->IsSameAllRepairCostRatioParam) ? 0 : 1;

		// 동일 값 여부에 따라 그리드 읽기전용 여부 설정
		SetReadOnlyTrafficCarryingGrid();
		SetReadOnlyRepairCostRatioGrid();



		//다국어
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sLabel1 = L"Is the \"traffic carrying capacity - time\" relationship the same for all the";
		String^ sLabel2 = L"Is the \"Repaire Cost Ratio\" array the same for all the";
		if (sUiLang->Equals("ko-KR")) {
			sLabel1 = L"복구기간(일)은 시설물분류 기준으로 동일한가";
			sLabel2 = L"복구비용(율)은 시설물분류 기준으로 동일한가";
		}
		this->label1->Text = sLabel1;
		this->label2->Text = sLabel2;


	}
	private: System::Void cboTrafficCarryingSameParam_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		SetReadOnlyTrafficCarryingGrid();
	}
	private: System::Void cboRepairCostRatioSameParam_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		SetReadOnlyRepairCostRatioGrid();
	}
	private: System::Void dgvTrafficCarryingCapacity_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		// Set grid row number and style
		int i = 1;
		for each(DataGridViewRow^ row in dgvTrafficCarryingCapacity->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvTrafficCarryingCapacity->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvTrafficCarryingCapacity->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvTrafficCarryingCapacity->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvTrafficCarryingCapacity->EnableHeadersVisualStyles = false;
		this->dgvTrafficCarryingCapacity->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step7Form::dgvTrafficCarryingCapacity_CellValueChanged);
	}
	private: System::Void dgvRepairCostRatio_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		// Set grid row number and style
		int i = 1;
		for each(DataGridViewRow^ row in dgvRepairCostRatio->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvRepairCostRatio->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvRepairCostRatio->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvRepairCostRatio->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvRepairCostRatio->EnableHeadersVisualStyles = false;
		this->dgvRepairCostRatio->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step7Form::dgvRepairCostRatio_CellValueChanged);
	}

	private: System::Void dgvTrafficCarryingCapacity_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		OnSaveDataChanged();
	}
	private: System::Void dgvRepairCostRatio_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		OnSaveDataChanged();
	}
	};
}
