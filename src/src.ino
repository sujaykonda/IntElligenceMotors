#include "DCMotor.h"
#include "DCEncoder.h"
int elligence;

DCMotor rmotor(11, 49, 48);
DCEncoder rencoder(19, 42);

DCMotor lmotor(10, 47, 46);
DCEncoder lencoder(18, 43);
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  rmotor.setPWM(-200);
  lmotor.setPWM(200);
  while(true) {
    Serial.print(lencoder.get());
    Serial.print('\t');
    Serial.println(rencoder.get());
  }
}
