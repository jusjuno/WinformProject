#pragma once
using namespace System;

/// <summary>
/// 컴포넌트의 정보
/// </summary>
[Serializable]
public value struct ComponentInfo {
public:
	// 피해가 발생(threshold 이상)된 컴포넌트의 최대 damage state(하위도 포함)
	// 예: 2 = damage state2와 damage state1이 피해가 발생한 걸로 볼 수 있음
	int				MaxDamageState;
	// 최대 피해 확률
	double			MaxDamageProbability;
	// 컴포넌트 아이디
	String^			ComponentID;
	// classID
	String^			ClassID;
	// 컴포넌트 위치 X
	double			ComponentX;
	// 컴포넌트 위치 Y
	double			ComponentY;
	// 컴포넌트가 위치한 링크 아이디
	String^			LinkID;
};