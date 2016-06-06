//ReedSwitch.h
#ifndef ReedSwitch_H_
#define ReedSwitch_H_
class ReedSwitch{
public:
  //コンストラクタ
  ReedSwitch(int pin);
  //値 読み込み
  int read();
private:
  int _pin;
};
#endif
