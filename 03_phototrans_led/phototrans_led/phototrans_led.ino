const byte LIGHT_SNR = 36;
const byte LED_PIN = 12;

byte light_status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("LightStart");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  unsigned short g_light = analogRead(LIGHT_SNR) * 100 / 4095 / 0.8;

  if(g_light < 70) {
    if(light_status == 0) {
      digitalWrite(LED_PIN, HIGH);
      light_status = 1;
    }
  } else {
    if(light_status != 0) {
      digitalWrite(LED_PIN, LOW);
      light_status = 0;
    }
  }
  
  Serial.println(String(g_light));
}
