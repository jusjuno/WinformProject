#pragma once
#include "Shape.h"
#include "LegendItemInfo.h"
#include "ComponentClassInfo.h"
#include "ShapeChartAttribute.h"
#include "DisplayOptions.h"

using namespace ChartDirector;
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows;
namespace WinformProject {
	/// <summary>
	/// shape data chart class
	/// </summary>
	ref class ShapeChart
	{
	private:
		static const int						PADDING = 10;// common padding
	public:
		Shape^									m_shape; // shape file data

		Rectangle								m_rect;
		Rectangle								m_mapRect;
		Rectangle								m_legendRect;

		// Display 
		double									m_lfMainRatio; // ��ü ȭ�� �� ���� ����
		double									m_lfZoomFactor;	// Ȯ��/��� ����
		System::Drawing::Point					m_scrCenterPoint; // ȭ�� �߽� ��
		GeoPoint								m_geoCenterPoint; // ���� �߽� ��

		int										m_labelCount;
		int										m_ratioWidth; // ������ ������ ���� map ��
		int										m_ratioHeight; // ������ ������ ���� map ����
		double									m_labelYOffset; // Y�� �� offset
		double									m_labelXOffset; // X�� �� offset
		double									m_geoPointRatio; // 1 geo point ����

		Drawing2D::SmoothingMode				m_SmoothingMode; // chart line smmothing mode

		int										m_markerSize;
		Dictionary<String^, LegendItemInfo>^	m_markers;
		// network components
		System::Data::DataTable^				m_networkComponents;
	private:
		Random^									m_rand;
		Font^									m_legendLabelFont;
		Pen^									m_shapePen;
		Brush^									m_shapeBrush;
		Color									m_shapeColor;
		int										m_shapeLineWidth;
		int										m_symbolSize;
	public:
		// initialize
		ShapeChart(Shape^ shape);

		/// <summary>
		/// native c++ �ҽ��� graphics�� �̿��ϴ� �Լ���
		/// ������ ���� c++/cli�� ���ߵ� �κп����� chartdirector ���̺귯���� ����ϱ� ������ ������� ����
		/// </summary>
	public:
		// draw map chart
		void Draw(Graphics^ g, System::Drawing::Rectangle clientRect);

	private:
		void Draw(Graphics^ g);
		void DrawPoint(Graphics^ g);
		void DrawArc(Graphics^ g);
		void DrawPolygon(Graphics^ g);
		void DrawMultiPoint(Graphics^ g);
		void DrawLegend(Graphics^ g);

		/// <summary>
		/// chartdirector�� ����Ͽ� shape ��Ʈ�� �׸��� �Լ�
		/// </summary>
	public:
		// draw full map chart by chartdirector library
		void Draw(WinChartViewer^ chartViewer, String^ title);

		// draw optional map chart by chartdirector library
		void Draw(WinChartViewer^ chartViewer, String^ title, DisplayOptions options);

		// draw map chart and link viewportcontrol by chartdirector library
		// preview ����� ����ϱ� ���ؼ� viewportcontrol�� ������
		void Draw(WinChartViewer^ chartViewer, WinViewPortControl^ vpc, String^ title);

		// draw network components with map by chartdirector library
		void DrawNetworkComponents(WinChartViewer^ chartViewer, String^ title, array<ComponentClassInfo>^ datas);

		// draw seismic distribution with map by chartdirector library
		void DrawSeismicDistribution(WinChartViewer^ chartViewer, String^ title, array<double>^ dataX, array<double>^ dataY, array<double>^ dataZ);

		// draw vulnerability map by chartdirector library
		void DrawVulnerabilityMap(WinChartViewer^ chartViewer, String^ title, array<double>^ dataX, array<double>^ dataY, array<double>^ dataZ);

		// draw traffic phase with map by chartdirector library
		void DrawTrafficPhase(WinChartViewer^ chartViewer, String^ title);

	private:
		// get chart property 
		XYChart^ CreateShapeChartProperty(String^ title, int chartWidth, int chartHeight, int plotAreaX, int plotAreaY, int plotAreaWidth, int plotAreaHeight);

		// draw
		void Draw(XYChart^ chartViewer, bool useProperties);

		// draw arc shape type
		void DrawArc(XYChart^ chartViewer, bool useProperties);

		// convert window point to geometry point
		GeoPoint DeviceToWorld(System::Drawing::Point _point, double _lfRatio) {
			GeoPoint tmpGeoPoint;
			tmpGeoPoint.x = m_shape->m_geoCenterPoint.x + (_point.X - m_scrCenterPoint.X) / (m_lfZoomFactor * _lfRatio);
			tmpGeoPoint.y = m_shape->m_geoCenterPoint.y - (_point.Y - m_scrCenterPoint.Y) / (m_lfZoomFactor * _lfRatio);
			return tmpGeoPoint;
		}

		// convert window point to geometry point
		System::Drawing::Point WorldToDevice(GeoPoint _geoPoint, double _lfRatio) {
			System::Drawing::Point tmpPoint;
			tmpPoint.X = long(_lfRatio * (_geoPoint.x - m_shape->m_geoCenterPoint.x) * m_lfZoomFactor + m_scrCenterPoint.X);
			tmpPoint.Y = long(_lfRatio * (m_shape->m_geoCenterPoint.y - _geoPoint.y) * m_lfZoomFactor + m_scrCenterPoint.Y);
			return tmpPoint;
		}

	public:
		// set map line color
		void SetShapeColor(Color color) {
			m_shapeColor = color;
			m_shapePen = gcnew Pen(m_shapeColor);
			m_shapeBrush = gcnew SolidBrush(m_shapeColor);
		}

		// set map line width
		void SetShapeWidth(int width) {
			this->m_shapeLineWidth = width;
		}

		void SetSymbolSize(int size) {
			this->m_symbolSize = size;
		}

		// convert color to int 
		int ColorToInt(Color color) {
			int c = color.ToArgb();
			c = c & 0x00FFFFFF; // AARRGGBB �������� AA����
			return c;
		}

		// get random color
		Color GetRandomColor() {
			return Color::FromArgb(m_rand->Next(256), m_rand->Next(256), m_rand->Next(256));
		}
	};
}

