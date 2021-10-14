#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "CommConst.h"
//#include "FragilityDataSet.h"

#include "PreferenceForm.h"
#include <string>
#include "BaseForm.h"
namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::IO;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	
	/*
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::IO;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;
	using namespace System::Resources;
	*/

	/// <summary>
	/// UserDefineForm에 대한 요약입니다.
	/// </summary>
	public ref class UserDefineForm : public System::Windows::Forms::Form
	//public ref class UserDefineForm : public WinformProject::BaseForm
	{


	public:

		UserDefineForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;

		}

		String^ sConstDefalut;

		UserDefineForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			
			
			// 
			//
	
		}


	public: void receiveFormEvent(String^ str) {

		sConstDefalut = str;
	}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~UserDefineForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ProjectDataSetBinder^ m_dataSet;
		BaseForm^ m_BaseForm;
		//PreferenceForm^ m_preferenceForm;

	private: System::Windows::Forms::Label^ label1;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;




	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox9;


	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox13;

	private: System::Windows::Forms::TextBox^ textBox12;

	private: System::Windows::Forms::TextBox^ textBox11;


	private: System::Windows::Forms::TextBox^ textBox10;








	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(23, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"STATE1 :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(23, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"STATE2 :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(23, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"STATE3 :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(23, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 15);
			this->label4->TabIndex = 3;
			this->label4->Text = L"STATE4 :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(23, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"REF :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 25);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(58, 25);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->groupBox1->Location = System::Drawing::Point(10, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Size = System::Drawing::Size(285, 212);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"TRAFFIC_CARRYING_DAMAGE";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(113, 175);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(58, 25);
			this->textBox5->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(113, 138);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(58, 25);
			this->textBox4->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(113, 100);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(58, 25);
			this->textBox3->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(113, 62);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 25);
			this->textBox2->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->groupBox2->Location = System::Drawing::Point(10, 265);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox2->Size = System::Drawing::Size(285, 186);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"REPAIR_COST_RATIO_DAMAGE";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(113, 138);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(58, 25);
			this->textBox9->TabIndex = 8;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(113, 100);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(58, 25);
			this->textBox8->TabIndex = 7;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(113, 62);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(58, 25);
			this->textBox7->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(23, 144);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 15);
			this->label7->TabIndex = 8;
			this->label7->Text = L"STATE4 :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(23, 106);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 15);
			this->label8->TabIndex = 7;
			this->label8->Text = L"STATE3 :";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label9->Location = System::Drawing::Point(23, 69);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(69, 15);
			this->label9->TabIndex = 6;
			this->label9->Text = L"STATE2 :";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(113, 25);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(58, 25);
			this->textBox6->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(23, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 15);
			this->label6->TabIndex = 5;
			this->label6->Text = L"STATE1 :";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox13);
			this->groupBox3->Controls->Add(this->textBox12);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->groupBox3->Location = System::Drawing::Point(346, 15);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox3->Size = System::Drawing::Size(285, 212);
			this->groupBox3->TabIndex = 14;
			this->groupBox3->TabStop = false;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(187, 138);
			this->textBox13->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(58, 25);
			this->textBox13->TabIndex = 12;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(187, 100);
			this->textBox12->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(58, 25);
			this->textBox12->TabIndex = 11;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(187, 62);
			this->textBox11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(58, 25);
			this->textBox11->TabIndex = 10;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(187, 25);
			this->textBox10->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(58, 25);
			this->textBox10->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label11->Location = System::Drawing::Point(23, 144);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(126, 15);
			this->label11->TabIndex = 12;
			this->label11->Text = L"PENALTY_COST :";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label12->Location = System::Drawing::Point(23, 106);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(129, 15);
			this->label12->TabIndex = 11;
			this->label12->Text = L"VALUE_OF_TIME :";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label13->Location = System::Drawing::Point(23, 69);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(146, 15);
			this->label13->TabIndex = 10;
			this->label13->Text = L"TRAFFIC_FACTOR2 :";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label14->Location = System::Drawing::Point(23, 31);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(146, 15);
			this->label14->TabIndex = 9;
			this->label14->Text = L"TRAFFIC_FACTOR1 :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(505, 385);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 56);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserDefineForm::button1_Click);
			// 
			// UserDefineForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(673, 478);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"UserDefineForm";
			this->Text = L"UserDefineForm";
			this->Load += gcnew System::EventHandler(this, &UserDefineForm::UserDefineForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void UserDefineForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (this->m_dataSet != nullptr) {
			if (this->m_dataSet->constDefault_DataSet_Str != nullptr) {

				this->textBox1->Text = this->m_dataSet->constDefault_DataSet_Str[0]->ToString();
				this->textBox2->Text = this->m_dataSet->constDefault_DataSet_Str[1]->ToString();
				this->textBox3->Text = this->m_dataSet->constDefault_DataSet_Str[2]->ToString();
				this->textBox4->Text = this->m_dataSet->constDefault_DataSet_Str[3]->ToString();
				this->textBox5->Text = this->m_dataSet->constDefault_DataSet_Str[4]->ToString();

				this->textBox6->Text = this->m_dataSet->constDefault_DataSet_Str[5]->ToString();
				this->textBox7->Text = this->m_dataSet->constDefault_DataSet_Str[6]->ToString();
				this->textBox8->Text = this->m_dataSet->constDefault_DataSet_Str[7]->ToString();
				this->textBox9->Text = this->m_dataSet->constDefault_DataSet_Str[8]->ToString();

				this->textBox10->Text = this->m_dataSet->constDefault_DataSet_Str[9]->ToString();
				this->textBox11->Text = this->m_dataSet->constDefault_DataSet_Str[10]->ToString();
				this->textBox12->Text = this->m_dataSet->constDefault_DataSet_Str[11]->ToString();
				this->textBox13->Text = this->m_dataSet->constDefault_DataSet_Str[12]->ToString();

			}

			else {

				this->textBox1->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1.ToString();
				this->textBox2->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2.ToString();
				this->textBox3->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3.ToString();
				this->textBox4->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4.ToString();
				this->textBox5->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF.ToString();

				this->textBox6->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1.ToString();
				this->textBox7->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2.ToString();
				this->textBox8->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3.ToString();
				this->textBox9->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4.ToString();

				this->textBox10->Text = CommConst::DEFAULT_TRAFFIC_FACTOR1.ToString();
				this->textBox11->Text = CommConst::DEFAULT_TRAFFIC_FACTOR2.ToString();
				this->textBox12->Text = CommConst::DEFAULT_VALUE_OF_TIME.ToString();
				this->textBox13->Text = CommConst::DEFAULT_PENALTY_COST.ToString();
			}
		}
		else {

		

			this->textBox1->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1.ToString();
			this->textBox2->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2.ToString();
			this->textBox3->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3.ToString();
			this->textBox4->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4.ToString();
			this->textBox5->Text = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF.ToString();

			this->textBox6->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1.ToString();
			this->textBox7->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2.ToString();
			this->textBox8->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3.ToString();
			this->textBox9->Text = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4.ToString();

			this->textBox10->Text = CommConst::DEFAULT_TRAFFIC_FACTOR1.ToString();
			this->textBox11->Text = CommConst::DEFAULT_TRAFFIC_FACTOR2.ToString();
			this->textBox12->Text = CommConst::DEFAULT_VALUE_OF_TIME.ToString();
			this->textBox13->Text = CommConst::DEFAULT_PENALTY_COST.ToString();
		}
	

		if (this->m_dataSet != nullptr) {
			this->sConstDefalut = this->m_dataSet->ConstDefalut;
		}

		if (this->sConstDefalut->Equals("N") || this->sConstDefalut == nullptr) {


			this->textBox1->Enabled = true;
			this->textBox2->Enabled = true;
			this->textBox3->Enabled = true;
			this->textBox4->Enabled = true;
			this->textBox5->Enabled = true;
			this->textBox6->Enabled = true;
			this->textBox7->Enabled = true;
			this->textBox8->Enabled = true;
			this->textBox9->Enabled = true;
			this->textBox10->Enabled = true;
			this->textBox11->Enabled = true;
			this->textBox12->Enabled = true;
			this->textBox13->Enabled = true;

		}
		else {
			this->textBox1->Text = CommConst::CONST_DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1.ToString();
			this->textBox2->Text = CommConst::CONST_DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2.ToString();
			this->textBox3->Text = CommConst::CONST_DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3.ToString();
			this->textBox4->Text = CommConst::CONST_DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4.ToString();
			this->textBox5->Text = CommConst::CONST_DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF.ToString();

			this->textBox6->Text = CommConst::CONST_DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1.ToString();
			this->textBox7->Text = CommConst::CONST_DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2.ToString();
			this->textBox8->Text = CommConst::CONST_DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3.ToString();
			this->textBox9->Text = CommConst::CONST_DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4.ToString();

			this->textBox10->Text = CommConst::CONST_DEFAULT_TRAFFIC_FACTOR1.ToString();
			this->textBox11->Text = CommConst::CONST_DEFAULT_TRAFFIC_FACTOR2.ToString();
			this->textBox12->Text = CommConst::CONST_DEFAULT_VALUE_OF_TIME.ToString();
			this->textBox13->Text = CommConst::CONST_DEFAULT_PENALTY_COST.ToString();

			this->textBox1->Enabled = false;
			this->textBox2->Enabled = false;
			this->textBox3->Enabled = false;
			this->textBox4->Enabled = false;
			this->textBox5->Enabled = false;
			this->textBox6->Enabled = false;
			this->textBox7->Enabled = false;
			this->textBox8->Enabled = false;
			this->textBox9->Enabled = false;
			this->textBox10->Enabled = false;
			this->textBox11->Enabled = false;
			this->textBox12->Enabled = false;
			this->textBox13->Enabled = false;
		}

	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->sConstDefalut->Equals("N")) {

			if (!ValidateRequired()) {
				return;
			}

			CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1 = double::Parse(this->textBox1->Text);
			CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2 = double::Parse(this->textBox2->Text);
			CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3 = double::Parse(this->textBox3->Text);
			CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 = double::Parse(this->textBox4->Text);
			CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF = double::Parse(this->textBox5->Text);

			CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1 = double::Parse(this->textBox6->Text);
			CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2 = double::Parse(this->textBox7->Text);
			CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3 = double::Parse(this->textBox8->Text);
			CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4 = double::Parse(this->textBox9->Text);

			CommConst::DEFAULT_TRAFFIC_FACTOR1 = double::Parse(this->textBox10->Text);
			CommConst::DEFAULT_TRAFFIC_FACTOR2 = double::Parse(this->textBox11->Text);
			CommConst::DEFAULT_VALUE_OF_TIME = int::Parse(this->textBox12->Text);
			CommConst::DEFAULT_PENALTY_COST = int::Parse(this->textBox13->Text);
			if (this->m_dataSet != nullptr) {
				updateConstDefault();
			}
		}


		//std::cout << " 확인: "  << std::endl;
		Close();

			
	}

	// Get the flag that is created instance a step form


	// Set enable/disable result menu by rdoSeismicBef/rdoSeismicAft
	public:	void initDefalutSet() {
		CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1 = 0.6;
		CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2 = 2.5;
		CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3 = 75;
		CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 = 230;
		CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF = 250;

		CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1 = 0.03;
		CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2 = 0.25;
		CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3 = 0.75;
		CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4 = 1;

		CommConst::DEFAULT_TRAFFIC_FACTOR1 = 16.08;
		CommConst::DEFAULT_TRAFFIC_FACTOR2 = 1.18;
		CommConst::DEFAULT_VALUE_OF_TIME = 9;
		CommConst::DEFAULT_PENALTY_COST = 20;
	}

		  // 기본 상수 설정
	public: void updateConstDefault() {

		this->m_dataSet->constDefault_DataSet_Str = gcnew array<String^>(13);
		this->m_dataSet->constDefault_DataSet_Str[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1.ToString();
		this->m_dataSet->constDefault_DataSet_Str[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2.ToString();
		this->m_dataSet->constDefault_DataSet_Str[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3.ToString();
		this->m_dataSet->constDefault_DataSet_Str[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4.ToString();
		this->m_dataSet->constDefault_DataSet_Str[4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF.ToString();

		this->m_dataSet->constDefault_DataSet_Str[5] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1.ToString();
		this->m_dataSet->constDefault_DataSet_Str[6] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2.ToString();
		this->m_dataSet->constDefault_DataSet_Str[7] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3.ToString();
		this->m_dataSet->constDefault_DataSet_Str[8] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4.ToString();

		this->m_dataSet->constDefault_DataSet_Str[9] = CommConst::DEFAULT_TRAFFIC_FACTOR1.ToString();
		this->m_dataSet->constDefault_DataSet_Str[10] = CommConst::DEFAULT_TRAFFIC_FACTOR2.ToString();
		this->m_dataSet->constDefault_DataSet_Str[11] = CommConst::DEFAULT_VALUE_OF_TIME.ToString();
		this->m_dataSet->constDefault_DataSet_Str[12] = CommConst::DEFAULT_PENALTY_COST.ToString();
	
	}

	// 필수값 체크
	bool ValidateRequired() {
		bool require_all = true;

		if (String::IsNullOrEmpty(this->textBox1->Text) || String::IsNullOrEmpty(this->textBox2->Text) || String::IsNullOrEmpty(this->textBox3->Text) || String::IsNullOrEmpty(this->textBox4->Text) 
			|| String::IsNullOrEmpty(this->textBox5->Text) || String::IsNullOrEmpty(this->textBox6->Text) || String::IsNullOrEmpty(this->textBox7->Text) || String::IsNullOrEmpty(this->textBox7->Text)
			|| String::IsNullOrEmpty(this->textBox8->Text) || String::IsNullOrEmpty(this->textBox8->Text) || String::IsNullOrEmpty(this->textBox9->Text) || String::IsNullOrEmpty(this->textBox10->Text)
			|| String::IsNullOrEmpty(this->textBox11->Text) || String::IsNullOrEmpty(this->textBox12->Text)) {

			require_all = false;
		}
		if (require_all == false) {
			Alert::Error("please fill in the blanks.");
			//this->textBox4->Focus();
			return false;
		}
		return true;
	}

};
}
