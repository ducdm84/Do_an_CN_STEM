
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

int soil_pin = A0;
int sensor_val = 0;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(soil_pin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("Soil Moisture!");
}

void loop() {
  int ss_val = analogRead(soil_pin); 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  sensor_val = map(ss_val,0,1024,0,100);
  // Prints the distance on the Serial Monitor
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Do am: ");
  lcd.setCursor(10, 1);
  lcd.print(int(sensor_val));
  lcd.setCursor(14, 1);
  lcd.print("%");
  delay(1000);
}
