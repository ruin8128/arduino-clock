#include <TM1637.h>
#include <DS3232RTC.h>
DS3232RTC myRTC;

//7segLED tm1637
#define CLK 2
#define DIO 3
TM1637 tm(CLK,DIO);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    myRTC.begin();
    //時間の設定
    setTime(12,42,50,30,10,2022);
     if(timeStatus() != timeSet)
        Serial.println("Unable to sync with the RTC");
    else
        Serial.println("RTC has set the system time");
}

void loop() {
  unsigned int digit_h1,digit_h2,digit_m1,digit_m2;
  //     1       2      :  0        0
  
  digit_h1 = hour() / 10;
  digit_h2 = hour() % 10;
  digit_m1 = minute() / 10;
  digit_m2 = minute() % 10;
  
  tm.point(1);
  tm.display(0,digit_h1);
  tm.display(1,digit_h2);
  tm.display(2,digit_m1);
  tm.display(3,digit_m2);
}
