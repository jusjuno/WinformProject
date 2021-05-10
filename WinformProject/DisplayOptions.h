#pragma once
using namespace System;

/// <summary>
/// chart display options
/// </summary>
[Serializable]
public value struct DisplayOptions
{
	bool Link;
	bool LinkID;

	bool Node;
	bool NodeID;
};