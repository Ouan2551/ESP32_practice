// #include <Arduino.h>
#include <SD.h>

#define PIN_SPI_CS 5

File myFile;

void setup()
{
    Serial.begin(9600);
    bool SD_ready = SD.begin(PIN_SPI_CS);
    if (SD_ready == false)
    {
        Serial.println("SD card not detected");
        while(true)
        {
            delay(1000);
        }
    }
    Serial.println("SD card initialized");

}
void loop()
{

}