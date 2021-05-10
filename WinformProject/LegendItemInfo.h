#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;

/// <summary>
/// geometry point
/// </summary>
[Serializable]
public value struct LegendItemInfo {
public:
	Color							color;
	Brush^							brush;
	String^							label;
	System::Drawing::Size			labelSize;
	Rectangle						rect;
	array<double>^					dataX;
	array<double>^					dataY;
	array<double>^					dataZ;
};
