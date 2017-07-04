/*
 * setup.cpp
 *
 * Created: 6/27/2017 4:46:11 PM
 *  Author: Grigori
 */ 

 #include "setup.h"
 #include <Arduino.h>

 void setup() {
	Serial.begin(HARDWARE_SERIAL_BAUDRATE);
	while (!Serial) {
		;
	}
	if (!rf95.init())
		Serial.println("LoRa init failed");
	Serial.println("Client is started!");
 }