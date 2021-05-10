#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "ComponentClassInfo.h"
#include "ChartHotspotAttrDialog.h"
#include "ShapeChartAttribute.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step3Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step3Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step3Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^			m_dataSet;
		ShapeChart^						m_chart;
		array<ComponentClassInfo>^		m_chartDatas;
		NetworkComponent^				m_networkComponent;

	private: ChartDirector::WinChartViewer^  chartViewer;
	public:
		Step3Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();

			this->m_dataSet = dataSet;
			m_chart = gcnew ShapeChart(m_dataSet->ShapeData);
			m_networkComponent = gcnew NetworkComponent(this->m_dataSet);
		}
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step3Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvNetworkComponent;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^  dgvCompClass;

	private: System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dgvNetworkComponent = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dgvCompClass = (gcnew System::Windows::Forms::DataGridView());
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCompClass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvNetworkComponent
			// 
			this->dgvNetworkComponent->AllowUserToAddRows = false;
			this->dgvNetworkComponent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvNetworkComponent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvNetworkComponent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvNetworkComponent->Location = System::Drawing::Point(3, 3);
			this->dgvNetworkComponent->MultiSelect = false;
			this->dgvNetworkComponent->Name = L"dgvNetworkComponent";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgvNetworkComponent->RowTemplate->Height = 23;
			this->dgvNetworkComponent->Size = System::Drawing::Size(807, 222);
			this->dgvNetworkComponent->TabIndex = 0;
			this->dgvNetworkComponent->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step3Form::dgvNetworkComponent_DataBindingComplete);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->dgvCompClass, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->dgvNetworkComponent, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 761);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// dgvCompClass
			// 
			this->dgvCompClass->AllowUserToAddRows = false;
			this->dgvCompClass->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvCompClass->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvCompClass->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCompClass->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvCompClass->Location = System::Drawing::Point(816, 3);
			this->dgvCompClass->MultiSelect = false;
			this->dgvCompClass->Name = L"dgvCompClass";
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::GrayText;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvCompClass->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dgvCompClass->RowTemplate->Height = 23;
			this->dgvCompClass->Size = System::Drawing::Size(265, 222);
			this->dgvCompClass->TabIndex = 1;
			this->dgvCompClass->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Step3Form::dgvCompClass_DataBindingComplete);
			// 
			// chartViewer
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->chartViewer, 2);
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->HotSpotCursor = System::Windows::Forms::Cursors::Hand;
			this->chartViewer->Location = System::Drawing::Point(3, 231);
			this->chartViewer->Name = L"chartViewer";
			this->chartViewer->Size = System::Drawing::Size(1078, 527);
			this->chartViewer->TabIndex = 5;
			this->chartViewer->TabStop = false;
			this->chartViewer->ClickHotSpot += gcnew ChartDirector::WinHotSpotEventHandler(this, &Step3Form::chartViewer_ClickHotSpot);
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step3Form::chartViewer_SizeChanged);
			// 
			// Step3Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step3Form";
			this->Text = L"Definition network component classes";
			this->Load += gcnew System::EventHandler(this, &Step3Form::Step3Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNetworkComponent))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCompClass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}
	private:
		void DrawNetworkComponentChart() {
			m_chart->DrawNetworkComponents(chartViewer, "Network components", m_chartDatas);
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
	private: System::Void Step3Form_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridViewCellStyle = (gcnew DataGridViewCellStyle());
		this->dataGridViewCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewCellStyle->BackColor = Color::LightGray;
		this->dataGridViewCellStyle->Font = (gcnew System::Drawing::Font(L"굴림", 10, System::Drawing::FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(129)));
		this->dataGridViewCellStyle->ForeColor = System::Drawing::SystemColors::WindowText;
		this->dataGridViewCellStyle->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		this->dataGridViewCellStyle->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridViewCellStyle->WrapMode = DataGridViewTriState::True;

		dgvNetworkComponent->DataSource = m_dataSet->NetworkCompnentData;
		dgvCompClass->DataSource = m_dataSet->ComponentClassData;
		// create chart data
		CreateNetworkComponentChartData();
		DrawNetworkComponentChart();
	}
	private: System::Void dgvNetworkComponent_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		// Set grid row number and style
		int i = 1;
		for each(DataGridViewRow^ row in dgvNetworkComponent->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvNetworkComponent->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvNetworkComponent->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvNetworkComponent->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvNetworkComponent->EnableHeadersVisualStyles = false;
	}
	private: System::Void dgvCompClass_DataBindingComplete(System::Object^  sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^  e) {
		// Set grid row number and style
		int i = 1;
		for each(DataGridViewRow^ row in dgvCompClass->Rows) {
			if (row->IsNewRow) continue;
			row->HeaderCell->Value = String::Format("{0}", i++);
		}
		this->dgvCompClass->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		this->dgvCompClass->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvCompClass->RowHeadersDefaultCellStyle = dataGridViewCellStyle;
		this->dgvCompClass->EnableHeadersVisualStyles = false;
	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawNetworkComponentChart();
	}
	private: System::Void chartViewer_ClickHotSpot(System::Object^  sender, ChartDirector::WinHotSpotEventArgs^  e) {
		ChartHotspotAttrDialog^ dlg = gcnew ChartHotspotAttrDialog(this->m_dataSet);
		dlg->Display(sender, e);
	}
	};
}
