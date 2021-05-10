#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "TrafficModule.h"

namespace WinformProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step8Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
	/// </summary>
	//public ref class Step8Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step8Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::ComboBox^  cboRecurrencePeriod;
	private: System::Windows::Forms::ComboBox^  cboSample;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cboPhase;
	private: ChartDirector::WinChartViewer^  chartViewer1;
	private: ChartDirector::WinChartViewer^  chartViewer2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  btnGenerateTrafficScenario;
	private:
		ProjectDataSetBinder^		m_dataSet;
		ShapeChart^					m_chart;
		TrafficModule^				m_trafficModule;
	public:
		Step8Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			this->m_chart = gcnew ShapeChart(m_dataSet->ShapeData);
			this->m_trafficModule = gcnew TrafficModule(this->m_dataSet);
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Step8Form()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboRecurrencePeriod = (gcnew System::Windows::Forms::ComboBox());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cboPhase = (gcnew System::Windows::Forms::ComboBox());
			this->chartViewer1 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewer2 = (gcnew ChartDirector::WinChartViewer());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnGenerateTrafficScenario = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer2))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Seismic source";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(3, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Recurrence Period";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(3, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Sample";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(136, 3);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(218, 20);
			this->cboSeismicSource->TabIndex = 3;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step8Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// cboRecurrencePeriod
			// 
			this->cboRecurrencePeriod->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboRecurrencePeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrencePeriod->FormattingEnabled = true;
			this->cboRecurrencePeriod->Location = System::Drawing::Point(136, 29);
			this->cboRecurrencePeriod->Name = L"cboRecurrencePeriod";
			this->cboRecurrencePeriod->Size = System::Drawing::Size(218, 20);
			this->cboRecurrencePeriod->TabIndex = 4;
			this->cboRecurrencePeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step8Form::cboRecurrencePeriod_SelectionChangeCommitted);
			// 
			// cboSample
			// 
			this->cboSample->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(136, 55);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(218, 20);
			this->cboSample->TabIndex = 5;
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step8Form::cboSample_SelectionChangeCommitted);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(494, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 26);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Phase";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboPhase
			// 
			this->cboPhase->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboPhase->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPhase->FormattingEnabled = true;
			this->cboPhase->Location = System::Drawing::Point(546, 3);
			this->cboPhase->Name = L"cboPhase";
			this->cboPhase->Size = System::Drawing::Size(535, 20);
			this->cboPhase->TabIndex = 6;
			this->cboPhase->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step8Form::cboPhase_SelectionChangeCommitted);
			// 
			// chartViewer1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer1, 3);
			this->chartViewer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer1->Location = System::Drawing::Point(3, 81);
			this->chartViewer1->Name = L"chartViewer1";
			this->chartViewer1->Size = System::Drawing::Size(485, 427);
			this->chartViewer1->TabIndex = 7;
			this->chartViewer1->TabStop = false;
			this->chartViewer1->SizeChanged += gcnew System::EventHandler(this, &Step8Form::chartViewer1_SizeChanged);
			// 
			// chartViewer2
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer2, 2);
			this->chartViewer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer2->Location = System::Drawing::Point(494, 29);
			this->chartViewer2->Name = L"chartViewer2";
			this->tableLayoutPanel1->SetRowSpan(this->chartViewer2, 3);
			this->chartViewer2->Size = System::Drawing::Size(587, 479);
			this->chartViewer2->TabIndex = 8;
			this->chartViewer2->TabStop = false;
			this->chartViewer2->SizeChanged += gcnew System::EventHandler(this, &Step8Form::chartViewer2_SizeChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel1->Controls->Add(this->cboSample, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboPhase, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboRecurrencePeriod, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer1, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer2, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnGenerateTrafficScenario, 2, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 511);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// btnGenerateTrafficScenario
			// 
			this->btnGenerateTrafficScenario->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnGenerateTrafficScenario->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btnGenerateTrafficScenario->Location = System::Drawing::Point(360, 3);
			this->btnGenerateTrafficScenario->Name = L"btnGenerateTrafficScenario";
			this->tableLayoutPanel1->SetRowSpan(this->btnGenerateTrafficScenario, 3);
			this->btnGenerateTrafficScenario->Size = System::Drawing::Size(128, 72);
			this->btnGenerateTrafficScenario->TabIndex = 9;
			this->btnGenerateTrafficScenario->Text = L"Generate\r\nTraffic\r\nScenarios";
			this->btnGenerateTrafficScenario->UseVisualStyleBackColor = true;
			this->btnGenerateTrafficScenario->Click += gcnew System::EventHandler(this, &Step8Form::btnGenerateTrafficScenario_Click);
			// 
			// Step8Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 511);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step8Form";
			this->Text = L"Step8Form";
			this->Load += gcnew System::EventHandler(this, &Step8Form::Step8Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer2))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
		// seismic source�� �ִ��� Ȯ��
		if (m_dataSet->SeismicSourceData->Rows->Count < 1) {
			Alert::Info("Seismic source is empty.\nYou have to enter a seismic source in Seismic hazard Form.");
			return false;
		}
			// monte cario ���� ������ �ߴ��� Ȯ��
			if (!m_dataSet->IsGeneratedMonteCario) {
				Alert::Info("Monte cario data was not generated.");
				return false;
			}
			return true;
	}
	private:
		bool GenerateTrafficScenarios() {
			// ������ ������ �ó������� ������ Ȯ�� �� ���� ��
			if (this->m_dataSet->IsGeneratedTrafficScenarios) {
				::DialogResult result = System::Windows::Forms::MessageBox::Show(this, "There are already traffic scenarios.\nDo you want to generate traffic scenarios again?", "Generate traffic scenarios", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (::DialogResult::Yes != result) {
					return false;
				}
			}
			bool result = m_trafficModule->GenerateScenarios();
			this->m_dataSet->IsGeneratedTrafficScenarios = result;
			OnSaveDataChanged();
			return result;
		}
		// update phase combobox data
		System::Void UpdatePhaseData(int count) {
			array<String^>^ trafficScenarioPhases = gcnew array<String^>(count);
			for (int i = 0; i < count; i++)
			{
				trafficScenarioPhases[i] = (i + 1).ToString();
			}
			this->cboPhase->Items->Clear();
			this->cboPhase->Items->AddRange(trafficScenarioPhases);
			this->cboPhase->SelectedIndex = 0;
		}
		// draw number of closed link chart(left side)
		System::Void DrawChart1() {
			int selectedIndex = cboRecurrencePeriod->SelectedIndex;
			String^ period = cboRecurrencePeriod->SelectedItem->ToString();
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ sample = cboSample->SelectedItem->ToString();
			String^ title = String::Format("Seismic source: {0} - Scenario: {1}", scenarioName, period);

			// The data for the chart
//			array<double>^ dataX = gcnew array<double>(4);
			//array<double>^ dataX = gcnew array<double>(5);
			array<double>^ dataX = gcnew array<double>(6);
			if (!m_dataSet->IsSameAllTrafficCarryingParam) {
				// ����� ���� �͸� ó�� ���� 
				Alert::Info("Traffic carrying parameters are each different.\nIt can support only same parameters.");
				return;
			}
			else {
				//dataX[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
				//dataX[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
				//dataX[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
				//dataX[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
				dataX[0] = 0;
				dataX[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
				dataX[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
				dataX[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
				dataX[4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
				dataX[5] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4+50;
			}
			array<double>^ dataY = gcnew array<double>(dataX->Length);

			TrafficScenario^ scenario = this->m_dataSet->GetTrafficScenario(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// step8���� �ʿ��� ���α��(functionality)�� ���뼱��  od zone�� �������Ƿ�, ��ǥ odIndex�� "1"�� ����Ѵ�. 
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//int odLocalIndex = 1;
			//TrafficScenario^ scenario = this->m_dataSet->GetTrafficScenario(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
					   
			if (scenario == nullptr) {
				return;
			}

			//array<int>^ tmpClosedLinkCount = TrafficModule::GetClosedLinkCount(scenario, dataX->Length);
			array<int>^ tmpClosedLinkCount = TrafficModule::GetClosedLinkCount(scenario, dataX->Length-1);
			// phase combo�� �׸��� ����
			int phaseCount = 0;
			/*
			for (int i = 0; i < tmpClosedLinkCount->Length; i++)
			{
				dataY[i] = (double)tmpClosedLinkCount[i];
				if ((dataY[i] == 0 || i + 1 == tmpClosedLinkCount->Length) && phaseCount == 0) {
					// closed ��ũ�� ó�� 0�� ��� ���� ��ũ�� ��� open �̱� ������ ���� ������ phase ������ ����
					phaseCount = i + 1;
				}
			}
			*/
			for (int i = 0; i < tmpClosedLinkCount->Length; i++)
			{
				dataY[i] = (double)tmpClosedLinkCount[i];
				if ((dataY[i] == 0 || i + 1 == tmpClosedLinkCount->Length) && phaseCount == 0) {
					// closed ��ũ�� ó�� 0�� ��� ���� ��ũ�� ��� open �̱� ������ ���� ������ phase ������ ����
					phaseCount = i + 1;
				}
			}

			dataY[tmpClosedLinkCount->Length] = 0;

			XYChart^ c = gcnew XYChart(chartViewer1->Size.Width, chartViewer1->Size.Height);

			int plotAreaWidth = chartViewer1->Size.Width - 130;
			int plotAreaHeight = chartViewer1->Size.Height - 120;
			c->setPlotArea(80, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);

			c->addTitle(title, "Times New Roman Bold", 18);

			c->xAxis()->setTitle("Recovery period(days)", "Arial Bold", 12);
			c->yAxis()->setTitle("Traffic capacity(num of closed links)", "Arial Bold", 12);

			StepLineLayer^ layer0 = c->addStepLineLayer(dataY, 0x0000FF, "");
			layer0->setXData(dataX);
			layer0->setLineWidth(2);

			// Output the chart
			chartViewer1->Chart = c;

			// ���� ����Ǿ� ���� chart�� �ٽ� �׸��� phase data�� ����
			UpdatePhaseData(phaseCount);
			DrawChart2();
		}
		// draw traffic phase chart(right side)
		System::Void DrawChart2() {
			int selectedIndex = cboPhase->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			int phase = Int32::Parse(cboPhase->SelectedItem->ToString());
			selectedIndex = cboRecurrencePeriod->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			String^ period = cboRecurrencePeriod->SelectedItem->ToString();
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ title = String::Format("Seismic source: {0} - Scenario: {1} - Ph: {2}", scenarioName, period, phase);

			// create chart data
			Shape^ shape = m_dataSet->ShapeData->Clone();
			Dictionary<String^, int>^ linkIDAndDamageStateDic = gcnew Dictionary<String^, int>();

			TrafficScenario^ scenario = this->m_dataSet->GetTrafficScenario(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// step8���� �ʿ��� ���α��(functionality)�� ���뼱��  od zone�� �������Ƿ�, ��ǥ odIndex�� "1"�� ����Ѵ�. 
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//int odLocalIndex = 1;
			//TrafficScenario^ scenario = this->m_dataSet->GetTrafficScenario(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);


			for each (ComponentInfo component in scenario->Components)
			{
				// ��Ʈ�� �׸��� ���� �ش� �� ��ũ�� �������� ���� ������ ���°� ���������� Ȯ��
				if (linkIDAndDamageStateDic->ContainsKey(component.LinkID)) {
					// �� ��ũ�� ������Ʈ�� ������ �� �� �ֱ⶧���� 
					// ��ϵ� ��ũ�� �̹� ������ ���� damage state�� ���ؼ� �� ū �������� �ݿ�
					if (linkIDAndDamageStateDic[component.LinkID] < component.MaxDamageState) {
						linkIDAndDamageStateDic[component.LinkID] = component.MaxDamageState;
					}
				}
				else {
					// ��ũ�� ������ �߰�
					linkIDAndDamageStateDic->Add(component.LinkID, component.MaxDamageState);
				}
			}
			// component damage ���°� phase ���� ũ�ų� ������ �ش� ��ũ�� close ��
			for (int i = 0; i < shape->m_nRecords; i++)
			{
				shape->m_SHPProperties[i]->IsClose = false;
				if (linkIDAndDamageStateDic->ContainsKey(shape->m_SHPProperties[i]->ID)) {
					int damageState = linkIDAndDamageStateDic[shape->m_SHPProperties[i]->ID];
					if (damageState >= phase) {
						shape->m_SHPProperties[i]->IsClose = true;
					}
				}
			}
			ShapeChart^ chart = gcnew ShapeChart(shape);
			chart->SetShapeWidth(2);
			chart->DrawTrafficPhase(chartViewer2, title);
		}
	private: System::Void Step8Form_Load(System::Object^  sender, System::EventArgs^  e) {
		// �ó������� �����Ǿ� ���� ������, ���� ������ �ڵ����� ����
		if (!this->m_dataSet->IsGeneratedTrafficScenarios) {
			GenerateTrafficScenarios();
		}
		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		this->cboSample->Items->AddRange(this->m_dataSet->TrafficScenarioSamples);
		this->cboSample->SelectedIndex = 0;

		// set recurrence periods datasource
		this->cboRecurrencePeriod->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboRecurrencePeriod->SelectedIndex = 0;

		if (this->m_dataSet->IsGeneratedTrafficScenarios) {
			// �ó������� �����Ǿ� �ִٸ� ���� ��Ʈ�� ����
			DrawChart1();
		}
		else {
			Alert::Error("Failed generate traffic scenarios.");
			this->Close();
		}
	}
	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawChart1();
	}
	private: System::Void cboRecurrencePeriod_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawChart1();
	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawChart1();
	}
	private: System::Void cboPhase_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawChart2();
	}
	private: System::Void chartViewer1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawChart1();
	}
	private: System::Void chartViewer2_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawChart2();
	}
	private: System::Void btnGenerateTrafficScenario_Click(System::Object^  sender, System::EventArgs^  e) {
		GenerateTrafficScenarios();
	}
	};
}
