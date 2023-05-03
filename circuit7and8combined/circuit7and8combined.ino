const int POT_PIN = A0;
const int BTN_PIN = 3;
const int LED_PIN = 13;

bool onMode = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  int potentiometerInput = analogRead(POT_PIN);
  int buttonInput = digitalRead(BTN_PIN);

  Serial.println(buttonInput);

  if (buttonInput == HIGH)
    onMode = !onMode;
  
  if (onMode) {
    digitalWrite(LED_PIN, HIGH);
    delay(potentiometerInput);
    digitalWrite(LED_PIN, LOW);
    onMode = false;
  }

}
