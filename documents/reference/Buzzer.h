/*
	@file		Buzzer.h
	@brief		부저 제어
 */


#ifndef BUZZER_H_
#define BUZZER_H_


#include "Protocol.h"
#include "Buzzer.Definition.h"
#include "Buzzer.Melody.h"
#include "Queue.Block.h"


	namespace Buzzer
	{
		/*
			음계와 시간 길이를 담은 구조체
		 */
		class MelodyData
		{
		public:
			Scale::Type	scale;
			u16			time;
		};
		
		
		/*
			소리 구조체
		 */
		#pragma pack(1)
		class SoundBlock
		{
		public:
			u8			octab;			// 옥타브(1~8옥타브까지의 값이 숫자로 저장됨)
			u32			mhz;			// Millihertz(hz * 1000)
			u16			time;			// 해당음을 연주할 시간
		};
		#pragma pack()
		
		
		class Fixed
		{
		public:
			static const u64			systemClock = 168000000000ll;	// TIM9 on APB2: 168MHz (PCLK2=84MHz × 2)
			
			static const u8				sizeOfMelody = 16;		// 멜로디를 담을 크기
			static const u8				sizeOfBuffer = 128;		// 버퍼의 크기
			
			static const u32			scaleHzData[12];
			
			static const MelodyData		mdStorage[Melody::EndOfType][sizeOfMelody];
		};
		
		
		class DataBlockPlay
		{
		public:
			//SoundBlock					sdBuffer[Fixed::sizeOfBuffer];
			u8							sdBuffer[sizeof(SoundBlock) * Fixed::sizeOfBuffer];
			Queue::Block				qbSound;
			
			SoundBlock					soundBlock;
			u64							timePlayNext;
			
			volatile bool				flagPlay;
		};
		
		
		/*
			@class		Buzzer::Device
			@brief		부저 제어 클래스
		 */
		class Device
		{
		private:
			DataBlockPlay				dbPlay;
			
		public:
			TIM_HandleTypeDef			htim;
			
		private:
			void						initTimer();
			
			void						on(u16 prescale, u16 period);
			void						off();
			
			void						play();
			void						sound();
			
		public:
			void						init();				// 초기화
			void						initMsp();			// 초기화
			
			void						run();
			
			void						reserve(Melody::Type newMelody);		// 예약
			void						reserve(Scale::Type scale, u16 time);	// 예약
			void						reserve(u16 hz, u16 time);				// 예약
			
			void						set(Melody::Type newMelody);			// 바로 실행
			void						set(Scale::Type scale, u16 time);		// 바로 실행
			void						set(u16 hz, u16 time);					// 바로 실행
			
			void						stop();
			
			bool						isPlaying()		{ return dbPlay.flagPlay; }
		};
	}

	extern Buzzer::Device BUZZER;


#endif