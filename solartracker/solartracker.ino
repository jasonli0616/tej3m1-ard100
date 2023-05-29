#include <Servo.h>

#define SERVO_PIN 9
#define PHOTORESISTOR_PIN_1 A0
#define PHOTORESISTOR_PIN_2 A1
#define PHOTORESISTOR_PIN_3 A2

Servo servo;

int photoresistorInput1 = 0;
int photoresistorInput2 = 0;
int photoresistorInput3 = 0;

// The motor will use seconds as a unit for distance, as in
// how much it can move at a constant velocity in the time given.
const int VELOCITY = 40;
int servoPosition = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(SERVO_PIN);

  servo.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:

  photoresistorInput1 = analogRead(PHOTORESISTOR_PIN_1) / 100;
  // photoresistorInput2 = analogRead(PHOTORESISTOR_PIN_2);
  photoresistorInput3 = analogRead(PHOTORESISTOR_PIN_3) / 100;

  int spinAmount = (photoresistorInput1 - photoresistorInput3);
  spinDistance(spinAmount);
}

/**
 * Spin at a constant velocity for x seconds,
 * representing the distance.
 */
void spinDistance(int distance) {
  Serial.println(distance);

  int directionFactor = (distance < 0) ? -1 : 1;
  servo.write(90 + (VELOCITY * directionFactor));

  delay(abs(distance) * 100);
  servo.write(90);

  servoPosition += distance;
}