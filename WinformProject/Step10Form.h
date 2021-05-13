#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "TrafficModule.h"
#include "OutputSummary.h"
#include "RecoveryCost.h"
#include "NeXTAHelper.h"
#include "UNISTHelper.h"
#include <algorithm> 
#include "FileUtil.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;


	/// <summary>
	/// Step10Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step10Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step10Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		bool						m_isCalculated;
		array<double>^				m_dataX;
		double						m_valueOfTime;
		double						m_trafficFactor1;
		double						m_trafficFactor2;
		double						m_penaltyCost;

		RecoveryCost^				m_recoveryCost;

		UNISTHelper^                m_UNISTHelper;//UNIST

		FileUtil^ m_fileUtil = gcnew FileUtil();

	public:
		Step10Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_recoveryCost = gcnew RecoveryCost(this->m_dataSet);
			this->m_UNISTHelper = gcnew UNISTHelper(this->m_dataSet);
		}
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step10Form()
		{
			if (components)
			{
				delete components;
			}
		}


	public:
		// create new datatable object by columns information
		DataTable^ NewTable(array<String^>^ columns) {
			DataTable^ table = gcnew DataTable();
			// define fields
			for each (String ^ col in columns)
			{
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  btnCalculate;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbValueOfTime;
	private: System::Windows::Forms::TextBox^  tbTrafficFactor1;
	private: System::Windows::Forms::TextBox^  tbTrafficFactor2;
	private: System::Windows::Forms::TextBox^  tbPenaltyCost;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radTypicalDayNo;
	private: System::Windows::Forms::RadioButton^  radTypicalDayYes;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: ChartDirector::WinChartViewer^  chartViewer1;
	private: ChartDirector::WinChartViewer^  chartViewer2;
	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::ComboBox^  cboRecurrencePeriod;
	private: System::Windows::Forms::ComboBox^  cboSample;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbValueOfTime = (gcnew System::Windows::Forms::TextBox());
			this->tbTrafficFactor1 = (gcnew System::Windows::Forms::TextBox());
			this->tbTrafficFactor2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radTypicalDayNo = (gcnew System::Windows::Forms::RadioButton());
			this->radTypicalDayYes = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tbPenaltyCost = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chartViewer1 = (gcnew ChartDirector::WinChartViewer());
			this->chartViewer2 = (gcnew ChartDirector::WinChartViewer());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboRecurrencePeriod = (gcnew System::Windows::Forms::ComboBox());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer2))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				69.71252F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30.28748F)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnCalculate, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1549, 1142);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->groupBox1->Location = System::Drawing::Point(4, 4);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel1->SetRowSpan(this->groupBox1, 2);
			this->groupBox1->Size = System::Drawing::Size(1071, 219);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Value of Time definition (VOT)";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				196)));
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->tbValueOfTime, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->tbTrafficFactor1, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->tbTrafficFactor2, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->panel1, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(4, 32);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1063, 183);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->label2->Location = System::Drawing::Point(4, 0);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(859, 45);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Traffic simulation of typical day";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->label3->Location = System::Drawing::Point(4, 45);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(859, 45);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Value of Time (￦1000)";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->label4->Location = System::Drawing::Point(4, 90);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(859, 45);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Traffic factor 1 (from simulated hour to typical day)";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->label5->Location = System::Drawing::Point(4, 135);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(859, 48);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Traffic factor 2 (from a day of simulated month to a day of a typical month)";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbValueOfTime
			// 
			this->tbValueOfTime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbValueOfTime->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->tbValueOfTime->Location = System::Drawing::Point(871, 49);
			this->tbValueOfTime->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbValueOfTime->Name = L"tbValueOfTime";
			this->tbValueOfTime->Size = System::Drawing::Size(188, 30);
			this->tbValueOfTime->TabIndex = 2;
			this->tbValueOfTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbValueOfTime->TextChanged += gcnew System::EventHandler(this, &Step10Form::tbValueOfTime_TextChanged);
			this->tbValueOfTime->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10Form::numberTypeTextBox_KeyPress);
			// 
			// tbTrafficFactor1
			// 
			this->tbTrafficFactor1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbTrafficFactor1->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->tbTrafficFactor1->Location = System::Drawing::Point(871, 94);
			this->tbTrafficFactor1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbTrafficFactor1->Name = L"tbTrafficFactor1";
			this->tbTrafficFactor1->ReadOnly = true;
			this->tbTrafficFactor1->Size = System::Drawing::Size(188, 30);
			this->tbTrafficFactor1->TabIndex = 2;
			this->tbTrafficFactor1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbTrafficFactor1->TextChanged += gcnew System::EventHandler(this, &Step10Form::tbTrafficFactor1_TextChanged);
			this->tbTrafficFactor1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10Form::numberTypeTextBox_KeyPress);
			// 
			// tbTrafficFactor2
			// 
			this->tbTrafficFactor2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbTrafficFactor2->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->tbTrafficFactor2->Location = System::Drawing::Point(871, 139);
			this->tbTrafficFactor2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbTrafficFactor2->Name = L"tbTrafficFactor2";
			this->tbTrafficFactor2->ReadOnly = true;
			this->tbTrafficFactor2->Size = System::Drawing::Size(188, 30);
			this->tbTrafficFactor2->TabIndex = 2;
			this->tbTrafficFactor2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbTrafficFactor2->TextChanged += gcnew System::EventHandler(this, &Step10Form::tbTrafficFactor2_TextChanged);
			this->tbTrafficFactor2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10Form::numberTypeTextBox_KeyPress);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radTypicalDayNo);
			this->panel1->Controls->Add(this->radTypicalDayYes);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(871, 4);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(188, 37);
			this->panel1->TabIndex = 3;
			// 
			// radTypicalDayNo
			// 
			this->radTypicalDayNo->AutoSize = true;
			this->radTypicalDayNo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radTypicalDayNo->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->radTypicalDayNo->Location = System::Drawing::Point(68, 0);
			this->radTypicalDayNo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radTypicalDayNo->Name = L"radTypicalDayNo";
			this->radTypicalDayNo->Size = System::Drawing::Size(120, 37);
			this->radTypicalDayNo->TabIndex = 0;
			this->radTypicalDayNo->TabStop = true;
			this->radTypicalDayNo->Text = L"No";
			this->radTypicalDayNo->UseVisualStyleBackColor = true;
			this->radTypicalDayNo->CheckedChanged += gcnew System::EventHandler(this, &Step10Form::radTypicalDays_CheckedChanged);
			// 
			// radTypicalDayYes
			// 
			this->radTypicalDayYes->AutoSize = true;
			this->radTypicalDayYes->Dock = System::Windows::Forms::DockStyle::Left;
			this->radTypicalDayYes->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->radTypicalDayYes->Location = System::Drawing::Point(0, 0);
			this->radTypicalDayYes->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radTypicalDayYes->Name = L"radTypicalDayYes";
			this->radTypicalDayYes->Size = System::Drawing::Size(68, 37);
			this->radTypicalDayYes->TabIndex = 0;
			this->radTypicalDayYes->TabStop = true;
			this->radTypicalDayYes->Text = L"Yes";
			this->radTypicalDayYes->UseVisualStyleBackColor = true;
			this->radTypicalDayYes->CheckedChanged += gcnew System::EventHandler(this, &Step10Form::radTypicalDays_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tbPenaltyCost);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(1083, 4);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(462, 150);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Non feasable trips";
			// 
			// tbPenaltyCost
			// 
			this->tbPenaltyCost->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->tbPenaltyCost->Location = System::Drawing::Point(241, 72);
			this->tbPenaltyCost->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbPenaltyCost->Name = L"tbPenaltyCost";
			this->tbPenaltyCost->Size = System::Drawing::Size(141, 30);
			this->tbPenaltyCost->TabIndex = 1;
			this->tbPenaltyCost->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPenaltyCost->TextChanged += gcnew System::EventHandler(this, &Step10Form::tbPenaltyCost_TextChanged);
			this->tbPenaltyCost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Step10Form::numberTypeTextBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->label1->Location = System::Drawing::Point(41, 80);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PenaltyCost(￦1000)";
			// 
			// groupBox3
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->groupBox3, 2);
			this->groupBox3->Controls->Add(this->tableLayoutPanel3);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->groupBox3->Location = System::Drawing::Point(4, 231);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(1541, 907);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Output";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				214)));
			this->tableLayoutPanel3->Controls->Add(this->chartViewer1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->chartViewer2, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->cboSeismicSource, 2, 1);
			this->tableLayoutPanel3->Controls->Add(this->cboRecurrencePeriod, 2, 3);
			this->tableLayoutPanel3->Controls->Add(this->cboSample, 2, 5);
			this->tableLayoutPanel3->Controls->Add(this->label6, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->label7, 2, 2);
			this->tableLayoutPanel3->Controls->Add(this->label8, 2, 4);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(4, 32);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 7;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1533, 871);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// chartViewer1
			// 
			this->chartViewer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer1->Location = System::Drawing::Point(4, 4);
			this->chartViewer1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewer1->Name = L"chartViewer1";
			this->tableLayoutPanel3->SetRowSpan(this->chartViewer1, 7);
			this->chartViewer1->Size = System::Drawing::Size(651, 863);
			this->chartViewer1->TabIndex = 0;
			this->chartViewer1->TabStop = false;
			this->chartViewer1->SizeChanged += gcnew System::EventHandler(this, &Step10Form::chartViewer1_SizeChanged);
			// 
			// chartViewer2
			// 
			this->chartViewer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer2->Location = System::Drawing::Point(663, 4);
			this->chartViewer2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chartViewer2->Name = L"chartViewer2";
			this->tableLayoutPanel3->SetRowSpan(this->chartViewer2, 7);
			this->chartViewer2->Size = System::Drawing::Size(651, 863);
			this->chartViewer2->TabIndex = 0;
			this->chartViewer2->TabStop = false;
			this->chartViewer2->SizeChanged += gcnew System::EventHandler(this, &Step10Form::chartViewer2_SizeChanged);
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->cboSeismicSource->FormattingEnabled = true;
			this->cboSeismicSource->Location = System::Drawing::Point(1322, 28);
			this->cboSeismicSource->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->Size = System::Drawing::Size(207, 31);
			this->cboSeismicSource->TabIndex = 1;
			this->cboSeismicSource->SelectedIndexChanged += gcnew System::EventHandler(this, &Step10Form::cboSeismicSource_SelectedIndexChanged);
			// 
			// cboRecurrencePeriod
			// 
			this->cboRecurrencePeriod->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboRecurrencePeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrencePeriod->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->cboRecurrencePeriod->FormattingEnabled = true;
			this->cboRecurrencePeriod->Location = System::Drawing::Point(1322, 91);
			this->cboRecurrencePeriod->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboRecurrencePeriod->Name = L"cboRecurrencePeriod";
			this->cboRecurrencePeriod->Size = System::Drawing::Size(207, 31);
			this->cboRecurrencePeriod->TabIndex = 1;
			this->cboRecurrencePeriod->SelectedIndexChanged += gcnew System::EventHandler(this, &Step10Form::cboRecurrencePeriod_SelectedIndexChanged);
			// 
			// cboSample
			// 
			this->cboSample->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->cboSample->FormattingEnabled = true;
			this->cboSample->Location = System::Drawing::Point(1322, 154);
			this->cboSample->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cboSample->Name = L"cboSample";
			this->cboSample->Size = System::Drawing::Size(207, 31);
			this->cboSample->TabIndex = 1;
			this->cboSample->SelectedIndexChanged += gcnew System::EventHandler(this, &Step10Form::cboSample_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(1322, 0);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(207, 24);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Seismic source";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(1322, 63);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(207, 24);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Recurrence period";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(1322, 126);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(207, 24);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Sample";
			// 
			// btnCalculate
			// 
			this->btnCalculate->Dock = System::Windows::Forms::DockStyle::Right;
			this->btnCalculate->Font = (gcnew System::Drawing::Font(L"Gulim", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btnCalculate->Location = System::Drawing::Point(1325, 162);
			this->btnCalculate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(220, 61);
			this->btnCalculate->TabIndex = 3;
			this->btnCalculate->Text = L"Calculate";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &Step10Form::btnCalculate_Click);
			// 
			// Step10Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1549, 1142);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Step10Form";
			this->Text = L"Step10Form";
			this->Load += gcnew System::EventHandler(this, &Step10Form::Step10Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	private:
		// draw chart(left side)
		void DrawChart1(array<double>^ dataX, array<double>^ dataY) {
			int selectedIndex = cboRecurrencePeriod->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			String^ period = cboRecurrencePeriod->SelectedItem->ToString();
			selectedIndex = cboSample->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			String^ sample = cboSample->SelectedItem->ToString();
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ title = String::Format("Functionality vs Time relationship\nSeismic source: {0} - Scenario: {1} years", scenarioName, period);
			//다국어
			String^ sUiLang = CultureInfo::CurrentUICulture->Name;
			if (sUiLang->Equals("ko-KR")) {
				title = String::Format("교통기능 vs 시간\n 지진원: {0} - Scenario: {1} years", scenarioName, period);
			}
			XYChart^ c = gcnew XYChart(chartViewer1->Size.Width, chartViewer1->Size.Height);

			int plotAreaWidth = chartViewer1->Size.Width - 130;
			int plotAreaHeight = chartViewer1->Size.Height - 150;
			c->setPlotArea(80, 80, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);

			c->addTitle(title, "Times New Roman Bold", 17);
			//다국어
			String^ sXAxis = L"Time (days)";
			String^ sYAxis = L"TrafficFunctionality%(a)";
			if (sUiLang->Equals("ko-KR")) {
				sXAxis = L"시간(일)";
				sYAxis = L"교통기능%(a)";
			}
			c->xAxis()->setTitle(sXAxis, "Arial Bold", 12);
			c->xAxis()->setLinearScale(0, 500);
			c->yAxis()->setTitle(sYAxis, "Arial Bold", 12);
			c->yAxis()->setLinearScale(0, 100);


			//DataX 최상위1열 및 DataY 최하위 1열 추가 및 값(=0)로 셋팅
			/*
			StepLineLayer^ layer0 = c->addStepLineLayer(dataY, 0x0000FF, "");
			layer0->setXData(dataX);
			layer0->setLineWidth(2);
			*/
			array<double>^ localDataX = gcnew array<double>(dataX->Length + 1);
			array<double>^ localDataY = gcnew array<double>(dataY->Length + 1);
			for (int i = 0; i <= dataX->Length; i++) 
			{
				if ((i == 0) || (i == dataX->Length))
				{
					if (i == 0) { localDataX[i] = 0; localDataY[i] = dataY[i]; }
					else if (i == dataX->Length) { localDataX[i] = dataX[i - 1]; localDataY[i] = 100; }
				}
				else {
					localDataX[i] = dataX[i-1]; 
					localDataY[i] = dataY[i];
				}
			}
			StepLineLayer^ layer0 = c->addStepLineLayer(localDataY, 0x0000FF, "");
			layer0->setXData(localDataX);
			// 추가 및 변경된 코드 끝 라인

			layer0->setLineWidth(2);

			// Output the chart
			chartViewer1->Chart = c;
			chartViewer1->ImageMap = c->getHTMLImageMap("clickable", "", "title='{x}/{value}'");
		}
		// draw chart(right side)
		void DrawChart2(array<double>^ dataX, array<double>^ dataY) {
			int selectedIndex = cboRecurrencePeriod->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			String^ period = cboRecurrencePeriod->SelectedItem->ToString();
			selectedIndex = cboSample->SelectedIndex;
			if (selectedIndex < 0) {
				return;
			}
			String^ sample = cboSample->SelectedItem->ToString();
			String^ scenarioName = cboSeismicSource->SelectedValue->ToString();
			String^ title = String::Format("Additional cost vs Time\nSeismic source: {0} - Scenario: {1} years", scenarioName, period);
			//다국어
			String^ sUiLang = CultureInfo::CurrentUICulture->Name;
			if (sUiLang->Equals("ko-KR")) {
				title = String::Format("추가비용 vs 시간\n 지진원: {0} - Scenario: {1} years", scenarioName, period);
			}
			XYChart^ c = gcnew XYChart(chartViewer2->Size.Width, chartViewer2->Size.Height);

			int plotAreaWidth = chartViewer2->Size.Width - 130;
			int plotAreaHeight = chartViewer2->Size.Height - 150;
			c->setPlotArea(80, 80, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);

			c->addTitle(title, "Times New Roman Bold", 17);
			//다국어
			String^ sXAxis = L"Time (days)";
			String^ sYAxis = L"Additional cost per day (￦)";
			if (sUiLang->Equals("ko-KR")) {
				sXAxis = L"시간(일)";
				sYAxis = L"일단위 추가비용(￦)";
			}
			c->xAxis()->setTitle(sXAxis, "Arial Bold", 12);
			c->xAxis()->setLinearScale(0, 500);
			//c->yAxis()->setTitle("Functionality%(a)", "Arial Bold", 12);
			c->yAxis()->setTitle(sYAxis, "Arial Bold", 12);

		
			//DataX 최상위1열 및 DataY 최하위 1열 추가 및 값(=0)로 셋팅
			/*
			StepLineLayer^ layer0 = c->addStepLineLayer(dataY, 0x0000FF, "");
			layer0->setXData(dataX);
			layer0->setLineWidth(2);
			*/
			array<double>^ localDataX = gcnew array<double>(dataX->Length + 1);
			array<double>^ localDataY = gcnew array<double>(dataY->Length + 1);
			int preRecoveryDay=0;
			for (int i = 0; i <= dataX->Length; i++)
			{
				if ((i == 0) || (i == dataX->Length))
				{
					if (i == 0) { localDataX[i] = 0; localDataY[i] = dataY[i]; }
					else if (i == dataX->Length) { localDataX[i] = dataX[i - 1]; localDataY[i] = 0; }
				}
				else {
					localDataX[i] = dataX[i - 1];
//					localDataY[i] = dataY[i];
					localDataY[i] = dataY[i]/(this->m_dataX[i]-preRecoveryDay);
					preRecoveryDay = m_dataX[i];
				}
			}
			StepLineLayer^ layer0 = c->addStepLineLayer(localDataY, 0x0000FF, "");
			layer0->setXData(localDataX);
			layer0->setLineWidth(2);
			// 추가 및 변경된 코드 끝 라인

			// Output the chart
			chartViewer2->Chart = c;
			chartViewer2->ImageMap = c->getHTMLImageMap("clickable", "", "title='{x}/{value}'");
		}
		// calculate

		//this->m_dataSet->m_resultData->ValueOfTime = m_valueOfTime;
		//this->m_dataSet->m_resultData->PenaltyCost = m_penaltyCost;


		bool CalculateAdditionalCost() {
			try {
				//

				this->m_dataSet->ValueOfTime = m_valueOfTime;
				this->m_dataSet->PenaltyCost = m_penaltyCost;
				this->m_dataSet->TrafficFactor1 = m_trafficFactor1;
				this->m_dataSet->TrafficFactor2 = m_trafficFactor2;


				// chart1, chart2 x data
//				this->m_dataX = gcnew array<double>(4);
				this->m_dataX = gcnew array<double>(5);
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
					this->m_dataX[4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 50;

				}

				array<array<double>^>^ functionalityData = gcnew array<array<double>^>(this->m_dataSet->TrafficScenarios->Length+1);
				array<array<double>^>^ additionalCostData = gcnew array<array<double>^>(this->m_dataSet->TrafficScenarios->Length+1);
				for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++)
				{
					functionalityData[i] = gcnew array<double>(this->m_dataX->Length+1);
					additionalCostData[i] = gcnew array<double>(this->m_dataX->Length+1);

					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
					array<int>^ tmpClosedLinkCount = TrafficModule::GetClosedLinkCount(scenario, this->m_dataX->Length);
					int preRecoveryDay = 0;

					for (int j = 0; j < this->m_dataX->Length; j++)
					{
						int damageState = j + 1;
						// NeXTA 시뮬레이션 결과가 없으면 정상하고 같음
						String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);
						OutputSummary^ outputSummary = nullptr;
						if (this->m_dataSet->NeXTAOutputSummaryDictionary->ContainsKey(key)) {
							outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[key];
							int totalLinkCount = this->m_dataSet->ShapeData->m_nRecords;
							//functionalityData[i][j] = (1.0 - ((double)tmpClosedLinkCount[j] / totalLinkCount)) * 100.0;
							// 기능감소율로 계산
							functionalityData[i][j] = ((double)tmpClosedLinkCount[j] / totalLinkCount) * 100.0;
							
							// 지진 직후 차량 평균 이동시간
							double avgTravelTime_NoDamaged= outputSummary->VT0 / outputSummary->TR0;

							// 도로망 진입 및 진출 차량 대수가 동일한 경우, 다시말해 진입한 모든 차량이 모두 진출한 경우  
							if (outputSummary->TR1 == outputSummary->TR0) {
								double extraVT = outputSummary->VT1 - outputSummary->VT0;
								additionalCostData[i][j] = (extraVT * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2) * (m_dataX[j] - preRecoveryDay);
							}
							// 도로망 진입한 모든 차량이 모두 진출 실패한 경우  
							else if(outputSummary->TR1 == 0) {
								double extraTR = outputSummary->TR0 - outputSummary->TR1;
								additionalCostData[i][j] = (extraTR * m_trafficFactor1 * m_trafficFactor2 * m_penaltyCost) * (m_dataX[j] - preRecoveryDay);
							}
/*
							// 도로망 진입한 차량중 일부만 진출한 경우
							else {
								double extraTR = abs(outputSummary->TR1 - outputSummary->TR0);
								double extraVT = outputSummary->VT1 - (outputSummary->TR0 - outputSummary->TR1) * avgTravelTime;
								// Volume of Time(VT)는 지진 전의 VT보다 같거나 커야 함  
								if (extraVT < 0) {
									extraVT = (outputSummary->TR0 - outputSummary->TR1) * avgTravelTime;
								}
								additionalCostData[i][j] = (extraVT * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2 +
									extraTR * m_trafficFactor1 * m_trafficFactor2 * m_penaltyCost) * (m_dataX[j] - preRecoveryDay);
							}
*/

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
								double leavingVehicle_VT0_VOT   = leavingVehicle_VT0 * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
								double leavingVehicle_VT1_VOT   = leavingVehicle_VT1 * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
								double noLeavingVehicle_VT1_VOT = (outputSummary->TR0 - outputSummary->TR1) * m_dataSet->PenaltyCost * m_trafficFactor1 * m_trafficFactor2;

								// 추가비용 = (max((진출차량VT1_VOT - 진출차량VT0_VOT),0) + 비진출차량VT1_VOT) * 복구일수
								additionalCostData[i][j] = (std::max((leavingVehicle_VT1_VOT - leavingVehicle_VT0_VOT), 0.0) + noLeavingVehicle_VT1_VOT)* (m_dataX[j] - preRecoveryDay);
							}

/*
							double extraVT = outputSummary->VT1 - outputSummary->VT0;
							double extraTR = abs(outputSummary->TR1 - outputSummary->TR0);
							//double extraTR = outputSummary->TR1;
							additionalCostData[i][j] = (extraVT * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2 +
								extraTR * m_trafficFactor1 * m_trafficFactor2 * m_penaltyCost) * (m_dataX[j] - preRecoveryDay);
*/
						}
						else {
							//outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[NeXTAHelper::NORMAL_SCENARIO_ID];
							//functionalityData[i][j] = 100.0;
							functionalityData[i][j] = 0.0;
							additionalCostData[i][j] = 0;
						}
						preRecoveryDay = m_dataX[j];
						//int totalLinkCount = this->m_dataSet->ShapeData->m_nRecords;
						// 전체 링크 대비 사용가능한(열린) 링크 확률
						//functionalityData[i][j] = (1.0 - ((double)tmpClosedLinkCount[j] / totalLinkCount)) * 100.0;
						//additionalCostData[i][j] = outputSummary->Total * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
					}
				}
				//그래프 상에 처음과 마지막에 해당하는 데이터 산출
				//functionalityData[this->m_dataX->Length][this->m_dataX->Length] = 100.0;
				//functionalityData[this->m_dataSet->TrafficScenarios->Length][this->m_dataX->Length] = 0.0;
				//additionalCostData[this->m_dataSet->TrafficScenarios->Length][this->m_dataX->Length] = 0;


				this->m_dataSet->ResultData->Functionalities = functionalityData;
				this->m_dataSet->ResultData->AdditionalCosts = additionalCostData;
				return true;
			}
			catch (Exception^ e) {
				Alert::Error("Chart data calculation failed.");
				return false;
			}
		}

		bool CalculateNetworkStructuralCost() {
			try {
				array<Dictionary<String^, long>^>^ result = gcnew array<Dictionary<String^, long>^>(this->m_dataSet->TrafficScenarios->Length);

				CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->ResultFilePath + "structureCost_summary.csv");
				array<String^>^ columns = {"scenarioNo", "compID", "directDamage"};
				DataTable^ newTable = NewTable(columns);

				for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++)
				{
					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
					result[i] = gcnew Dictionary<String^, long>();
					for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++)
					{
						DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
						String^ compID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
						long value = m_recoveryCost->GetEstimatedTotalComponentStructCost(scenario->SourceName, scenario->RecurrencePeriodName, scenario->Sample.ToString(), compID);
						result[i]->Add(compID, value);

						DataRow^ newRow = nullptr;
						newRow = newTable->NewRow(); // create new row
						newRow["scenarioNo"] = scenario->TrafficScenarioNo;
						newRow["compID"] = compID;
						newRow["directDamage"] = value;
						newTable->Rows->Add(newRow);
					}
				}
				this->m_dataSet->ResultData->NetworkStructuralCosts = result;
				csv->Write(columns, newTable);

				//csv->Write(scenario);

				return true;
			}
			catch (Exception ^ e) {
				Alert::Error("Network structural cost calculation failed.");
				return false;
			}
		}


		
		void SaveComponentScenarios() {
			try {
				CSVFileManager^ csv = gcnew CSVFileManager(this->m_dataSet->ResultFilePath + "ComponentScenarios_summary.csv");
				array<String^>^ columns = { "scenarioNo", "compID", "linkID", "MaxDamage" };
				DataTable^ newTable = NewTable(columns);

				for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++)
				{
					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
					for each (ComponentInfo component in scenario->Components)
					{
						DataRow^ newRow = newTable->NewRow();
						newRow["scenarioNo"] = scenario->TrafficScenarioNo;
						newRow["compID"] = component.ComponentID;
						newRow["linkID"] = component.LinkID;
						newRow["MaxDamage"] = component.MaxDamageState;
						newTable->Rows->Add(newRow);
					}
				}
				csv->Write(columns, newTable);
			}
			catch (Exception ^ e) {
				Alert::Error("Network structural cost calculation failed.");
			}
		}
		

		// update charts
		void UpdateCharts() {
			if (!this->m_isCalculated) {
				return;
			}
			String^ sRunExeName = this->m_dataSet->RunExeName;
			if (String::IsNullOrEmpty(sRunExeName)) {
				UpdateCharts_NEXTA();
			}
			else {
				if (sRunExeName->Equals("NEXTA")) {
					UpdateCharts_NEXTA();
				}
				if (sRunExeName->Equals("UNIST")) {
					UpdateCharts_UNIST();
				}
			}
		}

		// update charts
		void UpdateCharts_NEXTA() {
			if (!this->m_isCalculated) {
				return;
			}
			//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
			//DrawChart1(this->m_dataX, this->m_dataSet->ResultData->GetFunctionality(trafficScenarioNo));
			//DrawChart2(this->m_dataX, this->m_dataSet->ResultData->GetAdditionalCost(trafficScenarioNo));

			///////////////////////////////////////////////////////////////////////////////
			// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다  
			///////////////////////////////////////////////////////////////////////////////
			array<double>^ sumFunctionality = gcnew array<double>(5);  // damage state는 4단계 와 1단계의 정상상태로 5단계 구성됨
			array<double>^ sumAdditionalCost = gcnew array<double>(5);
			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, j+1);
				if(trafficScenarioNo > -1){
					for (int index = 0; index < 5; index++) {
						//비정상(감소)율로 계산된 도로기능
						sumFunctionality[index] = sumFunctionality[index] + this->m_dataSet->ResultData->GetFunctionality(trafficScenarioNo)[index];
						sumAdditionalCost[index] = sumAdditionalCost[index] + this->m_dataSet->ResultData->GetAdditionalCost(trafficScenarioNo)[index];
					}
				}
			}

			// OD평균값으로 정상도로기능 비율 및 추가비용 다시 계산
			for (int index = 0; index < 5; index++) {
				//sumFunctionality[index] = 100. - sumFunctionality[index] ;
				sumFunctionality[index] = 100. - sumFunctionality[index]/ this->m_dataSet->ODZoneParamData->Rows->Count;
				sumAdditionalCost[index] = sumAdditionalCost[index] / this->m_dataSet->ODZoneParamData->Rows->Count;
			}

			DrawChart1(this->m_dataX, sumFunctionality);
			DrawChart2(this->m_dataX, sumAdditionalCost);

		}
	private: System::Void Step10Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->m_isCalculated = false;
		this->radTypicalDayNo->Checked = true;
		this->tbPenaltyCost->Text = CommConst::DEFAULT_PENALTY_COST.ToString();
		this->tbValueOfTime->Text = CommConst::DEFAULT_VALUE_OF_TIME.ToString();

		this->cboSeismicSource->DataSource = this->m_dataSet->SeismicSourceData;
		this->cboSeismicSource->DisplayMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;
		this->cboSeismicSource->ValueMember = CommConst::GRID_SEISMIC_SOURCES_LIST_COL1;

		this->cboSample->Items->AddRange(this->m_dataSet->TrafficScenarioSamples);
		this->cboSample->SelectedIndex = 0;

		// set recurrence periods datasource
		this->cboRecurrencePeriod->Items->AddRange(this->m_dataSet->RecurrencePeriodData);
		this->cboRecurrencePeriod->SelectedIndex = 0;




		//다국어
		String^ sUiLang = CultureInfo::CurrentUICulture->Name;
		String^ sLabel1 = L"PenaltyCost(￦1000)";
		String^ sLabel2 = L"Traffic simulation of typical day";
		String^ sLabel3 = L"Value of Time (￦1000)";
		String^ sLabel4 = L"Traffic factor 1 (from simulated hour to typical day)";
		String^ sLabel5 = L"Traffic factor 2 (from a day of simulated month to a day of a typical month)";
		String^ sLabel6 = L"Seismic source";
		String^ sLabel7 = L"Recurrence period";
		String^ sLabel8 = L"Sample";

		String^ sGroupBox1 = L"Value of Time definition (VOT)";
		String^ sGroupBox2 = L"Non feasable trips";
		String^ sGroupBox3 = L"Output";

		String^ sCalculate = L"Calculate";


		if (sUiLang->Equals("ko-KR")) {
			sLabel1 = L"교통포기비용(천원)";
			sLabel2 = L"교통해석 표준화 여부";
			sLabel3 = L"통행시간 가치(천원)";
			sLabel4 = L"교통계수 1 (단위시간 - 통행량 vs 日통행량 변환계수)";
			sLabel5 = L"교통계수 2 (日단위 - 통행량 vs 月평균 - 日통행량 변환계수)";
			sLabel6 = L"지진원";
			sLabel7 = L"재현주기";
			sLabel8 = L"샘플";

			sGroupBox1 = L"통행시간 가치정의(VOT)";
			sGroupBox2 = L"교통통행 불가";
			sGroupBox3 = L"해석결과";

			sCalculate = L"계산";
		}
		this->label1->Text = sLabel1;
		this->label2->Text = sLabel2;
		this->label3->Text = sLabel3;
		this->label4->Text = sLabel4;
		this->label5->Text = sLabel5;
		this->label6->Text = sLabel6;
		this->label7->Text = sLabel7;
		this->label8->Text = sLabel8;

		this->groupBox1->Text = sGroupBox1;
		this->groupBox2->Text = sGroupBox2;
		this->groupBox3->Text = sGroupBox3;

		this->btnCalculate->Text = sCalculate;

	}
	private: System::Void radTypicalDays_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		RadioButton^ rad = (RadioButton^)sender;
		if (rad == radTypicalDayYes) { // yes
			radTypicalDayNo->Checked = !radTypicalDayYes->Checked;
			this->tbTrafficFactor1->Text = "1.0";
			this->tbTrafficFactor2->Text = "1.0";
			this->tbTrafficFactor1->ReadOnly = true;
			this->tbTrafficFactor2->ReadOnly = true;
		}
		else { // no
			radTypicalDayYes->Checked = !radTypicalDayNo->Checked;
			this->tbTrafficFactor1->Text = CommConst::DEFAULT_TRAFFIC_FACTOR1.ToString();
			this->tbTrafficFactor2->Text = CommConst::DEFAULT_TRAFFIC_FACTOR2.ToString();
			this->tbTrafficFactor1->ReadOnly = false;
			this->tbTrafficFactor2->ReadOnly = false;
		}
	}
	private: System::Void cboSeismicSource_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		UpdateCharts();
	}
	private: System::Void cboRecurrencePeriod_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		UpdateCharts();
	}
	private: System::Void cboSample_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		UpdateCharts();
	}
	private: System::Void btnCalculate_Click(System::Object^  sender, System::EventArgs^  e) {
		/*
		this->m_isCalculated = CalculateAdditionalCost();
		this->m_isCalculated = CalculateNetworkStructuralCost();

		SaveComponentScenarios();

		UpdateCharts();
		OnSaveDataChanged();
		*/


		String^ sRunExeName = this->m_dataSet->RunExeName;
		if (String::IsNullOrEmpty(sRunExeName)) {
			Debug::WriteLine("=============================>sRunExeName IsNullOrEmpty!");
			CalculateNEXTA();
		}
		else {
			if (sRunExeName->Equals("NEXTA")) {
				Debug::WriteLine("=============================>NEXTA");
				CalculateNEXTA();
			}
			if (sRunExeName->Equals("UNIST")) {
				Debug::WriteLine("=============================>UNIST");
				CalculateUNIST();
			}
		}

	}

	private: System::Void CalculateNEXTA() {
		this->m_isCalculated = CalculateAdditionalCost();
		this->m_isCalculated = CalculateNetworkStructuralCost();
		SaveComponentScenarios();
		UpdateCharts_NEXTA();
		OnSaveDataChanged();
	}

	private: System::Void CalculateUNIST() {
		this->m_isCalculated = CalculateAdditionalCost_UNIST();
		this->m_isCalculated = CalculateNetworkStructuralCost_UNIST();
		UpdateCharts_UNIST();
		OnSaveDataChanged();
	}

    // only 숫자 입력만 가능
	private: System::Void numberTypeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void tbValueOfTime_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		Double::TryParse(tbValueOfTime->Text, m_valueOfTime);
	}
	private: System::Void tbTrafficFactor1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		Double::TryParse(tbTrafficFactor1->Text, m_trafficFactor1);
	}
	private: System::Void tbTrafficFactor2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		Double::TryParse(tbTrafficFactor2->Text, m_trafficFactor2);
	}
	private: System::Void tbPenaltyCost_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		Double::TryParse(tbPenaltyCost->Text, m_penaltyCost);
	}
	private: System::Void chartViewer1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		UpdateCharts();
	}
	private: System::Void chartViewer2_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		UpdateCharts();
	}




	private: bool CalculateAdditionalCost_UNIST() {




		try {
			//
			this->m_dataSet->ValueOfTime = m_valueOfTime;
			this->m_dataSet->PenaltyCost = m_penaltyCost;
			// chart1, chart2 x data
//				this->m_dataX = gcnew array<double>(4);
			this->m_dataX = gcnew array<double>(5);
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
				this->m_dataX[4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 50;

			}

			String^ filename = "output_Resilience_curve.xlsx";
			DataTable^ dtOutputFile = m_UNISTHelper->ReadOutputFile(filename);

			if (dtOutputFile != nullptr) {
				//dtOutputFile->Columns->Count;//250

				array<double>^ arrTmpFunctionality = gcnew array<double>(dtOutputFile->Columns->Count);
				for (int i = 0; i < dtOutputFile->Rows->Count; i++) {
					for (int j = 0; j < dtOutputFile->Columns->Count; j++) {
						Double::TryParse(dtOutputFile->Rows[i][j]->ToString(), arrTmpFunctionality[j]);
					}
				}

				//방법이 없어서 50개씩 끊어서 계산해서 5개배열에 넣음
				array<double>^ arrFunctionality = gcnew array<double>(this->m_dataX->Length);
				//가장 큰 값가져옴
				double dMaxVal = 0;
				double dTR0 = 0;//전체차량대수
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 50; j++) {
						int k = i * 50 + j;
						Debug::WriteLine("=================>k:" + k);
						double dVal = arrTmpFunctionality[k];
						Debug::WriteLine("=================>dVal:" + dVal);
						if (dVal > dMaxVal) {
							dMaxVal = dVal;
						}
						if (dVal > dTR0) {
							dTR0 = dVal;
						}
					}
					Debug::WriteLine("=================>dMaxVal:" + dMaxVal);
					arrFunctionality[i] = dMaxVal;
				}
				Debug::WriteLine("=================>dTR0:" + dTR0);



				array<array<double>^>^ functionalityData = gcnew array<array<double>^>(this->m_dataSet->TrafficScenarios->Length + 1);
				array<array<double>^>^ additionalCostData = gcnew array<array<double>^>(this->m_dataSet->TrafficScenarios->Length + 1);
				for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++)
				{
					functionalityData[i] = gcnew array<double>(this->m_dataX->Length + 1);
					additionalCostData[i] = gcnew array<double>(this->m_dataX->Length + 1);

					TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
					//array<int>^ tmpClosedLinkCount = TrafficModule::GetClosedLinkCount(scenario, this->m_dataX->Length);
					int preRecoveryDay = 0;

					for (int j = 0; j < this->m_dataX->Length; j++)
					{
						int damageState = j + 1;
						// NeXTA 시뮬레이션 결과가 없으면 정상하고 같음
						String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);

						//임의로 만들어 줌
						OutputSummary^ outputSummary = gcnew OutputSummary();
						//this->m_dataSet->NeXTAOutputSummaryDictionary->Add(key, outputSummary);


						//OutputSummary^ outputSummary = nullptr;
						//if (this->m_dataSet->NeXTAOutputSummaryDictionary->ContainsKey(key)) {
							//outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[key];

							/*
							int totalLinkCount = this->m_dataSet->ShapeData->m_nRecords;
							//functionalityData[i][j] = (1.0 - ((double)tmpClosedLinkCount[j] / totalLinkCount)) * 100.0;
							// 기능감소율로 계산
							functionalityData[i][j] = ((double)tmpClosedLinkCount[j] / totalLinkCount) * 100.0;
							*/
						functionalityData[i][j] = (1.0 - (arrFunctionality[j] / dTR0)) * 100.0;

						outputSummary->TR1 = arrFunctionality[j];
						outputSummary->TR0 = dTR0;



						// 지진 직후 차량 평균 이동시간
						double avgTravelTime_NoDamaged = outputSummary->VT0 / outputSummary->TR0;

						// 도로망 진입 및 진출 차량 대수가 동일한 경우, 다시말해 진입한 모든 차량이 모두 진출한 경우  
						if (outputSummary->TR1 == outputSummary->TR0) {
							double extraVT = outputSummary->VT1 - outputSummary->VT0;
							additionalCostData[i][j] = (extraVT * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2) * (m_dataX[j] - preRecoveryDay);
						}
						// 도로망 진입한 모든 차량이 모두 진출 실패한 경우  
						else if (outputSummary->TR1 == 0) {
							double extraTR = outputSummary->TR0 - outputSummary->TR1;
							additionalCostData[i][j] = (extraTR * m_trafficFactor1 * m_trafficFactor2 * m_penaltyCost) * (m_dataX[j] - preRecoveryDay);
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
							double leavingVehicle_VT0_VOT = leavingVehicle_VT0 * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
							double leavingVehicle_VT1_VOT = leavingVehicle_VT1 * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
							double noLeavingVehicle_VT1_VOT = (outputSummary->TR0 - outputSummary->TR1) * m_dataSet->PenaltyCost * m_trafficFactor1 * m_trafficFactor2;

							// 추가비용 = (max((진출차량VT1_VOT - 진출차량VT0_VOT),0) + 비진출차량VT1_VOT) * 복구일수
							additionalCostData[i][j] = (std::max((leavingVehicle_VT1_VOT - leavingVehicle_VT0_VOT), 0.0) + noLeavingVehicle_VT1_VOT) * (m_dataX[j] - preRecoveryDay);
						}

						/*
													double extraVT = outputSummary->VT1 - outputSummary->VT0;
													double extraTR = abs(outputSummary->TR1 - outputSummary->TR0);
													//double extraTR = outputSummary->TR1;
													additionalCostData[i][j] = (extraVT * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2 +
														extraTR * m_trafficFactor1 * m_trafficFactor2 * m_penaltyCost) * (m_dataX[j] - preRecoveryDay);
						*/
						//}
						//else {
						//	//outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[NeXTAHelper::NORMAL_SCENARIO_ID];
						//	//functionalityData[i][j] = 100.0;
						//	functionalityData[i][j] = 0.0;
						//	additionalCostData[i][j] = 0;
						//}
						preRecoveryDay = m_dataX[j];
						//int totalLinkCount = this->m_dataSet->ShapeData->m_nRecords;
						// 전체 링크 대비 사용가능한(열린) 링크 확률
						//functionalityData[i][j] = (1.0 - ((double)tmpClosedLinkCount[j] / totalLinkCount)) * 100.0;
						//additionalCostData[i][j] = outputSummary->Total * m_valueOfTime * m_trafficFactor1 * m_trafficFactor2;
					}
				}

				/*
				functionalityData[this->m_dataSet->TrafficScenarios->Length] = gcnew array<double>(this->m_dataX->Length + 1);
				additionalCostData[this->m_dataSet->TrafficScenarios->Length] = gcnew array<double>(this->m_dataX->Length + 1);
				for (int j = 0; j < this->m_dataX->Length; j++) {
					functionalityData[this->m_dataSet->TrafficScenarios->Length][j] = 0.0;
					additionalCostData[this->m_dataSet->TrafficScenarios->Length][j] = 0;
				}
				*/

				this->m_dataSet->ResultData->Functionalities = functionalityData;
				this->m_dataSet->ResultData->AdditionalCosts = additionalCostData;
			}


			return true;
		}
		catch (IndexOutOfRangeException^ e) {
			Debug::WriteLine(e);
			return false;
		}
		catch (Exception^ e) {
			Alert::Error("Chart data calculation failed.");
			return false;
		}
	}


	private: bool CalculateNetworkStructuralCost_UNIST() {
		try {
			array<Dictionary<String^, long>^>^ result = gcnew array<Dictionary<String^, long>^>(this->m_dataSet->TrafficScenarios->Length);
			for (int i = 0; i < this->m_dataSet->TrafficScenarios->Length; i++)
			{
				TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
				result[i] = gcnew Dictionary<String^, long>();
				for (int j = 0; j < this->m_dataSet->NetworkCompnentData->Rows->Count; j++)
				{
					DataRow^ row = this->m_dataSet->NetworkCompnentData->Rows[j];
					String^ compID = row[NetworkComponent::COL_NETWORK_COMP_ID]->ToString();
					long value = m_recoveryCost->GetEstimatedTotalComponentStructCost(scenario->SourceName, scenario->RecurrencePeriodName, scenario->Sample.ToString(), compID);
					result[i]->Add(compID, value);
				}
			}
			this->m_dataSet->ResultData->NetworkStructuralCosts = result;
			return true;
		}
		catch (Exception^ e) {
			Alert::Error("Network structural cost calculation failed.");
			return false;
		}

	}

	private: void UpdateCharts_UNIST() {
		if (!this->m_isCalculated) {
			return;
		}
		//int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
		//DrawChart1(this->m_dataX, this->m_dataSet->ResultData->GetFunctionality(trafficScenarioNo));
		//DrawChart2(this->m_dataX, this->m_dataSet->ResultData->GetAdditionalCost(trafficScenarioNo));

		///////////////////////////////////////////////////////////////////////////////
		// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다  
		///////////////////////////////////////////////////////////////////////////////
		array<double>^ sumFunctionality = gcnew array<double>(5);  // damage state는 4단계 와 1단계의 정상상태로 5단계 구성됨
		array<double>^ sumAdditionalCost = gcnew array<double>(5);
		for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {

			int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, j + 1);
			if (trafficScenarioNo > -1) {
				for (int index = 0; index < 5; index++) {
					//비정상(감소)율로 계산된 도로기능
					sumFunctionality[index] = sumFunctionality[index] + this->m_dataSet->ResultData->GetFunctionality(trafficScenarioNo)[index];
					sumAdditionalCost[index] = sumAdditionalCost[index] + this->m_dataSet->ResultData->GetAdditionalCost(trafficScenarioNo)[index];
				}
			}
		}

		//정상비율로 도로기능을 다시 계산
		for (int index = 0; index < 5; index++) {
			sumFunctionality[index] = 100. - sumFunctionality[index];
		}

		DrawChart1(this->m_dataX, sumFunctionality);
		DrawChart2(this->m_dataX, sumAdditionalCost);


	}


	};
}
