/*
 * Elevator Stepper Motor project
 *
 * @author Jason Li
 * @author Omair Khan
 */

#include <Stepper.h>
#include <LiquidCrystal.h>

const int FLOOR_1_BTN = 2;
const int FLOOR_2_BTN = 3;
const int FLOOR_3_BTN = 4;
const int FLOOR_4_BTN = 5;

const int STEPS_PER_REVOLUTION = 512;

const int rs = 0, en = 1, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 6, 8, 7, A0); // 1, 3, 2, 4

// Elevator state
int currentFloor = 1; // start at fourth floor
const int TOTAL_FLOORS = 4;
const int ONE_FLOOR_FACTOR = 1;

// Button state
bool buttonPressed = false;

void setup() {
  myStepper.setSpeed(80);
  
  lcd.begin(16, 2);
  lcd.print("Elevator ready");
 
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
  
  if (!buttonPressed && targetFloor != 0) {
    buttonPressed = true;

    // Move to floor
    elevatorMoving(targetFloor);
    int moves = targetFloor - currentFloor;
    myStepper.step(STEPS_PER_REVOLUTION * 4 * moves);

    currentFloor = targetFloor;

  } else if (buttonPressed && targetFloor == 0) {
    buttonPressed = false;
    lcdSuccess();
  }

}

void elevatorMoving(int targetFloor) {
  lcd.clear();
  lcd.print("Moving to: " + targetFloor);
}

void lcdSuccess() {
  lcd.clear();
  lcd.print("Current floor: " + currentFloor);
}