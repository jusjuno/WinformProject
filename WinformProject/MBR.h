#pragma once
using namespace System;

/// <summary>
/// minimum bounding rectangle
/// A series of geometric shapes enclosed by its minimum bounding rectangle.
/// </summary>
[Serializable]
public value struct MBR
{
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
};