#define LED_PIN2 2 //Built-in LED

void setup()
{
  pinMode(LED_PIN2, OUTPUT);
}
void loop()
{
  digitalWrite(LED_PIN2, HIGH);
  delay(500);
  digitalWrite(LED_PIN2, LOW);
  delay(500);
}