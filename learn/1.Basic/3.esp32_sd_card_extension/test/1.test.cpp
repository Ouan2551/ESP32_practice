// #include <Arduino.h>
#include <SD.h>

#define PIN_SPI_CS 5

File myFile;
// 'File' is a class provided by the Arduino SD library
// 'myFile' is a variable of type 'File'

void setup()
{
    Serial.begin(9600);
    bool SD_ready = SD.begin(PIN_SPI_CS);
    if (SD_ready == false)
    {
        Serial.println("SD card not detected.");
        while(true)
        {
            delay(1000);
        }
    }
    Serial.println("SD card initialized.");

    // _______________________________________________

    // open file for writing
    myFile = SD.open("/esp32.txt", FILE_WRITE);

    if(myFile)
    {
        myFile.println("Surprise my friend.");
        myFile.close();
    }
    else
    {
        Serial.println("SD card: Issue to write to data.");
    }
    
    // open file to reading
    myFile = SD.open("/esp32.txt", FILE_READ);
    if (myFile == false)
    {
        while(true)
        {
        Serial.println("Error to read the file txt.");
        delay(1000);
        }
    }

    Serial.println("File content.");
    while(myFile.available() > 0)
    {
        char character = myFile.read();
        Serial.print(character);
    }
    myFile.close();
}
void loop()
{

}