/*
	@file		Protocol.h
	@brief		타입 정의 모음
 */


#ifndef PROTOCOL_H_
#define PROTOCOL_H_


#include "Base.h"

#include "Protocol.Battle.h"
#include "Protocol.Card.h"
#include "Protocol.Command.h"
#include "Protocol.Communication.h"
#include "Protocol.Controller.h"
#include "Protocol.Default.h"
#include "Protocol.Drone.h"
#include "Protocol.Light.h"
#include "Protocol.Link.h"
#include "Protocol.Monitor.h"


	/*

		*	Protocol을 사용하기 위한 규칙 정의(2016.12.06)

		1.	데이터 송수신에 사용하는 자료형은 프로젝트 자체에서 사용하고 있는 것들을 가능하면 그대로 쓰고,
			프로젝트 내부에서 사용하지 않으면서 데이터 송수신 시에만 사용하는 객체와 열거형들만
			Protocol.*.h 파일에 별도로 정의합니다.

		2.	대부분의 공통 자료형은 'Base.*.h' 파일에 담겨있으며, 여기에 정의되지 않은 자료형 및 열거형은
			'객체이름.Definition.h' 파일에 담겨있습니다.

	 */

	/*
		*	Protocol.*.h 파일들에 대한 설명

		1.	Protocol.Base.h
			데이터 송수신 시 사용되는 다른 구조체에 포함되거나 다른 클래스에 상속받는 대상이 되는 객체 정의 모음

		2.	Protocol.Default.h
			데이터 송수신 시 사용하는 기본 구조체 모음

		3.	Protocol.h
			데이터 송수신 시 사용하는 기본 정의 모음(데이터 종류, 명령 등)

		4.	Protocol.Light.h
			펌웨어 업데이트와 관련된 구조체 모음

		5.	Protocol.Zigbee.h
			Zigbee 통신과 관련된 구조체 모음


	 */

	/*

				종류		0x1234의 표현	0x12345678의 표현
			  빅 엔디언			12 34			12 34 56 78
			리틀 엔디언			34 12			78 56 34 12

		- 빅 엔디언은 사람이 숫자를 쓰는 방법과 같이 큰 단위의 바이트가 앞에 오는 방법
		- 리틀 엔디언은 반대로 작은 단위의 바이트가 앞에 오는 방법
		- x86 아키텍처를 사용하는 대부분의 데스크톱 컴퓨터는 리틀 엔디언을 쓰며 이를 ‘인텔 포맷’이라 한다.
		- ARM 프로세서들은 성능 향상을 위해 빅 엔디언과 리틀 엔디언을 선택할 수 있도록 되어 있다.

		데이터 전송 시 변수에서 상위 바이트가 배열의 뒤쪽(배열의 인덱스 값이 더 큼)에 위치함(C# BitConverter 사용 시)

			u32		value	= 0x12345678
			u8		* data	= (u8 *)&value;

		 	->	data[0] = 0x78
				data[1] = 0x56
				data[2] = 0x34
				data[3] = 0x12

	 */


	namespace Protocol
	{

		/*
			송수신 페이로드
		 */
		// Payload for Controller
		namespace Payload
		{
			static const u8 RX = 2 + 4 + 24 + 2;		// Start + Header + Data + CRC
			static const u8 TX = 2 + 4 + 24 + 2;		// Start + Header + Data + CRC
		}

		/*
			데이터의 길이
		 */
		class Length
		{
		public:
			static const u8	Start	= 2;	// 시작 코드
			static const u8	Header	= 4;	// 헤더
			static const u8 Crc		= 2;	// CRC의 길이
		};


		/*
			Header
		 */
		#pragma pack(1)
		struct Header
		{
			u8		dataType;		// 전송할 데이터 타입
			u8		length;			// 전송할 데이터 길이
			u8		from;			// 데이터를 전송하는 장치(DeviceType)
			u8		to;				// 데이터를 수신받는 장치(DeviceType)
		};
		#pragma pack()


		/*
			송수신 데이터 타입 정의
		 */
		namespace DataType
		{
			enum Type
			{
				None						= 0x00,		// 없음
				Ping						= 0x01,		// 통신 확인
				Ack							= 0x02,		// 데이터 수신에 대한 응답
				Error						= 0x03,		// 오류
				Request						= 0x04,		// 지정한 타입의 데이터 요청
				// Message						= 0x05,		// 문자열 데이터
				Address						= 0x06,		// 장치 주소(MAC이 있는 경우 MAC) 혹은 고유번호(MAC이 없는 경우 UUID)
				Information					= 0x07,		// 펌웨어 및 장치 정보
				Update						= 0x08,		// 펌웨어 업데이트
				UpdateLocation				= 0x09,		// 펌웨어 업데이트 위치 정정
				// Encrypt						= 0x0A,		// 펌웨어 암호화
				// SystemCount					= 0x0B,		// 시스템 카운트
				// SystemInformation			= 0x0C,		// 시스템 정보
				// Registration				= 0x0D,		// 제품 등록(암호화 데이터 및 등록 데이터를 데이터 길이로 구분)
				// Administrator				= 0x0E,		// 관리자 권한 획득
				Monitor						= 0x0F,		// 디버깅용 값 배열 전송. 첫번째 바이트에 타입, 두 번째 바이트에 페이지 지정(수신 받는 데이터의 저장 경로 구분)
				Control						= 0x10,		// 조종
				
				Command						= 0x11,		// 명령
				Pairing						= 0x12,		// 페어링
				ResponseRate				= 0x13,		// ResponseRate
				// TimeSync					= 0x14,		// 시간 동기화
				// TransmissionPower			= 0x15,		// 전송 출력
				// Configuration				= 0x16,		// 설정
				cpuId 						= 0x1E,		// cpuid(u_id)
				// Battle						= 0x1F,		// 전투
				
				// Light
				LightManual					= 0x20,		// LED 수동 제어
				LightMode					= 0x21,		// LED 모드 지정
				LightEvent					= 0x22,		// LED 이벤트
				LightDefault				= 0x23,		// LED 기본 색상
				
				// 센서 RAW 데이터
				RawMotion					= 0x30,		// Motion 센서 데이터 RAW 값
				RawFlow,								// Flow 센서 데이터 RAW 값
				
				// 상태,  센서
				State						= 0x40,		// 드론의 상태(비행 모드, 방위기준, 배터리량)
				Attitude,								// 드론의 자세(Angle)(Attitude)
				Position,								// 위치
				Altitude,								// 높이, 고도
				Motion,									// Motion 센서 데이터 처리한 값(IMU)
				Range, 									// 거리센서 데이터
				Flow,									// optical flow 센서
				
				// 설정
				Count						= 0x50,		// 카운트
				Bias,									// 엑셀, 자이로 바이어스 값
				Trim,									// 트림
				// Weight,									// 무게 설정
				LostConnection,							// 연결이 끊긴 후 반응 시간 설정
				
				// Device
				Motor						= 0x60,		// 모터 제어 및 현재 제어값 확인
				MotorSingle,							// 한 개의 모터 제어
				Buzzer,									// 버저 제어
				Vibrator,								// 진동 제어
				Battery,								// 배터리
				
				// Input
				Button						= 0x70,		// 버튼
				Joystick,								// 조이스틱
				
				// Display
				DisplayClear				= 0x80,		// 화면 지우기
				DisplayInvert,                          // 화면 반전
				DisplayDrawPoint,                       // 점 그리기
				DisplayDrawLine,                        // 선 그리기
				DisplayDrawRect,                        // 사각형 그리기
				DisplayDrawCircle,                      // 원 그리기
				DisplayDrawString,                      // 문자열 쓰기
				DisplayDrawStringAlign,                 // 문자열 쓰기
				DisplayDrawImage,                 		// 그림 그리기
				
				// Card
				CardClassify				= 0x90,		// 카드 색상 분류 기준 설정
				CardRange,								// 카드 색 범위(RAW 데이터의 출력 범위)
				CardRaw,								// 카드 데이터 RAW 값(유선으로만 전송)
				CardColor,								// 카드 데이터
				CardList,								// 카드 리스트 데이터
				CardFunctionList,						// 카드 함수 리스트 데이터
				// CardClassifyRaw,						// 카드 색상 분류(Raw)
				
				// Information Assembled
				InformationAssembledForController		= 0xA0,		// 데이터 모음
				InformationAssembledForEntry			= 0xA1,		// 데이터 모음
				InformationAssembledForByBlocks			= 0xA2,		// 데이터 모음
				EndOfType
			};
		}


		/*
			커맨드
		 */
		namespace CommandType
		{
			enum Type
			{
				None						= 0x00,		// 이벤트 없음
				
				Stop						= 0x01,		// 정지
				
				ModeControlFlight			= 0x02,		// 비행 제어 모드 설정
				Headless					= 0x03,		// 헤드리스 모드 설정
				ControlSpeed				= 0x04,		// 제어 속도 설정
				
				ClearBias					= 0x05,		// 자이로/엑셀 바이어스 리셋(트림도 같이 초기화 됨)
				ClearTrim					= 0x06,		// 트림 초기화
				
				FlightEvent					= 0x07,		// 비행 이벤트 실행
				
				SetDefault					= 0x08,		// 기본 설정으로 초기화
				Backlight					= 0x09,		// 조종기 백라이트 설정
				ModeController				= 0x0A,		// 조종기 동작 모드(0x10:조종, 0x80:링크)
				Link						= 0x0B,		// 링크 제어(0:Client Mode, 1:Server Mode, 2:Pairing Start)
				LoadDefaultColor			= 0x0C,		// 기본 색상으로 변경
				
				Trim						= 0x0D,		// 트림
				
				ModeTest					= 0xF0,		// 테스트 락(테스트를 완료하기 전까진 사용 불가 / 27:활성화, 11:해제))
				
				ResetTimeCount				= 0xFC,		// 테스트 시간 삭제 option 37
				
				RfChannel					= 0xFD,		// 2400, 2440, 2483
				RfModulate					= 0xFE,		// Modulate, Rx, Unmodulate						
				
				EndOfType
			};
		}
	}



#endif