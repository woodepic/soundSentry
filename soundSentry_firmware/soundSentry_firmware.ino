#include <LiquidCrystal.h>

//Initialize LCD
const int rs = 8, en = 7, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Initialize Mics
const int mic1 = A2, mic2 = A0, mic3 = A1;

long startTime;

void setup() {
  lcd.begin(16, 2); //cols, rows
  lcd.setCursor(0, 0);
  lcd.print("hello, world!");
  Serial.begin(9600);

  pinMode(mic1, INPUT);
  pinMode(mic2, INPUT);
  pinMode(mic3, INPUT);

  startTime = millis();
}
void loop() {
  // if ((millis() - startTime) > 2000) {
  //   startTime = millis();
  //   Serial.print(1200);
  //   Serial.print(",");
  // }

  // lcd.setCursor(0, 1);

  // long volume1 = analogRead(mic1);
  // long volume2 = analogRead(mic2);
  // long volume3 = analogRead(mic3);

  // Serial.print(volume1);
  // Serial.print(",");
  // Serial.print(volume2);
  // Serial.print(",");
  // Serial.print(volume3);
  // Serial.print("\n");
  
  long avgVol1 = 0;
  long maxVol1 = 0;

  long avgVol2 = 0;
  long avgVol3 = 0;
  int count = 0;
  long measStart = millis();
  for (int i = 0; i < 200; i++) {
    long reading = abs(analogRead(mic1) - 1551);

    if (reading > maxVol1) {
      maxVol1 = reading;
    }
    // avgVol2 += + analogRead(mic2);
    // avgVol3 += + analogRead(mic3);
    count++;
  }
  avgVol1 = maxVol1;

  // 28db is roughly 150
  // 92 db 1400
  long measEnd = millis();
  long measTime = measEnd - measStart;
  // avgVol1 = avgVol1 / count;
  // avgVol2 = avgVol2 / count;
  // avgVol3 = avgVol3 / count;

  int db = map(avgVol1, 150, 1400, 28, 92);
  // Serial.print(db);
  Serial.print(1200);
  Serial.print(",");
  Serial.println(avgVol1);
  delay(50);

  // // lcd.clear();
  // // lcd.print(volume);

  // delay(100);
  // Serial.println("Mic1: " + String(avgVol1) + "mV");
  // Serial.println("Mic2: " + String(avgVol2) + "mV");
  // Serial.println("Mic3: " + String(avgVol3) + "mV");
  Serial.println("Measurement Time: " + String(measTime) + "ms");
  // Serial.println("");

  // int db = map(peakToPeak,20,4096,49.5,94);             //calibrate for deciBels

}