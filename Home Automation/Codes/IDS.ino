//Code For Contolling the Intruder Detector System
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
  int pirState = digitalRead(pir);
  
  switch (pirState){
    case HIGH:{
      digitalWrite(buzzer, HIGH); //Alert for the user when motion is detected
      break;
    }
    case LOW:{
      digitalWrite(buzzer, LOW); //Turning off of the sensor when no motion is detected
      break;
    }
  }

}
