/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

double stepsPerRevolution = 2048;

Stepper Stepper(stepsPerRevolution, 5, 6, 9, 10);  // Pin inversion to make the library work

void setup() {

  Stepper.setSpeed(10);
  Serial.begin(9600);

  }
void loop() {

  // rotation counterclockwise 
  Stepper.step(stepsPerRevolution);
  delay(1000);


}