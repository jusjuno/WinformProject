#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "ExcelUtil.h"
#include "NetworkComponent.h"
#include <cmath>
#include "CustomMath.h"
#include <math.h>

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
	/// Step5Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step5Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step5Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		ShapeChart^					m_chart;
		array<double>^				m_dataX; // chart dataX
		array<double>^				m_dataY; // chart dataY
		array<double>^				m_dataZ; // chart dataZ
	private: System::Windows::Forms::DataGridView^  dgvSeismicSourceContent;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cboRecurrPeriods;
	private: System::Windows::Forms::ComboBox^  cboIntensityMeasure;
	public:
		Step5Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_chart = gcnew ShapeChart(dataSet->ShapeData);
		}


	public:
		DataTable^ NewTable(array<String^>^ columns) {
			DataTable^ table = gcnew DataTable();
			// define fields
			for each (String ^ col in columns)
			{
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}




	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step5Form()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: ChartDirector::WinChartViewer^  chartViewer;
	private: System::Windows::Forms::DataGridView^  dgvSeismicSources;
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
	private: System::Windows::Forms::Button^  btnAddSource;
	private: System::Windows::Forms::Button^  btnDelSource;


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
			this->dgvSeismicSources = (gcnew System::Windows::Forms::DataGridView());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->btnAddSource = (gcnew System::Windows::Forms::Button());
			this->btnDelSource = (gcnew System::Windows::Forms::Button());
			this->dgvSeismicSourceContent = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboRecurrPeriods = (gcnew System::Windows::Forms::ComboBox());
			this->cboIntensityMeasure = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSeismicSources))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSeismicSourceContent))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->tableLayoutPanel1->Controls->Add(this->dgvSeismicSources, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnAddSource, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnDelSource, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvSeismicSourceContent, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboRecurrPeriods, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboIntensityMeasure, 5, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 761);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvSeismicSources
			// 
			this->dgvSeismicSources->AllowUserToAddRows = false;
			this->dgvSeismicSources->AllowUserToDeleteRows = false;
			this->dgvSeismicSources->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvSeismicSources, 2);
			this->dgvSeismicSources->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvSeismicSources->Location = System::Drawing::Point(3, 3);
			this->dgvSeismicSources->Name = L"dgvSeismicSources";
			this->dgvSeismicSources->ReadOnly = true;
			this->dgvSeismicSources->RowTemplate->Height = 23;
			this->dgvSeismicSources->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvSeismicSources->Size = System::Drawing::Size(238, 213);
			this->dgvSeismicSources->TabIndex = 1;
			this->dgvSeismicSources->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Step5Form::dgvSeismicSources_CellClick);
			this->dgvSeismicSources->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step5Form::dgvSeismicSources_DataBindingComplete);
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 7);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(3, 251);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1078, 507);
			this->chartViewer->TabIndex = 0;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step5Form::chartViewer_SizeChanged);
			// 
			// btnAddSource
			// 
			this->btnAddSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAddSource->Location = System::Drawing::Point(3, 222);
			this->btnAddSource->Name = L"btnAddSource";
			this->btnAddSource->Size = System::Drawing::Size(116, 23);
			this->btnAddSource->TabIndex = 2;
			this->btnAddSource->Text = L"Add";
			this->btnAddSource->UseVisualStyleBackColor = true;
			this->btnAddSource->Click += gcnew System::EventHandler(this, &Step5Form::btnAddSource_Click);
			// 
			// btnDelSource
			// 
			this->btnDelSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnDelSource->Location = System::Drawing::Point(125, 222);
			this->btnDelSource->Name = L"btnDelSource";
			this->btnDelSource->Size = System::Drawing::Size(116, 23);
			this->btnDelSource->TabIndex = 3;
			this->btnDelSource->Text = L"Delete";
			this->btnDelSource->UseVisualStyleBackColor = true;
			this->btnDelSource->Click += gcnew System::EventHandler(this, &Step5Form::btnDelSource_Click);
			// 
			// dgvSeismicSourceContent
			// 
			this->dgvSeismicSourceContent->AllowUserToAddRows = false;
			this->dgvSeismicSourceContent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvSeismicSourceContent, 4);
			this->dgvSeismicSourceContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvSeismicSourceContent->Location = System::Drawing::Point(247, 3);
			this->dgvSeismicSourceContent->Name = L"dgvSeismicSourceContent";
			this->dgvSeismicSourceContent->RowTemplate->Height = 23;
			this->dgvSeismicSourceContent->Size = System::Drawing::Size(834, 213);
			this->dgvSeismicSourceContent->TabIndex = 4;
			this->dgvSeismicSourceContent->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step5Form::dgvSeismicSourceContent_DataBindingComplete);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(247, 219);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Recurrence periods";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(672, 219);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Intensity Measure";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cboRecurrPeriods
			// 
			this->cboRecurrPeriods->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboRecurrPeriods->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrPeriods->FormattingEnabled = true;
			this->cboRecurrPeriods->Location = System::Drawing::Point(387, 222);
			this->cboRecurrPeriods->Name = L"cboRecurrPeriods";
			this->cboRecurrPeriods->Size = System::Drawing::Size(279, 20);
			this->cboRecurrPeriods->TabIndex = 7;
			this->cboRecurrPeriods->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step5Form::cboRecurrPeriods_SelectionChangeCommitted);
			// 
			// cboIntensityMeasure
			// 
			this->cboIntensityMeasure->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboIntensityMeasure->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboIntensityMeasure->FormattingEnabled = true;
			this->cboIntensityMeasure->Location = System::Drawing::Point(801, 222);
			this->cboIntensityMeasure->Name = L"cboIntensityMeasure";
			this->cboIntensityMeasure->Size = System::Drawing::Size(280, 20);
			this->cboIntensityMeasure->TabIndex = 8;
			this->cboIntensityMeasure->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step5Form::cboIntensityMeasure_SelectionChangeCommitted);
			// 
			// Step5Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step5Form";
			this->Text = L"Step5Form";
			this->Load += gcnew System::EventHandler(this, &Step5Form::Step5Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSeismicSources))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSeismicSourceContent))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	private: System::Void DrawSeismicHazardChart() {
			DrawSeismicHazardChart(true);
		}
	private:
		System::Void DrawSeismicHazardChart(bool calculate) {
			if (calculate) {
				if (!CreateSeismicHazardChartData()) {
					Alert::Error("Can not create chart data.");
					return;
				}
			}
			int selectedIndex = dgvSeismicSources->CurrentCell->RowIndex;
			System::Data::DataRow^ row = this->m_dataSet->SeismicSourceData->Rows[selectedIndex];
			String^ scenarioName = row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL1]->ToString();

			int recurrencePeriodIndex = cboRecurrPeriods->SelectedIndex;
			String^ period = cboRecurrPeriods->Items[recurrencePeriodIndex]->ToString();
			String^ title = String::Format("Intensity Measure Distribution\nSeismic source: {0} - Scenario: {1}", scenarioName, period);
			//다국어
			String^ sUiLang = CultureInfo::CurrentUICulture->Name;
			if (sUiLang->Equals("ko-KR")) {
				title = String::Format(L"진도분포\n 진원지: {0} - Scenario: {1}", scenarioName, period);
			}
			m_chart->DrawSeismicDistribution(chartViewer, title, m_dataX, m_dataY, m_dataZ);
		}


		// create data for seismic harzard chart
		bool CreateSeismicHazardChartData() {
			if (dgvSeismicSources->CurrentCell != nullptr) {
				int selectedIndex = dgvSeismicSources->CurrentCell->RowIndex;
				System::Data::DataRow^ row = this->m_dataSet->SeismicSourceData->Rows[selectedIndex];
				try
				{
					String^ key = row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL1]->ToString();
					if (this->m_dataSet->SeismicSourceDictionary->ContainsKey(key)) {
						DataTable^ dt = this->m_dataSet->SeismicSourceDictionary[key];
						dgvSeismicSourceContent->DataSource = dt;

						// The (x, y, z) coordinates of the scattered data
						array<double>^ dataX = gcnew array<double>(dt->Rows->Count);
						array<double>^ dataY = gcnew array<double>(dt->Rows->Count);
						array<double>^ dataZ = gcnew array<double>(dt->Rows->Count);

						int i = 0;
						for each (System::Data::DataRow^ r in dt->Rows)
						{
							int recurrencePeriodIndex = cboRecurrPeriods->SelectedIndex;
							if (recurrencePeriodIndex < 0) {
								return false;
							}
							double::TryParse(String::Format("{0:F3}", r[CommConst::GRID_SEISMIC_SOURCES_COL1]->ToString()), dataX[i]);
							double::TryParse(String::Format("{0:F3}", r[CommConst::GRID_SEISMIC_SOURCES_COL2]->ToString()), dataY[i]);
							double::TryParse(String::Format("{0:F3}", r[recurrencePeriodIndex + 2]->ToString()), dataZ[i]);
							i++;
						}
						// SetChartData
						m_dataX = dataX;
						m_dataY = dataY;
						m_dataZ = dataZ;
						return true;
					}
				}
				catch (RowNotInTableException^ rnite)
				{
					return false;
				}
			}
			return false;
		}
		System::Void ClearChartData() {
			m_dataX = nullptr;
			m_dataY = nullptr;
			m_dataZ = nullptr;
		}
	private: System::Void Step5Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridViewCellStyle = gcnew DataGridViewCellStyle();
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		this->dgvSeismicSources->DataSource = this->m_dataSet->SeismicSourceData;
		ClearChartData();

		// set intensity measures datsoucre
		this->cboIntensityMeasure->Items->AddRange(this->m_dataSet->IntensityMeasureData);
		this->cboIntensityMeasure->SelectedIndex = 0;

		// set recurrence periods datasource
		this->cboRecurrPeriods->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboRecurrPeriods->SelectedIndex = 0;
	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawSeismicHazardChart();
	}
			 // add seismic source file
	private: System::Void btnAddSource_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ filename = CFileDlgUtil::GetExcelFile();
		if (!String::IsNullOrEmpty(filename))
		{
			try
			{
				// validation and create datatable 
				String^ _filename = Path::GetFileName(filename);
				_filename = _filename->Substring(0, _filename->LastIndexOf(L"."));
				if (this->m_dataSet->SeismicSourceData->Rows->Count > 0) {
					array<DataRow^>^ foundRows = this->m_dataSet->SeismicSourceData->Select(CommConst::GRID_SEISMIC_SOURCES_LIST_COL2 + "='" + filename + "'");
					if (foundRows->Length > 0) {
						Alert::Info("This file is exist.");
						return;
					}
				}


/*
				System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(filename
					, CommConst::GRID_SEISMIC_SOURCES_COL1, CommConst::GRID_SEISMIC_SOURCES_COL2, CommConst::GRID_SEISMIC_SOURCES_COL3
					, CommConst::GRID_SEISMIC_SOURCES_COL4, CommConst::GRID_SEISMIC_SOURCES_COL5, CommConst::GRID_SEISMIC_SOURCES_COL6
				);
				// 리스트 선택 시 데이터를 불러오기위해 dictionary에 filename을 key로 datatable을 추가
				this->m_dataSet->SeismicSourceDictionary->Add(_filename, dt);
*/
			
				System::Data::DataTable^ dt = ExcelUtil::ExcelToDataTable(filename
					, CommConst::GRID_SEISMIC_SOURCES_COL1, CommConst::GRID_SEISMIC_SOURCES_COL2, CommConst::GRID_SEISMIC_SOURCES_COL3
					, CommConst::GRID_SEISMIC_SOURCES_COL4, CommConst::GRID_SEISMIC_SOURCES_COL5, CommConst::GRID_SEISMIC_SOURCES_COL6
				);

///*
				array<String^>^ columns = { 
					CommConst::GRID_SEISMIC_SOURCES_COL1, CommConst::GRID_SEISMIC_SOURCES_COL2,
					CommConst::GRID_SEISMIC_SOURCES_COL3, CommConst::GRID_SEISMIC_SOURCES_COL4,
					CommConst::GRID_SEISMIC_SOURCES_COL5, CommConst::GRID_SEISMIC_SOURCES_COL6 };
				DataTable^ newTable = NewTable(columns);

				//


				//진앙지 정보에 있는 재현주기 개수
				// 재현주기개수는 xcoord, ycoord, 50년강도~ 로 구성되어 개수는 2를 뺌
				// 만약 재현주기개수가 4개가 아니면 경고메세지 발생 하는 코드 필요
				// 재현주기 년수 ex) 50, 100, 450, 1000
				int countPeriod = dt->Columns->Count - 2;
				array<double>^ returnYear = gcnew array<double>(countPeriod);
				returnYear[0] = double::Parse(CommConst::GRID_SEISMIC_SOURCES_COL3); //50년
				returnYear[1] = double::Parse(CommConst::GRID_SEISMIC_SOURCES_COL4); //100년
				returnYear[2] = double::Parse(CommConst::GRID_SEISMIC_SOURCES_COL5); //475년
				returnYear[3] = double::Parse(CommConst::GRID_SEISMIC_SOURCES_COL6); //1000년


				// 진앙지 내 세그먼트 개수
				int sourceCount = dt->Rows->Count;


				// create new row
				//시설물위치에서의 지진강도 저장: xcoord, ycoord,50년강도, 100년강도, 475년강도, 1000년강도
				DataRow^ newRow = nullptr; 

				//진앙지 정보 임시저장: xcoord, ycoord,50년강도, 100년강도, 475년강도, 1000년강도
				DataRow^ newSourceRow = nullptr;

				// 진앙의 크기(M) 및 진앙지에서 도로시설물까지의 위치(R)을 계산하고,
				// 이를 이용하여, 재현주기별 도로시설물 위치에서의 지진강도를 구한다
				for (int compIndex = 0; compIndex < m_dataSet->NetworkCompnentData->Rows->Count; compIndex++) {

					newRow = newTable->NewRow();

					for (int periodIndex = 0; periodIndex < countPeriod; periodIndex++) {

						//int colIndex = 0;
						System::Data::DataRow^ r = m_dataSet->NetworkCompnentData->Rows[compIndex];
						//String^ classID = r[NetworkComponent::COL_CLASS_ID]->ToString;
						String^ classID = String::Format("{0}", r[NetworkComponent::COL_CLASS_ID]);
						String^ xPos = String::Format("{0}", r[NetworkComponent::COL_X]);
						String^ yPos = String::Format("{0}", r[NetworkComponent::COL_Y]);
						newRow[0] = xPos;
						newRow[1] = yPos;

						double sa = 0; // 재현주기별 시설물위치에서의 지진동강도
						for (int sourceIndex = 0; sourceIndex < sourceCount; sourceIndex++) {
							newSourceRow = dt->Rows[sourceIndex];
							//진앙지 임시정보가 들어있는 변수의 칼럼 임시번호 지정
							int localColIndex = 0;

							//진앙지 좌표
							double xcoord = double::Parse(newSourceRow[0]->ToString());
							double ycoord = double::Parse(newSourceRow[1]->ToString());

							//시설물 좌표
							double xPosFacility = double::Parse(xPos);
							double yPosFacility = double::Parse(yPos);

							//거리
							double earthRadius = 6371.0;
							double d2r = 0.0174533; // degree to radian 0.0174533 = 3.1415/180
							double coeffA = pow(sin((yPosFacility - ycoord) * d2r / 2), 2) + cos(ycoord * d2r) * cos(yPosFacility * d2r) * pow(sin((xPosFacility - xcoord) * d2r / 2), 2);
							double coeffC = 2 * asin(sqrt(coeffA));
							double distance = earthRadius * coeffC;

							// 아래의 2가 뜻하는 바는 [0]:x좌표 [1]:y좌표 [3]~[n] 지진강도 M  
							double magnitude = double::Parse(newSourceRow[2 + periodIndex]->ToString());
							double lnPGA = -0.152 + 0.859 * (magnitude)-1.803 * log(distance + 25);
							sa += exp(lnPGA); // 평균값사용

						}
						sa = sa / sourceCount; // 등분단층(sourceCount)이 동일하게 기여하는 것으로 가정
						newRow[2 + periodIndex] = sa;
					}

					newTable->Rows->Add(newRow);

				}


				// 리스트 선택 시 데이터를 불러오기위해 dictionary에 filename을 key로 datatable을 추가
				//this->m_dataSet->SeismicSourceDictionary->Add(_filename, dt);
				this->m_dataSet->SeismicSourceDictionary->Add(_filename, newTable);



				////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// 리스트 선택 시 데이터를 불러오기위해 dictionary에 filename을 key로 datatable을 추가 - 엑셀로 추가한 진앙지 정보 2021.04.10 khd 추가
				if (this->m_dataSet->SeismicSourceContentDictionary != nullptr) {
					this->m_dataSet->SeismicSourceContentDictionary->Add(_filename, dt);
				}
				else {
					Alert::Info("이전 prd 파일입니다. 처음부터 다시 시작해야 합니다!");
					return;
				}
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				DataRow^ row = this->m_dataSet->SeismicSourceData->NewRow(); // create new row
				row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL1] = _filename;
				row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL2] = filename;
				this->m_dataSet->SeismicSourceData->Rows->Add(row);
				OnSaveDataChanged();
			}
			catch (Exception^ ex)
			{
				Alert::Error("Can not open file.");
			}
		}
	}
			 // delete seismic source file
	private: System::Void btnDelSource_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dgvSeismicSources->CurrentCell != nullptr) {
			int selectedIndex = dgvSeismicSources->CurrentCell->RowIndex;
			dgvSeismicSources->ClearSelection();
			System::Data::DataRow^ row = this->m_dataSet->SeismicSourceData->Rows[selectedIndex];
			String^ key = row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL1]->ToString();
			this->dgvSeismicSourceContent->DataSource = nullptr;
			this->m_dataSet->SeismicSourceDictionary->Remove(key);
			DataRow^ removedRow = this->m_dataSet->SeismicSourceData->Rows[selectedIndex];
			removedRow->Delete();
			ClearChartData();
			this->cboIntensityMeasure->SelectedIndex = 0;
			this->cboRecurrPeriods->SelectedIndex = 0;
			chartViewer->Image = nullptr;
			OnSaveDataChanged();
		}
	}
			 // Set grid row number and style
	private: System::Void dgvSeismicSources_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		int i = 1;
		for each(DataGridViewRow^ row in dgvSeismicSources->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvSeismicSources->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvSeismicSources->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSeismicSources->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSeismicSources->EnableHeadersVisualStyles = false;
	}
			 // Set grid row number and style
	private: System::Void dgvSeismicSourceContent_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		int i = 1;
		for each(DataGridViewRow^ row in dgvSeismicSourceContent->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvSeismicSourceContent->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvSeismicSourceContent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSeismicSourceContent->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSeismicSourceContent->EnableHeadersVisualStyles = false;
	}
	private: System::Void dgvSeismicSources_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		DrawSeismicHazardChart();
	}
	private: System::Void cboIntensityMeasure_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawSeismicHazardChart();
	}
	private: System::Void cboRecurrPeriods_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawSeismicHazardChart();
	}
	};
}
