#pragma once
using namespace System;

/// <summary>
/// ������Ʈ�� ����
/// </summary>
[Serializable]
public value struct Zone {
public:
	// id
	String^ ID;

	// number of POI
	int POICount;

	// zone�� ���� ��ũ ���̵�
	array<String^>^	Links;
};