#include <Wire.h>

//COUNTER LEDS, COAL MINES
#define CounterLEDKatowice1 22
//#define coalMine1

#define CounterLEDKatowice2 27
//#define coalMine8

#define CounterLEDKatowice3 25
//#define coalMine7

#define CounterLEDKatowice4 26
//#define coalMine4

#define CounterLEDSosnowiec 24
//#define coalMine6

#define CounterLEDPiekary 28
//#define coalMine5

#define CounterLEDBytom1 29
//#define coalMine2

#define CounterLEDBytom2 31
//#define coalMine3

//SWITCHES
#define switchKatowice 50
#define switchGOP1 52

//int stateCoalMine1 = LOW;
//int stateCoalMine2 = LOW;
//int stateCoalMine3 = LOW;
//int stateCoalMine4 = LOW;
//int stateCoalMine5 = LOW;
//int stateCoalMine6 = LOW;
//int stateCoalMine7 = LOW;
//int stateCoalMine8 = LOW;

int stateCounterLEDKatowice1 = LOW;
unsigned long blinkCounterLEDKatowice1 = 50;
unsigned long worktimeCounterLEDKatowice1 = 0;

int stateCounterLEDBytom1 = LOW;
unsigned long blinkCounterLEDBytom1 = 500;
unsigned long worktimeCounterLEDBytom1 = 0;

//unsigned long workCoalMine1 = 300;
//unsigned long workCoalMine2 = 300;
//unsigned long workCoalMine3 = 300;
//unsigned long workCoalMine4 = 300;
//unsigned long workCoalMine5 = 300;
//unsigned long workCoalMine6 = 300;
//unsigned long workCoalMine7 = 300;
//unsigned long workCoalMine8 = 300;

unsigned long currentMillis = 0;

//unsigned long worktime1 = 0;
//unsigned long worktime2 = 0;
//unsigned long worktime3 = 0;
//unsigned long worktime4 = 0;
//unsigned long worktime5 = 0;
//unsigned long worktime6 = 0;
//unsigned long worktime7 = 0;
//unsigned long worktime8 = 0;

void setup()
{

  Serial.begin(9600);

  Serial.write("Hush! Do you hear it? Something work undeground in Silesia.");

  //pinMode(coalMine1, OUTPUT);
  //pinMode(coalMine2, OUTPUT);
  //pinMode(coalMine3, OUTPUT);
  //pinMode(coalMine4, OUTPUT);
  //pinMode(coalMine5, OUTPUT);
  //pinMode(coalMine6, OUTPUT);
  //pinMode(coalMine7, OUTPUT);
  //pinMode(coalMine8, OUTPUT);
  pinMode(CounterLEDKatowice1, OUTPUT);
  pinMode(CounterLEDKatowice2, OUTPUT);
  pinMode(CounterLEDKatowice3, OUTPUT);
  pinMode(CounterLEDKatowice4, OUTPUT);
  pinMode(CounterLEDSosnowiec, OUTPUT);
  pinMode(CounterLEDPiekary, OUTPUT);
  pinMode(CounterLEDBytom1, OUTPUT);
  pinMode(CounterLEDBytom2, OUTPUT);
  pinMode(switchGOP1, INPUT_PULLUP);
  pinMode(switchKatowice, INPUT_PULLUP);
}

void loop()
{

  currentMillis = millis();
//  worktime();
  blinks();

  if (digitalRead(switchKatowice) == LOW)
  {
    blinkCounterLEDKatowice1 = 50;
    digitalWrite(CounterLEDKatowice2, HIGH);
    digitalWrite(CounterLEDKatowice3, HIGH);
    digitalWrite(CounterLEDKatowice4, HIGH);
  }
  else
  {
    //digitalWrite(coalMine1, LOW);
    //digitalWrite(coalMine4, LOW);
    //digitalWrite(coalMine8, LOW);
    //digitalWrite(coalMine7, LOW);
    digitalWrite(CounterLEDKatowice1, LOW);
    digitalWrite(CounterLEDKatowice2, LOW);
    digitalWrite(CounterLEDKatowice3, LOW);
    digitalWrite(CounterLEDKatowice4, LOW);
  }

  if (digitalRead(switchGOP1) == LOW)
  {
    blinkCounterLEDBytom1 = 500;
    digitalWrite(CounterLEDSosnowiec, HIGH);
    digitalWrite(CounterLEDPiekary, HIGH);
    digitalWrite(CounterLEDBytom2, HIGH);
  }
  else
  {
    //digitalWrite(coalMine2, LOW);
    //digitalWrite(coalMine3, LOW);
    //digitalWrite(coalMine5, LOW);
    //digitalWrite(coalMine6, LOW);
    digitalWrite(CounterLEDSosnowiec, LOW);
    digitalWrite(CounterLEDPiekary, LOW);
    digitalWrite(CounterLEDBytom1, LOW);
    digitalWrite(CounterLEDBytom2, LOW);
  }
}

//void worktime()
//{
//  if (currentMillis - worktime1 >= workCoalMine1)
//  {
//    worktime1 = currentMillis;
//    stateCoalMine1 = !stateCoalMine1;
//    digitalWrite(coalMine1, stateCoalMine1);
//  }
//  if (currentMillis - worktime2 >= workCoalMine2)
//  {
//    worktime2 = currentMillis;
//    stateCoalMine2 = !stateCoalMine2;
//    digitalWrite(coalMine2, stateCoalMine2);
//  }
//  if (currentMillis - worktime3 >= workCoalMine3)
//  {
//    worktime3 = currentMillis;
//    stateCoalMine3 = !stateCoalMine3;
//    digitalWrite(coalMine3, stateCoalMine3);
//  }
//  if (currentMillis - worktime4 >= workCoalMine4)
//  {
//    worktime4 = currentMillis;
//    stateCoalMine4 = !stateCoalMine4;
//    digitalWrite(coalMine4, stateCoalMine4);
//  }
//
//  if (currentMillis - worktime5 >= workCoalMine5)
//  {
//    worktime5 = currentMillis;
//    stateCoalMine5 = !stateCoalMine5;
//    digitalWrite(coalMine5, stateCoalMine5);
//  }
//
//  if (currentMillis - worktime6 >= workCoalMine6)
//  {
//    worktime6 = currentMillis;
//    stateCoalMine6 = !stateCoalMine6;
//    digitalWrite(coalMine6, stateCoalMine6);
//  }
//
//  if (currentMillis - worktime7 >= workCoalMine7)
//  {
//    worktime6 = currentMillis;
//    stateCoalMine7 = !stateCoalMine7;
//    digitalWrite(coalMine7, stateCoalMine7);
//  }
//
//  if (currentMillis - worktime8 >= workCoalMine8)
//  {
//    worktime6 = currentMillis;
//    stateCoalMine8 = !stateCoalMine8;
//    digitalWrite(coalMine8, stateCoalMine8);
//  }
//}

void blinks()
{
  if (currentMillis - worktimeCounterLEDKatowice1 >= blinkCounterLEDKatowice1)
  {
    worktimeCounterLEDKatowice1 = currentMillis;
    stateCounterLEDKatowice1 = !stateCounterLEDKatowice1;
    digitalWrite(CounterLEDKatowice1, stateCounterLEDKatowice1);
  }

  if (currentMillis - worktimeCounterLEDBytom1 >= blinkCounterLEDBytom1)
  {
    worktimeCounterLEDBytom1 = currentMillis;
    stateCounterLEDBytom1 = !stateCounterLEDBytom1;
    digitalWrite(CounterLEDBytom1, stateCounterLEDBytom1);
  }
}
