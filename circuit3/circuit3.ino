const int MOTOR_PIN = 9;
int currentMotorSpeed = 0;

void setup() {
  Serial.begin(9600);

  // Set motor pin to output
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {

  accelerate(100, 255);
  delay(5000);
  accelerate(100, -255);
  delay(5000);
}

/**
 * Ramp up to a specified speed starting from current speed,
 * in a specified amount of ticks.
 *
 * @param rate ticks
 * @param targetSpeed final speed, from -255 to 255
 */
void accelerate(double rate, double targetSpeed) {

  for (int i = currentMotorSpeed; i < rate; i++) {
    double speed = targetSpeed/rate * i;

    currentMotorSpeed = speed;
    analogWrite(MOTOR_PIN, speed);
  }
}