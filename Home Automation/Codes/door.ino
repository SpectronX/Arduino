//Automatic Door System
#include <Servo.h>

int trigPin = 13;
int echoPin = 12;
Servo door;
int pos = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  door.attach(3); //This line starts the micro servo
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.01723; 

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 100) {
    //Serial.println("Opening Door"); Optional
    for(pos = 0; pos <= 90; pos += 1){ // defines the range for which the door should open
      door.write(90);
    }
  } else {
    //Serial.println("Door Closed"); optional
    door.write(0);
  }
}

