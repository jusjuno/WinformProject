#include "ShapeChart.h"
#include <cmath>


WinformProject::ShapeChart::ShapeChart(Shape^ shape)
{
	this->m_shape = shape;
	m_lfMainRatio = 0.0;
	m_lfZoomFactor = 0.9;
	m_labelCount = 10;
	SetShapeColor(Color::Black);
	SetShapeWidth(1);
	SetSymbolSize(12);
	m_SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	m_rand = gcnew Random();
	m_markerSize = 5;
	m_markers = gcnew Dictionary<String^, LegendItemInfo>();
	m_legendLabelFont = gcnew Font(gcnew FontFamily(L"����"), 10.00F, System::Drawing::FontStyle::Bold);
}


void WinformProject::ShapeChart::Draw(Graphics^ g, System::Drawing::Rectangle clientRect)
{
	g->SmoothingMode = m_SmoothingMode;
	g->Clear(Color::White);

	m_rect = clientRect;
	
	// ������ �׷��� �κ�(��Ʈ ��ü ȭ���� ��/�� 10%�� ������ ��� �κ�)
	m_mapRect = Rectangle::FromLTRB(m_rect.Width * 0.1, 0, m_rect.Width, m_rect.Height - (m_rect.Height * 0.1));
	g->FillRectangle(Brushes::LightYellow, m_mapRect);

	// ��Ⱦ�� ���..
	double lfRatio_X = fabs(m_mapRect.Width / (m_shape->m_MBR.xmax - m_shape->m_MBR.xmin));
	double lfRatio_Y = fabs(m_mapRect.Height / (m_shape->m_MBR.ymax - m_shape->m_MBR.ymin));

	// ���� ���...
	if (lfRatio_X < lfRatio_Y)
		m_lfMainRatio = lfRatio_X;
	else
		m_lfMainRatio = lfRatio_Y;

	// ȭ�� �߽��·�(X, Y)
	m_scrCenterPoint.X = m_mapRect.Width / 2 + m_mapRect.Left;
	m_scrCenterPoint.Y = m_mapRect.Height / 2 + m_mapRect.Top;

	// shape ���ϳ��� �׸���
	this->Draw(g);

	// Draw asixs
	double diffValueX = m_shape->m_MBR.xmax - m_shape->m_MBR.xmin;
	double diffValueY = m_shape->m_MBR.ymax - m_shape->m_MBR.ymin;
	m_geoPointRatio = m_lfMainRatio * m_lfZoomFactor;
	m_ratioWidth = diffValueX * m_geoPointRatio;
	m_ratioHeight = diffValueY * m_geoPointRatio;

	// y���� ���ݴ� ��ǥ�� ���̸� �����Ѵ�.
	double step = m_ratioHeight / double(m_labelCount - 1);
	double pos = 0.0;
	m_labelYOffset = ((m_mapRect.Bottom - m_ratioHeight) / 2);

	// y���� ���ݴ� ��ġ���� �����Ѵ�.
	double scale = (m_shape->m_MBR.ymax - m_shape->m_MBR.ymin) / double(m_labelCount - 1);
	FontFamily^ ff = gcnew FontFamily(L"����");
	Font^ labelFont = gcnew Font(ff, 10.00F);
	Pen^ axisLineColor = Pens::Black;
	Brush^ axisFontColor = Brushes::Black;
	int i = 0;
	for (i = 0; i < m_labelCount; i++) {
		// ���ݰ� ��ġ���� �׸� y��ǥ�� �����Ѵ�.
		pos = m_labelYOffset + step * i;
		// y���� ������ �׸���.
		g->DrawLine(axisLineColor, m_mapRect.Left - 1, int(pos), m_mapRect.Left - 6, int(pos));
		// ������ ��ġ(�ִ밪�� ������ ������ ���� ��)�� ���ڷ� ����Ѵ�.
		g->DrawString(String::Format(L"{0:F3}", m_shape->m_MBR.ymax - scale * i), labelFont, axisFontColor, m_mapRect.Left * 0.3, pos - 8);
	}
	// x���� ���ݴ� ��ǥ�� ���̸� �����Ѵ�.
	step = m_ratioWidth / double(m_labelCount - 1);
	pos = 0.0;
	m_labelXOffset = (m_rect.Right - m_mapRect.Width - m_rect.Left) + ((m_mapRect.Width - m_ratioWidth) / 2);
	// x���� ���ݴ� ��ġ���� �����Ѵ�.
	scale = (m_shape->m_MBR.xmax - m_shape->m_MBR.xmin) / double(m_labelCount - 1);
	for (i = 0; i < m_labelCount; i++) {
		// ���ݰ� ��ġ���� �׸� x��ǥ�� �����Ѵ�.
		pos = m_labelXOffset + (step * i);
		// x���� ������ �׸���.
		g->DrawLine(axisLineColor, int(pos), m_mapRect.Bottom + 1, int(pos), m_mapRect.Bottom + 6);
		// ������ ��ġ(�ִ밪�� ������ ������ ���� ��)�� ���ڷ� ����Ѵ�.
		g->DrawString(String::Format(L"{0:F3}", m_shape->m_MBR.xmin + scale * i), labelFont, axisFontColor, int(pos - 15), m_mapRect.Bottom + 15);
	}

	g->DrawLine(axisLineColor, m_mapRect.Left, m_mapRect.Top, m_mapRect.Left, m_mapRect.Bottom);
	g->DrawLine(axisLineColor, m_mapRect.Left, m_mapRect.Bottom, m_mapRect.Right, m_mapRect.Bottom);
}


void WinformProject::ShapeChart::Draw(Graphics^ g)
{
	switch (m_shape->m_nShapeType)
	{
	case SHPT_POINT:		//point drawing
		DrawPoint(g);
		break;

	case SHPT_ARC:			//arc drawing
		DrawArc(g);
		break;

	case SHPT_POLYGON:		//polygon drawing
		DrawPolygon(g);
		break;

	case SHPT_MULTIPOINT:	//multipoint drawing
		DrawMultiPoint(g);
		break;
	}
}


void WinformProject::ShapeChart::Draw(XYChart^ chart, bool useProperties)
{
	switch (m_shape->m_nShapeType)
	{
	case SHPT_POINT:		//point drawing
		// not support
		break;

	case SHPT_ARC:			//arc drawing
		DrawArc(chart, useProperties);
		break;

	case SHPT_POLYGON:		//polygon drawing
		// not support
		break;

	case SHPT_MULTIPOINT:	//multipoint drawing
		// not support
		break;
	}
}


// ����Ʈ�� �׸���.
void WinformProject::ShapeChart::DrawPoint(Graphics^ g)
{
	System::Drawing::Point tmpPoint;
	// ����Ʈ�� ������ŭ ���鼭 ȭ�鿡 �׸���.
	for (int i = 0; i < m_shape->m_nRecords; ++i)
	{
		tmpPoint = WorldToDevice(m_shape->m_pSHPPoints[i], m_lfMainRatio);
		g->DrawEllipse(m_shapePen, Rectangle::FromLTRB(tmpPoint.X - 2, tmpPoint.Y - 2, tmpPoint.X + 2, tmpPoint.Y + 2));
	}
}


// �������� Ȥ�� ARC��� ���� �׸���.
void WinformProject::ShapeChart::DrawArc(Graphics^ g)
{
	// ���������� ������ŭ ���鼭 �׸���.
	for (int i = 0; i < m_shape->m_nRecords; ++i)
	{
		// ȭ�鿡 �׸� ����Ʈ�� �Ҵ��ϰ�..
		array<System::Drawing::Point>^ arrSrcPoint = gcnew array<System::Drawing::Point>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
		{
			arrSrcPoint[j] = WorldToDevice(m_shape->m_pSHPPolyObjects[i].arrPoints[j], m_lfMainRatio);
		}

		// ��Ʈ�� ���� �޸𸮸� �Ҵ��ϰ�..
		array<int>^ arrParts = gcnew array<int>(m_shape->m_pSHPPolyObjects[i].nNumParts);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumParts; ++j)
		{
			if (j == m_shape->m_pSHPPolyObjects[i].nNumParts - 1)
				arrParts[j] = m_shape->m_pSHPPolyObjects[i].nNumPoints - m_shape->m_pSHPPolyObjects[i].arrParts[j];
			else
				arrParts[j] = m_shape->m_pSHPPolyObjects[i].arrParts[j + 1] - m_shape->m_pSHPPolyObjects[i].arrParts[j];
		}
		// �׸���..
		g->DrawLines(m_shapePen, arrSrcPoint);
	}
}


// �������� Ȥ�� ARC��� ���� �׸���.
void WinformProject::ShapeChart::DrawArc(XYChart^ chart, bool useProperties)
{
	// ���������� ������ŭ ���鼭 �׸���.
	for (int i = 0; i < m_shape->m_nRecords; ++i)
	{
		// The (x, y) data for the first line
		array<double>^ dataX = gcnew array<double>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		array<double>^ dataY = gcnew array<double>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		// ȭ�鿡 �׸� ����Ʈ�� �Ҵ��ϰ�..
		array<System::Drawing::Point>^ arrSrcPoint = gcnew array<System::Drawing::Point>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
		{
			dataX[j] = m_shape->m_pSHPPolyObjects[i].arrPoints[j].x;
			dataY[j] = m_shape->m_pSHPPolyObjects[i].arrPoints[j].y;
		}

		int colorInt = ColorToInt(m_shapeColor);
		LineLayer^ layer;
		if (useProperties) {
			String^ colorStr = m_shape->m_SHPProperties[i]->GetProperty(ShapeProperty::PropertyType::COLOUR);
			if (!String::IsNullOrEmpty(colorStr)) {
				Int32::TryParse(colorStr, colorInt);
			}
			String^ linkID = m_shape->m_SHPProperties[i]->GetProperty(ShapeProperty::PropertyType::LINK_ID);
			ShapeChartAttribute^ att = gcnew ShapeChartAttribute(AttributeType::Link, linkID);
			layer = chart->addLineLayer(dataY, colorInt, att->GetAttributeToString());
			array<String^>^ info = gcnew array<String^>(dataY->Length);
			for (int j = 0; j < dataY->Length; j++)
			{
				info[j] = att->GetAttributeToString();
			}
			layer->addExtraField(info);
			layer->getHTMLImageMap("clickable", "x={x}&xLabel={xLabel}&dataSet={dataSet}&dataSetName={dataSetName}&value={value}&field0={field0}");
		}
		else {
			layer = chart->addLineLayer(dataY, colorInt);
		}
		layer->setXData(dataX);
		layer->setLineWidth(m_shapeLineWidth);
		//layer->setFastLineMode();
	}
}


// �������� �׸���.
void WinformProject::ShapeChart::DrawPolygon(Graphics^ g)
{
	for (int i = 0; i < m_shape->m_nRecords; ++i)
	{
		// ��ũ�� ����Ʈ�� �Ҵ��ϰ�..
		array<System::Drawing::Point>^ arrSrcPoint = gcnew array<System::Drawing::Point>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
		{
			arrSrcPoint[j] = WorldToDevice(m_shape->m_pSHPPolyObjects[i].arrPoints[j], m_lfMainRatio);
		}

		// ��Ʈ ������ �����ϰ�..
		array<int>^ arrParts = gcnew array<int>(m_shape->m_pSHPPolyObjects[i].nNumParts);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumParts; ++j)
		{
			if (j == m_shape->m_pSHPPolyObjects[i].nNumParts - 1)
				arrParts[j] = m_shape->m_pSHPPolyObjects[i].nNumPoints - m_shape->m_pSHPPolyObjects[i].arrParts[j];
			else
				arrParts[j] = m_shape->m_pSHPPolyObjects[i].arrParts[j + 1] - m_shape->m_pSHPPolyObjects[i].arrParts[j];
		}
		// �׸���..
		g->FillPolygon(m_shapeBrush, arrSrcPoint);
	}
}


// �������� �׸���.
void WinformProject::ShapeChart::DrawMultiPoint(Graphics^ g)
{
	for (int i = 0; i < m_shape->m_nRecords; ++i)
	{
		// ��ũ���� ���� �Ҵ��Ѵ�.
		array<System::Drawing::Point>^ arrScrPoint = gcnew array<System::Drawing::Point>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
		for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
		{
			arrScrPoint[j] = WorldToDevice(m_shape->m_pSHPPolyObjects[i].arrPoints[j], m_lfMainRatio);
			g->DrawEllipse(m_shapePen, Rectangle::FromLTRB(arrScrPoint[j].X - 2, arrScrPoint[j].Y - 2, arrScrPoint[j].X + 2, arrScrPoint[j].Y + 2));
		}
	}
}


void WinformProject::ShapeChart::DrawLegend(Graphics^ g)
{
	if (m_legendRect.IsEmpty)
	{
		m_legendRect.X = m_mapRect.Right - PADDING; // outer padding(10)
		m_legendRect.Y = m_mapRect.Top + PADDING; // outer padding(10)
		int width = 0;
		int height = 0;
		for each (KeyValuePair<String^, LegendItemInfo> item in m_markers)
		{
			width = 10 + item.Value.labelSize.Height + PADDING + item.Value.labelSize.Width + PADDING; // padding(10), marker, padding(10), label, padding(10)
			// ���� ���̰� ū�ɷ� legend�� width�� ����
			if (m_legendRect.X - width < m_legendRect.X) {
				m_legendRect.X = m_legendRect.X - width;
				m_legendRect.Width = width;
			}
			// ���̴� �����۸��� ��� ����
			height += PADDING + item.Value.labelSize.Height; // inner padding(10), height
		}
		m_legendRect.Height = height + PADDING;
	}
	int i = 0;
	g->FillRectangle(Brushes::White, m_legendRect);
	g->DrawRectangle(Pens::Black, m_legendRect);
	int offsetX = m_legendRect.Left + PADDING;
	int offsetY = m_legendRect.Top + PADDING;
	for each (KeyValuePair<String^, LegendItemInfo> item in m_markers)
	{
		int seperateHieght = i * (item.Value.labelSize.Height + PADDING);
		// draw circle
		g->FillEllipse(item.Value.brush, offsetX, offsetY + seperateHieght, item.Value.labelSize.Height, item.Value.labelSize.Height);
		// draw text
		g->DrawString(String::Format(L"{0}", item.Value.label), m_legendLabelFont, Brushes::Black, 
			offsetX + item.Value.labelSize.Height + PADDING, offsetY + seperateHieght);
		i++;
	}
}


void WinformProject::ShapeChart::DrawSeismicDistribution(WinChartViewer^ chartViewer, String^ title, array<double>^ dataX, array<double>^ dataY, array<double>^ dataZ)
{
	int plotAreaWidth = chartViewer->Size.Width - 200;
	int plotAreaHeight = chartViewer->Size.Height - 150;
	XYChart^ chart = CreateShapeChartProperty(title, chartViewer->Size.Width, chartViewer->Size.Height, 80, 80, plotAreaWidth, plotAreaHeight);
	Draw(chart, false);

	// Add a contour layer using the given data
	ContourLayer^ layer = chart->addContourLayer(dataX, dataY, dataZ);

	// Move the grid lines in front of the contour layer
	//chart->getPlotArea()->moveGridBefore(layer);

	// Add a color axis (the legend) in which the top center is anchored at (245, 455). Set
	// the length to 330 pixels and the labels on the top side.
	ColorAxis^ cAxis = layer->setColorAxis(80 + plotAreaWidth + 30, 80, Chart::TopLeft, plotAreaHeight, Chart::Right);

	// Add a bounding box to the color axis using the default line color as border.
	cAxis->setBoundingBox(Chart::Transparent, Chart::LineColor);
	array<double>^ tmp = (array<double>^)dataZ->Clone();
	Array::Sort(tmp);
	double zmin = tmp[0];
	double zmax = tmp[tmp->Length - 1]; 
	cAxis->setLinearScale(zmin, zmax, (zmax - zmin) / 10);

	chartViewer->Chart = chart;
}


void WinformProject::ShapeChart::DrawNetworkComponents(WinChartViewer^ chartViewer, String^ title, array<ComponentClassInfo>^ datas) {
	int plotAreaWidth = chartViewer->Size.Width - 130;
	int plotAreaHeight = chartViewer->Size.Height - 150;
	XYChart^ chart = CreateShapeChartProperty(title, chartViewer->Size.Width, chartViewer->Size.Height, 80, 80, plotAreaWidth, plotAreaHeight);

	chart->addLegend(50, 30, false, "Arial Bold", 12)->setBackground(Chart::Transparent);
	for (int i = 0; i < datas->Length; i++)
	{
		ComponentClassInfo info = datas[i];
		ChartDirector::ScatterLayer^ layer = chart->addScatterLayer(info.dataX, info.dataY, info.name, info.symbol, m_symbolSize, ColorToInt(info.color));

		int dataSize = info.dataX->Length;
		array<String^>^ text = gcnew array<String^>(dataSize);
		ShapeChartAttribute^ attr = gcnew ShapeChartAttribute(AttributeType::Component);
		for (int j = 0; j < dataSize; j++)
		{
			text[j] = attr->GetAttributeToString();
		}
		layer->addExtraField(text);
		layer->getHTMLImageMap("clickable", "x={x}&xLabel={xLabel}&dataSet={dataSet}&dataSetName={dataSetName}&value={value}&field0={field0}");
	}
	
	Draw(chart, false);
	chartViewer->Chart = chart;
	chartViewer->ImageMap = chart->getHTMLImageMap("clickable", "x={x}&xLabel={xLabel}&dataSet={dataSet}&dataSetName={dataSetName}&value={value}&field0={field0}");
}


void WinformProject::ShapeChart::DrawVulnerabilityMap(WinChartViewer^ chartViewer, String^ title, array<double>^ dataX, array<double>^ dataY, array<double>^ dataZ) {
	int plotAreaWidth = chartViewer->Size.Width - 200;
	int plotAreaHeight = chartViewer->Size.Height - 150;

	XYChart^ chart = gcnew XYChart(0, 0);
	// Add a contour layer using the given data
	ColorAxis^ tmpAxis = chart->addContourLayer(nullptr, nullptr, nullptr)->setColorAxis(0, 0, Chart::TopLeft, plotAreaHeight, Chart::Right);
	tmpAxis->setBoundingBox(Chart::Transparent, Chart::Transparent);
	double zmin = 0;
	double zmax = 100;
	tmpAxis->setLinearScale(zmin, zmax, (zmax - zmin) / 10);
	array<int>^ colorGradient = { 0x373194, 0x34b9a1, 0xffc545 };
	tmpAxis->setColorGradient(true, colorGradient);
	chart->layout();

	// ColorAxis���� GetColor�� ����ϱ� ���� layout �Լ��� ����� ������Ʈ �ؾ�������
	// ������Ʈ ���Ŀ��� chart�� layer�� �߰��� �� ���� 
	// ���� ȭ�鿡 �����ִ� ��Ʈ�� �Ʒ��ڵ忡�� ���� ���ڵ�� color ���� ����ϱ� ���� ����
	chart = CreateShapeChartProperty(title, chartViewer->Size.Width, chartViewer->Size.Height, 80, 80, plotAreaWidth, plotAreaHeight);
	ContourLayer^ layer = chart->addContourLayer(nullptr, nullptr, nullptr);
	ColorAxis^ cAxis = layer->setColorAxis(80 + plotAreaWidth + 30, 80, Chart::TopLeft, plotAreaHeight, Chart::Right);
	cAxis->setBoundingBox(Chart::Transparent, Chart::LineColor);
	cAxis->setLinearScale(zmin, zmax, (zmax - zmin) / 10);
	cAxis->setColorGradient(true, colorGradient);

	array<double>^ _arrX = gcnew array<double>(1);
	array<double>^ _arrY = gcnew array<double>(1);
	int color = 0;
	for (int i = 0; i < dataX->Length; i++)
	{
		_arrX[0] = dataX[i];
		_arrY[0] = dataY[i];
		color = tmpAxis->getColor(dataZ[i]);
		Debug::Print("{0} = {1:d}", i, color);
		ScatterLayer^ l = chart->addScatterLayer(_arrX, _arrY, nullptr, Chart::CircleShape, m_symbolSize, color);
	}

	Draw(chart, false);
	chartViewer->Chart = chart;
	chartViewer->ImageMap = chart->getHTMLImageMap("clickable", "", "X = {x}, Y = {value}'");
}


void WinformProject::ShapeChart::DrawTrafficPhase(WinChartViewer^ chartViewer, String^ title)
{
	int plotAreaWidth = chartViewer->Size.Width - 130;
	int plotAreaHeight = chartViewer->Size.Height - 150;
	XYChart^ chart = CreateShapeChartProperty(title, chartViewer->Size.Width, chartViewer->Size.Height, 80, 80, plotAreaWidth, plotAreaHeight);

	switch (m_shape->m_nShapeType)
	{
	case SHPT_POINT:		//point drawing
		// not support
		break;

	case SHPT_ARC:			//arc drawing
		// ���������� ������ŭ ���鼭 �׸���.
		for (int i = 0; i < m_shape->m_nRecords; ++i)
		{
			// The (x, y) data for the first line
			array<double>^ dataX = gcnew array<double>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
			array<double>^ dataY = gcnew array<double>(m_shape->m_pSHPPolyObjects[i].nNumPoints);

			// ȭ�鿡 �׸� ����Ʈ�� �Ҵ��ϰ�..
			array<System::Drawing::Point>^ arrSrcPoint = gcnew array<System::Drawing::Point>(m_shape->m_pSHPPolyObjects[i].nNumPoints);
			for (int j = 0; j < m_shape->m_pSHPPolyObjects[i].nNumPoints; ++j)
			{
				dataX[j] = m_shape->m_pSHPPolyObjects[i].arrPoints[j].x;
				dataY[j] = m_shape->m_pSHPPolyObjects[i].arrPoints[j].y;
			}
			
			// �ش� ��ũ�� ���������� red, �ƴϸ� lightgreen
			int colorInt = (m_shape->m_SHPProperties[i]->IsClose) ? ColorToInt(Color::Red) : ColorToInt(Color::LightGreen);
			LineLayer^ layer = chart->addLineLayer(dataY, colorInt, "" + i);
			layer->setXData(dataX);
			layer->setLineWidth(m_shapeLineWidth);
		}
		break;

	case SHPT_POLYGON:		//polygon drawing
		// not support
		break;

	case SHPT_MULTIPOINT:	//multipoint drawing
		// not support
		break;
	}
	chartViewer->Chart = chart;
	chartViewer->ImageMap = chart->getHTMLImageMap("clickable", "", "title='[{dataSetName}]: {x}/{value}'");
}


void WinformProject::ShapeChart::Draw(WinChartViewer^ chartViewer, String^ title)
{
	DisplayOptions options;
	WinformProject::ShapeChart::Draw(chartViewer, title, options);
}


void WinformProject::ShapeChart::Draw(WinChartViewer^ chartViewer, String^ title, DisplayOptions options) {
	int plotAreaWidth = chartViewer->Size.Width - 130;
	int plotAreaHeight = chartViewer->Size.Height - 150;
	XYChart^ chart = CreateShapeChartProperty(title, chartViewer->Size.Width, chartViewer->Size.Height, 80, 80, plotAreaWidth, plotAreaHeight);
	chart->setClipping();

	// show links
	if (options.Link) {
		Draw(chart, true);
	}
	// zoom ratio
	double zoomTo = ((double)Math::Round(Math::Min(chartViewer->ViewPortWidth, chartViewer->ViewPortHeight) * 100)) / 100;
	int minSymbolSize = 10;
	//int maxSymbolSize = this->m_symbolSize;
	//int maxSymbolSize = this->m_symbolSize/2;
	int maxSymbolSize = 10;
	int sizePeriod = maxSymbolSize - minSymbolSize;
	int symbolSize = 0;
	double zoom1 = (zoomTo * 100);
	if (zoom1 == 100) {
		symbolSize = maxSymbolSize;
	}
	else if (zoom1 <= 100) {
		symbolSize = minSymbolSize;
	}
	else {
		symbolSize = maxSymbolSize;
/*
		double a = (100 - zoom1 + 1);
		a = a * a;
		a = a / 100;
		a = maxSymbolSize - a / sizePeriod;
		symbolSize = Math::Round(a);
*/
	}
	//symbolSize = symbolSize / zoomTo;
	symbolSize = symbolSize;

	Debug::WriteLine(String::Format("zommTo={0} symbolSize={1} > fixedSymbolSize={2}", zoomTo, this->m_symbolSize, symbolSize));

	// show nodes
	if (options.Node) {
		for each(KeyValuePair<String^, ShapeNode^>^ item in m_shape->m_SHPNodes)
		{
			ShapeNode^ node = item->Value;
			array<double>^ arrX = { node->Location.x };
			array<double>^ arrY = { node->Location.y };
			ShapeChartAttribute^ att = gcnew ShapeChartAttribute(AttributeType::Node, node->ID);
			att->SetAttribute("CONNETED_LINK_COUNT", node->ConnectedLinkIndexes->Length);
			String^ datasetName = att->GetAttributeToString();
			array<String^>^ arrLabel = { datasetName };
			Layer^ layer = chart->addScatterLayer(arrX, arrY, node->ID, Chart::CircleShape, symbolSize, ColorToInt(Color::CadetBlue));
			layer->addExtraField(arrLabel);
			if (options.NodeID) {
				arrLabel[0] = node->ID;
				layer->addExtraField(arrLabel);
				layer->setDataLabelFormat("{field1}");
				//layer->setDataLabelStyle("Arial Bold", 8 / zoomTo);
				layer->setDataLabelStyle("Arial Bold", 10);
				layer->getHTMLImageMap("clickable", "x={x}&xLabel={xLabel}&dataSet={dataSet}&dataSetName={dataSetName}&value={value}&field0={field0}");
			}
		}
	}

	chartViewer->syncDateAxisWithViewPort("x", chart->xAxis());
	chartViewer->syncDateAxisWithViewPort("y", chart->yAxis());
	chartViewer->Chart = chart;
	chartViewer->ImageMap = chart->getHTMLImageMap("clickable", "x={x}&xLabel={xLabel}&dataSet={dataSet}&dataSetName={dataSetName}&value={value}&field0={field0}");
}


void WinformProject::ShapeChart::Draw(WinChartViewer^ chartViewer, WinViewPortControl^ vpc, String^ title)
{
	XYChart^ chart = gcnew XYChart(vpc->Size.Width, vpc->Size.Height);
	chart->setPlotArea(0, 0, chart->getWidth() - 1, chart->getHeight() - 1, -1, -1, 0xff0000, Chart::Transparent, Chart::Transparent);
	// The x and y axis scales reflect the full range of the view port
	chart->xAxis()->setDateScale(chartViewer->getValueAtViewPort("x", 0), chartViewer->getValueAtViewPort("x", 1), Chart::NoValue);
	chart->yAxis()->setDateScale(chartViewer->getValueAtViewPort("y", 0), chartViewer->getValueAtViewPort("y", 1), Chart::NoValue);
	Draw(chart, true);
	vpc->Chart = chart;
}

// get chart property 
XYChart^ WinformProject::ShapeChart::CreateShapeChartProperty(String^ title, int chartWidth, int chartHeight, int plotAreaX, int plotAreaY, int plotAreaWidth, int plotAreaHeight)
{
	//�ٱ���
	String^ sUiLang = CultureInfo::CurrentUICulture->Name;
	Debug::WriteLine("========CreateShapeChartProperty===>sUiLang:" + sUiLang);
	String^ sLongitude = "Longitude";//�浵
	String^ sLatitude = "Latitude";//����
	if (sUiLang->Equals("ko-KR")) {
		sLongitude = "�浵";//�浵
		sLatitude = "����";//����
	}

	XYChart^ chart = gcnew XYChart(chartWidth, chartHeight);
	chart->setPlotArea(plotAreaX, plotAreaY, plotAreaWidth, plotAreaHeight, 0xffffff, -1, 0xeeeeee, 0xeeeeee, -1);
	chart->addTitle(title, "Times New Roman Bold", 18);

	chart->xAxis()->setTitle(sLongitude, "Arial Bold", 12);
	chart->xAxis()->setWidth(3);
	chart->xAxis()->setTickLength(10, 0);

	chart->yAxis()->setTitle(sLatitude, "Arial Bold", 12);
	chart->yAxis()->setWidth(3);
	chart->xAxis()->setTickLength(10, 0);
	
	return chart;
}
