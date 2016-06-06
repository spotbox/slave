//Mic.cpp
#include "arduino.h"
#include "Mic.h"

//コンストラクタ
Mic::Mic(int pin):_pin(pin){

}

//マイクから入力された値を取得
int Mic::read(){
  return analogRead(_pin);
}
