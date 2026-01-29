/*
	@file		Base.h
	@brief		공통 include 파일
 */


#ifndef BASE_MODE_H_
#define BASE_MODE_H_


	namespace Mode
	{
		/*
			System 동작 모드
		 */
		namespace System
		{
			enum Type
			{
				None,					// 없음
				
				Boot		= 0x10,		// 부팅
				Start,					// 시작 코드 실행
				Running,				// 메인 코드 동작
				ReadyToReset,			// 리셋 대기(1초 뒤 리셋)
				
				Error		= 0xA0,		// 오류
				
				EndOfType
			};
		}
		
		
		/*
			드론 모드
		 */
		namespace Drone
		{
			enum Type
			{
				None,					// 없음
				
				Flight		= 0x10,		// 비행
				Card,					// 카드 코딩
				Motion,					// 모션 코딩
				Piano,					// 피아노 모드
				
				Link		= 0x80,		// 중계
				Calibration,			// 컬러 캘리브레이션 모드
				
				Error		= 0xA0,		// 오류(문제로 인해 정상적인 동작을 할 수 없는 경우)
				
				EndOfType
			};
		}
		
		
		/*
			조종기 모드
		 */
		namespace Controller
		{
			enum Type
			{
				None,					// 없음
				
				Control		= 0x10,		// 조종
				Setup,					// 설정
				
				Link		= 0x80,		// 링크
				
				Error		= 0xA0,		// 오류
				
				EndOfType
			};
		}
		
		
		/*
			Link 모드
		 */
		namespace Link
		{
			enum Type
			{
				None,					// 없음
				
				Transponder	= 0x10,		// 중계
				Bypass,					// 바이패스
				
				Error		= 0xA0,		// 오류
				
				EndOfType
			};
		}
		
		
		/*
			비행 모드 
		 */
		namespace Flight
		{
			enum Type
			{
				None			= 0x00,		// 없음
				
				Ready			= 0x10,		// 준비
				
				Start,						// 이륙 준비
				Takeoff,					// 이륙 (Flight로 자동전환)
				Flight,						// 비행
				Landing,					// 착륙
				Flip,						// 회전
				Reverse,					// 뒤집기
				
				Stop			= 0x20,		// 강제 정지
				
				Accident		= 0x30,		// 사고 (Ready로 자동전환)
				Error,						// 오류
				
				Test			= 0x40,		// 테스트 모드
							
				EndOfType
			};
		}
		
		
		/*
			USB 동작 모드
		 */
		// USB를 대문자로 사용하면 충돌 발생
		namespace Usb
		{
			enum Type
			{
				None = 0,			// 없음
				
				HID,				// HID
				CDC,
					
				EndOfType
			};
		}

		
		namespace Control
		{
			/*
				비행 제어 방법
			 */
			namespace Flight
			{
				enum Type
				{
					None			= 0x00,		// 없음
					
					Attitude		= 0x10,		// 자세 - X,Y는 각도(deg)로 입력받음, Z,Yaw는 속도(m/s)로 입력 받음
					Position		= 0x11,		// 위치 - X,Y,Z,Yaw는 속도(m/s)로 입력 받음
					Manual			= 0x12,		// 고도를 수동으로 조종함
					Rate			= 0x13,		// Rate - X,Y는 각속도(deg/s)로 입력받음, Z,Yaw는 속도(m/s)로 입력 받음
					Function		= 0x14,		// 기능 - X,Y,Z,Yaw는 속도(m/s)로 입력 받음
					BirdWing		= 0x15,
					FixedWing		= 0x16,
					
					EndOfType
				};
			}
			
			
			/*
				조종 입력 모드
			 */
			namespace Input
			{
				enum Type
				{
					None = 0,			// 없음
				
					Mode1,				// Mode1
					Mode2,				// Mode2
					Mode3,				// Mode3
					Mode4,				// Mode4
					
					EndOfType
				};
			}
			
			
			/*
				이동 명령
			 */
			namespace Command
			{
				enum Type
				{
					None,
					
					Attitude,
					Position,
					
					EndOfType
				};
			}
		}


		/*
			Movement
		 */
		namespace Movement
		{
			enum Type
			{
				None			= 0x00,		// 없음
				
				Ready			= 0x01,
                Hovering        = 0x02,
                Moving          = 0x03,
				ReturnHome		= 0x04
			};
		}        
		
	}

#endif