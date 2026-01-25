#include <Arduino.h>
// Define constants
const int thermistorPin = 35; // Pin connected to the thermistor
const float referenceVoltage = 3.3;
const float referenceResistor = 10000; // the 'other' resistor
const float beta = 3950; // Beta value (Typical Value)
const float nominalTemperature = 25; // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000; // Resistance value at nominal temperature

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(thermistorPin, INPUT); // Set pin as input
}

// void loop() {
//   int adcValue = analogRead(thermistorPin); // Read ADC value
//   float voltage = (adcValue * referenceVoltage) / 4095.0; // Calculate voltage
//   float resistance = (voltage * referenceResistor) / (referenceVoltage - voltage); // Calculate thermistor resistance with updated configuration

//   // Calculate temperature using the Beta parameter equation
//   float tempK = 1 / (((log(resistance / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));
  
//   float tempC = tempK - 273.15; // Get temperature in Celsius
//   float tempF = 1.8 * tempC + 32.0; // Get temperature in Fahrenheit

//   //Print temperature
//   printf("TempC: %.2f C\n", tempC);
//   printf("TempF: %.2f F\n", tempF);

//   delay(3000); // Wait 1 second
// }

void loop() {
  int adcValue = analogRead(thermistorPin);
  
  // 1. Prevent 0 or 4095 to avoid division by zero
  if (adcValue <= 0) adcValue = 1;
  if (adcValue >= 4095) adcValue = 4094;

  float voltage = (adcValue * referenceVoltage) / 4095.0;
  
  // 2. Calculate Resistance (Assuming Thermistor is on 3.3V side)
  float resistance = referenceResistor * (voltage / (referenceVoltage - voltage));

  // 3. Steinhart-Hart / Beta Equation
  float steinhart;
  steinhart = resistance / nominalResistance;     // (R/Ro)
  steinhart = log(steinhart);                      // ln(R/Ro)
  steinhart /= beta;                               // 1/B * ln(R/Ro)
  steinhart += 1.0 / (nominalTemperature + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                     // Invert
  
  float tempC = steinhart - 273.15;

  // 4. Use Serial.printf for better compatibility in PIO
  Serial.printf("ADC: %d | Temp: %.2f C\n", adcValue, tempC);

  delay(3000);
}