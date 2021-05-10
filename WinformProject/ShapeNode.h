#pragma once
#include "GeoPoint.h"
using namespace System;

/// <summary>
/// node information
/// </summary>
[Serializable]
public ref class ShapeNode
{
private:
	String^ id;
	GeoPoint location;
	array<int>^ connectedLinkIndexes;
public:
	// ��� ���̵�
	property String^ ID {
		String^ get() {
			return this->id;
		}
		void set(String^ value) {
			this->id = value;
		}
	}
	// ��� ��ġ(x, y)
	property GeoPoint Location {
		GeoPoint get() {
			return this->location;
		}
		void set(GeoPoint value) {
			this->location = value;
		}
	}
	// ��忡 ����� ��ũ�� index(ID�� �ƴ϶� link array �� index)
	property array<int>^ ConnectedLinkIndexes {
		array<int>^ get() {
			return this->connectedLinkIndexes;
		}
	}
public:
	ShapeNode() {
		connectedLinkIndexes = gcnew array<int>(0);
	}
public:
	// ���� ��ũ index array�� �߰�
	// ���� index�� ������ ����
	bool AddConnectedLinkIndex(int index) {
		for each(int i in connectedLinkIndexes) {
			if (index == i) {
				return false;
			}
		}
		Array::Resize(connectedLinkIndexes, connectedLinkIndexes->Length + 1);
		connectedLinkIndexes[connectedLinkIndexes->Length - 1] = index;
		return true;
	}
};