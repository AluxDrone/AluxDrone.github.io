/*
	@file		Protocol.External.h
	@brief		드론 몸체에 직접 연결되는 외부 장치 관련 정의
 */


#ifndef PROTOCOL_EXTERNAL_H_
#define PROTOCOL_EXTERNAL_H_


	namespace Protocol
	{
		namespace External
		{
			namespace Camera
			{
				/*
					카메라 동작 모드
				 */
				namespace ModeCamera
				{
					enum Type
					{
						None				= 0x00,		// 
						Stop				= 0x01,		// 장치 동작 멈춤
						Error				= 0x02,		// 장치 오류
						
						Camera				= 0x10,		// 카메라 작동
						Recording			= 0x11,		// 영상 저장
						
						EndOfType
					};
				}
				
				
				/*
					카메라 명령
				 */
				namespace CommandType
				{
					enum Type
					{
						None				= 0x00,		// 
						Stop				= 0x01,		// 장치 동작 멈춤
						
						VideoCapture		= 0x10,		// 영상 촬영 중 한 프레임을 저장
						VideoRecordingStart	= 0x11,		// 영상 저장 시작
						VideoRecordingStop	= 0x12,		// 영상 저장 중단
						
						TakePhoto			= 0x20,		// 영상 촬영을 잠시 중단하고 사진 촬영
						
						EndOfType
					};
				}
				
				
				
				/*
					DataType.ExternalCameraState
				 */
				#pragma pack(1)
				class State
				{
				public:
					u8			modeCamera;		// 카메라 동작 모드
					u16			fps;			// 초당 프레임 수
				};
				#pragma pack()
				
				
				/*
					DataType.ExternalCameraCommand
				 */
				#pragma pack(1)
				class Command
				{
				public:
					u8			commandType;	// 카메라 명령
				};
				#pragma pack()
			}
		}
	}


#endif /* PROTOCOL_EXTERNAL_H_ */

