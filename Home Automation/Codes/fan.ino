int tempPin = A0;
int fanPin = 6;

void setup(){
  pinMode(tempPin, INPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(tempPin);

  // Getting the temperature value in Celsius
  float voltage = (5.0/1024.0) * sensorValue;
  float tempC = (100 * voltage) - 50;

  Serial.print("Temperature: ");
  Serial.println(tempC);
  
  if (tempC > 35) {
    analogWrite(fanPin, 255);
  } else if (tempC > 30) {
    analogWrite(fanPin, 180);
  } else if (tempC > 25) {
    analogWrite(fanPin, 100);
  } else {
    analogWrite(fanPin, 0);
  }

}
