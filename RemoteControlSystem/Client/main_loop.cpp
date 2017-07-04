#include <Arduino.h>
#include "setup.h"
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
int sample_data = 123;
char data[10];
void loop() 
{
	if (rf95.available())
	{
		if (rf95.recv(buf, &len))
		{
			Serial.print("broadcast-> ");
			Serial.println((char*)buf);
			if (!strcmp((const char*)buf,DEVICE_ID))
			{
				Serial.println("Client is selected, sending the value...");
				// Send a message to Server
				sprintf((char*)data,"val=%d",sample_data);
				rf95.send((const uint8_t*)data, sizeof(data));
				rf95.waitPacketSent();
			}
		}
		else
		{
			Serial.println("--recv failed");
		}
	}
}
