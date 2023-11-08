#include <LiquidCrystal.h>

//Initialize LCD
const int rs = 8, en = 7, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Initialize Mics
const int mic1 = A2, mic2 = A0, mic3 = A1;

void setup() {
  lcd.begin(16, 2); //cols, rows
  lcd.setCursor(0, 0);
  lcd.print("hello, world!");

  pinMode(mic1, INPUT);
}

void loop() {
  lcd.setCursor(0, 1);

  int volume = analogRead(mic1);
  
  for (int i = 0; i < 20; i++) {
    // This loop will run 20 times. i will take values from 0 to 19.
    // You can place your code that you want to execute 20 times here.
  }

  lcd.clear();
  lcd.print(volume);

  delay(100);

  int db = map(peakToPeak,20,4096,49.5,94);             //calibrate for deciBels

}