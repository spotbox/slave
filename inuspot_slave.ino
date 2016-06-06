#include <Wire.h>
#include <Metro.h>
#include "Status.h"
#include "DHT.h"
#include "Solenoid.h"
#include "Mic.h"
#include "Vibration.h"
#include "ReedSwitch.h"

//I2C アドレス
#define I2C_ADDRESS 8

//Mic A0
#define PIN_MIC 0

//DHT22 D2
#define PIN_DHT22 2

//Vibration
#define PIN_VIBRATION 3

//Solenoid
#define PIN_SOLENOID 4

//Reed switch
#define PIN_REED_SWITCH 9

//各ステータスを格納するクラス
Status status;

//温度,湿度センサー
DHT dht(PIN_DHT22, DHT22);

//ソレノイド
Solenoid solenoid(PIN_SOLENOID);

//マイク
Mic mic(PIN_MIC);

//振動センサー
Vibration vibration(PIN_VIBRATION);

//リードスイッチ
ReedSwitch reedSwitch(PIN_REED_SWITCH);

//タイマー
Metro vibrationMetro = Metro(100);
Metro reedSwitchMetro = Metro(100);
Metro micMetro = Metro(100);
Metro dhtMetro = Metro(100);

void setup() {
  Serial.begin(9600);
  Serial.println("setup");

  //温度,湿度センサー 初期化
  dht.begin();

  //I2C SLAVE 初期化
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(onI2CRequest);
  Wire.onReceive(onI2CReceive);
}

void loop() {
  //Serial.println("loop");
  //ソレノイド操作
  //solenoid.toggle();
  
  if (reedSwitchMetro.check() == 1) {
    fireReedSwitch();
  }
  if (vibrationMetro.check() == 1) {
    fireVibration();
  }
  if (micMetro.check() == 1) {
    fireMic();
  }
  if (dhtMetro.check() == 1) {
    fireDHT();
  }
}

//リードスイッチ
int oldR = -1;
void fireReedSwitch(){
  int r = reedSwitch.read();
  if(r != oldR){
    //Serial.print("Reed switch:");
    //Serial.println(r);
    oldR = r;
    status.setReedSwitch(r);
  }
}

//振動スイッチ
int oldV = -1;
void fireVibration(){
  int v = vibration.read();
  if(v != oldV){
    //Serial.print("Vibration:");
    //Serial.println(v);
    oldV = v;
    status.setVibration(v);
  }
}

int oldM = -1;
void fireMic(){
  //マイク
  int m = mic.read();
  if(m != oldM){
    //Serial.print("mic:");
    //Serial.println(m);
    oldM = m;
    status.setMic(m);
  }
}

//温度,湿度センサー
float oldT = 0.0;
void fireDHT(){
  // Reading temperature
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    //Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  if(t == oldT){
    return;
  }
  oldT = t;
/*
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
*/
  status.setHumidity(h);
  status.setTemperature(t);
}

//I2C マスタからデータのリクエスト
void onI2CRequest(){
  STATUS result = status.getStatus();
  Wire.write((char*)&result,sizeof(STATUS)); 
}

//I2C マスタからデータが送られてきたとき
void onI2CReceive(int bytes){
  while(Wire.available()) {
    char c = Wire.read();
    //ソレノイド操作
    if(c == '1'){
      solenoid.on();  
      status.setSolenoid(HIGH);
    }
    else{
      solenoid.off();
      status.setSolenoid(LOW);
    }
  }
}
