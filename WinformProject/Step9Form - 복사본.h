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
	/// Step9Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
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
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			this->m_trafficModule = gcnew TrafficModule(this->m_dataSet);
			this->m_nextaHelper = gcnew NeXTAHelper(this->m_dataSet);

		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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
			// ���۵Ǹ� ��ư�� �ٽ� ������ ������ ���۹�ư ��Ȱ��ȭ
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

			//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//������ ����

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
			//������//
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
			//������//
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
			// output stream�� ���� �� ���� �ݺ�
			try
			{
				while (!proc->StandardOutput->EndOfStream)
				{
					// ���� �α� ���
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

			// process ���� �� ���� ���ο� ������� ���۹�ư Ȱ��ȭ
			btnStart->Enabled = true;
			btnStart->Text = "START";
		}
	private: System::Void Step9Form_Load(System::Object^  sender, System::EventArgs^  e) {

		///////////////////////////////////
		// Traffic scenario �籸��
		///////////////////////////////////
		// Traffic scenario�� �⺻ �� �� �ϳ��� OD���� �����
		// OD zone�� �ϳ� �̻� �ɶ��� Traffic Scenario �籸�� �ʿ�
		if (this->m_dataSet->ODZoneParamData->Rows->Count > 1) {
			bool result = this->m_trafficModule->GenerateScenarios();
		}


		///////////////////////////////////
		// input_demand.csv ���� �籸��
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
		//������//
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
		// output stream�� ���� �� ���� �ݺ�
		try
		{
			while (!proc->StandardOutput->EndOfStream)
			{
				// ���� �α� ���
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
		// input_demand.csv ���� �籸��
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
		//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//������ ����

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
				//proc->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;//������ ����

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
