#pragma once
#include "ComponentInfo.h"

using namespace System;

/// <summary>
/// Ʈ���� �ó�����
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
	// �������� �ҽ���
	property String^ SourceName {
		String^ get() {
			return this->m_sourceName;
		}
	}
	// �������� �ҽ� �ε���
	property int SourceIndex {
		int get() {
			return this->m_sourceIndex;
		}
	}
	// ���� �����ֱ��
	property String^ RecurrencePeriodName {
		String^ get() {
			return this->m_recurrencePeriodName;
		}
	}
	// ���� �����ֱ� �ε��� 
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
	// ������Ʈ �ջ� ����
	property array<ComponentInfo>^ Components {
		array<ComponentInfo>^ get() {
			return this->m_components;
		}
	}

	// OD zone ����
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
	// �ش� �ó������� damageState���� closed�� link�� �ִ��� Ȯ�� 
	bool IsContainClosedLink(int damageState) {
		for each (ComponentInfo^ component in m_components)
		{
			// �ִ� damage state�� ���� �ó������� damage state���� ū component�� ����
			if (component->MaxDamageState >= damageState) {
				return true;
			}
		}
		return false;
	}
	// damageState���� closed�� link�� ���� components index�� �����´�
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