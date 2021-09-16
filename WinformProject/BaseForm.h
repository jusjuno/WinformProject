#pragma once

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// BaseForm�� ���� ����Դϴ�.
	/// �̺�Ʈ �� ���� �κ��� �����ϱ� ���� Step Form�� ��� Ŭ���� 
	/// </summary>
	public ref class BaseForm : public System::Windows::Forms::Form
	{
	public:
		BaseForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	public:
		// ������ �����Ͱ� ����Ǿ��� �� ȣ��
		event System::EventHandler^ SaveDataChanged;
		// ���� ���ɰ��� �ɼ� �������� �� ȣ��
		event System::EventHandler^ SeismicChanged;


	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~BaseForm()
		{
			if (components)
			{
				delete components;
			}
		}
		// ������Ʈ ������ �� ������ �����Ͱ� �߻����� ��� ȣ��
		void OnSaveDataChanged() {
			SaveDataChanged(this, EventArgs::Empty);
		}

		//void UpdateResultMenu() {
		//	SeismicChanged(this, EventArgs::Empty);
		//}

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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"BaseForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
