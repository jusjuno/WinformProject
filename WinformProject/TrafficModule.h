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
		static double const DAMAGE_PROBABILITY_THRESHOLD = 0.5; // 50% 이상

		ProjectDataSetBinder^		m_dataSet;
		FragilityCurve^				m_fragilityCurve;
		double						m_totalTrafficVolume; // 모든 link의 총 차량 수용량
		double						m_totalTrafficTime; // 모든 link의 총 소요시간
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
		// 모든 link의 총 차량 수용량
		property double TotalTrafficVolume {
			double get() {
				return this->m_totalTrafficVolume;
			}
		}
		// 모든 link의 총 소요시간
		property double TotalTrafficTime {
			double get() {
				return this->m_totalTrafficTime;
			}
		}

	public:
		// damage state별 닫힌 링크 수
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
				// damage state 0 초과일 경우만 하위 damage state 모두 증가 
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
					// 한 링크에 컴포넌트가 여러개 일 수 있기때문에 
					// 등록된 링크가 이미 있으면 기존 damage state와 비교해서 더 큰 데미지로 반영
					if (linkIDAndDamageStateDic[component.LinkID] < component.MaxDamageState) {
						linkIDAndDamageStateDic[component.LinkID] = component.MaxDamageState;
					}
				}
				else {
					// 링크가 없으면 추가
					linkIDAndDamageStateDic->Add(component.LinkID, component.MaxDamageState);
				}
			}

			for each (String^ sIndex in linkIDAndDamageStateDic->Keys){
				int ds = linkIDAndDamageStateDic[sIndex];
				// damage state 0 초과일 경우만 하위 damage state 모두 증가 
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
		// 각 컴포넌트의 damage state를 랜덤으로 결정해서 
		// 해당 위치의 damage probablilty가 threshold 이상일 경우 랜덤으로 결정 된 damage state로 설정

		bool GenerateScenarios() {
			// 전체 시나리오 수
 			int totalTrafficScenarioCount = this->m_dataSet->TotalTrafficScenarioCount;

			Debug::WriteLine(String::Format("Total number of traffic scenario={0}", totalTrafficScenarioCount));

			Random^ rand = gcnew Random();
			// 시나리오(결과)
			int scenarioIndex = 0;
			// 지진소스 index
			int sourceIndex = 0;

			// 전체 traffic scenario
			array<TrafficScenario^>^ resultTrafficScenarios = gcnew array<TrafficScenario^>(totalTrafficScenarioCount);


			// ODIndex = OD zone 개수: 처음 시작시 ODZoneParamData가 활성화 하지 않은 단계는 
			// 기본값으로 ODIndex = 0 로 셋업
			int ODIndex;
			if (m_dataSet->ODZoneParamData->Rows->Count < 1) {
				ODIndex = 0;
			}
			else {
				ODIndex = m_dataSet->ODZoneParamData->Rows->Count;
			}

			// 컴포넌트의 손상 정보
			String^ sourceName = "";
			String^ recurrencePeriodName = "";
			//int recurrencePeriodIndex = 0;
			int sample = 1;
			// threshold 이상인 컴포넌트의 최대 damage state
			int maxDamageState = 0;
			// 최대 damage probability
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


					// 피해단계별 Repair Ratio 저장
					array <double>^ repairRatio = gcnew array<double>(m_fragilityCurve->DamageStateCount);
					// repair ratio 저장
					repairRatio[1] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE1;
					repairRatio[2] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE2;
					repairRatio[3] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE3;
					repairRatio[4] = CommConst::DEFAULT_REPAIR_COST_RATIO_DAMAGE_STATE4;

					// 피해 기준
					array <double>^ damageCriteria = gcnew array<double>(m_fragilityCurve->DamageStateCount);
					// repair ratio 저장
					damageCriteria[1] = 0.5 * (repairRatio[0] + repairRatio[1]);
					damageCriteria[2] = 0.5 * (repairRatio[1] + repairRatio[2]);
					damageCriteria[3] = 0.5 * (repairRatio[2] + repairRatio[3]);
					damageCriteria[4] = 0.5 * (repairRatio[3] + repairRatio[4]);


					// 특정 컴포넌트의 max damage probability and max damage state를 구한다.
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

							// 피해단계가 발생할 수 있는 확률 저장
							array <double>^ probabilityDamageState= gcnew array<double>(m_fragilityCurve->DamageStateCount);

							// recurrence period로 특정 컴포넌트의 지진 강도를 구함
							Double::TryParse(sourceRow[2 + recurIndex]->ToString(), sa); // 3(index=2)번째부터 damage state 1,2,3,4가 존재
							for (int damageState = 1; damageState < m_fragilityCurve->DamageStateCount; damageState++) // damage state 0은 제외
							{
								//								recurrencePeriodIndex = recurIndex;
								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();
								//damageProbability = m_fragilityCurve->GetFragilityValue(classID, damageState, sa);
								damageProbability = m_fragilityCurve->GetFragilityValue(this->m_dataSet, compID, damageState, sa);

								probabilityDamageState[damageState] = damageProbability;

								if (maxDamageProbability < damageProbability) {
									// 피해 확률이 높은 경우에는 업데이트
									maxDamageProbability = damageProbability;
								}

/*
								// 최대 피해단계 계산
								if (damageProbability < DAMAGE_PROBABILITY_THRESHOLD) {
									// threshold를 넘으면 그만(그냥 damage state 0)
									break;
								}
								else {
									// threshold를 넘으면 damage가 있다고 판단하여 현재 damage state를 설정
									maxDamageState = damageState;
								}
*/

							}

///*
							// 기존: 시설물별 최대 피해단계는 취약도곡선으로 부터 계산된 피해단계별 확률이 50%를 넘는 피해단계 중에, 최고단계를 최대피해단계로 정의
							// 변경: 각단계별 확도 중 최대값을 시설물 최대피해로 계산  
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

							// 변경: 각단계별 확도 중 최대값을 시설물 최대피해로 계산  
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
						// 특정 컴포넌트의 max damage probability and max damage state를 구한다.
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
								// recurrence period로 특정 컴포넌트의 지진 강도를 구함
								Double::TryParse(sourceRow[2 + recurIndex]->ToString(), sa); // 3(index=2)번째부터 damage state 1,2,3,4가 존재
								//recurrencePeriodIndex = recurIndex;
								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// 랜덤으로 현재 damage state를 결정
								// fragility 함수로 부터 구해지는 값을 0.00~1.00까지 소수점 2자리로 정량화 하고, 
								// 피해단계별(damage state) 확률값 범위를 설정한다.
								// 아래의 랜덤함수로 부터 1~100사이 값을 발생시켜 피해단계별 확률값 범위와 비교하고
								// 랜덤값이 범위내에 있는 피해단계를 해당 구조물의 피해단계로 설정한다. 
								double dsProbability;
								maxDamageState = 0;
								double dsRandom = static_cast<double>(rand->Next(1, 101)) / 100.0;
								//for (int ds = 1; ds < m_fragilityCurve->DamageStateCount; ds++) {
								for (int ds = 0; ds < m_fragilityCurve->DamageStateCount; ds++) {
									//dsProbability = m_fragilityCurve->GetFragilityValue(classID, ds, sa);
									dsProbability = m_fragilityCurve->GetFragilityValue(this->m_dataSet, compID, ds, sa);
									if (dsRandom > dsProbability) {
										maxDamageState = ds;
										break;
									}
									//else if (ds == m_fragilityCurve->DamageStateCount - 1) {
									//	maxDamageState = m_fragilityCurve->DamageStateCount - 1;
									//}
								}
								// Damage State i 부터 j 사이의 값을 난수표로 발생시키기 위한 함수는 
								// rand->Next(i,j+1)과 같다. 주의할 점은 (j)가 아니라 (j+1)이 라는 것이다.
	/*							int damageState = rand->Next(1, 4);
								damageProbability = m_fragilityCurve->GetFragilityValue(classID, damageState, sa);
								if (maxDamageProbability < damageProbability) {
									// 피해 확률이 높은 경우에는 업데이트
									maxDamageProbability = damageProbability;
								}
								if (damageProbability < DAMAGE_PROBABILITY_THRESHOLD) {
									// threshold를 넘으면 그만(그냥 damage state 0)
									maxDamageState = 0;
								}
								else {
									// threshold를 넘으면 damage가 있다고 판단하여 현재 damage state를 설정
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
								//maxDamageProbability는 이미 sample1에서 구해졌으므로, 여기서 다시 구할 필요는 없다.
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
				// 시나리오 번호는 ODIndex=0 와 연계하여 생성되므로, ODIndex=0에서 생성된 시나리오번호 다음부터 번호시작. 
				//scenarioIndex = this->m_dataSet->TrafficScenarios->Length;
			
				// 기존에 생성된 최초 OD와 관련된 시나리오 정보 저장
				//for (int i = 0; i < scenarioIndex; i++) {
				//	resultTrafficScenarios[i] = this->m_dataSet->TrafficScenarios[i];
				//}

				// 기존 코드에서는 OD 개수 만큼 시나리오를 추가하는 것으로 되어 있지만, 실제로 시나리오 OD와 관계없다.
				// 따라서 임시로 동일한 시나리오를 OD개수 만큼 생성함. 향후 수정필요
				//for (int odIndex = 1; odIndex < ODIndex; odIndex++) {


				// 3차시도
				scenarioIndex = 0;

				// OD index
				for (int odIndex = 0; odIndex < ODIndex; odIndex++) {
					int compoIndex = 0;

				
					// 지진소스 index
					sourceIndex = 0;
					for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary) {
						sourceName = pair->Key;
						array<ComponentInfo>^ components = nullptr;

						for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {

							for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {

								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// component 추출
								TrafficScenario^ scenario = this->m_dataSet->TrafficScenarios[compoIndex];
								components = scenario->Components;

								resultTrafficScenarios[scenarioIndex] = gcnew TrafficScenario(scenarioIndex, sourceName,
									sourceIndex, recurrencePeriodName, recurIndex, sample + 1, components, odIndex + 1);

								scenarioIndex++; // 전체시나리오 Index (0 ~ 소스*주기*샘플*OD)

								compoIndex++; // OD별로 새롭게 시작됨 (0~ 소스*주기*샘플)


							}

						}

						sourceIndex++;

					}
	
						
				}




				// 2차시도
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

								// component 추출
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





				// 1차시도
				/*
				for (int odIndex = 0; odIndex < ODIndex; odIndex++) {

					int compoIndex = 0;
					array<ComponentInfo>^ components = nullptr;


					// 이름 매칭

					for each (KeyValuePair<String^, DataTable^>^ pair in this->m_dataSet->SeismicSourceDictionary) {
						sourceName = pair->Key;


						for (int sample = 0; sample < m_dataSet->MonteCarioCount; sample++) {


							for (int recurIndex = 0; recurIndex < m_dataSet->RecurrencePeriodData->Length; recurIndex++) {

								recurrencePeriodName = m_dataSet->RecurrencePeriodData[recurIndex]->ToString();

								// component 추출
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
			ECOp	: p단계에서의 경제 손실지수
			ntot	: 총 노선 수
			Vj,p	: 노선 j의 p단계에서의 교통량
			tj,p	: 노선 j의 p단계에서의 노선통과시간
			Vj,p	: 노선 j의 지진 전 교통량
			tj,p	: 노선 j의 지진 전 노선통과시간
		*/
		double CalEconomicLossIndices(int trafficVolume, double trafficTime, int refVehicleCount, double refTime) {
			double totalTime = trafficVolume * trafficTime;
			double refTotalTime = refVehicleCount * refTime;
			return refTotalTime / totalTime;
		}
		/*
			calculate economic loss indices
			ECOp	: p단계에서의 경제 손실지수
			ntot	: 총 노선 수
			Vj,p	: 노선 j의 p단계에서의 교통량
			tj,p	: 노선 j의 p단계에서의 노선통과시간
			Vj,p	: 노선 j의 지진 전 교통량
			tj,p	: 노선 j의 지진 전 노선통과시간
		*/
		double CalEconomicLossIndices(int trafficVolume, double trafficTime) {
			double totalTime = trafficVolume * trafficTime;
			double refTotalTime = this->m_totalTrafficVolume * this->m_totalTrafficTime;
			return refTotalTime / totalTime;
		}

		DataRow^ CalConnectLossIndices(array<ShapeProperty^>^ links, DataRow^ newRow) {
			double sumLz0 = 0.0; // total length of link
			double sumLzp = 0.0; // total length of closed link
			for (int j = 0; j < links->Length; j++) {		//links[i]->Length는 해당구역에 포함된 총 노선(link)갯수
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

		// 현행 상태에서의 교통해석결과를 분석하여 환경지수를 계산하는 함수
		double CalEnvironmentLossIndices(ShapeProperty^ links, TrafficScenario^ scenario, int damageState) {
			if (links == nullptr) {
				return 0.0;
			}
			/*
			// excel에 있는 공식 그대로 데미지상태에 따라 상수값 적용
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

			// 환경 민감지수는 지진전에는 해당노선에 OD(Origin, Destination)에 해당하는 교통량이 발생하지 않지만, 
			// 지진후에는 교통량이 발생하는 경우를 대상으로 하였으며,
			// 지진전의 교통량은 기본통행량 TR0로 가정함 
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
				beforeVolume = norOutputSummary->TR0;  //지진전 교통량은 기본통행량
				if (outputSummary != nullptr) {
					//기존교통에는 O/D관련 교통이 없었고, 지진피해로 추가로 교통이 발생하기 때문에 큰 영향이 있다.
					afterVolume = beforeVolume + outputSummary->Volumes[filter1] + outputSummary->Volumes[filter2];
				}
			}
			else {
				beforeVolume = norOutputSummary->Volumes[filter1] + norOutputSummary->Volumes[filter2];
				if (outputSummary != nullptr) {
					//기존에 O/D관련 교통이 존재하였으므로, 추가발생교통량에 따른 환경영향이 상대적으로 적다.
					afterVolume = outputSummary->Volumes[filter1] + outputSummary->Volumes[filter2];
				}
			}
*/

			//지진 전 해당 노선에 교통량이 발생하지 않는 경우
			//if (norOutputSummary->Volumes->ContainsKey(filter1) == false && norOutputSummary->Volumes->ContainsKey(filter2) == false) {
			if (norOutputSummary->Volumes->ContainsKey(links->ID) == false ) {
					//지진 전 교통량 할당
				beforeVolume = norOutputSummary->TR0;  //지진전 교통량은 기본통행량
				//지진 후 교통량 할당
				//기존교통에는 O/D관련 교통이 없었고, 지진피해로 추가로 교통이 발생하기 때문에 큰 영향이 있다.
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
			//지진 전 해당 노선에 교통량이 발생하는 경우
			else {
				//지진 전 교통량 할당
				//if (norOutputSummary->Volumes->ContainsKey(filter1)) { beforeVolume = norOutputSummary->Volumes[filter1]; }
				//if (norOutputSummary->Volumes->ContainsKey(filter2)) { beforeVolume += norOutputSummary->Volumes[filter1]; }
				if (norOutputSummary->Volumes->ContainsKey(links->ID)) { beforeVolume += norOutputSummary->Volumes[links->ID]; }
				//지진 후 교통량 할당
				if (outputSummary != nullptr) {
					//if (outputSummary->Volumes->ContainsKey(filter1)) { afterVolume = outputSummary->Volumes[filter1]; }
					//if (outputSummary->Volumes->ContainsKey(filter2)) { afterVolume += outputSummary->Volumes[filter2]; }
					if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume += outputSummary->Volumes[links->ID]; }
					if (afterVolume < beforeVolume) { afterVolume = beforeVolume; } //지진의 영향으로 교통량이 지진전보다 적게 발생하는 경우, EnvRate = 1.0 할당.
				}
				else {
					afterVolume = beforeVolume;
				}
			}

			// Volumes(filter1) = 0 또는 Volumes(filter2) = 0 가 되며, 동시에 0 이상되는 값을 가지는 경우는 없다.
				//EnvRate = EnvRate + (links[i]->Length) / (afterVolume / beforeVolume * links[i]->Length);
				//EnvRate = EnvRate + (links->Length) / (afterVolume / beforeVolume * links->Length);
			
//			if (beforeVolume != 0) {
				EnvRate = afterVolume / beforeVolume;
//			}
//			else { EnvRate = 1.0; }

			if(EnvRate != 0) { return EnvRate; }
			else { return 1.0; } //Envrate에 변화가 없다는 것은, 환경민감지수가 지진전후 같다(rate=1)는 의미임 
		}

		// 내진보강전(기존) 또는 내진보강후(현행)을 구분해서 교통해석결과를 분석하여 환경지수를 계산하는 함수
		// 보강전: OutputSummaryDictionary = beforeNextOutputSummaryDictionary
		// 보강후: OutputSummaryDictionary = NextOutputSummaryDictionary
		double CalEnvironmentLossIndices(Dictionary<String^, OutputSummary^>^ OutputSummaryDictionary, ShapeProperty^ links, TrafficScenario^ scenario, int damageState, int unitScenarioStep) {
			if (links == nullptr) {
				return 0.0;
			}

			// 환경 민감지수는 지진전에는 해당노선에 OD(Origin, Destination)에 해당하는 교통량이 발생하지 않지만, 
			// 지진후에는 교통량이 발생하는 경우를 대상으로 하였으며,
			// 지진전의 교통량은 기본통행량 TR0로 가정함 
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

			//지진 전 해당 노선에 OD관련 교통량이 발생하지 않는 경우
			if (norOutputSummary->Volumes->ContainsKey(links->ID) == false) {
				//지진 전 교통량 할당
				beforeVolume = norOutputSummary->TR0;  //지진전 교통량은 기본통행량
				//지진 후 교통량 할당
				//기존교통에는 O/D관련 교통이 없었지만, 지진피해로 추가로 교통이 발생하기 때문에 큰 영향이 있다.
				if (outputSummary != nullptr) {
					if (outputSummary->Volumes->ContainsKey(links->ID)) {
						afterVolume = beforeVolume + outputSummary->Volumes[links->ID];
						//if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume += outputSummary->Volumes[links->ID]; }
					}
					else{ afterVolume = beforeVolume; }
				}
				else { afterVolume = beforeVolume; }
			}
			//지진 전 해당 노선에 교통량이 발생하는 경우
			else {
				//지진 전 교통량 할당
				//if (norOutputSummary->Volumes->ContainsKey(links->ID)) { beforeVolume += norOutputSummary->Volumes[links->ID]; }
				 beforeVolume = norOutputSummary->Volumes[links->ID];
				//지진 후 교통량 할당
				if (outputSummary != nullptr) {
					if (outputSummary->Volumes->ContainsKey(links->ID)) { afterVolume = outputSummary->Volumes[links->ID]; }
					if (afterVolume < beforeVolume) { afterVolume = beforeVolume; } //지진의 영향으로 교통량이 지진전보다 적게 발생하는 경우, EnvRate = 1.0 할당.
				}
				else {
					afterVolume = beforeVolume;
				}
			}
			// Volumes(filter1) = 0 또는 Volumes(filter2) = 0 가 되며, 동시에 0 이상되는 값을 가지는 경우는 없다.
			EnvRate = afterVolume / beforeVolume;

			if (EnvRate != 0) { return EnvRate; }
			else { return 1.0; } //Envrate에 변화가 없다는 것은, 환경민감지수가 지진전후 같다(rate=1)는 의미임 
		}

















	};
}