#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "FragilityCurve.h"
#include "NetworkComponent.h"
#include "FragilityCompList.h"
#include "FragilityDataSet.h"
#include "FileUtil.h"
#include "CSVFileManager.h"
#include "FragilityFile.h"

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
	/// Step4Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
	/// </summary>
	//public ref class Step4Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step4Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		// number of sampling(X-axis) 0~100;
		static int SAMPLING_SIZE = 100;
	private:
		ProjectDataSetBinder^		m_dataSet;
		array<double>^				m_dataX;
		FragilityCurve^				m_fragilityCurve;
		NetworkComponent^			m_networkComponent;
	public:
		Step4Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			this->m_fragilityCurve = gcnew FragilityCurve(this->m_dataSet->FragParameterData);
			this->m_networkComponent = gcnew NetworkComponent(dataSet);
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Step4Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::DataGridView^  dgvFragCurveParams;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
	private: System::Windows::Forms::ComboBox^  cboComponentCurves;
	private: System::Windows::Forms::Label^  label1;
	private: ChartDirector::WinChartViewer^  chartViewer;



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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvFragCurveParams = (gcnew System::Windows::Forms::DataGridView());
			this->cboComponentCurves = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFragCurveParams))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel1->Controls->Add(this->dgvFragCurveParams, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboComponentCurves, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 31.79881F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.20119F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 761);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvFragCurveParams
			// 
			this->dgvFragCurveParams->AllowUserToAddRows = false;
			this->dgvFragCurveParams->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvFragCurveParams, 2);
			this->dgvFragCurveParams->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvFragCurveParams->Location = System::Drawing::Point(3, 3);
			this->dgvFragCurveParams->Name = L"dgvFragCurveParams";
			this->dgvFragCurveParams->RowTemplate->Height = 23;
			this->dgvFragCurveParams->Size = System::Drawing::Size(1078, 227);
			this->dgvFragCurveParams->TabIndex = 0;
			this->dgvFragCurveParams->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step4Form::dgvFragCurveParams_DataBindingComplete);

			// 
			// cboComponentCurves
			// 
			this->cboComponentCurves->FormattingEnabled = true;
			this->cboComponentCurves->Location = System::Drawing::Point(219, 236);
			this->cboComponentCurves->Name = L"cboComponentCurves";
			this->cboComponentCurves->Size = System::Drawing::Size(235, 20);
			//this->cboComponentCurves->DropDownStyle = ComboBoxStyle::DropDownList;
			this->cboComponentCurves->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboComponentCurves->TabIndex = 1;
			this->cboComponentCurves->SelectedIndexChanged += gcnew System::EventHandler(this, &Step4Form::cboComponentCurves_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(3, 233);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 26);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Component curves";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 2);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(3, 262);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1078, 496);
			this->chartViewer->TabIndex = 3;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step4Form::chartViewer_SizeChanged);
			// 
			// Step4Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step4Form";
			this->Text = L"Step4Form";
			this->Load += gcnew System::EventHandler(this, &Step4Form::Step4Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFragCurveParams))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	private:
		void GetFragilityCurveData() {

		}
		// Draw fragility curves
		System::Void DrawFragilityCurves() {
			if (cboComponentCurves->SelectedIndex < 0) {
				return;
			}
			DataRowView^ r = (DataRowView^)cboComponentCurves->SelectedItem;
			String^ classID = r[m_networkComponent->GetColumnName(NetworkComponent::COL_CLASS_ID)]->ToString();
			
			String^ componentID = StringUtil::nullToString(r[NetworkComponent::COL_NETWORK_COMP_ID], "-");
			String^ upperType = StringUtil::nullToString(r[NetworkComponent::COL_UPPER_TYPE],"-");
			String^ continuity = StringUtil::nullToString(r[NetworkComponent::COL_CONTINUITY], "-");
			String^ bridgeHeight = StringUtil::nullToString(r[NetworkComponent::COL_BRIDGE_HEIGHT], "-");
			String^ bottomType = StringUtil::nullToString(r[NetworkComponent::COL_BOTTOM_TYPE], "-");
			String^ elastomericShoe = StringUtil::nullToString(r[NetworkComponent::COL_ELASTOMERIC_SHOE], "-");
			String^ briddgeFoundation = StringUtil::nullToString(r[NetworkComponent::COL_BRIDGE_FOUNDATION], "-");
			String^ seismicDesignYn = StringUtil::nullToString(r[NetworkComponent::COL_SEISMIC_DESIGN_YN], "-");
			String^ oldBridge = StringUtil::nullToString(r[NetworkComponent::COL_OLD_BRIDGE], "-");
			String^ oldShoe = StringUtil::nullToString(r[NetworkComponent::COL_OLD_SHOE], "-");
			String^ repairBridge = StringUtil::nullToString(r[NetworkComponent::COL_REPAIR_BRIDGE], "-");
			String^ repairShoe = StringUtil::nullToString(r[NetworkComponent::COL_REPAIR_SHOE], "-");

			String^ selectComponentKey = upperType+"_"+ continuity + "_" + bridgeHeight + "_" + bottomType + "_" 
				                         + elastomericShoe + "_" + briddgeFoundation + "_" + seismicDesignYn + "_" 
				                         + oldBridge + "_" + oldShoe + "_" + repairBridge + "_" + repairShoe ;

			Dictionary<String^, String^>^ fragilityCompDict = WinformProject::FragilityCompList::CompDict;

			//m_FragilityCurvDict->Add("PSC Beam_�ٰ氣_5m����_����_�Ϲ�_����_C_X_X_X_O","PB301203_00000_0001");
			//���Ӽ�	����	�Ϻα���	����	����	�������迩��	���ĵ�(����)	���ĵ�(����)	��������(����)	��������(����)
	



			//=======================================================================================================//
			/* ���� �ҽ� test */
			//double dTest = m_fragilityCurve->GetFragilityValue(classID, 1, 0.02);
			//array<double>^ dsArr = m_fragilityCurve->GetFragilityValues(classID, 0.02);

			//double dTest = m_fragilityCurve->GetFragilityValue(this->m_dataSet, componentID, 1, 0.02);
			//array<double>^ dsArr = m_fragilityCurve->GetFragilityValues(this->m_dataSet, componentID, 0.02);

			//=======================================================================================================//




			Debug::WriteLine("=================>classID:" + classID);
			Debug::WriteLine("=================>componentID:" + componentID);

			if (this->m_dataSet->FragilityDataSetDictionary == nullptr) {
				Alert::Info("���� prd �����Դϴ�. ó������ �ٽ� �����ؾ� �մϴ�!");
				return;
			}

			FragilityDataSet^ fragilityDataSet = nullptr;
			if (this->m_dataSet->FragilityDataSetDictionary->ContainsKey(componentID)) {
				fragilityDataSet = this->m_dataSet->FragilityDataSetDictionary[componentID];
			}
			else {
				if (fragilityCompDict->ContainsKey(selectComponentKey)) {
					String^ sFragilityCurvFileName = fragilityCompDict[selectComponentKey];
					fragilityDataSet = gcnew FragilityDataSet(sFragilityCurvFileName);

					this->m_dataSet->FragilityDataSetDictionary->Add(componentID, fragilityDataSet);

					Debug::WriteLine("=================>count:" + fragilityDataSet->m_FragilityFileDict->Count);
				}
				else {
					Alert::Error("No matching data file!");
				}
			}

			int samplingSize = fragilityDataSet->m_FragilityFileDict->Count;
			array<double>^ m_dataX = gcnew array<double>(samplingSize);

			// damage stats 1
			array<double>^ dataY0 = gcnew array<double>(samplingSize);
			// damage stats 2
			array<double>^ dataY1 = gcnew array<double>(samplingSize);
			// damage stats 3
			array<double>^ dataY2 = gcnew array<double>(samplingSize);
			// damage stats 4
			array<double>^ dataY3 = gcnew array<double>(samplingSize);

			// damage stats 1, damage stats 2, damage stats 3, damage stats 4
			int i = 0;
			for each (KeyValuePair<double, FragilityFile^> ^ pair in fragilityDataSet->m_FragilityFileDict)
			{
				double dPGA = pair->Key;
				FragilityFile^ fragilityFile = pair->Value;

				m_dataX[i] = fragilityFile->PGA;
				dataY0[i] = fragilityFile->Slight;
				dataY1[i] = fragilityFile->Moderate;
				dataY2[i] = fragilityFile->Severe;
				dataY3[i] = fragilityFile->Collapse;

				i++;
			}

			// Create a XYChart object
			ChartDirector::XYChart^ chart = gcnew ChartDirector::XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			// Set default text color to dark grey (0x333333)
			chart->setColor(ChartDirector::Chart::TextColor, 0x333333);


			String^ sUiLang = CultureInfo::CurrentUICulture->Name;
			String^ sTitle = "Fragility curve(Class ID:";//��൵�
			String^ sXAxisTitle = "Sa(g)";//���ݰ��ӵ�
			String^ sYAxisTitle = "P[D>dsi/Sa]";//�����ʰ���
			if (sUiLang->Equals("ko-KR")) {
				sTitle = "��൵�(�з���ȣ:";
				sXAxisTitle = "���ݰ��ӵ�";
				sYAxisTitle = "�����ʰ���";
			}

			// Add a title box using grey (0x555555) 20pt Arial font
			chart->addTitle("Fragility curve(Class ID:" + classID + ")", "���� Bold", 20, 0x000000);

			chart->setPlotArea(80, 100, chartViewer->Size.Width - 130, chartViewer->Size.Height - 170, ChartDirector::Chart::Transparent, -1, ChartDirector::Chart::Transparent, 0xcccccc);

			// Add a legend box with horizontal layout above the plot area. Use 12pt
			// Arial font, transparent background and border, and line style legend icon.
			ChartDirector::LegendBox^ legend = chart->addLegend(80, 35, false, "���� Bold", 12);
			legend->setBackground(ChartDirector::Chart::Transparent, ChartDirector::Chart::Transparent);
			legend->setLineStyleKey();

			// Set axis label font to 12pt Arial
			chart->xAxis()->setLabelStyle("����", 12);
			chart->yAxis()->setLabelStyle("����", 12);

			// Set the x and y axis stems to transparent, and the x-axis tick color to grey
			chart->xAxis()->setColors(ChartDirector::Chart::Transparent, ChartDirector::Chart::TextColor, ChartDirector::Chart::TextColor, 0x333333);
			chart->xAxis()->setTickLength(10, 0);
			chart->xAxis()->setTickDensity(80);
			chart->xAxis()->setTitle(sXAxisTitle, "���� Bold", 12, 0x000000);
			chart->xAxis()->setWidth(3);

			chart->yAxis()->setColors(ChartDirector::Chart::Transparent);
			chart->yAxis()->setTickDensity(40);
			chart->yAxis()->setTitle(sYAxisTitle, "���� Bold", 12, 0x000000);
			chart->yAxis()->setLinearScale(0, 1, 0.1);
			chart->yAxis()->setWidth(3);

			// Add a line layer to the chart with 3-pixel line width
			ChartDirector::SplineLayer^ layer = chart->addSplineLayer();
			layer->setLineWidth(3);

			// The x-coordinates for the line layer
			layer->setXData(m_dataX);

			// Add 4 data series to the line layer
			layer->addDataSet(dataY0, 0x5588cc, "DS1(��=" + m_fragilityCurve->GetBc(classID, 1) + ")");
			layer->addDataSet(dataY1, 0xee9944, "DS2(��=" + m_fragilityCurve->GetBc(classID, 2) + ")");
			layer->addDataSet(dataY2, 0x99bb55, "DS3(��=" + m_fragilityCurve->GetBc(classID, 3) + ")");
			layer->addDataSet(dataY3, 0x002233, "DS4(��=" + m_fragilityCurve->GetBc(classID, 4) + ")");

			// Output the chart
			chartViewer->Chart = chart;

			/*
			String^ sFragilityCurvFileName = nullptr;
			if (fragilityCompDict->ContainsKey(selectComponentKey)) {
				sFragilityCurvFileName = fragilityCompDict[selectComponentKey];
				Debug::WriteLine("=================>sFragilityCurvFileName:" + sFragilityCurvFileName);

				FragilityDataSet^ fragilityDataSet = gcnew FragilityDataSet(sFragilityCurvFileName);
			
				Debug::WriteLine("=================>count:" + fragilityDataSet->m_FragilityFileDict->Count);

				
				int samplingSize = fragilityDataSet->m_FragilityFileDict->Count;
				array<double>^ m_dataX = gcnew array<double>(samplingSize);

				// damage stats 1
				array<double>^ dataY0 = gcnew array<double>(samplingSize);
				// damage stats 2
				array<double>^ dataY1 = gcnew array<double>(samplingSize);
				// damage stats 3
				array<double>^ dataY2 = gcnew array<double>(samplingSize);
				// damage stats 4
				array<double>^ dataY3 = gcnew array<double>(samplingSize);
				
				// damage stats 1, damage stats 2, damage stats 3, damage stats 4
				int i = 0;
				for each (KeyValuePair<double, FragilityFile^> ^ pair in fragilityDataSet->m_FragilityFileDict)
				{
					double dPGA = pair->Key;
					FragilityFile^ fragilityFile = pair->Value;

					m_dataX[i] = fragilityFile->PGA;
					dataY0[i] = fragilityFile->Slight;
					dataY1[i] = fragilityFile->Moderate;
					dataY2[i] = fragilityFile->Severe;
					dataY3[i] = fragilityFile->Collapse;

					i++;
				}
				

				// Create a XYChart object
				ChartDirector::XYChart^ chart = gcnew ChartDirector::XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

				// Set default text color to dark grey (0x333333)
				chart->setColor(ChartDirector::Chart::TextColor, 0x333333);


				String^ sUiLang = CultureInfo::CurrentUICulture->Name;
				String^ sTitle = "Fragility curve(Class ID:";//��൵�
				String^ sXAxisTitle = "Sa(g)";//���ݰ��ӵ�
				String^ sYAxisTitle = "P[D>dsi/Sa]";//�����ʰ���
				if (sUiLang->Equals("ko-KR")) {
					sTitle = "��൵�(�з���ȣ:";
					sXAxisTitle = "���ݰ��ӵ�";
					sYAxisTitle = "�����ʰ���";
				}

				// Add a title box using grey (0x555555) 20pt Arial font
				chart->addTitle("Fragility curve(Class ID:" + classID + ")", "���� Bold", 20, 0x000000);

				chart->setPlotArea(80, 100, chartViewer->Size.Width - 130, chartViewer->Size.Height - 170, ChartDirector::Chart::Transparent, -1, ChartDirector::Chart::Transparent, 0xcccccc);

				// Add a legend box with horizontal layout above the plot area. Use 12pt
				// Arial font, transparent background and border, and line style legend icon.
				ChartDirector::LegendBox^ legend = chart->addLegend(80, 35, false, "���� Bold", 12);
				legend->setBackground(ChartDirector::Chart::Transparent, ChartDirector::Chart::Transparent);
				legend->setLineStyleKey();

				// Set axis label font to 12pt Arial
				chart->xAxis()->setLabelStyle("����", 12);
				chart->yAxis()->setLabelStyle("����", 12);

				// Set the x and y axis stems to transparent, and the x-axis tick color to grey
				chart->xAxis()->setColors(ChartDirector::Chart::Transparent, ChartDirector::Chart::TextColor, ChartDirector::Chart::TextColor, 0x333333);
				chart->xAxis()->setTickLength(10, 0);
				chart->xAxis()->setTickDensity(80);
				chart->xAxis()->setTitle(sXAxisTitle, "���� Bold", 12, 0x000000);
				chart->xAxis()->setWidth(3);

				chart->yAxis()->setColors(ChartDirector::Chart::Transparent);
				chart->yAxis()->setTickDensity(40);
				chart->yAxis()->setTitle(sYAxisTitle, "���� Bold", 12, 0x000000);
				chart->yAxis()->setLinearScale(0, 1, 0.1);
				chart->yAxis()->setWidth(3);

				// Add a line layer to the chart with 3-pixel line width
				ChartDirector::SplineLayer^ layer = chart->addSplineLayer();
				layer->setLineWidth(3);

				// The x-coordinates for the line layer
				layer->setXData(m_dataX);

				// Add 4 data series to the line layer
				layer->addDataSet(dataY0, 0x5588cc, "DS1(��=" + m_fragilityCurve->GetBc(classID, 1) + ")");
				layer->addDataSet(dataY1, 0xee9944, "DS2(��=" + m_fragilityCurve->GetBc(classID, 2) + ")");
				layer->addDataSet(dataY2, 0x99bb55, "DS3(��=" + m_fragilityCurve->GetBc(classID, 3) + ")");
				layer->addDataSet(dataY3, 0x002233, "DS4(��=" + m_fragilityCurve->GetBc(classID, 4) + ")");

				// Output the chart
				chartViewer->Chart = chart;

			}
			else {
				Alert::Error("No matching data!");
			}
			*/

		}



	private: System::Void Step4Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"����", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		// set datasource
		dgvFragCurveParams->DataSource = m_dataSet->FragParameterData;

		cboComponentCurves->DataSource = m_networkComponent->Data;
		cboComponentCurves->DisplayMember = m_networkComponent->GetColumnName(NetworkComponent::COL_NETWORK_COMP_ID);
		cboComponentCurves->ValueMember = m_networkComponent->GetColumnName(NetworkComponent::COL_CLASS_ID);


		//�ٱ���
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sLabelText = "Component curves";//�ü�����൵�
		if (sUiLang->Equals("ko-KR")) {
			sLabelText = "�ü�����൵�";
		}
		this->label1->Text = sLabelText;

	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		this->DrawFragilityCurves();
	}
	private: System::Void cboComponentCurves_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		this->DrawFragilityCurves();
	}

	private: System::Void dgvFragCurveParams_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		//�ٱ���
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		/*
		* 	// define fragility curve parameter grid columns.
			literal String^ GRID_FRAG_CURVE_PARAM_COL1 = L"Class ID";
			literal String^ GRID_FRAG_CURVE_PARAM_COL2 = L"DS1 IMm";
			literal String^ GRID_FRAG_CURVE_PARAM_COL3 = L"DS1 ��";
			literal String^ GRID_FRAG_CURVE_PARAM_COL4 = L"DS2 IMm";
			literal String^ GRID_FRAG_CURVE_PARAM_COL5 = L"DS2 ��";
			literal String^ GRID_FRAG_CURVE_PARAM_COL6 = L"DS3 IMm";
			literal String^ GRID_FRAG_CURVE_PARAM_COL7 = L"DS3 ��";
			literal String^ GRID_FRAG_CURVE_PARAM_COL8 = L"DS4 IMm";
			literal String^ GRID_FRAG_CURVE_PARAM_COL9 = L"DS4 ��";
		*/
		String^ sClassId = "Class ID";//�з���ȣ
		String^ sDS1_M = "DS1 IMm";//����1�ܰ� ���
		String^ sDS1_B = "DS1 ��";//����1�ܰ� �л�
		String^ sDS2_M = "DS2 IMm";//����2�ܰ� ���
		String^ sDS2_B = "DS2 ��";//����2�ܰ� �л�
		String^ sDS3_M = "DS3 IMm";//����3�ܰ� ���
		String^ sDS3_B = "DS3 ��";//����3�ܰ� �л�
		String^ sDS4_M = "DS4 IMm";//����4�ܰ� ���
		String^ sDS4_B = "DS4 ��";//����4�ܰ� �л�

		if (sUiLang->Equals("ko-KR")) {
			sClassId = "�з���ȣ";
			sDS1_M = "����1�ܰ� ���";
			sDS1_B = "����1�ܰ� �л�";
			sDS2_M = "����2�ܰ� ���";
			sDS2_B = "����2�ܰ� �л�";
			sDS3_M = "����3�ܰ� ���";
			sDS3_B = "����3�ܰ� �л�";
			sDS4_M = "����4�ܰ� ���";
			sDS4_B = "����4�ܰ� �л�";
		}
		this->dgvFragCurveParams->Columns[0]->HeaderText = sClassId;
		this->dgvFragCurveParams->Columns[1]->HeaderText = sDS1_M;
		this->dgvFragCurveParams->Columns[2]->HeaderText = sDS1_B;
		this->dgvFragCurveParams->Columns[3]->HeaderText = sDS2_M;
		this->dgvFragCurveParams->Columns[4]->HeaderText = sDS2_B;
		this->dgvFragCurveParams->Columns[5]->HeaderText = sDS3_M;
		this->dgvFragCurveParams->Columns[6]->HeaderText = sDS3_B;
		this->dgvFragCurveParams->Columns[7]->HeaderText = sDS4_M;
		this->dgvFragCurveParams->Columns[8]->HeaderText = sDS4_B;

	}


	};
}
