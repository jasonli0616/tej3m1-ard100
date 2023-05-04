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

const int D1_PIN = 12;
const int D2_PIN = 11;
const int D3_PIN = 10;
const int D0_PIN = 9;

bool buttonIsPressed = false;
int buttonPressCount = 0;
int buttonPressCountBinary[4];


void setup() {

  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT);
  pinMode(D1_PIN, OUTPUT);
  pinMode(D2_PIN, OUTPUT);
  pinMode(D3_PIN, OUTPUT);
  pinMode(D0_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);

}

void loop() {
  updateButtonPressCount();
  convertBase10ToBinary();

  Serial.print(buttonPressCount);
  Serial.print(" ");
  Serial.print(buttonPressCountBinary[0]);
  Serial.print(buttonPressCountBinary[1]);
  Serial.print(buttonPressCountBinary[2]);
  Serial.print(buttonPressCountBinary[3]);
  Serial.print("\n");

}

/**
 * Take base 10 int buttonPressCount,
 * and put it to buttonPressCountBinary
 * as a four digit binary number.
 */
void convertBase10ToBinary() {
  int i = 0;
  int decimalNumber = buttonPressCount;

  while (decimalNumber > 0) {
    buttonPressCountBinary[i] = decimalNumber % 2;
    decimalNumber /= 2;
    i++;
  }

  // TODO: Reverse array

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