#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "NeXTAHelper.h"
#include "TrafficModule.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Step9Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step9Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step9Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		NeXTAHelper^ m_nextaHelper;

		Boolean bStarting = false;
		int iIndex = 0;

		TrafficModule^ m_trafficModule;
		int localODindex = 0;


	public:
		Step9Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			this->m_trafficModule = gcnew TrafficModule(this->m_dataSet);
			this->m_nextaHelper = gcnew NeXTAHelper(this->m_dataSet);

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step9Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::ListBox^  lbLog;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker;
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
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lbLog = (gcnew System::Windows::Forms::ListBox());
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->btnStart->Location = System::Drawing::Point(238, 504);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(203, 45);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"START";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Step9Form::btnStart_Click);
			// 
			// lbLog
			// 
			this->lbLog->FormattingEnabled = true;
			this->lbLog->ItemHeight = 12;
			this->lbLog->Location = System::Drawing::Point(12, 16);
			this->lbLog->Name = L"lbLog";
			this->lbLog->Size = System::Drawing::Size(660, 484);
			this->lbLog->TabIndex = 1;
			// 
			// Step9Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->lbLog);
			this->Controls->Add(this->btnStart);
			this->Name = L"Step9Form";
			this->Text = L"Step9Form";
			this->Load += gcnew System::EventHandler(this, &Step9Form::Step9Form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
		return true;
	}
	private:
		delegate void AppendLogDelegate(String^ log);
	private:
		Process^ proc;
	private:




		void Run() {
			// 시작되면 버튼을 다시 누를수 없도록 시작버튼 비활성화
			btnStart->Enabled = false;
			btnStart->Text = "Running...";

			proc = gcnew Process();
			proc->StartInfo = gcnew ProcessStartInfo();
			proc->StartInfo->WorkingDirectory = "C:\\sample\\NEXTA";
			proc->StartInfo->FileName = "C:\\sample\\NEXTA\\DTALite_6.exe";
			//proc->StartInfo->Arguments = "command line arguments to your executable";

/*
			proc->StartInfo->UseShellExecute = false;
//			proc->StartInfo->RedirectStandardOutput = true;
//			proc->StartInfo->CreateNoWindow = true;
//			proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;
			proc->EnableRaisingEvents = true;
			proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);
			proc->Start();
//			backgroundWorker->RunWorkerAsync();
*/
			proc->StartInfo->UseShellExecute = false;

			/*
			//proc->StartInfo->RedirectStandardOutput = true;
			//proc->StartInfo->RedirectStandardError = true;
			//proc->StartInfo->CreateNoWindow = true;
			*/

			//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//윈도우 숨김

			proc->EnableRaisingEvents = true;
			proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);

			proc->Start();
//			bStarting = true;

			backgroundWorker->RunWorkerAsync();
			//backgroundWorker->


		}




		void AppendLog(String^ log) {
			lbLog->Items->Add(log);
			// focus last item
			lbLog->SelectedIndex = lbLog->Items->Count - 1;
		}
			//////////
			//수정중//
			/////////
		//bool CreateInputFiles() {
		bool CreateInputFiles(DataRow ^ OriginAndDestin) {
				AppendLog("Create input files.");
			String^ errMsg = "Can not create {0} file.";
			String^ okMsg = "Created {0} file.";

			String^ filename = "input_node.csv";
			if (!m_nextaHelper->WriteFileInputNode()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_link.csv";
			if (!m_nextaHelper->WriteFileInputLink()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_zone.csv";
			if (!m_nextaHelper->WriteFileInputZone()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_activity_location.csv";
			if (!m_nextaHelper->WriteFileInputActivityLocation()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));		
			
			filename = "input_node_control_type.csv";
			if (!m_nextaHelper->WriteAdvancedFileInputNodeControlType()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_link_type.csv";
			if (!m_nextaHelper->WriteAdvancedFileInputLinkType()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

//			filename = "input_demand_meta_data.csv";
			filename = "input_demand_file_list.csv";
			if (!m_nextaHelper->WriteFileInputDemandMetaData()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "scenario_work_zone.csv";
			if (!m_nextaHelper->WriteFileScenarioWorkZone()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));		
			
			filename = "input_scenario_setting.csv";
			if (!m_nextaHelper->WriteFileInputScenarioSettings()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));


			//==============================================================//
			// Start line for the new or modified input files for DTALite_64//
			//==============================================================//

			filename = "input_demand_type.csv";
			if (!m_nextaHelper->WriteFileInputDemandType()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));


			//////////
			//수정중//
			/////////
			filename = "input_demand.csv";
			if (!m_nextaHelper->WriteAdvancedFileInputDemand(OriginAndDestin)) {
					Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_pricing_type.csv";
			if (!m_nextaHelper->WriteAdvancedFileInputPricingType()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_VOT.csv";
			if (!m_nextaHelper->WriteFileInputVOT()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			//filename = "input_MOE_settings.csv";
			filename = "optional_MOE_settings.csv";
			if (!m_nextaHelper->WriteFileInputMOESettings()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "input_vehicle_type.csv";
			if (!m_nextaHelper->WriteFileInputVehicleType()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));

			filename = "scenario_incident.csv";
			if (!m_nextaHelper->WriteFileScenarioIncident()) {
				Alert::Error(String::Format(errMsg, filename));
				return false;
			}
			AppendLog(String::Format(okMsg, filename));


			//============================================================//
			// End line for the new or modified input files for DTALite_64// 
			//============================================================//

			return true;
		}

		System::Void backgroundWorkerDoWork(Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
			AppendLogDelegate^ appendLogDelegate = gcnew AppendLogDelegate(this, &Step9Form::AppendLog);

			array<Object^>^ args = gcnew array<Object^>(1);
			// output stream이 없을 때 까지 반복
			try
			{
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
			}
			catch (Exception^ err) 
			{
			}
		}
		System::Void backgroundWorkerRunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			if (e->Cancelled)    //Messages for the events
			{
				Alert::Error("Fail");
			}
			else
			{
				AppendLog("Read output_summary.csv");
				this->m_dataSet->IsRunTrafficSimulation = m_nextaHelper->ReadOutputSummaryFile();
				if (this->m_dataSet->IsRunTrafficSimulation) {
					this->m_dataSet->ResultData = gcnew ResultDataSet(this->m_dataSet->TotalTrafficScenarioCount);
					OnSaveDataChanged();
					AppendLog("Success");
				}
				else {
					AppendLog("Fail");
				}
			}
			if (proc != nullptr) {
				proc->Close();
			}

			// process 종료 후 성공 여부와 상관없이 시작버튼 활성화
			btnStart->Enabled = true;
			btnStart->Text = "START";
		}
	private: System::Void Step9Form_Load(System::Object^  sender, System::EventArgs^  e) {

		///////////////////////////////////
		// Traffic scenario 재구성
		///////////////////////////////////
		// Traffic scenario는 기본 값 즉 하나의 OD만을 고려함
		// OD zone이 하나 이상 될때는 Traffic Scenario 재구성 필요
		if (this->m_dataSet->ODZoneParamData->Rows->Count > 1) {
			bool result = this->m_trafficModule->GenerateScenarios();
		}


		///////////////////////////////////
		// input_demand.csv 파일 재구성
		///////////////////////////////////
		//String^ filename = "input_demand.csv";
		//String^ errMsg = "Can not create {0} file.";
		//String^ okMsg = "Created {0} file.";
		//DataRow^ OriginAndDestin = this->m_dataSet->ODZoneParamData->Rows[localODindex];
		//if (!m_nextaHelper->WriteAdvancedFileInputDemand(OriginAndDestin)) {
		//	Alert::Error(String::Format(errMsg, filename));
		//}
		//AppendLog(String::Format(okMsg, filename));

		DataRow^ OriginAndDestin = this->m_dataSet->ODZoneParamData->Rows[localODindex];
		CreateInputFiles(OriginAndDestin);
		//m_nextaHelper->WriteAdvancedFileInputDemand(OriginAndDestin);


		// set backgroundWorker work handler
		backgroundWorker->DoWork += gcnew DoWorkEventHandler(this, &Step9Form::backgroundWorkerDoWork);
		// set backgroundWorker work completed handler
		backgroundWorker->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &Step9Form::backgroundWorkerRunWorkerCompleted);
		m_nextaHelper = gcnew NeXTAHelper(m_dataSet);


	}

	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {


		//m_nextaHelper->ReadOutputSummaryFile();
//
//		lbLog->Items->Clear();
//		if (CreateInputFiles()) {
//				// run NeXTA after create input files.
//				Run();
//		}
//

//
		//////////
		//수정중//
		/////////
		DataRow^ OriginAndDestin;
		lbLog->Items->Clear();
		//for (int i=0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
		for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
			OriginAndDestin = this->m_dataSet->ODZoneParamData->Rows[i];
			if (CreateInputFiles(OriginAndDestin)) {
				// run NeXTA after create input files.
				//Run();



				BackgroundWorker^ backgroundWorker = gcnew BackgroundWorker();
				btnStart->Enabled = false;
				btnStart->Text = "Running...";

				proc = gcnew Process();
				proc->StartInfo = gcnew ProcessStartInfo();
				proc->StartInfo->WorkingDirectory = "C:\\sample\\NEXTA";
				proc->StartInfo->FileName = "C:\\sample\\NEXTA\\DTALite_6.exe";
				proc->StartInfo->UseShellExecute = false;
				proc->EnableRaisingEvents = true;
				proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);
				proc->Start();
//				bStarting = true;

			}
		}





		BackgroundWorker^ backgroundWorker = gcnew BackgroundWorker();
		Process^ proc = gcnew Process();
		proc->StartInfo = gcnew ProcessStartInfo();
		proc->StartInfo->WorkingDirectory = "C:\\sample\\NEXTA";
		proc->StartInfo->FileName = "C:\\sample\\NEXTA\\DTALite_6.exe";
		proc->StartInfo->UseShellExecute = false;
		proc->EnableRaisingEvents = true;
		proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);

//		proc->StartInfo->RedirectStandardOutput = true;
//		proc->StartInfo->CreateNoWindow = true;


		proc->Start();
		bStarting = true;

		backgroundWorker->RunWorkerAsync();


		/////////////////////////////////////////////
		// Do background work
		/////////////////////////////////////////////
/*
		AppendLogDelegate^ appendLogDelegate = gcnew AppendLogDelegate(this, &Step9Form::AppendLog);
		array<Object^>^ args = gcnew array<Object^>(1);
		// output stream이 없을 때 까지 반복
		try
		{
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
		}
		catch (Exception ^ err)
		{
		}
*/


		//OnSaveDataChanged();






	}



	private: System::Void procEndPrint(System::Object^ sender, System::EventArgs^ e) {

		/////////////////////////////////////////////
		// Read output_summary.csv
		/////////////////////////////////////////////
		//AppendLog("Read output_summary.csv");
		//this->m_dataSet->IsRunTrafficSimulation = m_nextaHelper->ReadOutputSummaryFile();
		m_nextaHelper->ReadOutputSummaryFile();
		//if (this->m_dataSet->IsRunTrafficSimulation) {
		//this->m_dataSet->ResultData = gcnew ResultDataSet(this->m_dataSet->TotalTrafficScenarioCount);
		//OnSaveDataChanged();
		//AppendLog("Success");
		//}


		///////////////////////////////////
		// input_demand.csv 파일 재구성
		///////////////////////////////////
		//String^ filename = "input_demand.csv";
		//String^ errMsg = "Can not create {0} file.";
		//String^ okMsg = "Created {0} file.";
		DataRow^ OriginAndDestin = this->m_dataSet->ODZoneParamData->Rows[localODindex];
		//if (!m_nextaHelper->WriteAdvancedFileInputDemand(OriginAndDestin)) {
		//	Alert::Error(String::Format(errMsg, filename));
		//}
		//AppendLog(String::Format(okMsg, filename));
		m_nextaHelper->WriteAdvancedFileInputDemand(OriginAndDestin);
		localODindex++;


		bStarting = false;

		BackgroundWorker^ backgroundWorker = gcnew BackgroundWorker();
		Process^ proc = gcnew Process();
		proc->StartInfo = gcnew ProcessStartInfo();
		proc->StartInfo->WorkingDirectory = "C:\\sample\\NEXTA";
		proc->StartInfo->FileName = "C:\\sample\\NEXTA\\DTALite_6.exe";
		proc->StartInfo->UseShellExecute = false;
		//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//윈도우 숨김

		proc->EnableRaisingEvents = true;
		proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);



		//Debug::WriteLine("=============================>End");
		//iIndex++;
		//Debug::WriteLine("=============================>iIndex:" + iIndex);
		while (localODindex < this->m_dataSet->ODZoneParamData->Rows->Count && !bStarting) {
			try
			{
/*
				BackgroundWorker^ backgroundWorker = gcnew BackgroundWorker();
				Process^ proc = gcnew Process();
				proc->StartInfo = gcnew ProcessStartInfo();
				proc->StartInfo->WorkingDirectory = "C:\\sample\\NEXTA";
				proc->StartInfo->FileName = "C:\\sample\\NEXTA\\DTALite_6.exe";
				proc->StartInfo->UseShellExecute = false;
				//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//윈도우 숨김

				proc->EnableRaisingEvents = true;
				proc->Exited += gcnew System::EventHandler(this, &Step9Form::procEndPrint);

*/



				proc->Start();
				bStarting = true;

				/////////////////////////////////////////////
				// Read output_summary.csv
				/////////////////////////////////////////////
				//this->m_dataSet->IsRunTrafficSimulation = m_nextaHelper->ReadOutputSummaryFile();
				//m_nextaHelper->ReadOutputSummaryFile();



			}
			catch (Exception ^ ex)
			{
				Debug::WriteLine("=============================>Exception:" + ex->Message);
				return;
			}
		}

		if (localODindex == this->m_dataSet->ODZoneParamData->Rows->Count) {
			proc->Close();
		}


	}















	};
}
