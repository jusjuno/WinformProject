#pragma once
#include "MBR.h"
#include "GeoPoint.h"

using namespace System;
using namespace System::Drawing;

/// <summary>
/// poly object
/// </summary>
[Serializable]
public value struct PolyObject
{
	MBR					MBR;
	int					nNumParts;
	int					nNumPoints;
	array<int>^			arrParts;
	array<GeoPoint>^	arrPoints;
};