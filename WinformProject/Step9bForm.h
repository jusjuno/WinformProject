#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "UNISTHelper.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step9bForm에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	
	//public ref class Step9bForm : public System::Windows::Forms::Form, IFormValidator
	public ref class Step9bForm : public WinformProject::BaseForm, IFormValidator/// 
	{
	private:
		ProjectDataSetBinder^ m_dataSet;
		UNISTHelper^ m_UNISTHelper;


		delegate void AppendLogDelegate(String^ log);
		AppendLogDelegate^ appendLogDelegate = nullptr;


	public:
	
		Step9bForm(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();

			this->m_dataSet = dataSet;
			this->m_UNISTHelper = gcnew UNISTHelper(this->m_dataSet);

			appendLogDelegate = gcnew AppendLogDelegate(this, &Step9bForm::AppendLog);
		}
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step9bForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbLog;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker;

	protected:

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
			this->lbLog = (gcnew System::Windows::Forms::ListBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// lbLog
			// 
			this->lbLog->FormattingEnabled = true;
			this->lbLog->ItemHeight = 15;
			this->lbLog->Location = System::Drawing::Point(14, 48);
			this->lbLog->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->lbLog->Name = L"lbLog";
			this->lbLog->Size = System::Drawing::Size(754, 604);
			this->lbLog->TabIndex = 2;
			// 
			// btnStart
			// 
			this->btnStart->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->btnStart->Location = System::Drawing::Point(275, 660);
			this->btnStart->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(232, 56);
			this->btnStart->TabIndex = 3;
			this->btnStart->Text = L"START";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Step9bForm::btnStart_Click);

			// 
			// Step9bForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 720);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->lbLog);
			this->Name = L"Step9bForm";
			this->Text = L"Step9bForm";
			this->Load += gcnew System::EventHandler(this, &Step9bForm::Step9bForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion



		public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
			return true;
		}

		private:
			Process^ proc;

		private:

			void AppendLog(String^ log) {
				lbLog->Items->Add(log);
				// focus last item
				lbLog->SelectedIndex = lbLog->Items->Count - 1;
			}

			bool CreateInputFiles(String^ seismicSourceName, String^ recurrencePeriod, int ODindex) {
				Debug::WriteLine("=============================>CreateInputFiles");

				String^ errMsg = "Can not create {0} file.";
				String^ okMsg = "Created {0} file.";
				
				//1. input_Bridge_fragility_curve.csv
				String^ filename = "input_Bridge_fragility_curve.csv";				
				if (!m_UNISTHelper->WriteBridgeFragilityCurve(filename)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				
				//2. input_Location_br.csv
				filename = "input_Location_br.csv";
				if (!m_UNISTHelper->WriteLocationBr(filename)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				//3. input_Location_eq.csv
				filename = "input_Location_eq.csv";
				if (!m_UNISTHelper->WriteLocationEq(filename, seismicSourceName)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				//4. input_M_eq.csv
				filename = "input_M_eq.csv";
				if (!m_UNISTHelper->WriteMEq(filename, seismicSourceName, recurrencePeriod)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				//5. input_Maxday.csv
				filename = "input_Maxday.csv";
				if (!m_UNISTHelper->WriteMaxday(filename)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				//6. input_No_samples.csv
				filename = "input_No_samples.csv";
				if (!m_UNISTHelper->WriteNoSamples(filename)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));

				//7. input_Restoration_days.csv
				filename = "input_Restoration_days.csv";
				if (!m_UNISTHelper->WriteRestorationDays(filename)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));
				
				//8. input_OD.csv
				filename = "input_OD.csv";
				if (!m_UNISTHelper->WriteOD(filename, ODindex)) {
					Alert::Error(String::Format(errMsg, filename));
					return false;
				}
				AppendLogDele(String::Format(okMsg, filename));


				return true;
			}

			System::Void backgroundWorkerDoWork(Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
				array<Object^>^ args = gcnew array<Object^>(1);

				Debug::WriteLine("=============================>Start backgroundWorkerDoWork");

				/*
				try
				{
					CreateInputFiles();


					proc = gcnew Process();
					proc->StartInfo = gcnew ProcessStartInfo();
					proc->StartInfo->WorkingDirectory = "C:\\sample\\UNIST";
					proc->StartInfo->FileName = "C:\\sample\\UNIST\\Resilience_estimation_main.exe";

					proc->StartInfo->CreateNoWindow = true;
					proc->StartInfo->UseShellExecute = false;
					proc->StartInfo->RedirectStandardOutput = true;


					proc->Start();


					this->m_dataSet->TrafficScenarios;


					while (!proc->StandardOutput->EndOfStream)
					{
						// 실행 로그 출력
						String^ log = proc->StandardOutput->ReadLine() + Environment::NewLine;
						if (lbLog->InvokeRequired) {
							args[0] = log;
							lbLog->Invoke(appendLogDelegate, args);
						}
						else {
							AppendLog(log);
						}
					}

					Debug::WriteLine("=============================>before WaitForExit");
					proc->WaitForExit();
					Debug::WriteLine("=============================>after WaitForExit");


					//Read output_Resilience_curve.xlsx

					String^ scenarioKey = "1111";
					String^ filename = "output_Resilience_curve.csv";
					DataTable^ dtOutputFile = m_UNISTHelper->ReadOutputFile(filename, scenarioKey);



				
				}
				*/

				
				try
				{

					for each (TrafficScenario^ trafficScenario in this->m_dataSet->TrafficScenarios){
					
						String^ seismicSourceName = trafficScenario->SourceName;
						String^ recurrencePeriod = trafficScenario->RecurrencePeriodName;
						int OD = trafficScenario->ODIndex;

						CreateInputFiles(seismicSourceName, recurrencePeriod, OD);

						proc = gcnew Process();
						proc->StartInfo = gcnew ProcessStartInfo();
						proc->StartInfo->WorkingDirectory = "C:\\sample\\UNIST";
						proc->StartInfo->FileName = "C:\\sample\\UNIST\\Resilience_estimation_main.exe";

						proc->StartInfo->CreateNoWindow = true;
						proc->StartInfo->UseShellExecute = false;
						proc->StartInfo->RedirectStandardOutput = true;


						proc->Start();

						while (!proc->StandardOutput->EndOfStream)
						{
							// 실행 로그 출력
							String^ log = proc->StandardOutput->ReadLine() + Environment::NewLine;
							if (lbLog->InvokeRequired) {
								args[0] = log;
								lbLog->Invoke(appendLogDelegate, args);
							}
							else {
								AppendLog(log);
							}
						}

						Debug::WriteLine("=============================>before WaitForExit");
						proc->WaitForExit();
						Debug::WriteLine("=============================>after WaitForExit");


						//Read output_Resilience_curve.xlsx

						String^ scenarioKey = trafficScenario->TrafficScenarioKey;
						String^ filename = "output_Resilience_curve.csv";
						DataTable^ dtOutputFile = m_UNISTHelper->ReadOutputFile(filename, scenarioKey);
					}

				}
				



				catch (Exception^ err)
				{
				}
			}

			System::Void backgroundWorkerRunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {

				Debug::WriteLine("=============================>backgroundWorkerRunWorkerCompleted");

				if (e->Cancelled)    //Messages for the events
				{
					Alert::Error("Fail");
				}
				else
				{
					this->m_dataSet->IsRunTrafficSimulation = true;

					OnSaveDataChanged();
					AppendLog("Success");


					this->m_dataSet->RunExeName = "UNIST";

				}
				if (proc != nullptr) {
					proc->Close();
				}

				// process 종료 후 성공 여부와 상관없이 시작버튼 활성화
				btnStart->Enabled = true;
				btnStart->Text = "START";

			}

			System::Void Step9bForm_Load(System::Object^ sender, System::EventArgs^ e) {


				Debug::WriteLine("=============================>backgroundWorkerRunWorkerCompleted");


				// set backgroundWorker work handler
				backgroundWorker->DoWork += gcnew DoWorkEventHandler(this, &Step9bForm::backgroundWorkerDoWork);
				// set backgroundWorker work completed handler
				backgroundWorker->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &Step9bForm::backgroundWorkerRunWorkerCompleted);



				//m_UNISTHelper = gcnew UNISTHelper(m_dataSet);
				

			}

			System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {


				//시작되면 버튼을 다시 누를수 없도록 시작버튼 비활성화
				btnStart->Enabled = false;
				btnStart->Text = "Running...";

				backgroundWorker->RunWorkerAsync();


			}

			System::Void AppendLogDele(String^ log) {
				if (lbLog->InvokeRequired) {
					lbLog->Invoke(appendLogDelegate, log);
				}
				else {
					AppendLog(log);
				}

			}




	};
}
