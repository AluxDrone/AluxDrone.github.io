

#ifndef CORE_INFORMATION_H_
#define CORE_INFORMATION_H_


#include "Base.h"


	namespace Core
	{
		/*
			펌웨어 헤더
		 */
		#pragma pack(1)
		class FirmwareHeader
		{
		public:
			u32									modelNumber;	// 업데이트 대상 장치
			u32									version;		// 펌웨어 버젼[4byte][4개의 영역에 필요한 의미를 넣어서 사용]
			u32									length;			// 펌웨어 길이(RAW 펌웨어의 길이)[4byte]
							
			u16									year;			// 펌웨어 빌드 날짜[년 2byte]
			u8									month;			// 펌웨어 빌드 날짜[월 1byte]
			u8									day;			// 펌웨어 빌드 날짜[일 1byte]
		};
		#pragma pack()
		
		
		class Information
		{
		public:
			static const DeviceType::Type		deviceType;
			static const ModelNumber::Type		modelNumber;
				 
			static const Version				version;
			
			static const u16					year;
			static const u8						month;
			static const u8						day;
			
			static const u16					manufactuerYear;	
			static const u8						manufactuerMonth;	
			static const u8						manufactuerday;		
		};
	}


#endif