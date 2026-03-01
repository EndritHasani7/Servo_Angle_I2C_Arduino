#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// ---- Config ---- 
const uint8_t LCD_ADDR = 0x27;  /// Common: 0x27 or 0x3F 
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

const int SERVO_PIN = 8;

const int LED_RED = 3;
const int LED_BLUE = 2;

// objects --- 
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
Servo myServo;

// Forward declaration so loop() can call it
void displayAngle(int angle);

void setup() 
{
  Wire.begin();
  myServo.attach(SERVO_PIN);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo angle:");

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
}

void loop() {
  // Sweep 0 -> 180
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    displayAngle(angle);
    digitalWrite(LED_BLUE, HIGH);
    delay(10);
  }
  digitalWrite(LED_BLUE, LOW);
  delay(7000);

  // Sweep 180 -> 0
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    displayAngle(angle);
    digitalWrite(LED_RED, HIGH);
    delay(10);
  }
  digitalWrite(LED_RED, LOW);
  delay(1000);
}
 
void displayAngle(int angle) {
  lcd.setCursor(0, 1);      // second row
  lcd.print("      ");      // quick clear of previous value area
  lcd.setCursor(0, 1);
  lcd.print(angle);
  lcd.print((char)223);     // degree symbol on HD44780
}

