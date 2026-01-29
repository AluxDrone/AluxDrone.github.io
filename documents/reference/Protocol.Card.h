/*
	@file		Protocol.Card.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_CARD_H_
#define PROTOCOL_CARD_H_


	namespace Protocol
	{		
		namespace Card
		{
			/*
				데이터 구조체 - 카드 색상 분류
			 */
			#pragma pack(1)
			class Classify
			{
			public:
				s8			index;
				s8			cc[6][3][2];		// [front, rear, line][r, y, g, c, b, m][h, s, l][min, max] - h는 +-60 범위 사용. s, l은 x100을 적용하여 0~100 범위 사용
				s8			l[2];				// [front, rear, line][min, max] / min 이하는 black, white 이상은 white
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - 카드(Total 24 byte)
			 */
			#pragma pack(1)
			class Range
			{
			public:
				s16			range[2][3][2];		// [Front/Rear][R/G/B][Min/Max]		24 byte
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - 카드(Total 37 byte)
			 */
			#pragma pack(1)
			class RawLight
			{
			public:
				s16			rgbRaw[2][3];		// [Front/Rear][R/G/B]				12 byte
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - 카드(Total 37 byte)
			 */
			#pragma pack(1)
			class Raw
			{
			public:
				s16			rgbRaw[2][3];		// [Front/Rear][R/G/B]				12 byte
				u8			rgbBody[2][3];		// [Front/Rear][R/G/B]				 6 byte
				s16			hsvl[2][4];			// [Front/Rear][R/G/B]				16 byte
				u8			color[2];			// [Front/Rear]						 2 byte
				u8			card;				// 									 1 byte
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - ADC 출력
			 */
			#pragma pack(1)
			class RawAdcForTester
			{
			public:
				s16			front;
				s16			rear;
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - 카드(Total 19 byte)
			 */
			#pragma pack(1)
			class Color
			{
			public:
				s16			hsvl[2][4];			// [Front/Rear][H/S/V/L]			16 byte
				u8			color[2];			// [Front/Rear]						 2 byte
				u8			card;				// 									 1 byte
			};
			#pragma pack()
			
			
			/*
				데이터 구조체 - 카드(Total 15 byte)
			 */
			#pragma pack(1)
			class List
			{
			public:
				u8			index;				// 현재 실행중인 카드의 인덱스
				u8			size;				// 입력된 카드의 총 갯수
				
				u8			cardIndex;			// 현재 전송하는 카드 배열의 시작 번호
				u8			card[12];
			};
			#pragma pack()
		}
	}


#endif

