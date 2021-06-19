#include "DCMotor.h"
#include "MotorEncoder.h"
int elligence;

DCMotor motor(11, 49, 48);
MotorEncoder encoder(19, 42);
  
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoder.channelA), count, RISING);
}

void loop() {
  motor.setSpeed(255);
  while(true) {
    motor.loop();
    Serial.println(encoder.getEnc());
  }
  delay(1000000);
}

void count() {
  ecount(&encoder);
}
