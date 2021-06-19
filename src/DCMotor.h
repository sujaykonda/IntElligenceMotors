class DCMotor {
  public:
    DCMotor(int pwmPin, int pinA, int pinB);
    void setMaxAcc(double acc);
    void setRawSpeed(int speed);
    void setSpeed(int speed);
    void loop();
  private:
    int pwmPin;
    int pinA;
    int pinB;
    // In power per second
    double acc;
}
