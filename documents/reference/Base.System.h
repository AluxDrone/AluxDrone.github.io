

#ifndef BASE_SYSTEM_H_
#define BASE_SYSTEM_H_


	/*
		Drone_4 프로젝트 부터 모든 드론은 동일한 디바이스 타입을 사용.
		각 드론 구분은 Information의 ModelNumber를 확인하여 구분
	 */
	namespace DeviceType
	{
		enum Type
		{
			None		= 0x00,
			
			Drone		= 0x10,		// 드론(Server)
			
			Controller	= 0x20,		// 조종기(Client)
			
			LinkClient	= 0x30,		// 링크 모듈(Client)
			LinkServer	= 0x31,		// 링크 모듈(Server)
			BleClient	= 0x32,		// BLE 클라이언트
			BleServer	= 0x33,		// BLE 서버
			
			Range		= 0x40,		// 거리 센서 모듈
			
			Base		= 0x70,		// 베이스(응용 프로그램)
			
			ByScratch	= 0x80,		// 바이스크래치
			Scratch		= 0x81,		// 스크래치
			Entry		= 0x82,		// 네이버 엔트리
			
			Tester		= 0xA0,		// 테스터
			Monitor		= 0xA1,		// 모니터
			Updater		= 0xA2,		// 펌웨어 업데이트 도구
			Encrypter	= 0xA3,		// 암호화 도구
			
			EndOfType,
			
			Whispering		= 0xFE,	// 바로 인접한 장치까지만 전달(받은 장치는 자기 자신에게 보낸 것처럼 처리하고 타 장치에 전달하지 않음)
			Broadcasting	= 0xFF	// 연결된 모든 장치에 전달
		};
	}


	/*
		// 펌웨어 업데이트 시 장치 구분
		0xFFFFFFFF
		4,294,967,295
	 */

	namespace ModelNumber
	{
		enum Type
		{
			None = 0,
			
			//							AAAABBCC, AAAA(Project Number), BB(Device Type), CC(Revision)
			// Drone_11 Pan2025 chip
			Drone_11_Drone_P0		= 0x000B1000,	// reserve
			Drone_11_Drone_P1		= 0x000B1001,	// 65 no coding
			Drone_11_Drone_P2		= 0x000B1002,	// fixWing
			Drone_11_Drone_P3		= 0x000B1003,	// 65 coding
			Drone_11_Drone_P4		= 0x000B1004,	// 95 battle drone
			Drone_11_Drone_P5		= 0x000B1005,	// drone soccer
			Drone_11_Drone_P6		= 0x000B1006,	// reserve
			Drone_11_Drone_P7		= 0x000B1007,	// reserve
			Drone_11_Drone_P8		= 0x000B1008,	// reserve
			Drone_11_Drone_P9		= 0x000B1009,	// reserve
			
			Drone_11_Controller_P0	= 0x000B2000,	// reserve
			Drone_11_Controller_P1	= 0x000B2001,	// Drone_11_Controller_P1 / small size, 65 drone, USB
			Drone_11_Controller_P2	= 0x000B2002,	// Drone_11_Controller_P2 / small size, 65 drone, NoUSB
			Drone_11_Controller_P3	= 0x000B2003,	// Drone_11_Controller_P3 / small size, Bird Wing, Fixed Wing, NoReturn
			Drone_11_Controller_P4	= 0x000B2004,	// Drone_11_Controller_P3 / middle size, Battle drone, USB
			Drone_11_Controller_P5	= 0x000B2005,	// 
			Drone_11_Controller_P6	= 0x000B2006,	// 
			Drone_11_Controller_P7	= 0x000B2007,	// 
			Drone_11_Controller_P8	= 0x000B2008,	// 
			Drone_11_Controller_P9	= 0x000B2009,	// 
			
			Drone_11_Link_P0		= 0x000B3000,	// Drone_11_Link_P0 RoboRobo
			Drone_11_Link_P1		= 0x000B3001,	// 
			Drone_11_Link_P2		= 0x000B3002,	// 
			Drone_11_Link_P3		= 0x000B3003,	// 
			Drone_11_Link_P4		= 0x000B3004,	// 
			Drone_11_Link_P5		= 0x000B3005,	// 
			Drone_11_Link_P6		= 0x000B3006,	// 
			Drone_11_Link_P7		= 0x000B3007,	// 
			Drone_11_Link_P8		= 0x000B3008,	// 
			Drone_11_Link_P9		= 0x000B3009,	// 
			
			// Drone_12  chip
			Drone_12_Drone_P0		= 0x000C1000,	// coding drone stm32f401rc + xn297
			Drone_12_Drone_P1		= 0x000C1001,	// coding drone STM32F407VE + nrf24l01
			Drone_12_Drone_P2		= 0x000C1002,	// 
			Drone_12_Drone_P3		= 0x000C1003,	// 
			Drone_12_Drone_P4		= 0x000C1004,	// 
			Drone_12_Drone_P5		= 0x000C1005,	// 
			Drone_12_Drone_P6		= 0x000C1006,	//.
			Drone_12_Drone_P7		= 0x000C1007,	//
			Drone_12_Drone_P8		= 0x000C1008,	// 
			Drone_12_Drone_P9		= 0x000C1009,	// 
			
			Drone_12_Controller_P0	= 0x000C2000,	// coding drone stm32f401rc + xn297
			Drone_12_Controller_P1	= 0x000C2001,	// coding drone STM32F407VE + nrf24l01
			Drone_12_Controller_P2	= 0x000C2002,	// 
			Drone_12_Controller_P3	= 0x000C2003,	// 
			Drone_12_Controller_P4	= 0x000C2004,	// 
			Drone_12_Controller_P5	= 0x000C2005,	// 
			Drone_12_Controller_P6	= 0x000C2006,	// 
			Drone_12_Controller_P7	= 0x000C2007,	// 
			Drone_12_Controller_P8	= 0x000C2008,	// 
			Drone_12_Controller_P9	= 0x000C2009,	// 
			 
			Drone_12_Link_P0		= 0x000C3000,	// Drone_12_Link_P0
			Drone_12_Link_P1		= 0x000C3001,	// 
			Drone_12_Link_P2		= 0x000C3002,	// 
			Drone_12_Link_P3		= 0x000C3003,	// 
			Drone_12_Link_P4		= 0x000C3004,	// 
			Drone_12_Link_P5		= 0x000C3005,	// 
			Drone_12_Link_P6		= 0x000C3006,	// 
			Drone_12_Link_P7		= 0x000C3007,	// 
			Drone_12_Link_P8		= 0x000C3008,	// 
			Drone_12_Link_P9		= 0x000C3009,	// 			
			
			Drone_12_Tester_P0		= 0x000CA000,	
			Drone_12_Tester_P1		= 0x000CA001,	// 
			Drone_12_Tester_P2		= 0x000CA002,	// 
			Drone_12_Tester_P3		= 0x000CA003,	// 
			Drone_12_Tester_P4		= 0x000CA004,	// 
			Drone_12_Tester_P5		= 0x000CA005,	// 
			Drone_12_Tester_P6		= 0x000CA006,	// 
			Drone_12_Tester_P7		= 0x000CA007,	// 
			Drone_12_Tester_P8		= 0x000CA008,	// 
			Drone_12_Tester_P9		= 0x000CA009,	// 
			
			Drone_12_Monitor_P0		= 0x000CA100,	
			Drone_12_Monitor_P1		= 0x000CA101,	// 
			Drone_12_Monitor_P2		= 0x000CA102,	// 
			Drone_12_Monitor_P3		= 0x000CA103,	// 
			Drone_12_Monitor_P4		= 0x000CA104,	// 
			Drone_12_Monitor_P5		= 0x000CA105,	// 
			Drone_12_Monitor_P6		= 0x000CA106,	// 
			Drone_12_Monitor_P7		= 0x000CA107,	// 
			Drone_12_Monitor_P8		= 0x000CA108,	// 
			Drone_12_Monitor_P9		= 0x000CA109,	// 
			
			// Drone_13  chip
			Drone_13_Drone_P0		= 0x000D1000,	// coding drone stm32f401rc + xn297
			Drone_13_Drone_P1		= 0x000D1001,	// 
			Drone_13_Drone_P2		= 0x000D1002,	// 
			Drone_13_Drone_P3		= 0x000D1003,	// 
			Drone_13_Drone_P4		= 0x000D1004,	// 
			Drone_13_Drone_P5		= 0x000D1005,	// 
			Drone_13_Drone_P6		= 0x000D1006,	//.
			Drone_13_Drone_P7		= 0x000D1007,	//
			Drone_13_Drone_P8		= 0x000D1008,	// 
			Drone_13_Drone_P9		= 0x000D1009,	// 
			
			Drone_13_Controller_P0	= 0x000D2000,	// coding drone stm32f401rc + xn297
			Drone_13_Controller_P1	= 0x000D2001,	//
			Drone_13_Controller_P2	= 0x000D2002,	// 
			Drone_13_Controller_P3	= 0x000D2003,	// 
			Drone_13_Controller_P4	= 0x000D2004,	// 
			Drone_13_Controller_P5	= 0x000D2005,	// 
			Drone_13_Controller_P6	= 0x000D2006,	// 
			Drone_13_Controller_P7	= 0x000D2007,	// 
			Drone_13_Controller_P8	= 0x000D2008,	// 
			Drone_13_Controller_P9	= 0x000D2009,	// 
			 
			Drone_13_Link_P0		= 0x000D3000,	// Drone_13_Link_P0
			Drone_13_Link_P1		= 0x000D3001,	// 
			Drone_13_Link_P2		= 0x000D3002,	// 
			Drone_13_Link_P3		= 0x000D3003,	// 
			Drone_13_Link_P4		= 0x000D3004,	// 
			Drone_13_Link_P5		= 0x000D3005,	// 
			Drone_13_Link_P6		= 0x000D3006,	// 
			Drone_13_Link_P7		= 0x000D3007,	// 
			Drone_13_Link_P8		= 0x000D3008,	// 
			Drone_13_Link_P9		= 0x000D3009,	// 			
			
			Drone_13_Tester_P0		= 0x000DA000,	
			Drone_13_Tester_P1		= 0x000DA001,	// 
			Drone_13_Tester_P2		= 0x000DA002,	// 
			Drone_13_Tester_P3		= 0x000DA003,	// 
			Drone_13_Tester_P4		= 0x000DA004,	// 
			Drone_13_Tester_P5		= 0x000DA005,	// 
			Drone_13_Tester_P6		= 0x000DA006,	// 
			Drone_13_Tester_P7		= 0x000DA007,	// 
			Drone_13_Tester_P8		= 0x000DA008,	// 
			Drone_13_Tester_P9		= 0x000DA009,	// 
			
			Drone_13_Monitor_P0		= 0x000DA100,	
			Drone_13_Monitor_P1		= 0x000DA101,	// 
			Drone_13_Monitor_P2		= 0x000DA102,	// 
			Drone_13_Monitor_P3		= 0x000DA103,	// 
			Drone_13_Monitor_P4		= 0x000DA104,	// 
			Drone_13_Monitor_P5		= 0x000DA105,	// 
			Drone_13_Monitor_P6		= 0x000DA106,	// 
			Drone_13_Monitor_P7		= 0x000DA107,	// 
			Drone_13_Monitor_P8		= 0x000DA108,	// 
			Drone_13_Monitor_P9		= 0x000DA109,	// 
		};
	}


	/*
		Error Flags For Sensor
	 */
	namespace ErrorFlagsForSensor
	{
		enum Type
		{
			None									= 0x00000000,

			Motion_NoAnswer							= 0x00000001,	// Motion 응답 없음
			Motion_WrongValue						= 0x00000002,	// Motion 잘못된 값
			Motion_NotCalibrated					= 0x00000004,	// Gyro Bias 보정이 완료되지 않음
			Motion_Calibrating						= 0x00000008,	// Gyro Bias 보정 중

			Pressure_NoAnswer						= 0x00000010,	// 압력 센서 응답 없음
			Pressure_WrongValue						= 0x00000020,	// 압력 센서 잘못된 값

			RangeGround_NoAnswer					= 0x00000100,	// 바닥 거리 센서 응답 없음
			RangeGround_WrongValue					= 0x00000200,	// 바닥 거리 센서 잘못된 값
			RangeFront_NoAnswer						= 0x00000400,	// 정면 거리 센서 응답 없음
			RangeFront_WrongValue					= 0x00000800,	// 정면 거리 센서 잘못된 값

			Flow_NoAnswer							= 0x00001000,	// Flow 응답 없음
			Flow_WrongValue							= 0x00002000,	// Flow 잘못된 값
			Flow_CannotRecognizeGroundImage			= 0x00004000,	// 바닥 이미지를 인식할 수 없음
			
			
			RF_NoAnswer								= 0x10000000,	// RF 응답 없음
			RF_Paired 								= 0x20000000,	// RF 페어링 완료
			RF_Connected							= 0x40000000,	// RF 연결됨
		};
	}
	
    
	/*
		Error Flags For State
	 */
	namespace ErrorFlagsForState
	{
		enum Type
		{
			None									= 0x00000000,

			NotRegistered							= 0x00000001,	// 장치 등록이 안됨
			FlashReadLock_UnLocked					= 0x00000002,	// 플래시 메모리 읽기 Lock이 안 걸림
			BootloaderWriteLock_UnLocked			= 0x00000004,	// 부트로더 영역 쓰기 Lock이 안 걸림
			LowBattery								= 0x00000008,	// Low Battery
			
			TakeoffFailure_CheckPropellerAndMotor	= 0x00000010,	// 이륙 실패
			CheckPropellerVibration					= 0x00000020,	// 프로펠러 진동발생
			Attitude_NotStable						= 0x00000040,	// 자세가 많이 기울어져 있거나 뒤집어져 있을때
			Motors_NotGood							= 0x00000080,	// 모터가 좋지 않을때
			
			CanNotFlip_LowBattery					= 0x00000100,	// 배터리가 30이하
			CanNotFlip_TooHeavy						= 0x00000200,	// 기체가 무거움
		};
	}
	
    
	/* 
		방향
	 */
	namespace Direction
	{
		enum Type
		{
			None = 0,

			Left,
			Front,
			Right,
			Rear,
			
			Top,
			Bottom,
			
			Center,
			
			EndOfType
		};
	}


	/*
		회전 방향
	 */
	namespace Rotation
	{
		enum Type
		{
			None = 0,
			
			Clockwise,				// 시계 방향
			Counterclockwise,		// 반시계 방향
			
			EndOfType
		};
	}


	/*
		비행 이벤트
	 */
	namespace FlightEvent
	{
		enum Type
		{
			None			= 0x00,		// 없음
					
			Stop			= 0x10,		// 정지
			Takeoff			= 0x11,		// 이륙
			Landing			= 0x12,		// 착륙
			
			Reverse			= 0x13,		// 뒤집기
			
			FlipFront		= 0x14,		// 회전
			FlipRear		= 0x15,		// 회전
			FlipLeft		= 0x16,		// 회전
			FlipRight		= 0x17,		// 회전
			
			Return			= 0x18,		// Return
			
			Shot			= 0x90,		// Shot
			UnderAttack,				// UnderAttack
			
			ResetHeading 	= 0xA0,		// 헤딩 리셋(Headless 모드 일 때 현재 heading을 0도로 변경)
			
			EndOfType
		};
	}
	
	
	/*
		MOTION 센서 상태
	 */
	namespace SensorOrientation
	{
		enum Type
		{
			None = 0,			// 없음
			
			Normal,				// 정상
			ReverseStart,		// 뒤집히기 시작
			Reversed,			// 뒤집힘
			
			EndOfType
		};
	}
	

	/*
		헤드리스 모드
	 */
	namespace Headless
	{
		enum Type
		{
			None = 0,		// 없음
			
			Headless,		// 헤드리스(앱솔루트)
			Normal,			// 일반
			
			EndOfType
		};
	}
	

	/*
		데이터 구조체 - 카운트 데이터
	 */
	namespace Counters
	{
		enum Type
		{
			// Flight Count	
			FlightTakeoff,				// 이륙
			FlightLanding,				// 착륙
			FlightAccident,				// 충돌(Accident)
			
			EndOfType
		};
	}
	

	/*
		데이터 구조체 - 카운트 데이터
	 */
	class Counter
	{
	public:
		u32		counter[Counters::EndOfType];
		
		// Time
		u64		timeRunSystem;			// 시스템 동작 시각(누적)
		u64		timeRunFlight;			// 비행 모드 사용 시간(누적)
	};


	/*
		온도
	 */
	class Temperature
	{
	public:
		union
		{
			struct
			{
				u16	value;		// 온도
			};
			u8 array[2];
		};
	};

	
	namespace TakeOff
	{
		enum Type
		{
			None = 0,
			
			OneKey,						// 원키 자동 이륙
			JoystickUp,					// 조종기 위로 하면 자동 이륙
			JoystickLeftRightDown,		// 조종기 왼쪽 오른쪽 대각선 아래로 하여 시동후 수동 이륙
			All,
			
			EndOfType
		};
	}
	
	
	namespace TrimDirection
	{
		enum Type
		{
			None = 0,			// 없음
 
			RollIncrease,		// Roll 증가
			RollDecrease,		// Roll 감소				
			PitchIncrease,		// Pitch 증가
			PitchDecrease,		// Pitch 감소				
			YawIncrease,		// Yaw 증가
			YawDecrease,		// Yaw 감소				
			ThrottleIncrease,	// Throttle 증가
			ThrottleDecrease,	// Throttle 감소
			
			Reset,				// 전체 트림 리셋
			
			EndOfType
		};
	}
	
	
#endif