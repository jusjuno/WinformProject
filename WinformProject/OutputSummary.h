#pragma once
#include "stdlib.h"
using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// OutputSummary
/// </summary>
[Serializable]
public ref class OutputSummary
{
public:
	OutputSummary() {
		this->m_volumes = gcnew Dictionary<String^, double>();
		this->m_times = gcnew Dictionary<String^, double>();
		this->m_VT0 = 0;
		this->m_VT1 = 0;
		this->m_TR0 = 0;
		this->m_TR1 = 0;
	}
private:
	double m_VT0;
	double m_VT1;
	double m_TR0;
	double m_TR1;
	Dictionary<String^, double>^ m_volumes;
	Dictionary<String^, double>^ m_times;
public:
	String^		ScenarioName;
	// VT1 - VT0 + (TR0 - TR1)
	property double Total {
		double get() {
			if (VT1 < VT0) { return VT0;}
			else{ return VT1 - VT0 ;}
			//return VT1 - VT0 + (TR0 - TR1);
			//return VT1 - VT0;
		}
	}
	// VT0 = volume X time of no damaged scenario
	property double VT0 {
		double get() {
			return this->m_VT0;
		}
		void set(double value) {
			this->m_VT0 = value;
		}
	}	
	
	// VT1 = volume X time of damaged scenario
	property double VT1 {
		double get() {
			return this->m_VT1;
		}
		void set(double value) {
			this->m_VT1 = value;
		}
	}	
	
	// TR0 = cumulative_out_flow_count of no damaged scenario 
	property double TR0 {
		double get() {
			return this->m_TR0;
		}
		void set(double value) {
			this->m_TR0 = value;	
		}
	}	
	
	// TR1 = cumulative_out_flow_count of damaged scenario 
	property double TR1 {
		double get() {
			return this->m_TR1;
		}
		void set(double value) {
			this->m_TR1 = value;
		}
	}

	// <link_id, volume>
	property Dictionary<String^, double>^ Volumes {
		Dictionary<String^, double>^ get() {
			return this->m_volumes;
		}
	}

	// <link_id, time>
	property Dictionary<String^, double>^ Times {
		Dictionary<String^, double>^ get() {
			return this->m_times;
		}
	}

	property double TotalVolumes {
		double get() {
			double result = 0;
			for each (KeyValuePair<String^, double>^ pair in this->m_volumes)
			{
				result += pair->Value;
			}
			return result;
		}
	}

	property double TotalTime {
		double get() {
			double result = 0;
			for each (KeyValuePair<String^, double>^ pair in this->m_times)
			{
				result += pair->Value;
			}
			return result;
		}
	}

	void AddVolume(String^ key, double value) {
		if (!this->m_volumes->ContainsKey(key)) {
			this->m_volumes->Add(key, value);
		}
	}

	void AddTime(String^ key, double value) {
		if (!this->m_times->ContainsKey(key)) {
			this->m_times->Add(key, value);
		}
	}
};
