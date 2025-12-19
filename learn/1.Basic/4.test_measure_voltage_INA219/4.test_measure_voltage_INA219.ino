#include <Wire.h>
#include <Adafruit_INA219.h>

#define EXT_LED_PIN 18

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  delay(1000);  // allow Serial Monitor to connect

  Wire.begin(21, 22);  // ESP32 I2C pins

  if (!ina219.begin()) {
    Serial.println("INA219 not found");
    while (1);
  }

  ina219.setCalibration_32V_2A();

  pinMode(EXT_LED_PIN, OUTPUT);

  Serial.println("INA219 Ready");
}

void loop() {
  float voltage = ina219.getBusVoltage_V();
  float current = ina219.getCurrent_mA();
  float power   = ina219.getPower_mW();

  Serial.println("____________________________");
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