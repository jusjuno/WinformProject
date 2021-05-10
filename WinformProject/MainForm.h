#pragma once
#include "Alert.h"
#include "CommConst.h"
#include "FileDlgUtil.h"
#include "ProjectDataSet.h"
#include "NewProjectForm.h"
#include "NeXTAHelper.h"

#include "Step0Form.h"
#include "Step1Form.h"
#include "Step2Form.h"
#include "Step3Form.h"
#include "Step4Form.h"
#include "Step5Form.h"
#include "Step6Form.h"
#include "Step7Form.h"
#include "Step8Form.h"
#include "Step9Form.h"

/////////////////////////////
#include "NeXTAInput.h"
/////////////////////////////

#include "Step10Form.h"
#include "Step10bForm.h"
#include "Step11Form.h"
#include "Step12Form.h"
#include "Step13Form.h"

namespace WinformProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::IO;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		literal String^				TITLE = "노후 도로시설 내진성능관리 의사결정시스템";
		static bool					IsModified; // save data modify status

		ProjectDataSetBinder^		m_projectDataSetBinder; // save project data

		/*
		 * all of form
		 */
		NewProjectForm^				m_newProjectForm;
		Step0Form^					m_step0Form;
		Step1Form^					m_step1Form;
		Step2Form^					m_step2Form;
		Step3Form^					m_step3Form;
		Step4Form^					m_step4Form;
		Step5Form^					m_step5Form;
		Step6Form^					m_step6Form;
		Step7Form^					m_step7Form;
		Step8Form^					m_step8Form;
		Step9Form^					m_step9Form;
		/////////////////////////////////////////////////
		NeXTAInput^					m_neXTAInput;
		/////////////////////////////////////////////////
		Step10Form^					m_step10Form;
		Step10bForm^				m_step10bForm;
		Step11Form^					m_step11Form;
		Step12Form^					m_step12Form;
		Step13Form^					m_step13Form;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  FileMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FileNewMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FileOpenMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FileSaveMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FilePreferencesMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FileExitMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ProjectMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep1MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep2MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep3MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep4MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep5MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep6MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep7MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProjectStep8MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ResultStep10MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ResultStep12MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ResultStep10bMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ResultStep11MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  NeXTAMenuItem;
///////////////////////////////////////////////////////////////////////////////
	private: System::Windows::Forms::ToolStripMenuItem^ NeXTAInputMenuItem;
///////////////////////////////////////////////////////////////////////////////
	private: System::Windows::Forms::ToolStripMenuItem^ NeXTARunMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ProjectStep0MenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ decisionToolStripMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  ResultMenuItem;

	protected:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->FileMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileNewMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileOpenMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileSaveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FilePreferencesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileExitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep0MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep1MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep2MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep3MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep4MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep5MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep6MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep7MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProjectStep8MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NeXTAMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NeXTAInputMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NeXTARunMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResultMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResultStep10MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResultStep10bMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResultStep11MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResultStep12MenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decisionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->FileMenuItem, this->ProjectMenuItem,
					this->NeXTAMenuItem, this->ResultMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(873, 33);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip";
			// 
			// FileMenuItem
			// 
			this->FileMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->FileNewMenuItem,
					this->FileOpenMenuItem, this->FileSaveMenuItem, this->FilePreferencesMenuItem, this->FileExitMenuItem
			});
			this->FileMenuItem->Name = L"FileMenuItem";
			this->FileMenuItem->Size = System::Drawing::Size(55, 29);
			this->FileMenuItem->Text = L"File";
			// 
			// FileNewMenuItem
			// 
			this->FileNewMenuItem->Name = L"FileNewMenuItem";
			this->FileNewMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->FileNewMenuItem->Size = System::Drawing::Size(270, 34);
			this->FileNewMenuItem->Text = L"New";
			this->FileNewMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FileNewMenuItem_Click);
			// 
			// FileOpenMenuItem
			// 
			this->FileOpenMenuItem->Name = L"FileOpenMenuItem";
			this->FileOpenMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->FileOpenMenuItem->Size = System::Drawing::Size(270, 34);
			this->FileOpenMenuItem->Text = L"Open";
			this->FileOpenMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FileOpenMenuItem_Click);
			// 
			// FileSaveMenuItem
			// 
			this->FileSaveMenuItem->Name = L"FileSaveMenuItem";
			this->FileSaveMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->FileSaveMenuItem->Size = System::Drawing::Size(270, 34);
			this->FileSaveMenuItem->Text = L"Save";
			this->FileSaveMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FileSaveMenuItem_Click);
			// 
			// FilePreferencesMenuItem
			// 
			this->FilePreferencesMenuItem->Enabled = false;
			this->FilePreferencesMenuItem->Name = L"FilePreferencesMenuItem";
			this->FilePreferencesMenuItem->Size = System::Drawing::Size(270, 34);
			this->FilePreferencesMenuItem->Text = L"Preferences";
			this->FilePreferencesMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FilePreferencesMenuItem_Click);
			// 
			// FileExitMenuItem
			// 
			this->FileExitMenuItem->Name = L"FileExitMenuItem";
			this->FileExitMenuItem->Size = System::Drawing::Size(270, 34);
			this->FileExitMenuItem->Text = L"Exit";
			this->FileExitMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FileExitMenuItem_Click);
			// 
			// ProjectMenuItem
			// 
			this->ProjectMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->ProjectStep0MenuItem,
					this->ProjectStep1MenuItem, this->ProjectStep2MenuItem, this->ProjectStep3MenuItem, this->ProjectStep4MenuItem, this->ProjectStep5MenuItem,
					this->ProjectStep6MenuItem, this->ProjectStep7MenuItem, this->ProjectStep8MenuItem
			});
			this->ProjectMenuItem->Enabled = false;
			this->ProjectMenuItem->Name = L"ProjectMenuItem";
			this->ProjectMenuItem->Size = System::Drawing::Size(84, 29);
			this->ProjectMenuItem->Text = L"Project";
			// 
			// ProjectStep0MenuItem
			// 
			this->ProjectStep0MenuItem->Name = L"ProjectStep0MenuItem";
			this->ProjectStep0MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep0MenuItem->Text = L"Map";
			this->ProjectStep0MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep0MenuItem_Click);
			// 
			// ProjectStep1MenuItem
			// 
			this->ProjectStep1MenuItem->Name = L"ProjectStep1MenuItem";
			this->ProjectStep1MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep1MenuItem->Text = L"Definition of Road Network";
			this->ProjectStep1MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep1MenuItem_Click);
			// 
			// ProjectStep2MenuItem
			// 
			this->ProjectStep2MenuItem->Name = L"ProjectStep2MenuItem";
			this->ProjectStep2MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep2MenuItem->Text = L"Definition network component classes";
			this->ProjectStep2MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep2MenuItem_Click);
			// 
			// ProjectStep3MenuItem
			// 
			this->ProjectStep3MenuItem->Name = L"ProjectStep3MenuItem";
			this->ProjectStep3MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep3MenuItem->Text = L"Definition of network component properties";
			this->ProjectStep3MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep3MenuItem_Click);
			// 
			// ProjectStep4MenuItem
			// 
			this->ProjectStep4MenuItem->Name = L"ProjectStep4MenuItem";
			this->ProjectStep4MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep4MenuItem->Text = L"Seismic fragility of network components";
			this->ProjectStep4MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep4MenuItem_Click);
			// 
			// ProjectStep5MenuItem
			// 
			this->ProjectStep5MenuItem->Name = L"ProjectStep5MenuItem";
			this->ProjectStep5MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep5MenuItem->Text = L"Seismic hazard";
			this->ProjectStep5MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep5MenuItem_Click);
			// 
			// ProjectStep6MenuItem
			// 
			this->ProjectStep6MenuItem->Name = L"ProjectStep6MenuItem";
			this->ProjectStep6MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep6MenuItem->Text = L"Couple hazard to fragility";
			this->ProjectStep6MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep6MenuItem_Click);
			// 
			// ProjectStep7MenuItem
			// 
			this->ProjectStep7MenuItem->Name = L"ProjectStep7MenuItem";
			this->ProjectStep7MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep7MenuItem->Text = L"Traffic carrying capacity - Repair cost ratio";
			this->ProjectStep7MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep7MenuItem_Click);
			// 
			// ProjectStep8MenuItem
			// 
			this->ProjectStep8MenuItem->Name = L"ProjectStep8MenuItem";
			this->ProjectStep8MenuItem->Size = System::Drawing::Size(475, 34);
			this->ProjectStep8MenuItem->Text = L"Traffic scenarios";
			this->ProjectStep8MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ProjectStep8MenuItem_Click);
			// 
			// NeXTAMenuItem
			// 
			this->NeXTAMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->NeXTAInputMenuItem,
					this->NeXTARunMenuItem
			});
			this->NeXTAMenuItem->Name = L"NeXTAMenuItem";
			this->NeXTAMenuItem->Size = System::Drawing::Size(85, 29);
			this->NeXTAMenuItem->Text = L"NeXTA";
			// 
			// NeXTAInputMenuItem
			// 
			this->NeXTAInputMenuItem->Name = L"NeXTAInputMenuItem";
			this->NeXTAInputMenuItem->Size = System::Drawing::Size(156, 34);
			this->NeXTAInputMenuItem->Text = L"Input";
			this->NeXTAInputMenuItem->Click += gcnew System::EventHandler(this, &MainForm::NeXTAInputMenuItem_Click);
			// 
			// NeXTARunMenuItem
			// 
			this->NeXTARunMenuItem->Name = L"NeXTARunMenuItem";
			this->NeXTARunMenuItem->Size = System::Drawing::Size(156, 34);
			this->NeXTARunMenuItem->Text = L"Run";
			this->NeXTARunMenuItem->Click += gcnew System::EventHandler(this, &MainForm::NeXTARunMenuItem_Click);
			// 
			// ResultMenuItem
			// 
			this->ResultMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->ResultStep10MenuItem,
					this->ResultStep10bMenuItem, this->ResultStep11MenuItem, this->ResultStep12MenuItem, this->decisionToolStripMenuItem
			});
			this->ResultMenuItem->Name = L"ResultMenuItem";
			this->ResultMenuItem->Size = System::Drawing::Size(77, 29);
			this->ResultMenuItem->Text = L"Result";
			// 
			// ResultStep10MenuItem
			// 
			this->ResultStep10MenuItem->Name = L"ResultStep10MenuItem";
			this->ResultStep10MenuItem->Size = System::Drawing::Size(294, 34);
			this->ResultStep10MenuItem->Text = L"Qualitative Indicators1";
			this->ResultStep10MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ResultStep10MenuItem_Click);
			// 
			// ResultStep10bMenuItem
			// 
			this->ResultStep10bMenuItem->Name = L"ResultStep10bMenuItem";
			this->ResultStep10bMenuItem->Size = System::Drawing::Size(294, 34);
			this->ResultStep10bMenuItem->Text = L"Qualitative Indicators2";
			this->ResultStep10bMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ResultStep10bMenuItem_Click);
			// 
			// ResultStep11MenuItem
			// 
			this->ResultStep11MenuItem->Name = L"ResultStep11MenuItem";
			this->ResultStep11MenuItem->Size = System::Drawing::Size(294, 34);
			this->ResultStep11MenuItem->Text = L"Qualitative Indicators3";
			this->ResultStep11MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ResultStep11MenuItem_Click);
			// 
			// ResultStep12MenuItem
			// 
			this->ResultStep12MenuItem->Name = L"ResultStep12MenuItem";
			this->ResultStep12MenuItem->Size = System::Drawing::Size(294, 34);
			this->ResultStep12MenuItem->Text = L"Decision BackData";
			this->ResultStep12MenuItem->Click += gcnew System::EventHandler(this, &MainForm::ResultStep12MenuItem_Click);
			// 
			// decisionToolStripMenuItem
			// 
			this->decisionToolStripMenuItem->Name = L"decisionToolStripMenuItem";
			this->decisionToolStripMenuItem->Size = System::Drawing::Size(294, 34);
			this->decisionToolStripMenuItem->Text = L"Decision";
			this->decisionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::decisionToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(873, 462);
			this->Controls->Add(this->menuStrip);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"노후 도로시설 내진성능관리 의사결정시스템";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		// Get the flag that is created a project
		bool IsCreatedProject(void) {
			return (m_projectDataSetBinder != nullptr) ? true : false;
		}
		// Get the flag that is created instance a step form
		bool IsCreatedFormInstance(System::Windows::Forms::Form^ form) {
			if (form == nullptr || form->IsDisposed) {
				return false;
			}
			else {
				// if there is a instance, the form is activity and bring to front
				this->ActiveControl = form;
				form->BringToFront();
				return true;
			}
		}
		// It occur, when save data has been changed.
		System::Void OnSaveDataChanged(System::Object^  sender, System::EventArgs^  e) {
			IsModified = true;
			UpdateForm();
		}
		// update main form
		//   - data modified status(save mode)
		//   - menu enable/disable
		System::Void UpdateForm() {
			String^ title;
			String^ modifiedMarker;
			// If the project is exist, project name and modified marker is shown.
			if (IsCreatedProject()) {
				if (IsModified) {
					// It is able to save.
					modifiedMarker = CommConst::MODIFY_MARKER;
				}
				else {
					modifiedMarker = "";
				}
 				title = String::Format("{0} - {1} {2}", TITLE, m_projectDataSetBinder->ProjectName, modifiedMarker);
			}
			else {
				title = TITLE;
			}
			UpdateMainMenu();
			// set main form title
			this->Text = title;
		}
		// Set enable/disable main menu
		void UpdateMainMenu() {
			if (IsCreatedProject()) {
				ProjectMenuItem->Enabled = true;
				if (IsModified) {
					FileSaveMenuItem->Enabled = true;
				}
				else {
					FileSaveMenuItem->Enabled = false;
				}

				if (this->m_projectDataSetBinder->IsGeneratedTrafficScenarios) {
					NeXTAMenuItem->Enabled = true;
				}
				if (this->m_projectDataSetBinder->IsRunTrafficSimulation) {
					ResultMenuItem->Enabled = true;
				}
			}
			else {
				// If there is not project, all of menu group is disable
				ProjectMenuItem->Enabled = false;
				NeXTAMenuItem->Enabled = false;
				ResultMenuItem->Enabled = false;
			}
		}
		// save file
		bool SaveFile(String^ filename) {
			FileStream^ fs = nullptr;
			BinaryFormatter^ bf = nullptr;
			try
			{
				this->m_projectDataSetBinder->SaveFilename = filename;
				fs = gcnew FileStream(filename, FileMode::Create);
				bf = gcnew BinaryFormatter();
				bf->Serialize(fs, this->m_projectDataSetBinder->DataSet);
				return true;
			}
			catch (Exception^ ex)
			{
				this->m_projectDataSetBinder->SaveFilename = "";
				Alert::Error("Can not save file.");
				return false;
			}
			finally{
				if (fs != nullptr) {
					fs->Close();
				}
			}
		}
		// read file1
		bool ReadFile(String^ filename) {
			FileStream^ fs = nullptr;
			BinaryFormatter^ bf = nullptr;
			try
			{
				fs = gcnew FileStream(filename, FileMode::Open, FileAccess::Read);
				bf = gcnew BinaryFormatter();
				ProjectDataSet^ ds = (ProjectDataSet^)bf->Deserialize(fs);
				// Set Project dataset from file 
				this->m_projectDataSetBinder = gcnew ProjectDataSetBinder(ds);
				return true;
			}
			catch (Exception^ ex)
			{
				Alert::Error("Can not read file.");
				return false;
			}
			finally{
				if (fs != nullptr) {
					fs->Close();
				}
			}
		}
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// when program start, 
		IsModified = false;
		UpdateForm();
	}
	private:
		/******************************************************
		* Menu strip
		*******************************************************/
		/////////////////////////////////////////////////////////
		// File
		/////////////////////////////////////////////////////////
		System::Void FileNewMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (IsCreatedProject())
			{
				::DialogResult result = System::Windows::Forms::MessageBox::Show(this, "기존 프로젝트의 데이터가 모두 삭제됩니다.\n새로 만드시겠습니까?", "새로만들기", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (::DialogResult::Yes != result) {
					return;
				}
			}
			NewProjectForm^ tmp = gcnew NewProjectForm();
			if (::DialogResult::OK == tmp->ShowDialog())
			{
				m_newProjectForm = tmp;
				m_projectDataSetBinder = gcnew ProjectDataSetBinder(tmp->ReturnDataSet);
				for each (Form^ form in this->MdiChildren)
				{
					// 생성된 모든 창 닫기
					form->Close();
				}
				IsModified = true;
				//IsModified = false;
				UpdateForm();
			}
		}
		System::Void FileOpenMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (IsModified) {
				::DialogResult result = System::Windows::Forms::MessageBox::Show(this, "현재 프로젝트의 저장되지 않은 데이터가 존재합니다.\n파일을 불러오시겠습니까?", "불러오기", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (::DialogResult::Yes != result) {
					return;
				}
			}
			bool result = false;
			String^ filename = CFileDlgUtil::GetProjectDataFile();
			if (!String::IsNullOrEmpty(filename)) {
				result = ReadFile(filename);
			}
			if (result) {
				// 생성된 모든 창 닫기
				for each (Form^ form in this->MdiChildren)
				{
					form->Close();
				}
				//IsModified = false;
				IsModified = true;
				UpdateForm();
			}
		}
		System::Void FileSaveMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
			/*
			if (IsCreatedProject()) {
				bool result = false;
				// if there is not savefilename, save as new filename
				if (String::IsNullOrEmpty(m_projectDataSetBinder->SaveFilename)) {
					SaveFileDialog^ dlg = gcnew SaveFileDialog();
					dlg->Filter = "Project data files (*.prd)|*.prd";
					dlg->Title = "Save";
					dlg->DefaultExt = "prd";

					if (::DialogResult::OK == dlg->ShowDialog()) {
						result = SaveFile(dlg->FileName);
					}
				}
				else {
					result = SaveFile(m_projectDataSetBinder->SaveFilename);
				}
				//IsModified = !result;
				IsModified = true;
				UpdateForm();
			}
			*/

			
			bool result = false;
			// if there is not savefilename, save as new filename
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = "Project data files (*.prd)|*.prd";
			dlg->Title = "Save";
			dlg->DefaultExt = "prd";

			if (::DialogResult::OK == dlg->ShowDialog()) {
				result = SaveFile(dlg->FileName);
			}
			//IsModified = !result;
			IsModified = true;
			UpdateForm();
			

		}
		System::Void FilePreferencesMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// TODO:: not prepared
		}
		System::Void FileExitMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
		/////////////////////////////////////////////////////////
		// Project menu group
		/////////////////////////////////////////////////////////
			System::Void ProjectStep0MenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				// 각 메뉴당 하나씩의 인스턴스만 존재하므로 인스턴스 체크
				if (!IsCreatedFormInstance(m_step0Form)) {
					// instance가 없으면 새로 만듬
					Step0Form^ _form = gcnew Step0Form(m_projectDataSetBinder);
					// 해당 폼을 열기위한 validation 체크
					if (!_form->IsValidToOpenForm()) {
						return;
					}
					// title 변경
					_form->Text = ((ToolStripMenuItem^)sender)->Text;
					_form->MdiParent = this;
					//_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
					m_step0Form = _form;
					m_step0Form->Show();
					
					}
			}
		   System::Void ProjectStep1MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// 각 메뉴당 하나씩의 인스턴스만 존재하므로 인스턴스 체크
			if (!IsCreatedFormInstance(m_step1Form)) {
				// instance가 없으면 새로 만듬
				Step1Form^ _form = gcnew Step1Form(m_projectDataSetBinder);
				// 해당 폼을 열기위한 validation 체크
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				// title 변경
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				//_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step1Form = _form;
				m_step1Form->Show();
			}
		}
		System::Void ProjectStep2MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step2Form)) {
				Step2Form^ _form = gcnew Step2Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step2Form = _form;
				m_step2Form->Show();
			}
		}
		System::Void ProjectStep3MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step3Form)) {
				Step3Form^ _form = gcnew Step3Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step3Form = _form;
				m_step3Form->Show();
			}
		}
		System::Void ProjectStep4MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step4Form)) {
				Step4Form^ _form = gcnew Step4Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step4Form = _form;
				m_step4Form->Show();
			}
		}
		System::Void ProjectStep5MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step5Form)) {
				Step5Form^ _form = gcnew Step5Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step5Form = _form;
				m_step5Form->Show();
			}
		}
		System::Void ProjectStep6MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step6Form)) {
				Step6Form^ _form = gcnew Step6Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step6Form = _form;
				m_step6Form->Show();
			}
		}
		System::Void ProjectStep7MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step7Form)) {
				Step7Form^ _form = gcnew Step7Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step7Form = _form;
				m_step7Form->Show();
			}
		}
		System::Void ProjectStep8MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step8Form)) {
				Step8Form^ _form = gcnew Step8Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step8Form = _form;
				m_step8Form->Show();
			}
		}
		/////////////////////////////////////////////////////////
		// NeXTA menu group
		/////////////////////////////////////////////////////////
		System::Void NeXTAInputMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!IsCreatedFormInstance(m_neXTAInput)) {
				NeXTAInput^ _form = gcnew NeXTAInput(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_neXTAInput = _form;
				m_neXTAInput->Show();
			}
		}


		System::Void NeXTARunMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!IsCreatedFormInstance(m_step9Form)) {
				Step9Form^ _form = gcnew Step9Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step9Form = _form;
				m_step9Form->Show();
			}
		}

		/////////////////////////////////////////////////////////
		// Result menu group
		/////////////////////////////////////////////////////////
		System::Void ResultStep10MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step10Form)) {
				Step10Form^ _form = gcnew Step10Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step10Form = _form;
				m_step10Form->Show();
			}
		}
		System::Void ResultStep10bMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step10bForm)) {
				Step10bForm^ _form = gcnew Step10bForm(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step10bForm = _form;
				m_step10bForm->Show();
			}
		}
		System::Void ResultStep11MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step11Form)) {
				Step11Form^ _form = gcnew Step11Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step11Form = _form;
				m_step11Form->Show();
			}
		}
		System::Void ResultStep12MenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsCreatedFormInstance(m_step12Form)) {
				Step12Form^ _form = gcnew Step12Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step12Form = _form;
				m_step12Form->Show();
			}
		}
		System::Void decisionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!IsCreatedFormInstance(m_step13Form)) {
				Step13Form^ _form = gcnew Step13Form(m_projectDataSetBinder);
				if (!_form->IsValidToOpenForm()) {
					return;
				}
				_form->Text = ((ToolStripMenuItem^)sender)->Text;
				_form->MdiParent = this;
				_form->SaveDataChanged += gcnew EventHandler(this, &MainForm::OnSaveDataChanged);
				m_step13Form = _form;
				m_step13Form->Show();
			}
		}

};
}
