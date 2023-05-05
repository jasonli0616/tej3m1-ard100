/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

Stepper stepper = Stepper(360 / 5.625, 5, 6, 9, 10);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  stepper.setSpeed(60);
  delay(1000);

}
