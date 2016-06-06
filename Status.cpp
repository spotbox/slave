//Status.cpp
#include <Arduino.h>
#include "Status.h"

Status::Status(){
  setSolenoid(0);
  setReedSwitch(0);
  setVibration(0);
  setMic(1023);
  setHumidity(0.0);
  setTemperature(0.0);
}

void Status::setSolenoid(int solenoid){
  _status.solenoid = solenoid;
}

int Status::getSolenoid(){
  return _status.solenoid;
}

void Status::setReedSwitch(int reedSwitch){
  _status.reedSwitch = reedSwitch;
}

int Status::getReedSwitch(){
  return _status.reedSwitch;
}

void Status::setVibration(int vibration){
  _status.vibration = vibration;
}

int Status::getVibration(){
  return _status.vibration;
}

void Status::setMic(int mic){
  _status.mic = mic;
}

int Status::getMic(){
  return _status.mic;
}

void Status::setHumidity(float humidity){
  _status.humidity = humidity;
}

float Status::getHumidity(){
  return _status.humidity;
}

void Status::setTemperature(float temperature){
  _status.temperature = temperature;
}
float Status::getTemperature(){
  return _status.temperature;
}

STATUS Status::getStatus(){
  return _status;
}

