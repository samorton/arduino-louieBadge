#include "DFRobot_HT1632C.h"


#define DATA 0
#define CS 1
#define WR 3
//#define RD 8
volatile int buttonState = 0;         

#define BTN 2     


DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char* messages[] = {" Hello   Louie :)",
               "Hi Mabel xx <3 x",
               "Love you Lilia " };

void setup() {
  attachInterrupt(0, pin_ISR, CHANGE);
  pinMode(BTN, INPUT);
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<3;i++){
    ht1632c.print(messages[i],50);
  }
  //delay(100);
}
