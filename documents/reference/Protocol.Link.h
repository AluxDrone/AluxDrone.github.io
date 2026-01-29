/*
	@file		Protocol.Link.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_LINK_H_
#define PROTOCOL_LINK_H_


	namespace Protocol
	{
		
		
		/*
			DataType.State
		 */
		#pragma pack(1)
		class StateLink
		{
		public:
			u8			modeSystem;				// 시스템 동작 모드
			u8			modeConnection;			// 연결 모드
			u8			deviceType;				// 현재 장치의 타입
			u8			responseRate;			// responseRate
		
			u32			systemTime;				// 시스템 시간(ms)
			u32			timeConnected;			// 연결된 이후부터의 시간(ms)
			u32			timeLostConnection;		// 연결이 끊어지고 나서의 시간(ms)
		
			u8			countCycleTransferRF;	// 1초당 전송 횟수 RF
			u8			countCycleReceiveRF;	// 1초당 수신 횟수 RF
			u8			countCycleTransferExternal;	// 1초당 전송 횟수 External
			u8			countCycleReceiveExternal;	// 1초당 수신 횟수 External
			u8			countCycleTransferUSB;	// 1초당 전송 횟수 USB
			u8			countCycleReceiveUSB;	// 1초당 수신 횟수 USB
		};
		#pragma pack()
		
		
	}


#endif