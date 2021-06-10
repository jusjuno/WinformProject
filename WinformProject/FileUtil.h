#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

/// <summary>
/// File util class
/// </summary>
ref class FileUtil
{
public:
	// write text to file
	bool WriteText(String^ filePath, String^ contents) {
		bool result = false;
		StreamWriter^ sw = nullptr;
		try {
			sw = gcnew StreamWriter(filePath);
			sw->WriteLine(contents);
			result = true;
		}
		catch (Exception^ e) {

		}
		finally	{
			if (sw != nullptr) {
				sw->Close();
			}
		}

		return result;
	};

	// read file
	String^ Read(String^ filePath) {
		StreamReader^ sr = nullptr;
		String^ result = "";
		try {
			sr = gcnew StreamReader(filePath, System::Text::Encoding::GetEncoding("euc-kr"));

			while (!sr->EndOfStream) {
				result += sr->ReadLine() + Environment::NewLine;
			}
		}
		catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", filePath);
			}
			else {
				Console::WriteLine("problem reading file '{0}'", filePath);
			}
		}
		finally{
			if (sr != nullptr) {
				sr->Close();
			}
		}
		return result;
	};
};