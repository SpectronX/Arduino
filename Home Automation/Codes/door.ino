#include <Servo.h>

int trigPin = 13;
int echoPin = 12;
Servo door;
int pos = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  door.attach(3);
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
    Serial.println("Opening Door");
    for(pos = 0; pos <= 90; pos += 1){
      door.write(90);
    }

    if (distance == 0) {
      Serial.println("Someone Just Entered");
      //door.write(0);
    }
  } else {
    Serial.println("Door Closed");
    door.write(0);
    //recentlyEntered = false;
  }
}

