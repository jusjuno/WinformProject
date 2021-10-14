#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "TrafficModule.h"
#include "ShapeChart.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NeXTAInput에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	// </summary>
	//public ref class NeXTAInput : public System::Windows::Forms::Form, IFormValidator
	public ref class NeXTAInput : public WinformProject::BaseForm, IFormValidator
	{
	private:

		ProjectDataSetBinder^ m_dataSet;
		ShapeChart^ m_chart;
		NetworkComponent^ m_networkComponent;
	private: System::Windows::Forms::TreeView^ tvDisplayOptions;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: ChartDirector::WinViewPortControl^ viewPortControl;
	
	public:
		NeXTAInput(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			m_chart = gcnew ShapeChart(dataSet->ShapeData);
			m_networkComponent = gcnew NetworkComponent(dataSet);
		}


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
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


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cboCountOD;

	private: TrafficModule^ m_trafficModule;
	private: System::Windows::Forms::ComboBox^ cboDefaultInputDemandMetaParam;


	private: ChartDirector::WinChartViewer^ chartViewer;
	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^ treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"ID"));
			System::Windows::Forms::TreeNode^ treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"link", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 }));
			System::Windows::Forms::TreeNode^ treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"ID"));
			System::Windows::Forms::TreeNode^ treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"node", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode3 }));
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NeXTAInput::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvInputDemandMeta = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboDefaultODZoneParam = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboDefaultInputDemandMetaParam = (gcnew System::Windows::Forms::ComboBox());
			this->dgvODZone = (gcnew System::Windows::Forms::DataGridView());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->cboCountOD = (gcnew System::Windows::Forms::ComboBox());
			this->tvDisplayOptions = (gcnew System::Windows::Forms::TreeView());
			this->viewPortControl = (gcnew ChartDirector::WinViewPortControl(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInputDemandMeta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvODZone))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewPortControl))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.71428F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.28572F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tableLayoutPanel1->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->dgvInputDemandMeta, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboDefaultODZoneParam, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboDefaultInputDemandMetaParam, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->dgvODZone, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 2, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1368, 714);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &NeXTAInput::tableLayoutPanel1_Paint);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoEllipsis = true;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(968, 7);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Is the default \"Origination and Destination\"";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// dgvInputDemandMeta
			// 
			this->dgvInputDemandMeta->AllowUserToAddRows = false;
			this->dgvInputDemandMeta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvInputDemandMeta, 2);
			this->dgvInputDemandMeta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvInputDemandMeta->Location = System::Drawing::Point(3, 369);
			this->dgvInputDemandMeta->Name = L"dgvInputDemandMeta";
			this->dgvInputDemandMeta->RowHeadersWidth = 62;
			this->dgvInputDemandMeta->RowTemplate->Height = 23;
			this->dgvInputDemandMeta->Size = System::Drawing::Size(502, 302);
			this->dgvInputDemandMeta->TabIndex = 1;
			this->dgvInputDemandMeta->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &NeXTAInput::dgvInputDemandMetaData_DataBindingComplete);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(3, 337);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(432, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Is the default \"Input Demand Meta Data\"";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboDefaultODZoneParam
			// 
			this->cboDefaultODZoneParam->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboDefaultODZoneParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDefaultODZoneParam->FormattingEnabled = true;
			this->cboDefaultODZoneParam->Location = System::Drawing::Point(1300, 3);
			this->cboDefaultODZoneParam->Name = L"cboDefaultODZoneParam";
			this->cboDefaultODZoneParam->Size = System::Drawing::Size(65, 23);
			this->cboDefaultODZoneParam->TabIndex = 4;
			this->cboDefaultODZoneParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboODZoneParam_SelectionChangeCommitted);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(2, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 15);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Number of \"Origin and Destin\"";
			// 
			// cboDefaultInputDemandMetaParam
			// 
			this->cboDefaultInputDemandMetaParam->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboDefaultInputDemandMetaParam->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDefaultInputDemandMetaParam->FormattingEnabled = true;
			this->cboDefaultInputDemandMetaParam->Location = System::Drawing::Point(441, 340);
			this->cboDefaultInputDemandMetaParam->Name = L"cboDefaultInputDemandMetaParam";
			this->cboDefaultInputDemandMetaParam->Size = System::Drawing::Size(64, 23);
			this->cboDefaultInputDemandMetaParam->TabIndex = 5;
			this->cboDefaultInputDemandMetaParam->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboInputDemandMetaParam_SelectionChangeCommitted);
			// 
			// dgvODZone
			// 
			this->dgvODZone->AllowUserToAddRows = false;
			this->dgvODZone->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvODZone, 2);
			this->dgvODZone->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvODZone->Location = System::Drawing::Point(3, 32);
			this->dgvODZone->Name = L"dgvODZone";
			this->dgvODZone->RowHeadersWidth = 62;
			this->dgvODZone->RowTemplate->Height = 23;
			this->dgvODZone->Size = System::Drawing::Size(502, 302);
			this->dgvODZone->TabIndex = 0;
			this->dgvODZone->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &NeXTAInput::dgvODZone_DataBindingComplete);
			// 
			// chartViewer
			// 
			this->chartViewer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 2);
			this->chartViewer->HotSpotCursor = System::Windows::Forms::Cursors::Hand;
			this->chartViewer->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->chartViewer->Location = System::Drawing::Point(511, 33);
			this->chartViewer->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->chartViewer->MouseUsage = ChartDirector::WinChartMouseUsage::ScrollOnDrag;
			this->chartViewer->Name = L"chartViewer";
			this->tableLayoutPanel1->SetRowSpan(this->chartViewer, 3);
			this->chartViewer->ScrollDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->Size = System::Drawing::Size(854, 637);
			this->chartViewer->TabIndex = 7;
			this->chartViewer->TabStop = false;
			this->chartViewer->ZoomDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->ZoomInHeightLimit = 0.1;
			this->chartViewer->ClickHotSpot += gcnew ChartDirector::WinHotSpotEventHandler(this, &NeXTAInput::chartViewer_ClickHotSpot);
			this->chartViewer->ViewPortChanged += gcnew ChartDirector::WinViewPortEventHandler(this, &NeXTAInput::chartViewer_ViewPortChanged);
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &NeXTAInput::chartViewer_SizeChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(699, 5);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(55, 19);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Link";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &NeXTAInput::checkBox1_CheckedChanged);
			// 
			// cboCountOD
			// 
			this->cboCountOD->FormattingEnabled = true;
			this->cboCountOD->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->cboCountOD->Location = System::Drawing::Point(240, 3);
			this->cboCountOD->Margin = System::Windows::Forms::Padding(2);
			this->cboCountOD->Name = L"cboCountOD";
			this->cboCountOD->Size = System::Drawing::Size(98, 23);
			this->cboCountOD->TabIndex = 4;
			this->cboCountOD->SelectionChangeCommitted += gcnew System::EventHandler(this, &NeXTAInput::cboCountOD_SelectionChangeCommitted);
			// 
			// tvDisplayOptions
			// 
			this->tvDisplayOptions->CheckBoxes = true;
			this->tvDisplayOptions->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tvDisplayOptions->Location = System::Drawing::Point(0, 0);
			this->tvDisplayOptions->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tvDisplayOptions->Name = L"tvDisplayOptions";
			treeNode1->Name = L"LinkID";
			treeNode1->Text = L"ID";
			treeNode2->Checked = true;
			treeNode2->Name = L"Link";
			treeNode2->Text = L"link";
			treeNode3->Checked = true;
			treeNode3->Name = L"NodeID";
			treeNode3->Text = L"ID";
			treeNode4->Checked = true;
			treeNode4->Name = L"Node";
			treeNode4->Text = L"node";
			this->tvDisplayOptions->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) { treeNode2, treeNode4 });
			this->tvDisplayOptions->ShowPlusMinus = false;
			this->tvDisplayOptions->Size = System::Drawing::Size(1368, 714);
			this->tvDisplayOptions->TabIndex = 5;
			// 
			// viewPortControl
			// 
			this->viewPortControl->Location = System::Drawing::Point(0, 0);
			this->viewPortControl->Name = L"viewPortControl";
			this->viewPortControl->Size = System::Drawing::Size(300, 200);
			this->viewPortControl->TabIndex = 0;
			this->viewPortControl->TabStop = false;
			this->viewPortControl->Viewer = this->chartViewer;
			// 
			// NeXTAInput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1368, 714);
			this->Controls->Add(this->cboCountOD);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tvDisplayOptions);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NeXTAInput";
			this->Text = L"NEXTA INPUT";
			this->Load += gcnew System::EventHandler(this, &NeXTAInput::NeXTAInput_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInputDemandMeta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvODZone))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewPortControl))->EndInit();
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
			// Yes이면 default 값으로 변경하고 readonly로 변경
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
			// Traffic scenario 재구성
			///////////////////////////////////
			// Traffic scenario는 기본 값 즉 하나의 OD만을 고려함
			// OD zone이 하나 이상 될때는 Traffic Scenario 재구성 필요 
			//bool result = this->m_trafficModule->GenerateScenarios();


		}

					   		 	  
		void SetReadOnlyInputDemandMetaGrid() {
			int selectedIndex = cboDefaultInputDemandMetaParam->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			// Yes이면 default 값으로 변경하고 readonly로 변경
			if (selectedIndex == 0) {
				this->m_dataSet->IsDefaultInputDemandMetaParam = true;
				dgvInputDemandMeta->ReadOnly = true;
			}
			else {
				this->m_dataSet->IsDefaultInputDemandMetaParam = false;
				dgvInputDemandMeta->ReadOnly = false;
			}
		}
		// 하위 노드 체크 상태 변경
		void CheckChildNode(TreeNode^ selectNode) {
			for each (TreeNode ^ tn in selectNode->Nodes) {
				// 하위 노드를 현재 선택된 노드의 상태와 동일하게 변경
				tn->Checked = selectNode->Checked;
				CheckChildNode(tn);
			}
			return;
		}
		// 상위 노드 체크 상태 변경
		void CheckParentNode(TreeNode^ selectNode) {
			// 상위 노드를 현재 하위 노드들의 선택된 노드의 상태와 동일하게 변경
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// 하위 노드가 체크이면 상위 노드는 무조건 1개 이상 이므로 체크
					t->Checked = true;
				}
				else {
					// 체크가 아닐경우 다른 노드들 중 체크가 있는지 확인
					t->Checked = IsCheckedChildNode(t);
				}
			}
		}
		// 노드 체크 상태 변경
		void CheckNode(TreeNode^ selectNode) {
			// 상위 노드를 현재 하위 노드들의 선택된 노드의 상태와 동일하게 변경
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// 하위 노드가 체크이면 상위 노드는 무조건 1개 이상 이므로 체크
					t->Checked = true;
				}
			}
			else {
				// selected node is parent node
				if (!selectNode->Checked) {
					// 체크해제 시 하위의 모든 노드를 체크 해제, 체크 시는 상관없음
					CheckChildNode(selectNode);
				}
			}
		}
		// 하위 노드들 중 체크 상태인 노드 확인
		bool IsCheckedChildNode(TreeNode^ node) {
			for each (TreeNode ^ tn in node->Nodes) {
				if (tn->Checked || IsCheckedChildNode(tn)) {
					return true;
				}
			}
			return false;
		}
		// 옵션 체크
		bool CheckNodeOption(TreeNode^ node, String^ name) {
			for each (TreeNode ^ tn in node->Nodes) {
				if (tn->Name == name) {
					return tn->Checked;
				}
			}
			return false;
		}
		void DrawChart() {
			// check display options
			DisplayOptions options;
			for each (TreeNode ^ node in tvDisplayOptions->Nodes)
			{
				if (node->Name == "Node") {
					options.Node = node->Checked;
					options.NodeID = CheckNodeOption(node, "NodeID");
				}
				else if (node->Name == "Link") {
					options.Link = node->Checked;
					options.LinkID = CheckNodeOption(node, "LinkID");
				}
			}

			m_chart->Draw(chartViewer, "Road Network", options);
		}
		/*
		void GenerateTrafficScenarios() {

			//this->m_dataSet->ResultData = gcnew ResultDataSet(this->m_dataSet->TotalTrafficScenarioCount);

			int temp = this->m_dataSet->TotalTrafficScenarioCount;

			
			
			this->m_trafficModule = gcnew TrafficModule(this->m_dataSet);


			this->m_trafficModule->GenerateScenarios();
		}
		*/


		// 줌 인/아웃
		void ZoomChartViewer()
		{
			if (!chartViewer->IsInViewPortChangedEvent)
			{
				//Remember the center point
				double centerX = chartViewer->ViewPortLeft + chartViewer->ViewPortWidth / 2;
				double centerY = chartViewer->ViewPortTop + chartViewer->ViewPortHeight / 2;

				//Aspect ratio and zoom factor
				double aspectRatio = chartViewer->ViewPortWidth / chartViewer->ViewPortHeight;
				double zoomTo = ((double)Math::Round(Math::Min(chartViewer->ViewPortWidth, chartViewer->ViewPortHeight) * 100)) / 100;

				//Zoom while respecting the aspect ratio
				chartViewer->ViewPortWidth = zoomTo * Math::Max(1.0, aspectRatio);
				chartViewer->ViewPortHeight = zoomTo * Math::Max(1.0, 1 / aspectRatio);

				//Adjust ViewPortLeft and ViewPortTop to keep center point unchanged
				chartViewer->ViewPortLeft = centerX - chartViewer->ViewPortWidth / 2;
				chartViewer->ViewPortTop = centerY - chartViewer->ViewPortHeight / 2;

				//update the chart, but no need to update the image map yet, as the chart is still
				//zooming and is unstable
				chartViewer->updateViewPort(true, false);
			}
		}

	private: System::Void NeXTAInput_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridViewCellStyle = gcnew DataGridViewCellStyle();
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
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

		// 같은 값 사용여부에 따라 값 설정
		cboDefaultODZoneParam->SelectedIndex = (m_dataSet->IsDefaultODZoneParam) ? 0 : 1;
		cboDefaultInputDemandMetaParam->SelectedIndex = (m_dataSet->IsDefaultInputDemandMetaParam) ? 0 : 1;

		// 동일 값 여부에 따라 그리드 읽기전용 여부 설정
		SetReadOnlyODZoneYesNoGrid();
		SetReadOnlyInputDemandMetaGrid();

		tvDisplayOptions->ExpandAll();
		chartViewer->updateViewPort(true, true);
		//m_chart->Draw(chartViewer, "Road Network");
		m_chart->Draw(chartViewer, viewPortControl, "Road Network");


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
		// Traffic scenario 재구성
		//GenerateTrafficScenarios();
		OnSaveDataChanged();
	}
	private: System::Void dgvInputDemandMeta_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		OnSaveDataChanged();
	}
	private: System::Void cboCountOD_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		SetReadOnlyODZoneCountGrid();
	}
	private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {

		//Step1Form 보다 먼저 호출 되면서 오류 발생함
		//DrawChart();
		if (this->m_dataSet != nullptr) {
			DrawChart();
		}
	}
		   // chartViewer에 연결된 viewport 값이 변경되면 실행 됨
	private: System::Void chartViewer_ViewPortChanged(System::Object^ sender, ChartDirector::WinViewPortEventArgs^ e) {
		ZoomChartViewer();
		// Update the chart if necessary
		if (e->NeedUpdateChart) {
			DrawChart();
		}
	}
private: System::Void chartViewer_ClickHotSpot(System::Object^ sender, ChartDirector::WinHotSpotEventArgs^ e) {
	
	//Alert::Error("ddereer");
	Display(sender, e);
}

	   void Display(System::Object^ sender, ChartDirector::WinHotSpotEventArgs^ e) {
		   // Add the name of the ChartViewer control that is being clicked
		   array<String^>^ strArr = gcnew array<String^>(2);
		   strArr[0] = "source";
		   strArr[1] = ((ChartDirector::WinChartViewer^)sender)->Name;
		 //  listView->Items->Add(gcnew ListViewItem(strArr));
		   String^ NodeId;
		   // List out the parameters of the hot spot
		   // field0에 hotspot에서 사용할 데이터를 key=value;key=value 구조로 셋팅
		   if (e->GetAttrValues()->ContainsKey("field0")) {
			   String^ value = e->GetAttrValues()["field0"]->ToString();
			   array<String^>^ attributes = value->Split(';');
			   AttributeType type;
			   for each (String ^ attribute in attributes)
			   {
				   array<String^>^ attr = attribute->Split('=');
				   if (attr->Length == 2) {
					   //AddList(attr[0], attr[1]);
					   if (attr[0] == "TYPE") {
						   Enum::TryParse(attr[1], type);
					   }
					   if (attr[0] == "ID") {
						   NodeId = attr[1]->ToString();
					   }
				   }
			   }
			   String^ filter = "";
			   array<DataRow^>^ foundRows = nullptr;
			   DataRow^ row = nullptr;
			   // 타입별 추가 parameter 설정
			   switch (type)
			   {
			   case AttributeType::Link:

				   break;
			   case AttributeType::Node:
				   if (NodeId != nullptr) {
					   //Alert::Error(NodeId);
					   this->dgvODZone->CurrentCell->Value = NodeId;
				   }
				   break;
			   case AttributeType::Component:
				   break;
			   default:
				   break;
			   }
		   }

	   }
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (checkBox1->Checked == true) {
		this->tvDisplayOptions->Nodes[0]->Checked = false;
		this->tvDisplayOptions->Nodes[0]->FirstNode->Checked = false;
	}
	else {
		this->tvDisplayOptions->Nodes[0]->Checked = true;
		this->tvDisplayOptions->Nodes[0]->FirstNode->Checked = true;
	}

	CheckChildNode(this->tvDisplayOptions->Nodes[0]);
	CheckNode(this->tvDisplayOptions->Nodes[0]->FirstNode);
	DrawChart();

}

};
}
