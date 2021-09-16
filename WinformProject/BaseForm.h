#pragma once

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// BaseForm에 대한 요약입니다.
	/// 이벤트 등 공통 부분을 적용하기 위한 Step Form의 상속 클래스 
	/// </summary>
	public ref class BaseForm : public System::Windows::Forms::Form
	{
	public:
		BaseForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	public:
		// 저장할 데이터가 변경되었을 때 호출
		event System::EventHandler^ SaveDataChanged;
		// 내진 성능관리 옵션 선택했을 때 호출
		event System::EventHandler^ SeismicChanged;


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~BaseForm()
		{
			if (components)
			{
				delete components;
			}
		}
		// 프로젝트 데이터 중 저장할 데이터가 발생했을 경우 호출
		void OnSaveDataChanged() {
			SaveDataChanged(this, EventArgs::Empty);
		}

		//void UpdateResultMenu() {
		//	SeismicChanged(this, EventArgs::Empty);
		//}

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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"BaseForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
