#include <Arduino.h>  

const int trigPin = 5;
const int echoPin = 18;

#define SOUND_SPEED_CM_PER_US 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseInLong(echoPin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Sensor Error: No Echo");
  } else {

    distanceCm = duration * SOUND_SPEED_CM_PER_US / 2;
    distanceInch = distanceCm * CM_TO_INCH;

    Serial.print("Distance (cm): ");
    Serial.println(distanceCm, 2);
  }

  delay(500);
}
