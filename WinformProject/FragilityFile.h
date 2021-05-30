#pragma once
#include "stdlib.h"
using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// 취약성분석 파일내용 
/// </summary>
[Serializable]
public ref class FragilityFile
{
public:
	String^ m_FileName;
	double m_PGA;
	double m_Slight;
	double m_Moderate;
	double m_Severe;
	double m_Collapse;

public:
	FragilityFile() {
		this->m_FileName = "";
		this->m_PGA = 0;
		this->m_Slight = 0;
		this->m_Moderate = 0;
		this->m_Severe = 0;
		this->m_Collapse = 0;
	}

public:
	property String^ FileName {
		String^ get() {
			return this->m_FileName;
		}
		void set(String^ value) {
			this->m_FileName = value;
		}
	}

	property double PGA {
		double get() {
			return this->m_PGA;
		}
		void set(double value) {
			this->m_PGA = value;
		}
	}

	property double Slight {
		double get() {
			return this->m_Slight;
		}
		void set(double value) {
			this->m_Slight = value;
		}
	}

	property double Moderate {
		double get() {
			return this->m_Moderate;
		}
		void set(double value) {
			this->m_Moderate = value;
		}
	}

	property double Severe {
		double get() {
			return this->m_Severe;
		}
		void set(double value) {
			this->m_Severe = value;
		}
	}

	property double Collapse {
		double get() {
			return this->m_Collapse;
		}
		void set(double value) {
			this->m_Collapse = value;
		}
	}



};
