//Mic.h
#ifndef Mic_H_
#define Mic_H_
class Mic{
public:
  //コンストラクタ
  Mic(int pin);
  //マイクから入力された値を取得
  int read();
private:
  int _pin;
};
#endif
