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

	/// <summary>
	/// NeXTAInput�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
	// </summary>
	//public ref class NeXTAInput : public System::Windows::Forms::Form, IFormValidator
	public ref class NeXTAInput : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^ m_dataSet;
	public:
		NeXTAInput(ProjectDataSetBinder^ dataSet)
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
		~NeXTAInput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
	private: System::Windows::Forms::DataGridView^ dgvODZone;

	private: System::Windows::Forms::DataGridView^ dgvInputDemandMeta;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cboDefaultODZoneParam;

	private: System::Windows::Forms::ComboBox^ cboDefaultInputDemandMetaParam;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cboCountOD;

	private: TrafficModule^ m_trafficModule;


	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NeXTAInput::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvODZone = (gcnew System::Windows::Forms::DataGridView());
			this->dgvInputDemandMeta = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboDefaultODZoneParam = (gcnew System::Windows::Forms::ComboBox());
			this->cboDefaultInputDemandMetaParam = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cboCountOD = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvODZone))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInputDemandMeta))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->dgvODZone, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvInputDemandMeta, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboDefaultODZoneParam, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboDefaultInputDemandMetaParam, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1231, 1072);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvODZone
			// 
			this->dgvODZone->AllowUserToAddRows = false;
			this->dgvODZone->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvODZone, 2);
			this->dgvODZone->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvODZone->Location = System::Drawing::Point(4, 38);
			this->dgvODZone->Margin = System::Windows::Forms::Padding(4);
			this->dgvODZone->Name = L"dgvODZone";
			this->dgvODZone->RowHeadersWidth = 62;
			this->dgvODZone->RowTemplate->Height = 23;
			this->dgvODZone->Size = System::Drawing::Size(1223, 494);
			this->dgvODZone->TabIndex = 0;
			this->dgvODZone->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &NeXTAInput::dgvODZone_DataBindingComplete);
			// 
			// dgvInputDemandMeta
			// 
			this->dgvInputDemandMeta->AllowUserToAddRows = false;
			this->dgvInputDemandMeta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvInputDemandMeta, 2);
			this->dgvInputDemandMeta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvInputDemandMeta->Location = System::Drawing::Point(4, 574);
			this->dgvInputDemandMeta->Margin = System::Windows::Forms::Padding(4);
			this->dgvInputDemandMeta->Name = L"dgvInputDemandMeta";
			this->dgvInputDemandMeta->RowHeadersWidth = 62;
			this->dgvInputDemandMeta->RowTemplate->Height = 23;
			this->dgvInputDemandMeta->Size = System::Drawing::Size(1223, 494);
			this->dgvInputDemandMeta->TabIndex = 1;
			this->dgvInputDemandMeta->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &NeXTAInput::dgvInputDemandMetaData_DataBindingComplete);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(4, 536);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1044, 34);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Is the default \"Input Demand Meta Data\"";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboDefaultODZoneParam
			// 
			this->cboDefaultODZoneParam->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cboDefaultODZoneParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDefaultODZoneParam->FormattingEnabled = true;
			this->cboDefaultODZoneParam->Location = System::Drawing::Point(1056, 4);
			this->cboDefaultODZoneParam->Margin = System::Windows::Forms::Padding(4);
			this->cboDefaultODZoneParam->Name = L"cboDefaultODZoneParam";
			this->cboDefaultODZoneParam->Size = System::Drawing::Size(171, 26);
			this->cboDefaultODZoneParam->TabIndex = 4;
			this->cboDefaultODZoneParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboODZoneParam_SelectionChangeCommitted);
			// 
			// cboDefaultInputDemandMetaParam
			// 
			this->cboDefaultInputDemandMetaParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDefaultInputDemandMetaParam->FormattingEnabled = true;
			this->cboDefaultInputDemandMetaParam->Location = System::Drawing::Point(1056, 540);
			this->cboDefaultInputDemandMetaParam->Margin = System::Windows::Forms::Padding(4);
			this->cboDefaultInputDemandMetaParam->Name = L"cboDefaultInputDemandMetaParam";
			this->cboDefaultInputDemandMetaParam->Size = System::Drawing::Size(171, 26);
			this->cboDefaultInputDemandMetaParam->TabIndex = 5;
			this->cboDefaultInputDemandMetaParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboInputDemandMetaParam_SelectionChangeCommitted);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(3, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 18);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Number of \"Origin and Destin\"";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoEllipsis = true;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(644, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(387, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Is the default \"Origination and Destination\"";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cboCountOD
			// 
			this->cboCountOD->FormattingEnabled = true;
			this->cboCountOD->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->cboCountOD->Location = System::Drawing::Point(300, 4);
			this->cboCountOD->Name = L"cboCountOD";
			this->cboCountOD->Size = System::Drawing::Size(121, 26);
			this->cboCountOD->TabIndex = 4;
			this->cboCountOD->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboCountOD_SelectionChangeCommitted);
			// 
			// NeXTAInput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1231, 1072);
			this->Controls->Add(this->cboCountOD);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tableLayoutPanel1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"NeXTAInput";
			this->Text = L"NEXTA INPUT";
			this->Load += gcnew System::EventHandler(this, &NeXTAInput::NeXTAInput_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvODZone))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInputDemandMeta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	public:
		void SetReadOnlyODZoneYesNoGrid() {

			// disable the cboCountOD comboBox
			cboCountOD->Enabled = false;

			int selectedIndexOD = cboDefaultODZoneParam->SelectedIndex;
			//this->m_dataSet->m_odDefaultIndex = false;

			if (selectedIndexOD < 0) {
				return;
			}
			// Yes�̸� default ������ �����ϰ� readonly�� ����
			if (selectedIndexOD == 0) {
				int minID;
				int maxID;
				int tempID;
				int tempIndex = 0;
				for each (KeyValuePair<String^, ShapeNode^>^ pair in m_dataSet->ShapeData->m_SHPNodes)
				{
					tempID = int::Parse(pair->Value->ID);
					if (tempIndex == 0) { minID = tempID; maxID = tempID; }
					else {
						if (minID > tempID) { minID = tempID; }
						if (maxID < tempID) { maxID = tempID; }
					}
					tempIndex++;
				}
/*
				if(this->m_dataSet->m_odZoneParams->Columns->Count == 0){
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL1));
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL2));
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL3));
				}
*/
				if (this->m_dataSet->ODZoneParamData->Columns->Count == 0) {
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL1));
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL2));
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL3));
				}

				//this->m_dataSet->m_odZoneParams->Clear();
				this->m_dataSet->ODZoneParamData->Clear();

				//DataRow^ newRow = this->m_dataSet->m_odZoneParams->NewRow();
				DataRow^ newRow = this->m_dataSet->ODZoneParamData->NewRow();

				newRow[CommConst::GRID_OD_ZONE_COL1] = String::Format("{0}", minID);
				newRow[CommConst::GRID_OD_ZONE_COL2] = String::Format("{0}", maxID);
				newRow[CommConst::GRID_OD_ZONE_COL3] = CommConst::DEFAULT_TRAFFIC_VOLUME;

				//this->m_dataSet->m_odZoneParams->Rows->Add(newRow);

				this->m_dataSet->ODZoneParamData->Rows->Add(newRow);
				this->m_dataSet->IsDefaultODZoneParam = true;
				dgvODZone->ReadOnly = true;

				this->m_dataSet->m_odDefaultIndex = true;
			}


			else {

				if(this->m_dataSet->m_odDefaultIndex == true){
					this->m_dataSet->ODZoneParamData->Clear();
					////cboCountOD->SelectedIndex = 0;
				}

				cboCountOD->Enabled = true;
				this->m_dataSet->IsDefaultODZoneParam = false;
				dgvODZone->ReadOnly = false;
/*
				if (this->m_dataSet->m_odZoneParams->Columns->Count == 0) {
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL1));
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL2));
					this->m_dataSet->m_odZoneParams->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL3));
				}
*/
				if (this->m_dataSet->ODZoneParamData->Columns->Count == 0) {
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL1));
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL2));
					this->m_dataSet->ODZoneParamData->Columns->Add(gcnew DataColumn(CommConst::GRID_OD_ZONE_COL3));
				}


/*

				//if (this->m_dataSet->m_odZoneParams->Rows->Count == 0) {
				if (this->m_dataSet->ODZoneParamData->Rows->Count == 0) {
					//DataRow^ newRow = this->m_dataSet->m_odZoneParams->NewRow();
					DataRow^ newRow = this->m_dataSet->ODZoneParamData->NewRow();
					newRow[CommConst::GRID_OD_ZONE_COL1] = "";
					newRow[CommConst::GRID_OD_ZONE_COL2] = "";
					newRow[CommConst::GRID_OD_ZONE_COL3] = "";

					//this->m_dataSet->m_odZoneParams->Rows->Add(newRow);


					this->m_dataSet->ODZoneParamData->Rows->Add(newRow);

					//this->m_dataSet->IsDefaultODZoneParam = true;
					//dgvODZone->ReadOnly = true;
				}

*/
				this->m_dataSet->m_odDefaultIndex = false;

			}
		}

		void SetReadOnlyODZoneCountGrid() {

			int selectedIndexOD = cboDefaultODZoneParam->SelectedIndex;


			if (selectedIndexOD < 0) {
				return;
			}

			if (this->m_dataSet->m_odDefaultIndex == true) {

				//this->m_dataSet->m_odZoneParams->Clear();
				this->m_dataSet->ODZoneParamData->Clear();
			}

			for (int i = 0; i <= cboCountOD->SelectedIndex; i++) {
				//DataRow^ newRow = this->m_dataSet->m_odZoneParams->NewRow();
				DataRow^ newRow = this->m_dataSet->ODZoneParamData->NewRow();
				newRow[CommConst::GRID_OD_ZONE_COL1] = "";
				newRow[CommConst::GRID_OD_ZONE_COL2] = "";
				newRow[CommConst::GRID_OD_ZONE_COL3] = "";
				//this->m_dataSet->m_odZoneParams->Rows->Add(newRow);
				this->m_dataSet->ODZoneParamData->Rows->Add(newRow);
			}

			this->m_dataSet->IsDefaultODZoneParam = false;
			dgvODZone->ReadOnly = false;


			///////////////////////////////////
			// Traffic scenario �籸��
			///////////////////////////////////
			// Traffic scenario�� �⺻ �� �� �ϳ��� OD���� �����
			// OD zone�� �ϳ� �̻� �ɶ��� Traffic Scenario �籸�� �ʿ� 
			//bool result = this->m_trafficModule->GenerateScenarios();


		}

					   		 	  
		void SetReadOnlyInputDemandMetaGrid() {
			int selectedIndex = cboDefaultInputDemandMetaParam->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			// Yes�̸� default ������ �����ϰ� readonly�� ����
			if (selectedIndex == 0) {
				this->m_dataSet->IsDefaultInputDemandMetaParam = true;
				dgvInputDemandMeta->ReadOnly = true;
			}
			else {
				this->m_dataSet->IsDefaultInputDemandMetaParam = false;
				dgvInputDemandMeta->ReadOnly = false;
			}
		}
	private: System::Void NeXTAInput_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridViewCellStyle = gcnew DataGridViewCellStyle();
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"����", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

//		this->dgvODZone->DataSource = this->m_dataSet->m_odZoneParams;
		this->dgvODZone->DataSource = this->m_dataSet->ODZoneParamData;
		this->dgvInputDemandMeta->DataSource = this->m_dataSet->InputDemandMetaParamData;


		array<String^>^ arrYesOrNo = gcnew array<String^>(2);
		arrYesOrNo[0] = "Yes";
		arrYesOrNo[1] = "No";
		cboDefaultODZoneParam->Items->AddRange(arrYesOrNo);
		cboDefaultInputDemandMetaParam->Items->AddRange(arrYesOrNo);

		// ���� �� ��뿩�ο� ���� �� ����
		cboDefaultODZoneParam->SelectedIndex = (m_dataSet->IsDefaultODZoneParam) ? 0 : 1;
		cboDefaultInputDemandMetaParam->SelectedIndex = (m_dataSet->IsDefaultInputDemandMetaParam) ? 0 : 1;

		// ���� �� ���ο� ���� �׸��� �б����� ���� ����
		SetReadOnlyODZoneYesNoGrid();
		SetReadOnlyInputDemandMetaGrid();
	}
	private: System::Void cboODZoneParam_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		SetReadOnlyODZoneYesNoGrid();
	}
	private: System::Void cboInputDemandMetaParam_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		SetReadOnlyInputDemandMetaGrid();
	}
	private: System::Void dgvODZone_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Set grid row number and style
		int i = 1;
		for each (DataGridViewRow ^ row in dgvODZone->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvODZone->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvODZone->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvODZone->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvODZone->EnableHeadersVisualStyles = false;
		this->dgvODZone->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &NeXTAInput::dgvODZone_CellValueChanged);
	}
	private: System::Void dgvInputDemandMetaData_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Set grid row number and style
		int i = 1;
		for each (DataGridViewRow ^ row in dgvInputDemandMeta->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvInputDemandMeta->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvInputDemandMeta->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvInputDemandMeta->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvInputDemandMeta->EnableHeadersVisualStyles = false;
		this->dgvInputDemandMeta->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &NeXTAInput::dgvInputDemandMeta_CellValueChanged);
	}

	private: System::Void dgvODZone_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		OnSaveDataChanged();
	}
	private: System::Void dgvInputDemandMeta_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		OnSaveDataChanged();
	}
	private: System::Void cboCountOD_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		SetReadOnlyODZoneCountGrid();
	}
};
}
