#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "TrafficModule.h"
#include "Zone.h"
#include "NeXTAHelper.h"
#include <algorithm> 


namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step11Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step10bForm : public System::Windows::Forms::Form, IFormValidator
	public ref class Step10bForm : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		TrafficModule^				m_trafficModule;
		bool						m_isCalculated; // 계산 완료 여부
		array<double>^				m_dataX; // chart x-axis data

//		array<Zone>^				m_zoneGroupData;


		bool						IsGeneratedZoneProperties;
//		DataTable^					m_zoneGroupProperties;






	public:
		Step10bForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
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
		~Step10bForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: ChartDirector::WinChartViewer^  chartViewer;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cboRecurrencePeriod;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cboSample;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::DataGridView^  dgvEnvironment;
	private: System::Windows::Forms::Button^  btnCalculate;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbEnvironmentCount;
	private: System::Windows::Forms::DataGridView^  dgvConnectivity;
	private: System::Windows::Forms::DataGridView^  dgvConnectivityZone;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbConnectivityCount;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvConnectivity = (gcnew System::Windows::Forms::DataGridView());
			this->dgvConnectivityZone = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbConnectivityCount = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvEnvironment = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbEnvironmentCount = (gcnew System::Windows::Forms::TextBox());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboRecurrencePeriod = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvConnectivity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvConnectivityZone))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEnvironment))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Gulim", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->groupBox1->Location = System::Drawing::Point(17, 18);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(553, 376);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"POI Connectivity";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				311)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->dgvConnectivity, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvConnectivityZone, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tbConnectivityCount, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(4, 27);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(545, 345);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dgvConnectivity
			// 
			this->dgvConnectivity->AllowUserToAddRows = false;
			this->dgvConnectivity->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvConnectivity, 2);
			this->dgvConnectivity->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvConnectivity->Location = System::Drawing::Point(4, 42);
			this->dgvConnectivity->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgvConnectivity->Name = L"dgvConnectivity";
			this->dgvConnectivity->RowHeadersWidth = 62;
			this->dgvConnectivity->RowTemplate->Height = 23;
			this->dgvConnectivity->Size = System::Drawing::Size(537, 145);
			this->dgvConnectivity->TabIndex = 0;
			this->dgvConnectivity->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step10bForm::dgvConnectivity_DataBindingComplete);
			// 
			// dgvConnectivityZone
			// 
			this->dgvConnectivityZone->AllowUserToAddRows = false;
			this->dgvConnectivityZone->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvConnectivityZone, 2);
			this->dgvConnectivityZone->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvConnectivityZone->Location = System::Drawing::Point(4, 195);
			this->dgvConnectivityZone->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgvConnectivityZone->Name = L"dgvConnectivityZone";
			this->dgvConnectivityZone->RowHeadersWidth = 62;
			this->dgvConnectivityZone->RowTemplate->Height = 23;
			this->dgvConnectivityZone->Size = System::Drawing::Size(537, 146);
			this->dgvConnectivityZone->TabIndex = 1;
			this->dgvConnectivityZone->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step10bForm::dgvConnectivityZone_DataBindingComplete);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Location = System::Drawing::Point(4, 0);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(303, 38);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Total Zone Count";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbConnectivityCount
			// 
			this->tbConnectivityCount->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbConnectivityCount->Location = System::Drawing::Point(315, 4);
			this->tbConnectivityCount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbConnectivityCount->Name = L"tbConnectivityCount";
			this->tbConnectivityCount->Size = System::Drawing::Size(226, 30);
			this->tbConnectivityCount->TabIndex = 3;
			this->tbConnectivityCount->Text = L"0";
			this->tbConnectivityCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbConnectivityCount->TextChanged += gcnew System::EventHandler(this, &Step10bForm::tbConnectivityCount_TextChanged);
			this->tbConnectivityCount->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10bForm::tbConnectivityCount_KeyPress);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Gulim", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->groupBox2->Location = System::Drawing::Point(574, 18);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(553, 376);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Environment";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->dgvEnvironment, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tbEnvironmentCount, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(4, 27);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(545, 345);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// dgvEnvironment
			// 
			this->dgvEnvironment->AllowUserToAddRows = false;
			this->dgvEnvironment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel2->SetColumnSpan(this->dgvEnvironment, 2);
			this->dgvEnvironment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvEnvironment->Location = System::Drawing::Point(4, 42);
			this->dgvEnvironment->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgvEnvironment->Name = L"dgvEnvironment";
			this->dgvEnvironment->RowHeadersWidth = 62;
			this->dgvEnvironment->RowTemplate->Height = 23;
			this->dgvEnvironment->Size = System::Drawing::Size(537, 299);
			this->dgvEnvironment->TabIndex = 0;
			this->dgvEnvironment->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step10bForm::dgvEnvironment_DataBindingComplete);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Location = System::Drawing::Point(4, 0);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(291, 38);
			this->label4->TabIndex = 1;
			this->label4->Text = L"# of environmentally sensitive";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbEnvironmentCount
			// 
			this->tbEnvironmentCount->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbEnvironmentCount->Location = System::Drawing::Point(303, 4);
			this->tbEnvironmentCount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbEnvironmentCount->Name = L"tbEnvironmentCount";
			this->tbEnvironmentCount->Size = System::Drawing::Size(238, 30);
			this->tbEnvironmentCount->TabIndex = 2;
			this->tbEnvironmentCount->Text = L"0";
			this->tbEnvironmentCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbEnvironmentCount->TextChanged += gcnew System::EventHandler(this, &Step10bForm::tbEnvironmentCount_TextChanged);
			this->tbEnvironmentCount->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10bForm::tbEnvironmentCount_KeyPress);
			// 
			// chartViewer
			// 
			this->chartViewer->Location = System::Drawing::Point(17, 404);
			this->chartViewer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(864, 720);
			this->chartViewer->TabIndex = 2;
			this->chartViewer->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gulim", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(963, 466);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Seismic source";
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(1183, 464);
			this->cboSeismicSource->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(253, 26);
			this->cboSeismicSource->TabIndex = 4;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step10bForm::cboSeismicSource_SelectionChangeCommitted);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gulim", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(963, 507);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Recurrence period";
			// 
			// cboRecurrencePeriod
			// 
			this->cboRecurrencePeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrencePeriod->FormattingEnabled = true;
			this->cboRecurrencePeriod->Location = System::Drawing::Point(1183, 504);
			this->cboRecurrencePeriod->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboRecurrencePeriod->Name = L"cboRecurrencePeriod";
			this->cboRecurrencePeriod->Size = System::Drawing::Size(253, 26);
			this->cboRecurrencePeriod->TabIndex = 4;
			this->cboRecurrencePeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step10bForm::cboRecurrencePeriod_SelectionChangeCommitted);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gulim", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(963, 548);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Sample";
			// 
			// cboSample
			// 
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(1183, 544);
			this->cboSample->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(253, 26);
			this->cboSample->TabIndex = 4;
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step10bForm::cboSample_SelectionChangeCommitted);
			// 
			// btnCalculate
			// 
			this->btnCalculate->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btnCalculate->Location = System::Drawing::Point(1161, 165);
			this->btnCalculate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(276, 164);
			this->btnCalculate->TabIndex = 5;
			this->btnCalculate->Text = L"Calculate";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &Step10bForm::btnCalculate_Click);
			// 
			// Step10bForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1549, 1050);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->cboSample);
			this->Controls->Add(this->cboRecurrencePeriod);
			this->Controls->Add(this->cboSeismicSource);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chartViewer);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Step10bForm";
			this->Text = L"S";
			this->Load += gcnew System::EventHandler(this, &Step10bForm::Step10bForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvConnectivity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvConnectivityZone))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEnvironment))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	private:
		// draw chart
		void DrawChart(array<double>^ dataX, array<double>^ dataECOY, array<double>^ dataCONY, array<double>^ dataENVY) 
		{
			if (!this->m_isCalculated) {
				Alert::Info("차트 데이터가 없습니다.\n먼저 데이터를 생성 후 진행해주세요.");
				return;
			}

			// chart 수정: 기존코드에서는 차트에 damage state1에서는 데미지가 있는 것으로 되어있지만
			// 데미지는 damage state2 부터 있어, 그래프가 우측으로 damage state2 일수 (7일) 만클 밀려 표현됨.
			// 코드 수정은 localDataX 및 localDataY를 이용하여 그래프를 x축상에서 좌측으로 7일 만큼 밀어 표현하게 함
			array<double>^ localDataX = gcnew array<double>(dataX->Length + 2);
			array<double>^ localECOY = gcnew array<double>(dataECOY->Length + 2);
			array<double>^ localCONY = gcnew array<double>(dataCONY->Length + 2);
			array<double>^ localENVY = gcnew array<double>(dataENVY->Length + 2);
			for (int i = 0; i <= dataX->Length; i++)
			{
				if ((i == 0) || (i == dataX->Length))
				{
					if (i == 0) { 
						localDataX[i] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1; //damage state 1= "0"일 하지만, 경우에 따라선 1~7일이 될 수 있음.
						localECOY[i] = dataECOY[i];
						localCONY[i] = dataCONY[i];
						localENVY[i] = dataENVY[i];
					}
					else if (i == dataX->Length) { 
						localDataX[i] = dataX[i - 1]; 
						localECOY[i] = 1;
						localCONY[i] = 1;
						localENVY[i] = 1;
					}
				}
				else {
					localDataX[i] = dataX[i - 1];
					localECOY[i] = dataECOY[i];
					localCONY[i] = dataCONY[i];
					localENVY[i] = dataENVY[i];
				}
			}

			// 회복 최종단계(ex 450일 이후는 모든 지수가 1이되며, 표현은 마지막 일수보다 50일 크게 표현  
			localDataX[dataX->Length + 1] = dataX[dataX->Length-1] + 50;
			localECOY[dataX->Length + 1] = 1;
			localCONY[dataX->Length + 1] = 1;
			localENVY[dataX->Length + 1] = 1;


			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ sample = cboSample->SelectedItem->ToString();
			String^ period = cboRecurrencePeriod->SelectedItem->ToString();
			String^ title = String::Format("Seismic source: {0} - Scenario: {1} years", scenarioName, period);

			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			int plotAreaWidth = chartViewer->Size.Width - 180;
			int plotAreaHeight = chartViewer->Size.Height - 150;
			c->setPlotArea(80, 80, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			c->addLegend(80 + plotAreaWidth + 30, 80, true);
			c->addTitle(title, "Times New Roman Bold", 17);
			c->xAxis()->setTitle("Time (days)", "Arial Bold", 12);
			c->xAxis()->setLinearScale(localDataX[0], localDataX[localDataX->Length - 1]);
			c->yAxis()->setTitle("Loss factor", "Arial Bold", 12);
			c->yAxis()->setLinearScale(-0.2, 1.2);
			StepLineLayer^ layerECO = c->addStepLineLayer(localECOY, 0x0000FF, "ECO");
			layerECO->setXData(localDataX);
			layerECO->setLineWidth(2);
			StepLineLayer^ layerCON = c->addStepLineLayer(localCONY, 0xFF0000, "CON");
			layerCON->setXData(localDataX);
			layerCON->setLineWidth(2);
			StepLineLayer^ layerENV = c->addStepLineLayer(localENVY, 0xFFC90E, "ENV");
			layerENV->setXData(localDataX);
			layerENV->setLineWidth(2);


			// Output the chart
			chartViewer->Chart = c;
			chartViewer->ImageMap = c->getHTMLImageMap("clickable", "", "title='[{dataSetName}]: {x}/{value}'");
		}


		void UpdateChart() {
			if (!this->m_isCalculated) {
				return;
			}

			int trafficSecnarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);

			//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
			int totalOD = this->m_dataSet->ODZoneParamData->Rows->Count;

			// 통합지수값이 저장된 index 번호
			int indicesIndex = (unitScenarioStep * totalOD) + trafficSecnarioNo;
								// 개별지수값 번호              // 통합지숙값 번호 

			DrawChart(this->m_dataX
				, this->m_dataSet->ResultData->GetEconomicLossIndices(indicesIndex)
				, this->m_dataSet->ResultData->GetConnectivityLossIndices(indicesIndex)
				, this->m_dataSet->ResultData->GetEnvironmentLossIndices(indicesIndex));
		}

		bool CalculateChartData() {
			try {

				Dictionary<String^, DataTable^>^ IndiceDictionaryECO = gcnew Dictionary<String^, DataTable^>();
				Dictionary<String^, DataTable^>^ IndiceDictionaryCON = gcnew Dictionary<String^, DataTable^>();
				Dictionary<String^, DataTable^>^ IndiceDictionaryENV = gcnew Dictionary<String^, DataTable^>();


				this->m_dataX = gcnew array<double>(4);
				this->m_dataX = gcnew array<double>(4);
				if (!m_dataSet->IsSameAllTrafficCarryingParam) {
					// 현재는 같은 것만 처리 가능 
					Alert::Info("Traffic carrying parameters are each different.\nIt can support only same parameters.");
					return false;
				}
				else {
					this->m_dataX[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
					this->m_dataX[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
					this->m_dataX[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
					this->m_dataX[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
				}

				double trafficVolume = 0.0;
				double trafficTime = 0.0;

				CreateZoneGroupData();
				// 위에서 생성된 Zone Group별 특성(길이, POI개수)생성 
				IsGeneratedZoneProperties = false;

				// 각 시나리오 별 chart 데이터를 생성
				for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++){


					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
					// 해당 시나리오에서 각 link 중 어느 damage state까지 link가 closed 되어있는지 확인(중복제거)
					Dictionary<String^, int>^ linkIDAndDamageStateDic = gcnew Dictionary<String^, int>();
					for each (ComponentInfo component in scenario->Components)
					{
						if (!linkIDAndDamageStateDic->ContainsKey(component.LinkID)) {
							linkIDAndDamageStateDic->Add(component.LinkID, component.MaxDamageState);
						}
						else {
							int value = linkIDAndDamageStateDic->ContainsKey(component.LinkID);
							if (component.MaxDamageState > value) {
								linkIDAndDamageStateDic->Remove(component.LinkID);
								linkIDAndDamageStateDic->Add(component.LinkID, component.MaxDamageState);
							}
						}
					}

					// Connectivity 관련 파라미터
					array<ShapeProperty^>^ connParameter;
					// Envoronmental 관련 파라미터
					ShapeProperty^ envParameter = nullptr;

					// 정상시나리오 output
					//int odIndex = //key를 생성하기 위한 변수
					// normScenarioIndex = //사전의 번호를 생성하기 위한 변수
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					int currentScenarioNumber = i;
					String^ normScenarioIndex = String::Format("{0}", int((currentScenarioNumber) / (unitScenarioStep) * (unitScenarioStep * 10)));
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

					// 0, 7, 150, 450
					for (int j = 0; j < this->m_dataX->Length; j++)
					{
						//시나리오별 경제지수 계산위한 기본 값(칼럼) 정의
						array<String^>^ columnECO = { "VT0", "VT1" };
						DataTable^ newTableECO = NewTable(columnECO);

						//시나리오별 연결지수 계산위한 기본 값(칼럼) 정의
						array<String^>^ columnCON = { "Lz0", "Lzp" };
						DataTable^ newTableCON = NewTable(columnCON);

						//시나리오별 환경지수 계산위한 기본 값(칼럼) 정의
						array<String^>^ columnENV = { "totalEnvLength", "envParamLength" };
						DataTable^ newTableENV = NewTable(columnENV);

						int damageState = j + 1;
						// NeXTA 시뮬레이션 결과가 없으면 정상하고 같음
						String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);
						OutputSummary^ outputSummary = nullptr;
						if (this->m_dataSet->NeXTAOutputSummaryDictionary->ContainsKey(key)) {
							outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[key];
						}
						else {
							outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
						}

						///////////////////////////////////////////////////
						// 경제지수(ECO) 값 생성 
						///////////////////////////////////////////////////

						// 시나리오별 & 데미지상태별 경제지수 계산위한 기본값 데이터 행 생성 및 초기화
						DataRow^ newRowECO;
						newRowECO = newTableECO->NewRow();
						for (int rowIndex = 0; rowIndex < newRowECO->ItemArray->Length; rowIndex++) {
							newRowECO[rowIndex] = 0;
						}
						// 지진 직후 차량 평균 이동시간
						double avgTravelTime_NoDamaged = outputSummary->VT0 / outputSummary->TR0;

						// 도로망 진입 및 진출 차량 대수가 동일한 경우, 다시말해 진입한 모든 차량이 모두 진출한 경우  
						if (outputSummary->TR1 == outputSummary->TR0) {
							newRowECO["VT0"] = outputSummary->VT0 * m_dataSet->ValueOfTime;
							newRowECO["VT1"] = outputSummary->VT1 * m_dataSet->ValueOfTime;
						}
						// 도로망 진입한 모든 차량이 모두 진출 실패한 경우  
						else if (outputSummary->TR1 == 0) {
							newRowECO["VT0"] = (outputSummary->VT0 * m_dataSet->ValueOfTime);
							newRowECO["VT1"] = (outputSummary->TR0 * m_dataSet->PenaltyCost);
						}
						// 도로망 진입한 차량중 일부만 진출한 경우
						else {
							double totalVehicleNo = outputSummary->TR0;
							double leavingVehicleNo = outputSummary->TR1;
							double noLeavingVehicleNo = (outputSummary->TR0 - outputSummary->TR1);

							newRowECO["VT0"] = (outputSummary->VT0 * m_dataSet->ValueOfTime);
							newRowECO["VT1"] = leavingVehicleNo * m_dataSet->ValueOfTime + noLeavingVehicleNo * m_dataSet->PenaltyCost;
						}
						newTableECO->Rows->Add(newRowECO);
						IndiceDictionaryECO->Add(key, newTableECO);


						///////////////////////////////////////////////////
						// 연결지수(CON) 값 생성 
						///////////////////////////////////////////////////

						for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++)
						{
							DataRow^ newRowCON;
							newRowCON = newTableCON->NewRow();
							Zone zone = this->m_dataSet->ZoneGroupData[zoneIndex];
							connParameter = gcnew array<ShapeProperty^>(zone.Links->Length);
							for (int zi = 0; zi < zone.Links->Length; zi++)
							{
								String^ linkID = zone.Links[zi];
								ShapeProperty^ link = this->m_dataSet->ShapeData->m_SHPProperties[this->m_dataSet->ShapeData->m_SHPPropertiesIndexes[linkID]]->Clone();
								// 복구일수는 {0일, 7일, 150일, 450일} max damage state는 {1, 2, 3, 4}, j={0, 1, 2, 3} 이므로 매칭을 하기위해 j+1 필요  
								if (linkIDAndDamageStateDic->ContainsKey(linkID) && linkIDAndDamageStateDic[linkID] >= j + 1) {
									if (j > 0)link->IsClose = true;
								}
								else {
									link->IsClose = false;
								}
								connParameter[zi] = link;
							}
							//CalConnectLossIndices()를 실행함으로써 사전인 IndiceDictionaryCON을 구성함
							// CalConnectLossIndices를 통해 newRowCON에는 각 교통시나리오별 교통구역(Zone)에 포함되는 Lzp(=폐쇄노선 길이) 결과가 저장됨
							newRowCON = m_trafficModule->CalConnectLossIndices(connParameter, newRowCON);
							newTableCON->Rows->Add(newRowCON);
						}
						IndiceDictionaryCON->Add(key, newTableCON);


						///////////////////////////////////////////////////
						// 환경지수(ENV) 값 생성 
						///////////////////////////////////////////////////

						// 시나리오별 & 데미지상태별 환경지수 계산위한 기본값 데이터 행 생성 및 초기화
						DataRow^ newRowENV;
						newRowENV = newTableENV->NewRow();
						for (int rowIndex = 0; rowIndex < newRowENV->ItemArray->Length; rowIndex++) {
							newRowENV[rowIndex] = 0;
						}

						double totalEnvLength = 0; //전체 환경민감 노선길이
						double envParamLength = 0; //환경민감지수가 고려된 환경민감 노선길이 

						//envParameter = gcnew array<ShapeProperty^>(m_dataSet->EnvironmentData->Rows->Count);
						for (int i = 0; i < this->m_dataSet->EnvironmentData->Rows->Count; i++)
						{
							DataRow^ row = this->m_dataSet->EnvironmentData->Rows[i];
							String^ linkID = row[CommConst::GRID_ENVIRONMENT_COL1]->ToString();

							if (this->m_dataSet->ShapeData->m_SHPPropertiesIndexes->ContainsKey(linkID)) {
								envParameter = this->m_dataSet->ShapeData->m_SHPProperties[this->m_dataSet->ShapeData->m_SHPPropertiesIndexes[linkID]];
							}
							totalEnvLength += envParameter->Length;
							envParamLength += envParameter->Length * m_trafficModule->CalEnvironmentLossIndices(envParameter, scenario, j + 1);// damage state0은 제외하므로 +1 해줌
						}
						newRowENV["totalEnvLength"] = totalEnvLength;
						newRowENV["envParamLength"] = envParamLength;

						newTableENV->Rows->Add(newRowENV);
						IndiceDictionaryENV->Add(key, newTableENV);
						//newTableENV->Rows->Clear();
					}

















				}

				SetLossFactor(IndiceDictionaryECO, IndiceDictionaryCON, IndiceDictionaryENV);
				return true;
			}
			catch (Exception^ e) {
				return false;
			}
		}

		// zone group data
		void CreateZoneGroupData() {
			int length = this->m_dataSet->POIConnectivityZoneData->Rows->Count;
			this->m_dataSet->ZoneGroupData = gcnew array<Zone>(length);
			for (int i = 0; i < length; i++)
			{
				DataRow^ zoneRow = this->m_dataSet->POIConnectivityZoneData->Rows[i];
				String^ zoneID = zoneRow[CommConst::GRID_POI_CONNECTIVITY_ZONE_COL1]->ToString();
				int poiCount = 0;
				Int32::TryParse(zoneRow[CommConst::GRID_POI_CONNECTIVITY_ZONE_COL2]->ToString(), poiCount);

				// zone을 기준으로 link 그룹 만들기
				String^ filter = "[" + CommConst::GRID_POI_CONNECTIVITY_COL2 + "]='" + zoneID + "'";
				array<DataRow^>^ foundRows = this->m_dataSet->POIConnectivityData->Select(filter);
				array<String^>^ links = gcnew array<String^>(foundRows->Length);
				for (int j = 0; j < foundRows->Length; j++)
				{
					String^ linkID = foundRows[j][CommConst::GRID_POI_CONNECTIVITY_COL1]->ToString();
					links[j] = linkID;
				}
				Zone zone;
				zone.ID = zoneID;
				zone.POICount = poiCount;
				zone.Links = links;
				this->m_dataSet->ZoneGroupData[i] = zone;
			}

			if (this->IsGeneratedZoneProperties == false) {
				//zone group 데이터의 Properties (ID, POI, Lz0) 정의
				//칼럼명 및 데이터테이블 생성
				//array<String^>^ columnZone = { "zoneID", "POI","Lz0", "totalPOI"};
				array<String^>^ columnZone = { "zoneID", "POI", "totalPOI" };
				this->m_dataSet->ZoneGroupProperties = NewTable(columnZone);
				DataRow^ newRowZone;

				double totalPOI = 0.0; // total number of POI
				for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++)
				{
					Zone zone = this->m_dataSet->ZoneGroupData[zoneIndex];
					totalPOI += zone.POICount;
				}

				for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++)
					{
					newRowZone = this->m_dataSet->ZoneGroupProperties->NewRow();
					Zone zone = this->m_dataSet->ZoneGroupData[zoneIndex];
					/*double sumLz0 = 0.0; // zone length
					for (int zi = 0; zi < zone.Links->Length; zi++)
					{
						String^ linkID = zone.Links[zi];
						ShapeProperty^ prop = this->m_dataSet->ShapeData->m_SHPProperties[this->m_dataSet->ShapeData->m_SHPPropertiesIndexes[linkID]]->Clone();
						sumLz0 += prop->Length;
					}
					//newRowZone["Lz0"] = sumLz0;
					*/
					newRowZone["zoneID"] = zone.ID;
					newRowZone["POI"] = zone.POICount;
					newRowZone["totalPOI"] = totalPOI;
					//글로벌 변수인 ZoneGroupProperties 생성
					this->m_dataSet->ZoneGroupProperties->Rows->Add(newRowZone);
				}
				//zone properties는 지진시나리오 및 교통시나리오와는 무관하므로, 한번만 생성되면 됨.
				this->IsGeneratedZoneProperties = true;
			}
		}

		void SetLossFactor(Dictionary<String^, DataTable^>^ IndiceDictionaryECO, Dictionary<String^, DataTable^>^ IndiceDictionaryCON, Dictionary<String^, DataTable^>^ IndiceDictionaryENV) {
			int totalOD = this->m_dataSet->ODZoneParamData->Rows->Count;
			int totalScenario = this->m_dataSet->TrafficScenarios->Length;
			int totalDamage = this->m_dataSet->DamageStateData->Length;
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
			String^ key;

			// 전체시나리오개수는 (지진소스개수 * 재현주기개수 * 샘플개수 * OD개수)이지만
			// 지수계산은 개별 OD에 대한 것이 아니라 통합OD에 대한 지수이므로
			// 지수는 (지진소스개수 * 재현주기개수 * 샘플개수) 각각에 해당하는 값으로 계산됨
			// 따라서 지수는 (전체시나리오개수/OD개수 = totalScenario / ODindex)별 값으로 계산되어야 함
			array<array<double>^>^ ecoLossIndices = gcnew array<array<double>^>((unitScenarioStep * (totalOD + 1)));
			array<array<double>^>^ conLossIndices = gcnew array<array<double>^>((unitScenarioStep * (totalOD + 1)));
			array<array<double>^>^ envLossIndices = gcnew array<array<double>^>((unitScenarioStep * (totalOD + 1)));

			//개별 OD에 대한 지수값 계산
			//개별 OD에 대한 지수값갯수는 전체시나리오개수(지진소스개수 * 재현주기개수 * 샘플개수 * OD개수)만큼 계산 됨
			// 저장되는 순서는 ecoLossIndices, conLossIndices, envLossIndices의 [i][j]에서 
			// i=(1) ~ (unitScenarioStep * ODindex)
			// j는 손상상태 갯수 (=4)
			for (int i = 0; i < unitScenarioStep* totalOD; i++) {
				// totalDamage는 무손, 경미, 보통, 심각, 붕괴, 최빈 등 6가지로 구성되어 있고
				// 이들 중 "무손", "최빈" 은 손상단계 계산시 제외해야 하며, 따라서 (totalDamage-2) 및 (j+1) 필요 
				ecoLossIndices[i] = gcnew array<double>(totalDamage - 2);
				conLossIndices[i] = gcnew array<double>(totalDamage - 2);
				envLossIndices[i] = gcnew array<double>(totalDamage - 2);


				for (int j = 0; j < totalDamage - 2; j++) {

					double VT0 = 0;
					double VT1 = 0;	
					double sumLzp = 0;
					double sumLz0 = 0;
					int totalPOI = 0;
					int zonePOI = 0;
					double totalEnvLength = 0;
					double envParamLength = 0;

					key = String::Format("{0}{1}", i, j + 1);
					DataRow^ ECO = IndiceDictionaryECO[key]->Rows[0];
					VT0 = double::Parse(ECO["VT0"]->ToString());
					VT1 = double::Parse(ECO["VT1"]->ToString());

					DataRow^ ENV = IndiceDictionaryENV[key]->Rows[0];
					totalEnvLength = double::Parse(ENV["totalEnvLength"]->ToString());
					envParamLength = double::Parse(ENV["envParamLength"]->ToString());

					DataTable^ newTableCON = IndiceDictionaryCON[key];
					for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++) {
							DataRow^ zoneRow = newTableCON->Rows[zoneIndex];
						DataRow^ zoneProperties = this->m_dataSet->ZoneGroupProperties->Rows[zoneIndex];

						sumLz0 = double::Parse(zoneRow["Lz0"]->ToString());
						sumLzp = double::Parse(zoneRow["Lzp"]->ToString());
						zonePOI = int::Parse(zoneProperties["POI"]->ToString());
						totalPOI = int::Parse(zoneProperties["totalPOI"]->ToString());
						conLossIndices[i][j] += ((sumLz0 - sumLzp) / sumLz0) * zonePOI / totalPOI;
					}
					ecoLossIndices[i][j] = VT0 / VT1;
					envLossIndices[i][j] = totalEnvLength / envParamLength;
				}
			}

			// 통합 OD에 대한 지수값 계산
			// 통합 OD에 대한 지수값 갯수는 unitScenarioStep갯수(=지진소스개수 * 재현주기개수 * 샘플개수)만큼 계산 됨
			// 저장되는 순서는 ecoLossIndices, conLossIndices, envLossIndices의 [i][j]에서 
			// i=(unitScenarioStep * ODindex) ~ (unitScenarioStep * (ODindex+1))
			// j는 손상상태 갯수 (=4)

			for (int i = 0; i < unitScenarioStep; i++) {
				// totalDamage는 무손, 경미, 보통, 심각, 붕괴, 최빈 등 6가지로 구성되어 있고
				// 이들 중 "무손", "최빈" 은 손상단계 계산시 제외해야 하며, 따라서 (totalDamage-2) 및 (j+1) 필요 
				ecoLossIndices[i + unitScenarioStep * totalOD] = gcnew array<double>(totalDamage - 2);
				conLossIndices[i + unitScenarioStep * totalOD] = gcnew array<double>(totalDamage - 2);
				envLossIndices[i + unitScenarioStep * totalOD] = gcnew array<double>(totalDamage - 2);

				for (int j = 0; j < totalDamage - 2; j++) {
					double totalVT0 = 0;
					double totalVT1 = 0;
					double totalEnvLength = 0;
					double envParamLength = 0;
					//double sumLzp = 0;
					//double sumLz0 = 0;
					int totalPOI = 0;
					int zonePOI = 0;
					array <double>^ SumLzp = gcnew array<double>(this->m_dataSet->ZoneGroupData->Length);
					array <double>^ SumLz0 = gcnew array<double>(this->m_dataSet->ZoneGroupData->Length);

					for (int k = 0; k < totalOD; k++) {
						key = String::Format("{0}{1}", (i + unitScenarioStep * k), j + 1);
						DataRow^ ECO = IndiceDictionaryECO[key]->Rows[0];
						totalVT0 += double::Parse(ECO["VT0"]->ToString());
						totalVT1 += double::Parse(ECO["VT1"]->ToString());

						DataRow^ ENV = IndiceDictionaryENV[key]->Rows[0];
						totalEnvLength += double::Parse(ENV["totalEnvLength"]->ToString());
						envParamLength += double::Parse(ENV["envParamLength"]->ToString());

						// 각 OD별 구역별 전체노선 및 폐쇄노선 길이 계산
						DataTable^ newTableCON = IndiceDictionaryCON[key];
						for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++) {
							// 구역별 폐쇄노선 길이 계산
							DataRow^ zoneRow = newTableCON->Rows[zoneIndex];
							SumLzp[zoneIndex] += double::Parse(zoneRow["Lzp"]->ToString());

							// 구역별 전체노선 길이 계산
							DataRow^ zoneProperties = this->m_dataSet->ZoneGroupProperties->Rows[zoneIndex];
							SumLz0[zoneIndex] += double::Parse(zoneRow["Lz0"]->ToString());
						}
					}
					ecoLossIndices[i + unitScenarioStep * totalOD][j] = (totalVT0 / totalVT1);
					envLossIndices[i + unitScenarioStep * totalOD][j] = totalEnvLength / envParamLength;

					// 통합 OD에 대한 지수값 계산
					// 각 OD별 폐쇄된 노선의 전체길이 계산
					// 교통해석을 통해 산출되는 결과물인 폐쇄된 노선길이 만 IndiceDictionaryCON에 포함되며,
					// 이를 통해 폐쇄된 노선의 길이을 산출함.
					// 나머지 구역정보는 아래 "통합 OD에 대한 지수값 계산" 처럼, 교통해석과는 관계없는 일정한 값으로서,
					// 구역(zone)정보를 통해 기본길이 및 POI 관련 정보를 계산할 수 있음

					for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++) {
						DataRow^ zoneProperties = this->m_dataSet->ZoneGroupProperties->Rows[zoneIndex];
						zonePOI = int::Parse(zoneProperties["POI"]->ToString());
						totalPOI = int::Parse(zoneProperties["totalPOI"]->ToString());
						//sumLz0 = SumLz0[zoneIndex];
						//sumLzp = SumLzp[zoneIndex];
						conLossIndices[i + unitScenarioStep * totalOD][j] += ((SumLz0[zoneIndex] - SumLzp[zoneIndex]) / SumLz0[zoneIndex]) * zonePOI / totalPOI;
					}
				}
			}

			// eco[i][j]는 시나리오단계[i],  복구단계[j]로 구분되어지며, 함수 SetLossFactor()는 개별 복구단계j 지수를 통합하여 통합지수값을 계산
			this->m_dataSet->ResultData->SetLossFactor(ecoLossIndices, conLossIndices, envLossIndices);

		}


	private: System::Void Step10bForm_Load(System::Object^  sender, System::EventArgs^  e) {
		m_trafficModule = gcnew TrafficModule(this->m_dataSet);
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		this->m_isCalculated = false;


		/*if (this->m_dataSet->POIConnectivityZoneData != nullptr) {
			tbConnectivityCount->SelectedText = String::Format("{0}", this->m_dataSet->POIConnectivityZoneData->Rows->Count);
			//tbConnectivityCount->SelectedText = this->m_dataSet->POIConnectivityZoneData->Rows->Count;
		}
		else { tbConnectivityCount->SelectedText = "1"; }

		// create environmental data
		if (this->m_dataSet->EnvironmentData != nullptr) {
			tbEnvironmentCount->Text = String::Format("{0}", this->m_dataSet->EnvironmentData->Rows->Count);
		}
		else { tbEnvironmentCount->SelectedText = "0"; }
		*/


		// create zone-link data
		dgvConnectivity->DataSource = this->m_dataSet->POIConnectivityData;
		dgvConnectivityZone->DataSource = this->m_dataSet->POIConnectivityZoneData;
		dgvEnvironment->DataSource = this->m_dataSet->EnvironmentData;



		// set combobox datasource for seismic source 
		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		// set combobox datasource for recurrence period 
		this->cboRecurrencePeriod->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboRecurrencePeriod->SelectedIndex = 0;

		// set combobox datasource for sample
		this->cboSample->Items->AddRange(this->m_dataSet->TrafficScenarioSamples);
		this->cboSample->SelectedIndex = 0;
	}
	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateChart();
	}
	private: System::Void cboRecurrencePeriod_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateChart();
	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateChart();
	}
	private: System::Void btnCalculate_Click(System::Object^  sender, System::EventArgs^  e) {
		this->m_isCalculated = CalculateChartData();
		UpdateChart();
	}
	private: System::Void dgvConnectivity_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		int i = 1;
		for each(DataGridViewRow^ row in dgvConnectivity->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvConnectivity->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvConnectivity->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvConnectivity->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvConnectivity->EnableHeadersVisualStyles = false;
	}
	private: System::Void dgvConnectivityZone_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		int i = 1;
		for each(DataGridViewRow^ row in dgvConnectivityZone->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvConnectivityZone->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvConnectivityZone->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvConnectivityZone->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvConnectivityZone->EnableHeadersVisualStyles = false;
	}
	private: System::Void dgvEnvironment_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		int i = 1;
		for each(DataGridViewRow^ row in dgvEnvironment->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvEnvironment->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvEnvironment->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvEnvironment->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvEnvironment->EnableHeadersVisualStyles = false;
	}
	private: System::Void tbConnectivityCount_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void tbEnvironmentCount_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}






	private: System::Void tbConnectivityCount_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		// zone의 갯수를 변경하면 zone define grid를 재설정
		if (String::IsNullOrEmpty(tbConnectivityCount->Text)) {
			tbConnectivityCount->Text = "1";
			return;
		}
		int count = Int32::Parse(tbConnectivityCount->Text);
		if (count >= 0) {
			DataTable^ tmpDt = gcnew DataTable();
			tmpDt->Columns->Add(gcnew DataColumn(CommConst::GRID_POI_CONNECTIVITY_ZONE_COL1));
			tmpDt->Columns->Add(gcnew DataColumn(CommConst::GRID_POI_CONNECTIVITY_ZONE_COL2));
			tmpDt->Columns[0]->ReadOnly = true;
			DataRow^ row = nullptr;
			for (int i = 0; i < count; i++)
			{
				row = tmpDt->NewRow();
				row[CommConst::GRID_POI_CONNECTIVITY_ZONE_COL1] = (i + 1).ToString();
				row[CommConst::GRID_POI_CONNECTIVITY_ZONE_COL2] = i + 1;
				tmpDt->Rows->Add(row);
			}
			this->m_dataSet->POIConnectivityZoneData = tmpDt;
			this->dgvConnectivityZone->DataSource = this->m_dataSet->POIConnectivityZoneData;

			tmpDt = gcnew DataTable();
			tmpDt->Columns->Add(gcnew DataColumn(CommConst::GRID_POI_CONNECTIVITY_COL1));
			tmpDt->Columns->Add(gcnew DataColumn(CommConst::GRID_POI_CONNECTIVITY_COL2));
			tmpDt->Columns[0]->ReadOnly = true; // link id readonly
			for each (ShapeProperty^ linkProperty in this->m_dataSet->ShapeData->m_SHPProperties)
			{
				row = tmpDt->NewRow();
				row[CommConst::GRID_POI_CONNECTIVITY_COL1] = linkProperty->ID;
				row[CommConst::GRID_POI_CONNECTIVITY_COL2] = "1"; // 무조건 zone 을 1로 설정
				tmpDt->Rows->Add(row);
			}
			this->m_dataSet->POIConnectivityData = tmpDt;
			this->dgvConnectivity->DataSource = this->m_dataSet->POIConnectivityData;
		}

	}
	private: System::Void tbEnvironmentCount_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		// evnironment 갯수를 변경하면 해당 grid를 재설정
		if (String::IsNullOrEmpty(tbEnvironmentCount->Text)) {
			tbEnvironmentCount->Text = "0";
			return;
		}
		int count = Int32::Parse(tbEnvironmentCount->Text);
		if (count >= 0) {
			DataTable^ tmpDt = gcnew DataTable();
			tmpDt->Columns->Add(gcnew DataColumn(CommConst::GRID_ENVIRONMENT_COL1));

			for (int i = 0; i < count; i++)
			{
				tmpDt->Rows->Add(tmpDt->NewRow());
			}
			this->m_dataSet->EnvironmentData = tmpDt;
			this->dgvEnvironment->DataSource = this->m_dataSet->EnvironmentData;
		}
	}
	};
}
