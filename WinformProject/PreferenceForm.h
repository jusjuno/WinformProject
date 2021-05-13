#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"


namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Diagnostics;
	using namespace System::Globalization;

	/// <summary>
	/// PreferenceForm에 대한 요약입니다.
	/// </summary>
	//public ref class PreferenceForm : public System::Windows::Forms::Form
	public ref class PreferenceForm : public WinformProject::BaseForm
	{

	private:
		ProjectDataSetBinder^ m_dataSet;

	public:
		delegate void FormSendDataHandler(String^ log);
		event FormSendDataHandler^ form2SendEvent;


	
	public:
		PreferenceForm()
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		PreferenceForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~PreferenceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ radioKor;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioEng;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PreferenceForm::typeid));
			this->radioKor = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioEng = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioKor
			// 
			resources->ApplyResources(this->radioKor, L"radioKor");
			this->radioKor->Name = L"radioKor";
			this->radioKor->TabStop = true;
			this->radioKor->UseVisualStyleBackColor = true;
			this->radioKor->Click += gcnew System::EventHandler(this, &PreferenceForm::radioKor_Click);
			// 
			// groupBox1
			// 
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Controls->Add(this->radioEng);
			this->groupBox1->Controls->Add(this->radioKor);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// radioEng
			// 
			resources->ApplyResources(this->radioEng, L"radioEng");
			this->radioEng->Name = L"radioEng";
			this->radioEng->TabStop = true;
			this->radioEng->UseVisualStyleBackColor = true;
			this->radioEng->Click += gcnew System::EventHandler(this, &PreferenceForm::radioEng_Click);
			// 
			// PreferenceForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->groupBox1);
			this->Name = L"PreferenceForm";
			this->Load += gcnew System::EventHandler(this, &PreferenceForm::PreferenceForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void radioKor_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->m_dataSet != nullptr) {
			this->m_dataSet->UiLang = "ko-KR";
		}
		CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("ko-KR");//Localization과 관련
		this->form2SendEvent("ko-KR");
	}
	private: System::Void radioEng_Click(System::Object^ sender, System::EventArgs^ e) {

		

		if (this->m_dataSet != nullptr) {
			this->m_dataSet->UiLang = "en-US";
		}
		CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("en-US");//Localization과 관련
		this->form2SendEvent("en-US");
	}
	private: System::Void PreferenceForm_Load(System::Object^ sender, System::EventArgs^ e) {

		if (this->m_dataSet != nullptr) {
			String^ sUiLang = this->m_dataSet->UiLang;
			if (String::IsNullOrEmpty(sUiLang)) {
				this->radioKor->Checked = true;
				CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("ko-KR");//Localization과 관련
				this->form2SendEvent("ko-KR");
			}
			else {
				if (sUiLang->Equals("en-US")) {
					this->radioEng->Checked = true;
					CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("en-US");//Localization과 관련
					this->form2SendEvent("en-US");
				}
				else {
					this->radioKor->Checked = true;
					CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("ko-KR");//Localization과 관련
					this->form2SendEvent("ko-KR");
				}
			}
		}else {
			this->radioKor->Checked = true;
			CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("ko-KR");//Localization과 관련
			this->form2SendEvent("ko-KR");
		}


		OnSaveDataChanged();
	}
};
}
