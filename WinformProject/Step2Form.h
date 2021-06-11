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
	/// Step2Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
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
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"����", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
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


		//�ٱ���
		/*
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sClassId = "Class ID";//�з���ȣ
		String^ sDescription = "Description";//����
		if (sUiLang->Equals("ko-KR")) {
			sClassId = "�з���ȣ";
			sDescription = "����";
		}
		this->dgvCompClass->Columns[0]->HeaderText = sClassId;
		this->dgvCompClass->Columns[1]->HeaderText = sDescription;
		*/

	}
	};
}
