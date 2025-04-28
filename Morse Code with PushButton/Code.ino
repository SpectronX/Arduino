int buttonState = 0;
int lastButtonState = 0;
int count1, count2, count3, count4 = 0;

int ledPin = 7;
int btnPin = 2;

long previousMillis = 0;
int inputstage = 1;
const long interval = 1000; 

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void decodeCount(int count) {
  if (count == 1) Serial.print(".");
  else if (count == 2) Serial.print(" __ ");
}


void loop() {
  long currentMillis = millis();

  buttonState = digitalRead(btnPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    digitalWrite(ledPin, HIGH);

    if (inputstage == 1) {
      count1++;
    }
    else if (inputstage == 2) {
      count2++;
    }
    else if (inputstage == 3) {
      count3++;
    }
    else if(inputstage == 4){
      count4++;
    }
  } else if (buttonState == LOW) {
    digitalWrite(ledPin, LOW);
  }
  
  lastButtonState = buttonState;

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    inputstage++;

   if(inputstage > 4) {  
   decodeCount(count1);
   decodeCount(count2);
   decodeCount(count3);
   decodeCount(count4);
   Serial.println();
   Serial.print("Decode the letter.");

   delay(1000);
   while(true);
    }
  }
}

