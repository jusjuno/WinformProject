#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "ChartHotspotAttrDialog.h"
#include "NetworkComponent.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step0Form�� ���� ����Դϴ�.
	/// </summary>
	public ref class Step0Form : public System::Windows::Forms::Form, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		Shape^						m_shape;
		String^ m_htmlPath;
		NetworkComponent^			m_networkComponent;


	public:
		Step0Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			m_shape = dataSet->ShapeData;
			m_networkComponent = gcnew NetworkComponent(this->m_dataSet);
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Step0Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	protected:

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
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->SuspendLayout();
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(0, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(1084, 761);
			this->webBrowser1->TabIndex = 0;
			// 
			// Step0Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->webBrowser1);
			this->Name = L"Step0Form";
			this->Text = L"Step0Form";
			this->Load += gcnew System::EventHandler(this, &Step0Form::Step0Form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
		return true;
	}
	private: System::Void Step0Form_Load(System::Object^  sender, System::EventArgs^  e) {
		// WebBrowser ��Ʈ�ѿ� "kakaoMap.html" �� ǥ���Ѵ�. 
		this->webBrowser1->AllowWebBrowserDrop = false;
		this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser1->WebBrowserShortcutsEnabled = false;
		this->webBrowser1->ObjectForScripting = this;

		Version^ ver = this->webBrowser1->Version;
		String^ name = this->webBrowser1->ProductName;
		String^ str = this->webBrowser1->ProductVersion;
		String^ html = "kakaoMap.html";
		m_htmlPath = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), html);
		DrawMap();
	}
	private: System::Void DrawMap() {
		this->webBrowser1->Navigate(m_htmlPath + String::Format("?centerLat={0}&centerLng={1}", m_shape->m_geoCenterPoint.y, m_shape->m_geoCenterPoint.x));
	}
	public: System::Void DrawLinks() {
		Debug::WriteLine("Draw Links");
		array<Object^>^ args = gcnew array<Object^>(1);
		// ���������� ������ŭ ���鼭 �׸���.
		for (int i = 0; i < m_shape->m_nRecords; ++i)
		{
			int numPoints = m_shape->m_pSHPPolyObjects[i].nNumPoints;
			args = gcnew array<Object^>(1);
			String^ jsonStr = "";
			array<double>^ lats = gcnew array<double>(numPoints);
			array<double>^ lngs = gcnew array<double>(numPoints);
			for (int j = 0; j < numPoints; ++j)
			{
				double lat = m_shape->m_pSHPPolyObjects[i].arrPoints[j].y;
				double lng = m_shape->m_pSHPPolyObjects[i].arrPoints[j].x;
				jsonStr += ("{" + String::Format("\"lat\":{0},\"lng\":{1}", lat, lng) + "}");
				if (j + 1 < numPoints) {
					jsonStr += ",";
				}
				//Debug::WriteLine(String::Format("Draw line lat={0}, lng={1}", lat, lng));
			}

			// javascript�� �ĸ����͸� �ѱ�� ���� json string ���·� ����
			args[0] = "[" + jsonStr + "]";
			Debug::WriteLine(args[0]);
			// draw link
			this->webBrowser1->Document->InvokeScript("drawPolyLine", args);
		}

		// move center geopoint
		//args = gcnew array<Object^>(2);
		//args[0] = m_shape->m_geoCenterPoint.y;
		//args[1] = m_shape->m_geoCenterPoint.x;
		//Debug::WriteLine(String::Format("Move to lat={0}, lng={1}", args[0], args[1]));
		//this->webBrowser1->Document->InvokeScript("moveTo", args);
	}
	public: System::Void DrawComponents()
	{
		Debug::WriteLine("Draw Components");
		array<ComponentClassInfo>^ components = m_networkComponent->GetNetworkComponentChartData();
		array<Object^>^ args = gcnew array<Object^>(1);
		// ������Ʈ Ŭ���� ����ŭ �׸��� 
		for (int i = 0; i < components->Length; ++i)
		{
			ComponentClassInfo^ component = components[i];
			args = gcnew array<Object^>(3);
			// ������Ʈ �̸� 
			args[0] = component->name2;

			String^ jsonStr = "";
			int componentsCount = component->dataX->Length;
			array<double>^ lats = gcnew array<double>(componentsCount);
			array<double>^ lngs = gcnew array<double>(componentsCount);

			for (int j = 0; j < componentsCount; j++)
			{
				double lat = component->dataY[j];
				double lng = component->dataX[j];
				jsonStr += ("{" + String::Format("\"lat\":{0},\"lng\":{1},\"attributes\":[", lat, lng));
				ShapeChartAttribute^ attribute = component->attributes[j];
				bool isFirst = true;
				// ���۳�Ʈ �� �Ӽ� ����� 
				for each (KeyValuePair<String^, Object^>^ item in attribute->Attributes)
				{
					if (isFirst) {
						isFirst = false;
					}
					else {
						jsonStr += ",";
					}
					jsonStr += "{" + String::Format("\"label\":\"{0}\",\"value\":\"{1}\"", item->Key, attribute->Attributes[item->Key]) + "}";
				}
				jsonStr += ",{" + String::Format("\"label\":\"{0}\",\"value\":\"{1}\"", "����", lat) + "}";
				jsonStr += ",{" + String::Format("\"label\":\"{0}\",\"value\":\"{1}\"", "�浵", lng) + "}";
				jsonStr += "]}";

				if (j + 1 < componentsCount) {
					jsonStr += ",";
				}
			}
			// javascript�� �ĸ����͸� �ѱ�� ���� json string ���·� ����
			args[1] = "[" + jsonStr + "]";
			// marker image
			args[2] = "";
			Debug::WriteLine(args[0]);
			Debug::WriteLine(args[1]);
			Debug::WriteLine(args[2]);
			// draw marker(components)
			this->webBrowser1->Document->InvokeScript("drawComponents", args);
		}
	}
	public: System::Void DrawNodes() {
		Debug::WriteLine("Draw Nodes");
		array<Object^>^ args = gcnew array<Object^>(1);
		bool isFirst = true;
		String^ jsonStr = "";
		for each (KeyValuePair<String^, ShapeNode^>^ item in m_shape->m_SHPNodes)
		{
			ShapeNode^ node = m_shape->m_SHPNodes[item->Key];
			if (isFirst) {
				isFirst = false;
			}
			else {
				jsonStr += ",";
			}
			jsonStr += "{" + String::Format("\"name\":\"{0}\",\"lat\":{1},\"lng\":{2}", node->ID, node->Location.y, node->Location.x) + "}";
		}
		// javascript�� �ĸ����͸� �ѱ�� ���� json string ���·� ����
		args[0] = "[" + jsonStr + "]";
		Debug::WriteLine(args[0]);
		// draw marker(nodes)
		this->webBrowser1->Document->InvokeScript("drawNodes", args);
	}
	};
}
