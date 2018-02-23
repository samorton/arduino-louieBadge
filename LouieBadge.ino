#include "DFRobot_HT1632C.h"


#define DATA 0
#define CS 1
#define WR 3
//#define RD 8
volatile int buttonState = 0;         

#define BTN 2     


DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);
int i =0;
char* messages[] = {" Hello   Louie :)",
               "Hi Mabel xx <3 x",
               "Love you Lilia " };

void setup() {
  attachInterrupt(0, pin_ISR, RISING);
  pinMode(BTN, INPUT);
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  delay(500);
}
char* currmsg;

void loop() {
   ht1632c.inLowpower(false);
  ht1632c.print(messages[i],5);
  delay(100);
  
   ht1632c.inLowpower(true);
  //delay(100);
}


void pin_ISR() {
  buttonState = digitalRead(BTN);
  if (++i>2)
    i=0;
   
  
}
