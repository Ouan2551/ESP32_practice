#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ina219.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
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
                    
  delay(2000);
}
