This will assume that you have Arduino IDE installed on your machine.

Go to Tools->External Tools:	

Title:     Send to Arduino UNO
Command:   C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude.exe
Arduments: -C "C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" -p atmega328p -c arduino -P COM3 -b 115200 -U flash:w:"$(ProjectDir)Debug\$(TargetName).hex":i

You can also check the "Use Output window"
PS: Check the com port number for your Arduino Uno