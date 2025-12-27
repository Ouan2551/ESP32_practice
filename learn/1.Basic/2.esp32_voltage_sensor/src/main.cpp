// #include <Arduino.h>

// /*
//  * This ESP32 code is created by esp32io.com
//  *
//  * This ESP32 code is released in the public domain
//  *
//  * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-measure-voltage
//  */

// #define ANALOG_IN_PIN  36 // ESP32 pin GPIO36 (ADC0) connected to voltage sensor
// #define REF_VOLTAGE    3.3
// #define ADC_RESOLUTION 4096.0
// #define R1             30000.0 // resistor values in voltage sensor (in ohms)
// #define R2             7500.0  // resistor values in voltage sensor (in ohms)
// #define LED_PIN 18

// void setup() {
//   Serial.begin(9600);
//   pinMode(LED_PIN, OUTPUT);

//   // set the ADC attenuation to 11 dB (up to ~3.3V input)
//   analogSetAttenuation(ADC_11db);
// }

// void loop() {
//   // read the analog input
//   digitalWrite(LED_PIN, HIGH);
//   int adc_value = analogRead(ANALOG_IN_PIN);

//   // determine voltage at adc input
//   float voltage_adc = ((float)adc_value * REF_VOLTAGE) / ADC_RESOLUTION;

//   // calculate voltage at the sensor input
//   float voltage_in = voltage_adc * (R1 + R2) / R2;

//   // print results to serial monitor to 2 decimal places
//   Serial.print("Measured Voltage = ");
//   Serial.println(voltage_in, 2);

//   delay(500);
// }


#include <Arduino.h>

#define ANALOG_IN_PIN  36   // GPIO36 (ADC1_CH0)
#define LED_PIN        17   // status LED (optional)

#define REF_VOLTAGE    3.3
#define ADC_RESOLUTION 4095.0

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  // Configure ADC
  analogSetWidth(12);           // 12-bit ADC (0–4095)
  analogSetAttenuation(ADC_11db); // 0–3.3V range
}

void loop() {
  digitalWrite(LED_PIN, HIGH);

  // Average multiple samples for stability
  const int samples = 20;
  long sum = 0;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(ANALOG_IN_PIN);
    delay(2);
  }

  float adc_value = sum / (float)samples;

  // Convert ADC value to voltage
  float voltage = adc_value * REF_VOLTAGE / ADC_RESOLUTION;

  Serial.print("LED Voltage = ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  delay(500);
}