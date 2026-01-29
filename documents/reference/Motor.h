/*
	@file		Motor.h
	@brief		Motor 제어
 */


#ifndef HAL_MOTOR_H_
#define HAL_MOTOR_H_


#include "Types.h"
#include "HAL.IO.h"
#include "Base.h"


	namespace Motor
	{
		//		Motor	Tim		Pin
		//		M1		T2-2	A1
		//		M2		T2-1	A15
		//		M3		T2-3	B10
		//		M4		T2-4	A3
		namespace Part
		{
			enum Type
			{
				MFR,		// Front Right
				MRR,		// Rear Right
				MRL,		// Rear Left
				MFL,		// Front Left
					
				EndOfPart,
				
				All
			};
		}
		
		
		class Motor
		{
		public:
			s16					value;
		};
		
		
		class Device
		{
		private:
			static const s16	max = 1000;
			static const s16	min = 0;
			
		public:
			Motor				motor[Part::EndOfPart];
			
		public:
			TIM_HandleTypeDef	htim;
				
		public:	
			void				init();			// 초기화
			void				initHardware();
			
			void				initMspTim2();
            void				deinitMspTim2();
	
			void				set(Part::Type part, s16 value, bool flagForce = false);		// 모터 출력 설정
				
			void				stop();			// 정지
			void				sleep();		// 슬립
		};
	}

	extern Motor::Device MOTOR;


#endif /* HAL_MOTOR_H_ */

