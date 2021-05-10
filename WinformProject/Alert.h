#pragma once
namespace WinformProject {
	using namespace System;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Messagebox Å¬·¡½º
	/// </summary>
	public ref class Alert {
	public:
		static DialogResult Error(String^ message) {
			return Alert::Error(message, "Error");
		}

		static DialogResult Error(String^ message, String^ title) {
			return System::Windows::Forms::MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		static DialogResult Warning(String^ message) {
			return Alert::Warning(message, "Warning");
		}

		static DialogResult Warning(String^ message, String^ title) {
			return System::Windows::Forms::MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		static DialogResult Help(String^ message) {
			return Alert::Help(message, "Help");
		}

		static DialogResult Help(String^ message, String^ title) {
			return System::Windows::Forms::MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		
		static DialogResult Info(String^ message) {
			return Alert::Help(message, "Information");
		}

		static DialogResult Info(String^ message, String^ title) {
			return System::Windows::Forms::MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}