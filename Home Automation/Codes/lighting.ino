// C++ code
//
int prPin = A0;
int bulb = 2;
int threshold = 500;

void setup()
{
  pinMode(bulb, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(analogRead(prPin) > threshold ){
    Serial.println("The sun is out");
    digitalWrite(bulb, LOW);
  } else {
    Serial.println("Darkness");
    digitalWrite(bulb, HIGH);
  }
}
