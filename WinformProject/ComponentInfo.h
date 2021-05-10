#pragma once
using namespace System;

/// <summary>
/// ������Ʈ�� ����
/// </summary>
[Serializable]
public value struct ComponentInfo {
public:
	// ���ذ� �߻�(threshold �̻�)�� ������Ʈ�� �ִ� damage state(������ ����)
	// ��: 2 = damage state2�� damage state1�� ���ذ� �߻��� �ɷ� �� �� ����
	int				MaxDamageState;
	// �ִ� ���� Ȯ��
	double			MaxDamageProbability;
	// ������Ʈ ���̵�
	String^			ComponentID;
	// classID
	String^			ClassID;
	// ������Ʈ ��ġ X
	double			ComponentX;
	// ������Ʈ ��ġ Y
	double			ComponentY;
	// ������Ʈ�� ��ġ�� ��ũ ���̵�
	String^			LinkID;
};