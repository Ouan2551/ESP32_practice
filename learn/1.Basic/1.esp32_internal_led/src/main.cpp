#include <Arduino.h>

#define LED_PIN 2   // Built-in LED (most ESP32 boards)

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    delay(2000);
    Serial.println("ESP32 CODE IS RUNNING");
}

void loop() {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    Serial.println("Blink");
    delay(1000);
}