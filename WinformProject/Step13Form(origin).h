#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "RecoveryCost.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "ComponentInfo.h"


namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Step13Form
	/// </summary>
	//public ref class Step13Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step13Form : public WinformProject::BaseForm, IFormValidator

	{
	private:
		ProjectDataSetBinder^ m_dataSet;
		RecoveryCost^ m_recoveryCost;
		array<String^>^ m_chartDataX1;
		array<double>^ m_chartDataY1;
		array<double>^ m_chartDataY2;
		array<String^>^ m_subChartDataX;

	private: ChartDirector::WinChartViewer^ chartViewerSub1;
	private: ChartDirector::WinChartViewer^ chartViewerSub2;
	private: ChartDirector::WinChartViewer^ chartViewerSub3;
	private: ChartDirector::WinChartViewer^ chartViewerSub4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
//	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
		   array<array<double>^>^ m_subChartDataY;

	private:	   array<ComponentClassInfo>^ m_chartDatas;
	private:	   NetworkComponent^ m_networkComponent;


	public:
		Step13Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_recoveryCost = gcnew RecoveryCost(m_dataSet);
			m_networkComponent = gcnew NetworkComponent(this->m_dataSet);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Step13Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	//protected:
	private: System::Windows::Forms::ComboBox^ cboSample;
	private: System::Windows::Forms::ComboBox^ cboSeismicSource;
	private: ChartDirector::WinChartViewer^ chartViewer;
	//protected:

	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvNetworkComponent = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chartViewerSub4 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewerSub1 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->chartViewerSub3 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewerSub2 = (gcnew ChartDirector::WinChartViewer());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub2))->BeginInit();
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
			this->tableLayoutPanel1->Controls->Add(this->dgvNetworkComponent, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub4, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->cboSample, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewerSub2, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1549, 1050);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvNetworkComponent
			// 
			this->dgvNetworkComponent->AllowUserToAddRows = false;
			this->dgvNetworkComponent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Gulim", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvNetworkComponent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvNetworkComponent, 2);
			this->dgvNetworkComponent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvNetworkComponent->Location = System::Drawing::Point(4, 292);
			this->dgvNetworkComponent->Margin = System::Windows::Forms::Padding(4);
			this->dgvNetworkComponent->MultiSelect = false;
			this->dgvNetworkComponent->Name = L"dgvNetworkComponent";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Gulim", 12, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgvNetworkComponent->RowHeadersWidth = 62;
			this->dgvNetworkComponent->RowTemplate->Height = 23;
			this->dgvNetworkComponent->Size = System::Drawing::Size(766, 754);
			this->dgvNetworkComponent->TabIndex = 14;
			this->dgvNetworkComponent->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvNetworkComponent_DataBindingComplete);
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
			// chartViewerSub4
			// 
			this->chartViewerSub4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub4->Location = System::Drawing::Point(1165, 38);
			this->chartViewerSub4->Margin = System::Windows::Forms::Padding(4);
			this->chartViewerSub4->Name = L"chartViewerSub4";
			this->chartViewerSub4->Size = System::Drawing::Size(380, 246);
			this->chartViewerSub4->TabIndex = 13;
			this->chartViewerSub4->TabStop = false;
			this->chartViewerSub4->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewerSub4_SizeChanged);
			// 
			// chartViewerSub1
			// 
			this->chartViewerSub1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub1->Location = System::Drawing::Point(4, 38);
			this->chartViewerSub1->Margin = System::Windows::Forms::Padding(4);
			this->chartViewerSub1->Name = L"chartViewerSub1";
			this->chartViewerSub1->Size = System::Drawing::Size(379, 246);
			this->chartViewerSub1->TabIndex = 10;
			this->chartViewerSub1->TabStop = false;
			this->chartViewerSub1->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewerSub1_SizeChanged);
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 2);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(778, 292);
			this->chartViewer->Margin = System::Windows::Forms::Padding(4);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(767, 754);
			this->chartViewer->TabIndex = 9;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewer_SizeChanged);
			// 
			// cboSample
			// 
			this->cboSample->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(1165, 4);
			this->cboSample->Margin = System::Windows::Forms::Padding(4);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(380, 26);
			this->cboSample->TabIndex = 4;
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSample_SelectionChangeCommitted);
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(391, 4);
			this->cboSeismicSource->Margin = System::Windows::Forms::Padding(4);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(379, 26);
			this->cboSeismicSource->TabIndex = 2;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// chartViewerSub3
			// 
			this->chartViewerSub3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub3->Location = System::Drawing::Point(778, 38);
			this->chartViewerSub3->Margin = System::Windows::Forms::Padding(4);
			this->chartViewerSub3->Name = L"chartViewerSub3";
			this->chartViewerSub3->Size = System::Drawing::Size(379, 246);
			this->chartViewerSub3->TabIndex = 12;
			this->chartViewerSub3->TabStop = false;
			this->chartViewerSub3->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewerSub3_SizeChanged);
			// 
			// chartViewerSub2
			// 
			this->chartViewerSub2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewerSub2->Location = System::Drawing::Point(391, 38);
			this->chartViewerSub2->Margin = System::Windows::Forms::Padding(4);
			this->chartViewerSub2->Name = L"chartViewerSub2";
			this->chartViewerSub2->Size = System::Drawing::Size(379, 246);
			this->chartViewerSub2->TabIndex = 11;
			this->chartViewerSub2->TabStop = false;
			this->chartViewerSub2->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewerSub2_SizeChanged);
			// 
			// Step13Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1549, 1050);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step13Form";
			this->Text = L"Step13Form";
			this->Load += gcnew System::EventHandler(this, &Step13Form::Step13Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewerSub2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

/*
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
*/



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

// 그래프 타입1: Multi-Stacked Bar Chart (병렬 나열이 아닌 직렬로 하나의 막대그래프 내 여러개 데이터 표현) 
/*
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
*/


// 그래프 타입2: y축 아래에 있는 면적 표현
/*
		void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {

//			double data[] = { 30, 28, 40, 55, 75, 68, 54, 60, 50, 62, 75, 65, 75, 89, 60, 55, 53, 35, 50, 66,
//	56, 48, 52, 65, 62 };
			array<double>^ data = { 30, 28, 40, 55, 75, 68, 54, 60, 50, 62, 75, 65, 75, 89, 60, 55, 53, 35, 50, 66,
	56, 48, 52, 65, 62 };

			// The labels for the area chart
//			const char* labels[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
//				"13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24" };

			array<String^>^ labels = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
				"13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24" };

			// Create a XYChart object of size 250 x 250 pixels
			//XYChart^ c = gcnew XYChart(250, 250);

			// Set the plotarea at (30, 20) and of size 200 x 200 pixels
			//c->setPlotArea(30, 20, 200, 200);

			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			int plotAreaWidth = chartViewer->Size.Width - 150;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			c->addTitle("", "Times New Roman Bold", 17);


			// Add an area chart layer using the given data
			//c->addAreaLayer(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))));
			c->addAreaLayer(data);

			// Set the labels on the x axis.
//			c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
			c->xAxis()->setLabels(labels);

			// Display 1 out of 3 labels on the x-axis.
			c->xAxis()->setLabelStep(3);

			// Output the chart
//			c->makeChart("simplearea.png");
			chartViewer->Chart = c;

			//free up resources
			delete c;
//			return 0;

		}

*/


//그래프 타입3: 수평 막대그래프
/*
void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {

	array<double>^ data = { 1350, 1600, 1950, 2300, 2700 };
	// The labels for the bar chart
	array<String^>^ labels = { "2001", "2002", "2003", "2004", "2005" };
	// The colors for the bars
	array<int>^ colors = { 0xcc0000, 0x66aaee, 0xeebb22, 0xcccccc, 0xcc88ff };

	XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);
	int plotAreaWidth = chartViewer->Size.Width - 150;
	int plotAreaHeight = chartViewer->Size.Height - 120;
	c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);

	// Use the white on black palette, which means the default text and line colors are white
	c->setColors(Chart::whiteOnBlackPalette);

	// Use a vertical gradient color from blue (0000cc) to deep blue (000044) as background. Use
	// rounded corners of 30 pixels radius for the top-left and bottom-right corners.
	c->setBackground(c->linearGradientColor(0, 0, 0, c->getHeight(), 0x0000cc, 0x000044));
	c->setRoundedFrame(0xffffff, 30, 0, 30, 0);

	// Add a title using 18pt Times New Roman Bold Italic font. Add 6 pixels top and bottom margins
	// to the title.

	Box^ title = c->addTitle("Annual Revenue for Star Tech", "timesbi.ttf", 18);

	// Add a separator line in white color just under the title
	c->addLine(20, title->getHeight(), c->getWidth() - 21, title->getHeight(), 0xffffff);

	// Tentatively set the plotarea at (70, 80) and of 480 x 240 pixels in size. Use transparent
	// border and white grid lines
	c->setPlotArea(70, 80, 480, 240, -1, -1, Chart::Transparent, 0xffffff);

	// Swap the axis so that the bars are drawn horizontally
	c->swapXY();

	// Add a multi-color bar chart layer using the supplied data. Use bar gradient lighting with the
	// light intensity from 0.75 to 2.0
	c->addBarLayer(data,colors)->setBorderColor(Chart::Transparent,Chart::barLighting(0.75, 2.0));

	// Set the labels on the x axis.
	c->xAxis()->setLabels(labels);

	// Show the same scale on the left and right y-axes
	c->syncYAxis();

	// Set the bottom y-axis title using 10pt Arial Bold font
	c->yAxis()->setTitle("USD (millions)", "arialbd.ttf", 10);

	// Set y-axes to transparent
	c->yAxis()->setColors(Chart::Transparent);
	c->yAxis2()->setColors(Chart::Transparent);

	// Disable ticks on the x-axis by setting the tick color to transparent
	c->xAxis()->setTickColor(Chart::Transparent);

	// Set the label styles of all axes to 8pt Arial Bold font
	c->xAxis()->setLabelStyle("arialbd.ttf", 8);
	c->yAxis()->setLabelStyle("arialbd.ttf", 8);
	c->yAxis2()->setLabelStyle("arialbd.ttf", 8);

	// Adjust the plot area size, such that the bounding box (inclusive of axes) is 30 pixels from
	// the left edge, 25 pixels below the title, 50 pixels from the right edge, and 25 pixels from
	// the bottom edge.
	c->packPlotArea(30, title->getHeight() + 25, c->getWidth() - 50, c->getHeight() - 25);
//	c->packPlotArea(30, 18 + 25, c->getWidth() - 50, c->getHeight() - 25);

	// Output the chart
	chartViewer->Chart = c;

	//free up resources
	delete c;
}
*/


//그래프 타입4: Multi_Bar Chart (직렬 합산이 아닌 병렬로 x축 한 값에 대한 여러개의 y축 데이터 표현)  
/*
void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {

	// The data for the bar chart
	//array<double>^ data
	array<double>^ data0 = { 100, 125, 245, 147, 67 };
	array<double>^ data1 = { 85, 156, 179, 211, 123 };
	array<double>^ data2 = { 97, 87, 56, 267, 157 };
	array<String^>^ labels = { "Mon", "Tue", "Wed", "Thu", "Fri" };

	XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);
	int plotAreaWidth = chartViewer->Size.Width - 150;
	int plotAreaHeight = chartViewer->Size.Height - 120;
	c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);

	// Add a title to the chart using 10 pt Arial font
	c->addTitle("         Average Weekday Network Load", "", 10);

	// Add a legend box at (55, 18) using horizontal layout. Use 8 pt Arial font, with transparent
	// background
	c->addLegend(55, 18, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the y-axis
	c->yAxis()->setTitle("Throughput (MBytes Per Hour)");

	// Reserve 20 pixels at the top of the y-axis for the legend box
	c->yAxis()->setTopMargin(20);

	// Set the x axis labels
	c->xAxis()->setLabels(labels);

	// Add a multi-bar layer with 3 data sets and 3 pixels 3D depth
	BarLayer^ layer = c->addBarLayer(Chart::Side, 3);


	layer->addDataSet(data0, 0xff8080,"Server #1");
	layer->addDataSet(data1, 0x80ff80,"Server #2");
	layer->addDataSet(data2, 0x8080ff,"Server #3");

	// Output the chart
	chartViewer->Chart = c;

	//free up resources
	delete c;
}
*/


//그래프 타입5: Histogram with Bell Curve  

		void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {

			char buffer[256];
			//String^ buffer;
			//
			// This example demonstrates creating a histogram with a bell curve from raw data. About half of
			// the code is to sort the raw data into slots and to generate the points on the bell curve. The
			// remaining half of the code is the actual charting code.
			//

			// Generate a random guassian distributed data series as the input data for this example.
			//RanSeries* r = new RanSeries(66);
			RanSeries^ r = gcnew RanSeries(66);

			//DoubleArray samples = r->getGaussianSeries(200, 100, 10);
			array<double>^ samples = r->getGaussianSeries(200, 100, 10);
			//
			// Classify the numbers into slots. In this example, the slot width is 5 units.
			//
			int slotSize = 5;

			// Compute the min and max values, and extend them to the slot boundary.
			ArrayMath^ m = gcnew ArrayMath(samples);
			double minX = floor(m->min() / slotSize) * slotSize;
			double maxX = floor(m->max() / slotSize) * slotSize + slotSize;

			// We can now determine the number of slots
			int slotCount = (int)((maxX - minX + 0.5) / slotSize);
			//double* frequency = new double[slotCount];
			array<double>^ frequency = gcnew array<double>(slotCount);
//			memset(frequency, 0, sizeof(*frequency) * slotCount);
			// Count the data points contained in each slot
			for (int i = 0; i < samples->Length; ++i) {
				int slotIndex = (int)((samples[i] - minX) / slotSize);
				frequency[slotIndex] = frequency[slotIndex] + 1;
			}

			//
			// Compute Normal Distribution Curve
			//

			// The mean and standard deviation of the data
			double mean = m->avg();
			double stdDev = m->stdDev();

			// The normal distribution curve (bell curve) is a standard statistics curve. We need to
			// vertically scale it to make it proportion to the frequency count.
			double scaleFactor = slotSize * (samples->Length) / stdDev / sqrt(6.2832);

			// In this example, we plot the bell curve up to 3 standard deviations.
			double stdDevWidth = 3.0;

			// We generate 4 points per standard deviation to be joined with a spline curve.
			int bellCurveResolution = (int)(stdDevWidth * 4 + 1);
			//double* bellCurve = new double[bellCurveResolution];
			array<double>^ bellCurve = gcnew array<double>(bellCurveResolution);

			for (int i = 0; i < bellCurveResolution; ++i) {
				double z = 2 * i * stdDevWidth / (bellCurveResolution - 1) - stdDevWidth;
				bellCurve[i] = exp(-z * z / 2) * scaleFactor;
			}

			//
			// At this stage, we have obtained all data and can plot the chart.
			//

			// Create a XYChart object of size 600 x 360 pixels
			//XYChart* c = new XYChart(600, 360);
			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);
			int plotAreaWidth = chartViewer->Size.Width - 150;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);
			//c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);


			// Set the plotarea at (50, 30) and of size 500 x 300 pixels, with transparent background and
			// border and light grey (0xcccccc) horizontal grid lines
			//c->setPlotArea(50, 30, 500, 300, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

			// Display the mean and standard deviation on the chart
			float temp1 = round(mean * 10) / 10;
			float temp2 = round(stdDev * 10) / 10;

			String^ meanDev = String::Format("Mean ={0} Standard Deviation ={1}", temp1, temp2);

			c->addTitle(meanDev, "arial.ttf");


			// Set the x and y axis label font to 12pt Arial
			c->xAxis()->setLabelStyle("arial.ttf", 12);
			c->yAxis()->setLabelStyle("arial.ttf", 12);

			// Set the x and y axis stems to transparent, and the x-axis tick color to grey (0x888888)
			c->xAxis()->setColors(Chart::Transparent, Chart::TextColor, Chart::TextColor, 0x888888);
			c->yAxis()->setColors(Chart::Transparent);

			// Draw the bell curve as a spline layer in red (0xdd0000) with 2-pixel line width
			//SplineLayer* bellLayer = c->addSplineLayer(DoubleArray(bellCurve, bellCurveResolution), 0xdd0000);
			SplineLayer^ bellLayer = c->addSplineLayer(bellCurve, 0xdd0000);

			bellLayer->setXData(mean - stdDevWidth * stdDev, mean + stdDevWidth * stdDev);
			bellLayer->setLineWidth(2);

			// Draw the histogram as bars in blue (0x6699bb) with dark blue (0x336688) border
			//BarLayer* histogramLayer = c->addBarLayer(DoubleArray(frequency, slotCount), 0x6699bb);
			//BarLayer^ histogramLayer = c->addBarLayer(DoubleArray(frequency, slotCount), 0x6699bb);
			BarLayer^ histogramLayer = c->addBarLayer(frequency, 0x6699bb);
			histogramLayer->setBorderColor(0x336688);
			// The center of the bars span from minX + half_bar_width to maxX - half_bar_width
			histogramLayer->setXData(minX + slotSize / 2.0, maxX - slotSize / 2.0);
			// Configure the bars to touch each other with no gap in between
			histogramLayer->setBarGap(Chart::TouchBar);
			// Use rounded corners for decoration
			histogramLayer->setRoundedCorners();

			// ChartDirector by default will extend the x-axis scale by 0.5 unit to cater for the bar width.
			// It is because a bar plotted at x actually occupies (x +/- half_bar_width), and the bar width
			// is normally 1 for label based x-axis. However, this chart is using a linear x-axis instead of
			// label based. So we disable the automatic extension and add a dummy layer to extend the x-axis
			// scale to cover minX to maxX.
			c->xAxis()->setIndent(false);
			c->addLineLayer()->setXData(minX, maxX);

			// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
			c->yAxis()->setTickDensity(40);

			// Output the chart
			//c->makeChart("histogram.png");
			chartViewer->Chart = c;

			//free up resources
			delete r;
			delete[] frequency;
			delete[] bellCurve;
			delete c;


		}



		// draw sub chart
		void DrawSubChart(WinChartViewer^ viewer, array<double>^ dataY) {
			int plotAreaWidth = viewer->Size.Width - 50;
			//int plotAreaHeight = viewer->Size.Height + 10;
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
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1);
				// The data for main chart
				// generate estimated total network structural cost
				m_chartDataY1[i] = this->m_dataSet->ResultData->GetTotalNetworkStructuralCost(trafficScenarioNo);
				// generate estimated total traffic cost
				m_chartDataY2[i] = this->m_dataSet->ResultData->GetTotalTrafficCost(trafficScenarioNo);

				// the data for sub chart
				m_subChartDataY[i] = gcnew array<double>(this->m_subChartDataX->Length);
				m_subChartDataY[i][0] = this->m_dataSet->ResultData->GetTotalEconomicLossIndices(trafficScenarioNo);
				m_subChartDataY[i][1] = this->m_dataSet->ResultData->GetTotalConnectivityLossIndices(trafficScenarioNo);
				m_subChartDataY[i][2] = this->m_dataSet->ResultData->GetTotalEnvironmentLossIndices(trafficScenarioNo);
			}

			DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
			DrawSubChart1(m_subChartDataY[0]);
			DrawSubChart2(m_subChartDataY[1]);
			DrawSubChart3(m_subChartDataY[2]);
			DrawSubChart4(m_subChartDataY[3]);
		}


		void CreateNetworkComponentChartData() {
			// 클래스 단위로 데이터를 표시하기 위해 클래스 단위로 그룹핑 데이터 생성
			m_chartDatas = gcnew array<ComponentClassInfo>(m_dataSet->ComponentClassData->Rows->Count);
			Random^ rand = gcnew Random();
			int columnCount = m_networkComponent->GetColumnCount();

			// ClassID별로 데이터 생성
			for (int index = 0; index < m_dataSet->ComponentClassData->Rows->Count; index++)
			{
				DataRow^ classDataRow = m_dataSet->ComponentClassData->Rows[index];
				// Define chart data infomation.
				String^ classId = classDataRow[CommConst::GRID_COMP_CLASS_COL1]->ToString();
				m_chartDatas[index].name = classId;
				m_chartDatas[index].color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
				m_chartDatas[index].symbol = index + 1; // present symbol

				// find class's components
				array<DataRow^>^ componentDataRows = m_networkComponent->FindRows(NetworkComponent::COL_CLASS_ID, classId);
				int componentDataRowCount = componentDataRows->Length;
				m_chartDatas[index].dataX = gcnew array<double>(componentDataRowCount);
				m_chartDatas[index].dataY = gcnew array<double>(componentDataRowCount);
				m_chartDatas[index].attributes = gcnew array<ShapeChartAttribute^>(componentDataRowCount);
				// set class's components data
				for (int rowIndex = 0; rowIndex < componentDataRowCount; rowIndex++)
				{
					DataRow^ componentDataRow = componentDataRows[rowIndex];
					double x = 0.0;
					double y = 0.0;
					if (double::TryParse(componentDataRow[NetworkComponent::COL_X]->ToString(), x)
						&& double::TryParse(componentDataRow[NetworkComponent::COL_Y]->ToString(), y)) {
						m_chartDatas[index].dataX[rowIndex] = x;
						m_chartDatas[index].dataY[rowIndex] = y;
					}

					// set component attributes
					/*
					ShapeChartAttribute^ attributes = gcnew ShapeChartAttribute(AttributeType::Component, componentDataRow[NetworkComponent::COL_NETWORK_COMP_ID]->ToString());
					for (int colIndex = 0; colIndex < columnCount; colIndex++)
					{
						if (colIndex != NetworkComponent::COL_X && colIndex != NetworkComponent::COL_Y) {
							attributes->SetAttribute(m_networkComponent->GetColumnName(colIndex), componentDataRow[colIndex]);
						}
					}
					m_chartDatas[index].attributes[rowIndex] = attributes;
					*/
				}
			}
		}
















	private: System::Void Step13Form_Load(System::Object^ sender, System::EventArgs^ e) {
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


		// set table for components of road-network
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		dgvNetworkComponent->DataSource = m_dataSet->NetworkCompnentData;
		// create chart data
		CreateNetworkComponentChartData();








	}









	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
	}
/*
	private: System::Void chartViewerSub1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart1(m_subChartDataY[0]);
		}
	}
	private: System::Void chartViewerSub2_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart1(m_subChartDataY[1]);
		}
	}
	private: System::Void chartViewerSub3_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart1(m_subChartDataY[2]);
		}
	}
	private: System::Void chartViewerSub4_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_subChartDataY != nullptr) {
			DrawSubChart1(m_subChartDataY[3]);
		}
	}
	private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_chartDataX1 != nullptr && m_chartDataY1 != nullptr && m_chartDataY2 != nullptr) {
			DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
		}
	}
*/



private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_chartDataX1 != nullptr && m_chartDataY1 != nullptr && m_chartDataY2 != nullptr) {
		DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
	}
}
private: System::Void chartViewerSub1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_subChartDataY != nullptr) {
		DrawSubChart1(m_subChartDataY[0]);
	}
}
private: System::Void chartViewerSub2_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_subChartDataY != nullptr) {
		DrawSubChart2(m_subChartDataY[1]);
	}
}
private: System::Void chartViewerSub3_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_subChartDataY != nullptr) {
		DrawSubChart3(m_subChartDataY[2]);
	}
}
private: System::Void chartViewerSub4_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_subChartDataY != nullptr) {
		DrawSubChart4(m_subChartDataY[3]);
	}
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




};
}
