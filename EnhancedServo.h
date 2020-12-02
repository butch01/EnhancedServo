/*
 * EnhancedServo.h
 *
 *  Created on: 06.12.2018
 *      Author: butch
 */

#ifndef ENHANCEDSERVO_H_
#define ENHANCEDSERVO_H_

#include <MegaServo.h>
#include <arduino.h>

class EnhancedServo: public MegaServo {
public:
	EnhancedServo();
	virtual ~EnhancedServo();
	void calculateNewTargetWithTrim(uint8_t trimValue, uint8_t newValue, uint8_t limitLow, uint8_t limitUp );
	void setTrim(signed int trimValue);
	void setMinValue(uint8_t minValue);
	void setMaxValue(uint8_t maxValue);
	void enhancedWrite(uint8_t rawInputValue);
	uint8_t getMinValue();
	uint8_t getMaxValue();

private:
	void debug(unsigned longToLog);
	void debug(char *stringToLog);
	uint8_t minValue;
	uint8_t maxValue;
	bool 	isReversed = false;
	uint8_t trimValue;
};

#endif /* ENHANCEDSERVO_H_ */
