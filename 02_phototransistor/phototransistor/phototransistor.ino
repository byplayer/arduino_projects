const byte LIGHT_SNR = 36;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("LightStart");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  unsigned short g_light = analogRead(LIGHT_SNR) * 100 / 4095 / 0.8;  
  Serial.println(String(g_light));
}
