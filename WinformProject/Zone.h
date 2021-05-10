#pragma once
using namespace System;

/// <summary>
/// 컴포넌트의 정보
/// </summary>
[Serializable]
public value struct Zone {
public:
	// id
	String^ ID;

	// number of POI
	int POICount;

	// zone에 속한 링크 아이디
	array<String^>^	Links;
};