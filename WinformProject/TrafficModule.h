#pragma once
#include <math.h>
#include "ShapeProperty.h"
#include "FragilityCurve.h"
#include "TrafficScenario.h"
#include "ComponentInfo.h"
#include "NetworkComponent.h"
#include "NeXTAHelper.h""

namespace WinformProject {
	/// <summary>
	/// traffic class
	/// </summary>
	public ref class TrafficModule
	{
	private:
		static double const DAMAGE_PROBABILITY_THRESHOLD = 0.5; // 50% �̻�

		ProjectDataSetBinder^		m_dataSet;
		FragilityCurve^				m_fragilityCurve;
		double						m_totalTrafficVolume; // ��� link�� �� ���� ���뷮
		double						m_totalTrafficTime; // ��� link�� �� �ҿ�ð�
		NetworkComponent^			m_networkComponent;
	public:
		TrafficModule(ProjectDataSetBinder^ dataSet) {
			this->m_dataSet = dataSet;
			this->m_fragilityCurve = gcnew FragilityCurve(m_dataSet->FragParameterData);
			this->m_totalTrafficVolume = 0.0;
			this->m_totalTrafficTime = 0.0;
			for (int i = 0; i < m_dataSet->ShapeData->m_SHPProperties->Length; i++)
			{
				ShapeProperty^ prop = m_dataSet->ShapeData->m_SHPProperties[i];
				this->m_totalTrafficVolume += prop->DailyTrafficVolume;
				this->m_totalTrafficTime += prop->Time;
			}
			this->m_networkComponent = gcnew NetworkComponent(this->m_dataSet);
		}
	public:
		// ��� link�� �� ���� ���뷮
		property double TotalTrafficVolume {
			double get() {
				return this->m_totalTrafficVolume;
			}
		}
		// ��� link�� �� �ҿ�ð�
		property double TotalTrafficTime {
			double get() {
				return this->m_totalTrafficTime;
			}
		}

	public:
		// damage state�� ���� ��ũ ��
		static array<int>^ GetClosedLinkCount(TrafficScenario^ trafficScenario, int damageStateCount) {
			array<int>^ closedLink = gcnew array<int>(damageStateCount); // damage state(1~4)
			// initialize
			for (int i = 0; i < closedLink->Length; i++)
			{
				closedLink[i] = 0;
			}

			/*
			for each (ComponentInfo component in trafficScenario->Components)
			{
				int ds = component.MaxDamageState;
				// damage state 0 �ʰ��� ��츸 ���� damage state ��� ���� 
				while (ds > 0) {
					closedLink[ds - 1]++;
					ds--;
				}
			}
//			return closedLink;
			*/
			
			Dictionary<String^, int>^ linkIDAndDamageStateDic = gcnew Dictionary<String^, int>();
			for each (ComponentInfo component in trafficScenario->Components)
			{
				if (linkIDAndDamageStateDic->ContainsKey(component.LinkID)) {
					// �� ��ũ�� ������Ʈ�� ������ �� �� �ֱ⶧���� 
					// ��ϵ� ��ũ�� �̹� ������ ���� damage state�� ���ؼ� �� ū �������� �ݿ�
					if (linkIDAndDamageStateDic[component.LinkID] < component.MaxDamageState) {
						linkIDAndDamageStateDic[component.LinkID] = component.MaxDamageState;
					}
				}
				else {
					// ��ũ�� ������ �߰�
					linkIDAndDamageStateDic->Add(component.LinkID, component.MaxDamageState);
				}
			}

			for each (String^ sIndex in linkIDAndDamageStateDic->Keys){
				int ds = linkIDAndDamageStateDic[sIndex];
				// damage state 0 �ʰ��� ��츸 ���� damage state ��� ���� 
				while (ds > 0) {
					closedLink[ds - 1]++;
					ds--;
				}
			}
			return closedLink;
		}

	public:
		// generate traffic scenarios
		// case 1(monte cario count == 1): 
		//		
		// case 2 or higher(monte cario count >= 2): 
		// �� ������Ʈ�� damage state�� �������� �����ؼ� 
		// �ش� ��ġ�� damage probablilty�� threshold �̻��� ��� �������� ���� �� damage state�� ����

		bool GenerateScenarios() {
			// ��ü �ó����� ��
			int totalTrafficScenarioCount = this->m_dataSet->TotalTrafficScenarioCount;

			Debug::WriteLine(String::Format("Total number of traffic scenario={0}", totalTrafficScenarioCount));

			Random^ rand = gcnew Random();
			// �ó�����(���)
			int scenarioIndex = 0;
			// �����ҽ� index
			int sourceIndex = 0;

			// ��ü traffic scenario
			array<TrafficScenario^>^ resultTrafficScenarios = gcnew array<TrafficScenario^>(totalTrafficScenarioCount);


			// ODIndex = OD zone ����: ó�� ���۽� ODZoneParamData�� Ȱ��ȭ ���� ���� �ܰ�� 
			// �⺻������ ODIndex = 0 �� �¾�
			int ODIndex;
			if (m_dataSet->ODZoneParamData->Rows->Count < 1) {
				ODIndex = 0;
			}
			else {
				ODIndex = m_dataSet->ODZoneParamData->Rows->Count;
			}

			// ������Ʈ�� �ջ� ����
			String^ sourceName = "";
			String^ recurrencePeriodName = "";
			//int recurrencePeriodIndex = 0;
			int sample = 1;
			// threshold �̻��� ������Ʈ�� �ִ� damage state
			int maxDamageState = 0;
			// �ִ� damage probability
			double maxDamageProbability = 0.0;

			// component count
			int componentCount = m_networkComponent->GetCount();


			if (ODIndex==0) {
				array<ComponentInfo>^ components = nullptr;
				int sourceIndex = 0;

				// source
				for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary)
				{
					DataTable^ sourceTable = pair->Value;
					///////////////////////////////////////////
					/// CASE 1:
					///////////////////////////////////////////
					sample = 1;
					sourceName = pair->Key;
					Debug::WriteLine(String::Format("CASE 1: source=[{0}]{1} sample={2}", sourceIndex, sourceName, sample));


					// ���شܰ躰 Repair Ratio ����
					array <double>^ repairRatio = gcnew array<double>(m_fragilityCurve->DamageStateCount);
					// repair ratio ����
					repairRatio[1] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1;
					repairRatio[2] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2;
					repairRatio[3] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3;
					repairRatio[4] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4;

					// ���� ����
					array <double>^ damageCriteria = gcnew array<double>(m_fragilityCurve->DamageStateCount);
					// repair ratio ����
					damageCriteria[1] = 0.5 * (repairRatio[0] + repairRatio[1]);
					damageCriteria[2] = 0.5 * (repairRatio[1] + repairRatio[2]);
					damageCriteria[3] = 0.5 * (repairRatio[2] + repairRatio[3]);
					damageCriteria[4] = 0.5 * (repairRatio[3] + repairRatio[4]);


					// Ư�� ������Ʈ�� max damage probability and max damage state�� ���Ѵ�.
					for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++)
					{
						components = gcnew array<ComponentInfo>(componentCount);
						for (int compIndex = 0; compIndex < componentCount; compIndex++)
						{
							String^ compID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_NETWORK_COMP_ID);
							String^ classID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_CLASS_ID);
							String^ xPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_X);
							String^ yPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_Y);
							String^ linkID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_LINK_ID);
							String^ filter = "[" + CommConst::GRID_SEISMIC_SOURCES_COL1 + "]='" + xPos + "' and [" + CommConst::GRID_SEISMIC_SOURCES_COL2 + "] = '" + yPos + "'";
							array<DataRow^>^ foundRows = sourceTable->Select(filter);
							if (foundRows->Length == 0) {
								Debug::WriteLine("Can not find source data.");
								return false;
							}
							DataRow^ sourceRow = foundRows[0];
							maxDamageState = 0;
							maxDamageProbability = 0.0;
							double sa = 0;
							double damageProbability = 0.0;

							// ���شܰ谡 �߻��� �� �ִ� Ȯ�� ����
							array <double>^ probabilityDamageState= gcnew array<double>(m_fragilityCurve->DamageStateCount);

							// recurrence period�� Ư�� ������Ʈ�� ���� ������ ����
							Double::TryParse(sourceRow[2 + recurIndex]->ToString(), sa); // 3(index=2)��°���� damage state 1,2,3,4�� ����
							for (int damageState = 1; damageState < m_fragilityCurve->DamageStateCount; damageState++) // damage state 0�� ����
							{
								//								recurrencePeriodIndex = recurIndex;
								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();
								damageProbability = m_fragilityCurve->GetFragilityValue(classID, damageState, sa);

								probabilityDamageState[damageState] = damageProbability;

								if (maxDamageProbability < damageProbability) {
									// ���� Ȯ���� ���� ��쿡�� ������Ʈ
									maxDamageProbability = damageProbability;
								}

/*
								// �ִ� ���شܰ� ���
								if (damageProbability < DAMAGE_PROBABILITY_THRESHOLD) {
									// threshold�� ������ �׸�(�׳� damage state 0)
									break;
								}
								else {
									// threshold�� ������ damage�� �ִٰ� �Ǵ��Ͽ� ���� damage state�� ����
									maxDamageState = damageState;
								}
*/

							}

///*
							// ����: �ü����� �ִ� ���شܰ�� ��൵����� ���� ���� ���شܰ躰 Ȯ���� 50%�� �Ѵ� ���شܰ� �߿�, �ְ�ܰ踦 �ִ����شܰ�� ����
							// ����: ���ܰ躰 Ȯ�� �� �ִ밪�� �ü��� �ִ����ط� ���  
							double sumDamage = 0.0;
							for (int i = 0; i <= CommConst::DAMAGE_STATE_COUNT; i++) {
								if(i==0){
									damageCriteria[i] = (1-probabilityDamageState[i+1]);
								}
								if (i > 0 && i < CommConst::DAMAGE_STATE_COUNT) {
									damageCriteria[i] = (probabilityDamageState[i] - probabilityDamageState[i+1]);
								}
								if (i == CommConst::DAMAGE_STATE_COUNT) {
									damageCriteria[i] = (probabilityDamageState[i]);
								}
							}

							// ����: ���ܰ躰 Ȯ�� �� �ִ밪�� �ü��� �ִ����ط� ���  
							double temp=0;
							for (int stateIndex = 0; stateIndex <= CommConst::DAMAGE_STATE_COUNT; stateIndex++) {
								if (damageCriteria[stateIndex] > temp) {
									temp = damageCriteria[stateIndex];
									maxDamageState = stateIndex;
								}
							}

							if (maxDamageState == 0 && probabilityDamageState[1] > DAMAGE_PROBABILITY_THRESHOLD) {
								maxDamageState = 1;
							}

//*/



							Debug::WriteLine(String::Format("\trecurrence period={0} compnent_id={1}, max probability={2}, max damage state={3}", recurrencePeriodName, compID, maxDamageProbability, maxDamageState));
							ComponentInfo ci;
							ci.ComponentID = compID;
							ci.ClassID = classID;
							Double::TryParse(xPos, ci.ComponentX);
							Double::TryParse(yPos, ci.ComponentY);
							ci.LinkID = linkID;
							ci.MaxDamageProbability = maxDamageProbability;
							ci.MaxDamageState = maxDamageState;
							components[compIndex] = ci;
						}
						//resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName, sourceIndex, recurrencePeriodName, recurrencePeriodIndex, sample, components);
						resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
							sourceIndex, recurrencePeriodName, recurIndex, sample, components, ODIndex+1);
						scenarioIndex++;
					}

					///////////////////////////////////////////
					/// CASE 2 or higher:
					///////////////////////////////////////////
					while (sample < m_dataSet->MonteCarioCount) {
						sample++;
						Debug::WriteLine(String::Format("CASE 2 or higher: source=[{0}]{1} sample={2}", sourceIndex, sourceName, sample));
						// Ư�� ������Ʈ�� max damage probability and max damage state�� ���Ѵ�.
						for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++)
						{
							components = gcnew array<ComponentInfo>(componentCount);
							for (int compIndex = 0; compIndex < componentCount; compIndex++)
							{
								String^ compID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_NETWORK_COMP_ID);
								String^ classID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_CLASS_ID);
								String^ xPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_X);
								String^ yPos = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_Y);
								String^ linkID = m_networkComponent->GetValue(compIndex, NetworkComponent::COL_LINK_ID);
								String^ filter = "[" + CommConst::GRID_SEISMIC_SOURCES_COL1 + "]='" + xPos + "' and [" + CommConst::GRID_SEISMIC_SOURCES_COL2 + "] = '" + yPos + "'";
								array<DataRow^>^ foundRows = sourceTable->Select(filter);
								if (foundRows->Length == 0) {
									Debug::WriteLine("Can not find source data.");
									return false;
								}
								DataRow^ sourceRow = foundRows[0];
								maxDamageState = 0;
								maxDamageProbability = 0.0;
								double sa = 0;
								// recurrence period�� Ư�� ������Ʈ�� ���� ������ ����
								Double::TryParse(sourceRow[2 + recurIndex]->ToString(), sa); // 3(index=2)��°���� damage state 1,2,3,4�� ����
								//recurrencePeriodIndex = recurIndex;
								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// �������� ���� damage state�� ����
								// fragility �Լ��� ���� �������� ���� 0.00~1.00���� �Ҽ��� 2�ڸ��� ����ȭ �ϰ�, 
								// ���شܰ躰(damage state) Ȯ���� ������ �����Ѵ�.
								// �Ʒ��� �����Լ��� ���� 1~100���� ���� �߻����� ���شܰ躰 Ȯ���� ������ ���ϰ�
								// �������� �������� �ִ� ���شܰ踦 �ش� �������� ���شܰ�� �����Ѵ�. 
								double dsProbability;
								maxDamageState = 0;
								double dsRandom = static_cast<double>(rand->Next(1, 101)) / 100.0;
								//for (int ds = 1; ds < m_fragilityCurve->DamageStateCount; ds++) {
								for (int ds = 0; ds < m_fragilityCurve->DamageStateCount; ds++) {
									dsProbability = m_fragilityCurve->GetFragilityValue(classID, ds, sa);
									if (dsRandom > dsProbability) {
										maxDamageState = ds;
										break;
									}
									//else if (ds == m_fragilityCurve->DamageStateCount - 1) {
									//	maxDamageState = m_fragilityCurve->DamageStateCount - 1;
									//}
								}
								// Damage State i ���� j ������ ���� ����ǥ�� �߻���Ű�� ���� �Լ��� 
								// rand->Next(i,j+1)�� ����. ������ ���� (j)�� �ƴ϶� (j+1)�� ��� ���̴�.
	/*							int damageState = rand->Next(1, 4);
								damageProbability = m_fragilityCurve->GetFragilityValue(classID, damageState, sa);
								if (maxDamageProbability < damageProbability) {
									// ���� Ȯ���� ���� ��쿡�� ������Ʈ
									maxDamageProbability = damageProbability;
								}
								if (damageProbability < DAMAGE_PROBABILITY_THRESHOLD) {
									// threshold�� ������ �׸�(�׳� damage state 0)
									maxDamageState = 0;
								}
								else {
									// threshold�� ������ damage�� �ִٰ� �Ǵ��Ͽ� ���� damage state�� ����
									maxDamageState = damageState;
								}
	*/
								Debug::WriteLine(String::Format("\trecurrence period={0} compnent_id={1}, max probability={2}, max damage state={3}", recurrencePeriodName, compID, maxDamageProbability, maxDamageState));
								ComponentInfo ci;
								ci.ComponentID = compID;
								ci.ClassID = classID;
								Double::TryParse(xPos, ci.ComponentX);
								Double::TryParse(yPos, ci.ComponentY);
								ci.LinkID = linkID;
								//maxDamageProbability�� �̹� sample1���� ���������Ƿ�, ���⼭ �ٽ� ���� �ʿ�� ����.
								//ci.MaxDamageProbability = maxDamageProbability;
								ci.MaxDamageState = maxDamageState;
								components[compIndex] = ci;
							}
							//resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName, sourceIndex, recurrencePeriodName, recurrencePeriodIndex, sample, components);
							resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
								sourceIndex, recurrencePeriodName, recurIndex, sample, components, ODIndex+1);
							scenarioIndex++;
						}
					}
					sourceIndex++;
				}

			}

			else {
				// �ó����� ��ȣ�� ODIndex=0 �� �����Ͽ� �����ǹǷ�, ODIndex=0���� ������ �ó�������ȣ �������� ��ȣ����. 
				//scenarioIndex = this->m_dataSet->TrafficScenarios->Length;
			
				// ������ ������ ���� OD�� ���õ� �ó����� ���� ����
				//for (int i = 0; i < scenarioIndex; i++) {
				//	resultTrafficScenarios[i] = this->m_dataSet->TrafficScenarios[i];
				//}

				// ���� �ڵ忡���� OD ���� ��ŭ �ó������� �߰��ϴ� ������ �Ǿ� ������, ������ �ó����� OD�� �������.
				// ���� �ӽ÷� ������ �ó������� OD���� ��ŭ ������. ���� �����ʿ�
				//for (int odIndex = 1; odIndex < ODIndex; odIndex++) {


				// 3���õ�
				scenarioIndex = 0;

				// OD index
				for (int odIndex = 0; odIndex < ODIndex; odIndex++) {
					int compoIndex = 0;

				
					// �����ҽ� index
					sourceIndex = 0;
					for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary) {
						sourceName = pair->Key;
						array<ComponentInfo>^ components = nullptr;

						for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {

							for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {

								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// component ����
								TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[compoIndex];
								components = scenario->Components;

								resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
									sourceIndex, recurrencePeriodName, recurIndex, sample + 1, components, odIndex + 1);

								scenarioIndex++; // ��ü�ó����� Index (0 ~ �ҽ�*�ֱ�*����*OD)

								compoIndex++; // OD���� ���Ӱ� ���۵� (0~ �ҽ�*�ֱ�*����)


							}

						}

						sourceIndex++;

					}
	
						
				}




				// 2���õ�
				/*
				for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary) {
					sourceName = pair->Key;
					int compoIndex = 0;
					array<ComponentInfo>^ components = nullptr;



					//for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {
					for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {

						//for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {
						for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {
						
							for (int odIndex = 0; odIndex < ODIndex; odIndex++) {


								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// component ����
								// int scenarioNum = 
								TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[compoIndex];
								components = scenario->Components;


								//resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
								//	sourceIndex, recurrencePeriodName, recurIndex, sample, components, odIndex + 1);

								resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
									sourceIndex, recurrencePeriodName, recurIndex, sample + 1, components, odIndex + 1);

								scenarioIndex++;
								//compoIndex++;



							}
							compoIndex++;
					
						
						}



					}



					sourceIndex++;




				}
				*/





				// 1���õ�
				/*
				for (int odIndex = 0; odIndex < ODIndex; odIndex++) {

					int compoIndex = 0;
					array<ComponentInfo>^ components = nullptr;


					// �̸� ��Ī

					for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary) {
						sourceName = pair->Key;


						for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {


							for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {

								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// component ����
								TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[compoIndex];
								components = scenario->Components;


								//resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
								//	sourceIndex, recurrencePeriodName, recurIndex, sample, components, odIndex + 1);

								resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
									sourceIndex, recurrencePeriodName, recurIndex, sample + 1, components, odIndex + 1);

								scenarioIndex++;
								compoIndex++;
							}

						}


						sourceIndex++;

					}






				}
				*/
			}

			this->m_dataSet->TrafficScenarios = resultTrafficScenarios;
			return true;
		}


		/*
			calculate economic loss indices
			ECOp	: p�ܰ迡���� ���� �ս�����
			ntot	: �� �뼱 ��
			Vj,p	: �뼱 j�� p�ܰ迡���� ���뷮
			tj,p	: �뼱 j�� p�ܰ迡���� �뼱����ð�
			Vj,p	: �뼱 j�� ���� �� ���뷮
			tj,p	: �뼱 j�� ���� �� �뼱����ð�
		*/
		double CalEconomicLossIndices(int trafficVolume, double trafficTime, int refVehicleCount, double refTime) {
			double totalTime = trafficVolume * trafficTime;
			double refTotalTime = refVehicleCount * refTime;
			return refTotalTime / totalTime;
		}
		/*
			calculate economic loss indices
			ECOp	: p�ܰ迡���� ���� �ս�����
			ntot	: �� �뼱 ��
			Vj,p	: �뼱 j�� p�ܰ迡���� ���뷮
			tj,p	: �뼱 j�� p�ܰ迡���� �뼱����ð�
			Vj,p	: �뼱 j�� ���� �� ���뷮
			tj,p	: �뼱 j�� ���� �� �뼱����ð�
		*/
		double CalEconomicLossIndices(int trafficVolume, double trafficTime) {
			double totalTime = trafficVolume * trafficTime;
			double refTotalTime = this->m_totalTrafficVolume * this->m_totalTrafficTime;
			return refTotalTime / totalTime;
		}

		DataRow^ CalConnectLossIndices(array<ShapeProperty^>^ links, DataRow^ newRow) {
			double sumLz0 = 0.0; // total length of link
			double sumLzp = 0.0; // total length of closed link
			for (int j = 0; j < links->Length; j++) {		//links[i]->Length�� �ش籸���� ���Ե� �� �뼱(link)����
				ShapeProperty^ prop = links[j];
				sumLz0 += prop->Length;
				if (prop->IsClose) {
					sumLzp += prop->Length;
				}
			}
//			newRow["Lzp"] = (double::Parse(newRow["Lzp"]->ToString()) + sumLzp);
			newRow["Lz0"] = sumLz0;
			newRow["Lzp"] = sumLzp;
			return newRow;
		}

		// ���� ���¿����� �����ؼ������ �м��Ͽ� ȯ�������� ����ϴ� �Լ�
		double CalEnvironmentLossIndices(ShapeProperty^ links, TrafficScenario^ scenario, int damageState) {
			if (links == nullptr) {
				return 0.0;
			}
			/*
			// excel�� �ִ� ���� �״�� ���������¿� ���� ����� ����
			double DDT = 0.0;
			double DT = 0.0;
			switch (damageState)
			{
			case 1:
				DDT = 0.82;
				DT = 2.5;
				break;
			case 2:
				DDT = 0.85;
				DT = 1.8;
				break;
			case 3:
				DDT = 0.9;
				DT = 1.4;
				break;
			default: // 4~
				DDT = 1;
				DT = 1;
				break;
			}
			double totalLj = 0.0;
			double totalAjpLj = 0.0;
			for (int i = 0; i < links->Length; i++)
			{
				ShapeProperty^ prop = links[i];
				double Lj = prop->Length * prop->EnvSensRate;
				double dailyTrafficAfterDamage = prop->DailyTrafficVolume * DDT;
				double timeAfterDamage = prop->Time * DT;
				double trafficWeight = prop->DailyTrafficVolume * prop->Time;
				double trafficWeightAfterDamage = dailyTrafficAfterDamage * timeAfterDamage;
				double Ajp = trafficWeightAfterDamage / trafficWeight;
				double AjpLj = Ajp * Lj;
				totalLj += Lj;
				totalAjpLj += AjpLj;
			}
			return totalLj / totalAjpLj;
			*/

			// ȯ�� �ΰ������� ���������� �ش�뼱�� OD(Origin, Destination)�� �ش��ϴ� ���뷮�� �߻����� ������, 
			// �����Ŀ��� ���뷮�� �߻��ϴ� ��츦 ������� �Ͽ�����,
			// �������� ���뷮�� �⺻���෮ TR0�� ������ 
			String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);
			OutputSummary^ outputSummary = nullptr;
			OutputSummary^ norOutputSummary = nullptr;
			if (this->m_dataSet->NeXTAOutputSummaryDictionary->ContainsKey(key)) {
				outputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[key];
			}


			//this->m_dataSet->JumpScenarioNum = this->m_dataSet->MonteCarioCount *	this->m_dataSet->SeismicSourceData->Rows->Count * this->m_dataSet->RecurrencePeriodData->Length;

			//int unitScenarioStep = this->m_dataSet->JumpScenarioNum;
			int unitScenarioStep = this->m_dataSet->UnitScenarioNum;

			int currentScenarioNumber = scenario->TrafficScenarioNo;
			double temp = (currentScenarioNumber) / (unitScenarioStep);
			String^ normScenarioIndex = String::Format("{0}", int((currentScenarioNumber) / (unitScenarioStep) * (unitScenarioStep * 10)));

			norOutputSummary = this->m_dataSet->NeXTAOutputSummaryDictionary[normScenarioIndex];


			double EnvRate = 0.0;
			double beforeVolume = 0.0;
			double afterVolume = 0.0;
			//String^ filter1 = links[i]->ID + "-" + links[i]->Nodes[0]->ID + "_" + links[i]->Nodes[1]->ID;
			//String^ filter2 = links[i]->ID + "-" + links[i]->Nodes[1]->ID + "_" + links[i]->Nodes[0]->ID;
			//String^ filter1 = links->ID + "-" + links->Nodes[0]->ID + "_" + links->Nodes[1]->ID;
			//String^ filter2 = links->ID + "-" + links->Nodes[1]->ID + "_" + links->Nodes[0]->ID;

			//array<String^>^ links = gcnew array<String^>(norOutputSummary->Volumes->Count);

			//array<String^ >^ temp = norOutputSummary->Volumes->Keys->ToString[1];



/*
			if (norOutputSummary->Volumes[filter1] == 0 && norOutputSummary->Volumes[filter2] == 0) {
				beforeVolume = norOutputSummary->TR0;  //������ ���뷮�� �⺻���෮
				if (outputSummary != nullptr) {
					//�������뿡�� O/D���� ������ ������, �������ط� �߰��� ������ �߻��ϱ� ������ ū ������ �ִ�.
					afterVolume = beforeVolume + outputSummary->Volumes[filter1] + outputSummary->Volumes[filter2];
				}
			}
			else {
				beforeVolume = norOutputSummary->Volumes[filter1] + norOutputSummary->Volumes[filter2];
				if (outputSummary != nullptr) {
					//������ O/D���� ������ �����Ͽ����Ƿ�, �߰��߻����뷮�� ���� ȯ�濵���� ��������� ����.
					afterVolume = outputSummary->Volumes[filter1] + outputSummary->Volumes[filter2];
				}
			}
*/

			//���� �� �ش� �뼱�� ���뷮�� �߻����� �ʴ� ���
			//if (norOutputSummary->Volumes->ContainsKey(filter1) == false && norOutputSummary->Volumes->ContainsKey(filter2) == false) {
			if (norOutputSummary->Volumes->ContainsKey(links->ID) == false ) {
					//���� �� ���뷮 �Ҵ�
				beforeVolume = norOutputSummary->TR0;  //������ ���뷮�� �⺻���෮
				//���� �� ���뷮 �Ҵ�
				//�������뿡�� O/D���� ������ ������, �������ط� �߰��� ������ �߻��ϱ� ������ ū ������ �ִ�.
				if (outputSummary != nullptr) {
					//if (outputSummary->Volumes->ContainsKey(filter1) || outputSummary->Volumes->ContainsKey(filter2)) {
					if (outputSummary->Volumes->ContainsKey(links->ID)) {
					afterVolume = beforeVolume;
						//if (outputSummary->Volumes->ContainsKey(filter1)) { afterVolume += outputSummary->Volumes[filter1]; }
						//if (outputSummary->Volumes->ContainsKey(filter2)) { afterVolume += outputSummary->Volumes[filter2]; }
						if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume += outputSummary->Volumes[links->ID]; }
					}
				}
				else {
					afterVolume = beforeVolume;
				}
			}
			//���� �� �ش� �뼱�� ���뷮�� �߻��ϴ� ���
			else {
				//���� �� ���뷮 �Ҵ�
				//if (norOutputSummary->Volumes->ContainsKey(filter1)) { beforeVolume = norOutputSummary->Volumes[filter1]; }
				//if (norOutputSummary->Volumes->ContainsKey(filter2)) { beforeVolume += norOutputSummary->Volumes[filter1]; }
				if (norOutputSummary->Volumes->ContainsKey(links->ID)) { beforeVolume += norOutputSummary->Volumes[links->ID]; }
				//���� �� ���뷮 �Ҵ�
				if (outputSummary != nullptr) {
					//if (outputSummary->Volumes->ContainsKey(filter1)) { afterVolume = outputSummary->Volumes[filter1]; }
					//if (outputSummary->Volumes->ContainsKey(filter2)) { afterVolume += outputSummary->Volumes[filter2]; }
					if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume += outputSummary->Volumes[links->ID]; }
					if (afterVolume < beforeVolume) { afterVolume = beforeVolume; } //������ �������� ���뷮�� ���������� ���� �߻��ϴ� ���, EnvRate = 1.0 �Ҵ�.
				}
				else {
					afterVolume = beforeVolume;
				}
			}

			// Volumes(filter1) = 0 �Ǵ� Volumes(filter2) = 0 �� �Ǹ�, ���ÿ� 0 �̻�Ǵ� ���� ������ ���� ����.
				//EnvRate = EnvRate + (links[i]->Length) / (afterVolume / beforeVolume * links[i]->Length);
				//EnvRate = EnvRate + (links->Length) / (afterVolume / beforeVolume * links->Length);
			
//			if (beforeVolume != 0) {
				EnvRate = afterVolume / beforeVolume;
//			}
//			else { EnvRate = 1.0; }

			if(EnvRate != 0) { return EnvRate; }
			else { return 1.0; } //Envrate�� ��ȭ�� ���ٴ� ����, ȯ��ΰ������� �������� ����(rate=1)�� �ǹ��� 
		}

		// ����������(����) �Ǵ� ����������(����)�� �����ؼ� �����ؼ������ �м��Ͽ� ȯ�������� ����ϴ� �Լ�
		// ������: OutputSummaryDictionary = beforeNextOutputSummaryDictionary
		// ������: OutputSummaryDictionary = NextOutputSummaryDictionary
		double CalEnvironmentLossIndices(Dictionary<String^, OutputSummary^>^ OutputSummaryDictionary, ShapeProperty^ links, TrafficScenario^ scenario, int damageState, int unitScenarioStep) {
			if (links == nullptr) {
				return 0.0;
			}

			// ȯ�� �ΰ������� ���������� �ش�뼱�� OD(Origin, Destination)�� �ش��ϴ� ���뷮�� �߻����� ������, 
			// �����Ŀ��� ���뷮�� �߻��ϴ� ��츦 ������� �Ͽ�����,
			// �������� ���뷮�� �⺻���෮ TR0�� ������ 
			String^ key = NeXTAHelper::GetScenarioId(scenario->TrafficScenarioNo, damageState);
			OutputSummary^ outputSummary = nullptr;
			OutputSummary^ norOutputSummary = nullptr;
			if (OutputSummaryDictionary->ContainsKey(key)) {
				outputSummary = OutputSummaryDictionary[key];
			}

			int currentScenarioNumber = scenario->TrafficScenarioNo;
			//double temp = (currentScenarioNumber) / (unitScenarioStep);
			String^ normScenarioIndex = String::Format("{0}", int((currentScenarioNumber) / (unitScenarioStep) * (unitScenarioStep * 10)));

			norOutputSummary = OutputSummaryDictionary[normScenarioIndex];

			double EnvRate = 0.0;
			double beforeVolume = 0.0;
			double afterVolume = 0.0;

			//���� �� �ش� �뼱�� OD���� ���뷮�� �߻����� �ʴ� ���
			if (norOutputSummary->Volumes->ContainsKey(links->ID) == false) {
				//���� �� ���뷮 �Ҵ�
				beforeVolume = norOutputSummary->TR0;  //������ ���뷮�� �⺻���෮
				//���� �� ���뷮 �Ҵ�
				//�������뿡�� O/D���� ������ ��������, �������ط� �߰��� ������ �߻��ϱ� ������ ū ������ �ִ�.
				if (outputSummary != nullptr) {
					if (outputSummary->Volumes->ContainsKey(links->ID)) {
						afterVolume = beforeVolume + outputSummary->Volumes[links->ID];
						//if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume += outputSummary->Volumes[links->ID]; }
					}
					else{ afterVolume = beforeVolume; }
				}
				else { afterVolume = beforeVolume; }
			}
			//���� �� �ش� �뼱�� ���뷮�� �߻��ϴ� ���
			else {
				//���� �� ���뷮 �Ҵ�
				//if (norOutputSummary->Volumes->ContainsKey(links->ID)) { beforeVolume += norOutputSummary->Volumes[links->ID]; }
				 beforeVolume = norOutputSummary->Volumes[links->ID];
				//���� �� ���뷮 �Ҵ�
				if (outputSummary != nullptr) {
					if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume = outputSummary->Volumes[links->ID]; }
					if (afterVolume < beforeVolume) { afterVolume = beforeVolume; } //������ �������� ���뷮�� ���������� ���� �߻��ϴ� ���, EnvRate = 1.0 �Ҵ�.
				}
				else {
					afterVolume = beforeVolume;
				}
			}
			// Volumes(filter1) = 0 �Ǵ� Volumes(filter2) = 0 �� �Ǹ�, ���ÿ� 0 �̻�Ǵ� ���� ������ ���� ����.
			EnvRate = afterVolume / beforeVolume;

			if (EnvRate != 0) { return EnvRate; }
			else { return 1.0; } //Envrate�� ��ȭ�� ���ٴ� ����, ȯ��ΰ������� �������� ����(rate=1)�� �ǹ��� 
		}

















	};
}