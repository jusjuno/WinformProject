#pragma once
#include "stdlib.h"
using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// 취약성분석 파일내용 
/// </summary>
[Serializable]
public ref class StructureFile
{
public:
	String^ m_Type;
	double m_Median1;
	double m_Median2;
	double m_Median3;
	double m_Median4;
	double m_Dispersion;

public:
	StructureFile() {
		this->m_Type = "";
		this->m_Median1 = 0;
		this->m_Median2 = 0;
		this->m_Median3 = 0;
		this->m_Median4 = 0;
		this->m_Dispersion = 0;
	}

public:
	property String^ Type {
		String^ get() {
			return this->m_Type;
		}
		void set(String^ value) {
			this->m_Type = value;
		}
	}

	property double Median1 {
		double get() {
			return this->m_Median1;
		}
		void set(double value) {
			this->m_Median1 = value;
		}
	}

	property double Median2 {
		double get() {
			return this->m_Median2;
		}
		void set(double value) {
			this->m_Median2 = value;
		}
	}

	property double Median3 {
		double get() {
			return this->m_Median3;
		}
		void set(double value) {
			this->m_Median3 = value;
		}
	}

	property double Median4 {
		double get() {
			return this->m_Median4;
		}
		void set(double value) {
			this->m_Median4 = value;
		}
	}

	property double Dispersion {
		double get() {
			return this->m_Dispersion;
		}
		void set(double value) {
			this->m_Dispersion = value;
		}
	}



};
