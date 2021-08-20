#pragma once
#include "CommonHeader.h"
#include "ProjectDataSetBinder.h"
#include "ShapeChart.h"
#include "ChartHotspotAttrDialog.h"

namespace WinformProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Step1Form에 대한 요약입니다.
	/// BaseForm을 상속하여 사용하면 디자인 화면이 에러가 발생하기 때문에 
	/// 폼을 수정하고 싶을땐 Form 으로 상속을 변경하여 수정 후 다시 BaseForm으로 변경해야 함
	/// </summary>
	//public ref class Step1Form : public System::Windows::Forms::Form, IFormValidator
	public ref class Step1Form : public WinformProject::BaseForm, IFormValidator
	{
	private:
		ProjectDataSetBinder^		m_dataSet;
		ShapeChart^			m_chart;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: ChartDirector::WinViewPortControl^  viewPortControl;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btnZoomOut;
	private: System::Windows::Forms::Button^  btnZoomIn;
	private: System::Windows::Forms::TreeView^  tvDisplayOptions;
	private: System::Windows::Forms::Button^  btnPoint;

	private: ChartDirector::WinChartViewer^  chartViewer;
	public:
		Step1Form(ProjectDataSetBinder^ dataSet)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->m_dataSet = dataSet;
			m_chart = gcnew ShapeChart(dataSet->ShapeData);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Step1Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Step1Form::typeid));
			this->chartViewer = (gcnew ChartDirector::WinChartViewer());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->viewPortControl = (gcnew ChartDirector::WinViewPortControl(this->components));
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnZoomOut = (gcnew System::Windows::Forms::Button());
			this->btnZoomIn = (gcnew System::Windows::Forms::Button());
			this->tvDisplayOptions = (gcnew System::Windows::Forms::TreeView());
			this->btnPoint = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewPortControl))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// chartViewer
			// 
			resources->ApplyResources(this->chartViewer, L"chartViewer");
			this->chartViewer->HotSpotCursor = System::Windows::Forms::Cursors::Hand;
			this->chartViewer->MouseUsage = ChartDirector::WinChartMouseUsage::ScrollOnDrag;
			this->chartViewer->Name = L"chartViewer";
			this->tableLayoutPanel1->SetRowSpan(this->chartViewer, 2);
			this->chartViewer->ScrollDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->TabStop = false;
			this->chartViewer->ZoomDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->ZoomInHeightLimit = 0.1;
			this->chartViewer->ClickHotSpot += gcnew ChartDirector::WinHotSpotEventHandler(this, &Step1Form::chartViewer_ClickHotSpot);
			this->chartViewer->ViewPortChanged += gcnew ChartDirector::WinViewPortEventHandler(this, &Step1Form::chartViewer_ViewPortChanged);
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step1Form::chartViewer_SizeChanged);
			// 
			// tableLayoutPanel1
			// 
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->viewPortControl, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// viewPortControl
			// 
			resources->ApplyResources(this->viewPortControl, L"viewPortControl");
			this->viewPortControl->Name = L"viewPortControl";
			this->viewPortControl->TabStop = false;
			this->viewPortControl->Viewer = this->chartViewer;
			// 
			// tableLayoutPanel2
			// 
			resources->ApplyResources(this->tableLayoutPanel2, L"tableLayoutPanel2");
			this->tableLayoutPanel2->Controls->Add(this->btnZoomOut, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->btnZoomIn, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tvDisplayOptions, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->btnPoint, 0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			// 
			// btnZoomOut
			// 
			resources->ApplyResources(this->btnZoomOut, L"btnZoomOut");
			this->btnZoomOut->Name = L"btnZoomOut";
			this->btnZoomOut->UseVisualStyleBackColor = true;
			this->btnZoomOut->Click += gcnew System::EventHandler(this, &Step1Form::btnZoomOut_Click);
			// 
			// btnZoomIn
			// 
			resources->ApplyResources(this->btnZoomIn, L"btnZoomIn");
			this->btnZoomIn->Name = L"btnZoomIn";
			this->btnZoomIn->UseVisualStyleBackColor = true;
			this->btnZoomIn->Click += gcnew System::EventHandler(this, &Step1Form::btnZoomIn_Click);
			// 
			// tvDisplayOptions
			// 
			resources->ApplyResources(this->tvDisplayOptions, L"tvDisplayOptions");
			this->tvDisplayOptions->CheckBoxes = true;
			this->tvDisplayOptions->Name = L"tvDisplayOptions";
			this->tvDisplayOptions->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
				(cli::safe_cast<System::Windows::Forms::TreeNode^>(resources->GetObject(L"tvDisplayOptions.Nodes"))),
					(cli::safe_cast<System::Windows::Forms::TreeNode^>(resources->GetObject(L"tvDisplayOptions.Nodes1")))
			});
			this->tvDisplayOptions->ShowPlusMinus = false;
			this->tvDisplayOptions->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCheck);
			this->tvDisplayOptions->AfterCollapse += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCollapse);
			// 
			// btnPoint
			// 
			resources->ApplyResources(this->btnPoint, L"btnPoint");
			this->btnPoint->Name = L"btnPoint";
			this->btnPoint->UseVisualStyleBackColor = true;
			this->btnPoint->Click += gcnew System::EventHandler(this, &Step1Form::btnPoint_Click);
			// 
			// Step1Form
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step1Form";
			this->Load += gcnew System::EventHandler(this, &Step1Form::Step1Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartViewer))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewPortControl))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: virtual bool IsValidToOpenForm() = IFormValidator::IsValidToOpenForm{
		return true;
	}
	private:
		// 하위 노드 체크 상태 변경
		void CheckChildNode(TreeNode^ selectNode) {
			for each(TreeNode^ tn in selectNode->Nodes) {
				// 하위 노드를 현재 선택된 노드의 상태와 동일하게 변경
				tn->Checked = selectNode->Checked;
				CheckChildNode(tn);
			}
			return;
		}
		// 상위 노드 체크 상태 변경
		void CheckParentNode(TreeNode^ selectNode) {
			// 상위 노드를 현재 하위 노드들의 선택된 노드의 상태와 동일하게 변경
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// 하위 노드가 체크이면 상위 노드는 무조건 1개 이상 이므로 체크
					t->Checked = true;
				}
				else {
					// 체크가 아닐경우 다른 노드들 중 체크가 있는지 확인
					t->Checked = IsCheckedChildNode(t);
				}
			}
		}
		// 노드 체크 상태 변경
		void CheckNode(TreeNode^ selectNode) {
			// 상위 노드를 현재 하위 노드들의 선택된 노드의 상태와 동일하게 변경
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// 하위 노드가 체크이면 상위 노드는 무조건 1개 이상 이므로 체크
					t->Checked = true;
				}
			}
			else {
				// selected node is parent node
				if (!selectNode->Checked) {
					// 체크해제 시 하위의 모든 노드를 체크 해제, 체크 시는 상관없음
					CheckChildNode(selectNode);
				}
			}
		}
		// 하위 노드들 중 체크 상태인 노드 확인
		bool IsCheckedChildNode(TreeNode^ node) {
			for each(TreeNode^ tn in node->Nodes) {
				if (tn->Checked || IsCheckedChildNode(tn)) {
					return true;
				}
			}
			return false;
		}
		// 옵션 체크
		bool CheckNodeOption(TreeNode^ node, String^ name) {
			for each(TreeNode^ tn in node->Nodes) {
				if (tn->Name == name) {
					return tn->Checked;
				}
			}
			return false;
		}
		void DrawChart() {
			// check display options
			DisplayOptions options;
			for each (TreeNode^ node in tvDisplayOptions->Nodes)
			{
				if (node->Name == "Node") {
					options.Node = node->Checked;
					options.NodeID = CheckNodeOption(node, "NodeID");
				}
				else if (node->Name == "Link") {
					options.Link = node->Checked;
					options.LinkID = CheckNodeOption(node, "LinkID");
				}
			}

			m_chart->Draw(chartViewer, "Road Network", options);
		}
		// 줌 인/아웃
		void ZoomChartViewer()
		{
			if (!chartViewer->IsInViewPortChangedEvent)
			{
				//Remember the center point
				double centerX = chartViewer->ViewPortLeft + chartViewer->ViewPortWidth / 2;
				double centerY = chartViewer->ViewPortTop + chartViewer->ViewPortHeight / 2;

				//Aspect ratio and zoom factor
				double aspectRatio = chartViewer->ViewPortWidth / chartViewer->ViewPortHeight;
				double zoomTo = ((double)Math::Round(Math::Min(chartViewer->ViewPortWidth, chartViewer->ViewPortHeight) * 100)) / 100;

				//Zoom while respecting the aspect ratio
				chartViewer->ViewPortWidth = zoomTo * Math::Max(1.0, aspectRatio);
				chartViewer->ViewPortHeight = zoomTo * Math::Max(1.0, 1 / aspectRatio);

				//Adjust ViewPortLeft and ViewPortTop to keep center point unchanged
				chartViewer->ViewPortLeft = centerX - chartViewer->ViewPortWidth / 2;
				chartViewer->ViewPortTop = centerY - chartViewer->ViewPortHeight / 2;

				//update the chart, but no need to update the image map yet, as the chart is still
				//zooming and is unstable
				chartViewer->updateViewPort(true, false);
			}
		}

	private: System::Void Step1Form_Load(System::Object^  sender, System::EventArgs^  e) {
		tvDisplayOptions->ExpandAll();
		chartViewer->updateViewPort(true, true);
		m_chart->Draw(chartViewer, viewPortControl, "Road Network");
	}
	private: System::Void chartViewer_SizeChanged(System::Object^  sender, System::EventArgs^  e) {

		//Step1Form 보다 먼저 호출 되면서 오류 발생함
		//DrawChart();
		if (this->m_dataSet != nullptr) {
			DrawChart();
		}
	}
			 
	// chartViewer에 연결된 viewport 값이 변경되면 실행 됨
	private: System::Void chartViewer_ViewPortChanged(System::Object^  sender, ChartDirector::WinViewPortEventArgs^  e) {
		ZoomChartViewer();
		// Update the chart if necessary
		if (e->NeedUpdateChart) {
			DrawChart();
		}
	}
	private: System::Void chartViewer_ClickHotSpot(System::Object^  sender, ChartDirector::WinHotSpotEventArgs^  e) {
		ChartHotspotAttrDialog^ dlg = gcnew ChartHotspotAttrDialog(this->m_dataSet);
		dlg->Display(sender, e);
	}
	private: System::Void tvDisplayOptions_AfterCheck(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		this->tvDisplayOptions->AfterCheck -= gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCheck);
		CheckChildNode(e->Node);
		CheckNode(e->Node);
		this->tvDisplayOptions->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCheck);
		DrawChart();
	}
	private: System::Void btnPoint_Click(System::Object^  sender, System::EventArgs^  e) {
		// 마우스 커서 변경(포인터)
		chartViewer->MouseUsage = WinChartMouseUsage::ScrollOnDrag;
	}
	private: System::Void btnZoomIn_Click(System::Object^  sender, System::EventArgs^  e) {
		// 마우스 커서 변경(줌인)
		chartViewer->MouseUsage = WinChartMouseUsage::ZoomIn;
	}
	private: System::Void btnZoomOut_Click(System::Object^  sender, System::EventArgs^  e) {
		// 마우스 커스 변경(줌아웃)
		chartViewer->MouseUsage = WinChartMouseUsage::ZoomOut;
	}
	private: System::Void tvDisplayOptions_AfterCollapse(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		// 무조건 전체 전체 열기
		tvDisplayOptions->ExpandAll();
	}
	};
}