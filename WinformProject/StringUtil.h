#pragma once
using namespace System;

/// <summary>
/// String util class
/// </summary>
public class StringUtil {
public:

	// get decimal string format
	static String^ DecimalFormat(int point, double value) {
		return String::Format("{0:F" + point + "}", Double::IsNaN(value) ? 0 : value);
	}

	// get decimal string format
	static String^ DecimalFormatWithComma(double value) {
		return String::Format("{0:#,###}", Double::IsNaN(value) ? 0 : value);
	}

	//nullToString
	static String^ nullToString(Object^ value1, String^ value2) {
		if (value1 == nullptr || value1->ToString()->Equals("")) {
			return value2;
		}
		else {
			return value1->ToString();
		}
	}
};