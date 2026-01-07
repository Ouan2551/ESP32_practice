#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup()
{
  Serial.begin(9600);
  bool display_ready = display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  if (display_ready == true)
  {
    Serial.println("Display allocation succeed");
  }
  else
  {
    Serial.println("Display allocation failed");
  }

  display.clearDisplay();

  // OUTPUT general text
  display.setTextSize(1); // 1 is smallest number
  display.setTextColor(WHITE);
  display.setCursor(0, 28); //  tell the display where to start writing at (x, y) position
  display.println("Hello World");
  display.display(); // push RAM into OLED
  delay(5000);
  display.clearDisplay(); //clear ram only not clear display
  display.display(); //after clear ram we just display blank screen

  // OUTPUT Inverted text
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, 28);
  display.println("Hello World");
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();

  // OUTPUT Number
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println(1234567890);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();



}
void loop()
{

}