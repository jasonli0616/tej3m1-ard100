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

LiquidCrystal lcd = LiquidCrystal(0, 1, 10, 11, 12, 13);
const int CONTRAST_PIN = A5;
int contrast = 10;

Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 6, 8, 7, 9); // 1, 3, 2, 4

// Elevator state
int currentFloor = 1; // start at fourth floor
const int TOTAL_FLOORS = 4;
const int ONE_FLOOR_FACTOR = 1;

// Button state
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(80);

  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, contrast);
  
  lcd.begin(16, 2);
  lcd.print("ELEVATOR");
 
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
    int moves = targetFloor - currentFloor;
    myStepper.step(STEPS_PER_REVOLUTION * 4 * moves);

    currentFloor = targetFloor;

  } else if (buttonPressed && targetFloor == 0) {
    buttonPressed = false;
  }

  // lcd.setCursor(0, 1);
  // lcd.print(currentFloor);

}