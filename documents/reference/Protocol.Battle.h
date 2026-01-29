/*
	@file		Protocol.Battle.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_BATTLE_H_
#define PROTOCOL_BATTLE_H_


	namespace Protocol
	{
		/*
			DataType.Battle
		 */
		#pragma pack(1)
		class BattleIrMessage
		{
		public:
			u8			irMessage;
		};
		#pragma pack()
		
		
		/*
			DataType.Battle
		 */
		#pragma pack(1)
		class BattleLightEventCommand
		{
		public:
			u8			event;			// LED 이벤트
			u16			interval;		// LED 이벤트 갱신 주기
			u8			repeat;			// LED 이벤트 반복 횟수
			u8			r;
			u8			g;
			u8			b;
			
			u8			commandType;
			u8			commandOption;
		};
		#pragma pack()
		
		
		/*
			DataType.Battle
		 */
		#pragma pack(1)
		class BattleIrMessageLightEventCommand
		{
		public:
			u8			irMessage;
			
			u8			event;			// LED 이벤트
			u16			interval;		// LED 이벤트 갱신 주기
			u8			repeat;			// LED 이벤트 반복 횟수
			u8			r;
			u8			g;
			u8			b;
			
			u8			commandType;
			u8			commandOption;
		};
		#pragma pack()
	}


#endif

