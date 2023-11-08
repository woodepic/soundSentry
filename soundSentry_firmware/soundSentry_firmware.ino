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
  Serial.begin(9600);

  pinMode(mic1, INPUT);
  pinMode(mic2, INPUT);
  pinMode(mic3, INPUT);
}

void loop() {
  lcd.setCursor(0, 1);

  long volume1 = analogRead(mic1);
  long volume2 = analogRead(mic2);
  long volume3 = analogRead(mic3);
  
  long avgVol1 = 0;
  long avgVol2 = 0;
  long avgVol3 = 0;
  int count = 0;
  long measStart = millis();
  for (int i = 0; i < 100; i++) {
    avgVol1 += + analogRead(mic1);
    avgVol2 += + analogRead(mic2);
    avgVol3 += + analogRead(mic3);
    count++;
  }
  long measEnd = millis();
  long measTime = measEnd - measStart;
  avgVol1 = avgVol1 / count;
  avgVol2 = avgVol2 / count;
  avgVol3 = avgVol3 / count;

  // lcd.clear();
  // lcd.print(volume);

  delay(100);
  Serial.println("Mic1: " + String(avgVol1) + "mV");
  Serial.println("Mic2: " + String(avgVol2) + "mV");
  Serial.println("Mic3: " + String(avgVol3) + "mV");
  Serial.println("Measurement Time: " + String(measTime) + "ms");
  Serial.println("");

  // int db = map(peakToPeak,20,4096,49.5,94);             //calibrate for deciBels

}