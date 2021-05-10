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
	// 노드 아이디
	property String^ ID {
		String^ get() {
			return this->id;
		}
		void set(String^ value) {
			this->id = value;
		}
	}
	// 노드 위치(x, y)
	property GeoPoint Location {
		GeoPoint get() {
			return this->location;
		}
		void set(GeoPoint value) {
			this->location = value;
		}
	}
	// 노드에 연결된 링크의 index(ID가 아니라 link array 의 index)
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
	// 연결 링크 index array에 추가
	// 같은 index가 있으면 무시
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