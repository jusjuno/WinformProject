#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args)
{

	/*�ٱ��� ���� Ȯ�� �� ����*/
	//Debug::WriteLine("=============================>CultureInfo.CurrentUICulture:" + CultureInfo::CurrentUICulture->Name);
	//CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("en-US");//Localization�� ����
	//Debug::WriteLine("==========================================>CultureInfo.CurrentUICulture:" + CultureInfo::CurrentUICulture->Name);


	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	WinformProject::MainForm form;
	System::Windows::Forms::Application::Run(%form);
}