//Vibration.cpp
#include "arduino.h"
#include "Vibration.h"

//コンストラクタ
Vibration::Vibration(int pin):_pin(pin){
  pinMode(_pin, INPUT);
}

//読み込み
int Vibration::read(){
  return digitalRead(_pin);
}
