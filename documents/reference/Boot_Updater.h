

#ifndef BOOT_UPDATER_H_
#define BOOT_UPDATER_H_


#include "Base.h"


	namespace Updater
	{
		namespace ModeUpdate
		{
			enum Type
			{
				None,			// 
				
				Ready,			// 업데이트 가능 상태
				Update,			// 업데이트 중
				Complete,		// 업데이트 완료
					
				Failed,			// 업데이트 실패(업데이트 완료까지 갔으나 body의 CRC16이 일치하지 않는 경우 등)
				
				NotAvailable,	// 업데이트 불가능 상태(Debug 모드 등)
				RunApplication,	// 어플리케이션 동작 중
				
				EndOfType
			};
		}
		

		#pragma pack(1)
		class Header
		{
		public:
			u32						modelNumber;	// 업데이트 대상 장치
			u32						version;		// 펌웨어 버젼[4byte][4개의 영역에 필요한 의미를 넣어서 사용]
			u32						length;			// 펌웨어 길이(RAW 펌웨어의 길이)[4byte]
				
			u16						year;			// 펌웨어 빌드 날짜[년 2byte]
			u8						month;			// 펌웨어 빌드 날짜[월 1byte]
			u8						day;			// 펌웨어 빌드 날짜[일 1byte]
			
			u32						crc32body;
		};
		#pragma pack()
		
		
		class Device
		{
		private:
			static const u8		sizeOfDataBlock = 16;
			
		private:	
			ModeUpdate::Type	modeUpdate;												// 업데이트 모드
			
			Updater::Header		header;													// 펌웨어 헤더
			u32					timeStart;												// 펌웨어 업데이트 시작 시각
			u32					timeComplete;											// 펌웨어 업데이트 완료
			u32					addressUpdateStart;										// 데이터를 기록하기 시작할 위치
			u32					indexBlockNext;											// 다음 기록할 데이터의 인덱스
			u32					indexBlockEnd;											// 마지막 블럭 인덱스
			u32					crc32body;												// 실제 펌웨어 영역의 CRC16값(serialCode의 crc16body와 비교하여 일치할 때만 업데이트 완료 처리)
			u32					crc32firmware;
			
			u32					countErrorTotal;										// 업데이트 중 발생한 에러 카운트(전체)
			u32					countError;												// 업데이트 중 발생한 에러 카운트(정상 데이터 수신 시에는 0
			
		private:
			bool				checkValidHeader(Header * header);						// 펌웨어의 헤더가 정상적인지 확인
			
			bool				dataHeader(u32 indexBlock, u8 * data);					// 헤더 데이터 처리
			bool				dataWrite(u32 indexBlock, u8 * data);					// 펌웨어 기록
			
			bool				updateBlock(u32 indexBlock, u8 * data);					// 펌웨어 업데이트(블럭 단위)
			
		public:		
			void				init();													// 초기화
			void				clear();
			
			bool				checkTargetArea();										// 업데이트 할 영역에 데이터가 있는지를 확인
			void				clearTargetArea();										// 업데이트 할 영역 메모리 삭제 미리 지움
			
			bool				update(u32 indexBlock, u8 * data, u32 dataLength);		// 펌웨어 업데이트
			
			ModeUpdate::Type	getMode();												// 현재 동작 모드 반환
			void				setMode(Updater::ModeUpdate::Type newModeUpdate);		// 동작 모드 설정
			
			u32					getIndexBlockNext();									// 요청할 다음 데이터 인덱스 반환
			u32					getIndexBlockEnd();										// 전체 데이터 블럭
			s8					getProgress();											// 진행율을 %로 반환
			
			u32					getTimeComplete()	{	return timeComplete; 		}
			u32					getVersion()		{	return header.version;		}
		};
		
	}

	extern Updater::Device UPDATER;


#endif