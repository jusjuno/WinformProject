#pragma once
#include "ShapeNode.h"

using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// link peorperty
/// </summary>
[Serializable]
public ref class ShapeProperty
{
public:
	// Proerty type(from dbf file)
	enum class PropertyType { LINK_ID, COLOUR, LENGTH, TYPE };
public:
	ShapeProperty() {
		Properties = gcnew Dictionary<String^, Object^>();
		Nodes = gcnew array<ShapeNode^>(2); // 무조건 링크는 노드가 2개임
		IsBidirectional = true;
		IsClose = false;
		POICount = 0;
		EnvSensRate = 0;
		DailyTrafficVolume = 0;
		Time = 0;
	}
private:
	// LINK_ID, COLOUR, LENGHT
	Dictionary<String^, Object^>^ Properties;
public:
	// 2 Nodes(start, end)
	array<ShapeNode^>^ Nodes;
	// Is bidirectional
	bool IsBidirectional;
	// Is close link
	bool IsClose;
	// number of POI
	int POICount;
	// Environment sensitive rate
	double EnvSensRate;
	// Daily traffic volume
	int DailyTrafficVolume;
	// 소요시간(hour)
	double Time;
public:
	// Link ID
	property String^ ID {
		String^ get() {
			return GetProperty(PropertyType::LINK_ID);
		}
	}

	// Length
	property double Length {
		double get() {
			String^ len = GetProperty(PropertyType::LENGTH);
			double result = 0;
			Double::TryParse(len, result);
			return result;
		}
	}

	// type
	property int TYPE {
		int get() {
			String^ type = GetProperty(PropertyType::TYPE);
			int result = 0;
			Int32::TryParse(type, result);
			return result;
		}
	}

	String^ GetProperty(PropertyType type) {
		return GetProperty(type.ToString());
	}

	String^ GetProperty(String^ type) {
		if (Properties->ContainsKey(type)) {
			return Properties[type]->ToString();
		}
		return "";
	}

	void SetProperty(String^ key, Object^ value) {
		if (Properties->ContainsKey(key)) {
			Properties[key] = value;
		}
		else {
			Properties->Add(key, value);
		}
	}
public:
	ShapeProperty^ Clone() {
		ShapeProperty^ obj = gcnew ShapeProperty();
		obj->Properties = this->Properties;
		obj->Nodes = this->Nodes;
		obj->IsBidirectional = this->IsBidirectional;
		obj->IsClose = this->IsClose;
		obj->POICount = this->POICount;
		obj->EnvSensRate = this->EnvSensRate;
		obj->DailyTrafficVolume = this->DailyTrafficVolume;
		obj->Time = this->Time;
		return obj;
	}
};