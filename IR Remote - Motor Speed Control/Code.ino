// C++ code
//
#include <IRremote.hpp>

int sensorPin = 13;
int transistor = 9;

void setup() {
  IrReceiver.begin(sensorPin);
  pinMode(sensorPin, INPUT);
  pinMode(transistor, OUTPUT);
  analogWrite(transistor, 0);
}

void loop() {
   if(IrReceiver.decode()){
   auto value = IrReceiver.decodedIRData.decodedRawData;
    
    if(value == 4010852096){
    	analogWrite(transistor, 64);
    }
    if(value == 3994140416){
    	analogWrite(transistor, 128);
    }
    if(value == 3977428736){
    	analogWrite(transistor, 192);
    }
    if(value == 3944005376){
    	analogWrite(transistor, 255);
    }
    if(value == 4278238976){
    	analogWrite(transistor, 0);
    }
    
    IrReceiver.resume();
  
  }

}
