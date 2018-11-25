#include <Adafruit_BMP280.h>
#include <Adafruit_SSD1306.h>
#include <SD.h>
#include <SPI.h>
File myFile;
#define OLED_Address 0x3C
Adafruit_BMP280 bmp; // I2C
Adafruit_SSD1306 oled(1);

void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  
  if (!bmp.begin()) {  
    oled.setCursor(0,0);
    oled.print("SENSOR BULNAMADI!");
    oled.display();
    while (1);
  }
}

void loop() {
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.print("Sicaklik = ");
  oled.print(bmp.readTemperature());
  oled.print(" C");
  
  oled.setCursor(0,8);
  oled.print("Basinc. = ");
  oled.print(bmp.readPressure()/100);
  oled.print(" hPa");
  
  oled.setCursor(0,16);
  oled.print("Yukseklik = ");
  oled.print(bmp.readAltitude(1016.9));
  oled.print(" m");
 
  oled.display();
  delay(2000);
}
