DCMotor::DCMotor(int pwmPin, int pinA, int pinB) {
  this->pwmPin = pwmPin;
  this->pinA = pinA;
  this->pinB = pinB;
  this->acc = 300;
}
