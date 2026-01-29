/*
	@file		NRF24L01.Connector.h
	@brief		연결 관리
 */


#ifndef NRF24L01_CONNECTOR_H_
#define NRF24L01_CONNECTOR_H_


#include "Protocol.h"


	namespace NRF24L01
	{
		namespace Connector
		{
			class Fixed
			{
			public:
				static const u16				timeLostConnection 	= 1000;
				static const u8					timeInterference	= 250;
				static const u8					channelLimitMin    	= 0;
				static const u8					channelLimitMax    	= 125;
				static const Pairing			pairingDefault;		// 페어링 시 사용하는 주소		
				static const Pairing			pairingTest;		// 페어링 시 사용하는 주소
			};
			

			// NRF24L01
			namespace TransmissionPower
			{
				enum Type
				{
					Minus_18	= 0x00,
					Minus_12    = 0x02,
					Minus_6		= 0x04,
					Zero_0		= 0x06,
			
					EndOfType
				};
			}
			
			/*
				연결 모드
			 */
			namespace ModeConnection
			{
				enum Type
				{
					None,
					
					PairingStart,					// 페어링 시작(주소 초기화 후 대기 // 한쪽에서는 새로운 주소를 생성하여 전송)
					PairingExchange,				// 페어링 데이터 교환
					PairingComplete,				// 드론 페어링 완료
					PairingFailed,					// 드론 페어링 실패
					
					Ready,							// 장치와 연결하지 않은 상태(장치와 연결 전 또는 연결 해제 완료 후 이 상태로 전환됨)
					
					ConnectingStart,				// 장치 연결 시작
					Connecting,						// 장치 연결 확인
					Connected,						// 장치 연결 완료
					
					LostConnection,					// 연결을 잃음(Server-Client간 통신이 되지 않는 상태)
					
					Disconnected,					// 장치 연결 해제 완료
					
					Interference,
					
					EndOfType
				};
			}
			
			
			namespace DeviceType
			{
				enum Type
				{
					Server,		// Drone
					Client		// Controller, Link
				};
			}
			
			
			class DataBlockState
			{
			public:
				DeviceType::Type			deviceType;							// 장치 타입
				ModeConnection::Type		modeConnection;					// 이벤트에 따른 Light 제어를 할 것인지
				
				u32							timeModeChanged;					// 모드가 변경된 시각
				
				u32							timeReceived;
				u32							timeConnected;						// 장치와 연결된 시각
				u32							timeRequest;						// 요청
				u32							timeConnectingStart;				// 연결 시작 시간
				u32							timeLostConnection;					// 연결 시작 시간
			};
			
			
			class DataBlockPairing
			{
			public:
				Pairing						pairingTemp;						
				Pairing						pairing;							// 현재 장치 주소
				
				volatile bool				flagPairingUpdated;					// 페어링 주소 업데이트가 완료됨
				
				u32							timePairingStart;					// 페어링 시작 시각
				u32							timeSendPairingDataNext;			// 다음 페어링 데이터 전송 시각
				u32							timeReceivePairingData;				// 페어링 데이터를 받기 시작한 시각
				u8							countSendPairingComplete;			// 페어링 완료 전송 카운트
			};
			
			
			class Connector
			{
			public:
				DataBlockState				dbState;
				DataBlockPairing			dbPairing;
					
			private:	
				void						checkConnection();										// 연결 상태 확인
					
				void						connectDevice(Pairing *pairing);						// 연결
										
				bool						pairingStart();											// 페어링 시작
				void						pairingExchange();										// 페어링 데이터 교환
				void						pairingComplete();										// 페어링 완료
				void						pairingFailed();										// 페어링 실패		
					
				void 						setMode(ModeConnection::Type newModeConnection, bool flagForce = false);		// 모드 변경
				
			private:
				// 개별 장치에서 실행할 명령(드론/컨트롤러/링크 등에서 해당 동작 실행 후 LED, Buzzer, Vibrator 등으로 결과를 표시할 때 사용)
				void						eventSetMode(ModeConnection::Type newModeConnection);	// 모드 변경 시 이벤트
					
			public:	
				void						init(DeviceType::Type deviceType);						// 초기화
					
				void						run();													// 드론과의 연결 상태 확인
					
				bool						dataScreening(Protocol::DataType::Type dataType);		// 송신 데이터 걸러내기
				ModeConnection::Type		getMode() 		{ return dbState.modeConnection; }		// 모드 반환
					
				void						connect(bool flagForce = false);						// 현재 지정된 주소로 연결
				void						disconnect();											// 장치와의 연결 해제
				void						pairing();												// 페어링 시작
					
				bool						isConnected();											// 연결 여부 확인
					
				void						setTest();												// 랜덤 주소 지정(장치 리셋 시)
				
				void						setRand(Pairing *pairing);
					
				void						update(Protocol::Pairing *newPairing);			        // 전송 받은 주소 데이터
				void						setPairing(Protocol::SetPairing *newPairing);			// 전송 받은 주소 데이터
			};
		}
	}


#endif