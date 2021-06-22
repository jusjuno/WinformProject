#pragma once
#include "Shape.h"
#include "TrafficScenario.h"
#include "ResultDataSet.h"
#include "OutputSummary.h"
#include "Zone.h"
#include "FragilityDataSet.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;

[Serializable]
public ref class ProjectDataSet
{
public protected:
	ProjectDataSet()
	{
		this->m_componentClasses = gcnew DataTable();
		this->m_networkCompnents = gcnew DataTable();
		this->m_fragParams = gcnew DataTable();
		this->m_soilAmps = gcnew DataTable();
		this->m_seismicSources = gcnew DataTable();
		this->m_seismicSourceDictionary = gcnew Dictionary<String^, DataTable^>();
		this->m_seismicSourceContentDictionary = gcnew Dictionary<String^, DataTable^>();
		this->m_trafficCarryingParams = gcnew DataTable();
		this->m_repairCostRatioParams = gcnew DataTable();
		this->m_trafficScenarioSamples = gcnew array<String^>(0);
		this->m_isSameAllTrafficCarryingParam = true;
		this->m_isSameAllRepairCostRatioParam = true;
		this->m_isGeneratedMonteCario = false;
		this->m_isGeneratedTrafficScenarios = false;
		this->m_isRunTrafficSimulation = false;
		this->m_monteCarioCount = 0;
		this->m_poiConnectivities = gcnew DataTable();
		this->m_poiConnectivityZones = gcnew DataTable();
		this->m_environments = gcnew DataTable();
		this->m_trafficScenarioIndexDictionary = gcnew Dictionary<String^, int>();
		this->m_NeXTAOutputSummaryDictionary = gcnew Dictionary<String^, OutputSummary^>();

		this->m_isDefaultODZoneParam = true;
		this->m_isDefaultInputDemandMetaParam = true;
		this->m_odZoneParams = gcnew DataTable();
		this->m_inputDemandMetaParams = gcnew DataTable();

		this->m_linkTypes = gcnew DataTable();
		this->m_nodeControlTypes = gcnew DataTable();


		this->m_resultFilePath; // NEXTA�ؼ� ��� ���� ���
		this->m_unistResultFilePath; // UNIST�ؼ� ��� ���� ���


		this->m_beforeRehabStructureCost = gcnew Dictionary<String^, DataTable^>(); 

		this->m_BeforeComponentScenarios = gcnew Dictionary<String^, DataTable^>(); 

		this->m_penaltyCost;
		this->m_valueOfTime;
		this->m_trafficFactor1;
		this->m_trafficFactor2;


		/*this->m_indiceDictionaryECO = gcnew Dictionary<String^, DataTable^>();
		this->m_indiceDictionaryCON = gcnew Dictionary<String^, DataTable^>();
		this->m_indiceDictionaryENV = gcnew Dictionary<String^, DataTable^>();*/


		//array<Zone>^ m_zoneGroupData;
		//DataTable^ m_zoneGroupProperties;

		this->m_zoneGroupData = gcnew array<Zone>(10);
		this->m_zoneGroupProperties = gcnew DataTable();


		this->m_trafficVolumeStatus = gcnew Dictionary<String^, array<String^>^>(); // �ó������� UNIST ��� ����

		this->m_FragilityDataSetDictionary = gcnew Dictionary<String^, FragilityDataSet^>();//ComponentID, FragilityDataSet
		this->m_BridgeList = gcnew DataTable();
		this->m_FragilityCompDict = gcnew Dictionary<String^, String^>();//Bridge List Dictionary

	}

public protected:	
	String^								m_projectName; // project name
	String^								m_saveFilename; // saved file name
	String^								m_shapeFilePath; // shape file(.shp) file path
	String^								m_classFilePath; // component classes file path
	String^                             m_listFilePath; // List file path
	String^								m_networkFilePath; // networkt of component file path
	String^								m_fragParamFilePath; // fragility curve parameter file path
	String^								m_soilAmpFilePath; // soil amplification factor file path

	String^								m_resultFilePath; // NEXTA�ؼ��� ���� �������ػ��� �� �����ؼ� ������� ��� 
	String^								m_unistResultFilePath; // UNIST�ؼ��� ���� �������ػ��� �� �����ؼ� ������� ��� 

	WinformProject::Shape^				m_shape; // shape ���� Ŭ����
	DataTable^							m_componentClasses; // 
	DataTable^							m_networkCompnents;
	DataTable^							m_fragParams;
	DataTable^							m_soilAmps;
	DataTable^							m_trafficCarryingParams;
	DataTable^							m_repairCostRatioParams;
	DataTable^							m_poiConnectivities;
	DataTable^							m_poiConnectivityZones;
	DataTable^							m_environments;

	DataTable^							m_nodeControlTypes;
	DataTable^							m_linkTypes;

	DataTable^							m_seismicSources;
	Dictionary<String^, DataTable^>^	m_seismicSourceDictionary;
	Dictionary<String^, DataTable^>^    m_seismicSourceContentDictionary;//���Ϻ� ������ ���� ����

	array<String^>^						m_intensityMeasureData;
	array<String^>^						m_recurrencePeriodData;
	array<String^>^						m_damageStateData;
	array<String^>^						m_trafficScenarioSamples;

	array<TrafficScenario^>^			m_trafficScenarios;
	Dictionary<String^, int>^			m_trafficScenarioIndexDictionary;

	Dictionary<String^, OutputSummary^>^	m_NeXTAOutputSummaryDictionary; // NEXTA output summary ����
	Dictionary<String^, OutputSummary^>^	m_UnistOutputSummaryDictionary; // UNIST output summary ����

	Dictionary<String^, DataTable^>^	m_beforeRehabStructureCost; // ���������� �������� �Ը�

	Dictionary<String^, DataTable^>^	m_BeforeComponentScenarios; // ���������� �����ó������� ���� ���νü��� ���ص�� ����



	/*Dictionary<String^, DataTable^>^		m_indiceDictionaryECO;
	Dictionary<String^, DataTable^>^		m_indiceDictionaryCON;
	Dictionary<String^, DataTable^>^		m_indiceDictionaryENV;*/

	//DataTable^								m_zoneGroupProperties;


	int									m_monteCarioCount;

	// outputSummary.csv�� OD zone������ ��Ī�Ͽ� �����Ǹ�
	// ���� ���ο� outputSummary.csv�� ������ ���� scenario ��ȣ�� ������ �α�����
	// ������ȣ�� ��ȣ���߰��Ͽ� scenario ��ȣ�� �����ϰ� ��
	// OD���� �ϳ��� �ó���������(�����ҽ�����*�����ֱⰳ��*���ð���)��ŭ �����ǹǷ�
	// �ó�������ȣ�� (�Ѱ���)/(OD����) ��ŭ �����ϴ� ������ ���� �� 		   			 		  		  
	//int									m_jumpScenarioNum = 0;

	bool								m_isGeneratedMonteCario;
	bool								m_isGeneratedTrafficScenarios;
	bool								m_isRunTrafficSimulation; // NeXTA
	bool								m_isSameAllTrafficCarryingParam;
	bool								m_isSameAllRepairCostRatioParam;

	bool								m_isDefaultODZoneParam;
	bool								m_isDefaultInputDemandMetaParam;
	DataTable^							m_odZoneParams;
	DataTable^							m_inputDemandMetaParams;

	ResultDataSet^						m_resultData;

	double								m_penaltyCost;
	double								m_valueOfTime;
	double								m_trafficFactor1;
	double								m_trafficFactor2;

	bool								m_odDefaultIndex;

	//bool								m_isGeneratedZoneProperties;

	array<Zone>^						m_zoneGroupData;
	DataTable^							m_zoneGroupProperties;

	String^ m_runExeName; // ��������[NEXTA, UNIST]: �ֱٽ������� ���� ����
	String^ m_uiLang; // ȭ�鿡�� �ٱ��� ����[en-US, ko-KR]


	Dictionary<String^, array<String^>^>^ m_trafficVolumeStatus; //Unist ����� �а� ����

	Dictionary<String^, FragilityDataSet^>^ m_FragilityDataSetDictionary;
	DataTable^                              m_BridgeList;
	Dictionary<String^, String^>^           m_FragilityCompDict;
};

