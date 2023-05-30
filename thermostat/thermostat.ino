#define TMP36_PIN A0 // TMP36
#define LED_R_PIN A1
#define LED_G_PIN A3
#define LED_B_PIN A2

#define COOL_MOTOR 3
#define HEAT_MOTOR 2

#define LED_OFF 0
#define LED_MAX 255

const int TEMPERATURE_COMFORTABLE_RANGE[] = {20, 23}; // {min, max}

// variables
float temperature;
int state; // 0=off, 1=cold, 2=hot

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(TMP36_PIN, INPUT);

  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  
  pinMode(COOL_MOTOR, OUTPUT);
  pinMode(HEAT_MOTOR, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Get temperature
  temperature = getTemperature();
  state = getTemperatureState(temperature);

  // Set
  setLEDs();
  determineMotorOutput();
}

void determineMotorOutput() {
  if (state == 1) {
    digitalWrite(COOL_MOTOR, LOW);
    digitalWrite(HEAT_MOTOR, HIGH);
  } else if (state == 2) {
    digitalWrite(COOL_MOTOR, HIGH);
    digitalWrite(HEAT_MOTOR, LOW);
  } else {
    digitalWrite(COOL_MOTOR, LOW);
    digitalWrite(HEAT_MOTOR, LOW);
  }
}

void setLEDs() {

  // Turn on LEDs based on temperature
  if (state == 1) {
    analogWrite(LED_R_PIN, LED_OFF);
    analogWrite(LED_G_PIN, LED_OFF);
    analogWrite(LED_B_PIN, LED_MAX);
  } else if (state == 2) {
    analogWrite(LED_R_PIN, LED_MAX);
    analogWrite(LED_G_PIN, LED_OFF);
    analogWrite(LED_B_PIN, LED_OFF);
  } else {
    analogWrite(LED_R_PIN, LED_OFF);
    analogWrite(LED_G_PIN, LED_MAX);
    analogWrite(LED_B_PIN, LED_OFF);
  }
}

/**
 * 0=off, 1=cold, 2=hot
 */
int getTemperatureState(float temperature) {
  if (temperature < TEMPERATURE_COMFORTABLE_RANGE[0]) {
    return 1;
  } else if (temperature > TEMPERATURE_COMFORTABLE_RANGE[1]) {
    return 2;
  }
  return 0;
}

float getTemperature() {
  float volts = getVoltage(TMP36_PIN);
  return (volts - 0.5) * 100; // ((voltage - 500mV) * 100)
}

float getVoltage(int pin) {
  return (analogRead(pin) * .004882814); // converting from a 0 to 1023 digital range to 0 to 5 volts
}
