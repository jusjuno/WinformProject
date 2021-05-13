#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args)
{

	/*다국어 설정 확인 및 변경*/
	//Debug::WriteLine("=============================>CultureInfo.CurrentUICulture:" + CultureInfo::CurrentUICulture->Name);
	//CultureInfo::CurrentUICulture = CultureInfo::CreateSpecificCulture("en-US");//Localization과 관련
	//Debug::WriteLine("==========================================>CultureInfo.CurrentUICulture:" + CultureInfo::CurrentUICulture->Name);


	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	WinformProject::MainForm form;
	System::Windows::Forms::Application::Run(%form);
}