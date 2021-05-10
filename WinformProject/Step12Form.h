#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "RecoveryCost.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step12Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step12Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step12Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		RecoveryCost^				m_recoveryCost;
		array<String^>^				m_chartDataX1;
		array<double>^				m_chartDataY1;
		array<double>^				m_chartDataY2;
		array<String^>^				m_subChartDataX;
		array<array<double>^>^		m_subChartDataY;
	public:
		Step12Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_recoveryCost = gcnew RecoveryCost(m_dataSet);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step12Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::ComboBox^  cboSample;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: ChartDirector::WinChartViewer^  chartViewerSub1;
	private: ChartDirector::WinChartViewer^  chartViewerSub2;
	private: ChartDirector::WinChartViewer^  chartViewerSub3;
	private: ChartDirector::WinChartViewer^  chartViewerSub4;
	private: ChartDirector::WinChartViewer^  chartViewer;

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
			this->chartViewerSub1 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewerSub2 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewerSub3 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewerSub4 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub4, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSample, 3, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1549, 1142);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// chartViewerSub1
			// 
			this->chartViewerSub1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub1->Location = System::Drawing::Point(4, 38);
			this->chartViewerSub1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewerSub1->Name = L"chartViewerSub1";
			this->chartViewerSub1->Size = System::Drawing::Size(379, 324);
			this->chartViewerSub1->TabIndex = 0;
			this->chartViewerSub1->TabStop = false;
			this->chartViewerSub1->SizeChanged += gcnew System::EventHandler(this, &Step12Form::chartViewerSub1_SizeChanged);
			// 
			// chartViewerSub2
			// 
			this->chartViewerSub2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub2->Location = System::Drawing::Point(391, 38);
			this->chartViewerSub2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewerSub2->Name = L"chartViewerSub2";
			this->chartViewerSub2->Size = System::Drawing::Size(379, 324);
			this->chartViewerSub2->TabIndex = 0;
			this->chartViewerSub2->TabStop = false;
			this->chartViewerSub2->SizeChanged += gcnew System::EventHandler(this, &Step12Form::chartViewerSub2_SizeChanged);
			// 
			// chartViewerSub3
			// 
			this->chartViewerSub3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub3->Location = System::Drawing::Point(778, 38);
			this->chartViewerSub3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewerSub3->Name = L"chartViewerSub3";
			this->chartViewerSub3->Size = System::Drawing::Size(379, 324);
			this->chartViewerSub3->TabIndex = 0;
			this->chartViewerSub3->TabStop = false;
			this->chartViewerSub3->SizeChanged += gcnew System::EventHandler(this, &Step12Form::chartViewerSub3_SizeChanged);
			// 
			// chartViewerSub4
			// 
			this->chartViewerSub4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub4->Location = System::Drawing::Point(1165, 38);
			this->chartViewerSub4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewerSub4->Name = L"chartViewerSub4";
			this->chartViewerSub4->Size = System::Drawing::Size(380, 324);
			this->chartViewerSub4->TabIndex = 0;
			this->chartViewerSub4->TabStop = false;
			this->chartViewerSub4->SizeChanged += gcnew System::EventHandler(this, &Step12Form::chartViewerSub4_SizeChanged);
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 4);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(4, 370);
			this->chartViewer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1541, 768);
			this->chartViewer->TabIndex = 0;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step12Form::chartViewer_SizeChanged);
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
			this->label1->Size = System::Drawing::Size(379, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Seismic source";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(778, 0);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(379, 34);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Sample";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(391, 4);
			this->cboSeismicSource->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(303, 26);
			this->cboSeismicSource->TabIndex = 1;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step12Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// cboSample
			// 
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(1165, 4);
			this->cboSample->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(303, 26);
			this->cboSample->TabIndex = 1;
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step12Form::cboSample_SelectionChangeCommitted);
			// 
			// Step12Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1549, 1142);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Step12Form";
			this->Text = L"Step12Form";
			this->Load += gcnew System::EventHandler(this, &Step12Form::Step12Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			if (!this->m_dataSet->ResultData->IsCalculatedAdditionalCost) {
				Alert::Info("Additional cost has been not calculated.");
				return false;
			}
			else if (!this->m_dataSet->ResultData->IsCalculatedFunctionality) {
				Alert::Info("Functionality has been not calculated.");
				return false;
			}
			else if (!this->m_dataSet->ResultData->IsCalculatedLossfactor) {
				Alert::Info("Loss factor has been not calculated.");
				return false;
			}
			else if (!this->m_dataSet->ResultData->IsNetworkStructuralCost) {
				Alert::Info("Network structural cost has been not calculated.");
				return false;
			}
			return true;
		}
	private:
		// draw main chart
		void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ sample = cboSample->SelectedItem->ToString();
			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			int plotAreaWidth = chartViewer->Size.Width - 150;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			c->addTitle("", "Times New Roman Bold", 17);

			LegendBox^ b = c->addLegend(120, 10, false, "Arial", 12);
			b->setBackground(Chart::Transparent, Chart::Transparent);
			b->setKeyBorder(Chart::SameAsMainColor);

			// Set the x and y axis stems to transparent and the label font to 12pt Arial
			c->xAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabels(dataX);
			c->xAxis()->setTitle("Recurrence Period (years)", "Arial Bold", 12);

			c->yAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabelStyle("Arial Bold", 12);
			c->yAxis()->setLabelStyle("Arial Bold", 12);
//			c->yAxis()->setTitle("Cost (￦) 10^7", "Arial Bold", 12);
			c->yAxis()->setTitle("백억원(￦)", "Arial Bold", 12);
			c->yAxis()->setLabelFormat("{={value}/10000000}");

			// Add a stacked bar layer
			BarLayer^ layer = c->addBarLayer2(Chart::Stack);

			// Add the three data sets to the bar layer
			layer->addDataSet(dataY1, 0x0000FF, "structural cost");
			layer->addDataSet(dataY2, 0xFFF000, "traffic cost");

			// Set the bar border to transparent
			layer->setBorderColor(Chart::Transparent);
			layer->setLegendOrder(Chart::ReverseLegend);

			// Output the chart
			chartViewer->Chart = c;
			chartViewer->ImageMap = c->getHTMLImageMap("clickable", "", "title='[{dataSetName}]: {xLabel}={value}'");
		}
		// draw sub chart
		void DrawSubChart(WinChartViewer^ viewer, array<double>^ dataY) {
			int plotAreaWidth = viewer->Size.Width - 50;
			int plotAreaHeight = viewer->Size.Height - 60;
			XYChart^ c = gcnew XYChart(viewer->Size.Width, viewer->Size.Height);
			c->setPlotArea(30, 20, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, -1, -1);

			c->xAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabels(m_subChartDataX);
			c->xAxis()->setLabelStyle("Arial Bold", 9);

			c->yAxis()->setColors(Chart::Transparent);
			c->yAxis()->setLabelStyle("Arial Bold", 9);
			c->yAxis()->setLinearScale(0, 1, 1);

			c->addBarLayer(dataY, 0x0000FF)->setBarGap(-0.01);

			viewer->Chart = c;
		}

		void DrawSubChart1(array<double>^ dataY) {
			DrawSubChart(chartViewerSub1, dataY);
		}
		void DrawSubChart2(array<double>^ dataY) {
			DrawSubChart(chartViewerSub2, dataY);
		}
		void DrawSubChart3(array<double>^ dataY) {
			DrawSubChart(chartViewerSub3, dataY);
		}
		void DrawSubChart4(array<double>^ dataY) {
			DrawSubChart(chartViewerSub4, dataY);
		}

		void DrawCharts() {
			if (cboSample->SelectedIndex < 0) {
				return;
			}
			m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
			m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
			m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

			m_subChartDataY = gcnew array<array<double>^>(this->m_dataSet->RecurrencePeriodData->Length);

			//교통시나리오개수 = 지진시나리오(개수) x 샘플링(개수) 에 대한 루프로 구성을 변경
			for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++) 
			{
				m_chartDataX1[i] = this->m_dataSet->RecurrencePeriodData[i];

				// The data for main chart
				// generate estimated total network structural cost
				///////////////////////////////////////////////////////////////////////////////
				// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
				///////////////////////////////////////////////////////////////////////////////
				//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1);
				int odLocalIndex = 1;
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, odLocalIndex);
				m_chartDataY1[i] = this->m_dataSet->ResultData->GetTotalNetworkStructuralCost(trafficScenarioNo);

				// generate estimated total traffic cost
				///////////////////////////////////////////////////////////////////////////////
				// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다  
				///////////////////////////////////////////////////////////////////////////////
				//m_chartDataY2[i] = this->m_dataSet->ResultData->GetTotalTrafficCost(trafficScenarioNo);
				double sumTrafficCost = 0;
				for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j+1);
					sumTrafficCost += this->m_dataSet->ResultData->GetTotalTrafficCost(localTrafficScenarioNo);
				}
				m_chartDataY2[i] = sumTrafficCost;


				// the data of Indices for sub chart

				//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
				int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
				int totalOD = this->m_dataSet->ODZoneParamData->Rows->Count;

				// 통합지수값이 저장된 index 번호
				int indicesIndex = (unitScenarioStep * totalOD) + trafficScenarioNo;
								    // 개별지수값 번호              // 통합지숙값 번호 

				m_subChartDataY[i] = gcnew array<double>(this->m_subChartDataX->Length);
				m_subChartDataY[i][0] = this->m_dataSet->ResultData->GetTotalEconomicLossIndices(indicesIndex);
				m_subChartDataY[i][1] = this->m_dataSet->ResultData->GetTotalConnectivityLossIndices(indicesIndex);
				m_subChartDataY[i][2] = this->m_dataSet->ResultData->GetTotalEnvironmentLossIndices(indicesIndex);
			}

			DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
			DrawSubChart1(m_subChartDataY[0]);
			DrawSubChart2(m_subChartDataY[1]);
			DrawSubChart3(m_subChartDataY[2]);
			DrawSubChart4(m_subChartDataY[3]);
		}
	private: System::Void Step12Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->m_subChartDataX = gcnew array<String^>(3);
		this->m_subChartDataX[0] = "TECO";
		this->m_subChartDataX[1] = "TCON";
		this->m_subChartDataX[2] = "TENV";

		// set combobox datasource for seismic source 
		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		// set combobox datasource for sample
		this->cboSample->Items->AddRange(this->m_dataSet->TrafficScenarioSamples);
		this->cboSample->SelectedIndex = 0;

		DrawCharts();
	}
	private: System::Void chartViewerSub1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart1(m_subChartDataY[0]);
		}
	}
	private: System::Void chartViewerSub2_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart2(m_subChartDataY[1]);
		}
	}
	private: System::Void chartViewerSub3_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart3(m_subChartDataY[2]);
		}
	}
	private: System::Void chartViewerSub4_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart4(m_subChartDataY[3]);
		}
	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (m_chartDataX1 != nullptr && m_chartDataY1 != nullptr && m_chartDataY2 != nullptr) {
			DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
		}
	}
	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawCharts();
	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawCharts();
	}
	};
}
