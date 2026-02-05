#include <Arduino.h>
#include <math.h>

#define NTC_PIN 34 // ADC pin

float TempC, TempF;

float Read_NTC10k()
{
  float a = 639.5, b = -0.1332, c = -162.5; // curve-fit constants
  float R_ntc, V_ntc, Temp;
  int adcValue = analogRead(NTC_PIN);
  V_ntc = (adcValue*3.3)/4095.0; // Converts digital ADC value back into real voltage
  R_ntc = 10000.0 * ((3.3/V_ntc) - 1); // Based on voltage divider rule // Fixed resistor = 10kΩ
  Temp = a * pow(R_ntc, b) + c; // depends on the thermistor model
  return Temp;
}

void setup()
{
  Serial.begin(9600);

  analogReadResolution(12);          // 12-bit ADC (0–4095)
  analogSetAttenuation(ADC_11db);    // 0–3.3V range
}

void loop()
{
  TempC = Read_NTC10k();
  TempF = (TempC * 1.8) + 32.0;
  Serial.print(TempC);
  Serial.print("°C \t");
  Serial.print(TempF);
  Serial.println("°F");
  delay(1500);
}