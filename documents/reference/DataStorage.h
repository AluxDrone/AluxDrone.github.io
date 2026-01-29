

#ifndef DATASTORAGE_H_
#define DATASTORAGE_H_


#include "Base.h"
#include "Protocol.h"
#include "HAL.Jumper.h"
#include "Card.Definition.h"


	namespace DataStorage
	{
		class Fixed
		{
		public:
			static const u32			sizeOfBlock	= 1024;		// 블럭 하나의 크기를 1024byte로 정함
			static const u8				sizeOfCrc	= 2;
			static const u32			addressEnd  = HAL::Jumper::Address::dataApp + (sizeOfBlock * 4);
		};	
		
		#pragma pack(1)
		class DataBlock 				// 8+13+3+4+12+1+8+6+4+4+
		{
		public:
			u64							timeRunSystem;			// 시스템 동작 시간
						
			Pairing						pairing;	
			
			u8							modeControlFlight;		// 비행 제어 모드
			u8							headless;				// 헤드리스 모드
			u8							controlSpeed;			// 제어 속도
			
			s16							trimFlightRoll;
			s16							trimFlightPitch;
			s16							trimFlightYaw;
			s16							trimFlightThrottle;
			
			s16							accelX;
			s16							accelY;
			s16							accelZ;			
			s16							gyroRoll;
			s16							gyroPitch;
			s16							gyroYaw;			
			u8							flagGyroBiasUpdated;			
			
			u64							timeRunFlight;			// 비행 시간(누적)
			Protocol::Light::ModeColor	ledModeColorBody;		// 6			
			u8							optionFlagsSetup;
			u32							counter[Counters::EndOfType];
			
			u16							cardReaderRange[2][3][2];	// [front, rear][r, g, b][min, max]
			s8							cc[2][6][3][2];				// [front, rear][r, y, g, c, b, m][h, s, l][min, max] / [2 * 6 * 3 * 2]
			s8							l[2][2];					// [front, rear][min, max]
			u8							c[Card::Fixed::sizeOfList];			// 카드 코딩
			u8							f[Card::Fixed::sizeOfList];			// 함수
			s16							sizeCard;
			s16							sizeFunction;		
			
			u8							cm[Card::Fixed::sizeOfList];			// 멜로디
			s16							size;								
			
		private:
			u16							crc16;								// CRC
							
		public:	
			bool						checkWithCrc();						// 플래시에서 데이터를 정상적으로 읽었는지 확인
			void						reset(bool isSetDefalut = false);	// 플래시에서 데이터를 읽지 못했을 경우 데이터 채움
			void						loadWithCrc();						// 플래시에 쓸 데이터 채우기
			void						apply();							// 데이터 블럭의 값을 관련된 변수에 복사
		};
		#pragma pack()
		
		
		// Flash 메모리에 데이터를 저장
		class Device
		{
		public:
			DataBlock					dataBlock;							
			u32							addressNow;							// 최신 데이터가 저장된 위치
	
		private:	
			volatile bool				flagChanged;						// 플래시 메모리에 저장할 데이터가 변경되었는지를 저장하는 변수
			volatile u32				timeChanged;						// 저장할 데이터가 변경된 시간
				
		public:	
			void						init();								// 초기화
			void						read();								// 가장 큰 인덱스를 가지고 있는 데이터 블럭을 찾아서 적용 해당 블럭의 전체 데이터는 dataArea에 저장, 제대로 읽지 못한 데이터가 있으면 false 반환
			bool						write(bool flagForce = false);		// 데이터를 플래시 메모리에 저장
			void						setDefault();						// 초기화
			// void						reset(bool flagAll);
				
			void						changed();							// 플래시 메모리에 저장할 데이터가 변경 된 경우 호출
		};
	}

	extern DataStorage::Device DATASTORAGE;


#endif

