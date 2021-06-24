#include "DCEncoderMotor.h"
int elligence;

DCEncoderMotor lmotor(10, 47, 46, 18, 43, MOTOR_5X_GAIN);

void isr_l() {
  lmotor.count();
}
  
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(18), isr_l, FALLING);
}

void loop() {
  lmotor.setTarEPS(300);
  while(true) {
    lmotor.loop();
    delay(1);
  }
}
