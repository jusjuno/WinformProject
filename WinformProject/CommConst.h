#pragma once
using namespace System;

[Serializable]
public value class CommConst {
public:
	// 저장할 데이터에 변경이 있을 경우 제목 뒤에 붙는 마커
	literal String^ MODIFY_MARKER = L"*";

	// define component class grid columns.
	literal String^ GRID_COMP_CLASS_COL1 = L"Class ID";
	literal String^ GRID_COMP_CLASS_COL2 = L"Description";

	// define fragility curve parameter grid columns.
	literal String^ GRID_FRAG_CURVE_PARAM_COL1 = L"Class ID";
	literal String^ GRID_FRAG_CURVE_PARAM_COL2 = L"DS1 IMm";
	literal String^ GRID_FRAG_CURVE_PARAM_COL3 = L"DS1 β";
	literal String^ GRID_FRAG_CURVE_PARAM_COL4 = L"DS2 IMm";
	literal String^ GRID_FRAG_CURVE_PARAM_COL5 = L"DS2 β";
	literal String^ GRID_FRAG_CURVE_PARAM_COL6 = L"DS3 IMm";
	literal String^ GRID_FRAG_CURVE_PARAM_COL7 = L"DS3 β";
	literal String^ GRID_FRAG_CURVE_PARAM_COL8 = L"DS4 IMm";
	literal String^ GRID_FRAG_CURVE_PARAM_COL9 = L"DS4 β";

	// define soil amplification factor grid columns.
	literal String^ GRID_SOIL_AMP_COL1 = L"NATURAL PERIOD";
	literal String^ GRID_SOIL_AMP_COL2 = L"SOIL TYPE I";
	literal String^ GRID_SOIL_AMP_COL3 = L"SOIL TYPE II";
	literal String^ GRID_SOIL_AMP_COL4 = L"SOIL TYPE III";
	literal String^ GRID_SOIL_AMP_COL5 = L"SOIL TYPE IV";
	literal String^ GRID_SOIL_AMP_COL6 = L"SOIL TYPE V";

	literal int SOIL_TYPE_COUNT = 5;
	literal int COL_NATURAL_PERIOD = 0;
	literal int COL_SOIL_TYPE_A = 1;
	literal int COL_SOIL_TYPE_B = 2;
	literal int COL_SOIL_TYPE_C = 3;
	literal int COL_SOIL_TYPE_D = 4;
	literal int COL_SOIL_TYPE_E = 5;

	// define seismic sources grid columns.
	literal String^ GRID_SEISMIC_SOURCES_LIST_COL1 = L"Name";
	literal String^ GRID_SEISMIC_SOURCES_LIST_COL2 = L"Path";

	// define seismic sources detail data grid columns.
	literal String^ GRID_SEISMIC_SOURCES_COL1 = L"X";
	literal String^ GRID_SEISMIC_SOURCES_COL2 = L"Y";
	literal String^ GRID_SEISMIC_SOURCES_COL3 = L"50";
	literal String^ GRID_SEISMIC_SOURCES_COL4 = L"100";
	literal String^ GRID_SEISMIC_SOURCES_COL5 = L"475";
	literal String^ GRID_SEISMIC_SOURCES_COL6 = L"1000";
	//literal int COUNT_SEISMIC_PERIOD = 4;

/*	literal String^ GRID_SEISMIC_SOURCES_COL3 = L"Period 1";
	literal String^ GRID_SEISMIC_SOURCES_COL4 = L"Period 2";
	literal String^ GRID_SEISMIC_SOURCES_COL5 = L"Period 3";
	literal String^ GRID_SEISMIC_SOURCES_COL6 = L"Period 4";
*/
	// define traffic carrying parameter grid columns.
	literal String^ GRID_TRAFFIC_CARRYING_COL1 = L"Class ID";
	literal String^ GRID_TRAFFIC_CARRYING_COL2 = L"Damage State 1";
	literal String^ GRID_TRAFFIC_CARRYING_COL3 = L"Damage State 2";
	literal String^ GRID_TRAFFIC_CARRYING_COL4 = L"Damage State 3";
	literal String^ GRID_TRAFFIC_CARRYING_COL5 = L"Damage State 4";

	// define repair cost ratio parameter grid columns.
	literal String^ GRID_REPAIR_COST_RATIO_COL1 = L"Class ID";
	literal String^ GRID_REPAIR_COST_RATIO_COL2 = L"Damage State 1";
	literal String^ GRID_REPAIR_COST_RATIO_COL3 = L"Damage State 2";
	literal String^ GRID_REPAIR_COST_RATIO_COL4 = L"Damage State 3";
	literal String^ GRID_REPAIR_COST_RATIO_COL5 = L"Damage State 4";

	// define active zone parameter grid columns.
	literal String^ GRID_OD_ZONE_COL1 = L"Origination";
	literal String^ GRID_OD_ZONE_COL2 = L"Destination";
	literal String^ GRID_OD_ZONE_COL3 = L"Traffic Volume";
	literal String^ DEFAULT_TRAFFIC_VOLUME = L"1000";


	// define input demand meta parameter grid columns.
	literal String^ GRID_INPUT_DEMAND_META_COL1 = L"Start Time";
	literal String^ GRID_INPUT_DEMAND_META_COL2 = L"End Time";

	literal String^ DEFAULT_START_TIME = L"660";
	literal String^ DEFAULT_END_TIME = L"720";

	// define POI connectivity grid columns.
	literal String^ GRID_POI_CONNECTIVITY_COL1 = L"Link ID";
	literal String^ GRID_POI_CONNECTIVITY_COL2 = L"Zone";

	// define POI connectivity zone grid columns.
	literal String^ GRID_POI_CONNECTIVITY_ZONE_COL1 = L"Zone";
	literal String^ GRID_POI_CONNECTIVITY_ZONE_COL2 = L"# of POIs";

	// define environment grid columns.
	literal String^ GRID_ENVIRONMENT_COL1 = L"Link ID";

	literal int DAMAGE_STATE_COUNT = 4;

	literal int DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1 = 0;
	literal int DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE2 = 7;
	literal int DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE3 = 150;
	literal int DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE4 = 450;
	literal int DEFAULT_TRAFFIC_CARRYING_DAMAGE_REF = 500;


	literal double DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1 = 0.03;
	literal double DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2 = 0.25;
	literal double DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3 = 0.75;
	literal double DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4 = 1;

	literal double DEFAULT_TRAFFIC_FACTOR1 = 16.08;
	literal double DEFAULT_TRAFFIC_FACTOR2 = 1.18;
	literal int DEFAULT_VALUE_OF_TIME = 9;
	literal int DEFAULT_PENALTY_COST = 20;

	literal int TOTAL_NUMBER_CATEGORY_FACILITY = 4;
	literal String^ FACILITY_TYPE1 = L"교량";
	literal String^ FACILITY_TYPE2 = L"터널";
	literal String^ FACILITY_TYPE3 = L"사면";
	literal String^ FACILITY_TYPE4 = L"옹벽";


	//UNIST 실행 시 필요한 행 갯수 
	literal int UNIST_RUN_REQ_ROWS = 262;

};