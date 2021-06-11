#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Step2Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step2Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step2Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
	public:
		Step2Form(ProjectDataSetBinder^ dataSet)
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
		~Step2Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvCompClass;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dgvCompClass = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCompClass))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvCompClass
			// 
			this->dgvCompClass->AllowUserToAddRows = false;
			this->dgvCompClass->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvCompClass->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvCompClass->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCompClass->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvCompClass->Location = System::Drawing::Point(0, 0);
			this->dgvCompClass->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dgvCompClass->MultiSelect = false;
			this->dgvCompClass->Name = L"dgvCompClass";
			this->dgvCompClass->RowHeadersWidth = 51;
			this->dgvCompClass->RowTemplate->Height = 23;
			this->dgvCompClass->Size = System::Drawing::Size(1239, 951);
			this->dgvCompClass->TabIndex = 0;
			this->dgvCompClass->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step2Form::dgvCompClass_DataBindingComplete);
			// 
			// Step2Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1239, 951);
			this->Controls->Add(this->dgvCompClass);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Step2Form";
			this->Text = L"Bridge List";
			this->Load += gcnew System::EventHandler(this, &Step2Form::Step2Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCompClass))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
		return true;
	}
	private: System::Void Step2Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		dgvCompClass->DataSource = m_dataSet->BridgeList;
	}
	private: System::Void dgvCompClass_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		// Set grid row number and style
		int i = 1;
		for each(DataGridViewRow^ row in dgvCompClass->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvCompClass->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvCompClass->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvCompClass->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvCompClass->EnableHeadersVisualStyles = false;


		//다국어
		/*
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sClassId = "Class ID";//분류번호
		String^ sDescription = "Description";//설명
		if (sUiLang->Equals("ko-KR")) {
			sClassId = "분류번호";
			sDescription = "설명";
		}
		this->dgvCompClass->Columns[0]->HeaderText = sClassId;
		this->dgvCompClass->Columns[1]->HeaderText = sDescription;
		*/

	}
	};
}
