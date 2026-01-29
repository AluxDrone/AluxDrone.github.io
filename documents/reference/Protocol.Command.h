/*
	@file		Protocol.Command.h
	@brief		Command 네임스페이스
 */


#ifndef PROTOCOL_COMMAND_H_
#define PROTOCOL_COMMAND_H_


#include "Protocol.Light.h"


	namespace Protocol
	{
		namespace Command
		{
			/*
				Command
			 */
			#pragma pack(1)
			class Command
			{
			public:
				u8			commandType;	// 명령 타입
				u8			option;			// 명령에 대한 옵션(System.h에 정의한 값을 사용)
			};
			#pragma pack()
			
			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightMode
			{
			public:
				Command					command;
				Protocol::Light::Mode	mode;
			};
			#pragma pack()

			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightModeColor
			{
			public:
				Command					command;
				Protocol::Light::Mode	mode;
				Color					color;
			};
			#pragma pack()

			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightModeColors
			{
			public:
				Command					command;
				Protocol::Light::Mode	mode;
				u8						colors;
			};
			#pragma pack()
			
			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightEvent
			{
			public:
				Command					command;
				Protocol::Light::Event	event;
			};
			#pragma pack()

			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightEventColor
			{
			public:
				Command					command;
				Protocol::Light::Event	event;
				Color					color;
			};
			#pragma pack()

			
			/*
				DataType.Command
			 */
			#pragma pack(1)
			class LightEventColors
			{
			public:
				Command					command;
				Protocol::Light::Event	event;
				u8						colors;
			};
			#pragma pack()
		}
	}


#endif

