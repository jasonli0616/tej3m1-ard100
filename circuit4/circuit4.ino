#include <Servo.h> 

const int SERVO_PIN = 9;
Servo servo;

void setup() {
  // put your setup code here, to run once:

  servo.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(180);
  delay(1000);
  servo.write(0);
}
