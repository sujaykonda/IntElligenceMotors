#include "DCEncoder.h"


void encoderChange()
{
  for (int i = 0; i < enc_s; i++)
  {
    if (encoders[i]->state && !digitalRead(encoders[i]->channelA))
    {
      encoders[i]->state = false;
    }
    if (!encoders[i]->state && digitalRead(encoders[i]->channelA))
    {
      encoders[i]->count();
      encoders[i]->state = true;
    }
  }
}


DCEncoder::DCEncoder(int channelA, int channelB)
{
  pinMode(channelA, INPUT_PULLUP);
  pinMode(channelB, INPUT_PULLUP);

  this->channelA = channelA;
  this->channelB = channelB;
  this->enc = 0;

  encoders[enc_s] = this;

  enc_s += 1;

  //attachInterrupt(digitalPinToInterrupt(this->channelA), encoderChange, CHANGE);
}

int DCEncoder::get()
{
  return this->enc;
}
void DCEncoder::reset()
{
  this->enc = 0;
}
void DCEncoder::count()
{
  //Serial.println("COUNT");
  if (digitalRead(channelB) == HIGH)
  {
    this->enc++;
  }
  else
  {
    this->enc--;
  }
}

DCEncoder *encoders[100];
int enc_s = 0;
