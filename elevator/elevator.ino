/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

const int FLOOR_1_BTN = 8;
const int FLOOR_2_BTN = 9;
const int FLOOR_3_BTN = 12;
const int FLOOR_4_BTN = 13;

const int STEPS_PER_REVOLUTION = 200;

Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 5, 6, 10, 11);

// Elevator state
int currentFloor = 4; // start at fourth floor
const int TOTAL_FLOORS = 4;

void setup() {
  // Serial.begin(9600);
  myStepper.setSpeed(200);
}

void loop() {
  myStepper.step(STEPS_PER_REVOLUTION);

}