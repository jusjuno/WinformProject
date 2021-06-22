#pragma once
//#include "ProjectDataSetBinder.h"



using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// project result dataset
/// </summary>
[Serializable]
public ref class ResultDataSet
{
public:
	ResultDataSet(int totalTrafficScenarioCount)
	//ResultDataSet(ProjectDataSetBinder^ dataSet)
	//ResultDataSet()
	{
		//this->m_dataSet = dataSet; 
		this->m_isCalculatedFunctionality = false;
		this->m_isCalculatedAdditionalCost = false;
		this->m_isCalculatedLossfactor = false;
		this->m_isNetworkStructuralCost = false;
		//this->m_totalTrafficScenarioCount ;
		//this->m_totalTrafficScenarioCount ;
		this->m_functionalities = gcnew array<array<double>^>(totalTrafficScenarioCount);
		//this->m_additionalCosts = gcnew array<array<double>^>(this->m_totalTrafficScenarioCount);
		this->m_additionalCosts = gcnew array<array<double>^>(totalTrafficScenarioCount);
		this->m_ecoLossIndices = gcnew array<array<double>^>(totalTrafficScenarioCount);
		this->m_conLossIndices = gcnew array<array<double>^>(totalTrafficScenarioCount);
		this->m_envLossIndices = gcnew array<array<double>^>(totalTrafficScenarioCount);

		this->m_networkStructuralCosts = gcnew array<Dictionary<String^, long>^> (totalTrafficScenarioCount);

		this->m_totalTrafficScenarioCount = totalTrafficScenarioCount;

	}
private:
	bool m_isCalculatedFunctionality;
	bool m_isCalculatedAdditionalCost;
	bool m_isCalculatedLossfactor;
	bool m_isNetworkStructuralCost;

	//ProjectDataSetBinder^ m_dataSet;


	// number of damage state 
	int m_damageStateCount;

	// total number of damage state 
	int m_totalTrafficScenarioCount;
	//int m_totalTrafficScenarioCount = this->m_dataSet->TrafficVolumeStatus->Count;

	array<array<double>^>^ m_functionalities;

	array<array<double>^>^ m_additionalCosts;

	// network component cost
	// 1-array: traffic scenario number
	// 2-array: value of each component
	array<Dictionary<String^, long>^>^ m_networkStructuralCosts;

	// Economic loss indices
	// 1-array: traffic scenario number
	// 2-array: value of each damage states
	array<array<double>^>^ m_ecoLossIndices;

	// Connectivity loss indices
	// key: traffic scenario number
	// value: value of each damage states
	array<array<double>^>^ m_conLossIndices;

	// Environment loss indices
	// 1-array: traffic scenario number
	// 2-array: value of each damage states
	array<array<double>^>^ m_envLossIndices;

public:
	property bool IsCalculatedFunctionality {
		bool get() {
			return this->m_isCalculatedFunctionality;
		}
		void set(bool value) {
			this->m_isCalculatedFunctionality = value;
		}
	}

	property bool IsCalculatedAdditionalCost {
		bool get() {
			return this->m_isCalculatedAdditionalCost;
		}
		void set(bool value) {
			this->m_isCalculatedAdditionalCost = value;
		}
	}

	property bool IsCalculatedLossfactor {
		bool get() {
			return this->m_isCalculatedLossfactor;
		}
		void set(bool value) {
			this->m_isCalculatedLossfactor = value;
		}
	}

	property bool IsNetworkStructuralCost {
		bool get() {
			return this->m_isNetworkStructuralCost;
		}
		void set(bool value) {
			this->m_isNetworkStructuralCost = value;
		}
	}

	// Link Functionality(open link)
	// 1-array: traffic scenario number
	// 2-array: value of each damage states
	property array<array<double>^>^ Functionalities {
		array<array<double>^>^ get() {
			return this->m_functionalities;
		}
		void set(array<array<double>^>^ value) {
			this->m_functionalities = value;
			this->m_isCalculatedFunctionality = (value != nullptr);
		}
	}	
	
	// Additional cost(traffic cost)
	// 1-array: traffic scenario number
	// 2-array: value of each damage states
	property array<array<double>^>^ AdditionalCosts {
		array<array<double>^>^ get(){
			return this->m_additionalCosts;
		}
		void set(array<array<double>^>^ value) {
			this->m_additionalCosts = value;
			this->m_isCalculatedAdditionalCost = (value != nullptr);
		}
	}

	// Additional cost(traffic cost)
	// 1-array: traffic scenario number
	// 2-array: value of each damage states
	property array<Dictionary<String^, long>^>^ NetworkStructuralCosts {
		//this->m_networkStructuralCosts = gcnew array<Dictionary<String^, long>^>(this->m_totalTrafficScenarioCount);
		//this->m_networkStructuralCosts = ;
		void set(array<Dictionary<String^, long>^>^ value) {
			this->m_networkStructuralCosts = value;
			this->m_isNetworkStructuralCost = (value != nullptr);
		}
	}



private:
	double SumValues(array<double>^ arr) {
		double result = 0.0;
		for (int i = 0; i < arr->Length; i++)
		{
			result += arr[i];
		}
		return result;
	}
public:
	// Get traffic scenario key
	// source index = seismic source index
	// recurrence period index = recurrence period index
	// sample = monte cario value(ex: value(2) = 1~2)
	String^ GetTrafficScenarioKey(int sourceIndex, int recurrencePeriodIndex, int sample) {
		return String::Format("{0}{1}{2}", sourceIndex, recurrencePeriodIndex, sample);
	}

	// Get estimated total traffic cost
	double GetTotalTrafficCost(const int trafficScenarioNo) {
		array<double>^ values = this->m_additionalCosts[trafficScenarioNo];
		return SumValues(values);
	}

	// Get estimated total network structural cost
	double GetTotalNetworkStructuralCost(const int trafficScenarioNo) {
		double result = 0.0;
		Dictionary<String^, long>^ componentsValueDic = this->m_networkStructuralCosts[trafficScenarioNo];
		for each (KeyValuePair<String^, long>^ pair in componentsValueDic)
		{
			result += pair->Value;
		}
		return result;
	}
	
	// Get estimated component structural cost
	double GetComponentStructuralCost(const int trafficScenarioNo, String^ componentID) {
		double result = 0.0;
		Dictionary<String^, long>^ componentsValueDic = this->m_networkStructuralCosts[trafficScenarioNo];
		if (componentsValueDic->ContainsKey(componentID)) {
			result = componentsValueDic[componentID];
		}
		return result;
	}

	// Get economic loss indices by traffic scenario no
	array<double>^ GetEconomicLossIndices(const int trafficScenarioNo) {
		return this->m_ecoLossIndices[trafficScenarioNo];
	}	
	
	// Get connectivity loss indices by traffic scenario no
	array<double>^ GetConnectivityLossIndices(const int trafficScenarioNo) {
		return this->m_conLossIndices[trafficScenarioNo];
	}	
	

	// Get environment loss indices by traffic scenario no
	array<double>^ GetEnvironmentLossIndices(const int trafficScenarioNo) {
		return this->m_envLossIndices[trafficScenarioNo];
	}

	/*
	// Get total economic loss indices by traffic scenario no
	double GetTotalEconomicLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_ecoLossIndices[trafficScenarioNo];
		//return SumValues(values);
		double min = 1;
		for (int i = 0; i < values->Length; i++) {
			if (values[i] < min) { min = values[i]; }
		}
		return min;
	}
	*/

	
	// Get total economic loss indices by traffic scenario no
	// 현재상태의 도로망에대한 교통해석 결과에 해당하는 outputsummary.csv로 부터 지수값 계산을 위한 함수
	// 현재상태란 WinformProject.exe를 실행하여 생성된 outputsummary를 의미 
	double GetTotalEconomicLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_ecoLossIndices[trafficScenarioNo];
		//return SumValues(values);
		double result = 0;
		//int recoveryRef= CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 100;
		array<int>^ recoveryDays = gcnew array<int>(4);
		recoveryDays[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
		recoveryDays[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
		recoveryDays[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
		recoveryDays[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
		double temp = 0;

		int recoveryRef = 0;
		for(int i=0;i< recoveryDays->Length;i++){
			recoveryRef += recoveryDays[i];
		}

		for (int i = 0; i < values->Length; i++) {
			//if (values[i] < min) { min = values[i]; }
			temp += recoveryDays[i] * (1 - values[i]);
		}
		result = (recoveryRef - temp) / recoveryRef;

		return result;
	}
	
	// 내진보강(전) 도로망에 대한 교통해석결과에 해당하는 before_outputsummary.csv로 부터 지수값 계산을 위한 함수
	double GetTotalEconomicLossIndices(array<double>^ values) {
		//array<double>^ values = this->m_ecoLossIndices[trafficScenarioNo];
		//return SumValues(values);
		double result = 0;
		//int recoveryRef = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 100;
		array<int>^ recoveryDays = gcnew array<int>(4);
		recoveryDays[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
		recoveryDays[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
		recoveryDays[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
		recoveryDays[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
		double temp = 0;

		int recoveryRef = 0;
		for (int i = 0; i < recoveryDays->Length; i++) {
			recoveryRef += recoveryDays[i];
		}

		for (int i = 0; i < values->Length; i++) {
			//if (values[i] < min) { min = values[i]; }
			temp += recoveryDays[i] * (1 - values[i]);
		}
		result = (recoveryRef - temp) / recoveryRef;

		return result;
	}




	/*
	// Get total connectivity loss indices by traffic scenario no
	double GetTotalConnectivityLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_conLossIndices[trafficScenarioNo];
//		return SumValues(values);
		double min = 1;
		for (int i = 0; i < values->Length; i++) {
			if (values[i] < min) { min = values[i]; }
		}
		return min;
	}
	*/

	// Get total connectivity loss indices by traffic scenario no
	double GetTotalConnectivityLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_conLossIndices[trafficScenarioNo];
		//return SumValues(values);
		double result = 0;
		//int recoveryRef = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 100;
		array<int>^ recoveryDays = gcnew array<int>(4);
		recoveryDays[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
		recoveryDays[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
		recoveryDays[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
		recoveryDays[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
		double temp = 0;

		int recoveryRef = 0;
		for (int i = 0; i < recoveryDays->Length; i++) {
			recoveryRef += recoveryDays[i];
		}

		for (int i = 0; i < values->Length; i++) {
			//if (values[i] < min) { min = values[i]; }
			temp += recoveryDays[i] * (1 - values[i]);
		}
		result = (recoveryRef - temp) / recoveryRef;

		return result;
	}




	
	/*
	// Get total environment loss indices by traffic scenario no
	double GetTotalEnvironmentLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_envLossIndices[trafficScenarioNo];
//		return SumValues(values);
		double min = 1;
		for (int i = 0; i < values->Length; i++) {
			if (values[i] < min) { min = values[i]; }
		}
		return min;
	}
	*/

	// Get total environment loss indices by traffic scenario no
	double GetTotalEnvironmentLossIndices(const int trafficScenarioNo) {
		array<double>^ values = this->m_envLossIndices[trafficScenarioNo];
		//return SumValues(values);
		double result = 0;
		//int recoveryRef = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 + 100;
		array<int>^ recoveryDays = gcnew array<int>(4);
		recoveryDays[0] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
		recoveryDays[1] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
		recoveryDays[2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
		recoveryDays[3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
		double temp = 0;

		int recoveryRef = 0;
		for (int i = 0; i < recoveryDays->Length; i++) {
			recoveryRef += recoveryDays[i];
		}

		for (int i = 0; i < values->Length; i++) {
			//if (values[i] < min) { min = values[i]; }
			temp += recoveryDays[i] * (1 - values[i]);
		}
		result = (recoveryRef - temp) / recoveryRef;

		return result;
	}










	array<double>^ GetFunctionality(int trafficScenarioNo) {
		return this->m_functionalities[trafficScenarioNo];
	}	
	
	array<double>^ GetAdditionalCost(int trafficScenarioNo) {
		return this->m_additionalCosts[trafficScenarioNo];
	}

	void SetLossFactor(array<array<double>^>^ ecoLossIndices, array<array<double>^>^ conLossIndices, array<array<double>^>^ envLossIndices) {
		if (ecoLossIndices != nullptr && conLossIndices != nullptr && envLossIndices != nullptr) {
			this->m_ecoLossIndices = ecoLossIndices;
			this->m_conLossIndices = conLossIndices;
			this->m_envLossIndices = envLossIndices;
			this->IsCalculatedLossfactor = true;
		}
		else {
			this->IsCalculatedLossfactor = false;
		}
	}










};