/* ADC extension for Home Heating System
   http://www.github.com/tochinet/TeensyADC

   This code is in the public domain.
*/
#include <stdarg.h>

void p(char *fmt, ... ){
        char tmp[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(tmp, 128, fmt, args);
        va_end (args);
        Serial.print(tmp);
}
const int ledPin = 11;   // Teensy has LED on 11, Teensy++ on 6
int i = 0;

void setup()   {                
  Serial.begin(38400);
  pinMode(ledPin, OUTPUT);
}

void loop()                     
{
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(100);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED offSerial.println("Hello World");
  delay(1000);
  p("%02d ",i++);
//  Serial.print(i++); Serial.print(' ');
  if (! (i%10)) Serial.println();
}

