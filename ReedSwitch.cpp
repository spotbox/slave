//ReedSwitch.cpp
#include "arduino.h"
#include "ReedSwitch.h"

//コンストラクタ
ReedSwitch::ReedSwitch(int pin):_pin(pin){
  pinMode(_pin, INPUT_PULLUP);
}

//読み込み
int ReedSwitch::read(){
  return digitalRead(_pin);
}
