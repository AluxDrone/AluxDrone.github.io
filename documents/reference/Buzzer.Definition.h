/*
	@file		Buzzer.Definition.h
	@brief		부저 제어
 */


#ifndef BUZZER_DEFINITION_H_
#define BUZZER_DEFINITION_H_


#include "Types.h"


	namespace Buzzer
	{
		/*
			모드
		 */
		namespace Mode
		{
			enum Type
			{
				Stop				= 0,	// 정지(Mode에서의 Stop은 통신에서 받았을 때 Buzzer를 끄는 용도로 사용, set으로만 호출)
				
				MuteInstantly		= 1,	// 묵음 즉시 적용
				MuteContinually		= 2,	// 묵음 예약
				
				ScaleInstantly		= 3,	// 음계 즉시 적용
				ScaleContinually	= 4,	// 음계 예약
				
				HzInstantly			= 5,	// 주파수 즉시 적용
				HzContinually		= 6,	// 주파수 예약
				
				EndOfType
			};
		}
		
		
		/*
			음계 데이터
		 */
		namespace Scale
		{
			enum Type
			{
				C1, CS1, D1, DS1, E1, F1, FS1, G1, GS1, A1, AS1, B1,
				C2, CS2, D2, DS2, E2, F2, FS2, G2, GS2, A2, AS2, B2,
				C3, CS3, D3, DS3, E3, F3, FS3, G3, GS3, A3, AS3, B3,
				C4, CS4, D4, DS4, E4, F4, FS4, G4, GS4, A4, AS4, B4,
				
				C5, CS5, D5, DS5, E5, F5, FS5, G5, GS5, A5, AS5, B5,
				C6, CS6, D6, DS6, E6, F6, FS6, G6, GS6, A6, AS6, B6,
				C7, CS7, D7, DS7, E7, F7, FS7, G7, GS7, A7, AS7, B7,
				C8, CS8, D8, DS8, E8, F8, FS8, G8, GS8, A8, AS8, B8,
			
				EndOfType,
				
				Mute	= 0xEE,		// 묵음
				Fin		= 0xFF		// 악보의 끝
			};
		}
	}


#endif