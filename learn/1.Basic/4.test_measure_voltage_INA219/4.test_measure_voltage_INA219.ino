#include <Wire.h>
#include <Adafruit_INA219.h>
#define EXT_LED_PIN 18

Adafruit_INA219 ina219;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ina219.begin();
  pinMode(EXT_LED_PIN, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("____________________________");
  float voltage = ina219.getBusVoltage_V();
  float current = ina219.getCurrent_mA();
  float power = ina219.getPower_mW();
                    
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
                    
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" mA");
                    
  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" mW");

  digitalWrite(EXT_LED_PIN, HIGH);
  delay(500);
  digitalWrite(EXT_LED_PIN, LOW);
  delay(500);
}
