/*
	@file		Protocol.Light.h
	@brief		Light
 */


#ifndef PROTOCOL_LIGHT_H_
#define PROTOCOL_LIGHT_H_


#include "Types.h"


	namespace Protocol
	{
		namespace Light
		{	
			/*
				DataType.LightManual
			 */
			#pragma pack(1)
			class Manual
			{
			public:
				u16			flags;			// Flags 열거형을 조합한 값
				u8			brightness;		// 밝기
			};
			#pragma pack()
			
			
			/*
				DataType.LightMode*
			 */
			#pragma pack(1)
			class Mode
			{
			public:
				u8			mode;			// LED 모드
				u16			interval;		// LED 모드의 갱신 주기
			};
			#pragma pack()
			
			
			/*
				DataType.LightEvent*
			 */
			#pragma pack(1)
			class Event
			{
			public:
				u8			event;			// LED 이벤트
				u16			interval;		// LED 이벤트 갱신 주기
				u8			repeat;			// LED 이벤트 반복 횟수
			};
			#pragma pack()
			
			
			/*
				DataType.LightModeColor
			 */
			#pragma pack(1)
			class ModeColor
			{
			public:
				Mode		mode;
				Color		color;
			};
			#pragma pack()
			
			
			/*
				DataType.LightModeColors
			 */
			#pragma pack(1)
			class ModeColors
			{
			public:
				Mode		mode;
				u8			colors;
			};
			#pragma pack()
			
			
			/*
				DataType.LightEventColor
			 */
			#pragma pack(1)
			class EventColor
			{
			public:
				Event		event;
				Color		color;
			};
			#pragma pack()

			
			/*
				DataType.LightEventColors
			 */
			#pragma pack(1)
			class EventColors
			{
			public:
				Event		event;
				u8			colors;
			};
			#pragma pack()
		}
	}		


#endif