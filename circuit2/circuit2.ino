const int LED_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int NUM_OF_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

void setup() {
  Serial.begin(9600);

  // Set all LED pins to output
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

void loop() {
  // fillFromSideAnimation();
  loadingAnimation();
}

void fillFromSideAnimation() {
  const int ANIMATION_DELAY = 100;

  // Fill from side 1
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(ANIMATION_DELAY);
  }
  // Clear from side 1
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
    delay(ANIMATION_DELAY);
  }
  // Fill from side 2
  for (int i = NUM_OF_LEDS-1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(ANIMATION_DELAY);
  }
  // Clear from side 2
  for (int i = NUM_OF_LEDS-1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], LOW);
    delay(ANIMATION_DELAY);
  }
}

void loadingAnimation() {
  const int ANIMATION_DELAY = 100;
  const int LED_BLOCK_AMOUNT = 5;

  int firstLEDBlock = 0;
  int cycle = 0;

  while (cycle <= NUM_OF_LEDS + LED_BLOCK_AMOUNT) {
    int lastLEDBlock = firstLEDBlock - LED_BLOCK_AMOUNT;

    for (int i = 0; i < NUM_OF_LEDS; i++) {
      Serial.print(cycle);
      Serial.print("cycle");
      Serial.print(i);
      Serial.print("\n");

      if (i <= firstLEDBlock && i > lastLEDBlock)
        digitalWrite(LED_PINS[i], HIGH);
      else
       digitalWrite(LED_PINS[i], LOW);

    }
    delay(ANIMATION_DELAY);
    cycle++;
    firstLEDBlock++;
    lastLEDBlock++;
  }

}