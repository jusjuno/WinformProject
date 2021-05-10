#pragma once
#include "NetworkComponent.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ChartParameterDialog�� ���� ����Դϴ�.
	/// Chart hotspot�� parameter dialog ���� Ŭ����
	/// </summary>
	public ref class ChartHotspotAttrDialog : public System::Windows::Forms::Form
	{
	private:
		ProjectDataSetBinder^				m_dataSet;
		NetworkComponent^					m_networkComponent;
	public:
		ChartHotspotAttrDialog(ProjectDataSetBinder^ dataSet)
		{
			this->m_dataSet = dataSet;
			InitializeComponent();

			m_networkComponent = gcnew NetworkComponent(dataSet);
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~ChartHotspotAttrDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Key;
	private: System::Windows::Forms::ColumnHeader^  Value;

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
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Key = (gcnew System::Windows::Forms::ColumnHeader());
			this->Value = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Key, this->Value });
			this->listView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView->GridLines = true;
			this->listView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView->HideSelection = false;
			this->listView->Location = System::Drawing::Point(0, 0);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(434, 311);
			this->listView->TabIndex = 0;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
			this->listView->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChartHotspotAttrDialog::listView_KeyPress);
			// 
			// Key
			// 
			this->Key->Text = L"Key";
			this->Key->Width = 224;
			// 
			// Value
			// 
			this->Value->Text = L"Value";
			this->Value->Width = 205;
			// 
			// ChartHotspotAttrDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 311);
			this->Controls->Add(this->listView);
			this->Name = L"ChartHotspotAttrDialog";
			this->Text = L"ChartHotspotAttrDialog";
			this->ResumeLayout(false);

		}
#pragma endregion
	public: 
		void Display(System::Object^  sender, ChartDirector::WinHotSpotEventArgs^ e) {
			// Add the name of the ChartViewer control that is being clicked
			array<String^>^ strArr = gcnew array<String^>(2);
			strArr[0] = "source";
			strArr[1] = ((ChartDirector::WinChartViewer^)sender)->Name;
			listView->Items->Add(gcnew ListViewItem(strArr));

			// List out the parameters of the hot spot
			// field0�� hotspot���� ����� �����͸� key=value;key=value ������ ����
			if (e->GetAttrValues()->ContainsKey("field0")) {
				String^ value = e->GetAttrValues()["field0"]->ToString();
				array<String^>^ attributes = value->Split(';');
				AttributeType type;
				for each (String^ attribute in attributes)
				{
					array<String^>^ attr = attribute->Split('=');
					if (attr->Length == 2) {
						AddList(attr[0], attr[1]);
						if (attr[0] == "TYPE") {
							Enum::TryParse(attr[1], type);
						}
					}
				}
				String^ filter = "";
				array<DataRow^>^ foundRows = nullptr;
				DataRow^ row = nullptr;
				// Ÿ�Ժ� �߰� parameter ����
				switch (type)
				{
				case AttributeType::Link:
					break;
				case AttributeType::Node:
					break;
				case AttributeType::Component:		
					// ��ǥ�� ������ ã��
					listView->Items->RemoveAt(2);
					foundRows = m_networkComponent->FindRows(NetworkComponent::COL_X, e->GetAttrValues()["x"], NetworkComponent::COL_Y, e->GetAttrValues()["value"]);
					if (foundRows->Length > 0) {
						row = foundRows[0];
						for (int i = 0; i < m_networkComponent->GetColumnCount(); i++)
						{
							AddList(m_networkComponent->GetColumnName(i), row[i]);
						}
					}
					break;
				default:
					break;
				}
			}

			// Display the form
			ShowDialog();
		}
		void AddList(String^ key, Object^ value) {
			array<String^>^ row = gcnew array<String^>(2);
			row[0] = key; // key
			row[1] = String::Format("{0}", value); // value
			listView->Items->Add(gcnew ListViewItem(row));
		}
	private: System::Void listView_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (char)Keys::Escape) {
			this->Close();
		}
	}
};
}
