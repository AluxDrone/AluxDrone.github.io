/*
	@file		Protocol.Navigation.h
	@brief		데이터 송수신에 사용하는 데이터 구조체 모음
 */


#ifndef PROTOCOL_NAVIGATION_H_
#define PROTOCOL_NAVIGATION_H_
			 

	namespace Protocol
	{
		/*
		
			NavigationTarget 송수신 데이터 구조 정의
			
			 1.	드론 및 GCS에서 가지고 있는 NavigationTarget 원본 구조체는 아래의 개별 구조체들을 모두 통합한 형태이나
				데이터 송수신 시에는 길이의 제한이 있으므로 각 행동에 맞는 데이터만 전송하고,
				비어있는 부분은 모두 0으로 초기화해서 사용.
			
			 2.	공통으로 명령 번호와 시간(실행 시간 또는 이동 제한)은 단위로 초를 사용하고, u16 변수에 담아서 전송
		
			 3. GCS에서 드론에 데이터 전송 시 드론은 받은 데이터를 그대로 GCS에 응답으로 전달 GCS는 응답으로 돌려받은
				데이터와 전송한 데이터를 비교하여 일치하는 경우 다음 목표점 데이터를 전송하게 할 것
		
			 4. 드론 방향 제어는 NavigationTargetAction을 사용하고 option에 heading을 degree 값으로 넣어서 전송
		
			 5. 드론 이동은 드론이 향하고 있는 방향에 상관없이 움직여야함 - 드론의 방향 제어는 촬영을 위한 것
		
		 */
		
		/*
			DataType.NavigationTarget
			NavigationTarget의 원형 데이터(실제로는 크기가 커서 전송할 수 없기 때문에 
			몇 개의 반드시 필요한 세부 사항만 가진 작은 데이터 블록으로 전송함
		
			Wildconnect.Navigation.DataModel.Target
		 */
		#pragma pack(1)
		class NavigationTargetRaw
		{
		public:
			u32			index;				// 명령 번호
			
			u32			modeBehavior;		// 행동
			
			f64			latitude;			// 위도(Y)
			f64			longitude;			// 경도(X)
			f32			altitude;			// 고도(Z)
			f32			speed;				// 이동속도(m/s)
			
			f32			heading;			// 헤딩(degree, compass 0 ~ 360)
			f32			rotationalSpeed;	// 헤딩 회전 속도
			
			u32			time;				// 실행 시간(ms)
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationTarget
			이동
			modeBehavior가 항상 move이므로 공간을 절약하기 위해 변수에서는 제거함
		 */
		#pragma pack(1)
		class NavigationTargetMove
		{
		public:
			u8			index;				//  1 명령 번호
			
			f64			latitude;			//  9 위도(Y)
			f64			longitude;			// 17 경도(X)
			f32			altitude;			// 21 고도(Z)
			u8			speed;				// 22 속도(m/s) (0.0 ~ 255 m/s)
			
			s16			heading;			// 24 헤딩(degree, compass 0 ~ 360)
			//s16			rotationalSpeed;	// 26 회전 속도(deg/sec) (-180 ~ +180)
			s8			rotationalSpeed;	// 26 회전 속도(deg/sec) (-120 ~ +120)
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationTarget
			행동(이륙, 착륙, 대기)
		 */
		#pragma pack(1)
		class NavigationTargetAction
		{
		public:
			u8			index;				//  1 명령 번호
			
			u16			modeBehavior;		//  3 행동
			
			u32			time;				//  5 실행 시간(ms)
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationLocation
		 */
		#pragma pack(1)
		class NavigationLocation
		{
		public:
			u8			fixType;			//  1 fixType
			u8			numSV;				//  2 Number of satellites used in Nav Solution
				
			f64			latitude;			// 10 현재위치, 위도(Y)
			f64			longitude;			// 18 현재위치, 경도(X)
			f32			altitude;			// 22 현재위치, 고도(Z)
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationLocationAdjust
		 */
		#pragma pack(1)
		class NavigationLocationAdjust
		{
		public:
			u8			mode;				//  1 0: 초기화, 1: 위치 보정, 2: 네비게이션 시뮬레이션 모드 전환 및 가상 위치 지정
			f64			latitude;			//  8 보정할 위치, 위도(Y)
			f64			longitude;			// 16 보정할 위치, 경도(X)
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationMonitor
		 */
		#pragma pack(1)
		class NavigationMonitor
		{
		public:
			u8			modeNavigation;		//  1 네비게이션 작동 상태
			
			f32			distanceToTarget;	//  5 목표점까지의 거리
			f32			velocity;			//  9 속도
			f32			heading;			// 13 헤딩
			u32			timeRemain;			// 17 남은 시간
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationHeading
		 */
		#pragma pack(1)
		class NavigationHeading
		{
		public:
			f32			heading;			//  4 헤딩
			f32			headingPath;		//  8 targetPath의 방향
			f32			headingToTarget;	// 12 현재 위치로부터 목표점까지 선을 이었을 때의 방향
			f32			headingError;		// 16 headingToTarget과 heading의 차이
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationCounter
		 */
		#pragma pack(1)
		class NavigationCounter
		{
		public:
			u16			countPerSecRfReceive;
			u16			countPerSecRfTransfer;
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationSatellite
		 */
		#pragma pack(1)
		class NavigationSatellite
		{
		public:
			u32			iTOW;					//  4 GPS time of week of the navigation epoch.
												//    See the description of iTOW for details.
			u16			year;					//  6
			u8			month;					//  7
			u8			day;					//  8
			u8			hour;					//  9
			u8			min;					// 10 
			u8			sec;					// 11
			u8			valid;					// 12 UBX_NAV_PVT_valid
			u8			flags;					// 13 UBX_NAV_PVT_flags
			u8			flags2;					// 14 UBX_NAV_PVT_flags2
			s32			gSpeed;					// 19
			u16			pDOP;					// 21
		};
		#pragma pack()
		
		
		/*
			DataType.NavigationTargetEcef
			DataType.NavigationLocationEcef
		 */
		#pragma pack(1)
		class NavigationLocationXYZ
		{
		public:
			f64			x;			// 10 현재위치, X
			f64			y;			// 18 현재위치, Y
			f32			z;			// 22 현재위치, X
		};
		#pragma pack()
	}


#endif
