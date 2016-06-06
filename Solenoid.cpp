//Solenoid.cpp
#include "arduino.h"
#include "Solenoid.h"

//コンストラクタ
Solenoid::Solenoid(int pin):_status(LOW),_pin(pin){
  pinMode(pin, OUTPUT);
}

//ステータス変更
void Solenoid::set(int v){
  _status = v;
  digitalWrite(_pin,v);
}

//トグル
int Solenoid::toggle(){
  if(_status == LOW){
      set(HIGH);
  }
  else{
      set(LOW);
  }
  return _status;
}

//ON
void Solenoid::on(void){
  set(HIGH);
}

//OFF
void Solenoid::off(void){
  set(LOW);
}
