/*
	@file		Protocol.Monitor.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_MONITOR_H_
#define PROTOCOL_MONITOR_H_
			 

	namespace Protocol
	{
		/*
			2018.7.9
			Monitor 구조체는 [MonitorType] + [MonitorX] 형태로 결합한다.
			데이터의 첫 번째 바이트가 Monitor타입이며 여기의 타입에 따라 뒤에 붙는 헤더를 판단
		 */
		/*
			Monitor 헤더의 타입
		 */
		namespace MonitorHeaderType
		{
			enum Type
			{
				Monitor0	= 0x00,
				Monitor4	= 0x01,
				Monitor8	= 0x02
			};
		}
		
		
		/*
			Monitor 데이터의 타입
		 */
		namespace MonitorDataType
		{
			enum Type
			{
				U8		= 0x00,
				S8		= 0x01,
				U16		= 0x02,
				S16		= 0x03,
				U32		= 0x04,
				S32		= 0x05,
				U64		= 0x06,
				S64		= 0x07,
				F32		= 0x08,
				F64		= 0x09
			};
		}
		
		
		#pragma pack(1)
		class MonitorType
		{
		public:
			u8			monitorHeaderType;				// Monitor 헤더 타입
		};
		#pragma pack()

		
		#pragma pack(1)
		class Monitor0
		{
		public:
			u8			monitorDataType;
			u8			index;
		};
		#pragma pack()

		
		#pragma pack(1)
		class Monitor4
		{
		public:
			u32			systemTime;
			u8			monitorDataType;
			u8			index;
		};
		#pragma pack()

		
		#pragma pack(1)
		class Monitor8
		{
		public:
			u64			systemTime;
			u8			monitorDataType;
			u8			index;
		};
		#pragma pack()
	}


#endif