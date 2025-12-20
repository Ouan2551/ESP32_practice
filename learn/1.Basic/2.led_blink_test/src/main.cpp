#include <Arduino.h>

#define LED_PIN 18

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Start_Program");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
}