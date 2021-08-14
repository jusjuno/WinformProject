#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "NetworkComponent.h"
#include "StructureFileList.h"
#include "FragilityCurve.h"


namespace WinformProject {

	using namespace ChartDirector;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Step4bForm에 대한 요약입니다.
	/// </summary>
	public ref class Step4bForm : public System::Windows::Forms::Form
	{

	private:
		static int SAMPLING_SIZE = 100;
	private:
		ProjectDataSetBinder^ m_dataSet;
		array<double>^ m_dataX;
		FragilityCurve^ m_fragilityCurve;
		NetworkComponent^ m_networkComponent;


	public:
		Step4bForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			
			this->m_dataSet = dataSet;
			this->m_fragilityCurve = gcnew FragilityCurve(this->m_dataSet->FragParameterData);
			this->m_networkComponent = gcnew NetworkComponent(dataSet);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step4bForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;

	protected:

	private: ChartDirector::WinChartViewer^ chartViewer;

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
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->dgvNetworkComponent = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
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
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvNetworkComponent, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1164, 691);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 2);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->HotSpotCursor = System::Windows::Forms::Cursors::Hand;
			this->chartViewer->Location = System::Drawing::Point(3, 349);
			this->chartViewer->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1158, 338);
			this->chartViewer->TabIndex = 7;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step4bForm::chartViewer_SizeChanged);
			// 
			// dgvNetworkComponent
			// 
			this->dgvNetworkComponent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvNetworkComponent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvNetworkComponent->Location = System::Drawing::Point(3, 3);
			this->dgvNetworkComponent->Name = L"dgvNetworkComponent";
			this->dgvNetworkComponent->RowHeadersWidth = 51;
			this->dgvNetworkComponent->RowTemplate->Height = 27;
			this->dgvNetworkComponent->Size = System::Drawing::Size(1158, 339);
			this->dgvNetworkComponent->TabIndex = 0;
			this->dgvNetworkComponent->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step4bForm::dgvNetworkComponent_CellDoubleClick);
			this->dgvNetworkComponent->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step4bForm::dgvNetworkComponent_DataBindingComplete);
			// 
			// Step4bForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1164, 691);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step4bForm";
			this->Text = L"Step4bForm";
			this->Load += gcnew System::EventHandler(this, &Step4bForm::Step4bForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Step4bForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		dgvNetworkComponent->DataSource = m_dataSet->NetworkCompnentData;



		if (this->m_dataSet->StructureFileDictionary == nullptr) {
			Alert::Info("이전 prd 파일입니다. 처음부터 다시 시작해야 합니다!");
			return;
		}

		/* Structure File Read */
		if (this->m_dataSet->StructureFileDictionary != nullptr && this->m_dataSet->StructureFileDictionary->Count == 0) {
			StructureFileList^ structureFileList = gcnew StructureFileList("Structure_list_new");
			this->m_dataSet->StructureFileDictionary = structureFileList->StructureFileDict;
		}


		/*테스트*/
		for (int i = 0; i < m_networkComponent->GetCount(); i++)
		{
			// component info
			System::Data::DataRow^ r = m_dataSet->NetworkCompnentData->Rows[i];
			String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
			String^ classID = m_networkComponent->GetValue(i, NetworkComponent::COL_CLASS_ID);
			
			if (this->m_dataSet->StructureFileDictionary->ContainsKey(classID)) {
				Debug::WriteLine("================================================");
				Debug::WriteLine("=================> compID:"+ compID);
				Debug::WriteLine("=================> classID:" + classID);
				Debug::WriteLine("================================================");
			}
		}

	}


	private: System::Void dgvNetworkComponent_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {

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

	private: System::Void dgvNetworkComponent_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		//Debug::WriteLine("dgvNetworkComponent CellDoubleClick!!!!");
		//Debug::WriteLine("e->RowIndex:"+ e->RowIndex);
		//Debug::WriteLine("Columns count:" + this->dgvNetworkComponent->Columns->Count);


		DataGridViewRow^ row = this->dgvNetworkComponent->CurrentRow;
		String^ componentID = StringUtil::nullToString(row->Cells[NetworkComponent::COL_NETWORK_COMP_ID]->Value, "");
		String^ classID = StringUtil::nullToString(row->Cells[NetworkComponent::COL_CLASS_ID]->Value, "");
		Debug::WriteLine("componentID:" + componentID);
		Debug::WriteLine("classID:" + classID);

		DrawFragilityCurves(classID);

	}


	// Draw fragility curves
	private: System::Void DrawFragilityCurves(String^ classID) {
			

		int samplingSize = SAMPLING_SIZE;
		//double xTick = 1.0 / samplingSize;
		double xTick = 3.0 / samplingSize;
		if (m_dataX == nullptr) {
			m_dataX = gcnew array<double>(samplingSize);
			for (int i = 0; i < samplingSize; i++) {
				m_dataX[i] = (i + 1) * xTick;
			}
		}
		// damage stats 1
		array<double>^ dataY0 = gcnew array<double>(m_dataX->Length);
		// damage stats 2
		array<double>^ dataY1 = gcnew array<double>(m_dataX->Length);
		// damage stats 3
		array<double>^ dataY2 = gcnew array<double>(m_dataX->Length);
		// damage stats 4
		array<double>^ dataY3 = gcnew array<double>(m_dataX->Length);


		// damage stats 1, damage stats 2, damage stats 3, damage stats 4
		for (int i = 0; i < m_dataX->Length; i++)
		{
			dataY0[i] = m_fragilityCurve->GetFragilityValue(classID, 1, m_dataX[i], this->m_dataSet->StructureFileDictionary);
			dataY1[i] = m_fragilityCurve->GetFragilityValue(classID, 2, m_dataX[i], this->m_dataSet->StructureFileDictionary);
			dataY2[i] = m_fragilityCurve->GetFragilityValue(classID, 3, m_dataX[i], this->m_dataSet->StructureFileDictionary);
			dataY3[i] = m_fragilityCurve->GetFragilityValue(classID, 4, m_dataX[i], this->m_dataSet->StructureFileDictionary);
		}

		// Create a XYChart object
		ChartDirector::XYChart^ chart = gcnew ChartDirector::XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

		// Set default text color to dark grey (0x333333)
		chart->setColor(ChartDirector::Chart::TextColor, 0x333333);


		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sTitle = "Fragility curve(Class ID:";//취약도곡선
		String^ sXAxisTitle = "Sa(g)";//지반가속도
		String^ sYAxisTitle = "P[D>dsi/Sa]";//피해초과률
		if (sUiLang->Equals("ko-KR")) {
			sTitle = "취약도곡선(분류번호:";
			sXAxisTitle = "지반가속도";
			sYAxisTitle = "피해초과률";
		}

		// Add a title box using grey (0x555555) 20pt Arial font
		chart->addTitle("Fragility curve(Class ID:" + classID + ")", "굴림 Bold", 20, 0x000000);

		chart->setPlotArea(80, 100, chartViewer->Size.Width - 130, chartViewer->Size.Height - 170, ChartDirector::Chart::Transparent, -1, ChartDirector::Chart::Transparent, 0xcccccc);

		// Add a legend box with horizontal layout above the plot area. Use 12pt
		// Arial font, transparent background and border, and line style legend icon.
		ChartDirector::LegendBox^ legend = chart->addLegend(80, 35, false, "굴림 Bold", 12);
		legend->setBackground(ChartDirector::Chart::Transparent, ChartDirector::Chart::Transparent);
		legend->setLineStyleKey();

		// Set axis label font to 12pt Arial
		chart->xAxis()->setLabelStyle("굴림", 12);
		chart->yAxis()->setLabelStyle("굴림", 12);

		// Set the x and y axis stems to transparent, and the x-axis tick color to grey
		chart->xAxis()->setColors(ChartDirector::Chart::Transparent, ChartDirector::Chart::TextColor, ChartDirector::Chart::TextColor, 0x333333);
		chart->xAxis()->setTickLength(10, 0);
		chart->xAxis()->setTickDensity(80);
		chart->xAxis()->setTitle(sXAxisTitle, "굴림 Bold", 12, 0x000000);
		chart->xAxis()->setWidth(3);

		chart->yAxis()->setColors(ChartDirector::Chart::Transparent);
		chart->yAxis()->setTickDensity(40);
		chart->yAxis()->setTitle(sYAxisTitle, "굴림 Bold", 12, 0x000000);
		chart->yAxis()->setLinearScale(0, 1, 0.1);
		chart->yAxis()->setWidth(3);

		// Add a line layer to the chart with 3-pixel line width
		ChartDirector::SplineLayer^ layer = chart->addSplineLayer();
		layer->setLineWidth(3);

		// The x-coordinates for the line layer
		layer->setXData(m_dataX);

		// Add 4 data series to the line layer
		layer->addDataSet(dataY0, 0x5588cc, "DS1(β=" + m_fragilityCurve->GetBc(classID, 1, this->m_dataSet->StructureFileDictionary) + ")");
		layer->addDataSet(dataY1, 0xee9944, "DS2(β=" + m_fragilityCurve->GetBc(classID, 2, this->m_dataSet->StructureFileDictionary) + ")");
		layer->addDataSet(dataY2, 0x99bb55, "DS3(β=" + m_fragilityCurve->GetBc(classID, 3, this->m_dataSet->StructureFileDictionary) + ")");
		layer->addDataSet(dataY3, 0x002233, "DS4(β=" + m_fragilityCurve->GetBc(classID, 4, this->m_dataSet->StructureFileDictionary) + ")");

		// Output the chart
		chartViewer->Chart = chart;
	}


	private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		DataGridViewRow^ row = this->dgvNetworkComponent->CurrentRow;
		if (row != nullptr) {
			String^ componentID = StringUtil::nullToString(row->Cells[NetworkComponent::COL_NETWORK_COMP_ID]->Value, "");
			String^ classID = StringUtil::nullToString(row->Cells[NetworkComponent::COL_CLASS_ID]->Value, "");
			Debug::WriteLine("componentID:" + componentID);
			Debug::WriteLine("classID:" + classID);

			DrawFragilityCurves(classID);
		}

	}
};
}
