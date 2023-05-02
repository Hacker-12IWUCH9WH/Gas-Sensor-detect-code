/*MQ2 sensor with Arduino.
 * https://srituhobby.com
 */
 
#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED 6
#define Buzzer 7
#define Sensor A1

void setup() {
  Serial.begin(9200);
  lcd.begin();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(Sensor);
  lcd.setCursor(0, 0);
  lcd.print(" Gas Value :");
  lcd.print(value);
  lcd.print("  ");

  if (value > 100) {
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("GAS Detected!");
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("             ");
  }
}
