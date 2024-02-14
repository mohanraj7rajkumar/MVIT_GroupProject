#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#define CW 7
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//RS,EN,D4,D5,D6,D7
char PRESSURESHOW[4];// initializing a character of size 4 for showing the  result
char TEMPARATURESHOW[4];// initializing a character of size 4 for showing the temparature result
Adafruit_BMP085 bmp;
void setup() {
                pinMode(CW, OUTPUT);
                lcd.begin(16, 2);
                // Print a logo message to the LCD.
                lcd.print("  CIRCUITDIGEST");
                lcd.setCursor(0, 1);
Serial.begin(9600);
Serial.println("Program started");

delay (2500);
     	lcd.clear();//clear display
// Print another message to the LCd
Serial.begin(9600);
if (!bmp.begin())
                {
 Serial.println("ERROR");	///if there is an error in communication
 while (1) {}
                }
}
void loop()
{
  lcd.print("Pressure= ");          // print name
String PRESSUREVALUE = String(bmp.readPressure());
                // convert the reading to a char array
                PRESSUREVALUE.toCharArray(PRESSURESHOW, 4);
               String PRESVAL = "920";
               digitalWrite(CW, LOW);
                lcd.print(PRESSURESHOW);
          Serial.println(PRESSURESHOW);
                if(PRESSUREVALUE > PRESVAL)
                
                  {digitalWrite(CW, HIGH);
                  delay(750);
                  }
                lcd.print("hPa   ");
                lcd.setCursor(0, 1);
                //// set the cursor to column 0, line 1
         	 lcd.print("Tempar.=");// print name
  String TEMPARATUREVALUE = String(bmp.readTemperature());
                // convert the reading to a char array
                TEMPARATUREVALUE.toCharArray(TEMPARATURESHOW, 4);
                lcd.print(TEMPARATURESHOW);
                lcd.print("C   ");
 lcd.setCursor(0, 0);// set the cursor to column 0, line1
 delay(1000);
}
