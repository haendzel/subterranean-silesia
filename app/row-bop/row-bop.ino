#include <Wire.h>

//COUNTER LEDS, COAL MINES 
#define CounterLEDCzechowiceDziedzice 22 //A3
  #define coalMine1 3

#define CounterLEDRybnik1 23 //C3
  #define coalMine2 4

#define CounterLEDRybnik2 25 //D3
  #define coalMine3 5

#define CounterLEDPruszowice 28 //E3
  #define coalMine4 9

#define CounterLEDJastrzebie1 27 //E4
  #define coalMine5 7 

#define CounterLEDJastrzebie2 29 //D4
  #define coalMine6 8 //opening

//#define CounterLEDJastrzebie3 28 //C4
  //#define coalMine7 8

//#define CounterLEDJastrzebie4 29 //C2
  //#define coalMine8 11

//#define CounterLEDGliwice 30 //C3
  //#define coalMine9 12

//#define CounterLEDZabrze 31 //A2
  //#define coalMine10 44 //liquidation

//#define CounterLEDLaziska 32 //A1
  //#define coalMine11 13 


//SWITCHES
#define switchROW 50
#define switchBOP 48
 
int stateCoalMine1 = LOW;
int stateCoalMine2 = LOW;
int stateCoalMine3 = LOW;
int stateCoalMine4 = LOW;
int stateCoalMine5 = LOW;
int stateCoalMine6 = LOW;
//int stateCoalMine7 = LOW;
//int stateCoalMine8 = LOW;
//int stateCoalMine9 = LOW;
//int stateCoalMine10 = LOW;
//int stateCoalMine11 = LOW;

int stateCounterLEDJastrzebie2 = LOW;
unsigned long blinkCounterLEDJastrzebie2= 400;
unsigned long worktimeCounterLEDJastrzebie2 = 0;
 
unsigned long workCoalMine1 = 1000;
unsigned long workCoalMine2 = 1000;
unsigned long workCoalMine3 = 1000;
unsigned long workCoalMine4 = 1000;
unsigned long workCoalMine5 = 1000;
unsigned long workCoalMine6 = 1000;
//unsigned long workCoalMine7 = 300;
//unsigned long workCoalMine8 = 300;
//unsigned long workCoalMine9 = 300;
//unsigned long workCoalMine10 = 300;
//unsigned long workCoalMine11 = 300;
 
unsigned long currentMillis = 0;

unsigned long worktime1 = 0;
unsigned long worktime2 = 0;
unsigned long worktime3 = 0;
unsigned long worktime4 = 0;
unsigned long worktime5 = 0;
unsigned long worktime6 = 0;
//unsigned long worktime7 = 0;
//unsigned long worktime8 = 0;
//unsigned long worktime9 = 0;
//unsigned long worktime10 = 0;
//unsigned long worktime11 = 0;
 
void setup()
{
  Serial.begin(115200);

  Serial.write("Dear Gods or Programmers Alek and Filip, thank you for my new life."); 

  pinMode(coalMine1, OUTPUT);
  pinMode(coalMine2, OUTPUT);
  pinMode(coalMine3, OUTPUT);
  pinMode(coalMine4, OUTPUT);
  pinMode(coalMine5, OUTPUT);
  pinMode(coalMine6, OUTPUT);
  //pinMode(coalMine7, OUTPUT);
  //pinMode(coalMine8, OUTPUT);
  //pinMode(coalMine9, OUTPUT);
  //pinMode(coalMine10, OUTPUT);
  //pinMode(coalMine11, OUTPUT);
  pinMode(CounterLEDCzechowiceDziedzice, OUTPUT);
  pinMode(CounterLEDRybnik1, OUTPUT);
  pinMode(CounterLEDRybnik2, OUTPUT);
  pinMode(CounterLEDPruszowice, OUTPUT);
  pinMode(CounterLEDJastrzebie1, OUTPUT);
  pinMode(CounterLEDJastrzebie2, OUTPUT);
  //pinMode(CounterLEDJastrzebie3, OUTPUT);
  //pinMode(CounterLEDJastrzebie4, OUTPUT);
  //pinMode(CounterLEDRadlin, OUTPUT);
  //pinMode(CounterLEDKnurow, OUTPUT);
  //pinMode(CounterLEDOrmontowice, OUTPUT);
  pinMode(switchBOP, INPUT_PULLUP);
  pinMode(switchROW, INPUT_PULLUP);
}
 
void loop()
{
  currentMillis = millis();
  worktime();
  blinks();
 
  if (digitalRead(switchROW) == LOW) {
    blinkCounterLEDJastrzebie2 = 400;
    digitalWrite(CounterLEDJastrzebie1, HIGH);
    digitalWrite(CounterLEDRybnik1, HIGH);
    digitalWrite(CounterLEDRybnik2, HIGH);
    digitalWrite(CounterLEDPruszowice, HIGH);
  } else {
    digitalWrite(coalMine2, LOW);
    digitalWrite(coalMine3, LOW);
    digitalWrite(coalMine4, LOW);
    digitalWrite(CounterLEDJastrzebie1, LOW);
    digitalWrite(CounterLEDJastrzebie2, LOW);
    digitalWrite(CounterLEDRybnik1, LOW);
    digitalWrite(CounterLEDRybnik2, LOW);
    digitalWrite(CounterLEDPruszowice, LOW);
  }

  if (digitalRead(switchBOP) == LOW) {
    digitalWrite(CounterLEDCzechowiceDziedzice, HIGH);
  } else {
    digitalWrite(coalMine1, LOW);
    digitalWrite(CounterLEDCzechowiceDziedzice, LOW);
  }
}

void worktime()
{
    if (currentMillis - worktime1 >= workCoalMine1) {
      worktime1 = currentMillis;
      stateCoalMine1 = !stateCoalMine1;
      digitalWrite(coalMine1, stateCoalMine1);
    }
    if (currentMillis - worktime2 >= workCoalMine2) {
      worktime2 = currentMillis;
      stateCoalMine2 = !stateCoalMine2;
      digitalWrite(coalMine2, stateCoalMine2);
    }
    if (currentMillis - worktime3 >= workCoalMine3) {
      worktime3 = currentMillis;
      stateCoalMine3 = !stateCoalMine3;
      digitalWrite(coalMine3, stateCoalMine3);
    }
    if (currentMillis - worktime4 >= workCoalMine4) {
      worktime4 = currentMillis;
      stateCoalMine4 = !stateCoalMine4;
      digitalWrite(coalMine4, stateCoalMine4);
    }

    if (currentMillis - worktime5 >= workCoalMine5) {
      worktime5 = currentMillis;
      stateCoalMine5 = !stateCoalMine5;
      digitalWrite(coalMine5, stateCoalMine5);
    }

    if (currentMillis - worktime6 >= workCoalMine6) {
      worktime6 = currentMillis;
      stateCoalMine6 = !stateCoalMine6;
      digitalWrite(coalMine6, stateCoalMine6);
    }
}

void blinks()
{
  if (currentMillis - worktimeCounterLEDJastrzebie2 >= blinkCounterLEDJastrzebie2) {
      worktimeCounterLEDJastrzebie2 = currentMillis;
      stateCounterLEDJastrzebie2 = !stateCounterLEDJastrzebie2;
      digitalWrite(CounterLEDJastrzebie2, stateCounterLEDJastrzebie2);
  }
}
