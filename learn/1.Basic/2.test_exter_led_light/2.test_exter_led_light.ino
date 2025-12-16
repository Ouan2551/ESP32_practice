#define EXT_LED_PIN 18

void setup() {
  pinMode(EXT_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(EXT_LED_PIN, HIGH);  // LED ON
  delay(500);
  digitalWrite(EXT_LED_PIN, LOW);   // LED OFF
  delay(500);
}