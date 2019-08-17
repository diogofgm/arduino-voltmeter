/* 
* Voltmeter with LCD display
*/

#include "LiquidCrystal_I2C.h"
#include "Wire.h"

// Set correct I2C address of the I2C LCD (0x27 or 0x3F)
// and the LCD size
#define LCDADDR 0x27
#define LCDCOLS 16
#define LCDROWS 2


// LCD object
// LiquidCrystal_I2C lcd(LCDADDR, LCDCOLS, LCDROWS);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

    lcd.begin(16,2);
    lcd.init();

    // Turn on the backlight.
    lcd.backlight();
}

void loop() {
    int Pin; // 0-1023 I/P
    double Vin;

    Pin = analogRead(A0); // Probe Input
    Vin = Pin * (5.0*11 / 1023); // Pin to Vin (Reduction Factor 11)

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(Vin, 3);
    lcd.print(" VOLT DC "); // Custom Text

    delay(500);
}