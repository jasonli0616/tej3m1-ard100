#include <Servo.h>

#define SERVO_PIN 9
#define PHOTORESISTOR_PIN_1 A0
#define PHOTORESISTOR_PIN_2 A1
#define PHOTORESISTOR_PIN_3 A2

Servo servo;

int photoresistorInput1 = 0;
int photoresistorInput2 = 0;
int photoresistorInput3 = 0;
int servoPosition = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  servo.attach(SERVO_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:

  servoPosition = servo.read();

  photoresistorInput1 = analogRead(PHOTORESISTOR_PIN_1);
  photoresistorInput2 = analogRead(PHOTORESISTOR_PIN_2);
  photoresistorInput3 = analogRead(PHOTORESISTOR_PIN_3);

  Serial.println(servoPosition);

}
