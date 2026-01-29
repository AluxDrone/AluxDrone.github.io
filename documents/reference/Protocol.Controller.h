/*
	@file		Protocol.Controller.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음 - 조종기
 */


#ifndef PROTOCOL_CONTROLLER_H_
#define PROTOCOL_CONTROLLER_H_


	namespace Protocol
	{
		/*
			DataType.State
		 */
		#pragma pack(1)
		class StateController
		{
		public:
			u8			modeSystem;				// 시스템 동작 모드
			u8			modeController;			// 조종기 동작 모드
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
		

		/*
			DataType.JoystickBlock
		 */
		#pragma pack(1)
		class JoystickBlock
		{
		public:
			s8		x;
			s8		y;
			u8		direction;
			u8		event;
		};
		#pragma pack()
		
		
		/*
			DataType.Joystick
		 */
		#pragma pack(1)
		class Joystick
		{
		public:
			JoystickBlock	joystickLeft;
			JoystickBlock	joystickRight;
		};
		#pragma pack()
		
		
		/*
			DataType.Joystick
		 */
		#pragma pack(1)
		class JoystickRaw
		{
		public:
			s16				rlx;
			s16				rly;
			s16				rrx;
			s16				rry;
		
			s8				lx;
			s8				ly;
			s8				rx;
			s8				ry;
		};
		#pragma pack()
		
		
		/*
			DataType.Vibrator
		 */
		#pragma pack(1)
		class Vibrator
		{
		public:
			u8		mode;	// 모드(0은 set, 1은 reserve)
			u16		on;		// 진동을 켠 시간(ms)
			u16		off;	// 진동을 끈 시간(ms)
			u16		total;	// 전체 진행 시간(ms)
		};
		#pragma pack()
	}


#endif