// C++ code
//
#include <LiquidCrystal_I2C.h>

#include <IRremote.hpp>

int sensorpin = 12;
int ledpin = 13;
bool lcdstate = false;

LiquidCrystal_I2C lcd(32, 16, 2);

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(sensorpin);
  lcd.init();
  lcd.noBacklight();
  pinMode(sensorpin, INPUT);
  pinMode(ledpin, OUTPUT);
}

void loop()
{
  if(IrReceiver.decode()){
  	auto value = IrReceiver.decodedIRData.decodedRawData;
    
     if (value == 4278238976) {
      lcdstate = !lcdstate; 

      if (lcdstate) {
        digitalWrite(ledpin, HIGH);
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("Welcome Sir");
        delay(1000);
        lcd.clear();
      } else {
        digitalWrite(ledpin, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Goodbye");
        delay(1000);
        lcd.clear();
        lcd.noBacklight();
      }
    }
    IrReceiver.resume();
  }
}
