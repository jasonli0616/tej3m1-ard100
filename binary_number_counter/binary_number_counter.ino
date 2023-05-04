/**
 * Binary number counter.
 * 
 * @author Jason Li
 * @author Omair Khan
 */


const int BTN_PIN = 13;


const int D1_PIN = 12;
const int D2_PIN = 11
const int D3_PIN = 10;
const int D0_PIN = 9;

int buttonPressCount = 0;


void setup() {

  pinMode(BTN_PIN, INPUT);
  pinMode(D1_PIN, OUTPUT);
  pinMode(D2_PIN, OUTPUT);
  pinMode(D3_PIN, OUTPUT);
  pinMode(D0_PIN, OUTPUT);

}

void loop() {
  updateButtonPressCount();

}

/**
 * Update the button press count periodically.
 * Ensure the max is 9, then go back to 0.
 */
void updateButtonPressCount() {
  
  if (digitalRead(BTN_PIN) == HIGH) {
    // Max is 9, then go back to 0
    if (++buttonPressCount >= 10)
      buttonPressCount = 0;
  }
}