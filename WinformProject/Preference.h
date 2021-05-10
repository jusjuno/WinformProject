#pragma once
namespace WinformProject {
	using namespace System;

	/// <summary>
	/// Summary for Preference
	/// Singleton
	/// </summary>
	public ref class Preference
	{
	private:
		Preference^ instance = nullptr;
	private:
		String^ a;
	private:
		Preference(void)
		{
		}
	public:
		Preference^ GetInstance() {
			if (this->instance == nullptr) {
				this->instance = gcnew Preference();
			}
			return this->instance;
		}
	};
}