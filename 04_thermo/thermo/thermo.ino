//  IoT電子工作キット
//  2-3.温湿度センサ
 
#include <DHT.h>    // ①ライブラリを読み込み（DHTセンサー）
const byte TEMP_SNR = 5;  // ②温・湿度センサのピン設定（GPIO5）
 
DHT dht(TEMP_SNR, DHT11);   // ③DHTクラスをインスタンス化
 
// ④起動時、最初に実行される処理
void setup() {
  Serial.begin(115200);   // ⑤シリアルモニタ設定
  Serial.println();   // (見やすくするために改行)
  Serial.println("TempStart");  // ⑥シリアルモニタに開始を表示
  dht.begin();  // ⑦DHTセンサ利用開始
}
 
// ⑧setup完了後、電源OFFまで繰り返し処理
void loop() {
  // ⑨5秒待つ（センサーからデータ取得に時間を要するためWait）
  delay(5000);
  // ⑩温湿度センサーのデータ取得
  //DHT dht(TEMP_SNR, DHT11);
  float g_humidity = dht.readHumidity();
  float g_temperature = dht.readTemperature();
  // ⑪シリアルモニターにデータ表示
  Serial.print( String(g_temperature) );
  Serial.print( " °C / " );
  Serial.print( String(g_humidity) );
  Serial.println(" %");
}
