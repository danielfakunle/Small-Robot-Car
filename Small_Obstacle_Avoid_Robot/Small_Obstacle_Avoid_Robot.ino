const int pingPin = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 13; // Echo Pin of Ultrasonic Sensor
const int ledPin = 7;
int motorPin = 4;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
    pinMode(motorPin, OUTPUT);

}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   pinMode(motorPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
    if (cm <=30)
    {
      digitalWrite(motorPin, LOW);
      blinkLed();
    }
    else if(cm>30)
    {
      digitalWrite(motorPin, HIGH);
      delay(0.1);
      digitalWrite(motorPin, LOW);
      delay(500);
      digitalWrite(motorPin, HIGH);
      delay(0.1);
    }
   delay(100);
}

void blinkLed(){
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, HIGH);
delay(2000);
digitalWrite(ledPin, LOW);
delay(2000);

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
