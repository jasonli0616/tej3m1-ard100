/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>

const int FLOOR_1_BTN = 2;
const int FLOOR_2_BTN = 3;
const int FLOOR_3_BTN = 4;
const int FLOOR_4_BTN = 5;

const int STEPS_PER_REVOLUTION = 200;

Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 6, 9, 7, 10); // 1, 3, 2, 4

// Elevator state
int currentFloor = 4; // start at fourth floor
const int TOTAL_FLOORS = 4;
const int ONE_FLOOR_FACTOR = 1.13;

void setup() {
  // Serial.begin(9600);
  myStepper.setSpeed(60);
}

void loop() {
  // Get floor input
  int targetFloor = 0;

  if (digitalRead(FLOOR_1_BTN) == HIGH)
    targetFloor = 1;
  else if (digitalRead(FLOOR_2_BTN) == HIGH)
    targetFloor = 2;
  else if (digitalRead(FLOOR_3_BTN) == HIGH)
    targetFloor = 3;
  else if (digitalRead(FLOOR_4_BTN) == HIGH)
    targetFloor = 4;
  
  // Move to floor
  if (targetFloor > 0) {
    int moves = currentFloor - targetFloor;
    myStepper.step(moves * (STEPS_PER_REVOLUTION * ONE_FLOOR_FACTOR));
  }
  

}