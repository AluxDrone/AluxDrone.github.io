/*
	@file		Protocol.Drone.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_DRONE_H_
#define PROTOCOL_DRONE_H_


	namespace Protocol
	{
		/*
			DataType.Configuration
			현재 2바이트 사용 중
		 */
		#pragma pack(1)
		class Configuration
		{
		public:
			u16			index;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - MOTION 센서 Raw 데이터
		 */
		#pragma pack(1)
		class RawMotion
		{
		public:
			s16			accelX;
			s16			accelY;
			s16			accelZ;
			
			s16			gyroRoll;
			s16			gyroPitch;
			s16			gyroYaw;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Flow 센서 Raw 데이터
		 */
		#pragma pack(1)
		class RawFlow
		{
		public:
			float		x;
			float		y;
		};
		#pragma pack()


		/*
			DataType.State
		 */
		#pragma pack(1)
		class State
		{
		public:
			u8			modeSystem;				// boot, running
			u8			modeFlight;				// ready, start, takeoff, landing
			
			u8			modeControlFlight;		// Attitude,Poition,Manual,Rate,Function, BirdWing, FixedWing
			u8			modeMovement;			// 이동 상태
			u8			headless;				// 헤드리스 모드
			u8			controlSpeed;			// 제어 속도
			u8			sensorOrientation;		// 센서 방향
			u8			battery;				// 배터리량(0 ~ 100)
		};
		#pragma pack()


		/*
			DataType.Attitude
		 */
		#pragma pack(1)
		class Attitude
		{
		public:
			s16			roll;		// Roll
			s16			pitch;		// Pitch
			s16			yaw;		// Yaw
		};
		#pragma pack()

		
		/*
			DataType.Altitude
		 */
		#pragma pack(1)
		class Altitude
		{
		public:
			float		temperature;
			float		pressure;
			float		altitude;
			float		rangeHeight;
		};
		#pragma pack()

		
		/*
			데이터 구조체 - MOTION 센서 RAW 데이터와 Angle
		 */
		#pragma pack(1)
		class Motion
		{
		public:
			s16			accelX;
			s16			accelY;
			s16			accelZ;
			
			s16			gyroRoll;
			s16			gyroPitch;
			s16			gyroYaw;
			
			s16			angleRoll;
			s16			anglePitch;
			s16			angleYaw;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Range 센서
		 */
		#pragma pack(1)
		class Range
		{
		public:
			s16			left;
			s16			front;
			s16			right;
			s16			rear;
			s16			top;
			s16			bottom;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Flow 센서 데이터
		 */
		#pragma pack(1)
		class Flow
		{
		public:
			float		x;
			float		y;
			float		z;	// Range Sensor Height
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Range 센서
		 */
		#pragma pack(1)
		class Range3
		{
		public:
			s16			left;
			s16			front;
			s16			right;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Range 센서
		 */
		#pragma pack(1)
		class Range5
		{
		public:
			s16			left;
			s16			front;
			s16			right;
			s16			rear;
			s16			top;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - Position
		 */
		#pragma pack(1)
		struct Position
		{
			float		x;
			float		y;
			float		z;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - PositionVelocity
		 */
		#pragma pack(1)
		struct PositionVelocity
		{
			float		x;
			float		y;
			float		z;			
			float		vx;
			float		vy;
			float		vz;
		};
		#pragma pack()		
		
		
		/*
			DataType.
		 */
		#pragma pack(1)
		class Bias
		{
		public:
			s16			accelX;
			s16			accelY;
			s16			accelZ;
			
			s16			gyroRoll;		// Roll
			s16			gyroPitch;		// Pitch
			s16			gyroYaw;		// Yaw
		};
		#pragma pack()


		/*
			DataType.Trim
		 */
		#pragma pack(1)
		class Trim
		{
		public:
			s16			roll;
			s16			pitch;
			s16			yaw;
			s16			throttle;
		};
		#pragma pack()


		/*
			DataType.Weight
		 */
		#pragma pack(1)
		class Weight
		{
		public:
			float		weight;
		};
		#pragma pack()
		
		
		/*
			DataType.LostConnection
		 */
		#pragma pack(1)
		class LostConnection
		{
		public:
			u16			timeNeutral;				// 조종 중립
			u16			timeLanding;				// 착륙
			u32			timeStop;   				// 정지
		};
		#pragma pack()


		/*
			DataType.MagnetometerOffset
		 */
		#pragma pack(1)
		class MagnetometerOffset
		{
		public:
			s16		offset;
		};
		#pragma pack()


		namespace Control
		{
			#pragma pack(1)
			class Quad8
			{
			public:
				s8			roll;
				s8			pitch;
				s8			yaw;
				s8			throttle;
			};
			#pragma pack()
			
			
			#pragma pack(1)
			class Quad8AndRequestData
			{
			public:
				s8			roll;
				s8			pitch;
				s8			yaw;
				s8			throttle;
				
				u8			dataType;
			};
			#pragma pack()
			
			
			#pragma pack(1)
			class Position16
			{
			public:
				s16			positionX;				// meter	x 10
				s16			positionY;				// meter	x 10
				s16			positionZ;				// meter	x 10
				
				s16			velocity;				// m/s		x 10
				
				s16			heading;				// degree
				s16			rotationalVelocity;		// deg/s
			};
			#pragma pack()
			
			
			#pragma pack(1)
			class Position
			{
			public:
				float		positionX;				// meter
				float		positionY;				// meter
				float		positionZ;				// meter
				
				float		velocity;				// m/s
				
				s16			heading;				// degree
				s16			rotationalVelocity;		// deg/s
			};
			#pragma pack()
		}
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		class MotorV
		{
		public:
			s16			value;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		class MotorRV
		{
		public:
			u8			rotation;
			s16			value;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		class MotorVA
		{
		public:
			s16			value;
			s16			adc;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		class MotorRVA
		{
		public:
			u8			rotation;
			s16			value;
			s16			adc;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		V
		{
		public:
			u8			target;
			s16			value;
		};
		#pragma pack()
		
		
		/*
			데이터 구조체 - 모터 제어
		 */
		#pragma pack(1)
		class MotorSingleRV
		{
		public:
			u8			target;
			u8			rotation;
			s16			value;
		};
		#pragma pack()
		
		
		/*
			DataType.InformationAssembledForController
			현재 18바이트 사용 중
		 */
		#pragma pack(1)
		class InformationAssembledForController
		{
		public:
			s16			angleRoll;				// 자세 Roll
			s16			anglePitch;				// 자세 Pitch
			s16			angleYaw;				// 자세 Yaw
			
			u16			rpm;					// RPM
			
			s16			positionX;				// meter x 10
			s16			positionY;				// meter x 10
			s16			positionZ;				// meter x 10
			
			s8			speedX;					// meter x 10
			s8			speedY;					// meter x 10
			
			u8			rangeHeight;			// meter x 100
			
			u8			responseRate;			// responseRate
		};
		#pragma pack()
		

		/*
			DataType.InformationAssembledForEntry
		 */
		#pragma pack(1)
		class InformationAssembledForEntry
		{
		public:
			s16			angleRoll;
			s16			anglePitch;
			s16			angleYaw;
			
			s16			positionX;
			s16			positionY;
			s16			positionZ;
			
			s16			rangeHeight;
			float		altitude;
		};
		#pragma pack()
		
		
		/*
			DataType.InformationAssembledForByblocks
		 */
		#pragma pack(1)
		class InformationAssembledForByBlocks
		{
		public:
			s8			battery;			// 배터리 잔량
			
			s16			angleRoll;			// 자세 Roll
			s16			anglePitch;			// 자세 Pitch
			s16			angleYaw;   		// 자세 Yaw
			
			s16			positionX;			// meter x 10
			s16			positionY;			// meter x 10
			s16			positionZ;			// meter x 10
			
			s16			rangeLeft;			// meter x 1000
			s16			rangeFront;			// meter x 1000
			s16			rangeRight;			// meter x 1000
			s16			rangeBottom;		// meter x 1000
		};
		#pragma pack()
	}


#endif