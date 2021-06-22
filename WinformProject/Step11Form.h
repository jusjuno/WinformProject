#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "NetworkComponent.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;


	/// <summary>
	/// Step11Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step11Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step11Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		NetworkComponent^			m_networkComponent;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::ComboBox^  cboSeismicSource;
	private: System::Windows::Forms::ComboBox^  cboSample;



	public:
		Step11Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_networkComponent = gcnew NetworkComponent(dataSet);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step11Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cboRecurrencePeriod;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbTotNetStructCost;
	private: System::Windows::Forms::TextBox^  tbTotTrafficCost;
	private: System::Windows::Forms::TextBox^  tbTotCost;

	private: System::Windows::Forms::TextBox^  tbEconomv;
	private: System::Windows::Forms::TextBox^  tbConnectivity;
	private: System::Windows::Forms::TextBox^  tbEnvironment;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  cboComponent;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbCompStructCost;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Step11Form::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboRecurrencePeriod = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbTotNetStructCost = (gcnew System::Windows::Forms::TextBox());
			this->tbTotTrafficCost = (gcnew System::Windows::Forms::TextBox());
			this->tbTotCost = (gcnew System::Windows::Forms::TextBox());
			this->tbEconomv = (gcnew System::Windows::Forms::TextBox());
			this->tbConnectivity = (gcnew System::Windows::Forms::TextBox());
			this->tbEnvironment = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbCompStructCost = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cboComponent = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->cboSeismicSource = (gcnew System::Windows::Forms::ComboBox());
			this->cboSample = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->cboRecurrencePeriod, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label11, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label12, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSeismicSource, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->cboSample, 1, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// cboRecurrencePeriod
			// 
			this->cboRecurrencePeriod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRecurrencePeriod->FormattingEnabled = true;
			resources->ApplyResources(this->cboRecurrencePeriod, L"cboRecurrencePeriod");
			this->cboRecurrencePeriod->Name = L"cboRecurrencePeriod";
			this->cboRecurrencePeriod->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step11Form::cboRecurrencePeriod_SelectionChangeCommitted);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->tableLayoutPanel1->SetColumnSpan(this->groupBox1, 2);
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// tableLayoutPanel2
			// 
			resources->ApplyResources(this->tableLayoutPanel2, L"tableLayoutPanel2");
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->label6, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->label7, 0, 5);
			this->tableLayoutPanel2->Controls->Add(this->label8, 0, 6);
			this->tableLayoutPanel2->Controls->Add(this->tbTotNetStructCost, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->tbTotTrafficCost, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->tbTotCost, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->tbEconomv, 1, 4);
			this->tableLayoutPanel2->Controls->Add(this->tbConnectivity, 1, 5);
			this->tableLayoutPanel2->Controls->Add(this->tbEnvironment, 1, 6);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// tbTotNetStructCost
			// 
			resources->ApplyResources(this->tbTotNetStructCost, L"tbTotNetStructCost");
			this->tbTotNetStructCost->Name = L"tbTotNetStructCost";
			this->tbTotNetStructCost->ReadOnly = true;
			// 
			// tbTotTrafficCost
			// 
			resources->ApplyResources(this->tbTotTrafficCost, L"tbTotTrafficCost");
			this->tbTotTrafficCost->Name = L"tbTotTrafficCost";
			this->tbTotTrafficCost->ReadOnly = true;
			// 
			// tbTotCost
			// 
			resources->ApplyResources(this->tbTotCost, L"tbTotCost");
			this->tbTotCost->Name = L"tbTotCost";
			this->tbTotCost->ReadOnly = true;
			// 
			// tbEconomv
			// 
			resources->ApplyResources(this->tbEconomv, L"tbEconomv");
			this->tbEconomv->Name = L"tbEconomv";
			this->tbEconomv->ReadOnly = true;
			// 
			// tbConnectivity
			// 
			resources->ApplyResources(this->tbConnectivity, L"tbConnectivity");
			this->tbConnectivity->Name = L"tbConnectivity";
			this->tbConnectivity->ReadOnly = true;
			// 
			// tbEnvironment
			// 
			resources->ApplyResources(this->tbEnvironment, L"tbEnvironment");
			this->tbEnvironment->Name = L"tbEnvironment";
			this->tbEnvironment->ReadOnly = true;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->tableLayoutPanel1->SetColumnSpan(this->groupBox2, 2);
			this->groupBox2->Controls->Add(this->tableLayoutPanel3);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			// 
			// tableLayoutPanel3
			// 
			resources->ApplyResources(this->tableLayoutPanel3, L"tableLayoutPanel3");
			this->tableLayoutPanel3->Controls->Add(this->label10, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->tbCompStructCost, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			// 
			// tbCompStructCost
			// 
			resources->ApplyResources(this->tbCompStructCost, L"tbCompStructCost");
			this->tbCompStructCost->Name = L"tbCompStructCost";
			this->tbCompStructCost->ReadOnly = true;
			// 
			// tableLayoutPanel4
			// 
			resources->ApplyResources(this->tableLayoutPanel4, L"tableLayoutPanel4");
			this->tableLayoutPanel3->SetColumnSpan(this->tableLayoutPanel4, 2);
			this->tableLayoutPanel4->Controls->Add(this->label9, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->cboComponent, 1, 0);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			// 
			// cboComponent
			// 
			this->cboComponent->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->cboComponent, L"cboComponent");
			this->cboComponent->FormattingEnabled = true;
			this->cboComponent->Name = L"cboComponent";
			this->cboComponent->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step11Form::cboComponent_SelectionChangeCommitted);
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			// 
			// cboSeismicSource
			// 
			this->cboSeismicSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSeismicSource->FormattingEnabled = true;
			resources->ApplyResources(this->cboSeismicSource, L"cboSeismicSource");
			this->cboSeismicSource->Name = L"cboSeismicSource";
			this->cboSeismicSource->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step11Form::cboSeismicSource_SelectionChangeCommitted);
			// 
			// cboSample
			// 
			this->cboSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSample->FormattingEnabled = true;
			resources->ApplyResources(this->cboSample, L"cboSample");
			this->cboSample->Name = L"cboSample";
			this->cboSample->SelectionChangeCommitted += gcnew System::EventHandler(this, &Step11Form::cboSample_SelectionChangeCommitted);
			// 
			// Step11Form
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"Step11Form";
			this->Load += gcnew System::EventHandler(this, &Step11Form::Step11Form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
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
			//else if (!this->m_dataSet->ResultData->IsCalculatedLossfactor) {
			//	Alert::Info("Loss factor has been not calculated.");
			//	return false;
			//}
			return true;
		}
	private:
		// update network level components
		void UpdateNetworkLevel() {
			if (cboRecurrencePeriod->SelectedIndex < 0) {
				return;
			}

			///////////////////////////////////////////////////////////////////////////////
			// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
			///////////////////////////////////////////////////////////////////////////////
/*
			int trafficSecnarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
			// estimated total network structural cost
			long totalNetworkStructCost = this->m_dataSet->ResultData->GetTotalNetworkStructuralCost(trafficSecnarioNo);
			this->tbTotNetStructCost->Text = StringUtil::DecimalFormatWithComma(totalNetworkStructCost);
*/
			int odLocalIndex = 1;
			int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);
			long totalNetworkStructCost = this->m_dataSet->ResultData->GetTotalNetworkStructuralCost(trafficScenarioNo);
			this->tbTotNetStructCost->Text = StringUtil::DecimalFormatWithComma(totalNetworkStructCost);

			// estimated total traffic cost
			///////////////////////////////////////////////////////////////////////////////
			// 간접피해 계산: 간접피해는 od zone에 따른 간접피해(추가교통량) 합산으로 구한다  
			///////////////////////////////////////////////////////////////////////////////
/*
			long totalTrafficCost = this->m_dataSet->ResultData->GetTotalTrafficCost(trafficSecnarioNo);
			this->tbTotTrafficCost->Text = StringUtil::DecimalFormatWithComma(totalTrafficCost);
*/
			// 여기서 j+1은 OD index가 1부터 시작되기 때문임
			long totalTrafficCost = 0;
			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int localTrafficScenarioNo;
				localTrafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, j+1);
				totalTrafficCost += this->m_dataSet->ResultData->GetTotalTrafficCost(trafficScenarioNo);
			}
			this->tbTotTrafficCost->Text = StringUtil::DecimalFormatWithComma(totalTrafficCost);

			// estimated total cost(network + traffic)
			this->tbTotCost->Text = StringUtil::DecimalFormatWithComma(totalNetworkStructCost + totalTrafficCost);







			/// Resilience indices
			////////////////////////////////////////////////////////////////////////////////////////
			// 지수값은 ResultDataSet.h에 (1)개별OD에 대한 지수값, (2)통합OD에 대한 지수값 순으로 저장됨  
			////////////////////////////////////////////////////////////////////////////////////////
			/*
			int totalOD = this->m_dataSet->ODZoneParamData->Rows->Count;
			//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;

			// 통합지수값이 저장된 index 번호
			int indicesIndex = (unitScenarioStep * totalOD) + trafficScenarioNo ;
                                // 개별지수값 번호              // 통합지숙값 번호 
			// economv
			this->tbEconomv->Text = StringUtil::DecimalFormat(2, this->m_dataSet->ResultData->GetTotalEconomicLossIndices(indicesIndex));
			// connectivity
			this->tbConnectivity->Text = StringUtil::DecimalFormat(2, this->m_dataSet->ResultData->GetTotalConnectivityLossIndices(indicesIndex));
			// environment
			this->tbEnvironment->Text = StringUtil::DecimalFormat(2, this->m_dataSet->ResultData->GetTotalEnvironmentLossIndices(indicesIndex));

			*/

			/*double sumECOindices = 0;
			double sumCONindices = 0;
			double sumENVindices = 0;
			for (int j = 0; j < this->m_dataSet->ODZoneParamData->Rows->Count; j++) {
				int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, j+1);
				sumECOindices = sumECOindices + this->m_dataSet->ResultData->GetTotalEconomicLossIndices(trafficScenarioNo);
				sumCONindices = sumCONindices + this->m_dataSet->ResultData->GetTotalConnectivityLossIndices(trafficScenarioNo);
				sumENVindices = sumENVindices + this->m_dataSet->ResultData->GetTotalEnvironmentLossIndices(trafficScenarioNo);
			}*/



		}
		// update component level components
		void UpdateComponentLevel() {
			if (cboRecurrencePeriod->SelectedIndex < 0 && cboComponent->SelectedIndex < 0) {
				return;
			}
			///////////////////////////////////////////////////////////////////////////////
			// 직접피해 계산: 직접피해는 od zone과 관계없어므로, 대표 odIndex값 "1"을 사용한다. 
			///////////////////////////////////////////////////////////////////////////////
			//int trafficSecnarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1);
			int odLocalIndex = 1;
			int trafficScenarioNo = this->m_dataSet->GetTrafficScenarioNo(cboSeismicSource->SelectedIndex, cboRecurrencePeriod->SelectedIndex, cboSample->SelectedIndex + 1, odLocalIndex);

			DataRowView^ componentRow = (DataRowView^)cboComponent->SelectedItem;
			String^ componentID = componentRow[m_networkComponent->GetColumnName(NetworkComponent::COL_NETWORK_COMP_ID)]->ToString();
			double value = this->m_dataSet->ResultData->GetComponentStructuralCost(trafficScenarioNo, componentID);
			this->tbCompStructCost->Text = StringUtil::DecimalFormatWithComma(value);
		}
		// 둘다 업데이트 
		void UpdateForm() {
			UpdateNetworkLevel();
			UpdateComponentLevel();
		}

	private: System::Void Step11Form_Load(System::Object^  sender, System::EventArgs^  e) {
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

		// Set component combobox datasource
		this->cboComponent->DataSource = m_dataSet->NetworkCompnentData;
		this->cboComponent->DisplayMember = m_networkComponent->GetColumnName(NetworkComponent::COL_NETWORK_COMP_ID);
		this->cboComponent->ValueMember = m_networkComponent->GetColumnName(NetworkComponent::COL_CLASS_ID);
		UpdateForm();
	}
	private: System::Void cboRecurrencePeriod_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateForm();
	}
	private: System::Void cboSeismicSource_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateForm();
	}
	private: System::Void cboSample_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		UpdateForm();
	}
	private: System::Void cboComponent_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		// 컴포넌트 코스트 업데이트
		UpdateComponentLevel();
	}
	};
}
