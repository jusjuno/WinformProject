#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "RecoveryCost.h"
#include "ComponentInfo.h"
#include "CSVFileManager.h"
#include "NeXTAHelper.h"
#include <algorithm> 
#include "TrafficModule.h"
#include "UNISTHelper.h"






//#include <stdio.h>
//#include <math.h>
//#include <iostream>
//#include <string>
//#include <array>



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
		array<double>^ m_chartDataY3;
		array<double>^ m_chartDataY4;



		array<String^>^ m_subChartDataX;

		NeXTAHelper^ m_nextaHelper;
		UNISTHelper^ m_unistHelper;

		double valueOfTime;
		double penaltyCost;
		double trafficFactor1;
		double trafficFactor2;

		TrafficModule^ m_trafficModule;


		// step9에서 OD수만큼 교통해석프로그램을 수행하고 결과값인 outputsummary.csv를 읽어들이는 것과 같이
		// OD수만큼 OD(i)outputsummary.csv저장된 결과를 읽어 들이고, 내진보강전의 교통해석 결과를 
		// 사전 NeXTAOutputSummaryDictionary에 저장하기 위한 for문임 
		Dictionary<String^, OutputSummary^>^ beforeNeXTAOutputSummaryDictionary;
		Dictionary<String^, array<String^>^ >^ beforeUnistOutputSummaryDictionary;


		//직접
		Dictionary<String^, array<double>^ >^ directCompoBeforDict;
		Dictionary<String^, array<double>^ >^ directCompoAfterDict;
		Dictionary<String^, array<double>^ >^ directLinkBeforDict;
		Dictionary<String^, array<double>^ >^ directLinkAfterDict;
		Dictionary<String^, array<double>^ >^ directLinkAllDict;

		//간접
		Dictionary<String^, array<double>^ >^ inDirectCompoBeforDict;
		Dictionary<String^, array<double>^ >^ inDirectCompoAfterDict;
		Dictionary<String^, array<double>^ >^ inDirectLinkBeforDict;
		Dictionary<String^, array<double>^ >^ inDirectLinkAfterDict;
		Dictionary<String^, array<double>^ >^ inDirectLinkAllDict;



		String^ m_chartType;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
		   //	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
		   array<array<double>^>^ m_subChartDataY;

	private:	   array<ComponentClassInfo>^ m_chartDatas;
	private: ChartDirector::WinChartViewer^ chartViewer;
	private: System::Windows::Forms::ComboBox^ cboSRoad;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ cboEffect;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ cboBudget;

	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cboPriority;


	private: System::Windows::Forms::DataGridView^ dgvSRoad;

	private: System::Windows::Forms::DataGridView^ dgvEffect;

	private: System::Windows::Forms::DataGridView^ dgvBudget;


	private: System::Windows::Forms::DataGridView^ dgvPriority;

	private: System::Windows::Forms::DataGridView^ dgvDirectDamage;

	private: System::Windows::Forms::ComboBox^ cboSeismicPeriod;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cboDirectDamage;

	private: System::Windows::Forms::ComboBox^ cboGrpCondi01;
	private: System::Windows::Forms::ComboBox^ cboGrpCondi02;




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

			this->m_nextaHelper = gcnew NeXTAHelper(this->m_dataSet);
			this->m_unistHelper = gcnew UNISTHelper(this->m_dataSet);


			this->beforeNeXTAOutputSummaryDictionary = gcnew Dictionary<String^, OutputSummary^>();
			this->beforeUnistOutputSummaryDictionary = gcnew Dictionary<String^, array<String^>^>();

			this->directCompoBeforDict = gcnew Dictionary<String^, array<double>^>();
			this->directCompoAfterDict = gcnew Dictionary<String^, array<double>^>();
			this->directLinkBeforDict = gcnew Dictionary<String^, array<double>^>();
			this->directLinkAfterDict = gcnew Dictionary<String^, array<double>^>();
			this->directLinkAllDict = gcnew Dictionary<String^, array<double>^>();

			this->inDirectCompoBeforDict = gcnew Dictionary<String^, array<double>^>();
			this->inDirectCompoAfterDict = gcnew Dictionary<String^, array<double>^>();
			this->inDirectLinkBeforDict = gcnew Dictionary<String^, array<double>^>();
			this->inDirectLinkAfterDict = gcnew Dictionary<String^, array<double>^>();
			this->inDirectLinkAllDict = gcnew Dictionary<String^, array<double>^>();




			this->valueOfTime = this->m_dataSet->ValueOfTime;
			this->penaltyCost = this->m_dataSet->PenaltyCost;
			this->trafficFactor1 = this->m_dataSet->TrafficFactor1;
			this->trafficFactor2 = this->m_dataSet->TrafficFactor2;

			/*if (this->valueOfTime == 0) {
				this->valueOfTime = 9;
				this->penaltyCost = 20;
				this->trafficFactor1 = 16.08;
				this->trafficFactor2 = 1.18;
			}*/


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

		   //protected:


	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Step13Form::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cboDirectDamage = (gcnew System::Windows::Forms::ComboBox());
			this->cboSeismicPeriod = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cboSRoad = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cboEffect = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cboBudget = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cboPriority = (gcnew System::Windows::Forms::ComboBox());
			this->dgvSRoad = (gcnew System::Windows::Forms::DataGridView());
			this->dgvEffect = (gcnew System::Windows::Forms::DataGridView());
			this->dgvBudget = (gcnew System::Windows::Forms::DataGridView());
			this->dgvPriority = (gcnew System::Windows::Forms::DataGridView());
			this->dgvDirectDamage = (gcnew System::Windows::Forms::DataGridView());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboGrpCondi01 = (gcnew System::Windows::Forms::ComboBox());
			this->cboGrpCondi02 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSRoad))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEffect))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudget))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPriority))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDirectDamage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Controls->Add(this->cboDirectDamage, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicPeriod, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->label9, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSRoad, 10, 1);
			this->tableLayoutPanel1->Controls->Add(this->label8, 9, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboEffect, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->label7, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboBudget, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->label6, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboPriority, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->dgvSRoad, 9, 2);
			this->tableLayoutPanel1->Controls->Add(this->dgvEffect, 6, 2);
			this->tableLayoutPanel1->Controls->Add(this->dgvBudget, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->dgvPriority, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->dgvDirectDamage, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 6, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 8, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSample, 10, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboGrpCondi01, 6, 3);
			this->tableLayoutPanel1->Controls->Add(this->cboGrpCondi02, 9, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// cboDirectDamage
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboDirectDamage, 2);
			resources->ApplyResources(this->cboDirectDamage, L"cboDirectDamage");
			this->cboDirectDamage->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDirectDamage->FormattingEnabled = true;
			this->cboDirectDamage->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
				resources->GetString(L"cboDirectDamage.Items"),
					resources->GetString(L"cboDirectDamage.Items1")
			});
			this->cboDirectDamage->Name = L"cboDirectDamage";
			this->cboDirectDamage->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboDirectDamage_SelectionChangeCommitted);
			// 
			// cboSeismicPeriod
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSeismicPeriod, 2);
			resources->ApplyResources(this->cboSeismicPeriod, L"cboSeismicPeriod");
			this->cboSeismicPeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicPeriod->FormattingEnabled = true;
			this->cboSeismicPeriod->Name = L"cboSeismicPeriod";
			this->cboSeismicPeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSeismicPeriod_SelectionChangeCommitted);
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->tableLayoutPanel1->SetColumnSpan(this->label9, 2);
			this->label9->Name = L"label9";
			// 
			// cboSRoad
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSRoad, 2);
			resources->ApplyResources(this->cboSRoad, L"cboSRoad");
			this->cboSRoad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSRoad->FormattingEnabled = true;
			this->cboSRoad->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				resources->GetString(L"cboSRoad.Items"), resources->GetString(L"cboSRoad.Items1"),
					resources->GetString(L"cboSRoad.Items2"), resources->GetString(L"cboSRoad.Items3")
			});
			this->cboSRoad->Name = L"cboSRoad";
			this->cboSRoad->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSRoad_SelectionChangeCommitted);
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// cboEffect
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboEffect, 2);
			resources->ApplyResources(this->cboEffect, L"cboEffect");
			this->cboEffect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboEffect->FormattingEnabled = true;
			this->cboEffect->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				resources->GetString(L"cboEffect.Items"), resources->GetString(L"cboEffect.Items1"),
					resources->GetString(L"cboEffect.Items2"), resources->GetString(L"cboEffect.Items3"), resources->GetString(L"cboEffect.Items4"),
					resources->GetString(L"cboEffect.Items5")
			});
			this->cboEffect->Name = L"cboEffect";
			this->cboEffect->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboEffect_SelectionChangeCommitted);
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// cboBudget
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboBudget, 2);
			resources->ApplyResources(this->cboBudget, L"cboBudget");
			this->cboBudget->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboBudget->FormattingEnabled = true;
			this->cboBudget->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				resources->GetString(L"cboBudget.Items"), resources->GetString(L"cboBudget.Items1"),
					resources->GetString(L"cboBudget.Items2"), resources->GetString(L"cboBudget.Items3")
			});
			this->cboBudget->Name = L"cboBudget";
			this->cboBudget->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboBudget_SelectionChangeCommitted);
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->tableLayoutPanel1->SetColumnSpan(this->label4, 4);
			this->label4->Name = L"label4";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// cboPriority
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboPriority, 2);
			resources->ApplyResources(this->cboPriority, L"cboPriority");
			this->cboPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPriority->FormattingEnabled = true;
			this->cboPriority->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				resources->GetString(L"cboPriority.Items"), resources->GetString(L"cboPriority.Items1"),
					resources->GetString(L"cboPriority.Items2"), resources->GetString(L"cboPriority.Items3")
			});
			this->cboPriority->Name = L"cboPriority";
			this->cboPriority->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboPriority_SelectionChangeCommitted);
			// 
			// dgvSRoad
			// 
			this->dgvSRoad->AllowUserToAddRows = false;
			this->dgvSRoad->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvSRoad, 3);
			resources->ApplyResources(this->dgvSRoad, L"dgvSRoad");
			this->dgvSRoad->Name = L"dgvSRoad";
			this->dgvSRoad->RowTemplate->Height = 23;
			this->dgvSRoad->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvSRoad_DataBindingComplete);
			// 
			// dgvEffect
			// 
			this->dgvEffect->AllowUserToAddRows = false;
			this->dgvEffect->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvEffect, 3);
			resources->ApplyResources(this->dgvEffect, L"dgvEffect");
			this->dgvEffect->Name = L"dgvEffect";
			this->dgvEffect->RowTemplate->Height = 23;
			this->dgvEffect->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvEffect_DataBindingComplete);
			// 
			// dgvBudget
			// 
			this->dgvBudget->AllowUserToAddRows = false;
			this->dgvBudget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvBudget, 3);
			resources->ApplyResources(this->dgvBudget, L"dgvBudget");
			this->dgvBudget->Name = L"dgvBudget";
			this->dgvBudget->RowTemplate->Height = 23;
			this->dgvBudget->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvBudget_DataBindingComplete);
			// 
			// dgvPriority
			// 
			this->dgvPriority->AllowUserToAddRows = false;
			this->dgvPriority->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvPriority, 3);
			resources->ApplyResources(this->dgvPriority, L"dgvPriority");
			this->dgvPriority->Name = L"dgvPriority";
			this->dgvPriority->RowTemplate->Height = 23;
			this->dgvPriority->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvPriority_DataBindingComplete);
			// 
			// dgvDirectDamage
			// 
			this->dgvDirectDamage->AllowUserToAddRows = false;
			this->dgvDirectDamage->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDirectDamage->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvDirectDamage, 6);
			resources->ApplyResources(this->dgvDirectDamage, L"dgvDirectDamage");
			this->dgvDirectDamage->Name = L"dgvDirectDamage";
			this->dgvDirectDamage->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dgvDirectDamage->RowTemplate->Height = 23;
			this->dgvDirectDamage->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step13Form::dgvDirectDamage_DataBindingComplete);
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 6);
			resources->ApplyResources(this->chartViewer, L"chartViewer");
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewer_SizeChanged);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->tableLayoutPanel1->SetColumnSpan(this->label2, 2);
			this->label2->Name = L"label2";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->tableLayoutPanel1->SetColumnSpan(this->label1, 2);
			this->label1->Name = L"label1";
			// 
			// cboSample
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSample, 2);
			resources->ApplyResources(this->cboSample, L"cboSample");
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Name = L"cboSample";
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSample_SelectionChangeCommitted);
			// 
			// cboSeismicSource
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSeismicSource, 2);
			resources->ApplyResources(this->cboSeismicSource, L"cboSeismicSource");
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// cboGrpCondi01
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboGrpCondi01, 3);
			resources->ApplyResources(this->cboGrpCondi01, L"cboGrpCondi01");
			this->cboGrpCondi01->DropDownWidth = 160;
			this->cboGrpCondi01->FormattingEnabled = true;
			this->cboGrpCondi01->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				resources->GetString(L"cboGrpCondi01.Items"),
					resources->GetString(L"cboGrpCondi01.Items1"), resources->GetString(L"cboGrpCondi01.Items2"), resources->GetString(L"cboGrpCondi01.Items3"),
					resources->GetString(L"cboGrpCondi01.Items4"), resources->GetString(L"cboGrpCondi01.Items5"), resources->GetString(L"cboGrpCondi01.Items6")
			});
			this->cboGrpCondi01->Name = L"cboGrpCondi01";
			this->cboGrpCondi01->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboGrpCondi01_SelectionChangeCommitted);
			// 
			// cboGrpCondi02
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboGrpCondi02, 2);
			resources->ApplyResources(this->cboGrpCondi02, L"cboGrpCondi02");
			this->cboGrpCondi02->FormattingEnabled = true;
			this->cboGrpCondi02->Name = L"cboGrpCondi02";
			this->cboGrpCondi02->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboGrpCondi02_SelectionChangeCommitted);
			// 
			// Step13Form
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step13Form";
			this->Load += gcnew System::EventHandler(this, &Step13Form::Step13Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSRoad))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEffect))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudget))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPriority))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDirectDamage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
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
		//else if (!this->m_dataSet->ResultData->IsCalculatedLossfactor) {
		//	Alert::Info("Loss factor has been not calculated.");
		//	return false;
		//}
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
		/*
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
			//RanSeries^ r = gcnew RanSeries(66);

			//DoubleArray samples = r->getGaussianSeries(200, 100, 10);
			//array<double>^ samples = r->getGaussianSeries(200, 100, 10);
			array<double>^ samples = gcnew array<double>(dataY2->Length);
			for (int i = 0; i < dataY2->Length; i++) {
				samples[i] = dataY2[i] / (1000000);
			}

			//
			// Classify the numbers into slots. In this example, the slot width is 5 units.
			//
			ArrayMath^ m = gcnew ArrayMath(samples);
			int slotSize;
			if(samples->Length < 20){
				slotSize = (floor(m->max()) - floor(m->min())) / (samples->Length-1);
			}
			else{
				slotSize = (floor(m->max()) - floor(m->min())) / 19;
			}
			if (slotSize <= 0) { slotSize = 10; }
			//int slotSize = 20;
			//int slotSize = 10000000;

			// Compute the min and max values, and extend them to the slot boundary.
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


			c->yAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabelStyle("Arial Bold", 12);
			c->yAxis()->setLabelStyle("Arial Bold", 12);
			c->yAxis()->setTitle("샘플개수", "Arial Bold", 12);

			c->xAxis()->setColors(Chart::Transparent);
			c->xAxis()->setTitle("피해규모(십억원)", "Arial Bold", 12);


			// Output the chart
			//c->makeChart("histogram.png");
			chartViewer->Chart = c;

			//free up resources
//			delete r;
			delete[] frequency;
			delete[] bellCurve;
			delete c;


		}
		*/

		//그래프 타입6: 병렬 + 직렬 그래프

		void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ sample = cboSample->SelectedItem->ToString();
			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			int plotAreaWidth = chartViewer->Size.Width - 150;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			c->addTitle("", "Times New Roman Bold", 17);

			LegendBox^ b = c->addLegend(120, 10, false, "Arial", 11);
			b->setBackground(Chart::Transparent, Chart::Transparent);
			b->setKeyBorder(Chart::SameAsMainColor);

			// Set the x and y axis stems to transparent and the label font to 12pt Arial
			c->xAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabels(dataX);
			c->xAxis()->setTitle("Recurrence Period (years)", "Arial Bold", 11);

			c->yAxis()->setColors(Chart::Transparent);
			c->xAxis()->setLabelStyle("Arial Bold", 11);
			c->yAxis()->setLabelStyle("Arial Bold", 11);
			//			c->yAxis()->setTitle("Cost (￦) 10^7", "Arial Bold", 12);
			c->yAxis()->setTitle("백억원(￦)", "Arial Bold", 11);
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



		/*
		void DrawCharts() {
			//if (cboSample->SelectedIndex < 0) {
			//	return;
			//}

			// 내진보강(전)
			if (cboIndirectDamage->SelectedIndex == 0) {
				m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
				m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
				m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

				//교통시나리오개수 = 지진시나리오(개수) x 샘플링(개수) 에 대한 루프로 구성을 변경
				for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++)
				{
					m_chartDataX1[i] = this->m_dataSet->RecurrencePeriodData[i];
					///////////////////////////////////////////////////////////////////////////////
					// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다.
					///////////////////////////////////////////////////////////////////////////////
					int odLocalIndex = 1;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, odLocalIndex);

					double sumCost = 0;
					for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
						// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
						String^ localKey = String::Format("{0}", trafficScenarioNo);
						DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];
						sumCost += double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());
					}
					m_chartDataY1[i] = sumCost;

					///////////////////////////////////////////////////////////////////////////////
					// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다
					///////////////////////////////////////////////////////////////////////////////
					double sumTrafficCost = 0;
					array<double>^ beforeAdditionalCostData;

					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
						// 0 = 내진보강전, 1= 내진보강후
						beforeAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);
						int recoveryDayCount = beforeAdditionalCostData->Length;
						for (int i = 0; i < recoveryDayCount; i++) {
							sumTrafficCost += beforeAdditionalCostData[i];
						}
					}
					m_chartDataY2[i] = sumTrafficCost;

				}

				DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
			}



			// 내진보강(후)
			if (cboIndirectDamage->SelectedIndex == 1) {

				m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
				m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
				m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

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

					int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

					double sumTrafficCost = 0;
					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
						sumTrafficCost += this->m_dataSet->ResultData->GetTotalTrafficCost(localTrafficScenarioNo);
					}
					m_chartDataY2[i] = sumTrafficCost;

				}

				DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);

			}


		}

		*/


		//Direct Damage of Component in road-network
		System::Data::DataTable^ NewTable(array<String^>^ columns) {
			DataTable^ table = gcnew DataTable();
			for each (String ^ col in columns) {
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}

		// 정수배열에 대한 내림차순 정리
		array<int>^ DescenderOrder(array<int>^ value) {
			//int temp;
			array<int>^ tempArray = gcnew array<int>(value->Length);
			for (int i = 0; i < value->Length; i++) {
				tempArray[i] = value[i];
			}
			array<int>^ order = gcnew array<int>(tempArray->Length);
			for (int i = 0; i < tempArray->Length; i++) {
				order[i] = i;
			}

			for (int i = 0; i < tempArray->Length; i++)
			{
				for (int j = i + 1; j < tempArray->Length; j++)
				{
					if (tempArray[i] < tempArray[j])
					{
						int tempi = tempArray[i];
						int tempj = tempArray[j];
						tempArray[i] = tempj;
						tempArray[j] = tempi;

						int orderi = order[i];
						int orderj = order[j];
						order[i] = orderj;
						order[j] = orderi;

					}
				}
			}
			return order;
		}

		// 실수배열에 대한 내림차순 정리
		array<int>^ DescenderOrder(array<double>^ value) {
			//double temp;
			array<double>^ tempArray = gcnew array<double>(value->Length);
			for (int i = 0; i < value->Length; i++) {
				tempArray[i] = value[i];
			}
			array<int>^ order = gcnew array<int>(tempArray->Length);
			for (int i = 0; i < tempArray->Length; i++) {
				order[i] = i;
			}

			for (int i = 0; i < tempArray->Length; i++)
			{
				for (int j = i + 1; j < tempArray->Length; j++)
				{
					//if (tempArray[i] < tempArray[j])
					if (tempArray[i] <= tempArray[j])
					{
						double tempi = tempArray[i];
						double tempj = tempArray[j];
						tempArray[i] = tempj;
						tempArray[j] = tempi;

						int orderi = order[i];
						int orderj = order[j];
						order[i] = orderj;
						order[j] = orderi;

					}
				}
			}
			return order;
		}

		// 실수배열에 대한 오름차순 정리
		array<int>^ AscenderOrder(array<double>^ value) {
			//double temp;
			array<double>^ tempArray = gcnew array<double>(value->Length);
			for (int i = 0; i < value->Length; i++) {
				tempArray[i] = value[i];
			}
			array<int>^ order = gcnew array<int>(tempArray->Length);
			for (int i = 0; i < tempArray->Length; i++) {
				order[i] = i;
			}

			for (int i = 0; i < tempArray->Length; i++)
			{
				for (int j = i + 1; j < tempArray->Length; j++)
				{
					if (tempArray[i] > tempArray[j])
					{
						double tempi = tempArray[i];
						double tempj = tempArray[j];
						tempArray[i] = tempj;
						tempArray[j] = tempi;

						int orderi = order[i];
						int orderj = order[j];
						order[i] = orderj;
						order[j] = orderi;
					}
				}
			}
			return order;
		}


		// 시나리오별 간접피해규모 계산(교통피해규모)

		/*
		array<double>^ CalculateAdditionalCost(int beforeAfterIndex, int trafficScenarioNo) {
			try {

				//복구단계 또는 피해단계 총 개수
				int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

				array<double>^ dataX = gcnew array<double>(recoveryStepCount);
				dataX[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
				dataX[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
				dataX[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
				dataX[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;

				//array<array<double>^>^ additionalCostData = gcnew array<array<double>^>(this->m_dataSet->TrafficScenarios->Length + 1);
				array<double>^ additionalCostData = gcnew array<double>(recoveryStepCount);

				//TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
				int preRecoveryDay = 0;

				// 로컬사전 메모리 할당
				Dictionary<String^, OutputSummary^>^ OutputSummaryDictionary = gcnew Dictionary<String^, OutputSummary^>();
				// 내진보강전 결과값 입력
				if (beforeAfterIndex == 0) {
					OutputSummaryDictionary = this->beforeNeXTAOutputSummaryDictionary;
				}
				// 내진보강후 결과값 입력
				else {
					OutputSummaryDictionary = this->m_dataSet->NeXTAOutputSummaryDictionary;
				}

				for (int j = 0; j < recoveryStepCount; j++)
				{
					int damageState = j + 1;
					// NeXTA 시뮬레이션 결과가 없으면 정상하고 같음
					//String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);
					String^ key = NeXTAHelper::GetScenarioId(trafficScenarioNo, damageState);
					OutputSummary^ outputSummary = nullptr;

					if (OutputSummaryDictionary->ContainsKey(key)) {
						outputSummary = OutputSummaryDictionary[key];
						//int totalLinkCount = this->m_dataSet->ShapeData->m_nRecords;

						// 지진 직후 차량 평균 이동시간
						double avgTravelTime_NoDamaged = outputSummary->VT0 / outputSummary->TR0;

						// 도로망 진입 및 진출 차량 대수가 동일한 경우, 다시말해 진입한 모든 차량이 모두 진출한 경우
						if (outputSummary->TR1 == outputSummary->TR0) {
							double extraVT = outputSummary->VT1 - outputSummary->VT0;
							additionalCostData[j] = (extraVT * this->valueOfTime * this->trafficFactor1 * this->trafficFactor2) * (dataX[j] - preRecoveryDay);
						}
						// 도로망 진입한 모든 차량이 모두 진출 실패한 경우
						else if (outputSummary->TR1 == 0) {
							double extraTR = outputSummary->TR0 - outputSummary->TR1;
							additionalCostData[j] = (extraTR * this->trafficFactor1 * this->trafficFactor2 * this->penaltyCost) * (dataX[j] - preRecoveryDay);
						}

						// 도로망 진입한 차량중 일부만 진출한 경우
						else {
							// 추가비용 = max((진출차량VT1_VOT - 진출차량VT0_VOT),0) + 비진출차량VT1_VOT
							// 전체차량대수              = outputSummary->TR0
							// 진출차량대수              = outputSummary->TR1
							// 비진출차량대수            = (outputSummary->TR0 - outputSummary->TR1)
							double totalVehicleNo = outputSummary->TR0;
							double leavingVehicleNo = outputSummary->TR1;
							double noLeavingVehicleNo = (outputSummary->TR0 - outputSummary->TR1);

							// 진출차량VT0               = (outputSummary->TR1 * avgTravelTime_NoDamaged);
							// 진출차량VT1               = outputSummary->VT1
							double leavingVehicle_VT0 = (outputSummary->TR1 * avgTravelTime_NoDamaged);
							double leavingVehicle_VT1 = outputSummary->VT1;

							// 진출차량VT0_VOT               = 진출차량VTO * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
							// 진출차량VT1_VOT               = 진출차량VT1 * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2
							// 비진출차량VT1_VOT             = 비진출차량대수 * m_dataSet->PenaltyCost * m_trafficFactor1 * m_trafficFactor2
							double leavingVehicle_VT0_VOT = leavingVehicle_VT0 * this->valueOfTime * this->trafficFactor1 * this->trafficFactor2;
							double leavingVehicle_VT1_VOT = leavingVehicle_VT1 * this->valueOfTime * this->trafficFactor1 * this->trafficFactor2;
							double noLeavingVehicle_VT1_VOT = (outputSummary->TR0 - outputSummary->TR1) * this->penaltyCost * this->trafficFactor1 * this->trafficFactor2;

							// 추가비용 = (max((진출차량VT1_VOT - 진출차량VT0_VOT),0) + 비진출차량VT1_VOT) * 복구일수
							additionalCostData[j] = (std::max((leavingVehicle_VT1_VOT - leavingVehicle_VT0_VOT), 0.0) + noLeavingVehicle_VT1_VOT) * (dataX[j] - preRecoveryDay);
						}
					}
					else {
						additionalCostData[j] = 0;
					}
					preRecoveryDay = dataX[j];
				}

				return additionalCostData;
			}
			catch (Exception ^ e) {
				Alert::Error("Chart data calculation failed.");
//				return;
			}
		}
		*/

		// Unist 교통해석을 통한 간접피해 규모계산
		array<double>^ CalculateAdditionalCost(int beforeAfterIndex, int trafficScenarioNo) {

			// 내진보강(전) 
			if (beforeAfterIndex == 0) {
				try {
					String^ key = String::Format("{0}", trafficScenarioNo);
					array<String^>^ trafficVolumeStatus = this->beforeUnistOutputSummaryDictionary[key];
					int totalTrafficDay = trafficVolumeStatus->Length;

					array<double>^ trafficVolume = gcnew array<double>(totalTrafficDay);
					array<double>^ additionalCostData = gcnew array<double>(totalTrafficDay);

					for (int j = 0; j < totalTrafficDay; j++) {
						trafficVolume[j] = double::Parse(trafficVolumeStatus[j]->ToString());
					}

					// 지진(전)교통량 대비 지진(후)교통량이 5% 이하일 경우, 교통포기가 발생하는 것으로 산정
					// 이는 Suroggate Model의 불확실성을 고려하기 위함
					double currentTrafficeVolume;
					double normalTrafficVolume = trafficVolume[totalTrafficDay - 1]; // 도로망이 정상일때의 차량통행량

					for (int j = 0; j < totalTrafficDay; j++) {
						currentTrafficeVolume = trafficVolume[j];
						if (currentTrafficeVolume < 0.05 * normalTrafficVolume) {
							additionalCostData[j] = (normalTrafficVolume - currentTrafficeVolume) *
								this->trafficFactor1 * this->trafficFactor2 * this->penaltyCost;
						}
						else {
							additionalCostData[j] = (normalTrafficVolume - currentTrafficeVolume) *
								this->valueOfTime * this->trafficFactor1 * this->trafficFactor2;
						}
					}
					return additionalCostData;

				}
				catch (Exception^ e) {
					Alert::Error("Chart data calculation failed.");
				}

			}

			if (beforeAfterIndex == 1) {
				try {
					// 내진보강(전) 
					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[trafficScenarioNo];
					array<String^>^ trafficVolumeStatus = this->m_dataSet->TrafficVolumeStatus[scenario->TrafficScenarioKey];
					int totalTrafficDay = trafficVolumeStatus->Length;

					array<double>^ functionalityData = gcnew array<double>(totalTrafficDay);
					array<double>^ additionalCostData = gcnew array<double>(totalTrafficDay);

					for (int j = 0; j < totalTrafficDay; j++) {
						functionalityData[j] = double::Parse(trafficVolumeStatus[j]->ToString());
					}

					// 지진(전)교통량 대비 지진(후)교통량이 5% 이하일 경우, 교통포기가 발생하는 것으로 산정
					// 이는 Suroggate Model의 불확실성을 고려하기 위함
					double currentTrafficeVolume;
					double normalTrafficVolume = functionalityData[totalTrafficDay - 1]; // 도로망이 정상일때의 차량통행량

					for (int j = 0; j < totalTrafficDay; j++) {
						currentTrafficeVolume = functionalityData[j];
						if (currentTrafficeVolume < 0.05 * normalTrafficVolume) {
							additionalCostData[j] += (normalTrafficVolume - currentTrafficeVolume) *
								this->trafficFactor1 * this->trafficFactor2 * this->penaltyCost;
						}
						else {
							additionalCostData[j] += (normalTrafficVolume - currentTrafficeVolume) *
								this->valueOfTime * this->trafficFactor1 * this->trafficFactor2;
						}
					}
					return additionalCostData;

				}
				catch (Exception^ e) {
					Alert::Error("Chart data calculation failed.");
				}

			}

		}


		// (총)직접피해규모 계산
		double CalculateDirectCost(int stageIndex, int odIndex) {

			double totalDirectCost = 0; //총직접피해 규모 

			// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
			int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, 1);
			String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
			DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];

			DataRow^ newRow = this->m_dataSet->ODZoneParamData->Rows[odIndex];
			int originNode = int::Parse(newRow[0]->ToString());
			int destinNode = int::Parse(newRow[1]->ToString());
			array<String^>^ roadLink = this->m_unistHelper->dijkstra(originNode, destinNode);
			int ODlinkCount = roadLink->Length;

			if (stageIndex == 0) {
				// OD별 노선수 -> 노선별 시설물개수 계산과정을 통해, OD에 포함된 (총)시설물 개수를 계산
				for (int i = 0; i < ODlinkCount; i++) {
					for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
						String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
						if (linkID == roadLink[i]) {
//							totalDirectCost += double::Parse(beforeDirectCostTable->Rows[i]->ItemArray[1]->ToString());            // 내진보강전 직접피해규모                                                                                   //내진보강전 직접피해규모
							totalDirectCost += double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());            // 내진보강전 직접피해규모                                                                                   //내진보강전 직접피해규모
						}
					}
				}
			}

			if (stageIndex == 1) {
				// 노선에 속해 있는 시설물 리스트들에 대한 (총)직접피해비용 계산
				// OD별 노선수 -> 노선별 시설물개수 계산과정을 통해, OD에 포함된 (총)시설물 개수를 계산
				for (int i = 0; i < ODlinkCount; i++) {
					for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
						String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
						if (linkID == roadLink[i]) {
							totalDirectCost += this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNoForStructureCost, compID); // 내진보강후 직접피해규모                                                                       //내진보강전 직접피해규모
						}
					}
				}
			}

			return totalDirectCost;

			/*
			double totalDirectCost = 0; //총직접피해 규모
			// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;

			// OD노선에 속하는 시설물을 파악하기 위해 사용되는 교통시나리오 번호이며, normalOutputSummary 계산시 사용됨
			int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex+1);
			// 전체시설물의 직접피해는 OD와 관계없이 일정, 따라서 직접피해계산함수 "GetComponentStructuralCost()","beforeDirectCostTable()"에 사용되는 "odIndex+1"값은 기본값인 "1"을 사용
			int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, 1);

			String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
			OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

			if(stageIndex == 0) {
				// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
				String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
				DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];

				// 노선에 속해 있는 시설물 리스트들에 대한 (총)직접피해비용 계산
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
				{
					String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
					String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

					// for 문을 통해 전체시설물과 OD노선에 속하는 시설물을 비교하여, 포함된 시설물의 직접피해 비용을 저장
					if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
						totalDirectCost += double::Parse(beforeDirectCostTable->Rows[i]->ItemArray[1]->ToString());            // 내진보강전 직접피해규모                                                                                   //내진보강전 직접피해규모
					}
				}// 전체 시설물 개수에 대한 for()
			}


			if(stageIndex == 1){
				// 노선에 속해 있는 시설물 리스트들에 대한 (총)직접피해비용 계산
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
				{
					String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
					String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

					// for 문을 통해 전체시설물과 OD노선에 속하는 시설물을 비교하여, 포함된 시설물의 직접피해 비용을 저장
					if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
						totalDirectCost += this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNoForStructureCost, compID); // 내진보강후 직접피해규모
					}
				}// 전체 시설물 개수에 대한 for()
			}

			*/


		}

		// (총)간접피해규모 계산
		double CalculateIndirectCost(int stageIndex, int odIndex) {
			// 총 복구단계 (수)
			//int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

			int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
			//array<double>^ currentAdditionalCostData = gcnew array<double>(recoveryStepCount);
			array<double>^ currentAdditionalCostData;
			//DataRow^ newRow = SRoadDamage->NewRow();

			// 0 = 내진보강전, 1= 현재상태
			currentAdditionalCostData = CalculateAdditionalCost(stageIndex, localTrafficScenarioNo);

			double totalIndirectCost = 0;
			//for (int j = 0; j < recoveryStepCount; j++)
			for (int j = 0; j < currentAdditionalCostData->Length; j++)
				{
				totalIndirectCost += currentAdditionalCostData[j];
			}
			return totalIndirectCost;
		}


		// 경제지수(ECO) 계산
		double CalculateIndiceECO(int trafficScenarioNo, Dictionary<String^, OutputSummary^>^ outputSummaryDictionary) {

			//int odIndex = //key를 생성하기 위한 변수
			// normScenarioIndex = //사전의 번호를 생성하기 위한 변수
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
			String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
			OutputSummary^ normalOutputSummary = outputSummaryDictionary[normScenarioIndex];

			// 0, 7, 150, 450
			int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;
			// 각시나리오에 해당하는 복구단계별 지수값을 저장하는 열 
			array<double>^ ECO = gcnew array<double>(recoveryStepCount);
			double result;


			for (int j = 0; j < recoveryStepCount; j++)
			{
				double VT0;
				double VT1;
				//시나리오별 경제지수 계산위한 기본 값(칼럼) 정의
				array<String^>^ columnECO = { "VT0", "VT1" };
				DataTable^ newTableECO = NewTable(columnECO);

				int damageState = j + 1;
				// NeXTA 시뮬레이션 결과가 없으면 정상하고 같음
				String^ key = NeXTAHelper::GetScenarioId(trafficScenarioNo, damageState);
				OutputSummary^ outputSummary = nullptr;
				if (outputSummaryDictionary->ContainsKey(key)) {
					outputSummary = outputSummaryDictionary[key];
				}
				else {
					outputSummary = outputSummaryDictionary[normScenarioIndex];
				}

				// 도로망 진입 및 진출 차량 대수가 동일한 경우, 다시말해 진입한 모든 차량이 모두 진출한 경우  
				if (outputSummary->TR1 == outputSummary->TR0) {
					VT0 = outputSummary->VT0 * this->valueOfTime;
					VT1 = outputSummary->VT1 * this->valueOfTime;
				}
				// 도로망 진입한 모든 차량이 모두 진출 실패한 경우  
				else if (outputSummary->TR1 == 0) {
					VT0 = (outputSummary->VT0 * this->valueOfTime);
					VT1 = (outputSummary->TR0 * this->penaltyCost);
				}
				// 도로망 진입한 차량중 일부만 진출한 경우
				else {
					double totalVehicleNo = outputSummary->TR0;
					double leavingVehicleNo = outputSummary->TR1;
					double noLeavingVehicleNo = (outputSummary->TR0 - outputSummary->TR1);

					VT0 = (outputSummary->VT0 * this->valueOfTime);
					VT1 = leavingVehicleNo * this->valueOfTime + noLeavingVehicleNo * this->penaltyCost;
				}
				ECO[j] = VT0 / VT1;
			}
			result = this->m_dataSet->ResultData->GetTotalEconomicLossIndices(ECO);
			return result;

		}

		// 연결지수(CON) 계산
		double CalculateIndiceCON(int stageIndex, int trafficScenarioNo, Dictionary<String^, OutputSummary^>^ outputSummaryDictionary) {

			// 계산순서
			// 1. 특정 시나리오에 대해 도로망노선 중 폐쇄노선 및 해당노선의 폐쇄정도(데미지단계)확인
			// 2. 

			Dictionary<String^, int>^ linkIDAndDamageStateDic = gcnew Dictionary<String^, int>();

			if (stageIndex == 0) {


				if (this->m_dataSet->BeforeComponentScenarios == nullptr) {
					String^ key = nullptr;
					//Dictionary<String^, DataTable^>^ beforeRehabStructureCost = gcnew Dictionary<String^, DataTable^>();
					this->m_dataSet->BeforeComponentScenarios = gcnew Dictionary<String^, DataTable^>();

					//CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->ResultFilePath + "before_ComponentScenarios_summary.csv");
					CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->UnistResultFilePath + "before_ComponentScenarios_summary.csv");
					String^ output = csv->Read();
					if (!String::IsNullOrEmpty(output)) {

						array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
						int outputRowCount = dataArray->Length;

						String^ outputLineData = dataArray[0];
						array<String^>^ originalColumns = CSVFileManager::Parse(outputLineData, ",");
						// 사전을 구성하기 위해 "Key" 와 "값"으로 구분. key는 originalColumns[0]에 있음
						array<String^>^ columns = gcnew array<String^>(originalColumns->Length - 1);
						for (int i = 0; i < originalColumns->Length - 1; i++) {
							columns[i] = originalColumns[i + 1];
						}
						DataTable^ newTable;
						newTable = NewTable(columns);

						for (int i = 1; i < outputRowCount; i++)
						{
							String^ outputLineData = dataArray[i];
							array<String^>^ values = gcnew array<String^>(originalColumns->Length);
							values = CSVFileManager::Parse(outputLineData, ",");
							DataRow^ newRow = nullptr;
							newRow = newTable->NewRow(); // create new row

							if (i == 1) {
								key = values[0];
							}

							if (key == values[0]) {
								// 데이터 행 초기화
								//DataTable^ newTable;
								//newTable = NewTable(columns);
								//DataRow^ newRow = nullptr;
								//newRow = newTable->NewRow(); // create new row

								newRow["compID"] = values[1];
								newRow["linkID"] = values[2];
								newRow["MaxDamage"] = values[3];
								newTable->Rows->Add(newRow);
							}
							else {
								// 기존key에 해당하는 테이블을 사전에 등록
								this->m_dataSet->BeforeComponentScenarios->Add(key, newTable);

								// 데이터 테이블 및 행 초기화
								//DataTable^ newTable = nullptr;
								//newTable = NewTable(columns);
								newTable = gcnew DataTable();
								//newTable->Clear();
								//newTable = nullptr;
								newTable = NewTable(columns);
								DataRow^ newRow = nullptr;
								newRow = newTable->NewRow(); // create new row

								// 새로운 key를 할당하고 key에 해당하는 테이블 작성시작
								key = values[0];
								newRow["compID"] = values[1];
								newRow["linkID"] = values[2];
								newRow["MaxDamage"] = values[3];
								newTable->Rows->Add(newRow);
							}
							if (i == outputRowCount - 1) {
								this->m_dataSet->BeforeComponentScenarios->Add(key, newTable);
							}
						}
					}
				}

				// 해당 시나리오에서 각 link 중 어느 damage state까지 link가 closed 되어있는지 확인(중복제거)

				String^ key = String::Format("{0}", trafficScenarioNo);
				DataTable^ beforeComponentScenario = this->m_dataSet->BeforeComponentScenarios[key];

				//beforeComponentScenario->Rows[i]->ItemArray[0]->ToString()
				for (int compIndex = 0; compIndex < beforeComponentScenario->Rows->Count; compIndex++) {

					String^ LinkID = beforeComponentScenario->Rows[compIndex]->ItemArray[1]->ToString();
					int MaxDamageState = int::Parse(beforeComponentScenario->Rows[compIndex]->ItemArray[2]->ToString());

					if (!linkIDAndDamageStateDic->ContainsKey(LinkID)) {
						linkIDAndDamageStateDic->Add(LinkID, MaxDamageState);
					}
					else {
						int value = linkIDAndDamageStateDic->ContainsKey(LinkID);
						if (MaxDamageState > value) {
							linkIDAndDamageStateDic->Remove(LinkID);
							linkIDAndDamageStateDic->Add(LinkID, MaxDamageState);
						}
					}
				}
			}

			if (stageIndex == 1) {
				// 해당 시나리오에서 각 link 중 어느 damage state까지 link가 closed 되어있는지 확인(중복제거)
				TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[trafficScenarioNo];
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
			}

			//int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
			//String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
			//OutputSummary^ normalOutputSummary = outputSummaryDictionary[normScenarioIndex];

			// 0, 7, 150, 450
			int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;
			// 각시나리오에 해당하는 복구단계별 지수값을 저장하는 열 
			array<double>^ CON = gcnew array<double>(recoveryStepCount);
			double result;

			// Connectivity 구역(zone)에 속해있는 노선(link)를 저장
			array<ShapeProperty^>^ connParameter;

			for (int j = 0; j < recoveryStepCount; j++)
			{
				//시나리오별 연결지수 계산위한 기본 값(칼럼) 정의
				array<String^>^ columnCON = { "Lz0", "Lzp" };
				DataTable^ newTableCON = NewTable(columnCON);

				// zoneGroupData는 내진보강(전)과(후) 동일함
				for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++)
				{

					DataRow^ newRowCON = newTableCON->NewRow();
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
					//CalConnectLossIndices()를 통해 newRowCON에는 각 교통시나리오별 교통구역(Zone)에 포함되는 Lzp(=폐쇄노선 길이) 결과가 저장됨 
					newRowCON = m_trafficModule->CalConnectLossIndices(connParameter, newRowCON);
					newTableCON->Rows->Add(newRowCON);
				}

				for (int zoneIndex = 0; zoneIndex < this->m_dataSet->ZoneGroupData->Length; zoneIndex++) {
					DataRow^ zoneRow = newTableCON->Rows[zoneIndex];
					DataRow^ zoneProperties = this->m_dataSet->ZoneGroupProperties->Rows[zoneIndex];

					double sumLz0 = double::Parse(zoneRow["Lz0"]->ToString());
					double sumLzp = double::Parse(zoneRow["Lzp"]->ToString());
					int zonePOI = int::Parse(zoneProperties["POI"]->ToString());
					int totalPOI = int::Parse(zoneProperties["totalPOI"]->ToString());
					CON[j] += ((sumLz0 - sumLzp) / sumLz0) * zonePOI / totalPOI;
				}
			}

			result = this->m_dataSet->ResultData->GetTotalEconomicLossIndices(CON);
			return result;

		}

		// 환경지수(ENV) 계산
		double CalculateIndiceENV(int trafficScenarioNo, Dictionary<String^, OutputSummary^>^ outputSummaryDictionary) {

			// normScenarioIndex = //사전의 번호를 생성하기 위한 변수
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
			String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
			OutputSummary^ normalOutputSummary = outputSummaryDictionary[normScenarioIndex];

			int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT; 			// 0, 7, 150, 450
			array<double>^ ENV = gcnew array<double>(recoveryStepCount); 			// 각시나리오에 해당하는 복구단계별 지수값을 저장하는 열 
			double result;

			ShapeProperty^ envParameter = nullptr; 			// Connectivity: 환경민감 노선의 지진전후 교통량 변화율
			TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[trafficScenarioNo]; 			// 교통시나리오 구성

			for (int j = 0; j < recoveryStepCount; j++)
			{
				double totalEnvLength = 0; //전체 환경민감 노선길이
				double envParamLength = 0; //환경민감지수가 고려된 환경민감 노선길이 

				for (int i = 0; i < this->m_dataSet->EnvironmentData->Rows->Count; i++)
				{
					DataRow^ row = this->m_dataSet->EnvironmentData->Rows[i];
					String^ linkID = row[CommConst::GRID_ENVIRONMENT_COL1]->ToString();

					if (this->m_dataSet->ShapeData->m_SHPPropertiesIndexes->ContainsKey(linkID)) {
						envParameter = this->m_dataSet->ShapeData->m_SHPProperties[this->m_dataSet->ShapeData->m_SHPPropertiesIndexes[linkID]];
					}
					totalEnvLength += envParameter->Length;
					envParamLength += envParameter->Length * m_trafficModule->CalEnvironmentLossIndices(outputSummaryDictionary, envParameter, scenario, j + 1, unitScenarioStep);// damage state0은 제외하므로 +1 해줌
				}
				ENV[j] = totalEnvLength / envParamLength;
			}
			result = this->m_dataSet->ResultData->GetTotalEconomicLossIndices(ENV);
			return result;
		}


		// 내진보강전 값(직접피해, 간접피해, Outputsummary) 계산
		void beforeRehabSimulationResult() {
			//////////////////////////////////////////////////////////////////
			// 기존 직접피해규모 시뮬레이션 결과 확보 
			// structureCost_summary.csv에 저장되어 있는 시설물별 직접피해 계산
			//////////////////////////////////////////////////////////////////

			if (this->m_dataSet->BeforeRehabStructureCost == nullptr || this->m_dataSet->BeforeRehabStructureCost->Count == 0) {
				String^ key = nullptr;
				//Dictionary<String^, DataTable^>^ beforeRehabStructureCost = gcnew Dictionary<String^, DataTable^>();
				this->m_dataSet->BeforeRehabStructureCost = gcnew Dictionary<String^, DataTable^>();

				//CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->ResultFilePath + "before_structureCost_summary.csv");
				CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->UnistResultFilePath + "before_structureCost_summary.csv");
				String^ output = csv->Read();
				if (!String::IsNullOrEmpty(output)) {

					array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
					int outputRowCount = dataArray->Length;

					String^ outputLineData = dataArray[0];
					array<String^>^ originalColumns = CSVFileManager::Parse(outputLineData, ",");
					array<String^>^ columns = gcnew array<String^>(originalColumns->Length - 1);
					for (int i = 0; i < originalColumns->Length - 1; i++) {
						columns[i] = originalColumns[i + 1];
					}

					DataTable^ newTable;
					newTable = NewTable(columns);

					for (int i = 1; i < outputRowCount; i++)
					{
						String^ outputLineData = dataArray[i];
						array<String^>^ values = gcnew array<String^>(originalColumns->Length);
						values = CSVFileManager::Parse(outputLineData, ",");

						DataRow^ newRow = nullptr;
						newRow = newTable->NewRow(); // create new row

						if (i == 1) {
							key = values[0];
						}

						if (key == values[0]) {
							// 데이터 행 초기화
							newRow["compID"] = values[1];
							newRow["directDamage"] = values[2];
							newTable->Rows->Add(newRow);
						}
						else {
							// 기존key에 해당하는 테이블을 사전에 등록
							this->m_dataSet->BeforeRehabStructureCost->Add(key, newTable);

							// 데이터 테이블 및 행 초기화
							newTable = gcnew DataTable();
							newTable = NewTable(columns);
							DataRow^ newRow = nullptr;
							newRow = newTable->NewRow(); // create new row

							// 새로운 key를 할당하고 key에 해당하는 테이블 작성시작
							key = values[0];
							newRow["compID"] = values[1];
							newRow["directDamage"] = values[2];
							newTable->Rows->Add(newRow);
						}
						if (i == outputRowCount - 1) {
							this->m_dataSet->BeforeRehabStructureCost->Add(key, newTable);
						}
					}
				}

			}

			//////////////////////////////////////////////
			// 기존(내진보강전) 교통해석 파일에서 결과값 읽기
			//////////////////////////////////////////////
			// step9b에서 OD수만큼 교통해석프로그램을 수행하고 결과값인 TrafficSimulationResult_summary.csv를
			// OD수만큼 읽어 들이고, 내진보강전의 교통해석 결과로 
			// 사전 UnistOutputSummaryDictionary에 저장하기 위한 for문임 

			if (this->beforeUnistOutputSummaryDictionary->Count == 0) {
				int scenarioCount = this->m_dataSet->TotalTrafficScenarioCount;
				// 직접피해산출 및 교통해석 결과저장 경로
				String^ filePath = this->m_dataSet->UnistResultFilePath + "before_TrafficSimulationResult_summary.csv";
				// 사전에 수록되는 정보는 교통시나리오 수 만큼 임
				this->beforeUnistOutputSummaryDictionary = m_unistHelper->ReadOutputSummaryFile(filePath, scenarioCount, this->beforeUnistOutputSummaryDictionary);

			}


			/*
			// step9에서 OD수만큼 교통해석프로그램을 수행하고 결과값인 outputsummary.csv를 읽어들이는 것과 같이
			// OD수만큼 OD(i)outputsummary.csv저장된 결과를 읽어 들이고, 내진보강전의 교통해석 결과를
			// 사전 NeXTAOutputSummaryDictionary에 저장하기 위한 for문임
			if (this->beforeNeXTAOutputSummaryDictionary->Count == 0) {
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					// 직접피해산출 및 교통해석 결과저장 경로
					//String^ filePath = this->m_dataSet->ResultFilePath + "before_OD" + String::Format("{0}", odIndex + 1) + "_output_summary.csv";
					String^ filePath = this->m_dataSet->UnistResultFilePath + "before_OD" + String::Format("{0}", odIndex + 1) + "_output_summary.csv";
					// 사전에 수록되는 정보는 UnitScenarioNum * OD(수)
					this->beforeNeXTAOutputSummaryDictionary = m_nextaHelper->ReadOutputSummaryFile(filePath, odIndex, this->beforeNeXTAOutputSummaryDictionary);
				}
			}
			*/




		}



		// NEXTAHelper를 이용한 OD별 시설물번호 계산
		array<int, 2>^ CalculateODComponent() {
			int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index

			//array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
				//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
				int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
				//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
				String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);
				OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
				if (maxIndex < normalOutputSummary->Volumes->Count) {
					maxIndex = normalOutputSummary->Volumes->Count;
				}
			}

			array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

				int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

				// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
				int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
				String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
				OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

				// 노선에 속해 있는 시설물 리스트들
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
				{
					String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
					String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

					if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
						odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
						odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
						//directCostOrder[odIndex] += odComponentFull[compoIndex, odIndex * 2 + 1];

						compoIndex++;
					}
				}// 전체 시설물 개수에 대한 for()
			}// 전체 OD 개수에 대한 for()


			return odComponentFull;

		}

		/*
		array<int, 2>^ CalculateODComponent(int stageIndex) {
			int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index

			//array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
				//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
				int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
				//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
				String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);

				OutputSummary^ normalOutputSummary;
				if(stageIndex == 0){
					normalOutputSummary = this->beforeNeXTAOutputSummaryDictionary[normScenarioIndex];
				}
				else if(stageIndex ==1){
					normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
				}

				if (maxIndex < normalOutputSummary->Volumes->Count) {
					maxIndex = normalOutputSummary->Volumes->Count;
				}
			}

			array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

				int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

				// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
				int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
				String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
				OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

				// 노선에 속해 있는 시설물 리스트들
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
				{
					String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
					String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

					if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
						odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
						odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
						//directCostOrder[odIndex] += odComponentFull[compoIndex, odIndex * 2 + 1];

						compoIndex++;
					}
				}// 전체 시설물 개수에 대한 for()
			}// 전체 OD 개수에 대한 for()


			return odComponentFull;

		}
		*/
		// UnistHelper를 이용한 OD별 시설물 번호 계산
		array<int, 2>^ CalculateODComponent(int stageIndex) {

			// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
			int maxIndex = 0;
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
				DataRow^ newRow = this->m_dataSet->ODZoneParamData->Rows[odIndex];
				int originNode = int::Parse(newRow[0]->ToString());
				int destinNode = int::Parse(newRow[1]->ToString());
				array<String^>^ roadLink = this->m_unistHelper->dijkstra(originNode, destinNode);
				int ODlinkCount = roadLink->Length;

				int compoCountIndex = 0;

				for (int odIndex = 0; odIndex < ODlinkCount; odIndex++) {
					for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
						String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
						if (linkID == roadLink[odIndex]) {
							compoCountIndex++;
						}
					}
				}

				if (maxIndex < compoCountIndex) {
					maxIndex = compoCountIndex;
				}
			}


			// OD 노선에 속해 있는 시설물 리스트 및 직접피해규모 산출

			array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);
			for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

				int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);

				DataRow^ newRow = this->m_dataSet->ODZoneParamData->Rows[odIndex];
				int originNode = int::Parse(newRow[0]->ToString());
				int destinNode = int::Parse(newRow[1]->ToString());
				array<String^>^ roadLink = this->m_unistHelper->dijkstra(originNode, destinNode);
				int ODlinkCount = roadLink->Length;

				if (stageIndex == 0) {
					String^ localKey = String::Format("{0}", trafficScenarioNo);
					DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];

					for (int i = 0; i < ODlinkCount; i++) {
						for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
							String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
							String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
							if (linkID == roadLink[i]) {
								odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
								odComponentFull[compoIndex, odIndex * 2 + 1] = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());
								compoIndex++;
							}
						}
					}
				}


				if (stageIndex == 1) {
					for (int i = 0; i < ODlinkCount; i++) {
						for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
							String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
							String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
							if (linkID == roadLink[i]) {
								odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
								odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
								compoIndex++;
							}
						}
					}
				}
			}

			return odComponentFull;

		}



		// 시설물별 직접피해규모 계산
		void UpdateComponentDirectDamage() {

			Debug::WriteLine("========= UpdateComponentDirectDamage ========>cboDirectDamage:" + cboDirectDamage->SelectedIndex);
			m_chartDataX1 = gcnew array<String^>(this->m_dataSet->NetworkCompnentData->Rows->Count);
			m_chartDataY1 = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);
			m_chartDataY2 = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);
			m_chartDataY3 = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);
			m_chartDataY4 = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);


			/*** 내진보강(전) ***/
			if (cboDirectDamage->SelectedIndex == 0) {

				array<String^>^ columns = { "시설물", "노선", "50년", "100년", "475년", "1000년" };
				DataTable^ newTable = NewTable(columns);

				for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
					DataRow^ newRow = newTable->NewRow();
					DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
					String^ componentID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ link = row[NetworkComponent::COL_LINK_ID]->ToString();

					newRow[0] = componentID;
					newRow[1] = link;

					//그래프 X축
					array<double>^ arrDataY = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);//직접
					array<double>^ arrDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);//간접

					for (int k = 0; k < this->m_dataSet->RecurrencePeriodData->Length; k++) {
						///////////////////////////////////////////////////////////////////////////////
						// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
						///////////////////////////////////////////////////////////////////////////////

						// 도로망의 전체 직접피해(Direct Cost or Structure Cost) 계산은 OD와 관계없으므로,
						// 시나리오번호 계산함수 "GetTrafficScenarioNo()"에 사용되는 "odIndex+1"값은 기본값인 "1"을 사용
						int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, k, 1, 1);

						// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
						String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
						DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];

						double value = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());

						// 재현주기는 2번칼럼 부터 재현주기1(예50년), 재현주기2(예,100년), 재현주기3(예,475년), 재현주기4(예,1000년) 순으로 입력됨											   						 					  
						newRow[k + 2] = value;

						arrDataY[k] = value;


						/////////////////////////////////////////////////////////
						//간접피해 계산
						/////////////////////////////////////////////////////////
						double sumTrafficCost = 0;
						array<double>^ beforeAdditionalCostData;
						for (int a = 0; a < this->m_dataSet->ODZoneParamData->Rows->Count; a++) {
							int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, k, 1, a + 1);
							// 0 = 내진보강전, 1= 내진보강후
							beforeAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);
							int recoveryDayCount = beforeAdditionalCostData->Length;
							for (int b = 0; b < recoveryDayCount; b++) {
								sumTrafficCost += beforeAdditionalCostData[b];
							}
						}
						arrDataY2[k] = sumTrafficCost;


						
					}

					/**** Dict에 저장 ****/
					//직접
					if (!directCompoBeforDict->ContainsKey(componentID)) {
						directCompoBeforDict->Add(componentID, arrDataY);
					}

					array<double>^ tmpY = (array<double>^)arrDataY->Clone();
					if (directLinkBeforDict->ContainsKey(link)) {
						array<double>^ arr = directLinkBeforDict[link];
						for (int n = 0; n < tmpY->Length; n++) {
							//arrDataY[n] += arr[n];
							arr[n] += tmpY[n];
						}
						directLinkBeforDict[link] = arr;
					}
					else {
						directLinkBeforDict->Add(link, tmpY);
					}


					//간접
					if (!inDirectCompoBeforDict->ContainsKey(componentID)) {
						inDirectCompoBeforDict->Add(componentID, arrDataY2);
					}
	
					array<double>^ tmpY2 = (array<double>^)arrDataY2->Clone();
					if (inDirectLinkBeforDict->ContainsKey(link)) {
						array<double>^ arr = inDirectLinkBeforDict[link];
						for (int n = 0; n < tmpY2->Length; n++) {
							//arrDataY2[n] += arr[n];
							arr[n] += tmpY2[n];
						}
						inDirectLinkBeforDict[link] = arr;
					}
					else {
						inDirectLinkBeforDict->Add(link, tmpY2);
					}





					newTable->Rows->Add(newRow);
				}

				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = newTable->Rows[i];
					//directDamages[i] = double::Parse(newRow->ItemArray[indexRecurrencePeriod]->ToString());
					//String^ temp = newRow[indexRecurrencePeriod]->ToString();
					//int k=1;
				}

				dgvDirectDamage->DataSource = newTable;
				//dgvPriority->DataSource = directDamages;
			}


			/*** 내진보강(후) ***/
			if (cboDirectDamage->SelectedIndex == 1) {
				array<String^>^ columns = { "시설물", "노선", "50년", "100년", "475년", "1000년" };
				DataTable^ newTable = NewTable(columns);

				//newTable->Rows[1]->ItemArray[5] = 1;


				for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
					DataRow^ newRow = newTable->NewRow();
					DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
					String^ componentID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ link = row[NetworkComponent::COL_LINK_ID]->ToString();

					newRow[0] = componentID;
					newRow[1] = link;

					//그래프 X축
					array<double>^ arrDataY = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
					array<double>^ arrDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

					for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++) {
						///////////////////////////////////////////////////////////////////////////////
						// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
						///////////////////////////////////////////////////////////////////////////////
						//int trafficSecnarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1);
						int odLocalIndex = 1;
						int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, odLocalIndex);

						double value = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, componentID);
						// 재현주기는 2번칼럼 부터 재현주기1(예50년), 재현주기2(예,100년), 재현주기3(예,475년), 재현주기4(예,1000년) 순으로 입력됨
						newRow[i + 2] = value;


						arrDataY[i] = value;

						/////////////////////////////////////////////////////////
						//간접피해 계산
						/////////////////////////////////////////////////////////
						double sumTrafficCost = 0;
						array<double>^ beforeAdditionalCostData;
						for (int a = 0; a < this->m_dataSet->ODZoneParamData->Rows->Count; a++) {
							int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, 1, a + 1);
							// 0 = 내진보강전, 1= 내진보강후
							beforeAdditionalCostData = CalculateAdditionalCost(1, localTrafficScenarioNo);
							int recoveryDayCount = beforeAdditionalCostData->Length;
							for (int b = 0; b < recoveryDayCount; b++) {
								sumTrafficCost += beforeAdditionalCostData[b];
							}
						}
						arrDataY2[i] = sumTrafficCost;

					}

					/**** Dict에 저장 ****/
					//직접
					if (!directCompoAfterDict->ContainsKey(componentID)) {
						directCompoAfterDict->Add(componentID, arrDataY);
					}

					array<double>^ tmpY = (array<double>^)arrDataY->Clone();
					if (directLinkAfterDict->ContainsKey(link)) {
						array<double>^ arr = directLinkAfterDict[link];
						for (int n = 0; n < tmpY->Length; n++) {
							//arrDataY[n] += arr[n];
							arr[n] += tmpY[n];
						}
						directLinkAfterDict[link] = arr;
					}
					else {
						directLinkAfterDict->Add(link, tmpY);
					}
					

					//간접
					if (!inDirectCompoAfterDict->ContainsKey(componentID)) {
						inDirectCompoAfterDict->Add(componentID, arrDataY2);
					}

					array<double>^ tmpY2 = (array<double>^)arrDataY2->Clone();
					if (inDirectLinkAfterDict->ContainsKey(link)) {
						array<double>^ arr = inDirectLinkAfterDict[link];
						for (int n = 0; n < tmpY2->Length; n++) {
							//arrDataY2[n] += arr[n];
							arr[n] += tmpY2[n];
						}
						inDirectLinkAfterDict[link] = arr;
					}
					else {
						inDirectLinkAfterDict->Add(link, tmpY2);
					}



					newTable->Rows->Add(newRow);
				}

				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = newTable->Rows[i];
					//directDamages[i] = double::Parse(newRow->ItemArray[indexRecurrencePeriod]->ToString());
					//String^ temp = newRow[indexRecurrencePeriod]->ToString();
					//int k=1;
				}

				dgvDirectDamage->DataSource = newTable;
				//dgvPriority->DataSource = directDamages;

			}
		}






		void UpdatePriority() {


			// 직접피해 기준으로 내진성능관리 우선순위를 선정하는 경우 
			if (this->cboPriority->SelectedIndex == 0) {

				//콤보박스로 부터 선택된 재현주기를 칼럼의 명칭으로 지정
				String^ seismicPeriod = cboSeismicPeriod->SelectedItem->ToString() + "년";
				array<String^>^ columns = { "시설물", "노선", "보수비용" };
				DataTable^ unSortTable = NewTable(columns);

				//재현주기별 시설물별 직접피해비용 산출
				array<double>^ directDamages = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);

				for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
					DataRow^ newRow = unSortTable->NewRow();
					DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
					String^ componentID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ link = row[NetworkComponent::COL_LINK_ID]->ToString();

					newRow[0] = componentID;
					newRow[1] = link;

					///////////////////////////////////////////////////////////////////////////////
					// 직접피해 계산: 직접피해는 od zone과 관계없으므로, 대표 odIndex값 "1"을 사용한다. 
					///////////////////////////////////////////////////////////////////////////////

					//내진보강(후) 직접피해 계산
					/*
					int odLocalIndex = 1;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
					double value = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, componentID);
					*/

					// 내진보강(전) 직접피해 계산		
					// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
					int odLocalIndex = 1;
					int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
					String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
					DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];
					double value = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());

					newRow[2] = value;
					unSortTable->Rows->Add(newRow);
					directDamages[j] = value;

				}

				//직접피해비용 크기 순서로 리스팅
				// sorting된 행렬 저장 테이블 지정
				array<int>^ order = gcnew array<int>(this->m_dataSet->NetworkCompnentData->Rows->Count);
				order = DescenderOrder(directDamages);

				//시설물별 직접피해비용을 크기순서(내림차순) 배열
				DataTable^ sortTable = NewTable(columns);
				array<double>^ sortDirectDamages = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = sortTable->NewRow();
					for (int j = 0; j < unSortTable->Columns->Count; j++) {
						newRow[j] = unSortTable->Rows[order[i]]->ItemArray[j];
					}
					sortTable->Rows->Add(newRow);
					sortDirectDamages[i] = directDamages[order[i]];
				}

				// 전체 시설물 직접피해비
				double totalDirectCost = 0;
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					totalDirectCost += directDamages[i];
				}

				//콤보박스로 부터 선택된 재현주기를 칼럼의 명칭으로 지정
				array<String^>^ damageColumns = { "0%~100%", "0%~50%", "0%~25%", "0%~10%", "0%~5%" };
				DataTable^ componentPriorityTable = NewTable(damageColumns);
				// 전체피해대비 피해율
				array<double>^ damageRatio = gcnew array<double>(5);
				damageRatio[0] = totalDirectCost * 0.05;
				damageRatio[1] = totalDirectCost * 0.1;
				damageRatio[2] = totalDirectCost * 0.25;
				damageRatio[3] = totalDirectCost * 0.50;
				damageRatio[4] = totalDirectCost;

				double costSum = sortDirectDamages[0];
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = componentPriorityTable->NewRow();
					if (costSum <= damageRatio[0]) {
						newRow[4] = sortTable->Rows[i]->ItemArray[0];
						newRow[3] = sortTable->Rows[i]->ItemArray[0];
						newRow[2] = sortTable->Rows[i]->ItemArray[0];
						newRow[1] = sortTable->Rows[i]->ItemArray[0];
						newRow[0] = sortTable->Rows[i]->ItemArray[0];
					}
					else if (damageRatio[0] < costSum && costSum <= damageRatio[1]) {
						newRow[3] = sortTable->Rows[i]->ItemArray[0];
						newRow[2] = sortTable->Rows[i]->ItemArray[0];
						newRow[1] = sortTable->Rows[i]->ItemArray[0];
						newRow[0] = sortTable->Rows[i]->ItemArray[0];
					}

					else if (damageRatio[1] < costSum && costSum <= damageRatio[2]) {
						newRow[2] = sortTable->Rows[i]->ItemArray[0];
						newRow[1] = sortTable->Rows[i]->ItemArray[0];
						newRow[0] = sortTable->Rows[i]->ItemArray[0];
					}
					else if (damageRatio[2] < costSum && costSum <= damageRatio[3]) {
						newRow[1] = sortTable->Rows[i]->ItemArray[0];
						newRow[0] = sortTable->Rows[i]->ItemArray[0];
					}
					else if (damageRatio[3] < costSum) {
						newRow[0] = sortTable->Rows[i]->ItemArray[0];
					}
					if (i != this->m_dataSet->NetworkCompnentData->Rows->Count - 1) {
						costSum = costSum + sortDirectDamages[i + 1];
					}
					componentPriorityTable->Rows->Add(newRow);
				}

				//선택된 지진소스, 재현주기에 대한 Sorting된 직접피해비 화면 표출력
				dgvPriority->DataSource = nullptr;//이전설정이 남아서 초기화함
				dgvPriority->DataSource = componentPriorityTable;

			}

			// 노선 직접피해 기준으로 내진성능관리 우선순위를 결정하는 경우
			if (this->cboPriority->SelectedIndex == 1) {

				// 시뮬레이션 단계 (0= 내진보강전 단계, 1= 내진보강후 단계)
				int stageIndex = 0;
				array<int, 2>^ odComponentFull = CalculateODComponent(stageIndex);

				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = odComponentFull->Length / (this->m_dataSet->ODZoneParamData->Rows->Count * 2);
				array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					for (int j = 0; j < maxIndex; j++) {
						directCostOrder[i] += odComponentFull[j, i * 2 + 1];
					}
				}
				directCostOrder = DescenderOrder(directCostOrder);

				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i] = "OD" + String::Format("{0}", directCostOrder[i] + 1) + " 시설물";
				}
				DataTable^ odPriorityTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();
					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						newRow[j] = odComponentFull[i, directCostOrder[j] * 2];
						//newRow[j * 2 + 1] = odComponentFull[i, directCostOrder[j] * 2 + 1];
					}
					odPriorityTable->Rows->Add(newRow);
				}

				dgvPriority->DataSource = nullptr;//이전설정이 남아서 초기화함
				dgvPriority->DataSource = odPriorityTable;
			}// end of selection 1 : 노선의 직접피해별 우선순위 선정 


			// 노선의 간접피해 기준으로 내진성능관리 우선순위 결정
			if (this->cboPriority->SelectedIndex == 2) {

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalIndirectCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalIndirectCost[odIndex] = CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ indirectCostOrder = gcnew array<int>(totalIndirectCost->Length);
				indirectCostOrder = AscenderOrder(totalIndirectCost);


				/*int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index

				//array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
					if (maxIndex < normalOutputSummary->Volumes->Count) {
						maxIndex = normalOutputSummary->Volumes->Count;
					}
				}

				array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

					int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

					// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

					// 노선에 속해 있는 시설물 리스트들
					for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
					{
						String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

						if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
							odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
							odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
							//directCostOrder[odIndex] += odComponentFull[compoIndex, odIndex * 2 + 1];

							compoIndex++;
						}
					}// 전체 시설물 개수에 대한 for()
				}// 전체 OD 개수에 대한 for()
				*/

				// stageIndex: 보강전(=0), 현재상태(=1)
				//array<int, 2>^ odComponentFull = CalculateODComponent();
				array<int, 2>^ odComponentFull = CalculateODComponent(stageIndex);

				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = odComponentFull->Length / (this->m_dataSet->ODZoneParamData->Rows->Count * 2);

				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i] = "OD" + String::Format("{0}", indirectCostOrder[i] + 1) + " 시설물";
				}
				DataTable^ odPriorityTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();
					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						newRow[j] = odComponentFull[i, indirectCostOrder[j] * 2];
						//newRow[j * 2 + 1] = odComponentFull[i, directCostOrder[j] * 2 + 1];

					}

					odPriorityTable->Rows->Add(newRow);
				}

				dgvPriority->DataSource = nullptr;//이전설정이 남아서 초기화함
				dgvPriority->DataSource = odPriorityTable;

			}


			// 노선의 통합피해 기준으로 내진성능관리 우선순위 결정
			if (this->cboPriority->SelectedIndex == 3) {

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalCost[odIndex] = CalculateDirectCost(stageIndex, odIndex) + CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ totalCostOrder = gcnew array<int>(totalCost->Length);
				totalCostOrder = AscenderOrder(totalCost);

				/*
				int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index

				// OD에 해당하는 시설물 번호 작성
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
					if (maxIndex < normalOutputSummary->Volumes->Count) {
						maxIndex = normalOutputSummary->Volumes->Count;
					}
				}

				array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

					int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

					// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

					// 노선에 속해 있는 시설물 리스트들
					for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
					{
						String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

						if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
							odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
							odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
							//directCostOrder[odIndex] += odComponentFull[compoIndex, odIndex * 2 + 1];

							compoIndex++;
						}
					}// 전체 시설물 개수에 대한 for()
				}// 전체 OD 개수에 대한 for()

				*/

				//stageIndex: 보강전(=0), 현재상태(=1)
				array<int, 2>^ odComponentFull = CalculateODComponent(stageIndex);

				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = odComponentFull->Length / (this->m_dataSet->ODZoneParamData->Rows->Count * 2);


				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i] = "OD" + String::Format("{0}", totalCostOrder[i] + 1) + " 시설물";
				}
				DataTable^ odPriorityTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();
					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						newRow[j] = odComponentFull[i, totalCostOrder[j] * 2];
						//newRow[j * 2 + 1] = odComponentFull[i, directCostOrder[j] * 2 + 1];

					}

					odPriorityTable->Rows->Add(newRow);
				}

				dgvPriority->DataSource = nullptr;//이전설정이 남아서 초기화함
				dgvPriority->DataSource = odPriorityTable;
			}

		} //end of UpdatePriority()


		void UpdateBudget() {
			// 시설별 직접피해 기준으로 예산선정 
			if (this->cboBudget->SelectedIndex == 0) {

				//콤보박스로 부터 선택된 재현주기를 칼럼의 명칭으로 지정
				String^ seismicPeriod = cboSeismicPeriod->SelectedItem->ToString() + "년";
				array<String^>^ columns = { "시설물", "노선", "보수비용" };
				DataTable^ unSortTable = NewTable(columns);

				//재현주기별 시설물별 직접피해비용 산출
				array<double>^ directDamages = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);

				for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
					DataRow^ newRow = unSortTable->NewRow();
					DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
					String^ componentID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					String^ link = row[NetworkComponent::COL_LINK_ID]->ToString();

					newRow[0] = componentID;
					newRow[1] = link;

					///////////////////////////////////////////////////////////////////////////////
					// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
					///////////////////////////////////////////////////////////////////////////////

					// 내진보강(전) 직접피해 계산	
					/*
					int odLocalIndex = 1;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
					double value = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, componentID);
					*/

					// 내진보강(전) 직접피해 계산		
					int odLocalIndex = 1;
					int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
					String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
					DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];
					double value = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());


					newRow[2] = value;
					unSortTable->Rows->Add(newRow);

					directDamages[j] = value;

				}

				//직접피해비용 크기 순서로 리스팅
				// sorting된 행렬 저장 테이블 지정
				array<int>^ order = gcnew array<int>(this->m_dataSet->NetworkCompnentData->Rows->Count);
				order = DescenderOrder(directDamages);

				//시설물별 직접피해비용을 크기순서(내림차순) 배열
				DataTable^ sortTable = NewTable(columns);
				array<double>^ sortDirectDamages = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = sortTable->NewRow();
					for (int j = 0; j < unSortTable->Columns->Count; j++) {
						newRow[j] = unSortTable->Rows[order[i]]->ItemArray[j];
					}
					sortTable->Rows->Add(newRow);
					sortDirectDamages[i] = directDamages[order[i]];
				}

				// 전체 시설물 직접피해비
				double totalDirectCost = 0;
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					totalDirectCost += directDamages[i];
				}

				//콤보박스로 부터 선택된 재현주기를 칼럼의 명칭으로 지정
				//array<String^>^ damageColumns = { "0%~5%", "0%~10%", "0%~25%", "0%~50%", "0%~100%" };
				array<String^>^ damageColumns = { "0%~100%", "0%~50%", "0%~25%", "0%~10%", "0%~5%" };
				DataTable^ budgetTable = NewTable(damageColumns);
				// 전체피해대비 피해율
				array<double>^ damageRatio = gcnew array<double>(5);
				damageRatio[0] = totalDirectCost * 0.05;
				damageRatio[1] = totalDirectCost * 0.1;
				damageRatio[2] = totalDirectCost * 0.25;
				damageRatio[3] = totalDirectCost * 0.50;
				damageRatio[4] = totalDirectCost;

				double costSum = sortDirectDamages[0];
				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
					DataRow^ newRow = budgetTable->NewRow();
					if (costSum <= damageRatio[0]) {
						//newRow[0] = sortTable->Rows[i]->ItemArray[0];
						newRow[4] = sortTable->Rows[i]->ItemArray[2];
						newRow[3] = sortTable->Rows[i]->ItemArray[2];
						newRow[2] = sortTable->Rows[i]->ItemArray[2];
						newRow[1] = sortTable->Rows[i]->ItemArray[2];
						newRow[0] = sortTable->Rows[i]->ItemArray[2];
					}
					else if (damageRatio[0] < costSum && costSum <= damageRatio[1]) {
						//newRow[0] = sortTable->Rows[i]->ItemArray[0];
						newRow[3] = sortTable->Rows[i]->ItemArray[2];
						newRow[2] = sortTable->Rows[i]->ItemArray[2];
						newRow[1] = sortTable->Rows[i]->ItemArray[2];
						newRow[0] = sortTable->Rows[i]->ItemArray[2];
					}

					else if (damageRatio[1] < costSum && costSum <= damageRatio[2]) {
						//newRow[0] = sortTable->Rows[i]->ItemArray[0];
						newRow[2] = sortTable->Rows[i]->ItemArray[2];
						newRow[1] = sortTable->Rows[i]->ItemArray[2];
						newRow[0] = sortTable->Rows[i]->ItemArray[2];
					}
					else if (damageRatio[2] < costSum && costSum <= damageRatio[3]) {
						//newRow[0] = sortTable->Rows[i]->ItemArray[0];
						newRow[1] = sortTable->Rows[i]->ItemArray[2];
						newRow[0] = sortTable->Rows[i]->ItemArray[2];
					}
					else if (damageRatio[3] < costSum) {
						//newRow[0] = sortTable->Rows[i]->ItemArray[0];
						newRow[0] = sortTable->Rows[i]->ItemArray[2];
					}
					if (i != this->m_dataSet->NetworkCompnentData->Rows->Count - 1) {
						costSum = costSum + sortDirectDamages[i + 1];
					}

					budgetTable->Rows->Add(newRow);
				}

				//선택된 지진소스, 재현주기에 대한 Sorting된 직접피해비 화면 표출력
				dgvBudget->DataSource = budgetTable;

			}


			// 노선별 직접피해 기준으로 예산선정
			if (this->cboBudget->SelectedIndex == 1) {

				/*
				array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);

				int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
					if (maxIndex < normalOutputSummary->Volumes->Count) {
						maxIndex = normalOutputSummary->Volumes->Count;
					}
				}

				// 시뮬레이션 단계 (0= 내진보강전 단계, 1= 내진보강후 단계)
				int stageIndex = 0;
				array<int, 2>^ odComponentFull = CalculateODComponent(stageIndex);
				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = odComponentFull->Length / (this->m_dataSet->ODZoneParamData->Rows->Count * 2);

				array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 2);

				directCostOrder = DescenderOrder(directCostOrder);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

					// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));

					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

					// 노선에 속해 있는 시설물 리스트들
					for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
					{
						String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);
						if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
							odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
							odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);
							directCostOrder[odIndex] += odComponentFull[compoIndex, odIndex * 2 + 1];
							compoIndex++;
						}
					}// 전체 시설물 개수에 대한 for()
				}// 전체 OD 개수에 대한 for()

				*/


				// 시뮬레이션 단계 (0= 내진보강전 단계, 1= 내진보강후 단계)
				int stageIndex = 0;
				//int stageIndex = 1;
				array<int, 2>^ odComponentFull = CalculateODComponent(stageIndex);

				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = odComponentFull->Length / (this->m_dataSet->ODZoneParamData->Rows->Count * 2);
				array<int>^ directCostOrder = gcnew array<int>(this->m_dataSet->ODZoneParamData->Rows->Count);

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					for (int j = 0; j < maxIndex; j++) {
						directCostOrder[i] += odComponentFull[j, i * 2 + 1];
					}
				}
				directCostOrder = DescenderOrder(directCostOrder);



				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i] = "OD" + String::Format("{0}", directCostOrder[i] + 1) + " Damage";
				}
				DataTable^ odPriorityTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();
					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						newRow[j] = odComponentFull[i, directCostOrder[j] * 2 + 1];
						//newRow[j * 2 + 1] = odComponentFull[i, directCostOrder[j] * 2 + 1];
					}
					odPriorityTable->Rows->Add(newRow);
				}

				dgvBudget->DataSource = odPriorityTable;


			}// end of selection 1 : 노선별 직접피해 기준으로 예산선정 


			// 노선별 간접피해 기준으로 예산산정
			if (this->cboBudget->SelectedIndex == 2) {

				int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

				array<String^>^ damageColumns = gcnew array<String^>(2);
				damageColumns[0] = "OD번호";
				damageColumns[1] = "필요예산";

				DataTable^ odPriorityTable = NewTable(damageColumns);


				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalIndirectCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalIndirectCost[odIndex] = CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ indirectCostOrder = gcnew array<int>(totalIndirectCost->Length);
				indirectCostOrder = AscenderOrder(totalIndirectCost);

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();

					newRow[0] = indirectCostOrder[i] + 1;
					newRow[1] = int(totalIndirectCost[indirectCostOrder[i]]);

					odPriorityTable->Rows->Add(newRow);

				}

				/*
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					double currentSumTrafficCost = 0;
					DataRow^ newRow = odPriorityTable->NewRow();

					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);
					array<double>^ currentAdditionalCostData = gcnew array<double>(recoveryStepCount);

					// 0 = 내진보강전, 1= 내진보강후
					//currentAdditionalCostData = CalculateAdditionalCost(1, localTrafficScenarioNo);
					currentAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);

					for (int j = 0; j < recoveryStepCount; j++)
					{
						currentSumTrafficCost += currentAdditionalCostData[j];
					}



					newRow[0] = i + 1;
					newRow[1] = int(currentSumTrafficCost);

					odPriorityTable->Rows->Add(newRow);
				}
				*/

				dgvBudget->DataSource = odPriorityTable;

			}

			// 노설별 총합피해 기준으로 예산산정
			if (this->cboBudget->SelectedIndex == 3) {

				//stageIndex: 보강전(=0), 현재상태(=1)
				int stageIndex = 0;
				int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

				array<String^>^ damageColumns = gcnew array<String^>(2);
				damageColumns[0] = "OD번호";
				damageColumns[1] = "필요예산";

				DataTable^ odPriorityTable = NewTable(damageColumns);

				array<double>^ totalCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalCost[odIndex] = CalculateDirectCost(stageIndex, odIndex) + CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ totalCostOrder = gcnew array<int>(totalCost->Length);
				totalCostOrder = AscenderOrder(totalCost);




				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = odPriorityTable->NewRow();
					newRow[0] = totalCostOrder[i] + 1;
					newRow[1] = int(totalCost[totalCostOrder[i]]);
					odPriorityTable->Rows->Add(newRow);
				}


				/*
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					//노선별 간접피해 계산
					double currentSumTrafficCost = 0;
					double currentSumDirectCost = 0;

					DataRow^ newRow = odPriorityTable->NewRow();
					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);
					array<double>^ currentAdditionalCostData = gcnew array<double>(recoveryStepCount);

					// stageIndex: 내진보강전(=0), 내진보강후(=1)
					currentAdditionalCostData = CalculateAdditionalCost(stageIndex, localTrafficScenarioNo);
					for (int j = 0; j < recoveryStepCount; j++){
						currentSumTrafficCost += currentAdditionalCostData[j];
					}

					//노선별 직접피해 계산

					// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);
					String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNo) / (unitScenarioStep) * (unitScenarioStep * 10)));
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];


					// 노선에 속해 있는 시설물 리스트들
					for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
					{
						String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

						if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
							//odComponentFull[compoIndex, odIndex * 2] = int::Parse(compID); // 시설물 번호
							//odComponentFull[compoIndex, odIndex * 2 + 1] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);

							currentSumDirectCost += this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);

							//compoIndex++;
							//if (compoIndex > maxIndex) { maxIndex = compoIndex; }
						}

					}// 전체 시설물 개수에 대한 for()

					newRow[0] = i + 1;
					newRow[1] = int(currentSumTrafficCost+ currentSumDirectCost);

					odPriorityTable->Rows->Add(newRow);
				}

				*/




				dgvBudget->DataSource = odPriorityTable;

			}

		}


		void UpdateEffect() {

			// 시설별 직접피해 기준으로 보강효과 계산 
			if (this->cboEffect->SelectedIndex == 0) {

				//////////////////////////////////
				// 기존시뮬레이젼 vs 신규시뮬레이션
				//////////////////////////////////
				String^ key = nullptr;
				array<String^>^ columns = { "compID", "보강전직접피해", "보강후직접피해", "보강효과" };
				DataTable^ directCostEffect = NewTable(columns);;

				// 도로망의 전체 직접피해(Direct Cost or Structure Cost) 계산은 OD와 관계없으므로,
				// 시나리오번호 계산함수 "GetTrafficScenarioNo()"에 사용되는 "odIndex+1"값은 기본값인 "1"을 사용
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, 1);

				key = String::Format("{0}", trafficScenarioNo);
				DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[key];

				for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
				{
					String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
					double afterDirectCost = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID);

					double beforeDirectCost;
					if (compID == beforeDirectCostTable->Rows[i]->ItemArray[0]->ToString()) {
						beforeDirectCost = double::Parse(beforeDirectCostTable->Rows[i]->ItemArray[1]->ToString());
					}
					else {
						for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
							if (compID == beforeDirectCostTable->Rows[j]->ItemArray[0]->ToString()) {
								beforeDirectCost = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());
							}
						}
					}

					DataRow^ newRow = directCostEffect->NewRow(); // create new row
					newRow["compID"] = compID;
					newRow["보강전직접피해"] = beforeDirectCost;
					newRow["보강후직접피해"] = afterDirectCost;
					newRow["보강효과"] = beforeDirectCost - afterDirectCost;

					directCostEffect->Rows->Add(newRow);
				}
				dgvEffect->DataSource = directCostEffect;

			}


			// 노선별 직접피해 기준으로 내진보강 효과계산
			if (this->cboEffect->SelectedIndex == 1) {

				// OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				int maxIndex = 0;
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					DataRow^ newRow = this->m_dataSet->ODZoneParamData->Rows[odIndex];
					int originNode = int::Parse(newRow[0]->ToString());
					int destinNode = int::Parse(newRow[1]->ToString());
					array<String^>^ roadLink = this->m_unistHelper->dijkstra(originNode, destinNode);
					int ODlinkCount = roadLink->Length;

					int compoCountIndex = 0;

					for (int i = 0; i < ODlinkCount; i++) {
						for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
							String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
							String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
							if (linkID == roadLink[i]) {
								compoCountIndex++;
							}
						}
					}

					if (maxIndex < compoCountIndex) {
						maxIndex = compoCountIndex;
					}
				}

				array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 4);
				// 여기서 int, 2 의 의미는 2개의 자연수 i와j가 있다는 것을 의미하며, [i,j]에서 i갯수=maxIndex, j갯수= OD수*3
				//                     OD1                                                                  :                                OD2                                               .....
				// [0,0]=1(시설번호) [0,1]=100(보강전 피해) [0,2]=100(보강후 피해) [0,3]=0  (보강효과) :  [0,4]= 5(시설번호)  [0,5]=1000(보강전 피해) [0,6]=100(보강후 피해)   [0,7]=100(보강효과)   
				// [1,0]=3(시설번호) [1,1]=50 (보강전 피해) [1,2]=50 (보강후 피해) [1,3]=0  (보강효과) :  [1,4]=14(시설번호)  [1,5]=200 (보강전 피해)  [1,6]=50 (보강후 피해)  [1,7]=100(보강효과) 
				//                  .                                                                  :                                .
				//                  .                                                                  :                                .

				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

					int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index 
					// 도로망의 전체 직접피해(Direct Cost or Structure Cost) 계산은 OD와 관계없으므로,
					int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, 1);
					String^ key = String::Format("{0}", trafficScenarioNo);
					DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[key];

					DataRow^ newRow = this->m_dataSet->ODZoneParamData->Rows[odIndex];
					int originNode = int::Parse(newRow[0]->ToString());
					int destinNode = int::Parse(newRow[1]->ToString());
					array<String^>^ roadLink = this->m_unistHelper->dijkstra(originNode, destinNode);
					int ODlinkCount = roadLink->Length;

					// OD별 노선수 -> 노선별 시설물개수 계산과정을 통해, OD에 포함된 (총)시설물 개수를 계산
					for (int i = 0; i < ODlinkCount; i++) {
						for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
							String^ compID = m_networkComponent->GetValue(j, NetworkComponent::COL_NETWORK_COMP_ID);
							String^ linkID = m_networkComponent->GetValue(j, NetworkComponent::COL_LINK_ID);
							if (linkID == roadLink[i]) {
								odComponentFull[compoIndex, odIndex * 4] = int::Parse(compID); // 시설물 번호
								odComponentFull[compoIndex, odIndex * 4 + 1] = double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());            // 내진보강전 직접피해규모                                                                                   //내진보강전 직접피해규모
								odComponentFull[compoIndex, odIndex * 4 + 2] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, compID); // 내진보강후 직접피해규모
								compoIndex++; //OD노선에 포함됨 시설물 index, 예) 전체시설물 갯수 27개중 8개가 포함됨
							}
						}
					}

				}// 전체 OD 개수에 대한 for()	


				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count * 4);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i * 4] = "OD" + String::Format("{0}   ", i + 1) + " 시설번호";
					damageColumns[i * 4 + 1] = "OD" + String::Format("{0}   ", i + 1) + " 보강(전)직접피해";
					damageColumns[i * 4 + 2] = "OD" + String::Format("{0}   ", i + 1) + " 보강(후)직접피해";
					damageColumns[i * 4 + 3] = "OD" + String::Format("{0}   ", i + 1) + " 보강효과";

				}
				DataTable^ odEffectTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odEffectTable->NewRow();

					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						//newRow[j] = odComponentFull[i, j];
						newRow[j * 4] = odComponentFull[i, j * 4];
						newRow[j * 4 + 1] = odComponentFull[i, j * 4 + 1];
						newRow[j * 4 + 2] = odComponentFull[i, j * 4 + 2];
						newRow[j * 4 + 3] = odComponentFull[i, j * 4 + 1] - odComponentFull[i, j * 4 + 2];
					}

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;


				/*
				int maxIndex = 0;   // OD별 경로에 속해있는 시설물 갯수 중 큰 값으로 결과테이블의 row(수)를 정의하기 위한 Index
				// OD별 노선직접피해비용
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;
					//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, odIndex + 1);
					String^ normScenarioIndex = String::Format("{0}", odIndex * unitScenarioStep * 10);
					//OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];
					OutputSummary^ normalOutputSummary = this->beforeNeXTAOutputSummaryDictionary[normScenarioIndex];
					if (maxIndex < normalOutputSummary->Volumes->Count) {
						maxIndex = normalOutputSummary->Volumes->Count;
					}
				}

				array<int, 2>^ odComponentFull = gcnew array<int, 2>(maxIndex, this->m_dataSet->ODZoneParamData->Rows->Count * 4);
				// 여기서 int, 2 의 의미는 2개의 자연수 i와j가 있다는 것을 의미하며, [i,j]에서 i갯수=maxIndex, j갯수= OD수*3
				//                     OD1                                                                  :                                OD2                                               .....
				// [0,0]=1(시설번호) [0,1]=100(보강전 피해) [0,2]=100(보강후 피해) [0,3]=0  (보강효과) :  [0,4]= 5(시설번호)  [0,5]=1000(보강전 피해) [0,6]=100(보강후 피해)   [0,7]=100(보강효과)
				// [1,0]=3(시설번호) [1,1]=50 (보강전 피해) [1,2]=50 (보강후 피해) [1,3]=0  (보강효과) :  [1,4]=14(시설번호)  [1,5]=200 (보강전 피해)  [1,6]=50 (보강후 피해)  [1,7]=100(보강효과)
				//                  .                                                                  :                                .
				//                  .                                                                  :                                .

				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {

					int compoIndex = 0; //시설물명(번호)에 대한 순서를 매김하기 위한 Index

					// OD별 정상도로기능 상태시의 교통해석 결과 "normalOutputSummary"
					//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
					int unitScenarioStep = this->m_dataSet->UnitScenarioNum;

					// 도로망의 전체 직접피해(Direct Cost or Structure Cost) 계산은 OD와 관계없으므로,
					// 시나리오번호 계산함수 "GetTrafficScenarioNo()"에 사용되는 "odIndex+1"값은 기본값인 "1"을 사용
					int trafficScenarioNoForStructureCost = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, 1);

					String^ normScenarioIndex = String::Format("{0}", int((trafficScenarioNoForStructureCost) / (unitScenarioStep) * (unitScenarioStep * 10)));
					OutputSummary^ normalOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];

					// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
					String^ localKey = String::Format("{0}", trafficScenarioNoForStructureCost);
					DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];


					// 노선에 속해 있는 시설물 리스트들에 대한 (총)직접피해비용 계산
					for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++)
					{
						String^ compID = m_networkComponent->GetValue(i, NetworkComponent::COL_NETWORK_COMP_ID);
						String^ linkID = m_networkComponent->GetValue(i, NetworkComponent::COL_LINK_ID);

						// for 문을 통해 전체시설물과 OD노선에 속하는 시설물을 비교하여, 포함된 시설물의 직접피해 비용을 저장
						if (normalOutputSummary->Volumes->ContainsKey(linkID)) {
							odComponentFull[compoIndex, odIndex * 4] = int::Parse(compID); // 시설물 번호
							odComponentFull[compoIndex, odIndex * 4 + 1] = double::Parse(beforeDirectCostTable->Rows[i]->ItemArray[1]->ToString());            // 내진보강전 직접피해규모                                                                                   //내진보강전 직접피해규모
							odComponentFull[compoIndex, odIndex * 4 + 2] = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNoForStructureCost, compID); // 내진보강후 직접피해규모
							compoIndex++; //OD노선에 포함됨 시설물 index, 예) 전체시설물 갯수 27개중 8개가 포함됨
						}
					}// 전체 시설물 개수에 대한 for()

				}// 전체 OD 개수에 대한 for()


				//array<String^>^ damageColumns = { "OD(i) Component", "OD(i) Damage", "OD(i++) Component", "OD(i++) Damage"};
				array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count * 4);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					damageColumns[i * 4]     = "OD" + String::Format("{0}   ", i + 1) + " 시설번호";
					damageColumns[i * 4 + 1] = "OD" + String::Format("{0}   ", i + 1) + " 보강(전)직접피해";
					damageColumns[i * 4 + 2] = "OD" + String::Format("{0}   ", i + 1) + " 보강(후)직접피해";
					damageColumns[i * 4 + 3] = "OD" + String::Format("{0}   ", i + 1) + " 보강효과";

				}
				DataTable^ odEffectTable = NewTable(damageColumns);

				for (int i = 0; i < maxIndex; i++) {
					DataRow^ newRow = odEffectTable->NewRow();

					for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						//newRow[j] = odComponentFull[i, j];
						newRow[j * 4] = odComponentFull[i, j * 4];
						newRow[j * 4 + 1] = odComponentFull[i, j * 4 + 1];
						newRow[j * 4 + 2] = odComponentFull[i, j * 4 + 2];
						newRow[j * 4 + 3] = odComponentFull[i, j * 4 + 1]- odComponentFull[i, j * 4 + 2];
					}

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;
				*/


			}// end of selection 1 : 노선별 직접피해 기준으로 예산선정 


			// 노선별 간접피해규모
			if (this->cboEffect->SelectedIndex == 2) {

				int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

				array<String^>^ damageColumns = gcnew array<String^>(4);
				damageColumns[0] = "OD번호";
				damageColumns[1] = "보강(전)간접피해";
				damageColumns[2] = "보강(후)간접피해";
				damageColumns[3] = "내진보강    효과";

				DataTable^ odEffectTable = NewTable(damageColumns);

				//double beforeSumTrafficCost = 0;
				//double currentSumTrafficCost = 0;

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalIndirectCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalIndirectCost[odIndex] = CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					double beforeSumTrafficCost = 0;
					double currentSumTrafficCost = 0;
					DataRow^ newRow = odEffectTable->NewRow();

					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);
					array<double>^ beforeAdditionalCostData = gcnew array<double>(recoveryStepCount);
					array<double>^ currentAdditionalCostData = gcnew array<double>(recoveryStepCount);

					// 0 = 내진보강전, 1= 내진보강후
					beforeAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);
					currentAdditionalCostData = CalculateAdditionalCost(1, localTrafficScenarioNo);


					for (int j = 0; j < recoveryStepCount; j++)
					{
						beforeSumTrafficCost += beforeAdditionalCostData[j];
						currentSumTrafficCost += currentAdditionalCostData[j];
					}

					newRow[0] = i + 1;
					//newRow[1] = int(beforeSumTrafficCost);
					newRow[1] = int(totalIndirectCost[i]);
					newRow[2] = int(currentSumTrafficCost);
					newRow[3] = int(beforeSumTrafficCost - currentSumTrafficCost);

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;


			}


			// 경제(ECO)지수 기준으로 내진보강 효과 계산
			if (this->cboEffect->SelectedIndex == 3) {

				array<String^>^ indiceColumns = gcnew array<String^>(4);
				indiceColumns[0] = "OD번호";
				indiceColumns[1] = "보강(전)경제지수";
				indiceColumns[2] = "보강(후)경제지수";
				indiceColumns[3] = "내진보강 효과(%)";

				DataTable^ odEffectTable = NewTable(indiceColumns);


				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = odEffectTable->NewRow();

					double beforeEconomicIndiceData;
					double currentEconomicIndiceData;
					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);

					newRow[0] = i + 1;
					newRow[1] = beforeEconomicIndiceData = CalculateIndiceECO(localTrafficScenarioNo, beforeNeXTAOutputSummaryDictionary);
					newRow[2] = currentEconomicIndiceData = CalculateIndiceECO(localTrafficScenarioNo, this->m_dataSet->NeXTAOutputSummaryDictionary);
					newRow[3] = (double::Parse(newRow[2]->ToString()) - double::Parse(newRow[1]->ToString())) * 100;

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;


			}


			// 연결(CON)지수 기준으로 내진보강 효과 계산
			if (this->cboEffect->SelectedIndex == 4) {

				array<String^>^ indiceColumns = gcnew array<String^>(4);
				indiceColumns[0] = "OD번호";
				indiceColumns[1] = "보강(전)연결지수";
				indiceColumns[2] = "보강(후)연결지수";
				indiceColumns[3] = "내진보강 효과(%)";

				DataTable^ odEffectTable = NewTable(indiceColumns);


				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = odEffectTable->NewRow();

					double beforeConnectIndiceData;
					double currentConnectIndiceData;
					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);

					// calculateIndiceCON(0,xx,xx)는 보강전 CON계산,  calculateIndiceCON(1,xx,xx)는 현재상태 CON계산, 
					newRow[0] = i + 1;
					newRow[1] = beforeConnectIndiceData = CalculateIndiceCON(0, localTrafficScenarioNo, beforeNeXTAOutputSummaryDictionary);
					newRow[2] = currentConnectIndiceData = CalculateIndiceCON(1, localTrafficScenarioNo, this->m_dataSet->NeXTAOutputSummaryDictionary);
					newRow[3] = (double::Parse(newRow[2]->ToString()) - double::Parse(newRow[1]->ToString())) * 100;

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;


			}


			// 환경(ENV)지수 기준으로 내진보강 효과 계산
			if (this->cboEffect->SelectedIndex == 5) {

				array<String^>^ indiceColumns = gcnew array<String^>(4);
				indiceColumns[0] = "OD번호";
				indiceColumns[1] = "보강(전)환경지수";
				indiceColumns[2] = "보강(후)환경지수";
				indiceColumns[3] = "내진보강 효과(%)";

				DataTable^ odEffectTable = NewTable(indiceColumns);


				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = odEffectTable->NewRow();

					double beforeEnvironmentalIndiceData;
					double currentEnvironmentalIndiceData;
					int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboSeismicPeriod->SelectedIndex, cboSample->SelectedIndex + 1, i + 1);

					newRow[0] = i + 1;
					newRow[1] = beforeEnvironmentalIndiceData = CalculateIndiceENV(localTrafficScenarioNo, beforeNeXTAOutputSummaryDictionary);
					newRow[2] = currentEnvironmentalIndiceData = CalculateIndiceENV(localTrafficScenarioNo, this->m_dataSet->NeXTAOutputSummaryDictionary);
					newRow[3] = (double::Parse(newRow[2]->ToString()) - double::Parse(newRow[1]->ToString())) * 100;

					odEffectTable->Rows->Add(newRow);
				}

				dgvEffect->DataSource = odEffectTable;


			}


		}


		void UpdateSRoad() {

			// 시설별 직접피해 기준으로 방재도로 선정 
			if (this->cboSRoad->SelectedIndex == 0) {

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalDirectCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalDirectCost[odIndex] = CalculateDirectCost(stageIndex, odIndex);
				}
				array<int>^ costOrder = gcnew array<int>(totalDirectCost->Length);
				costOrder = AscenderOrder(totalDirectCost);

				array<String^>^ SRoadColumns = gcnew array<String^>(2);
				SRoadColumns[0] = "OD번호";
				SRoadColumns[1] = "직접피해";
				DataTable^ SRoadDamage = NewTable(SRoadColumns);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = SRoadDamage->NewRow();
					newRow[0] = costOrder[i] + 1;
					newRow[1] = int(totalDirectCost[costOrder[i]]);
					SRoadDamage->Rows->Add(newRow);
				}

				dgvSRoad->DataSource = SRoadDamage;

			}// end of selection 1 : 노선별 직접피해 기준으로 예산선정 

			 // 노선별 간접피해 기준으로 방재도로 선정
			if (this->cboSRoad->SelectedIndex == 1) {

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalIndirectCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalIndirectCost[odIndex] = CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ costOrder = gcnew array<int>(totalIndirectCost->Length);
				costOrder = AscenderOrder(totalIndirectCost);

				array<String^>^ SRoadColumns = gcnew array<String^>(2);
				SRoadColumns[0] = "OD번호";
				SRoadColumns[1] = "간접피해";
				DataTable^ SRoadDamage = NewTable(SRoadColumns);

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = SRoadDamage->NewRow();
					newRow[0] = costOrder[i] + 1;
					newRow[1] = int(totalIndirectCost[costOrder[i]]);
					SRoadDamage->Rows->Add(newRow);
				}
				dgvSRoad->DataSource = SRoadDamage;

			}// end of selection 1 : 노선별 직접피해 기준으로 예산선정 

			// 노선별 총합피해 기준으로 방재도로 선정
			if (this->cboSRoad->SelectedIndex == 2) {

				int stageIndex = 0; //보강전(0), 현재상태(1)
				array<double>^ totalCost = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					totalCost[odIndex] = CalculateDirectCost(stageIndex, odIndex) + CalculateIndirectCost(stageIndex, odIndex);
				}// 전체 OD 개수에 대한 for()	
				array<int>^ costOrder = gcnew array<int>(totalCost->Length);
				costOrder = AscenderOrder(totalCost);

				array<String^>^ SRoadColumns = gcnew array<String^>(2);
				SRoadColumns[0] = "OD번호";
				SRoadColumns[1] = "총합피해";
				DataTable^ SRoadDamage = NewTable(SRoadColumns);

				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = SRoadDamage->NewRow();
					newRow[0] = costOrder[i] + 1;
					newRow[1] = int(totalCost[costOrder[i]]);
					SRoadDamage->Rows->Add(newRow);
				}
				dgvSRoad->DataSource = SRoadDamage;

			}

			// 노선별 보강효과 기준으로 방재도로 선정
			if (this->cboSRoad->SelectedIndex == 3) {
				//int stageIndex = 1; //보강전(0), 현재상태(1)
				array<double>^ DirectCostEffect = gcnew array<double>(this->m_dataSet->ODZoneParamData->Rows->Count);
				for (int odIndex = 0; odIndex < this->m_dataSet->ODZoneParamData->Rows->Count; odIndex++) {
					DirectCostEffect[odIndex] = CalculateDirectCost(0, odIndex) - CalculateDirectCost(1, odIndex);
				}
				array<int>^ costOrder = gcnew array<int>(DirectCostEffect->Length);
				costOrder = DescenderOrder(DirectCostEffect);

				array<String^>^ SRoadColumns = gcnew array<String^>(2);
				SRoadColumns[0] = "OD번호";
				SRoadColumns[1] = "보강효과";
				DataTable^ SRoadDamage = NewTable(SRoadColumns);
				for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
					DataRow^ newRow = SRoadDamage->NewRow();
					newRow[0] = costOrder[i] + 1;
					newRow[1] = int(DirectCostEffect[costOrder[i]]);
					SRoadDamage->Rows->Add(newRow);
				}

				dgvSRoad->DataSource = SRoadDamage;
			}

		}




	private: System::Void Step13Form_Load(System::Object^ sender, System::EventArgs^ e) {

		// set combobox datasource for seismic source 
		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		// set combobox datasource for sample
		this->cboSample->Items->AddRange(this->m_dataSet->TrafficScenarioSamples);
		this->cboSample->SelectedIndex = 0;

		// set combobox datasource for seismic recurrency
		this->cboSeismicPeriod->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboSeismicPeriod->SelectedIndex = 0;


		// set table for components of road-network
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		//this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		// set combobox cboPriority
		this->cboPriority->SelectedIndex = 0;
		// set combobox cboBudget
		this->cboBudget->SelectedIndex = 0;
		// set combobox cboEffect
		this->cboEffect->SelectedIndex = 0;
		// set combobox cboSRoad
		this->cboSRoad->SelectedIndex = 0;

		// set combobox cboDirectDamage
		this->cboDirectDamage->SelectedIndex = 0;
		// set combobox cboIndirectDamage
		//this->cboIndirectDamage->SelectedIndex = 0;




		// 그래프 조건 01 
		this->cboGrpCondi01->SelectedIndex = 1;
		this->m_chartType = "A1";//맨처음 chart type

		// 그래프 조건 02
		array<String^>^ damageColumns = gcnew array<String^>(this->m_dataSet->ODZoneParamData->Rows->Count + 1);
		damageColumns[0] = "--OD시설물 선택--";
		for (int i = 1; i < this->m_dataSet->ODZoneParamData->Rows->Count + 1; i++) {
			damageColumns[i] = "OD" + String::Format("{0}", i) + " 시설물";
		};
		this->cboGrpCondi02->Items->AddRange(damageColumns);
		this->cboGrpCondi02->SelectedIndex = 0;




		beforeRehabSimulationResult();
		DrawCharts();
		UpdateComponentDirectDamage();
		UpdatePriority();
		UpdateBudget();
		UpdateEffect();
		UpdateSRoad();
		OnSaveDataChanged();

	}

	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
		UpdateComponentDirectDamage();
		UpdatePriority();
		UpdateBudget();
		UpdateEffect();
		UpdateSRoad();
	}

	private: System::Void cboSample_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
		UpdateComponentDirectDamage();
		UpdatePriority();
		UpdateBudget();
		UpdateEffect();
		UpdateSRoad();
	}

	private: System::Void cboSeismicPeriod_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
		UpdateComponentDirectDamage();
		UpdatePriority();
		UpdateBudget();
		UpdateEffect();
		UpdateSRoad();
	}

	private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (m_chartDataX1 != nullptr && m_chartDataY1 != nullptr && m_chartDataY2 != nullptr) {
			DrawCharts();
		}
	}



	private: System::Void cboPriority_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		UpdatePriority();
	}

	private: System::Void cboBudget_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		UpdateBudget();
	}

	private: System::Void cboEffect_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		UpdateEffect();
	}

	private: System::Void cboSRoad_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		UpdateSRoad();
	}



	private: System::Void dgvDirectDamage_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Set grid row number and style
		int i = 1;
		for each (DataGridViewRow ^ row in dgvDirectDamage->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvDirectDamage->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvDirectDamage->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvDirectDamage->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvDirectDamage->EnableHeadersVisualStyles = false;
	}


	private: System::Void dgvPriority_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {

		int i = 1;
		for each (DataGridViewRow ^ row in dgvPriority->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvPriority->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvPriority->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvPriority->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvPriority->EnableHeadersVisualStyles = false;

		//그리드 컬럼 순서 변경 - Test 
		/*
		DataGridViewColumnCollection^ aa = this->dgvPriority->Columns;
		this->dgvPriority->Columns["0%~50%"]->DisplayIndex = 0;
		this->dgvPriority->Columns["0%~25%"]->DisplayIndex = 1;
		this->dgvPriority->Columns["0%~10%"]->DisplayIndex = 2;
		this->dgvPriority->Columns["0%~5%"]->DisplayIndex = 3;
		this->dgvPriority->Columns["0%~100%"]->DisplayIndex = 4;
		*/


	}



	private: System::Void dgvBudget_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		int i = 1;
		for each (DataGridViewRow ^ row in dgvBudget->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvBudget->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvBudget->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvBudget->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvBudget->EnableHeadersVisualStyles = false;
	}

	private: System::Void dgvEffect_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		int i = 1;
		for each (DataGridViewRow ^ row in dgvEffect->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvEffect->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvEffect->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvEffect->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvEffect->EnableHeadersVisualStyles = false;
	}

	private: System::Void dgvSRoad_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		int i = 1;
		for each (DataGridViewRow ^ row in dgvSRoad->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvSRoad->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvSRoad->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSRoad->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvSRoad->EnableHeadersVisualStyles = false;
	}

	private: System::Void cboDirectDamage_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		UpdateComponentDirectDamage();
	}
	/*
	private: System::Void cboIndirectDamage_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
	}
	*/

	private: System::Void cboGrpCondi01_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		/*
		--선택--
		내진보강(전)(후) 전체도로망-직/간접 총피해
		내진보강(전) 개별시설물별 직접피해
		내진보강(후) 개별시설물별 직접피해
		내진보강(전)(후) 노선별 직접피해
		내진보강(전)(후) 노선별 간접피해
		내진보강(전)(후) 노선별 종합피해
		*/
		this->m_chartType = "A" + this->cboGrpCondi01->SelectedIndex;
		Debug::WriteLine("========= before ========>m_chartType:" + m_chartType);

		DrawCharts();
		this->cboGrpCondi02->SelectedIndex = 0;
	}

	private: System::Void cboGrpCondi02_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		this->m_chartType = "B" + this->cboGrpCondi01->SelectedIndex;
		Debug::WriteLine("========= before ========>m_chartType:" + m_chartType);

		DrawCharts();		
		this->cboGrpCondi01->SelectedIndex = 0;
	}





	private: void DrawCharts() {

		/*
		--선택--
		내진보강(전)(후) 전체도로망-직/간접 총피해
		내진보강(전) 개별시설물별 직접피해
		내진보강(후) 개별시설물별 직접피해
		내진보강(전)(후) 노선별 직접피해
		내진보강(전)(후) 노선별 간접피해
		내진보강(전)(후) 노선별 종합피해
		*/
		if (this->m_chartType->Equals("A1")) {//내진보강(전)(후) 전체도로망-직/간접 총피해
			Debug::WriteLine("=================> DrawCharts : DrawChart_A1");
			DrawChart_A1();
		}
		else if (this->m_chartType->Equals("A2")) {//내진보강(전) 개별시설물별 직접피해
			Debug::WriteLine("=================> DrawCharts : DrawChart_A2");

			if (directCompoBeforDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 0;
				UpdateComponentDirectDamage();
			}
				

			array<String^>^ arrDataX = gcnew array<String^>(directCompoBeforDict->Count);
			array<double>^ arrDataY = gcnew array<double>(directCompoBeforDict->Count);
			int i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in directCompoBeforDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX[i] = skey;
				arrDataY[i] = dVal;
				i++;
			}
			DrawBellChart(arrDataX, arrDataY);

		}
		else if (this->m_chartType->Equals("A3")) {//내진보강(후) 개별시설물별 직접피해
			Debug::WriteLine("=================> DrawCharts : DrawChart_A3");

			if (directCompoAfterDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 1;
				UpdateComponentDirectDamage();
			}
				

			array<String^>^ arrDataX = gcnew array<String^>(directCompoAfterDict->Count);
			array<double>^ arrDataY = gcnew array<double>(directCompoAfterDict->Count);
			int i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in directCompoAfterDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX[i] = skey;
				arrDataY[i] = dVal;
				i++;
			}
			DrawBellChart(arrDataX, arrDataY);

		}

		//내진보강(전)(후) 노선별 직접피해
		else if (this->m_chartType->Equals("A4")) {
			Debug::WriteLine("=================> DrawCharts : DrawChart_A4");

			if (directLinkBeforDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 0;
				UpdateComponentDirectDamage();
			}

			if (directLinkAfterDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 1;
				UpdateComponentDirectDamage();
			}

			array<String^>^ arrDataX = gcnew array<String^>(directLinkBeforDict->Count);
			array<double>^ arrDataY = gcnew array<double>(directLinkBeforDict->Count);
			int i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in directLinkBeforDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX[i] = skey;
				arrDataY[i] = dVal;
				i++;
			}

			array<String^>^ arrDataX2 = gcnew array<String^>(directLinkAfterDict->Count);
			array<double>^ arrDataY2 = gcnew array<double>(directLinkAfterDict->Count);
			i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in directLinkAfterDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX2[i] = skey;
				arrDataY2[i] = dVal;
				i++;
			}


			DrawChart_A4(arrDataX, arrDataY, arrDataY2);

		}
		//내진보강(전)(후) 노선별 간접피해
		else if (this->m_chartType->Equals("A5")) {
			Debug::WriteLine("=================> DrawCharts : DrawChart_A4");

			if (inDirectLinkBeforDict->Count < 1) {
				UpdateComponentDirectDamage();
			}

			if (inDirectLinkAfterDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 1;
				UpdateComponentDirectDamage();
			}

			array<String^>^ arrDataX = gcnew array<String^>(inDirectLinkBeforDict->Count);
			array<double>^ arrDataY = gcnew array<double>(inDirectLinkBeforDict->Count);
			int i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in inDirectLinkBeforDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX[i] = skey;
				arrDataY[i] = dVal;
				i++;
			}

			array<String^>^ arrDataX2 = gcnew array<String^>(inDirectLinkAfterDict->Count);
			array<double>^ arrDataY2 = gcnew array<double>(inDirectLinkAfterDict->Count);
			i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in inDirectLinkAfterDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX2[i] = skey;
				arrDataY2[i] = dVal;
				i++;
			}


			DrawChart_A4(arrDataX, arrDataY, arrDataY2);
		}
		//내진보강(전)(후) 노선별 종합피해
		else if (this->m_chartType->Equals("A6")) {
			Debug::WriteLine("=================> DrawCharts : DrawChart_A6");


			if (inDirectLinkBeforDict->Count < 1) {
				UpdateComponentDirectDamage();
			}

			if (inDirectLinkAfterDict->Count < 1) {
				this->cboDirectDamage->SelectedIndex = 1;
				UpdateComponentDirectDamage();
			}


			//직접
			if (directLinkAllDict->Count < 1) {

				for each (KeyValuePair<String^, array<double>^> ^ pair in directLinkBeforDict)
				{
					String^ skey = pair->Key;
					array<double>^ aVal = pair->Value;

					directLinkAllDict->Add(skey, aVal);
				}

				for each (KeyValuePair<String^, array<double>^> ^ pair in directLinkAfterDict)
				{
					String^ skey = pair->Key;
					array<double>^ aVal = pair->Value;

					if (directLinkAllDict->ContainsKey(skey)) {
						array<double>^ arr = directLinkAllDict[skey];
						for (int n = 0; n < aVal->Length; n++) {
							aVal[n] += arr[n];
						}
						directLinkAllDict[skey] = aVal;
					}
					else {
						directLinkAllDict->Add(skey, aVal);
					}

				}
			}



			//간접
			if (inDirectLinkAllDict->Count < 1) {

				for each (KeyValuePair<String^, array<double>^> ^ pair in inDirectLinkBeforDict)
				{
					String^ skey = pair->Key;
					array<double>^ aVal = pair->Value;

					inDirectLinkAllDict->Add(skey, aVal);
				}

				for each (KeyValuePair<String^, array<double>^> ^ pair in inDirectLinkAfterDict)
				{
					String^ skey = pair->Key;
					array<double>^ aVal = pair->Value;

					if (inDirectLinkAllDict->ContainsKey(skey)) {
						array<double>^ arr = inDirectLinkAllDict[skey];
						for (int n = 0; n < aVal->Length; n++) {
							aVal[n] += arr[n];
						}
						inDirectLinkAllDict[skey] = aVal;
					}
					else {
						inDirectLinkAllDict->Add(skey, aVal);
					}

				}
			}


			array<String^>^ arrDataX = gcnew array<String^>(directLinkAllDict->Count);
			array<double>^ arrDataY = gcnew array<double>(directLinkAllDict->Count);
			int i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in directLinkAllDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX[i] = skey;
				arrDataY[i] = dVal;
				i++;
			}

			array<String^>^ arrDataX2 = gcnew array<String^>(inDirectLinkAllDict->Count);
			array<double>^ arrDataY2 = gcnew array<double>(inDirectLinkAllDict->Count);
			i = 0;
			for each (KeyValuePair<String^, array<double>^> ^ pair in inDirectLinkAllDict)
			{
				String^ skey = pair->Key;
				array<double>^ aVal = pair->Value;
				double dVal;
				if (cboSeismicPeriod->SelectedIndex == 0) {
					dVal = aVal[0];
				}
				else if (cboSeismicPeriod->SelectedIndex == 1) {
					dVal = aVal[1];
				}
				else if (cboSeismicPeriod->SelectedIndex == 2) {
					dVal = aVal[2];
				}
				else if (cboSeismicPeriod->SelectedIndex == 3) {
					dVal = aVal[3];
				}
				arrDataX2[i] = skey;
				arrDataY2[i] = dVal;
				i++;
			}



			DrawChart_A4(arrDataX, arrDataY, arrDataY2);
		}


		else if (this->m_chartType->StartsWith("B")) {
			Debug::WriteLine("=================> DrawCharts : StartsWith B.......");
			int iIdx = this->cboGrpCondi02->SelectedIndex;
			Debug::WriteLine("=================> iIdx : " + iIdx);

			
			DataTable^ dt = this->m_dataSet->ODZoneParamData;

			//선택이 있어서 -1 함
			int indexOrigin = Convert::ToInt32(dt->Rows[iIdx - 1][CommConst::GRID_OD_ZONE_COL1]);
			int indexDestin = Convert::ToInt32(dt->Rows[iIdx - 1][CommConst::GRID_OD_ZONE_COL2]);
			int indexVolume = Convert::ToInt32(dt->Rows[iIdx - 1][CommConst::GRID_OD_ZONE_COL3]);

			//Link 가져옴
			array<String^>^ roadLink = this->m_unistHelper->dijkstra(indexOrigin, indexDestin);
			

			//다국어
			String^ sUiLang = CultureInfo::CurrentUICulture->Name;
			Debug::WriteLine("========CreateShapeChartProperty===>sUiLang:" + sUiLang);
			String^ sLongitude = "Longitude";//경도
			String^ sLatitude = "Latitude";//위도
			if (sUiLang->Equals("ko-KR")) {
				sLongitude = "경도";//경도
				sLatitude = "위도";//위도
			}
			XYChart^ chart = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);


			int plotAreaWidth = chartViewer->Size.Width - 100;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			chart->setPlotArea(60, 60, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			//chart->addTitle("타이틀", "Times New Roman Bold", 18);

			chart->xAxis()->setTitle(sLongitude, "Arial Bold", 9);
			chart->xAxis()->setWidth(3);
			chart->xAxis()->setTickLength(10, 0);

			chart->yAxis()->setTitle(sLatitude, "Arial Bold", 9);
			chart->yAxis()->setWidth(3);
			chart->xAxis()->setTickLength(10, 0);

			Shape^ shape = this->m_dataSet->ShapeData->Clone();
			for (int i = 0; i < shape->m_nRecords; i++)
			{
				ShapeProperty^ prop = shape->m_SHPProperties[i];
				String^ linkID = prop->GetProperty(ShapeProperty::PropertyType::LINK_ID);
				//Debug::WriteLine(String::Format("========>linkID[{0}]", linkID));

				// The (x, y) data for the first line
				array<double>^ dataX = gcnew array<double>(shape->m_pSHPPolyObjects[i].nNumPoints);
				array<double>^ dataY = gcnew array<double>(shape->m_pSHPPolyObjects[i].nNumPoints);

				// 화면에 그릴 포인트를 할당하고..
				array<System::Drawing::Point>^ arrSrcPoint = gcnew array<System::Drawing::Point>(shape->m_pSHPPolyObjects[i].nNumPoints);
				for (int j = 0; j < shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
				{
					dataX[j] = shape->m_pSHPPolyObjects[i].arrPoints[j].x;
					dataY[j] = shape->m_pSHPPolyObjects[i].arrPoints[j].y;
				}

				int colorInt = ColorToInt(Color::Black);
				//노드링크 색깔 변경
				for (int k = 0; k < roadLink->Length; k++) {
					if (linkID == roadLink[k]) 
						colorInt = ColorToInt(Color::Red);
				}
				
				LineLayer^ layer = chart->addLineLayer(dataY, colorInt, "" + i);
				layer->setXData(dataX);
				//layer->setLineWidth(m_shapeLineWidth);

			}

			chartViewer->Chart = chart;
			chartViewer->ImageMap = chart->getHTMLImageMap("clickable", "", "title='[{dataSetName}]: {x}/{value}'");

		}

	}

	private: int ColorToInt(Color color) {
		int c = color.ToArgb();
		c = c & 0x00FFFFFF; // AARRGGBB 구조에서 AA제거
		return c;
	}


	private: void DrawChart_A1() {


		array<String^>^ m_chartX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length * 2);
		array<double>^ m_chartY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length * 2);
		array<double>^ m_chartY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length * 2);


		// 내진보강(전)
		//if (cboIndirectDamage->SelectedIndex == 0) {
		m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

		//교통시나리오개수 = 지진시나리오(개수) x 샘플링(개수) 에 대한 루프로 구성을 변경
		for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++)
		{
			m_chartDataX1[i] = this->m_dataSet->RecurrencePeriodData[i] + "(전)";
			///////////////////////////////////////////////////////////////////////////////
			// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
			///////////////////////////////////////////////////////////////////////////////
			int odLocalIndex = 1;
			int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, odLocalIndex);

			double sumCost = 0;
			for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
				// 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
				String^ localKey = String::Format("{0}", trafficScenarioNo);
				DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];
				sumCost += double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());
			}
			m_chartDataY1[i] = sumCost;

			///////////////////////////////////////////////////////////////////////////////
			// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다  
			///////////////////////////////////////////////////////////////////////////////
			double sumTrafficCost = 0;
			array<double>^ beforeAdditionalCostData;

			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
				// 0 = 내진보강전, 1= 내진보강후
				beforeAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);
				int recoveryDayCount = beforeAdditionalCostData->Length;
				for (int i = 0; i < recoveryDayCount; i++) {
					sumTrafficCost += beforeAdditionalCostData[i];
				}
			}
			m_chartDataY2[i] = sumTrafficCost;

		}

		//DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
	//}

	//0,2,4,6
		for (int i = 0; i < m_chartDataX1->Length; i++) {
			m_chartX1[i * 2] = m_chartDataX1[i];
			m_chartY1[i * 2] = m_chartDataY1[i];
			m_chartY2[i * 2] = m_chartDataY2[i];
		}

		// 내진보강(후)
		//if (cboIndirectDamage->SelectedIndex == 1) {

		m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

		//교통시나리오개수 = 지진시나리오(개수) x 샘플링(개수) 에 대한 루프로 구성을 변경
		for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++)
		{
			m_chartDataX1[i] = this->m_dataSet->RecurrencePeriodData[i] + "(후)";

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

			int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

			double sumTrafficCost = 0;
			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
				sumTrafficCost += this->m_dataSet->ResultData->GetTotalTrafficCost(localTrafficScenarioNo);
			}
			m_chartDataY2[i] = sumTrafficCost;

		}

		//DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);

	//}


	//1,3,5,7
		for (int i = 0; i < m_chartDataX1->Length; i++) {
			m_chartX1[i * 2 + 1] = m_chartDataX1[i];
			m_chartY1[i * 2 + 1] = m_chartDataY1[i];
			m_chartY2[i * 2 + 1] = m_chartDataY2[i];
		}


		DrawMainChart(m_chartX1, m_chartY1, m_chartY2);

	}


		   /*
		   private: void DrawChart_A1() {

			   // 내진보강(전)
			   //if (cboIndirectDamage->SelectedIndex == 0) {
				   m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
				   m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
				   m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

				   //교통시나리오개수 = 지진시나리오(개수) x 샘플링(개수) 에 대한 루프로 구성을 변경
				   for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++)
				   {
					   m_chartDataX1[i] = this->m_dataSet->RecurrencePeriodData[i];
					   ///////////////////////////////////////////////////////////////////////////////
					   // 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다.
					   ///////////////////////////////////////////////////////////////////////////////
					   int odLocalIndex = 1;
					   int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, odLocalIndex);

					   double sumCost = 0;
					   for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
						   // 글로벌변수로 저장된 내진보강전 직접피해규모 저장 테이터 테이블 호출
						   String^ localKey = String::Format("{0}", trafficScenarioNo);
						   DataTable^ beforeDirectCostTable = this->m_dataSet->BeforeRehabStructureCost[localKey];
						   sumCost += double::Parse(beforeDirectCostTable->Rows[j]->ItemArray[1]->ToString());
					   }
					   m_chartDataY1[i] = sumCost;

					   ///////////////////////////////////////////////////////////////////////////////
					   // 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다
					   ///////////////////////////////////////////////////////////////////////////////
					   double sumTrafficCost = 0;
					   array<double>^ beforeAdditionalCostData;

					   for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
						   int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
						   // 0 = 내진보강전, 1= 내진보강후
						   beforeAdditionalCostData = CalculateAdditionalCost(0, localTrafficScenarioNo);
						   int recoveryDayCount = beforeAdditionalCostData->Length;
						   for (int i = 0; i < recoveryDayCount; i++) {
							   sumTrafficCost += beforeAdditionalCostData[i];
						   }
					   }
					   m_chartDataY2[i] = sumTrafficCost;

				   }

				   DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
			   //}



		   }
		   */

	private: void DrawChart_A2() {


		// 내진보강(후)
		//if (cboIndirectDamage->SelectedIndex == 1) {

		m_chartDataX1 = gcnew array<String^>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY1 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);
		m_chartDataY2 = gcnew array<double>(this->m_dataSet->RecurrencePeriodData->Length);

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

			int recoveryStepCount = CommConst::DAMAGE_STATE_COUNT;

			double sumTrafficCost = 0;
			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1, j + 1);
				sumTrafficCost += this->m_dataSet->ResultData->GetTotalTrafficCost(localTrafficScenarioNo);
			}
			m_chartDataY2[i] = sumTrafficCost;

		}

		DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);

		//}


	}




		   void DrawChart_A4(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {
			   String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			   String^ sample = cboSample->SelectedItem->ToString();
			   XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);

			   int plotAreaWidth = chartViewer->Size.Width - 150;
			   int plotAreaHeight = chartViewer->Size.Height - 120;
			   c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
			   c->addTitle("", "Times New Roman Bold", 17);

			   LegendBox^ b = c->addLegend(120, 10, false, "Arial", 11);
			   b->setBackground(Chart::Transparent, Chart::Transparent);
			   b->setKeyBorder(Chart::SameAsMainColor);

			   // Set the x and y axis stems to transparent and the label font to 12pt Arial
			   c->xAxis()->setColors(Chart::Transparent);
			   c->xAxis()->setLabels(dataX);
			   //c->xAxis()->setTitle("Recurrence Period (years)", "Arial Bold", 11);

			   c->yAxis()->setColors(Chart::Transparent);
			   c->xAxis()->setLabelStyle("Arial Bold", 11);
			   c->yAxis()->setLabelStyle("Arial Bold", 11);
			   //			c->yAxis()->setTitle("Cost (￦) 10^7", "Arial Bold", 12);
			   c->yAxis()->setTitle("백억원(￦)", "Arial Bold", 11);
			   c->yAxis()->setLabelFormat("{={value}/10000000}");

			   // Add a stacked bar layer
			   BarLayer^ layer = c->addBarLayer2(Chart::Stack);

			   // Add the three data sets to the bar layer
			   layer->addDataSet(dataY1, 0x0000FF, "내진보강(전)");
			   layer->addDataSet(dataY2, 0xFFF000, "내진보강(후)");

			   // Set the bar border to transparent
			   layer->setBorderColor(Chart::Transparent);
			   layer->setLegendOrder(Chart::ReverseLegend);

			   // Output the chart
			   chartViewer->Chart = c;
			   chartViewer->ImageMap = c->getHTMLImageMap("clickable", "", "title='[{dataSetName}]: {xLabel}={value}'");
		   }



	private: void DrawBellChart(array<String^>^, array<double>^ dataY) {

		char buffer[256];
		//String^ buffer;
		//
		// This example demonstrates creating a histogram with a bell curve from raw data. About half of
		// the code is to sort the raw data into slots and to generate the points on the bell curve. The
		// remaining half of the code is the actual charting code.
		//

		// Generate a random guassian distributed data series as the input data for this example.
		//RanSeries* r = new RanSeries(66);
		//RanSeries^ r = gcnew RanSeries(66);

		//DoubleArray samples = r->getGaussianSeries(200, 100, 10);
		//array<double>^ samples = r->getGaussianSeries(200, 100, 10);
		array<double>^ samples = gcnew array<double>(dataY->Length);
		for (int i = 0; i < dataY->Length; i++) {
			samples[i] = dataY[i] / (1000000);
		}

		//
		// Classify the numbers into slots. In this example, the slot width is 5 units.
		//
		ArrayMath^ m = gcnew ArrayMath(samples);

		int slotSize;
		if (samples->Length < 20) {
			slotSize = (floor(m->max()) - floor(m->min())) / (samples->Length - 1);
		}
		else {
			slotSize = (floor(m->max()) - floor(m->min())) / 19;
		}
		if (slotSize <= 0) { slotSize = 10; }
		//int slotSize = 20;
		//int slotSize = 10000000;

		// Compute the min and max values, and extend them to the slot boundary.
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


		c->yAxis()->setColors(Chart::Transparent);
		c->xAxis()->setLabelStyle("Arial Bold", 12);
		c->yAxis()->setLabelStyle("Arial Bold", 12);
		c->yAxis()->setTitle("샘플개수", "Arial Bold", 12);

		c->xAxis()->setColors(Chart::Transparent);
		c->xAxis()->setTitle("피해규모(십억원)", "Arial Bold", 12);


		// Output the chart
		//c->makeChart("histogram.png");
		chartViewer->Chart = c;

		//free up resources
//			delete r;
		delete[] frequency;
		delete[] bellCurve;
		delete c;


	}


	};

}
