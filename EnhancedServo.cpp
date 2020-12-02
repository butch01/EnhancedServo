/*
 * EnhancedServo.cpp
 *
 *  Created on: 06.12.2018
 *      Author: butch
 */

#include "EnhancedServo.h"
#include "arduino.h"
#include <ArduinoLog.h>
#define IS_DEBUG 0

EnhancedServo::EnhancedServo()
{
	// TODO Auto-generated constructor stub
}

/**
 * stores the trim value
 */
void EnhancedServo::setTrim(signed int trimValue)
{
	this -> trimValue = trimValue;
}

/**
 * returns the min value
 */
uint8_t EnhancedServo::getMinValue()
{
	return minValue;
}


/**
 * returns the maxvalue
 */
uint8_t EnhancedServo::getMaxValue()
{
	return maxValue;
}



/**
 * stores the min Value
 */
void EnhancedServo::setMinValue(uint8_t minValue)
{
	this -> minValue = minValue;
}

/**
 * stores the max value
 */
void EnhancedServo::setMaxValue(uint8_t maxValue)
{
	this -> maxValue = maxValue;
}

/**
 * calculates the final servo position, respecting min, max, trim and writes it to servo.
 */
void EnhancedServo::enhancedWrite(uint8_t rawInputValue)
{
	int calculatedValue = 0 ;
	calculatedValue = map(rawInputValue, 0, 255, 0, 180)  + trimValue;
	if (calculatedValue > maxValue)
	{
		calculatedValue = maxValue;
	}
	else if (calculatedValue < minValue)
	{
		calculatedValue = minValue;
	}
//	this -> debug("write servo:");
//	this -> debug(calculatedValue);
	// write the servo position
	write(calculatedValue);
	Serial.print("cs: ");
	Serial.print(calculatedValue);
	Serial.print("\n");
	//Log.notice(F("Enhanced Servo: raw: %d, calculated:%d" CR),rawInputValue,calculatedValue);
}

//void debug(unsigned longToLog)
//{
//	#if IS_DEBUG == 1
//		Serial.print(longToLog);
//	#endif
//}
//void debug(char *stringToLog)
//{
//	#if IS_DEBUG == 1
//		Serial.print(stringToLog);
//	#endif
//}


EnhancedServo::~EnhancedServo() {
	// TODO Auto-generated destructor stub
}

