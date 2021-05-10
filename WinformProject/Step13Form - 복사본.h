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





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
//	private: System::Windows::Forms::DataGridView^ dgvNetworkComponent;
		   array<array<double>^>^ m_subChartDataY;

	private:	   array<ComponentClassInfo>^ m_chartDatas;
	private: ChartDirector::WinChartViewer^ chartViewer;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridView^ dgvSRoad;

	private: System::Windows::Forms::DataGridView^ dgvEffect;

	private: System::Windows::Forms::DataGridView^ dgvBudget;


	private: System::Windows::Forms::DataGridView^ dgvPriority;

	private: System::Windows::Forms::DataGridView^ dgvDirectDamage;

	private: System::Windows::Forms::ComboBox^ cboSeismicPeriod;

	private: System::Windows::Forms::Label^ label9;
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

	//protected:


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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cboSeismicPeriod = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			this->tableLayoutPanel1->ColumnCount = 12;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.399999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.399999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.399999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.399999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.299999F)));
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicPeriod, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->label9, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->comboBox4, 10, 1);
			this->tableLayoutPanel1->Controls->Add(this->label8, 9, 1);
			this->tableLayoutPanel1->Controls->Add(this->comboBox3, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->label7, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->comboBox2, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->label6, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 6, 3);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 1, 1);
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
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1031, 700);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// cboSeismicPeriod
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSeismicPeriod, 2);
			this->cboSeismicPeriod->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicPeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicPeriod->FormattingEnabled = true;
			this->cboSeismicPeriod->Location = System::Drawing::Point(518, 4);
			this->cboSeismicPeriod->Margin = System::Windows::Forms::Padding(4);
			this->cboSeismicPeriod->Name = L"cboSeismicPeriod";
			this->cboSeismicPeriod->Size = System::Drawing::Size(162, 26);
			this->cboSeismicPeriod->TabIndex = 22;
			this->cboSeismicPeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSeismicPeriod_SelectionChangeCommitted);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label9, 2);
			this->label9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label9->Location = System::Drawing::Point(348, 0);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(162, 45);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Period";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// comboBox4
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->comboBox4, 2);
			this->comboBox4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(858, 60);
			this->comboBox4->Margin = System::Windows::Forms::Padding(4);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(169, 26);
			this->comboBox4->TabIndex = 20;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(773, 45);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 45);
			this->label8->TabIndex = 19;
			this->label8->Text = L"S-Road";
			this->label8->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// comboBox3
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->comboBox3, 2);
			this->comboBox3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(603, 60);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(162, 26);
			this->comboBox3->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(518, 45);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 45);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Effect";
			this->label7->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// comboBox2
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->comboBox2, 2);
			this->comboBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0%~5%", L"0%~10%", L"0%~25%", L"0%~50%", L"0%~100%" });
			this->comboBox2->Location = System::Drawing::Point(348, 60);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(162, 26);
			this->comboBox2->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(262, 45);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 45);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Budget";
			this->label6->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label5, 6);
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(518, 372);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(509, 45);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Indirect Damage(Traffic Cost)";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label4, 6);
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(4, 372);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(506, 45);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Direct Damage";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(4, 45);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 45);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Priority";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// comboBox1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->comboBox1, 2);
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(90, 60);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(164, 26);
			this->comboBox1->TabIndex = 11;
			// 
			// dgvSRoad
			// 
			this->dgvSRoad->AllowUserToAddRows = false;
			this->dgvSRoad->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvSRoad, 3);
			this->dgvSRoad->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvSRoad->Location = System::Drawing::Point(773, 94);
			this->dgvSRoad->Margin = System::Windows::Forms::Padding(4);
			this->dgvSRoad->Name = L"dgvSRoad";
			this->dgvSRoad->RowHeadersWidth = 62;
			this->dgvSRoad->RowTemplate->Height = 23;
			this->dgvSRoad->Size = System::Drawing::Size(254, 274);
			this->dgvSRoad->TabIndex = 10;
			// 
			// dgvEffect
			// 
			this->dgvEffect->AllowUserToAddRows = false;
			this->dgvEffect->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvEffect, 3);
			this->dgvEffect->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvEffect->Location = System::Drawing::Point(518, 94);
			this->dgvEffect->Margin = System::Windows::Forms::Padding(4);
			this->dgvEffect->Name = L"dgvEffect";
			this->dgvEffect->RowHeadersWidth = 62;
			this->dgvEffect->RowTemplate->Height = 23;
			this->dgvEffect->Size = System::Drawing::Size(247, 274);
			this->dgvEffect->TabIndex = 9;
			// 
			// dgvBudget
			// 
			this->dgvBudget->AllowUserToAddRows = false;
			this->dgvBudget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvBudget, 3);
			this->dgvBudget->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvBudget->Location = System::Drawing::Point(262, 94);
			this->dgvBudget->Margin = System::Windows::Forms::Padding(4);
			this->dgvBudget->Name = L"dgvBudget";
			this->dgvBudget->RowHeadersWidth = 62;
			this->dgvBudget->RowTemplate->Height = 23;
			this->dgvBudget->Size = System::Drawing::Size(248, 274);
			this->dgvBudget->TabIndex = 8;
			// 
			// dgvPriority
			// 
			this->dgvPriority->AllowUserToAddRows = false;
			this->dgvPriority->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvPriority, 3);
			this->dgvPriority->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvPriority->Location = System::Drawing::Point(4, 94);
			this->dgvPriority->Margin = System::Windows::Forms::Padding(4);
			this->dgvPriority->Name = L"dgvPriority";
			this->dgvPriority->RowHeadersWidth = 62;
			this->dgvPriority->RowTemplate->Height = 23;
			this->dgvPriority->Size = System::Drawing::Size(250, 274);
			this->dgvPriority->TabIndex = 7;
			// 
			// dgvDirectDamage
			// 
			this->dgvDirectDamage->AllowUserToAddRows = false;
			this->dgvDirectDamage->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableLayoutPanel1->SetColumnSpan(this->dgvDirectDamage, 6);
			this->dgvDirectDamage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDirectDamage->Location = System::Drawing::Point(4, 421);
			this->dgvDirectDamage->Margin = System::Windows::Forms::Padding(4);
			this->dgvDirectDamage->Name = L"dgvDirectDamage";
			this->dgvDirectDamage->RowHeadersWidth = 62;
			this->dgvDirectDamage->RowTemplate->Height = 23;
			this->dgvDirectDamage->Size = System::Drawing::Size(506, 275);
			this->dgvDirectDamage->TabIndex = 6;
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 6);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->Location = System::Drawing::Point(518, 421);
			this->chartViewer->Margin = System::Windows::Forms::Padding(4);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(509, 275);
			this->chartViewer->TabIndex = 5;
			this->chartViewer->TabStop = false;
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step13Form::chartViewer_SizeChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label2, 2);
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(688, 0);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 45);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Sample";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label1, 2);
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(4, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Source";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// cboSample
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSample, 2);
			this->cboSample->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(858, 4);
			this->cboSample->Margin = System::Windows::Forms::Padding(4);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(169, 26);
			this->cboSample->TabIndex = 4;
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSample_SelectionChangeCommitted);
			// 
			// cboSeismicSource
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->cboSeismicSource, 2);
			this->cboSeismicSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(176, 4);
			this->cboSeismicSource->Margin = System::Windows::Forms::Padding(4);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(164, 26);
			this->cboSeismicSource->TabIndex = 2;
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step13Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// Step13Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1031, 700);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step13Form";
			this->Text = L"Step13Form";
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


//그래프 타입: Histogram with Bell Curve  

		void DrawMainChart(array<String^>^ dataX, array<double>^ dataY1, array<double>^ dataY2) {

			char buffer[256];
			//String^ buffer;
			//
			// This example demonstrates creating a histogram with a bell curve from raw data. About half of
			// the code is to sort the raw data into slots and to generate the points on the bell curve. The
			// remaining half of the code is the actual charting code.
			//
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

			// Compute the min and max values, and extend them to the slot boundary.
			double minX = floor(m->min() / slotSize) * slotSize;
			double maxX = floor(m->max() / slotSize) * slotSize + slotSize;

			// We can now determine the number of slots
			int slotCount = (int)((maxX - minX + 0.5) / slotSize);
			array<double>^ frequency = gcnew array<double>(slotCount);
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
			array<double>^ bellCurve = gcnew array<double>(bellCurveResolution);

			for (int i = 0; i < bellCurveResolution; ++i) {
				double z = 2 * i * stdDevWidth / (bellCurveResolution - 1) - stdDevWidth;
				bellCurve[i] = exp(-z * z / 2) * scaleFactor;
			}

			//
			// At this stage, we have obtained all data and can plot the chart.
			//

			// Create a XYChart object of size 600 x 360 pixels
			XYChart^ c = gcnew XYChart(chartViewer->Size.Width, chartViewer->Size.Height);
			int plotAreaWidth = chartViewer->Size.Width - 150;
			int plotAreaHeight = chartViewer->Size.Height - 120;
			c->setPlotArea(100, 50, plotAreaWidth, plotAreaHeight, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

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

			SplineLayer^ bellLayer = c->addSplineLayer(bellCurve, 0xdd0000);
			bellLayer->setXData(mean - stdDevWidth * stdDev, mean + stdDevWidth * stdDev);
			bellLayer->setLineWidth(2);

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

		void DrawCharts() {
			if (cboSample->SelectedIndex < 0) {
				return;
			}
			m_chartDataX1 = gcnew array<String^>(this->m_dataSet->TrafficScenarioSamples->Length);
			m_chartDataY1 = gcnew array<double>(this->m_dataSet->TrafficScenarioSamples->Length);
			m_chartDataY2 = gcnew array<double>(this->m_dataSet->TrafficScenarioSamples->Length);


			for (int i = 0; i < this->m_dataSet->TrafficScenarioSamples->Length; i++)
			{
				m_chartDataX1[i] = String::Format("{0}",i);
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, this->cboSeismicPeriod->SelectedIndex, i + 1);
				// The data for main chart
				// generate estimated total network structural cost
				m_chartDataY1[i] = this->m_dataSet->ResultData->GetTotalNetworkStructuralCost(trafficScenarioNo);
				// generate estimated total traffic cost
				m_chartDataY2[i] = this->m_dataSet->ResultData->GetTotalTrafficCost(trafficScenarioNo);
			}
			DrawMainChart(m_chartDataX1, m_chartDataY1, m_chartDataY2);
		}

		//Direct Damage of Component in road-network

		System::Data::DataTable^ NewTable(array<String^>^ columns) { 
			DataTable^ table = gcnew DataTable(); 
			for each (String ^ col in columns) {
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}


		void UpdateComponentDirectDamage() {
			array<String^>^ columns = { "시설물", "노선", "50년", "100년", "475년", "1000년" };
			DataTable^ newTable = NewTable(columns);

			for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++) {
				DataRow^ newRow = newTable->NewRow();
				DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
				String^ componentID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
				String^ link = row[NetworkComponent::COL_LINK_ID]->ToString();

				newRow[0] = componentID;
				newRow[1] = link;

				for (int i = 0; i < this->m_dataSet->RecurrencePeriodData->Length; i++) {
					int trafficSecnarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, i, cboSample->SelectedIndex + 1);
					double value = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficSecnarioNo, componentID);
					// 재현주기는 2번칼럼 부터 재현주기1(예50년), 재현주기2(예,100년), 재현주기3(예,475년), 재현주기4(예,1000년) 순으로 입력됨
					newRow[i+2] = value;
				}
				newTable->Rows->Add(newRow);
			}



			//직접피해에 기초한 의사결정 (상위 5%, 10%, 25%, 50%, 100%)
			int indexRecurrencePeriod;
			if (cboSeismicPeriod->SelectedItem == this->m_dataSet->RecurrencePeriodData[0]->ToString()) {
				indexRecurrencePeriod = 0;
			}
			else if (cboSeismicPeriod->SelectedIndex == int::Parse(this->m_dataSet->RecurrencePeriodData[1]->ToString())) {
				indexRecurrencePeriod = 1;
			}
			else if (cboSeismicPeriod->SelectedIndex == int::Parse(this->m_dataSet->RecurrencePeriodData[2]->ToString())) {
				indexRecurrencePeriod = 2;
			}
			else {
				indexRecurrencePeriod = 3;
			}


			array<double>^ directDamages = gcnew array<double>(this->m_dataSet->NetworkCompnentData->Rows->Count);



			for (int i = 0; i < this->m_dataSet->NetworkCompnentData->Rows->Count; i++) {
				DataRow^ newRow = newTable->Rows[i];
				directDamages[i] = double::Parse(newRow->ItemArray[indexRecurrencePeriod]->ToString());
				//String^ temp = newRow[indexRecurrencePeriod]->ToString();
				int k=1;
			}
			dgvDirectDamage->DataSource = newTable;
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

		UpdateComponentDirectDamage();

	}



	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
		UpdateComponentDirectDamage();

	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
		DrawCharts();
		UpdateComponentDirectDamage();
	}

private: System::Void dgvNetworkComponent_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
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



private: System::Void cboSeismicPeriod_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
	DrawCharts();
	UpdateComponentDirectDamage();
}



private: System::Void chartViewer_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (m_chartDataX1 != nullptr && m_chartDataY1 != nullptr && m_chartDataY2 != nullptr) {
		DrawCharts();
	}
}

};
}
