/*
	@file		Protocol.Communication.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_COMMUNICATION_H_
#define PROTOCOL_COMMUNICATION_H_
			 

	namespace Protocol
	{
		/*
			DataType.ResponseRate
		 */
		#pragma pack(1)
		class ResponseRate
		{
		public:
			u8			responseRate;
		};
		#pragma pack()
		
		
		/*
			DataType.SetPairing
			페어링
		 */
		#pragma pack(1)
		class SetPairing
		{
		public:			
			u8			address[5];		// 6 byte
			u8			channel;		// 채널
		};
		#pragma pack()		
		
		
		/*
			DataType.Pairing
			페어링
		 */
		#pragma pack(1)
		class Pairing
		{
		public:
			u8			connectorDeviceType;	// 연결 장치의 타입
			
			u8			address[5];		// 6 byte
			u8			channelArray[8];		// 채널
		};
		#pragma pack()
		
		
		/*
			DataType.TransmissionPower
		 */
		#pragma pack(1)
		class TransmissionPower
		{
		public:
			u8			pairing;
			u8			connected;
		};
		#pragma pack()

	
		/*
			Frequency Hopping
		 */
		#pragma pack(1)
		struct FrequencyHopping
		{
			u8		timeSyncFh;		
			u8		channelFh;	
		};
		#pragma pack()
	}


#endif 