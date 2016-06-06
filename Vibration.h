//Vibration.h
#ifndef Vibration_H_
#define Vibration_H_
class Vibration{
public:
  //コンストラクタ
  Vibration(int pin);
  //読み込み
  int read();
private:
  int _pin;
};
#endif
