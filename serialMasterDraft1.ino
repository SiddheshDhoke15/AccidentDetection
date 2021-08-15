#include <SoftwareSerial.h>

SoftwareSerial BTserial(9, 8); // RX | TX
char c = ' ';

void setup() 
{
  Serial.begin(9600);
  Serial.println("---------------Master Node------------------");
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);  
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor

  if (BTserial.available())
  {  
    c = BTserial.read();
    Serial.write(c);
  }
}
