/*
	@file		Property.cpp
	@brief		Property
 */


#include "Base.h"

#include "Property.h"
#include "Control.Flight.h"
#include "DataStorage.h"
#include "Light.h"
#include "SystemTIme.h"


Property::Device PROPERTY;


void Property::Device::init()
{
	reset();

	memset((void *)&systemCounter, 0, sizeof(Counter));

	lightBright = 63;

	timeUnlockNext = 2897;
}


void Property::Device::reset()
{
	optionFlagsSetup.option		= 0;
	
	timeConnectExternal			= 0;
	timeReceiveExternal			= 0;
	
	errorFlagsForSensor			= 0;
	errorFlagsForState			= 0;
	
	flagConnectExternal			= false;	// ?¸ë? ?¥ì¹˜?€ ?°ê²°
}


void Property::Device::countIncrease(Counters::Type systemCounters)
{
	if( (u8)systemCounters >= (u8)Counters::EndOfType )
	{
		return;
	}
	
	if( FLIGHTCONTROL.testFlight.flagStart == true )
	{
		return;
	}
	
	systemCounter.counter[systemCounters]++;
	DATASTORAGE.changed();
}


u32 Property::Device::getCount(Counters::Type systemCounters)
{
	if( (u8)systemCounters >= (u8)Counters::EndOfType )
	{
		return 0;
	}
	
	return systemCounter.counter[systemCounters];
}


void Property::Device::updateSystemRunningTime()
{
	static u64 timeUpdatedLast	= 0;
	static u64 timeSaveNext		= 0;
	
	u64 timeProgress = NOW - timeUpdatedLast;
	
	if( timeProgress > 337 )
	{
		systemCounter.timeRunSystem += timeProgress;
		
		timeUpdatedLast = NOW;
	}
	
	// ?¤ë¥¸ ë³€ê²??¬í•­???†ë”?¼ë„ 5ë¶„ì— ??ë²ˆì”© ?€??
	if( timeSaveNext < NOW )
	{
		timeSaveNext = NOW + 5 * 60 * 1000;
		DATASTORAGE.changed();
	}
}


void Property::Device::updateFlightTime(u64 timeStart)
{	
	if( FLIGHTCONTROL.testFlight.flagStart == true )
		return;
	
	systemCounter.timeRunFlight += NOW - timeStart;
	DATASTORAGE.changed();
}


u64 Property::Device::getFlightTime()
{
	switch( FLIGHTCONTROL.getModeFlight() )
	{
	case Mode::Flight::Flight:
	case Mode::Flight::Landing:
		{
			return systemCounter.timeRunFlight + (NOW - FLIGHTCONTROL.dbState.timeFlyingStart);
		}
		break;
		
	default:
		{
			return systemCounter.timeRunFlight;
		}
		break;
	}
}


void Property::Device::setError(ErrorFlagsForSensor::Type errorFlagsForSensor)
{
	this->errorFlagsForSensor |= (u32)errorFlagsForSensor;
}


void Property::Device::setError(ErrorFlagsForState::Type errorFlagsForState)
{
	this->errorFlagsForState |= (u32)errorFlagsForState;
}


void Property::Device::clearError(ErrorFlagsForSensor::Type errorFlagsForSensor)
{
	this->errorFlagsForSensor &= ~((u32)errorFlagsForSensor);
}


void Property::Device::clearError(ErrorFlagsForState::Type errorFlagsForState)
{
	this->errorFlagsForState &= ~((u32)errorFlagsForState);
}


bool Property::Device::checkError(ErrorFlagsForSensor::Type errorFlagsForSensor)
{
	if( this->errorFlagsForSensor && ((u32)errorFlagsForSensor) != 0 )
		return true;
	else
		return false;
}


bool Property::Device::checkError(ErrorFlagsForState::Type errorFlagsForState)
{
	if( this->errorFlagsForState && ((u32)errorFlagsForState) != 0 )
		return true;
	else
		return false;
}


void Property::Device::setLightDefault(Protocol::Light::ModeColor * lightModeColor)
{
	bool flagChanged = false;
	
	u8 modePart = lightModeColor->mode.mode & 0xF0;
	
	switch( modePart )
	{
	case Light::Drone::Mode::BodyNone:
		{
			ledModeColorBody	= *lightModeColor;
			flagChanged			= true;
		}
		break;
		
	default:
		break;
	}
	
	if( flagChanged )
	{
		LIGHT.set(lightModeColor->mode.mode, lightModeColor->color, lightModeColor->mode.interval);

		DATASTORAGE.changed();
	}
}

