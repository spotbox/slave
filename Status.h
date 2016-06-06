//Status.h
#ifndef Status_H_
#define Status_H_

struct STATUS {
  //ソレノイド
  int solenoid;
  //リードスイッチ
  int reedSwitch;
  //振動センサ
  int vibration;
  //マイク
  int mic;
  //湿度
  float humidity;
  //温度
  float temperature;
};

class Status {
public:
  Status();
  void setSolenoid(int solenoid);
  int getSolenoid();
  void setReedSwitch(int reedSwitch);
  int getReedSwitch();
  void setVibration(int vibration);
  int getVibration();
  void setMic(int mic);
  int getMic();
  void setHumidity(float humidity);
  float getHumidity();
  void setTemperature(float temperature);
  float getTemperature();

  STATUS getStatus();
private:
  //
  struct STATUS _status;
};
#endif
