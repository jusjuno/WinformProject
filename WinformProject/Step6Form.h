#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "MonteCarioModule.h"
#include "FragilityCurve.h"
#include "NetworkComponent.h"
#include "SoilAmp.h"
#include "CSVFileManager.h"

namespace WinformProject {
	using namespace ChartDirector;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step6Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
	/// </summary>
	//public ref class Step6Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step6Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		ShapeChart^					m_chart;
		array<double>^				m_chartDataX;
		array<double>^				m_chartDataY;
		array<double>^				m_chartDataZ;
		FragilityCurve^				m_fragilityCurve;
		NetworkComponent^			m_networkComponent;

		SoilAmp^					m_soilAmp;

	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::ComboBox^  cboRecurrencePeriod;
	private: System::Windows::Forms::ComboBox^  cboDamageState;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnGenerateMonteCario;
	private: System::Windows::Forms::TextBox^  tbMonteCarioCount;

	private: ChartDirector::WinChartViewer^  chartViewer;
	public:
		Step6Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			this->m_chart = gcnew ShapeChart(dataSet->ShapeData);
			this->m_fragilityCurve = gcnew FragilityCurve(this->m_dataSet->FragParameterData);
			this->m_networkComponent = gcnew NetworkComponent(dataSet);

			// soil amplification ��� �Լ�			
			this->m_soilAmp = gcnew SoilAmp(this->m_dataSet->SoilAmpData);
		}

	public:
		// create new datatable object by columns information
		// write output_damage_state.csv file
		String^ m_basePath = "C:\\sample\\NEXTA\\";
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
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Step6Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

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
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboRecurrencePeriod = (gcnew System::Windows::Forms::ComboBox());
			this->cboDamageState = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbMonteCarioCount = (gcnew System::Windows::Forms::TextBox());
			this->btnGenerateMonteCario = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 6);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(3, 29);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1078, 700);
			this->chartViewer->TabIndex = 0;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step6Form::chartViewer_SizeChanged);
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(117, 3);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(239, 20);
			this->cboSeismicSource->TabIndex = 1;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step6Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// cboRecurrencePeriod
			// 
			this->cboRecurrencePeriod->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboRecurrencePeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrencePeriod->FormattingEnabled = true;
			this->cboRecurrencePeriod->Location = System::Drawing::Point(494, 3);
			this->cboRecurrencePeriod->Name = L"cboRecurrencePeriod";
			this->cboRecurrencePeriod->Size = System::Drawing::Size(239, 20);
			this->cboRecurrencePeriod->TabIndex = 2;
			this->cboRecurrencePeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step6Form::cboRecurrencePeriod_SelectionChangeCommitted);
			// 
			// cboDamageState
			// 
			this->cboDamageState->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboDamageState->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDamageState->FormattingEnabled = true;
			this->cboDamageState->Location = System::Drawing::Point(840, 3);
			this->cboDamageState->Name = L"cboDamageState";
			this->cboDamageState->Size = System::Drawing::Size(241, 20);
			this->cboDamageState->TabIndex = 3;
			this->cboDamageState->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step6Form::cboDamageState_SelectionChangeCommitted);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Seismic source";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(362, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 26);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Recurrence period";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(739, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 26);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Damage state";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboDamageState, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboRecurrencePeriod, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tbMonteCarioCount, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnGenerateMonteCario, 4, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 761);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label4, 3);
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(3, 732);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(485, 29);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Total number of Monte Cario";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbMonteCarioCount
			// 
			this->tbMonteCarioCount->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbMonteCarioCount->Location = System::Drawing::Point(494, 735);
			this->tbMonteCarioCount->Name = L"tbMonteCarioCount";
			this->tbMonteCarioCount->Size = System::Drawing::Size(239, 21);
			this->tbMonteCarioCount->TabIndex = 7;
			this->tbMonteCarioCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbMonteCarioCount->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step6Form::tbMonteCarioCount_KeyPress);
			// 
			// btnGenerateMonteCario
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->btnGenerateMonteCario, 2);
			this->btnGenerateMonteCario->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnGenerateMonteCario->Location = System::Drawing::Point(739, 735);
			this->btnGenerateMonteCario->Name = L"btnGenerateMonteCario";
			this->btnGenerateMonteCario->Size = System::Drawing::Size(342, 23);
			this->btnGenerateMonteCario->TabIndex = 6;
			this->btnGenerateMonteCario->Text = L"Generate Monte Cario Simulations";
			this->btnGenerateMonteCario->UseVisualStyleBackColor = true;
			this->btnGenerateMonteCario->Click += gcnew System::EventHandler(this, &Step6Form::btnGenerateMonteCario_Click);
			// 
			// Step6Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step6Form";
			this->Text = L"Step6Form";
			this->Load += gcnew System::EventHandler(this, &Step6Form::Step6Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			// seismic source �Է� ���� Ȯ��
			if (this->m_dataSet->SeismicSourceData->Rows->Count < 1) {
				Alert::Error("Seismic source is empty.\nYou have to enter a seismic source in Seismic hazard Form.");
				return false;
			}
			return true;
		}
	private:
		Void DrawVulnerabilityMap() {
			DrawVulnerabilityMap(true);
		}
		Void DrawVulnerabilityMap(bool caculate) {
			if (!CreateVulnerabilityMapChartData()) {
				Alert::Error("Can not create chart data.");
				return;				
			}

//			if (!WriteFileDamageState()) {
//				Alert::Error("Can not create damage state file.");
//				return;
//			}

			System::Data::DataRow^ row = this->m_dataSet->SeismicSourceData->Rows[cboSeismicSource->SelectedIndex];
			String^ scenarioName = row[CommConst::GRID_SEISMIC_SOURCES_LIST_COL1]->ToString();
			String^ period = cboRecurrencePeriod->Items[cboRecurrencePeriod->SelectedIndex]->ToString();
			String^ state = cboDamageState->Items[cboDamageState->SelectedIndex]->ToString();
			String^ title = String::Format("Vulnerability Map\nDamage State: {0} - Seismic source: {1} - Scenario: {2}", state, scenarioName, period);

			m_chart->DrawVulnerabilityMap(chartViewer, title, m_chartDataX, m_chartDataY, m_chartDataZ);
		}
		// create vulnerability chart data
		bool CreateVulnerabilityMapChartData() {
			try
			{
				// set array size
				int componentCount = m_networkComponent->GetCount();
				m_chartDataX = gcnew array<double>(componentCount);
				m_chartDataY = gcnew array<double>(componentCount);
				m_chartDataZ = gcnew array<double>(componentCount);

				try
				{
					String^ key = cboSeismicSource->SelectedValue->ToString();
					if (this->m_dataSet->SeismicSourceDictionary->ContainsKey(key)) {
						// source data
						DataTable^ seismicData = this->m_dataSet->SeismicSourceDictionary[key];

						double sa = 0.0;
						double temp1 = 0.0;
						double temp2 = 0.0;

						int soilType;
						double naturalPeriod;
						
						for (int i = 0; i < componentCount; i++)
						{
							// component info
							System::Data::DataRow^ r = m_dataSet->NetworkCompnentData->Rows[i];
							String^ classID = m_networkComponent->GetValue(i, NetworkComponent::COL_CLASS_ID);
							String^ xPos = m_networkComponent->GetValue(i, NetworkComponent::COL_X);
							String^ yPos = m_networkComponent->GetValue(i, NetworkComponent::COL_Y);

							// seismic info
							String^ filter = "[" + CommConst::GRID_SEISMIC_SOURCES_COL1 + "]='" + xPos + "' and [" + CommConst::GRID_SEISMIC_SOURCES_COL2 + "] = '" + yPos + "'";
							array<DataRow^>^ foundRows = seismicData->Select(filter);
							if (foundRows->Length < 1) {
								continue;
							}
							
							// soil amplification factor ���
							// soil type�� A~E�� �ԷµǸ�, ������� ����� ���� �ڿ��� 1~5�� ��ȯ��
							soilType = (int)(m_networkComponent->GetValue(i, NetworkComponent::COL_SOIL_TYPE))[0] - 64;
							naturalPeriod = double::Parse(m_networkComponent->GetValue(i, NetworkComponent::COL_FUNDAMENTAL_PERIOD));
							double soilAmpFactor = m_soilAmp->CalcSoilAmpFactor(soilType, naturalPeriod);

							//sa = Double::Parse(foundRows[0][cboRecurrencePeriod->SelectedIndex + 2]->ToString());
							sa = (Double::Parse(foundRows[0][cboRecurrencePeriod->SelectedIndex + 2]->ToString())) * soilAmpFactor;

							double tempX = 1.0;
							double tempStandardDev = 0.57;
							double tempMean= -0.5767;
							double tempValue = CustomMath::LOGNORMSDIST(tempX, tempMean, tempStandardDev);

													   							 						  						  
							m_chartDataX[i] = Double::Parse(xPos); // X
							m_chartDataY[i] = Double::Parse(yPos); // Y
							// find fragility curve parameter
//							m_chartDataZ[i] = m_fragilityCurve->GetFragilityValue(classID, cboDamageState->SelectedIndex, sa) * 100; // %
							if (cboDamageState->SelectedIndex == 0) {
								m_chartDataZ[i] = (1 - m_fragilityCurve->GetFragilityValue(classID, cboDamageState->SelectedIndex + 1, sa)) * 100;
							}
							else if (cboDamageState->SelectedIndex < CommConst::DAMAGE_STATE_COUNT) {
								temp1 = m_fragilityCurve->GetFragilityValue(classID, cboDamageState->SelectedIndex, sa) * 100;
								temp2 = m_fragilityCurve->GetFragilityValue(classID, cboDamageState->SelectedIndex + 1, sa) * 100;
								m_chartDataZ[i] = temp1 - temp2;
							}
							else {
								m_chartDataZ[i] = m_fragilityCurve->GetFragilityValue(classID, cboDamageState->SelectedIndex, sa) * 100; // %
							}

						}
						return true;
					}
				}
				catch (RowNotInTableException^ rnite)
				{
					return false;
				}
			}
			catch (Exception^ ex)
			{
				return false;
			}
	   			 		  		  		 	   			   	  
			return true;
		}			   		 	  	  	 



		bool WriteFileDamageState() {
			array<String^>^ columns = { "component", "build cost", 
				"NO(1)", "I(1)", "II(1)", "III(1)", "IV(1)" , 
				"NO(2)", "I(2)", "II(2)", "III(2)", "IV(2)" ,
				"NO(3)", "I(3)", "II(3)", "III(3)", "IV(3)" ,
				"NO(4)", "I(4)", "II(4)", "III(4)", "IV(4)" };

			CSVFileManager^ csv = gcnew CSVFileManager(this->m_basePath + "output_damage_state.csv");
		
			// seismic source data
			String^ key = cboSeismicSource->SelectedValue->ToString();
			DataTable^ seismicData = this->m_dataSet->SeismicSourceDictionary[key];
			//sa = Double::Parse(foundRows[0][cboRecurrencePeriod->SelectedIndex + 2]->ToString());

			// set data			
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;

			//for each (KeyValuePair<String^, ShapeNode^>^ pair in m_dataSet->ShapeData->m_SHPNodes)
			for(int compIndex=0; compIndex < m_dataSet->NetworkCompnentData->Rows->Count; compIndex++)
				{
					int tmpIndex = 0;

					// create new row
					newRow = newTable->NewRow(); 
			
					// component info
					System::Data::DataRow^ r = m_dataSet->NetworkCompnentData->Rows[compIndex];
					String^ classID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_CLASS_ID);
					String^ xPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_X);
					String^ yPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_Y);

					// seismic info
					String^ filter = "[" + CommConst::GRID_SEISMIC_SOURCES_COL1 + "]='" + xPos + "' and [" + CommConst::GRID_SEISMIC_SOURCES_COL2 + "] = '" + yPos + "'";
					array<DataRow^>^ foundRows = seismicData->Select(filter);

					// [�Է�] �ü��� ��:
					String^ charCompIndex = String::Format("{0}", compIndex);
					newRow[columns[tmpIndex++]] = charCompIndex;
					
					// [�Է�] �ü��� �Ǽ����:
					newRow[columns[tmpIndex++]] = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_RECONSTRUCTION_COST);

					for(int returnIndex = 0; returnIndex < m_dataSet->RecurrencePeriodData->Length; returnIndex++) {
						double sa = Double::Parse(foundRows[0][returnIndex + 2]->ToString());

						for (int dsIndex = 0; dsIndex <= CommConst::DAMAGE_STATE_COUNT; dsIndex++){
														
							double dsState;
							double temp1;
							double temp2;
						
							if (dsIndex == 0) {
								dsState = (1 - m_fragilityCurve->GetFragilityValue(classID, dsIndex+1, sa)) * 100;
							}
							else if (dsIndex < CommConst::DAMAGE_STATE_COUNT) {
								temp1 = m_fragilityCurve->GetFragilityValue(classID, dsIndex, sa) * 100;
								temp2 = m_fragilityCurve->GetFragilityValue(classID, dsIndex + 1, sa) * 100;
								dsState = temp1 - temp2;
							}
							else {
								dsState = m_fragilityCurve->GetFragilityValue(classID, dsIndex, sa) * 100; // %
							}

							// [�Է�] �� �����ֱ⺰ damage state �Է�
							newRow[columns[tmpIndex++]] = String::Format("{0}",dsState);
						}
					}
				
				newTable->Rows->Add(newRow);
			}
			return csv->Write(columns, newTable);
		}

	private: System::Void Step6Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		this->cboRecurrencePeriod->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboRecurrencePeriod->SelectedIndex = 0;

		this->cboDamageState->Items->AddRange(this->m_dataSet->DamageStateData);
		this->cboDamageState->SelectedIndex = 1;

		if (this->m_dataSet->MonteCarioCount == 0) {
			tbMonteCarioCount->Text = "1";
		}
		else {
			tbMonteCarioCount->Text = this->m_dataSet->MonteCarioCount + "";
		}

		DrawVulnerabilityMap();
	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawVulnerabilityMap();
	}
	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawVulnerabilityMap();
	}
	private: System::Void cboRecurrencePeriod_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawVulnerabilityMap();
	}
	private: System::Void cboDamageState_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		DrawVulnerabilityMap();
	}
	private: System::Void btnGenerateMonteCario_Click(System::Object^  sender, System::EventArgs^  e) {
		if (String::IsNullOrEmpty(tbMonteCarioCount->Text)) {
			Alert::Info("Total number of monte cario is empty.");
			return;
		}
		if (tbMonteCarioCount->Text == "0") {
			Alert::Info("Can not use zero value.");
			return;
		}

		try
		{
			this->m_dataSet->MonteCarioCount = Convert::ToInt32(tbMonteCarioCount->Text);
			// generate mote cario
			this->m_dataSet->IsGeneratedMonteCario = MonteCarioModule::Generate();
			OnSaveDataChanged();
			Alert::Info("Success");
		}
		catch (Exception^ ex)
		{
			this->m_dataSet->IsGeneratedMonteCario = false;
			OnSaveDataChanged();
			Alert::Error("Failed");
		}
	}
	private: System::Void tbMonteCarioCount_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	};
}