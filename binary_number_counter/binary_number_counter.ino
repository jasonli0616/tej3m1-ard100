/**
 * Arduino Binary Counter
 * TEJ3M1-02
 *
 * Objective:
 * Create a circuit using your Arduino that counts from 0 to 9 as you press
 * the push button. The Arduino should display the current count value in
 * 4-bit binary (using the 4 LEDs), as well as displaying the correct number
 * on the 7-segment display. When the count increases beyond 9, have the count
 * reset back to 0.
 *
 * Assignment outline:
 * https://docs.google.com/document/d/1pkNXHHZ0pdCSnCbuD3DuEeFPS5_wGoCx0zS-g1uBUGI/edit?usp=sharing
 * 
 * @author Jason Li
 * @author Omair Khan
 * @date 2023-05-04
 * @version 1.0.0
 */


// Digital pins
const int BUTTON_PIN = 13; // Pushbutton pin
const int LED_PINS[] = {2, 3, 4, 5}; // LED pins
const int IC_PINS[] = {12, 11, 10, 9}; // 4511 IC pins; D1, D2, D3, D0


// Size of array, and digits of binary number
const int BINARY_AMOUNT_OF_DIGITS = 4;


// Button state
bool buttonIsPressed = false;
int buttonPressCount = 0;
int buttonPressCountBinary[4];



/**
 * Setup the program.
 *
 * Set the pin mode of all pins.
 */
void setup() {

  // Set pin mode
  pinMode(BTN_PIN, INPUT);
  for (int i = 0; i < BINARY_AMOUNT_OF_DIGITS; i++) {
    pinMode(IC_PINS[i], OUTPUT);
    pinMode(LED_PINS[i], OUTPUT);
  }

}


/**
 * Periodic loop for the program.
 *
 * This will handle all user input from the
 * pushbutton, and update the 7-segment display
 * and the LEDs accordingly.
 */
void loop() {
  updateButtonPressCount();
  convertBase10ToBinary();

  digitalWriteBinaryToComponents();

}


/**
 * Write binary to LED and IC.
 */
void digitalWriteBinaryToComponents() {
  for (int i = 0; i < BINARY_AMOUNT_OF_DIGITS; i++) {
    digitalWrite(IC_PINS[i], buttonPressCountBinary[i]);
    digitalWrite(LED_PINS[i], buttonPressCountBinary[i]);
  }
}


/**
 * Take base 10 int buttonPressCount,
 * and put it to buttonPressCountBinary
 * as a four digit binary number.
 */
void convertBase10ToBinary() {

  // Convert to array of binary digits
  for (int i = 0; i < BINARY_AMOUNT_OF_DIGITS; ++i) {
    buttonPressCountBinary[BINARY_AMOUNT_OF_DIGITS-i-1] = (buttonPressCount >> i) & 1;
  }

}


/**
 * Handle counting with button presses.
 *
 * Update the button press count periodically.
 * Ensure the max is 9, then go back to 0.
 */
void updateButtonPressCount() {
  
  if (digitalRead(BTN_PIN) == HIGH && !buttonIsPressed) {
    // Max is 9, then go back to 0
    if (++buttonPressCount >= 10)
      buttonPressCount = 0;
    buttonIsPressed = true;
  } else if (digitalRead(BTN_PIN) == LOW) {
    // Button is not pressed
    buttonIsPressed = false;
  }
}
