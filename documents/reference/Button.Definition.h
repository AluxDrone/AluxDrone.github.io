/*
	@file		Input.Definition.h
	@brief		조이스틱, 버튼 입력 정의
 */


#ifndef BUTTON_DEFINITION_H_
#define BUTTON_DEFINITION_H_


#include "Base.h"
#include "HAL.IO.h"


	namespace Button
	{
		namespace Event
		{
			enum Type
			{
				None,
				
				Down,				// 누르기 시작
				Press,				// 누르는 중
				Up,					// 뗌
				
				EndContinuePress	// 연속 입력 종료
			};
		}	
	
		
		namespace State
		{
			enum Type
			{
				Ready,				// 입력 대기 상태
				PressStart,			// 입력 시작
				Press,				// 입력
				Release,			// 연속 입력 해제
				Clear,				// 연속 입력 카운트 초기화
			};
		}
		
		
		namespace Drone
		{
			namespace ButtonType
			{
				enum Type
				{
					None		= 0x0000,
					
					// 버튼
					Pairing		= 0x0001,
				};
			}
			
			
			// 버튼 배열에 접근하기 위한 인덱스
			namespace ButtonIndex
			{
				enum Type
				{
					Pairing,
					
					EndOfType
				};
			}
		}

		
		namespace Controller
		{
			namespace ButtonType
			{
				enum Type
				{
					None				= 0x0000,
									
					// 버튼
					FrontLeftTop		= 0x0001,
					FrontLeftBottom		= 0x0002,
					FrontRightTop		= 0x0004,
					FrontRightBottom	= 0x0008,
					
					TopLeft				= 0x0010,
					TopRight			= 0x0020,	// POWER ON/OFF
					
					MidUp				= 0x0040,
					MidLeft				= 0x0080,
					MidRight			= 0x0100,
					MidDown				= 0x0200,
					
					BottomLeft			= 0x0400,
					BottomRight			= 0x0800,
				};
			}
			
			
			// 버튼 배열에 접근하기 위한 인덱스
			namespace ButtonIndex
			{
				enum Type
				{
					FrontLeftTop,
					FrontLeftBottom,
					FrontRightTop,
					FrontRightBottom,
					
					TopLeft,
					TopRight,
					
					MidUp,
					MidLeft,
					MidRight,
					MidDown,
					
					BottomLeft,
					BottomRight,
					
					EndOfType
				};
			}
		}

		
		class Fixed
		{
		public:
			static const u16		buttonTypeNone	= 0;
			static const u16		sizeOfArray		= Drone::ButtonIndex::EndOfType;
		};
	}


#endif