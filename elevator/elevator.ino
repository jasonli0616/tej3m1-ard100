/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

const int UP_BTN = 13;
const int DOWN_BTN = 12;

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 5, 6, 10, 11);

void setup() {
  // Serial.begin(9600);
  myStepper.setSpeed(10);
}

void loop() {
  if (digitalRead(UP_BTN) == HIGH)
    myStepper.step(1);
  else if (digitalRead(DOWN_BTN) == HIGH)
    myStepper.step(-1);

}