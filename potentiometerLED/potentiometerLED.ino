const int LED_PINS[] = {10, 9, 8, 7, 6, 5};
const int POTENTIOMETER_PIN = A0;

const int AMOUNT_OF_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const int POTENTIOMETER_MAX_VALUE = 1023;

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < AMOUNT_OF_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);

  int onLEDs = (potentiometerValue / (double) POTENTIOMETER_MAX_VALUE) * AMOUNT_OF_LEDS;

  for (int i = 0; i < AMOUNT_OF_LEDS; i++) {
    if (i < onLEDs)
      digitalWrite(LED_PINS[i], HIGH);
    else
     digitalWrite(LED_PINS[i], LOW);
  }

}
