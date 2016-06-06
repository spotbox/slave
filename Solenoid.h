//Solenoid.h
#ifndef Solenoid_H_
#define Solenoid_H_
class Solenoid {
public:
  Solenoid(int pin);
  int toggle();
  void on();
  void off();

private:
  void set(int v);
  int _pin;
  int _status;
};

#endif
