/*
 * setup.cpp
 *
 * Created: 6/27/2017 4:49:04 PM
 *  Author: Grigori
 */ 

#include "setup.h"
#include <Arduino.h>

RH_RF95 rf95;

void setup() 
{
	Serial.begin(HARDWARE_SERIAL_BAUDRATE);
	while (!Serial) {
		;
	}
	if (!rf95.init())
		Serial.println("LoRa init failed");
	Serial.println("Server is started!");
}