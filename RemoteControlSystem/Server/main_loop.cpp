#include <Arduino.h>
#include "setup.h"
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
uint8_t request[] = DEVICE_ID;

void loop() 
{
	Serial.println("*Requesting data from Client");

	rf95.send(request, sizeof(request));

	rf95.waitPacketSent();

	if (rf95.waitAvailableTimeout(3000))
	{
		if (rf95.recv(buf, &len))
		{
			Serial.print("got-> ");
			Serial.println((char*)buf);
		}
		else
		{
			Serial.println("--recv failed");
		}
	}
	else
	{
		Serial.println("--No clients.");
	}
	delay(400);
}
