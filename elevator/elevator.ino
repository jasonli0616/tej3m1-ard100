/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

double stepsPerRevolution = 32;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 4, 5, 6);  // Pin inversion to make the library work

void setup() {
  myStepper.setSpeed(100);
  Serial.begin(9600);

}

void loop() {
  myStepper.step(stepsPerRevolution);
  delay(1000);


}