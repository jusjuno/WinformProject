#pragma once
#include "ComponentInfo.h"

using namespace System;

/// <summary>
/// 트래픽 시나리오
/// </summary>
[Serializable]
public ref class TrafficScenario {
public:
	//TrafficScenario(int no, String^ sourceName, int sourceIndex, String^ recurrencePeriodName, int recurrencePeriodIndex, int sample, array<ComponentInfo>^ components) {
	TrafficScenario(int no, String ^ sourceName, int sourceIndex, String ^ recurrencePeriodName, 
		int recurrencePeriodIndex, int sample, array<ComponentInfo> ^ components, int odIndex) 
	{
		this->m_no = no;
		this->m_sourceName = sourceName;
		this->m_sourceIndex = sourceIndex;
		this->m_recurrencePeriodName = recurrencePeriodName;
		this->m_recurrencePeriodIndex = recurrencePeriodIndex;
		this->m_sample = sample;
		this->m_components = components;

		this->m_odIndex = odIndex;
	}
private:
	int				m_no;
	String^			m_sourceName;
	int				m_sourceIndex;
	String^			m_recurrencePeriodName;
	int				m_recurrencePeriodIndex;
	int				m_sample;
	array<ComponentInfo>^ m_components;

	int				m_odIndex;

public:
	// 지진강도 소스명
	property String^ SourceName {
		String^ get() {
			return this->m_sourceName;
		}
	}
	// 지진강도 소스 인덱스
	property int SourceIndex {
		int get() {
			return this->m_sourceIndex;
		}
	}
	// 지진 재현주기명
	property String^ RecurrencePeriodName {
		String^ get() {
			return this->m_recurrencePeriodName;
		}
	}
	// 지진 재현주기 인덱스 
	property int RecurrencePeriodIndex {
		int get() {
			return this->m_recurrencePeriodIndex;
		}
	}
	// Monte cario sample
	property int Sample {
		int get() {
			return this->m_sample;;
		}
	}
	// 컴포넌트 손상 정보
	property array<ComponentInfo>^ Components {
		array<ComponentInfo>^ get() {
			return this->m_components;
		}
	}

	// OD zone 정보
	property int ODIndex {
		int get() {
			return this->m_odIndex;
		}
	}




	// traffic scenario key
	// source index = seismic source index
	// recurrence period index = recurrence period index
	// sample = monte cario value(ex: value(2) = 1~2)
/*
	property String^ TrafficScenarioKey {
		String^ get() {
			return String::Format("{0}{1}{2}", this->m_sourceIndex, this->m_recurrencePeriodIndex, this->m_sample);
		}
	}
*/
	property String^ TrafficScenarioKey {
		String^ get() {
			return String::Format("{0}{1}{2}{3}", this->m_sourceIndex, this->m_recurrencePeriodIndex, this->m_sample, this->m_odIndex);
		}
	}
	// traffic scenario number
	property int TrafficScenarioNo {
		int get() {
			return this->m_no;
		}
	}
public:
	// 해당 시나리오에 damageState별로 closed된 link가 있는지 확인 
	bool IsContainClosedLink(int damageState) {
		for each (ComponentInfo^ component in m_components)
		{
			// 최대 damage state가 현재 시나리오의 damage state보다 큰 component만 설정
			if (component->MaxDamageState >= damageState) {
				return true;
			}
		}
		return false;
	}
	// damageState별로 closed된 link가 속한 components index를 가져온다
	array<int>^ GetClosedLinkIndexes(int damageState) {
		array<int>^ result = gcnew array<int>(0);
		int length = m_components->Length;
		for (int i = 0; i < length; i++)
		{
			ComponentInfo^ component = m_components[i];
			if (component->MaxDamageState >= damageState) {
				Array::Resize(result, result->Length + 1);
				result[result->Length - 1] = i;
			}
		}
		return result;
	}
};