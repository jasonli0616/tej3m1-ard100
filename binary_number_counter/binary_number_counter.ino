/**
 * Binary number counter.
 * 
 * @author Jason Li
 * @author Omair Khan
 */


const int BTN_PIN = 13;

const int LED1_PIN = 2;
const int LED2_PIN = 3;
const int LED3_PIN = 4;
const int LED4_PIN = 5;
const int LED_PINS[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};

const int D1_PIN = 12;
const int D2_PIN = 11;
const int D3_PIN = 10;
const int D0_PIN = 9;
const int IC_PINS[] = {D1_PIN, D2_PIN, D3_PIN, D0_PIN};

const int BINARY_AMOUNT_OF_DIGITS = 4;

bool buttonIsPressed = false;
int buttonPressCount = 0;
int buttonPressCountBinary[4];


void setup() {

  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT);

  for (int i = 0; i < BINARY_AMOUNT_OF_DIGITS; i++) {
    pinMode(IC_PINS[i], OUTPUT);
    pinMode(LED_PINS[i], OUTPUT);
  }

}

void loop() {
  updateButtonPressCount();
  convertBase10ToBinary();

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
    buttonIsPressed = false;
  }
}