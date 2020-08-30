//  IoT電子工作キット
//  2-4.人感センサ
 #include <DHT.h>      //LED で温湿度調べるLED 追加した
const byte MOTN_SNR = 17;  // ①人感センサのピン設定
const byte LED_PIN = 13;
const byte LED_PIN = 12;
const byte TEMP_SNR = 5
// ②起動時、最初に実行される処理
void setup() {
  Serial.begin(115200);   // ③シリアルモニタ設定
  Serial.println();     // (見やすくするために改行)
  Serial.println("MotionStart");// ④シリアルモニタに開始を表示
  pinMode(MOTN_SNR, INPUT); // ⑤人感センサ端子を入力設定
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}
 
// ⑥setup完了後、電源OFFまで繰り返し処理
void loop() {
  delay(1000);        // ⑦1秒待つ
  // ⑧モーションセンサーのデータ取得(True/False)
  if (digitalRead(MOTN_SNR)) {
    Serial.println( "Detected!" );
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println( "No detected." );
    digitalWrite(LED_PIN, LOW);
    //ここから温湿度チェックプログラムを入れる
  }
    
}
