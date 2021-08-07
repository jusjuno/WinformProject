#pragma once
#include "ProjectDataSet.h"
#include "CommConst.h"
#include "OutputSummary.h"

/// <summary>
/// Project dataset binder 
/// ���α׷��� ������Ʈ�� ��� �����͸� �����ϴ� Ŭ����
/// </summary>
public ref class ProjectDataSetBinder : ProjectDataSet
{
public:
	ProjectDataSetBinder()
	{
		this->m_dataSet = gcnew ProjectDataSet();
	}
	ProjectDataSetBinder(ProjectDataSet^ dataSet)
	{
		if (dataSet == nullptr) {
			this->m_dataSet = gcnew ProjectDataSet();
		}
		else {
			this->m_dataSet = dataSet;
		}
	}
private:
	// ������Ʈ �����ͼ�
	ProjectDataSet^ m_dataSet;
public:
	// ������Ʈ �����ͼ�
	property ProjectDataSet^ DataSet {
		ProjectDataSet^ get() {
			return this->m_dataSet;
		}
	private:
		void set(ProjectDataSet^ value) {
			this->m_dataSet = value;
		}
	}

	// ������Ʈ ��
	property String^ ProjectName {
		String^ get() {
			return this->m_dataSet->m_projectName;
		}
		void set(String^ value) {
			this->m_dataSet->m_projectName = value;
		}
	}

	// �������ϸ�
	property String^ SaveFilename {
		String^ get() {
			return this->m_dataSet->m_saveFilename;
		}
		void set(String^ value) {
			this->m_dataSet->m_saveFilename = value;
		}
	}

	// shape ���� ���
	property String^ ShapeFilePath {
		String^ get() {
			return this->m_dataSet->m_shapeFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_shapeFilePath = value;
		}
	}

	// component class ���� ���
	property String^ ClassFilePath {
		String^ get() {
			return this->m_dataSet->m_classFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_classFilePath = value;
		}
	}

	// network component ���� ���
	property String^ NetworkFilePath {
		String^ get() {
			return this->m_dataSet->m_networkFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_networkFilePath = value;
		}
	}

	// fragility curve parameter ���� ���
	property String^ FragParamFilePath {
		String^ get() {
			return this->m_dataSet->m_fragParamFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_fragParamFilePath = value;
		}
	}

	// soil amplification parameter ���� ���
	property String^ SoilAmpFilePath {
		String^ get() {
			return this->m_dataSet->m_soilAmpFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_soilAmpFilePath = value;
		}
	}

	// �������ػ��� �� �����ؼ� ������� ���
	property String^ ResultFilePath {
		String^ get() {
			return this->m_dataSet->m_resultFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_resultFilePath = value;
		}
	}


	// �������ػ��� �� �����ؼ� ������� ���
	property String^ UnistResultFilePath {
		String^ get() {
			return this->m_dataSet->m_unistResultFilePath;
		}
		void set(String^ value) {
			this->m_dataSet->m_unistResultFilePath = value;
		}
	}







	// shape data
	property WinformProject::Shape^ ShapeData {
		WinformProject::Shape^ get() {
			return this->m_dataSet->m_shape;
		}
		void set(WinformProject::Shape^ value) {
			this->m_dataSet->m_shape = value;
		}
	}

	// component class define data
	property DataTable^ ComponentClassData {
		DataTable^ get() {
			return this->m_dataSet->m_componentClasses;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_componentClasses = value;
		}
	}

	// network component define data
	property DataTable^ NetworkCompnentData {
		DataTable^ get() {
			return this->m_dataSet->m_networkCompnents;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_networkCompnents = value;
		}
	}

	// fragility curve parameter define data
	property DataTable^ FragParameterData {
		DataTable^ get() {
			return this->m_dataSet->m_fragParams;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_fragParams = value;
		}
	}

	// soil amplification facor define data
	property DataTable^ SoilAmpData {
		DataTable^ get() {
			return this->m_dataSet->m_soilAmps;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_soilAmps = value;
		}
	}

	// seismic source data
	property DataTable^ SeismicSourceData {
		DataTable^ get() {
			return this->m_dataSet->m_seismicSources;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_seismicSources = value;
		}
	}

	// traffic carrying capacity - time parameter data
	property DataTable^ TrafficCarryingParamData {
		DataTable^ get() {
			return this->m_dataSet->m_trafficCarryingParams;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_trafficCarryingParams = value;
		}
	}

	// repair cost ratio parameter data
	property DataTable^ RepairCostRatioParamData {
		DataTable^ get() {
			return this->m_dataSet->m_repairCostRatioParams;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_repairCostRatioParams = value;
		}
	}

	// define OD Zone
	property DataTable^ ODZoneParamData {
		DataTable^ get() {
			return this->m_dataSet->m_odZoneParams;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_odZoneParams = value;
		}
	}

	// define input demand meta data
	property DataTable^ InputDemandMetaParamData {
		DataTable^ get() {
			return this->m_dataSet->m_inputDemandMetaParams;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_inputDemandMetaParams = value;
		}
	}

	// POI connectivity data
	property DataTable^ POIConnectivityData {
		DataTable^ get() {
			return this->m_dataSet->m_poiConnectivities;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_poiConnectivities = value;
		}
	}

	// POI connectivity zone define data
	property DataTable^ POIConnectivityZoneData {
		DataTable^ get() {
			return this->m_dataSet->m_poiConnectivityZones;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_poiConnectivityZones = value;
		}
	}

	// envirionment link data
	property DataTable^ EnvironmentData {
		DataTable^ get() {
			return this->m_dataSet->m_environments;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_environments = value;
		}
	}

	// node control type for NeXTA input
	property DataTable^ NodeControlTypes {
		DataTable^ get() {
			return this->m_dataSet->m_nodeControlTypes;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_nodeControlTypes = value;
		}
	}

	// link type for NeXTA input
	property DataTable^ LinkTypes {
		DataTable^ get() {
			return this->m_dataSet->m_linkTypes;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_linkTypes = value;
		}
	}

	// seismic source data dictionary
	// key: filename(seismic source name(column1))
	// value: detail data
	property Dictionary<String^, DataTable^>^ SeismicSourceDictionary {
		Dictionary<String^, DataTable^>^ get() {
			return this->m_dataSet->m_seismicSourceDictionary;
		}
		void set(Dictionary<String^, DataTable^>^ value) {
			this->m_dataSet->m_seismicSourceDictionary = value;
		}
	}

	// intensity measure data
	property array<String^>^ IntensityMeasureData {
		array<String^>^ get() {
			return this->m_dataSet->m_intensityMeasureData;
		}
		void set(array<String^>^ value) {
			this->m_dataSet->m_intensityMeasureData = value;
		}
	}

	// recurrence periods data
	property array<String^>^ RecurrencePeriodData {
		array<String^>^ get() {
			return this->m_dataSet->m_recurrencePeriodData;
		}
		void set(array<String^>^ value) {
			this->m_dataSet->m_recurrencePeriodData = value;
		}
	}

	// damage state data
	property array<String^>^ DamageStateData {
		array<String^>^ get() {
			return this->m_dataSet->m_damageStateData;
		}
		void set(array<String^>^ value) {
			this->m_dataSet->m_damageStateData = value;
		}
	}

	// traffic scenario sample
	// Step6 monte cario ������ ��
	property array<String^>^ TrafficScenarioSamples {
		array<String^>^ get() {
			return this->m_dataSet->m_trafficScenarioSamples;
		}
		void set(array<String^>^ value) {
			this->m_dataSet->m_trafficScenarioSamples = value;
		}
	}

	// ��ü �ó����� �� = �����ҽ� �� * ����ī���� �� * �����ֱ� ��
	property int TotalTrafficScenarioCount {
		int get() {
			//return this->m_dataSet->m_monteCarioCount * this->m_dataSet->m_seismicSources->Rows->Count * this->m_dataSet->m_recurrencePeriodData->Length;

			// this->m_dataSet->m_odZoneParams->Rows->Count == 0�� ���� OD zone�� ������ �ȵ� ���� �ǹ��ϹǷ�
			// this->m_dataSet->m_odZoneParams->Rows->Count = 1 �� �ϳ��� �߻���Ű�� ������ �ϸ�
			// OD Zone �Է�â�� ���ؼ� 1�� �̻��� OD zone�� �ԷµǸ�, �� ���� ����ϵ��� ��

			if (this->m_dataSet->m_odZoneParams->Rows->Count < 2) {
				return this->m_dataSet->m_monteCarioCount *
					this->m_dataSet->m_seismicSources->Rows->Count *
					this->m_dataSet->m_recurrencePeriodData->Length;
			}
			else {
				return this->m_dataSet->m_monteCarioCount *
					this->m_dataSet->m_seismicSources->Rows->Count *
					this->m_dataSet->m_recurrencePeriodData->Length *
					this->m_dataSet->m_odZoneParams->Rows->Count;
			}
		}
	}


	// outputSummary.csv�� OD zone������ ��Ī�Ͽ� �����Ǹ�
	// ���� ���ο� outputSummary.csv�� ������ ���� scenario ��ȣ�� ������ �α�����
	// ������ȣ�� �ó�����(��)*10 �� ���� (��, m_jumpScenarioNum = m_jumpScenarioNum + 8*10) 
	// scenario ��ȣ�� �����ϰ� ��   
/*	property int JumpScenarioNum {
		int get() {
			return this->m_dataSet->m_jumpScenarioNum;
		}
		void set(int value) {
			this->m_dataSet->m_jumpScenarioNum = value;
		}
	}
*/

	property int UnitScenarioNum {
		int get() {
			return this->m_dataSet->m_monteCarioCount *
				this->m_dataSet->m_seismicSources->Rows->Count *
				this->m_dataSet->m_recurrencePeriodData->Length;
		}
	}









	// traffic scenario phases
	// Step8 Ʈ���� �ó������� ��������� ������
	property array<TrafficScenario^>^ TrafficScenarios {
		array<TrafficScenario^>^ get() {
			return this->m_dataSet->m_trafficScenarios;
		}
		void set(array<TrafficScenario^>^ value) {
			this->m_dataSet->m_trafficScenarios = value;
			if (this->m_dataSet->m_trafficScenarioIndexDictionary == nullptr) {
				this->m_dataSet->m_trafficScenarioIndexDictionary = gcnew Dictionary<String^, int>();
			}
			// ã�� ���ϰ� index�� ����
			this->m_dataSet->m_trafficScenarioIndexDictionary->Clear();
			for (int i = 0; i < value->Length; i++)
			{
				TrafficScenario^ ts = value[i];
				this->m_dataSet->m_trafficScenarioIndexDictionary->Add(ts->TrafficScenarioKey, i);
			}
		}
	}	

	//ECO, CON, ENV ���� ������ ǥ���ϱ����� ����ð���ġ(value of Time) ���� 
	property double ValueOfTime {
		double get() {
			return this->m_dataSet->m_valueOfTime;
		}
		void set(double value) {
			this->m_dataSet->m_valueOfTime = value;
		}
	}

	//ECO, CON, ENV ���� ������ ǥ���ϱ����� �������Ⱑġ(Penalty Cost) ���� 
	property double PenaltyCost {
		double get() {
			return this->m_dataSet->m_penaltyCost;
		}
		void set(double value) {
			this->m_dataSet->m_penaltyCost = value;
		}
	}
	

	property double TrafficFactor1 {
		double get() {
			return this->m_dataSet->m_trafficFactor1;
		}
		void set(double value) {
			this->m_dataSet->m_trafficFactor1 = value;
		}
	}

	//ECO, CON, ENV ���� ������ ǥ���ϱ����� �������Ⱑġ(Penalty Cost) ���� 
	property double TrafficFactor2 {
		double get() {
			return this->m_dataSet->m_trafficFactor2;
		}
		void set(double value) {
			this->m_dataSet->m_trafficFactor2 = value;
		}
	}






	// Get traffic scenario
	// traffic scenario�� ����ϱ� ���� �Լ��� 2�� ����
	// �ϳ��� OD������ �⺻ ������ �����Ͽ� �ó����� ���� ����ϴ� �Լ�
	// �������� OD���� ���� ���� �ɶ� �̿��ϴ� �Լ�

	TrafficScenario^ GetTrafficScenario(int sourceIndex, int recurrencePeriodIndex, int sample) {
		if (this->m_dataSet->m_trafficScenarios == nullptr || this->m_dataSet->m_trafficScenarios->Length == 0) {
			return nullptr;
		}
		int odIndex = 1;
		String^ key = GetTrafficScenarioKey(sourceIndex, recurrencePeriodIndex, sample, odIndex);
		return this->m_dataSet->m_trafficScenarios[this->m_dataSet->m_trafficScenarioIndexDictionary[key]];
	}

	TrafficScenario^ GetTrafficScenario(int sourceIndex, int recurrencePeriodIndex, int sample, int odIndex) {
		if (this->m_dataSet->m_trafficScenarios == nullptr || this->m_dataSet->m_trafficScenarios->Length == 0) {
			return nullptr;
		}
		String^ key = GetTrafficScenarioKey(sourceIndex, recurrencePeriodIndex, sample, odIndex);
		return this->m_dataSet->m_trafficScenarios[this->m_dataSet->m_trafficScenarioIndexDictionary[key]];
	}

// Get traffic scenario key
	// source index = seismic source index
	// recurrence period index = recurrence period index
	// sample = monte cario value(ex: value(2) = 1~2)
/*
	String^ GetTrafficScenarioKey(int sourceIndex, int recurrencePeriodIndex, int sample) {
		return String::Format("{0}{1}{2}", sourceIndex, recurrencePeriodIndex, sample);
	}
*/
	String^ GetTrafficScenarioKey(int sourceIndex, int recurrencePeriodIndex, int sample, int odIndex) {
		return String::Format("{0}{1}{2}{3}", sourceIndex, recurrencePeriodIndex, sample, odIndex);
	}

	// Get traffic scenario number(primary key)
	// source index = seismic source index
	// recurrence period index = recurrence period index
	// sample = monte cario value(ex: value(2) = 1~2)
	// return: �ش�Ǵ� scenario number�� ����
	//  �ش�Ǵ� scenario number�� ������ -1 ����

	int GetTrafficScenarioNo(int sourceIndex, int recurrencePeriodIndex, int sample) {
		int odIndex;
		String^ key = GetTrafficScenarioKey(sourceIndex, recurrencePeriodIndex, sample,odIndex=1);
		if (this->m_dataSet->m_trafficScenarioIndexDictionary->ContainsKey(key)) {
			return this->m_dataSet->m_trafficScenarioIndexDictionary[key];
		}
		return -1;
	}

	int GetTrafficScenarioNo(int sourceIndex, int recurrencePeriodIndex, int sample, int odIndex) {
		String^ key = GetTrafficScenarioKey(sourceIndex, recurrencePeriodIndex, sample, odIndex);
		if (this->m_dataSet->m_trafficScenarioIndexDictionary->ContainsKey(key)) {
			return this->m_dataSet->m_trafficScenarioIndexDictionary[key];
		}
		return -1;
	}

	// traffic scenario�� ã�� ���� index dictionary
	// key: traffic scenario key ������ ����(sourceIndex+recurrencePeriodIndex+sample)
	// value: traffic scenario number(primary key) = TrafficScenarios array index
	property Dictionary<String^, int>^ TrafficScenarioIndexDictionary {
		Dictionary<String^, int>^ get() {
			return this->m_dataSet->m_trafficScenarioIndexDictionary;
		}
	}

	// NeXTA output data
	// key: scenarios no + damage state: (key(0)=����ó����� ������)
	// value: secenarios output data
	property Dictionary<String^, OutputSummary^>^ NeXTAOutputSummaryDictionary {
		Dictionary<String^, OutputSummary^>^ get() {
			return this->m_dataSet->m_NeXTAOutputSummaryDictionary;
		}
		void set(Dictionary<String^, OutputSummary^>^ value) {
			this->m_dataSet->m_NeXTAOutputSummaryDictionary = value;
		}
	}


	// Unist output data
	// key: scenarios no + damage state: (key(0)=����ó����� ������)
	// value: secenarios output data
	property Dictionary<String^, OutputSummary^>^ UnistOutputSummaryDictionary {
		Dictionary<String^, OutputSummary^>^ get() {
			return this->m_dataSet->m_UnistOutputSummaryDictionary;
		}
		void set(Dictionary<String^, OutputSummary^>^ value) {
			this->m_dataSet->m_UnistOutputSummaryDictionary = value;
		}
	}

	// Number of monte cario sample
	property int MonteCarioCount {
		int get() {
			return this->m_dataSet->m_monteCarioCount;
		}
		void set(int value) {
			this->m_dataSet->m_monteCarioCount = value;
			this->m_dataSet->m_trafficScenarioSamples = gcnew array<String^>(value);
			for (int i = 0; i < value; i++)
			{
				this->m_dataSet->m_trafficScenarioSamples[i] = (i + 1).ToString();
			}
		}
	}

	// This is a flag, that monte cario data has been generate.
	property bool IsGeneratedMonteCario {
		bool get() {
			return this->m_dataSet->m_isGeneratedMonteCario;
		}
		void set(bool value) {
			this->m_dataSet->m_isGeneratedMonteCario = value;
		}
	}

	// This is a flag, that traffic scenarios has been generate.
	property bool IsGeneratedTrafficScenarios {
		bool get() {
			return this->m_dataSet->m_isGeneratedTrafficScenarios;
		}
		void set(bool value) {
			this->m_dataSet->m_isGeneratedTrafficScenarios = value;
		}
	}

	// This is a flag, that traffic simulation has been run.
	property bool IsRunTrafficSimulation {
		bool get() {
			return this->m_dataSet->m_isRunTrafficSimulation;
		}
		void set(bool value) {
			this->m_dataSet->m_isRunTrafficSimulation = value;
		}
	}
	
	// This is a flag, that all traffic carrying parameter is same.
	property bool IsSameAllTrafficCarryingParam {
		bool get() {
			return this->m_dataSet->m_isSameAllTrafficCarryingParam;
		}
		void set(bool value) {
			this->m_dataSet->m_isSameAllTrafficCarryingParam = value;
			// if, the flag is true, set default value
			if (value) {
				this->m_dataSet->m_trafficCarryingParams->Clear();
				for each (DataRow^ row in this->m_dataSet->m_componentClasses->Rows)
				{
					DataRow^ newRow = this->m_dataSet->m_trafficCarryingParams->NewRow();
					String^ classID = row[CommConst::GRID_COMP_CLASS_COL1]->ToString();
					newRow[CommConst::GRID_TRAFFIC_CARRYING_COL1] = classID;
					newRow[CommConst::GRID_TRAFFIC_CARRYING_COL2] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1;
					newRow[CommConst::GRID_TRAFFIC_CARRYING_COL3] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2;
					newRow[CommConst::GRID_TRAFFIC_CARRYING_COL4] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3;
					newRow[CommConst::GRID_TRAFFIC_CARRYING_COL5] = CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4;
					this->m_dataSet->m_trafficCarryingParams->Rows->Add(newRow);
				}
			}
		}
	}

	// This is a flag, that all repair cost ratio parameter is same.
	property bool IsSameAllRepairCostRatioParam {
		bool get() {
			return this->m_dataSet->m_isSameAllRepairCostRatioParam;
		}
		void set(bool value) {
			this->m_dataSet->m_isSameAllRepairCostRatioParam = value;
			// if, the flag is true, set default value
			if (value) {
				this->m_dataSet->m_repairCostRatioParams->Clear();
				for each (DataRow^ row in this->m_dataSet->m_componentClasses->Rows)
				{
					DataRow^ newRow = this->m_dataSet->m_repairCostRatioParams->NewRow();
					String^ classID = row[CommConst::GRID_COMP_CLASS_COL1]->ToString();
					newRow[CommConst::GRID_REPAIR_COST_RATIO_COL1] = classID;
					newRow[CommConst::GRID_REPAIR_COST_RATIO_COL2] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1;
					newRow[CommConst::GRID_REPAIR_COST_RATIO_COL3] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2;
					newRow[CommConst::GRID_REPAIR_COST_RATIO_COL4] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3;
					newRow[CommConst::GRID_REPAIR_COST_RATIO_COL5] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4;
					this->m_dataSet->m_repairCostRatioParams->Rows->Add(newRow);
				}
			}
		}
	}

	// This is a flag, that the OD Zone is default.
	property bool IsDefaultODZoneParam {
		bool get() {
			return this->m_dataSet->m_isDefaultODZoneParam;
		}
		void set(bool value) {
			this->m_dataSet->m_isDefaultODZoneParam = value;
			// if, the flag is true, set default value
			if (value) {
/*				this->m_dataSet->m_odZoneParams->Clear();
				DataRow^ newRow = this->m_dataSet->m_odZoneParams->NewRow();
				newRow[CommConst::GRID_OD_ZONE_COL1] = "";
				newRow[CommConst::GRID_OD_ZONE_COL2] = "";
				newRow[CommConst::GRID_OD_ZONE_COL3] = "";
				this->m_dataSet->m_odZoneParams->Rows->Add(newRow);
*/
			}
		}
	}

	// This is a flag, that the Input_Demand_Meta_Data is default.
	property bool IsDefaultInputDemandMetaParam {
		bool get() {
			return this->m_dataSet->m_isDefaultInputDemandMetaParam;
		}
		void set(bool value) {
			this->m_dataSet->m_isDefaultInputDemandMetaParam = value;
			// if, the flag is true, set default value
			if (value) {

				this->m_dataSet->m_inputDemandMetaParams->Clear();
				DataRow^ newRow = this->m_dataSet->m_inputDemandMetaParams->NewRow();
				newRow[CommConst::GRID_INPUT_DEMAND_META_COL1] = CommConst::DEFAULT_START_TIME;
				newRow[CommConst::GRID_INPUT_DEMAND_META_COL2] = CommConst::DEFAULT_END_TIME;
				this->m_dataSet->m_inputDemandMetaParams->Rows->Add(newRow);				
			}
			else {
				this->m_dataSet->m_inputDemandMetaParams->Clear();
				DataRow^ newRow = this->m_dataSet->m_inputDemandMetaParams->NewRow();
				newRow[CommConst::GRID_INPUT_DEMAND_META_COL1] = "";
				newRow[CommConst::GRID_INPUT_DEMAND_META_COL2] = "";
				this->m_dataSet->m_inputDemandMetaParams->Rows->Add(newRow);

			}
		}
	}

	   	  
	/// result
	// project result dataset
	property ResultDataSet^ ResultData {
		ResultDataSet^ get() {
			return this->m_dataSet->m_resultData;
		}
		void set(ResultDataSet^ value) {
			this->m_dataSet->m_resultData = value;
		}
	}


	// NeXTA output data
	// key: scenarios no 
	// value: �������� �Ը�
	property Dictionary<String^, DataTable^>^ BeforeRehabStructureCost {
		Dictionary<String^, DataTable^>^ get() {
			return this->m_dataSet->m_beforeRehabStructureCost;
		}
		void set(Dictionary<String^, DataTable^>^ value) {
			this->m_dataSet->m_beforeRehabStructureCost = value;
		}
	}



	// ���Ἲ���� ���� ���θ������� ����ó������� ����Ǵ� Ư������(���뼱 ��ü����)
	property array<Zone>^ ZoneGroupData {
		array<Zone>^ get() {
			return this->m_dataSet->m_zoneGroupData;
		}
		void set(array<Zone>^ value) {
			this->m_dataSet->m_zoneGroupData = value;
		}
	}


	// ���Ἲ���� ���� ���θ������� ����ó������� ������� Ư�� ����(�ѱ�������, ������ȣ, ��������)
	property DataTable^ ZoneGroupProperties {
		DataTable^ get() {
			return this->m_dataSet->m_zoneGroupProperties;
		}
		void set(DataTable^ value) {
			this->m_dataSet->m_zoneGroupProperties = value;
		}
	}


	// ���������� �����ó������� ���� ���νü��� ���ص�� ����
	property Dictionary<String^, DataTable^>^ BeforeComponentScenarios {
		Dictionary<String^, DataTable^>^ get() {
			return this->m_dataSet->m_BeforeComponentScenarios;
		}
		void set(Dictionary<String^, DataTable^>^ value) {
			this->m_dataSet->m_BeforeComponentScenarios = value;
		}
	}



	// �ֱٽ������� ����
	property String^ RunExeName {
		String^ get() {
			return this->m_dataSet->m_runExeName;
		}
		void set(String^ value) {
			this->m_dataSet->m_runExeName = value;
		}
	}


	// ȭ�鿡�� �ٱ��� ����
	property String^ UiLang {
		String^ get() {
			return this->m_dataSet->m_uiLang;
		}
		void set(String^ value) {
			this->m_dataSet->m_uiLang = value;
		}
	}



	//���Ϻ� ������ ���� ����
	property Dictionary<String^, DataTable^>^ SeismicSourceContentDictionary {
		Dictionary<String^, DataTable^>^ get() {
			return this->m_dataSet->m_seismicSourceContentDictionary;
		}
		void set(Dictionary<String^, DataTable^>^ value) {
			this->m_dataSet->m_seismicSourceContentDictionary = value;
		}
	}


	// Unist �����ؼ� ��� ����
	// key: OD��ȣ,��������ȣ,�����ֱ��ȣ,���ø���ȣ
	// value: ���뷮(�������)
	property Dictionary<String^, array<String^>^>^ TrafficVolumeStatus {
		Dictionary<String^, array<String^>^>^ get() {
			return this->m_dataSet->m_trafficVolumeStatus;
		}
		void set(Dictionary<String^, array<String^>^>^ value) {
			this->m_dataSet->m_trafficVolumeStatus = value;
		}
	}


	//Structure File dataset 
	property Dictionary<String^, StructureFile^>^ StructureFileDictionary {
		Dictionary<String^, StructureFile^>^ get() {
			return this->m_dataSet->m_structureFileDictionary;
		}
		void set(Dictionary<String^, StructureFile^>^ value) {
			this->m_dataSet->m_structureFileDictionary = value;
		}
	}


};