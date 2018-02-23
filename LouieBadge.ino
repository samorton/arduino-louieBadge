#include "DFRobot_HT1632C.h"


#define DATA 0
#define CS 1
#define WR 3
//#define RD 8

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char str[] = " Hello   Louie :)";

void setup() {

  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  ht1632c.print(str,50);
  //delay(100);
}
