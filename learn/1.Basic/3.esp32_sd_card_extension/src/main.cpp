// #include <Arduino.h>
// #include <SD.h>

// #define PIN_SPI_CS 5

// File myFile;
// // 'File' is a class provided by the Arduino SD library
// // 'myFile' is a variable of type 'File'

// void setup()
// {
//     Serial.begin(9600);
//     bool SD_ready = SD.begin(PIN_SPI_CS);
//     if (SD_ready == false)
//     {
//         Serial.println("SD card not detected.");
//         while(true)
//         {
//             delay(1000);
//         }
//     }
//     Serial.println("SD card initialized.");

//     // _______________________________________________

//     // open file for writing
//     myFile = SD.open("/esp32.txt", FILE_WRITE);

//     if(myFile)
//     {
//         myFile.println("Surprise my friend.");
//         myFile.close();
//     }
//     else
//     {
//         Serial.println("SD card: Issue to write to data.");
//     }
    
//     // open file to reading
//     myFile = SD.open("/esp32.txt", FILE_READ);
//     if (myFile == false)
//     {
//         while(true)
//         {
//         Serial.println("Error to read the file txt.");
//         delay(1000);
//         }
//     }

//     Serial.println("File content.");
//     while(myFile.available() > 0)
//     {
//         char character = myFile.read();
//         Serial.print(character);
//     }
//     myFile.close();
// }
// void loop()
// {

// }

// ___________________________________________________________________________

// Write variable to SD Card
#include <Arduino.h>
#include <SD.h>
#define PIN_SPI_CS 5

File myfile;
int Integer = -52;
float Float = -12.7;
String string = "My name is ";
char Char[] = "Nannaphat";
byte byte_array[] = {1, 2, 3, 4, 5};

void setup()
{
  Serial.begin(9600);

  bool sd_ready = SD.begin(PIN_SPI_CS);
  if (sd_ready == false)
  {
    while(true)
    {
      Serial.println("False to read SD card.");
      delay(1000);
    }
  }
  Serial.println("Successful to read SD card.");

  // writing the data
  myfile = SD.open("/esp32.txt", FILE_WRITE);
  if (myfile)
  {
    myfile.print(Integer); myfile.print(Float); myfile.print(string); myfile.print(Char);
    myfile.write(byte_array, 5);
  }
  myfile.close();

  // reading the data
  myfile = SD.open("/esp32.txt", FILE_READ);
  if (myfile == false)
  {
    while(true)
    {
      Serial.println("Error to read the file txt.");
      delay(1000);
    }
  }

  Serial.println("File content.");
  while(myfile.available() > 0)
  {
    char character = myfile.read();
    Serial.println(character);
  }
  myfile.close();
}

void loop()
{

}