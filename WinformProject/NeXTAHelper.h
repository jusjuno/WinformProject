#pragma once
#include "FileUtil.h"
#include "CSVFileManager.h"
#include "ProjectDataSetBinder.h"
#include "OutputSummary.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

/// <summary>
/// NeXTA 클래스
/// </summary>
namespace WinformProject {
	public ref class NeXTAHelper
	{
	private:
		FileUtil^ m_fileUtil;
		String^ m_basePath;
		ProjectDataSetBinder^ m_dataSet;
		String^ m_scenarioNamePrefix;


	// OD변경 직후 true, 이외의 경우 false 
	int odIndex = 0;



	public:
		int totalLinkNum;
	public:
		NeXTAHelper(ProjectDataSetBinder^ dataSet) {
			this->m_dataSet = dataSet;
			this->m_fileUtil = gcnew FileUtil();
//			this->m_basePath = "NeXTA/";
			this->m_basePath = "C:\\sample\\NEXTA\\";;
			this->m_scenarioNamePrefix = "test";
		}
	public:
		// convert mile to km
		static double mileToKm(double mile) {
			double km = 1.609344;
			return mile * km;
		}

		// convert km to mile
		static double kmToMile(double km) {
			double mile = 0.6213711922;
			return km * mile;
		}

		static String^ GetScenarioId(int trafficScenarioNo, int damageState) {
//			return String::Format("{0}-{1}", trafficScenarioNo, damageState);
			return String::Format("{0}{1}", trafficScenarioNo, damageState);
		}

		literal String^ NORMAL_SCENARIO_ID = "0";
	public:
		// create new datatable object by columns information
		DataTable^ NewTable(array<String^>^ columns) {
			DataTable^ table = gcnew DataTable();
			// define fields
			for each (String^ col in columns)
			{
				table->Columns->Add(gcnew DataColumn(col));
			}
			return table;
		}

		// generate mote cario
		bool GenerateInputFiles() {
			// TODO: generate NeXTA input file
			return true;
		}

		// write input_node.csv file
		bool WriteFileInputNode() {
			array<String^>^ columns = { "name", "node_id", "control_type", "control_type_name", "cycle_length_in_second"
				, "x", "y", "geometry" };
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_node.csv");

			// set data			
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			for each (KeyValuePair<String^, ShapeNode^>^ pair in m_dataSet->ShapeData->m_SHPNodes)
			{
				int tmpIndex = 0;
				newRow = newTable->NewRow(); // create new row
				// name:
				// Optional for visualization only
				newRow[columns[tmpIndex++]] = "";
				// node_id:
				// Node identification number
				newRow[columns[tmpIndex++]] = pair->Value->ID;
				// control_type:
				// defined in input_node_control_type.csv, certain control type such as pretimed signals or 4­way stop signs
				newRow[columns[tmpIndex++]] = "0";
				// control_type_name:
				// defined in input_node_control_type.csv
				newRow[columns[tmpIndex++]] = "unknown_control";
				// cycle_length_in_second:
				// The signal cycle length for a specific node, unit: second.
				newRow[columns[tmpIndex++]] = "0";
				// x:
				// Longitude or horizontal coordinate in any arbitrary geographic coordinate system.
				newRow[columns[tmpIndex++]] = pair->Value->Location.x;
				// y:
				// Latitude or vertical coordinate horizontal coordinate in any arbitrary geographic coordinate system
				newRow[columns[tmpIndex++]] = pair->Value->Location.y;
				// geometry:
				// Text string used to describe node location(typically in WGS84 geographic coordinate system)
				newRow[columns[tmpIndex++]] = String::Format("\"<Point><coordinates>{0},{1}</coordinates></Point>\"", pair->Value->Location.x, pair->Value->Location.y);
				newTable->Rows->Add(newRow);
			}
			return csv->Write(columns, newTable);
		}

		// write input_link.csv file
		bool WriteFileInputLink() {
			// Requirements: 
			// the from_node_id, to_node_id fields must be defined in input_node.csv.
			// If the downstream node is a signalized intersection, the effective_green_time_length_in_second field is required.

			array<String^>^ columns = { "name", "link_id", "from_node_id", "to_node_id", "link_type_name"
				, "direction", "length", "number_of_lanes", "speed_limit", "lane_capacity_in_vhc_per_hour", "link_type"
				, "jam_density", "wave_speed", "geometry" };
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_link.csv");

			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			totalLinkNum = 0;
			for each (ShapeProperty^ prop in this->m_dataSet->ShapeData->m_SHPProperties)
			{
				String^ linkID = prop->GetProperty(ShapeProperty::PropertyType::LINK_ID);
				String^ length = prop->GetProperty(ShapeProperty::PropertyType::LENGTH);


				String^ linkType = prop->GetProperty(ShapeProperty::PropertyType::TYPE);


				bool bidirFlag = prop->IsBidirectional;
				int nodeIndex = 0;
				do {
					ShapeNode^ fromNode = nullptr;
					ShapeNode^ toNode = nullptr;
					if (nodeIndex == 0) {
						fromNode = prop->Nodes[nodeIndex];
						toNode = prop->Nodes[nodeIndex + 1];
						if (toNode == nullptr) {
							toNode = fromNode;
						}
					}
					else {
						fromNode = prop->Nodes[nodeIndex];
						toNode = prop->Nodes[nodeIndex - 1];
						if (fromNode == nullptr) {
							fromNode = toNode;
						}
					}
					// 링크는 노드가 같을 수가 없기 때문에 같은경우 제외
					if (fromNode->ID != toNode->ID) {
						int tmpIndex = 0;
						newRow = newTable->NewRow(); // create new row
						// name: 
						// Optional for visualization purposes
						newRow[columns[tmpIndex++]] = "";
						// link_id: 
						// Optional link identification number, generated from NeXTA
						newRow[columns[tmpIndex++]] = linkID;
						// from_node_id:
						// Upstream node number of the link, must already defined in input_node.csv
						newRow[columns[tmpIndex++]] = fromNode->ID;
						// to_node_id:
						// Downstream node number of the link, must already defined in input_node.csv
						newRow[columns[tmpIndex++]] = toNode->ID;
						// link_type_name:
						// Optional text label for visualization and data checking purposes, 
						// generated from NeXTA based on field link_type and name defined in input_link_type.csv
						newRow[columns[tmpIndex++]] = "Minor arterial";
						// direction:
						// Identifies the direction of travel on the link.Default value = 1.
						// When 1, NeXTA reverses from_node_id and to_node_id for correct orientation.
						// When 0 or 2, NeXTA automatically converts link into two oneway links.
						newRow[columns[tmpIndex++]] = "1";
						// length:
						// The length of the link (between end nodes), measured in units of miles.
						newRow[columns[tmpIndex++]] = length;
						// number_of_lanes:
						// The number of lanes on the link
						newRow[columns[tmpIndex++]] = "2";
						// speed_limit:
						// Speed limit on defined link in units of miles per hour.Unit: mph
						newRow[columns[tmpIndex++]] = "80";


						// lane_cap:
						// Maximum service flow rate for each lane on the link, in vehicles per hour.
						// This capacity value is not used used for signalized control with a positive cycle length defined.
						// Typical values are 1800 for a freeway lane, 900 for an arterial lane, 1500 for a single on­ramp lane.
						//newRow[columns[tmpIndex++]] = "1500";

						String^ linkCapacity;
						String^ linkTypeIndex;
						for(int typeIndex=0; typeIndex< m_dataSet->LinkTypes->Rows->Count; typeIndex++){
							DataRow^ newRow = nullptr;
							newRow = m_dataSet->LinkTypes->Rows[typeIndex];
							linkTypeIndex = String::Format("{0}",newRow[0]->ToString());  // @newProjectForm.h에 정의된 linkType에 따라, 첫칼럼(=0)에 linkType이 저장됨  
							if (linkTypeIndex == linkType) {
								linkCapacity = String::Format("{0}", newRow[3]->ToString());     // linkType별 capacity는 셋째칼럼(=2)에 저장됨
								break;
							}
						}
						newRow[columns[tmpIndex++]] = linkCapacity;						
						// link_type:
						// Link type identification number, corresponding to link functional class (freeway, ramps), must bedefined in input_link_type.csv
						//newRow[columns[tmpIndex++]] = "7";
						newRow[columns[tmpIndex++]] = linkTypeIndex;


						// jam_density:
						// Jam density (in vehicles per mile per lane), 
						// input for two traffic flow models(spatial queue and Newell’s simplified kinematic wave model).
						// Unit: number of vehicles per mile per lane : default value 180 for freeway links, 190 for arterial street links.
						newRow[columns[tmpIndex++]] = "180";
						// wave_speed:
						// Backward wave speed in miles per hour, 
						// only used in Newell’s simplified kinematic wave model to define the vehicle storage space on a link : Default = 12mph
						newRow[columns[tmpIndex++]] = "12";
						// geometry:
						// Text string used to describe link shape and location(typically in WGS84 geographic coordinate system).
						// The initial value can be empty, and NeXTA will generate the text string based on the coordinates of upstream and downstream nodes.
						newRow[columns[tmpIndex++]] = String::Format("\"<LineString><coordinates>{0},{1},{2} {3},{4},{5}</coordinates></LineString>\"", fromNode->Location.x, fromNode->Location.y, "0.0", toNode->Location.x, toNode->Location.y, "0.0");
						newTable->Rows->Add(newRow);
						nodeIndex++;
					}
				} while (bidirFlag && nodeIndex == 1);
				totalLinkNum = totalLinkNum + 1;
			}
			return csv->Write(columns, newTable);
		}

		// write input_zone.csv file
		bool WriteFileInputZone() {
			array<String^>^ columns = { "zone_id", "geometry" };
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_zone.csv");

			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;

			int tmpIndex = 0;
			// TODO:: 나중에 zone 생성 방법을 찾아 변경해야함 
			// 지금은 노드 하나당 링크 하나로 맵핑
			for each (KeyValuePair<String^, array<ShapeNode^>^>^ pair in m_dataSet->ShapeData->m_SHPZones)
			{
				tmpIndex = 0;
				newRow = newTable->NewRow(); // create new row
				// zone_id:
				// Zone identification number. 
				// A zone number used in OD demand table files must be defined here first.Zone numbers are not required to be consecutively sequential.
				newRow[columns[tmpIndex++]] = pair->Key;

				// geometry: 
				// Optional: Text string used to describe zone location for visualization(typically in WGS84 geographic coordinate system).
				/*
				MBR mbr = m_dataSet->ShapeData->m_MBR;
				String^ geoStr = "\"<Polygon><outerBoundaryIs><LinearRing><coordinates>" +
					String::Format("{0},{1},{2} {3},{4},{5} ", mbr.xmin, mbr.ymin, "0.0", mbr.xmin, mbr.ymax, "0.0") +
					String::Format("{0},{1},{2} {3},{4},{5}", mbr.xmax, mbr.ymax, "0.0", mbr.xmax, mbr.ymin, "0.0") + 
					"</coordinates></LinearRing></outerBoundaryIs></Polygon>\"";
				*/
				String^ geoStr = "\"<Polygon><outerBoundaryIs><LinearRing><coordinates></coordinates></LinearRing></outerBoundaryIs></Polygon>\"";
				newRow[columns[tmpIndex++]] = geoStr;
				newTable->Rows->Add(newRow);
			}

			return csv->Write(columns, newTable);
		}

		// write input_activity_location.csv file
		bool WriteFileInputActivityLocation() {
			array<String^>^ columns = { "zone_id", "node_id", "external_OD_flag" };
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_activity_location.csv");

			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;

			int tmpIndex = 0;
			for each (KeyValuePair<String^, array<ShapeNode^>^>^ pair in m_dataSet->ShapeData->m_SHPZones)
			{
				for each (ShapeNode^ node in pair->Value)
				{
					int tmpIndex = 0;
					newRow = newTable->NewRow(); // create new row
					// zone_id:
					// Zone identification number
					newRow[columns[tmpIndex++]] = pair->Key;
					// node_id:
					// Node identification number associated with the zone identification number in the same row.
					// Must defined in input_node.csv.
					newRow[columns[tmpIndex++]] = node->ID;
					// external_OD_flag
					// Used to identify the type of activity location as non­external (default = 0) or external(­1 or 1).
					// When 0, acts as both origin and destination.
					newRow[columns[tmpIndex++]] = "0";
					newTable->Rows->Add(newRow);
				}
			}
			return csv->Write(columns, newTable);
		}

		// write input_node_control_type.csv file
		bool WriteAdvancedFileInputNodeControlType() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_node_control_type.csv");
			array<String^>^ columns = { "control_type_name", "control_type" };
			csv->IsWriteColumnNames = false;
			csv->IsVertical = true;
			if (this->m_dataSet->NodeControlTypes != nullptr) {
				return csv->Write(columns, this->m_dataSet->NodeControlTypes);
			}
			else {
				// set data
				DataTable^ newTable = NewTable(columns);
				DataRow^ newRow = nullptr;
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "unknown_control";
				newRow[columns[1]] = "0";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "no_control";
				newRow[columns[1]] = "1";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "yield_sign";
				newRow[columns[1]] = "2";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "2way_stop_sign";
				newRow[columns[1]] = "3";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "4way_stop_sign";
				newRow[columns[1]] = "4";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "pretimed_signal";
				newRow[columns[1]] = "5";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "actuated_signal";
				newRow[columns[1]] = "6";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				newRow[columns[0]] = "roundabout";
				newRow[columns[1]] = "100";
				newTable->Rows->Add(newRow);
				return csv->Write(columns, newTable);
			}
		}


		// write input_link_type.csv file
		bool WriteAdvancedFileInputLinkType() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_link_type.csv");
			array<String^>^ columns = { "link_type", "link_type_name", "type_code", "default_lane_capacity", "default_speed_limit"
				, "default_number_of_lanes" };
			if (this->m_dataSet->LinkTypes != nullptr) {
				return csv->Write(columns, this->m_dataSet->LinkTypes);
			}
			else {
				// set data
				DataTable^ newTable = NewTable(columns);
				DataRow^ newRow = nullptr;
				newRow = newTable->NewRow(); // create new row
				int colIndex = 0;
				newRow[columns[colIndex++]] = "1";
				newRow[columns[colIndex++]] = "Freeway";
				newRow[columns[colIndex++]] = "f";
				newRow[columns[colIndex++]] = "1800";
				newRow[columns[colIndex++]] = "65";
				newRow[columns[colIndex++]] = "3";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "2";
				newRow[columns[colIndex++]] = "Highway/Expressway";
				newRow[columns[colIndex++]] = "h";
				newRow[columns[colIndex++]] = "1450";
				newRow[columns[colIndex++]] = "50";
				newRow[columns[colIndex++]] = "3";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "3";
				newRow[columns[colIndex++]] = "Principal arterial";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "1000";
				newRow[columns[colIndex++]] = "40";
				newRow[columns[colIndex++]] = "3";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "4";
				newRow[columns[colIndex++]] = "Major arterial";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "900";
				newRow[columns[colIndex++]] = "35";
				newRow[columns[colIndex++]] = "3";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "5";
				newRow[columns[colIndex++]] = "Minor arterial";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "850";
				newRow[columns[colIndex++]] = "30";
				newRow[columns[colIndex++]] = "2";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "6";
				newRow[columns[colIndex++]] = "Collector";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "650";
				newRow[columns[colIndex++]] = "25";
				newRow[columns[colIndex++]] = "1";
				newTable->Rows->Add(newRow);
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "7";
				newRow[columns[colIndex++]] = "Local";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "600";
				newRow[columns[colIndex++]] = "20";
				newRow[columns[colIndex++]] = "1";
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "8";
				newRow[columns[colIndex++]] = "Frontage road";
				newRow[columns[colIndex++]] = "a";
				newRow[columns[colIndex++]] = "1000";
				newRow[columns[colIndex++]] = "45";
				newRow[columns[colIndex++]] = "2";
				newTable->Rows->Add(newRow);
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "9";
				newRow[columns[colIndex++]] = "Ramp";
				newRow[columns[colIndex++]] = "r";
				newRow[columns[colIndex++]] = "1300";
				newRow[columns[colIndex++]] = "30";
				newRow[columns[colIndex++]] = "2";
				newTable->Rows->Add(newRow);
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "10";
				newRow[columns[colIndex++]] = "Zonal connector";
				newRow[columns[colIndex++]] = "c";
				newRow[columns[colIndex++]] = "2000";
				newRow[columns[colIndex++]] = "100";
				newRow[columns[colIndex++]] = "2";
				newTable->Rows->Add(newRow);
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "100";
				newRow[columns[colIndex++]] = "Transit link";
				newRow[columns[colIndex++]] = "t";
				newRow[columns[colIndex++]] = "1000";
				newRow[columns[colIndex++]] = "40";
				newRow[columns[colIndex++]] = "1";
				newTable->Rows->Add(newRow);
				m_dataSet->LinkTypes->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "200";
				newRow[columns[colIndex++]] = "Walking link";
				newRow[columns[colIndex++]] = "w";
				newRow[columns[colIndex++]] = "1000";
				newRow[columns[colIndex++]] = "5";
				newRow[columns[colIndex++]] = "1";
				newTable->Rows->Add(newRow);
				return csv->Write(columns, newTable);
			}
		}

		// write input_pricing_type.csv file
		bool WriteAdvancedFileInputPricingType() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_pricing_type.csv");
			array<String^>^ columns = { "pricing_type", "defalult_VOT"};
		// set data
				DataTable^ newTable = NewTable(columns);
				DataRow^ newRow = nullptr;
				newRow = newTable->NewRow(); // create new row
				int colIndex = 0;
				newRow[columns[colIndex++]] = "1";
				newRow[columns[colIndex++]] = "10";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "2";
				newRow[columns[colIndex++]] = "20";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "3";
				newRow[columns[colIndex++]] = "30";
				newTable->Rows->Add(newRow);
				newRow = newTable->NewRow(); // create new row
				colIndex = 0;
				newRow[columns[colIndex++]] = "4";
				newRow[columns[colIndex++]] = "10";
				newTable->Rows->Add(newRow);
				return csv->Write(columns, newTable);
		}

		// write input_VOT.csv file
		bool WriteFileInputVOT() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_VOT.csv");
			array<String^>^ columns = { "demand_type", "VOT_dollar_per_hour", "percentage"};
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
				return csv->Write(columns, newTable);
		}
					   		
		// write input_vehicle_type.csv file
		bool WriteFileInputVehicleType() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_vehicle_type.csv");
			array<String^>^ columns = { "vehicle_type", "vehicle_type_name"};
			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			newRow = newTable->NewRow(); // create new row
			int colIndex = 0;
			newRow[columns[colIndex++]] = "1";
			newRow[columns[colIndex++]] = "passenger car";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "2";
			newRow[columns[colIndex++]] = "passener truck";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "3";
			newRow[columns[colIndex++]] = "light commercial truck";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "4";
			newRow[columns[colIndex++]] = "single unit short-haul truck";
			newTable->Rows->Add(newRow);
			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "5";
			newRow[columns[colIndex++]] = "combination long-haul truck";
			newTable->Rows->Add(newRow);
			return csv->Write(columns, newTable);
		}

		// write input_demand_type.csv file
		bool WriteFileInputDemandType() {
			//array<String^>^ columns = { "demand_type", "demand_type_name", "average_VOT", "pricing_type","percentage_of_pretrip_info"
			//	, "percentage_of_enroute_info", "percentage_of_vehicle_type1", "percentage_of_vehicle_type2", "percentage_of_vehicle_type3"
			//    , "percentage_of_vehicle_type4", "percentage_of_vehicle_type5"};
			array<String^>^ columns = { "demand_type", "demand_type_name", "avg_VOT", "pricing_type","percentage_of_pretrip_info"
				, "percentage_of_enroute_info", "percentage_of_vehicle_type1", "percentage_of_vehicle_type2", "percentage_of_vehicle_type3"
				, "percentage_of_vehicle_type4", "percentage_of_vehicle_type5" };

			// Additional columns (with incremental #) can be used when	more vehicle types are defined.
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_demand_type.csv");
			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			newRow = newTable->NewRow(); // create new row
			int colIndex = 0;
			newRow[columns[colIndex++]] = "1";
			newRow[columns[colIndex++]] = "SOV";
			newRow[columns[colIndex++]] = "10";
			newRow[columns[colIndex++]] = "1";
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "80";
			newRow[columns[colIndex++]] = "20";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newTable->Rows->Add(newRow);

			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "2";
			newRow[columns[colIndex++]] = "HOV";
			newRow[columns[colIndex++]] = "10";
			newRow[columns[colIndex++]] = "2";
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "80";
			newRow[columns[colIndex++]] = "20";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newTable->Rows->Add(newRow);

			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "3";
			newRow[columns[colIndex++]] = "truck";
			newRow[columns[colIndex++]] = "20";
			newRow[columns[colIndex++]] = "3";
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "30";
			newRow[columns[colIndex++]] = "30";
			newRow[columns[colIndex++]] = "40";
			newTable->Rows->Add(newRow);

			newRow = newTable->NewRow(); // create new row
			colIndex = 0;
			newRow[columns[colIndex++]] = "4";
			newRow[columns[colIndex++]] = "SOV";
			newRow[columns[colIndex++]] = "10";
			newRow[columns[colIndex++]] = "1";
			newRow[columns[colIndex++]] = "100";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newRow[columns[colIndex++]] = "0";
			newTable->Rows->Add(newRow);

			return csv->Write(columns, newTable);
		}	
		
		// write input_demand.csv file

			//////////
			//수정중//
			/////////

			//bool WriteAdvancedFileInputDemand() {
		bool WriteAdvancedFileInputDemand(DataRow^ OriginAndDestin) {
			array<String^>^ columns = { "from_zone_id", "to_zone_id", "number_of_trips_demand_type1" };
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_demand.csv");
			// set data
			DataTable^ newTable = NewTable(columns);

			/*
			//for (int i = 0; i < this->m_dataSet->m_odZoneParams->Rows->Count; i++) {
			for (int i = 0; i < this->m_dataSet->ODZoneParamData->Rows->Count; i++) {
				DataRow^ newRow = nullptr;
				//OD(Origination출발점 - Destination도착점)경로를 설정하는 UI가 필요함.
				//임시로 zone"5"를 출발점으로 zone"4"를 도착점으로 설정함.
				//향후 버튼 또는 화면클릭을 통한 OD를 선정할 수 있도록 할 수 있는 방법이 필요함.
				newRow = newTable->NewRow(); // create new row


				int colIndex = 0;

				//DataRow^ newRowOD = this->m_dataSet->m_odZoneParams->Rows[i];
				DataRow^ newRowOD = this->m_dataSet->ODZoneParamData->Rows[i];
				
//				int indexOrigin = this->m_dataSet->ODZoneParamData->Columns->IndexOf("Origination");
//				int indexDestin = this->m_dataSet->ODZoneParamData->Columns->IndexOf("Destination");
//				int indexVolume = this->m_dataSet->ODZoneParamData->Columns->IndexOf("Traffic Volume");


				//newRow[columns[colIndex++]] = "419";
				//newRow[columns[colIndex++]] = "335";
				//newRow[columns[colIndex++]] = "1000";

				newRow[columns[colIndex++]] = newRowOD[CommConst::GRID_OD_ZONE_COL1];
				newRow[columns[colIndex++]] = newRowOD[CommConst::GRID_OD_ZONE_COL2];
				newRow[columns[colIndex++]] = newRowOD[CommConst::GRID_OD_ZONE_COL3];

				newTable->Rows->Add(newRow);
			}
			return csv->Write(columns, newTable);
			*/

			//OD(Origination출발점 - Destination도착점)경로를 설정하는 UI가 필요함.
			//임시로 zone"5"를 출발점으로 zone"4"를 도착점으로 설정함.
			//향후 버튼 또는 화면클릭을 통한 OD를 선정할 수 있도록 할 수 있는 방법이 필요함.
			DataRow^ newRow = newTable->NewRow(); // create new row
			int colIndex = 0;
			newRow[columns[colIndex++]] = OriginAndDestin[CommConst::GRID_OD_ZONE_COL1];
			newRow[columns[colIndex++]] = OriginAndDestin[CommConst::GRID_OD_ZONE_COL2];
			newRow[columns[colIndex++]] = OriginAndDestin[CommConst::GRID_OD_ZONE_COL3];

			newTable->Rows->Add(newRow);

			return csv->Write(columns, newTable);
		}

		// write input_demand_file_list.csv file
		bool WriteFileInputDemandMetaData() {
			array<String^>^ columns = { "scenario_no", "file_sequence_no", "file_name", "format_type"
				, "number_of_lines_to_be_skipped", "loading_multiplier", "subtotal_in_last_column", "start_time_in_min", "end_time_in_min"
				, "apply_additional_time_dependent_profile", "number_of_demand_types"
				, "demand_type_1", "demand_type_2", "demand_type_3", "demand_type_4" };
			// 00:00 ~ 23:45까지 15분 간격으로 시간 컬럼 생성
			int oldArrSize = columns->Length;
			int addArrSize = 24 * (60 / 15); // 24시간 * (60분 / 15분)
			Array::Resize(columns, oldArrSize + addArrSize);
			int time = -15; // 00:00 부터 시작하기위해서 강제로 -15분 부터 시작
			// demand_type_4 이후부터 추가
			for (int i = oldArrSize; i < columns->Length; i++)
			{
				time += 15;
				columns[i] = String::Format("'{0}:{1}", (time / 60).ToString()->PadLeft(2, '0'), (time - ((time / 60) * 60)).ToString()->PadLeft(2, '0'));
			}

			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			int tmpIndex = 0;
			//int startTime = 660;
			//int endTime = 720;
			//String^ startTimeStr = String::Format("{0}", startTime);
			//String^ endTimeStr = String::Format("{0}", endTime);
			
			DataRow^ newRowMeta = this->m_dataSet->InputDemandMetaParamData->Rows[0];
//			int indexStart = this->m_dataSet->InputDemandMetaParamData->Columns->IndexOf("Start Time");
//			int indexEnd = this->m_dataSet->InputDemandMetaParamData->Columns->IndexOf("End Time");
			

			String^ startTimeStr = newRowMeta[CommConst::GRID_INPUT_DEMAND_META_COL1]->ToString();
			String^ endTimeStr = newRowMeta[CommConst::GRID_INPUT_DEMAND_META_COL2]->ToString();


			// 전체 시나리오 수 = 정상케이스 + (생성 시나리오 * DAMAGE_STATE_COUNT)
			// array index: 0=정상, 1=시나리오1(ds1), 2=시나리오1(ds2), 3=시나리오1(ds3), 4=시나리오1(ds4), 5=시나리오2(ds1) ....
			//int totalCount = (this->m_dataSet->TotalTrafficScenarioCount * CommConst::DAMAGE_STATE_COUNT) + 1;
			int totalCount = 1;
			for (int i = 0; i < totalCount; i++)
			{
				tmpIndex = 0;
				newRow = newTable->NewRow();
				// scenario_no
				newRow[columns[tmpIndex++]] = String::Format("{0}", i);
				// file_sequence_no
				newRow[columns[tmpIndex++]] = "1";
				// file_name
				newRow[columns[tmpIndex++]] = "input_demand.csv";
				// format_type
				newRow[columns[tmpIndex++]] = "column";
				// number_of_lines_to_be_skipped
				newRow[columns[tmpIndex++]] = "1";
				// loading_multiplier
				newRow[columns[tmpIndex++]] = "1.0";
				// subtotal_in_last_column
				newRow[columns[tmpIndex++]] = "0";
				// start_time_in_min
				newRow[columns[tmpIndex++]] = startTimeStr;
				// end_time_in_min
				newRow[columns[tmpIndex++]] = endTimeStr;
				// apply_additional_time_dependent_profile
				newRow[columns[tmpIndex++]] = "0";
				// number_of_demand_types
				newRow[columns[tmpIndex++]] = "1";
				// demand_type_1
				newRow[columns[tmpIndex++]] = "1";


				tmpIndex = oldArrSize + (int::Parse(startTimeStr) / 15);
				int tmpTime = int::Parse(startTimeStr);
				// 반복
				while (tmpTime <= int::Parse(endTimeStr))
				{
					// time column
					newRow[columns[tmpIndex]] = "";
					tmpIndex++;
					tmpTime += 15;
				}

/*
					//while (tmpTime < endTime)
					{
					// time column
					if (tmpTime < 480) { // 07:00시 이후
						newRow[columns[tmpIndex]] = "0.25";
					}
					else {
						newRow[columns[tmpIndex]] = "0.3";
					}
					tmpIndex++;
					tmpTime += 15;
				}
*/


				newTable->Rows->Add(newRow);
			}
//			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_demand_meta_data.csv");
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_demand_file_list.csv");
			return csv->Write(columns, newTable);
		}

		// write input_scenario_settings.csv file
		// 시나리오 생성
		// 정상을 제외한 데미지가 없는 시나리오는 생성하지 않음
		bool WriteFileInputScenarioSettings() {
			array<String^>^ columns = {

				"scenario_no"
				, "scenario_name"
				, "number_of_assignment_days"
//				, "number_of_iteration"
				, "traffic_flow_model"
				, "traffic_assignment_method"
//				, "agent_demand_input_mode"
				, "ODME_mode"
				, "emission_data_output"
				, "demand_multiplier"
				, "random_seed"
				, "default_arterial_k_jam"
				, "default_cycle_length"
				, "ODME_start_iteration"
				, "ODME_max_percentage_deviation_wrt_hist_demand"
				, "ODME_step_size"
				, "freeway_bias_factor"
				, "ue_gap_calculation_method"
				, "agent_demand_input_mode"
				, "calibration_data_start_time_in_min"
				, "calibration_data_end_time_in_min"
			};
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			int tmpIndex = 0;
			int scenarioNo = 0;

			// 전체 시뮬레이션 시나리오 수 = (생성 시나리오 x damageState 중 모든 link가 closed된 경우의 수) + 정상케이스
			int totalCount = this->m_dataSet->TrafficScenarios->Length;
			//Damage State별 복구일수가 "0"일 이상일 경우만 시나리오 생성 
			int damageStateStart = 1;
			if (CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1 == 0) {
				damageStateStart = 2;
			}

			// 시나리오 총수(totalCount)는 (지진소스 개수 * 재현주기 개수 * 샘플 개수 * OD 개수)
			// 따라서 교통해석프로그램(DTALite)에서 한번에 생성되는 Outputsummary 시나리오수는 (지진소스 개수 * 재현주기 개수 * 샘플 개수) 이므로
			// 한번에 계산되는 (시나리오 수) = (시나리오 총수) / (OD 개수)
			//for (int i = 0; i < totalCount; i++)
			for (int i = 0; i < (totalCount)/(this->m_dataSet->ODZoneParamData->Rows->Count); i++)
				{
				TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[i];
				for (int damageState = damageStateStart; damageState <= CommConst::DAMAGE_STATE_COUNT; damageState++)
				{
					// 정상케이스(0), 모든 링크가 닫힌 시나리오가 아닌경우만 시뮬레이션 시나리오로 생성
					if (scenarioNo == 0 || scenario->IsContainClosedLink(damageState)) {
						tmpIndex = 0;
						newRow = newTable->NewRow();
						// scenario_no
						newRow[columns[tmpIndex++]] = String::Format("{0}", scenarioNo);
						// scenario_name
						if (scenarioNo == 0) {
							// 정상은 교통 시나리오가 없기 때문에 그냥 0으로 생성
							newRow[columns[tmpIndex++]] = String::Format("{0}{1}", m_scenarioNamePrefix, NORMAL_SCENARIO_ID);
						}
						else {
							newRow[columns[tmpIndex++]] = String::Format("{0}{1}", m_scenarioNamePrefix, GetScenarioId(scenario->TrafficScenarioNo, damageState));
						}

						// number_of_assignment_days
						//newRow[columns[tmpIndex++]] = "2";
						newRow[columns[tmpIndex++]] = "1";

						// traffic_flow_model
						newRow[columns[tmpIndex++]] = "2";
						// traffic_assignment_method
						newRow[columns[tmpIndex++]] = "0";
						// agent_demand_input_mode
						//newRow[columns[tmpIndex++]] = "0";
						// ODME_mode
						newRow[columns[tmpIndex++]] = "0";
						// emission_data_output
						newRow[columns[tmpIndex++]] = "0";
						// demand_multiplier
						newRow[columns[tmpIndex++]] = "1";
						// random_seed
						newRow[columns[tmpIndex++]] = "100";
						// default_arterial_k_jam
						newRow[columns[tmpIndex++]] = "250";
						// default_cycle_length
						newRow[columns[tmpIndex++]] = "110";

						// ODME_start_iteration
						//newRow[columns[tmpIndex++]] = "20";

						// ODME_max_percentage_deviation_wrt_hist_demand
						newRow[columns[tmpIndex++]] = "30";
						//newRow[columns[tmpIndex++]] = "100";

						// ODME_step_size
						newRow[columns[tmpIndex++]] = "0.05";
						//newRow[columns[tmpIndex++]] = "0.1";

						// freeway_bias_factor
						newRow[columns[tmpIndex++]] = "1";
						// ue_gap_calculation_method
						newRow[columns[tmpIndex++]] = "0";
						// agent_demand_input_mode
						newRow[columns[tmpIndex++]] = "0";
						// calibration_data_start_time_in_min
						//newRow[columns[tmpIndex++]] = "420";
						newRow[columns[tmpIndex++]] = "";
						// calibration_data_end_time_in_min
						//newRow[columns[tmpIndex++]] = "480";
						newRow[columns[tmpIndex++]] = "";
						newTable->Rows->Add(newRow);
						scenarioNo++;
						if (scenarioNo - 1 == 0) {
							// 0 = 정상 시나리오
							i--;
							break;
						}
					}
				}
			}
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_scenario_settings.csv");
			return csv->Write(columns, newTable);
		}

		// write scenario_incident.csv file
		bool WriteFileScenarioIncident() {
			array<String^>^ columns = { "Link", "Scenario No", "Day No", "Start Time in min"
				, "End Time in min", "Capacity Reduction Percentage(%)", "Speed Limit(mph)"};
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "scenario_incident.csv");
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			return csv->Write(columns, newTable);
		}

		// write scenario_work_zone.csv file
		// 시나리오별 closed link 셋팅
		bool WriteFileScenarioWorkZone() {
			array<String^>^ columns = { "Link", "Scenario No", "Start Day", "End Day", "Start Time in Min", "End Time in Min"
				, "Capacity Reduction Percentage (%)", "Speed Limit (mph)" };
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;
			int tmpIndex = 0;
			int scenarioNo = 1;

			// 전체 시나리오 수
			int trafficScenarioLength = this->m_dataSet->TrafficScenarios->Length;
			// damage state별 복구일수가 "0"일 이상일 경우만 시나리오 생성
			int damageStateStart = 1;
			if (CommConst::DEFAULT_TRAFFIC_CARRYING_DAMAGE_STATE1 == 0) {
				damageStateStart = 2;
			}
			for (int j = 0; j < trafficScenarioLength; j++) 
			{
				// scenario no가 0(정상 시나리오) 모든 노선이 오픈이므로 생성 안함
				TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[j];
				for (int damageState = damageStateStart ; damageState <= CommConst::DAMAGE_STATE_COUNT; damageState++)
				//for (int damageState = 1; damageState <= CommConst::DAMAGE_STATE_COUNT; damageState++)
					{
					// If there is closed link index, write data.
							// 시나리오 별로 각 damage state중 closed 되지 않은 link만 생성
					array<int>^ closedLinkIndexes = scenario->GetClosedLinkIndexes(damageState);
					for each (int index in closedLinkIndexes)
					{
						// data of closed link
						Dictionary<String^, bool>^ closedLinkMap = gcnew Dictionary<String^, bool>();
						// 컴포넌트 데미지 정보 확인
						ComponentInfo^ component = scenario->Components[index];
						String^ linkID = component->LinkID;
						if (this->m_dataSet->ShapeData->m_SHPPropertiesIndexes->ContainsKey(linkID)) {
							// 하나의 노선에는 1개이상의 시설물이 포함될 수 있으며
							// 이 경우 노선폐쇄 결정은 시설물중 최대피해를 입는 시설물에 의해 결정됨
							// 이미 등록된 링크가 있으면 추가등록 안함
							if (!closedLinkMap->ContainsKey(linkID)) {
								closedLinkMap->Add(linkID, true);

								//로컬변수할당
								int index = this->m_dataSet->ShapeData->m_SHPPropertiesIndexes[linkID];
								ShapeProperty^ prop = this->m_dataSet->ShapeData->m_SHPProperties[index];

								// 양방향여부
								bool bidirFlag = prop->IsBidirectional;
								int nodeIndex = 0;

								do {
									ShapeNode^ fromNode = nullptr;
									ShapeNode^ toNode = nullptr;
									if (nodeIndex == 0) {
										fromNode = prop->Nodes[nodeIndex];
										toNode = prop->Nodes[nodeIndex + 1];
										if (toNode == nullptr) {
											toNode = fromNode;
										}
									}
									else {
										fromNode = prop->Nodes[nodeIndex];
										toNode = prop->Nodes[nodeIndex - 1];
										if (fromNode == nullptr) {
											fromNode = toNode;
										}
									}
									// 링크는 노드가 같을 수가 없기 때문에 같은경우 제외
									if (fromNode->ID != toNode->ID) {
										tmpIndex = 0;
										newRow = newTable->NewRow();
										// Nodes are start and end of Link(from > to)
										newRow[columns[tmpIndex++]] = String::Format("[{0} {1}]", fromNode->ID, toNode->ID);
										// Scenario No
										newRow[columns[tmpIndex++]] = String::Format("{0}", scenarioNo);
										// Start Day
										newRow[columns[tmpIndex++]] = "1";
										// End Day
										String^ filter = String::Format("[{0}]='{1}'", CommConst::GRID_TRAFFIC_CARRYING_COL1, component->ClassID);
										DataRow^ foundRow = this->m_dataSet->TrafficCarryingParamData->Select(filter)[0];
										String^ param = String::Format("{0}", foundRow[component->MaxDamageState]);
										// Damage state에 따라서 종료일자를 산정
										if (param == "0") {
											newRow[columns[tmpIndex++]] = "1";
											//newRow[columns[tmpIndex++]] = "100";
										}
										else {
											newRow[columns[tmpIndex++]] = param;
											//newRow[columns[tmpIndex++]] = 100;
										}
										// Start Time in Min
										newRow[columns[tmpIndex++]] = "420";
										// End Time in Min
										//newRow[columns[tmpIndex++]] = "720";
										newRow[columns[tmpIndex++]] = "1440";
										// Capacity Reduction Percentage (%)
										newRow[columns[tmpIndex++]] = "100";
										// Speed Limit (mph)
										newRow[columns[tmpIndex++]] = "80";
										newTable->Rows->Add(newRow);
										nodeIndex++;
									}
								} while (bidirFlag && nodeIndex == 1);
							}
						}
					}
					if (closedLinkIndexes->Length > 0) {
						scenarioNo++;
					}
				}
			}
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "scenario_work_zone.csv");
			return csv->Write(columns, newTable);
		}

		// write optional_MOE_setting.csv file 
		bool WriteFileInputMOESettings() {
			array<String^>^ columns = { "moe_type", "moe_group", "notes", "moe_category_label", "cut_off_volume", "demand_type", "vehicle_type"
				, "information_type", "from_node_id", "mid_node_id", "to_node_id", "origin_zone_id", "destination_zone_id", "exclude_link_no"
				, "link_list_string", "departure_starting_time", "departure_ending_time", "entrance_starting_time", "entrance_ending_time"
				, "impact_type" };
			// set data
			DataTable^ newTable = NewTable(columns);
			DataRow^ newRow = nullptr;






			for each (ShapeProperty^ prop in this->m_dataSet->ShapeData->m_SHPProperties)
			{
				String^ linkID = prop->GetProperty(ShapeProperty::PropertyType::LINK_ID);
				String^ length = prop->GetProperty(ShapeProperty::PropertyType::LENGTH);
				bool bidirFlag = prop->IsBidirectional;
				int nodeIndex = 0;
//				int nodeIndex = 1;

				do {
					ShapeNode^ fromNode = nullptr;
					ShapeNode^ toNode = nullptr;
					if (nodeIndex == 0) {
						fromNode = prop->Nodes[nodeIndex];
						toNode = prop->Nodes[nodeIndex + 1];
						if (toNode == nullptr) {
							toNode = fromNode;
						}
					}
					//
					else {
						fromNode = prop->Nodes[nodeIndex];
						toNode = prop->Nodes[nodeIndex - 1];
						if (fromNode == nullptr) {
							fromNode = toNode;
						}
					}
					//
					// 링크는 노드가 같을 수가 없기 때문에 같은경우 제외
					if (fromNode->ID != toNode->ID) {
						newRow = newTable->NewRow(); // create new row
						newRow[columns[0]] = "link"; // moe_type
						newRow[columns[1]] = "1"; // moe_group
						newRow[columns[3]] = String::Format("{0}-{1}_{2}", linkID, fromNode->ID, toNode->ID); // moe_category_label
						newRow[columns[8]] = fromNode->ID; // from_node_id
						newRow[columns[10]] = toNode->ID; // to_node_id
						newTable->Rows->Add(newRow);
						nodeIndex++;
					}
				} while (bidirFlag && nodeIndex == 1);
			}







/*
			newRow = newTable->NewRow(); // create new row
			newRow[columns[0]] = "network"; // moe_type
			newRow[columns[1]] = "1"; // moe_group
			newRow[columns[3]] = "network"; // moe_category_label
			newTable->Rows->Add(newRow);
*/




			//CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "input_MOE_settings.csv");
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "optional_MOE_settings.csv");
			return csv->Write(columns, newTable);



		}

		// read output summary file
		bool ReadOutputSummaryFile() {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "output_summary.csv");
			String^ output = csv->Read();
			// scenario output map
			//this->m_dataSet->NeXTAOutputSummaryDictionary = gcnew Dictionary<String^, OutputSummary^>();

/*
			
			if (!String::IsNullOrEmpty(output)) {
				array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
				int outputRowCount = dataArray->Length;
				Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));
				bool isNotDamagedData = true; // 첫번째는 무조건 정상 데이터
				int notDamagedTotalVT = 0; // 정상 데이터의 전체 통행시간 합계
				// int notDamagedCumulativeOutFlowCount = 0; // 정상 데이터의 cumulative_out_flow_count

				int notDamagedNumberOfVehicleInNetwork = 0; //정상 네트워크의 총 차량대수
				int cumulativeOutFlowCount = 0; // cumulative_out_flow_count

				double avg_trip_time = 0; //평균 네트워크 이동시간

				OutputSummary^ outputSummary = nullptr; // output summary object
				// output 찾았는지 여부 
				bool isFindOutput = false;
				String^ scenarioId = ""; // traffic scenarioNo + damage state

				//=========================================
				// 지진피해로 출발점 -> 도착점 이동 불가 판단
				//=========================================				
				bool isNoAccess = false; //이동불가판단 논리변수

				for (int i = 0; i < outputRowCount; i++)
				{
					String^ outputLineData = dataArray[i];
					if (outputLineData->IndexOf(String::Format("-----{0}", this->m_scenarioNamePrefix)) >= 0) {
						// find output first line of scenario group
						// ex) ----------------------test0----------------------
						String^ scenarioName = outputLineData->Trim()->Replace("-", ""); // scenario name만 가져오기 
						scenarioId = scenarioName->Replace(this->m_scenarioNamePrefix, ""); // prefix 삭제
						outputSummary = gcnew OutputSummary();
						outputSummary->ScenarioName = scenarioName;
						Debug::WriteLine(String::Format("[{0}:{1}:{2}]", i, scenarioName, scenarioId));
						isFindOutput = true;
					}

					if (isFindOutput) {
						if (outputLineData->IndexOf("--Time Dependent Network MOE--,60 min interval") >= 0) {
							// find output
							avg_trip_time = 0;
							int j = i - 1; // 다음 1줄은 컬럼줄 제외
							outputLineData = dataArray[j];
							array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
							double::TryParse(values[13], avg_trip_time); // average network travel time
						}

						else if (outputLineData->IndexOf("--Time Dependent Network MOE--,5 min interval") >= 0) {
							// find output
							cumulativeOutFlowCount = 0;
							i = i + 2; // 다음 1줄은 컬럼줄 제외
							double cumulativeOutflowCount = 0;
							double numberOfVehicleInNetwork = 0;
							int length = 0;
							while (true) {
								outputLineData = dataArray[i++];
								array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
								if (length == 0) {
									length = values->Length;
								}
								if (values->Length != length) {
									break;
								}
								Double::TryParse(values[3], cumulativeOutflowCount); // cumulative_out_flow_count
								Double::TryParse(values[4], numberOfVehicleInNetwork); // number of vehicle in network

								if (values[3] == "0") { isNoAccess = true; } //"0"의 의미는 지진피해로 도로망으로 진입한 차량중 진출차량 전무
								else { isNoAccess = false; }
							}
							if (isNotDamagedData) {
								notDamagedTotalVT = cumulativeOutflowCount * avg_trip_time / 60;
								notDamagedNumberOfVehicleInNetwork = numberOfVehicleInNetwork; //
								isNotDamagedData = false;
							}
							outputSummary->TR0 = notDamagedNumberOfVehicleInNetwork;
							outputSummary->VT0 = notDamagedTotalVT; //
							outputSummary->TR1 = numberOfVehicleInNetwork;
							outputSummary->VT1 = cumulativeOutflowCount * avg_trip_time / 60; //

							this->m_dataSet->NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
							isFindOutput = false;
							isNoAccess = false;

							Debug::WriteLine(String::Format("[{0}:{1}] cumulative_out_flow_count={2}", outputSummary->ScenarioName, scenarioId, cumulativeOutflowCount));
						}

					}
				}
			}

*/

			if (!String::IsNullOrEmpty(output)) {
				array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
				int outputRowCount = dataArray->Length;
				Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));
				bool isNotDamagedData = true; // 첫번째는 무조건 정상 데이터
				double notDamagedTotalVT = 0; // 정상 데이터의 전체 통행시간 합계
				int notDamagedCumulativeOutFlowCount = 0; // 정상 데이터의 cumulative_out_flow_count
				
				int notDamangedTrafficNumber = 0;// 정상상태 통행차량대수 
				
				//int cumulativeOutFlowCount = 0; // cumulative_out_flow_count

				OutputSummary^ outputSummary = nullptr; // output summary object
				// output 찾았는지 여부 
				bool isFindOutput = false;
				String^ scenarioId = ""; // traffic scenarioNo + damage state

				//=========================================
				// 지진피해로 출발점 -> 도착점 이동 불가 판단
				//=========================================				
				bool isNoAccess = false; //이동불가판단 논리변수

				for (int i = 0; i < outputRowCount; i++)
				{
					String^ outputLineData = dataArray[i];
					//
					//	find output line index
					//
					if (outputLineData->IndexOf(String::Format("-----{0}", this->m_scenarioNamePrefix)) >= 0) {
						// find output first line of scenario group
						// ex) ----------------------test0----------------------
						String^ scenarioName = outputLineData->Trim()->Replace("-", ""); // scenario name만 가져오기 
						scenarioId = scenarioName->Replace(this->m_scenarioNamePrefix, ""); // prefix 삭제
						outputSummary = gcnew OutputSummary();
						outputSummary->ScenarioName = scenarioName;
						Debug::WriteLine(String::Format("[{0}:{1}:{2}]", i, scenarioName, scenarioId));
						isFindOutput = true;
					}

					if (isFindOutput) {
						if (outputLineData->IndexOf("Assignment method=,Zone-based routing") >= 0) {
							// find output
							//cumulativeOutFlowCount = 0;
							i = i + 2; // 다음 1줄은 컬럼줄 제외
							double averageTravelTime = 0;
							double totalVehicle = 0;
							double completedVehicle = 0;
			//				int length = 0;
			//				while (true) {
								outputLineData = dataArray[i++];
								array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
/*
								if (length == 0) {
									length = values->Length;
								}
								if (values->Length != length) {
									break;
								}
*/
								Double::TryParse(values[3], totalVehicle); // totalVehicle;0
								Double::TryParse(values[5], averageTravelTime); // averageTravelTime
								Double::TryParse(values[4], completedVehicle); // averageDistance;1

								if (values[4] == "0") { isNoAccess = true; } //"0"의 의미는 지진피해로 도로망으로 진입한 차량중 진출차량 전무
								else { isNoAccess = false; }
			//				}

							if (isNotDamagedData) {
								//notDamagedCumulativeOutFlowCount = totalVehicle;
								notDamangedTrafficNumber = totalVehicle;
								notDamagedTotalVT = totalVehicle * averageTravelTime / 60.;
								isNotDamagedData = false;
							}
							//cumulativeOutFlowCount = averageTravelTime;

							outputSummary->TR0 = notDamangedTrafficNumber;
							outputSummary->VT0 = notDamagedTotalVT;

							//지진시나리오에 따라, OD통행이 불가능한 경우에 대한 VT0 계산
							//if (isNoAccess) {
								//step10내 additional cost 계산시, 
								//통행불가시_추가비용(outputSummary->TR1 - outputSummary->TR0)
								//통행가능시_추가비용(outputSummary->VT1 - outputSummary->VT0)
								//OD zone이 2개 이상인 경우는 통행불가 와 통행가능인 OD zone이 존재하게 되어 이경우를 해결하기 위한 방안 필요
								//전체통행량 중, 통행가능교통량(outputSummary->VT1 - outputSummary->VT0)*VOT + 
								//통행불가교통량(outputSummary->TR1 - outputSummary->TR0)*Panelty 
								//따라서 통행불가 교통량을 즉 Vehicle in Network를 표현하는 방법을 DTALite에 표기필요

								//따라서 통행불가시 통행불가시_추가비용 만 발생하고, 통행가능시_추가비용은 발생하지 않게 하기위해 
								//다음과 같은 값을 할당함
								//outputSummary->TR1 = 0.0;
								outputSummary->TR1 = completedVehicle;
								//outputSummary->VT1 = outputSummary->VT0;
								outputSummary->VT1 = completedVehicle * averageTravelTime / 60.;
							//}
							//else {
							//	//outputSummary->TR1 = totalVehicle;
							//	outputSummary->TR1 = completedVehicle;
							//	outputSummary->VT1 = completedVehicle * averageTravelTime / 60.;
							//}


							//데미지단계(damage state)가 2이상(moderate damage)임에도 TR1=0인경우는 노선이 폐쇄된 것을 의미하며
							//노선이 폐쇄된다는 것은, 정상시의 TR0와 변화가 없는 것으로 가정한다.
							//단 노선폐쇄에 따른 변화는 모두 VT1에 반영됨
							//outputSummary->TR1 = cumulativeOutFlowCount; //기존코드
							//if (cumulativeOutFlowCount == 0) { outputSummary->TR1 = outputSummary->TR0; }
							//if (cumulativeOutFlowCount < outputSummary->TR0) { outputSummary->TR1 = outputSummary->TR0; }
							//else { outputSummary->TR1 = cumulativeOutFlowCount; }
							Debug::WriteLine(String::Format("[{0}:{1}] cumulative_out_flow_count={2}", outputSummary->ScenarioName, scenarioId, averageTravelTime));
						}

						if (outputLineData->IndexOf("--MOE Group 1--") >= 0) {
							if(isNoAccess == false){
								// find output
								i = i + 3; // 다음 2줄은 빈줄과 컬럼줄 제외
								// 데이터 줄을 찾으면 데이터 추출
								//double totalVT = 0; // total volume X time
								int length = 0;


								while (true) {
									if (i >= outputRowCount) {
										break;
									}
									outputLineData = dataArray[i];
									array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
									if (length == 0) {
										length = values->Length;
									}
									if (values->Length != length) {
										i--;
										break;
									}
									double vt = 0; // volume X time
									double volume = 0.0;
									double time = 0.0;

									// ID의 String형식은 "노선번호"-"시점노드번호"_"종점노드번호", 예) 1-5_6
									// 따라서 String을 분리하여 노선만 ID에 저장한다.
									// String^ ID = values[0];
									//String^ tempID = values[0];
									//array<String^>^ IDarray = values[0]->Split();
									array<String^>^ IDarray = CSVFileManager::Parse(values[0], "-");
									String^ ID = IDarray[0];



									Double::TryParse(values[1], volume); // #_of_vehicles
									Double::TryParse(values[4], time); // avg_travel_time
									outputSummary->AddVolume(ID, volume);
									outputSummary->AddTime(ID, time);
									if (time != 0) {
										vt = volume * (time / 60);
									}
									Debug::WriteLine(String::Format("[{0}:{1}] volume={2} time={3} vt={4}", outputSummary->ScenarioName, scenarioId, volume, time, vt));
									i = i + 1;
								}

								//if (isNoAccess) { outputSummary->VT1 = outputSummary->VT0 * 5.0; }
								//else { outputSummary->VT1 = totalVT; };							
								//Debug::WriteLine(String::Format("[{0}:{1}] add result: totalVT={2}", outputSummary->ScenarioName, scenarioId, totalVT));
								this->m_dataSet->NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
								//isNoAccess = false;
							}
							else{
								this->m_dataSet->NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
								//isNoAccess = false;
							}
						}
		
						//isFindOutput = false;
					}
				}
			}		
			return true;
		}

		// read output summary file
		bool ReadOutputSummaryFile(int odIndex) {
			CSVFileManager^ csv = gcnew CSVFileManager(m_basePath + "output_summary.csv");
			String^ output = csv->Read();

			if (!String::IsNullOrEmpty(output)) {
				array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
				int outputRowCount = dataArray->Length;
				Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));
				bool isNotDamagedData = true; // 첫번째는 무조건 정상 데이터
				double notDamagedTotalVT = 0; // 정상 데이터의 전체 통행시간 합계
				int notDamagedCumulativeOutFlowCount = 0; // 정상 데이터의 cumulative_out_flow_count
				int notDamangedTrafficNumber = 0;// 정상상태 통행차량대수 
				OutputSummary^ outputSummary = nullptr; // output summary object
				// output 찾았는지 여부 
				bool isFindOutput = false;
				String^ scenarioId = ""; // traffic scenarioNo + damage state

				//=========================================
				// 지진피해로 출발점 -> 도착점 이동 불가 판단
				//=========================================				
				bool isNoAccess = false; //이동불가판단 논리변수

				for (int i = 0; i < outputRowCount; i++)
				{
					String^ outputLineData = dataArray[i];
					//	find output line index
					if (outputLineData->IndexOf(String::Format("-----{0}", this->m_scenarioNamePrefix)) >= 0) {
						// find output first line of scenario group
						// ex) ----------------------test0----------------------
						String^ scenarioName = outputLineData->Trim()->Replace("-", ""); // scenario name만 가져오기 
						// prefix 삭제 하고 scenario Numer를 UnitScenarioNum*odIndex*10만큼 더함
						scenarioId = String::Format("{0}", (int::Parse(scenarioName->Replace(this->m_scenarioNamePrefix, "")) + m_dataSet->UnitScenarioNum*odIndex*10));
						outputSummary = gcnew OutputSummary();
						outputSummary->ScenarioName = scenarioName;
						Debug::WriteLine(String::Format("[{0}:{1}:{2}]", i, scenarioName, scenarioId));
						isFindOutput = true;
					}

					if (isFindOutput) {
						if (outputLineData->IndexOf("Assignment method=,Zone-based routing") >= 0) {
							// find output
							i = i + 2; // 다음 1줄은 컬럼줄 제외
							double averageTravelTime = 0;
							double totalVehicle = 0;
							double completedVehicle = 0;
							outputLineData = dataArray[i++];
							array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
							Double::TryParse(values[3], totalVehicle); // totalVehicle;0
							Double::TryParse(values[5], averageTravelTime); // averageTravelTime
							Double::TryParse(values[4], completedVehicle); // averageDistance;1
							if (values[4] == "0") { isNoAccess = true; } //"0"의 의미는 지진피해로 도로망으로 진입한 차량중 진출차량 전무
							else { isNoAccess = false; }

							if (isNotDamagedData) {
								notDamangedTrafficNumber = totalVehicle;
								notDamagedTotalVT = totalVehicle * averageTravelTime / 60.;
								isNotDamagedData = false;
							}

							outputSummary->TR0 = notDamangedTrafficNumber;
							outputSummary->VT0 = notDamagedTotalVT;

							outputSummary->TR1 = completedVehicle;
							outputSummary->VT1 = completedVehicle * averageTravelTime / 60.;
							Debug::WriteLine(String::Format("[{0}:{1}] cumulative_out_flow_count={2}", outputSummary->ScenarioName, scenarioId, averageTravelTime));
						}

						if (outputLineData->IndexOf("--MOE Group 1--") >= 0) {
							if (isNoAccess == false) {
								// find output
								i = i + 3; // 다음 2줄은 빈줄과 컬럼줄 제외
								// 데이터 줄을 찾으면 데이터 추출
								int length = 0;

								while (true) {
									if (i >= outputRowCount) {
										break;
									}
									outputLineData = dataArray[i];
									array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
									if (length == 0) {
										length = values->Length;
									}
									if (values->Length != length) {
										i--;
										break;
									}
									double vt = 0; // volume X time
									double volume = 0.0;
									double time = 0.0;
									array<String^>^ IDarray = CSVFileManager::Parse(values[0], "-");
									String^ ID = IDarray[0];

									Double::TryParse(values[1], volume); // #_of_vehicles
									Double::TryParse(values[4], time); // avg_travel_time
									outputSummary->AddVolume(ID, volume);
									outputSummary->AddTime(ID, time);
									if (time != 0) {
										vt = volume * (time / 60);
									}
									Debug::WriteLine(String::Format("[{0}:{1}] volume={2} time={3} vt={4}", outputSummary->ScenarioName, scenarioId, volume, time, vt));
									i = i + 1;
								}

								this->m_dataSet->NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
							}
							else {
								this->m_dataSet->NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
							}
						}
					}
				}
			}
			return true;
		}



		// read output summary file
		Dictionary<String^, OutputSummary^>^ ReadOutputSummaryFile(String^ filePath, int odIndex, Dictionary<String^, OutputSummary^>^ NeXTAOutputSummaryDictionary) {
			// step9에서 읽어 들이는 방식과 비슷하게 outputsummary 결과를 읽어들임
			//Dictionary<String^, OutputSummary^>^ NeXTAOutputSummaryDictionary;
			//NeXTAOutputSummaryDictionary = gcnew Dictionary<String^, OutputSummary^>();

			CSVFileManager^ csv = gcnew CSVFileManager(filePath);
			String^ output = csv->Read();
			if (!String::IsNullOrEmpty(output)) {
				array<String^>^ dataArray = output->Split(Environment::NewLine->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);
				int outputRowCount = dataArray->Length;
				Debug::WriteLine(String::Format("Number of output summary lines:{0}", outputRowCount));
				bool isNotDamagedData = true; // 첫번째는 무조건 정상 데이터
				double notDamagedTotalVT = 0; // 정상 데이터의 전체 통행시간 합계
				int notDamagedCumulativeOutFlowCount = 0; // 정상 데이터의 cumulative_out_flow_count
				int notDamangedTrafficNumber = 0;// 정상상태 통행차량대수 
				OutputSummary^ outputSummary = nullptr; // output summary object
				// output 찾았는지 여부 
				bool isFindOutput = false;
				String^ scenarioId = ""; // traffic scenarioNo + damage state

				//=========================================
				// 지진피해로 출발점 -> 도착점 이동 불가 판단
				//=========================================				
				bool isNoAccess = false; //이동불가판단 논리변수

				for (int i = 0; i < outputRowCount; i++)
				{
					String^ outputLineData = dataArray[i];
					//
					//	find output line index
					//
					if (outputLineData->IndexOf(String::Format("-----{0}", this->m_scenarioNamePrefix)) >= 0) {
						// find output first line of scenario group
						// ex) ----------------------test0----------------------
						String^ scenarioName = outputLineData->Trim()->Replace("-", ""); // scenario name만 가져오기 
						// prefix 삭제 하고 UnitScenarioNum을 더함
						scenarioId = String::Format("{0}", (int::Parse(scenarioName->Replace(this->m_scenarioNamePrefix, "")) + m_dataSet->UnitScenarioNum* 10 * odIndex)); 
						outputSummary = gcnew OutputSummary();
						outputSummary->ScenarioName = scenarioName;
						Debug::WriteLine(String::Format("[{0}:{1}:{2}]", i, scenarioName, scenarioId));
						isFindOutput = true;
					}

					if (isFindOutput) {
						if (outputLineData->IndexOf("Assignment method=,Zone-based routing") >= 0) {
							// find output
							//cumulativeOutFlowCount = 0;
							i = i + 2; // 다음 1줄은 컬럼줄 제외
							double averageTravelTime = 0;
							double totalVehicle = 0;
							double completedVehicle = 0;
							outputLineData = dataArray[i++];
							array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
							Double::TryParse(values[3], totalVehicle); // totalVehicle;0
							Double::TryParse(values[5], averageTravelTime); // averageTravelTime
							Double::TryParse(values[4], completedVehicle); // averageDistance;1

							if (values[4] == "0") { isNoAccess = true; } //"0"의 의미는 지진피해로 도로망으로 진입한 차량중 진출차량 전무
							else { isNoAccess = false; }

							if (isNotDamagedData) {
								//notDamagedCumulativeOutFlowCount = totalVehicle;
								notDamangedTrafficNumber = totalVehicle;
								notDamagedTotalVT = totalVehicle * averageTravelTime / 60.;
								isNotDamagedData = false;
							}

							outputSummary->TR0 = notDamangedTrafficNumber;
							outputSummary->VT0 = notDamagedTotalVT;
							outputSummary->TR1 = completedVehicle;
							outputSummary->VT1 = completedVehicle * averageTravelTime / 60.;
							Debug::WriteLine(String::Format("[{0}:{1}] cumulative_out_flow_count={2}", outputSummary->ScenarioName, scenarioId, averageTravelTime));
						}

						if (outputLineData->IndexOf("--MOE Group 1--") >= 0) {
							if (isNoAccess == false) {
								// find output
								i = i + 3; // 다음 2줄은 빈줄과 컬럼줄 제외
								// 데이터 줄을 찾으면 데이터 추출
								int length = 0;

								while (true) {
									if (i >= outputRowCount) {
										break;
									}
									outputLineData = dataArray[i];
									array<String^>^ values = CSVFileManager::Parse(outputLineData, ",");
									if (length == 0) {
										length = values->Length;
									}
									if (values->Length != length) {
										i--;
										break;
									}
									double vt = 0; // volume X time
									double volume = 0.0;
									double time = 0.0;

									// ID의 String형식은 "노선번호"-"시점노드번호"_"종점노드번호", 예) 1-5_6
									// 따라서 String을 분리하여 노선만 ID에 저장한다.
									array<String^>^ IDarray = CSVFileManager::Parse(values[0], "-");
									String^ ID = IDarray[0];

									Double::TryParse(values[1], volume); // #_of_vehicles
									Double::TryParse(values[4], time); // avg_travel_time
									outputSummary->AddVolume(ID, volume);
									outputSummary->AddTime(ID, time);
									if (time != 0) {
										vt = volume * (time / 60);
									}
									Debug::WriteLine(String::Format("[{0}:{1}] volume={2} time={3} vt={4}", outputSummary->ScenarioName, scenarioId, volume, time, vt));
									i = i + 1;
								}

								NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
							}
							else {
								NeXTAOutputSummaryDictionary->Add(scenarioId, outputSummary);
								isFindOutput = false;
							}
						}
						//isFindOutput = false;
					}
				}
			}
			return NeXTAOutputSummaryDictionary;
		}






	};
}