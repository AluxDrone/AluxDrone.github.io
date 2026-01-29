/*
	@file		Protocol.Default.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_DEFAULT_H_
#define PROTOCOL_DEFAULT_H_


	namespace Protocol
	{
		/*
			DataType.Ping
		 */
		#pragma pack(1)
		class Ping
		{
		public:
			u64			systemTime;				// Ping을 전송하는 장치의 시각
		};
		#pragma pack()


		/*
			DataType.Ack
		 */
		#pragma pack(1)
		class Ack
		{
		public:
			u64			systemTime;				// 수신 받은 시간
			u8			dataType;				// 수신 받은 데이터 타입
			u16			crc16;					// 수신 받은 데이터의 crc16
		};
		#pragma pack()
		
		
		/*
			DataType.Error
		 */
		#pragma pack(1)
		class Error
		{
		public:
			u64			systemTime;				// 에러 메세지 송신 시각
			u32			errorFlagsForSensor;	// 
			u32			errorFlagsForState;		// 
		};
		#pragma pack()

		
		/*
			DataType.Request
		 */
		#pragma pack(1)
		class Request
		{
		public:
			u8			dataType;			// 요청할 데이터 타입
		};
		
		
		/*
			DataType.Request
		 */
		#pragma pack(1)
		class RequestOption
		{
		public:
			u8			dataType;			// 요청할 데이터 타입
			u32			option;				// 추가 옵션
		};
		#pragma pack()

		
		/*
			DataType.SystemInformation
		 */
		#pragma pack(1)
		class SystemInformation
		{
		public:
			u32			crc32bootloader;	// 부트로더 영역 CRC32
			u32			crc32application;	// 앱 영역 CRC32
		};
		#pragma pack()
		
		
		/*
			DataType.Information
		 */
		#pragma pack(1)
		class Information
		{
		public:
			u8			modeUpdate;			// 업데이트 모드
		
			u32			modelNumber;		// 모델 번호
			u32			version;			// 현재 펌웨어의 버젼
			
			u16			year;				// 빌드 년
			u8			month;				// 빌드 월
			u8			day;				// 빌드 일
		};
		#pragma pack()
		
		
		/*
			DataType.CpuId
		 */
		#pragma pack(1)
		class CpuId
		{
		public:
			u8			cpuId[12];
		};
		#pragma pack()		
		
		
		/*
			DataType.UpdateLocation
		 */
		#pragma pack(1)
		struct UpdateLocation
		{
			u16			indexBlockNext;		// 요청 블럭 번호
		};
		#pragma pack()
		

		/*
			DataType.Update
		 */
		#pragma pack(1)
		struct Update
		{
			u16			indexBlock;			// 블럭 번호
		};
		#pragma pack()
		

		/*
			DataType.Address
		 */
		#pragma pack(1)
		class Address
		{
		public:
			union
			{
				u8			address[5];		// 5 byte
			};
		};
		#pragma pack()
		
		
		/*
			DataType.Address
		 */
		#pragma pack(1)
		class AddressInjection
		{
		public:
			u32			modelNumber;
			u8			address[5];				// 5 byte
			u16			year;					// 시리얼 번호 부여 년도
			u8			month;					// 시리얼 번호 부여 월
			u8			day;					// 시리얼 번호 부여 일
		};
		#pragma pack()
		
		
		/*
			DataType.Button
		 */
		#pragma pack(1)
		class Button
		{
		public:
			u16			button;
			u8			event;
		};
		#pragma pack()
		
		
		/*
			DataType.Count						// 비행 관련 카운트 
		
			* u32 크기에 ms 단위로 저장하는 경우 저장 범위
				4,294,967,295	ms
				4,294,967		s
				71,583			min
				1,193			hour
				50				day
		
			* u32 크기에 s 단위로 저장하는 경우 저장 범위
				4,294,967,295	s
				71,582,788		min
				1,193,046		hour
				49,710			day
				136				year		
		 */
		#pragma pack(1)
		class Count
		{
		public:
			u32			timeSystem;				// 사용 시간(sec)
			u32			timeFlight;				// 비행 시간(sec)
			
			u16			countTakeOff;			// 이륙 횟수
			u16			countLanding;			// 착륙 횟수
			u16			countAccident;			// 충돌 횟수
		};
		#pragma pack()
		
		
		/*
			DataType.Buzzer
		 */
		#pragma pack(1)
		class BuzzerMelody
		{
		public:
			u8			melody;		// 멜로디 타입
			u8			repeat;		// 반복횟수
		};
		#pragma pack()
		
		
		/*
			DataType.Buzzer
		 */
		#pragma pack(1)
		class Buzzer
		{
		public:
			u8			mode;
			union
			{
				u16		scale;	// 옥타브
				u16		hz;		// 주파수
				u16		value;	// union을 사용할 수 없는 경우엔 value 하나만 정의할 것
			};
			u16			time;
		};
		#pragma pack()
		

		/*
			DataType.Battery
		 */
		#pragma pack(1)
		class Battery
		{
		public:
			u8			batteryPercentage;		// 배터리량(0 ~ 100)
			float		voltage;				// 입력전압
		};
		#pragma pack()
	}


#endif