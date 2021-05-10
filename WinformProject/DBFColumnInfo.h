#pragma once
using namespace System;

/// <summary>
/// dbf file struct information
/// </summary>
[Serializable]
public value struct DBFColumnInfo
{
	String^ Name;
	Char Type;
	int MaxLength;
	int Count;
};