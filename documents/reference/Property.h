/*
	@file		Property.h
	@brief		Property
 */


#ifndef PROPERTY_H_
#define PROPERTY_H_


#include "Base.h"
#include "Protocol.h"
#include "DataStorage.h"


	namespace Property
	{
		class Device
		{
		public:
			// ?Œë˜??ë©”ëª¨ë¦¬ì— ?€?¥í•˜???ì„±
			Counter							systemCounter;				// ?íƒœ ?°ì´??ê¸°ë¡??ì¹´ìš´??
			
			Protocol::Light::ModeColor		ledModeColorBody;
			
			Drone::Option::Flags::Setup		optionFlagsSetup;			// ?µì…˜ ?Œë˜ê·?
			
		public:
			// ?Œë˜??ë©”ëª¨ë¦¬ì— ?€?¥í•˜ì§€ ?ŠëŠ” ?ì„±
			u64								timeConnectExternal;		// ?¸ë? ?¥ì¹˜???°ê²°???œê°
			u64								timeReceiveExternal;		// ?¸ë? ?¥ì¹˜ë¡œë????°ì´?°ë? ë°›ì? ?œê°
			
			u32								errorFlagsForSensor;		// ?¼ì„œ ?¤ë¥˜ ?Œë˜ê·?
			u32								errorFlagsForState;			// ?íƒœ ?¤ë¥˜ ?Œë˜ê·?
			
			bool							flagConnectExternal;		// ?¸ë? ?¥ì¹˜?€ ?°ê²°

			u8								lightBright;				// LED ë°ê¸°

		private:
			u64								timeUnlockNext;
			
		public:
			void							init();
			void							reset();
			
			void							countIncrease	(Counters::Type systemCounters);
			u32								getCount		(Counters::Type systemCounters);
			
			void							updateSystemRunningTime();
			void							updateFlightTime(u64 timeStart);
			u64								getFlightTime();
			
			void							setError	(ErrorFlagsForSensor::Type	errorFlagsForSensor);
			void							setError	(ErrorFlagsForState::Type	errorFlagsForState);
			
			void							clearError	(ErrorFlagsForSensor::Type	errorFlagsForSensor);
			void							clearError	(ErrorFlagsForState::Type	errorFlagsForState);
			
			bool							checkError	(ErrorFlagsForSensor::Type	errorFlagsForSensor);
			bool							checkError	(ErrorFlagsForState::Type	errorFlagsForState);
			
			void							setLightDefault(Protocol::Light::ModeColor * lightModeColor);
			
			void							clearSystemCount();										// ?œìŠ¤??ì¹´ìš´??ì´ˆê¸°??
		};
	}

	extern Property::Device PROPERTY;


#endif 

