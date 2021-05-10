#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace WinformProject {
	public enum class AttributeType { Link, Node, Component };
	/// <summary>
	/// Shape chart attribute(hotspot) class
	/// Chart
	/// </summary>}
	ref class ShapeChartAttribute
	{
	private:
		AttributeType			m_type;
		String^					m_id;
		int						m_connectedLinkCount;

		Dictionary<String^, Object^>^ m_attributes;
	public:
		property AttributeType Type {
			AttributeType get() {
				return this->m_type;
			}
			void set(AttributeType value) {
				this->m_type = value;
			}
		}
		property String^ ID {
			String^ get() {
				return this->m_id;
			}
			void set(String^ value) {
				this->m_id = value;
			}
		}
		property int ConnectedLinkCount {
			int get() {
				return this->m_connectedLinkCount;
			}
			void set(int value) {
				this->m_connectedLinkCount = value;
			}
		}
		property Dictionary<String^, Object^>^ Attributes {
			Dictionary<String^, Object^>^ get() {
				return this->m_attributes;
			}
		}
	public:
		ShapeChartAttribute(AttributeType type) {
			this->m_type = type;
			this->m_id = "0";
			this->m_connectedLinkCount = 0;
			this->m_attributes = gcnew Dictionary<String^, Object^>();
		}
		ShapeChartAttribute(AttributeType type, String^ id) {
			this->m_type = type;
			this->m_id = id;
			this->m_connectedLinkCount = 0;
			this->m_attributes = gcnew Dictionary<String^, Object^>();
		}
		// set attribute
		void SetAttribute(String^ key, Object^ value) {
			if (this->m_attributes->ContainsKey(key)) {
				this->m_attributes[key] = value;
			}
			else {
				this->m_attributes->Add(key, value);
			}
		}
		// get string attribute
		// ±¸ºÐÀÚ = ;
		// key=value
		String^ GetAttributeToString() {
			String^ attributesString = String::Format("TYPE={0};ID={1}", m_type, m_id);
			for each (KeyValuePair<String^, Object^> pair in m_attributes)
			{
				attributesString = attributesString + String::Format(";" + pair.Key + "={0}", pair.Value);
			}
			return attributesString;
			/*String^ formatStr = String::Format("TYPE={0};ID={1}", m_type, m_id);
			switch (this->m_type)
			{
			case AttributeType::Node:
				formatStr = String::Format(formatStr + ";CONNECTED_LINK_COUNT={0}", m_connectedLinkCount);
				break;
			case AttributeType::Link:
				break;
			case AttributeType::Component:
				formatStr = String::Format(formatStr + ";X={1};Y={2}", 100.1, 200.2);
				break;
			default:
				return "";
				break;
			}
			return formatStr;*/
		}
	};
}