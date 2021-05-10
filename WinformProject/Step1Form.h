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
	/// Step1Form�� ���� ����Դϴ�.
	/// BaseForm�� ����Ͽ� ����ϸ� ������ ȭ���� ������ �߻��ϱ� ������ 
	/// ���� �����ϰ� ������ Form ���� ����� �����Ͽ� ���� �� �ٽ� BaseForm���� �����ؾ� ��
	/// </summary>
	public ref class Step1Form : public System::Windows::Forms::Form, IFormValidator
		//public ref class Step1Form : public WinformProject::BaseForm, IFormValidator
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
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			this->m_dataSet = dataSet;
			m_chart = gcnew ShapeChart(dataSet->ShapeData);
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"ID"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Link", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 }));
			System::Windows::Forms::TreeNode^  treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"ID"));
			System::Windows::Forms::TreeNode^  treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"Node", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode3 }));
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
			this->chartViewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartViewer->HotSpotCursor = System::Windows::Forms::Cursors::Hand;
			this->chartViewer->Location = System::Drawing::Point(153, 3);
			this->chartViewer->MouseUsage = ChartDirector::WinChartMouseUsage::ScrollOnDrag;
			this->chartViewer->Name = L"chartViewer";
			this->tableLayoutPanel1->SetRowSpan(this->chartViewer, 2);
			this->chartViewer->ScrollDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->Size = System::Drawing::Size(928, 755);
			this->chartViewer->TabIndex = 0;
			this->chartViewer->TabStop = false;
			this->chartViewer->ZoomDirection = ChartDirector::WinChartDirection::HorizontalVertical;
			this->chartViewer->ZoomInHeightLimit = 0.1;
			this->chartViewer->ClickHotSpot += gcnew ChartDirector::WinHotSpotEventHandler(this, &Step1Form::chartViewer_ClickHotSpot);
			this->chartViewer->ViewPortChanged += gcnew ChartDirector::WinViewPortEventHandler(this, &Step1Form::chartViewer_ViewPortChanged);
			this->chartViewer->SizeChanged += gcnew System::EventHandler(this, &Step1Form::chartViewer_SizeChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->chartViewer, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->viewPortControl, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1084, 761);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// viewPortControl
			// 
			this->viewPortControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->viewPortControl->Location = System::Drawing::Point(3, 3);
			this->viewPortControl->Name = L"viewPortControl";
			this->viewPortControl->Size = System::Drawing::Size(144, 144);
			this->viewPortControl->TabIndex = 1;
			this->viewPortControl->TabStop = false;
			this->viewPortControl->Viewer = this->chartViewer;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->btnZoomOut, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->btnZoomIn, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tvDisplayOptions, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->btnPoint, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 153);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(144, 605);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// btnZoomOut
			// 
			this->btnZoomOut->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnZoomOut->Location = System::Drawing::Point(3, 73);
			this->btnZoomOut->Name = L"btnZoomOut";
			this->btnZoomOut->Size = System::Drawing::Size(138, 29);
			this->btnZoomOut->TabIndex = 6;
			this->btnZoomOut->Text = L"ZoomOut";
			this->btnZoomOut->UseVisualStyleBackColor = true;
			this->btnZoomOut->Click += gcnew System::EventHandler(this, &Step1Form::btnZoomOut_Click);
			// 
			// btnZoomIn
			// 
			this->btnZoomIn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnZoomIn->Location = System::Drawing::Point(3, 38);
			this->btnZoomIn->Name = L"btnZoomIn";
			this->btnZoomIn->Size = System::Drawing::Size(138, 29);
			this->btnZoomIn->TabIndex = 5;
			this->btnZoomIn->Text = L"ZoomIn";
			this->btnZoomIn->UseVisualStyleBackColor = true;
			this->btnZoomIn->Click += gcnew System::EventHandler(this, &Step1Form::btnZoomIn_Click);
			// 
			// tvDisplayOptions
			// 
			this->tvDisplayOptions->CheckBoxes = true;
			this->tvDisplayOptions->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tvDisplayOptions->Location = System::Drawing::Point(3, 108);
			this->tvDisplayOptions->Name = L"tvDisplayOptions";
			treeNode1->Name = L"LinkID";
			treeNode1->Text = L"ID";
			treeNode2->Checked = true;
			treeNode2->Name = L"Link";
			treeNode2->Text = L"Link";
			treeNode3->Name = L"NodeID";
			treeNode3->Text = L"ID";
			treeNode4->Name = L"Node";
			treeNode4->Text = L"Node";
			this->tvDisplayOptions->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) { treeNode2, treeNode4 });
			this->tvDisplayOptions->ShowPlusMinus = false;
			this->tvDisplayOptions->Size = System::Drawing::Size(138, 494);
			this->tvDisplayOptions->TabIndex = 3;
			this->tvDisplayOptions->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCheck);
			this->tvDisplayOptions->AfterCollapse += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Step1Form::tvDisplayOptions_AfterCollapse);
			// 
			// btnPoint
			// 
			this->btnPoint->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnPoint->Location = System::Drawing::Point(3, 3);
			this->btnPoint->Name = L"btnPoint";
			this->btnPoint->Size = System::Drawing::Size(138, 29);
			this->btnPoint->TabIndex = 4;
			this->btnPoint->Text = L"Pointer";
			this->btnPoint->UseVisualStyleBackColor = true;
			this->btnPoint->Click += gcnew System::EventHandler(this, &Step1Form::btnPoint_Click);
			// 
			// Step1Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 761);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Step1Form";
			this->Text = L"Definition of Road Network";
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
		// ���� ��� üũ ���� ����
		void CheckChildNode(TreeNode^ selectNode) {
			for each(TreeNode^ tn in selectNode->Nodes) {
				// ���� ��带 ���� ���õ� ����� ���¿� �����ϰ� ����
				tn->Checked = selectNode->Checked;
				CheckChildNode(tn);
			}
			return;
		}
		// ���� ��� üũ ���� ����
		void CheckParentNode(TreeNode^ selectNode) {
			// ���� ��带 ���� ���� ������ ���õ� ����� ���¿� �����ϰ� ����
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// ���� ��尡 üũ�̸� ���� ���� ������ 1�� �̻� �̹Ƿ� üũ
					t->Checked = true;
				}
				else {
					// üũ�� �ƴҰ�� �ٸ� ���� �� üũ�� �ִ��� Ȯ��
					t->Checked = IsCheckedChildNode(t);
				}
			}
		}
		// ��� üũ ���� ����
		void CheckNode(TreeNode^ selectNode) {
			// ���� ��带 ���� ���� ������ ���õ� ����� ���¿� �����ϰ� ����
			TreeNode^ t = selectNode->Parent;
			if (t != nullptr) {
				// selected node is child node
				if (selectNode->Checked) {
					// ���� ��尡 üũ�̸� ���� ���� ������ 1�� �̻� �̹Ƿ� üũ
					t->Checked = true;
				}
			}
			else {
				// selected node is parent node
				if (!selectNode->Checked) {
					// üũ���� �� ������ ��� ��带 üũ ����, üũ �ô� �������
					CheckChildNode(selectNode);
				}
			}
		}
		// ���� ���� �� üũ ������ ��� Ȯ��
		bool IsCheckedChildNode(TreeNode^ node) {
			for each(TreeNode^ tn in node->Nodes) {
				if (tn->Checked || IsCheckedChildNode(tn)) {
					return true;
				}
			}
			return false;
		}
		// �ɼ� üũ
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
		// �� ��/�ƿ�
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
		DrawChart();
	}
			 // chartViewer�� ����� viewport ���� ����Ǹ� ���� ��
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
		// ���콺 Ŀ�� ����(������)
		chartViewer->MouseUsage = WinChartMouseUsage::ScrollOnDrag;
	}
	private: System::Void btnZoomIn_Click(System::Object^  sender, System::EventArgs^  e) {
		// ���콺 Ŀ�� ����(����)
		chartViewer->MouseUsage = WinChartMouseUsage::ZoomIn;
	}
	private: System::Void btnZoomOut_Click(System::Object^  sender, System::EventArgs^  e) {
		// ���콺 Ŀ�� ����(�ܾƿ�)
		chartViewer->MouseUsage = WinChartMouseUsage::ZoomOut;
	}
	private: System::Void tvDisplayOptions_AfterCollapse(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		// ������ ��ü ��ü ����
		tvDisplayOptions->ExpandAll();
	}
	};
}