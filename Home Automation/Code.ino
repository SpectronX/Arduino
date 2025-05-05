int pir = 12;
int buzzer = 7;

void setup()
{
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Code for the Intruder Detector System Using the PIR Sensor and Buzzer.
  int pirState = digitalRead(pir);
  
  switch (pirState){
    case HIGH:{
      digitalWrite(buzzer, HIGH);
      break;
    }
    case LOW:{
      digitalWrite(buzzer, LOW);
      break;
    }
  }


  
}
