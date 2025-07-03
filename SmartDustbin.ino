
#include <Servo.h>

Servo myservo;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  myservo.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20) {
    myservo.write(90); // Open lid
    delay(5000);       // Wait 5 sec
    myservo.write(0);  // Close lid
  }
  delay(500);
}
