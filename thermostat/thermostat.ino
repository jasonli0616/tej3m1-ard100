#define TMP36_PIN A0 // TMP36
#define LED_R_PIN A1
#define LED_G_PIN A3
#define LED_B_PIN A2

#define LED_OFF 0
#define LED_MAX 255

const int TEMPERATURE_COMFORTABLE_RANGE[] = {20, 23}; // {min, max}

float temperature;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(TMP36_PIN, INPUT);
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = getTemperature();
  Serial.println(temperature);

  setLEDs(temperature);
}

void setLEDs(float temperature) {

  analogWrite(LED_R_PIN, LED_OFF);
  analogWrite(LED_G_PIN, LED_OFF);
  analogWrite(LED_B_PIN, LED_OFF);

  // Turn on LEDs based on temperature
  if (temperature < TEMPERATURE_COMFORTABLE_RANGE[0]) {
    analogWrite(LED_B_PIN, LED_MAX);
  } else if (temperature > TEMPERATURE_COMFORTABLE_RANGE[1]) {
    analogWrite(LED_R_PIN, LED_MAX);
  } else {
    analogWrite(LED_G_PIN, LED_MAX);
  }
}

float getTemperature() {
  float volts = getVoltage(TMP36_PIN);
  return (volts - 0.5) * 100; // ((voltage - 500mV) * 100)
}

float getVoltage(int pin) {
  return (analogRead(pin) * .004882814); // converting from a 0 to 1023 digital range to 0 to 5 volts
}
