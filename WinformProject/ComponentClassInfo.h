#pragma once
#include "ShapeChartAttribute.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows;

/// <summary>
/// Component class information
/// </summary>
[Serializable]
public value struct ComponentClassInfo{
public:
	String^					name; // classID
	String^					name2; // className
	Color					color;
	int						symbol;
	array<double>^			dataX;
	array<double>^			dataY;
	array<double>^			dataZ;

	// 속성정보
	array<WinformProject::ShapeChartAttribute^>^ attributes;
};
