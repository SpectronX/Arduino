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
      digitalWrite(buzzer, HIGH);
      break;
    }
    case LOW:{
      digitalWrite(buzzer, LOW);
      break;
    }
  }
}
