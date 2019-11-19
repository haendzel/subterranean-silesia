#include <Wire.h>

//COUNTER LEDS, COAL MINES 
#define CounterLEDBrzeszcze 24 //F2
  #define coalMine1 3

#define CounterLEDJaworzno 23 //E1
  #define coalMine2 4

#define CounterLEDLibiaz 26 //D1
  #define coalMine3 6

#define CounterLEDRudaSilesia1 22 //F4
  #define coalMine4 9 //liquidation

#define CounterLEDRudaSilesia2 25 //E2
  #define coalMine5 10 

//#define CounterLEDRudaSilesia3 27 //D4
//  #define coalMine6 7

//#define CounterLEDRudaSilesia4 28 //C4
//  #define coalMine7 8

//SWITCHES
#define switchGOP2 52
#define switchJCOP 50
 
int stateCoalMine1 = LOW;
int stateCoalMine2 = LOW;
int stateCoalMine3 = LOW;
int stateCoalMine4 = LOW;
int stateCoalMine5 = LOW;
//int stateCoalMine6 = LOW;
//int stateCoalMine7 = LOW;
//int stateCoalMine8 = LOW;

int stateCounterLEDRudaSilesia1 = LOW;
unsigned long blinkCounterLEDRudaSilesia1 = 100;
unsigned long worktimeCounterLEDRudaSilesia1 = 0;
 
unsigned long workCoalMine1 = 300;
unsigned long workCoalMine2 = 300;
unsigned long workCoalMine3 = 300;
unsigned long workCoalMine4 = 300;
unsigned long workCoalMine5 = 300;
//unsigned long workCoalMine6 = 300;
//unsigned long workCoalMine7 = 300;
//unsigned long workCoalMine8 = 300;
 
unsigned long currentMillis = 0;

unsigned long worktime1 = 0;
unsigned long worktime2 = 0;
unsigned long worktime3 = 0;
unsigned long worktime4 = 0;
unsigned long worktime5 = 0;
//unsigned long worktime6 = 0;
//unsigned long worktime7 = 0;
//unsigned long worktime8 = 0;
 
void setup()
{
  Serial.begin(115200);

  Serial.write("Dear Gods or Programmers Alek and Filip, thank you for my new life."); 
  pinMode(coalMine1, OUTPUT);
  pinMode(coalMine2, OUTPUT);
  pinMode(coalMine3, OUTPUT);
  pinMode(coalMine4, OUTPUT);
  pinMode(coalMine5, OUTPUT);
  //pinMode(coalMine6, OUTPUT);
  //pinMode(coalMine7, OUTPUT);
  //pinMode(coalMine8, OUTPUT);
  pinMode(CounterLEDBrzeszcze, OUTPUT);
  pinMode(CounterLEDJaworzno, OUTPUT);
  pinMode(CounterLEDLibiaz, OUTPUT);
  pinMode(CounterLEDRudaSilesia1, OUTPUT);
  pinMode(CounterLEDRudaSilesia2, OUTPUT);
  //pinMode(CounterLEDRudaSilesia3, OUTPUT);
  //pinMode(CounterLEDRudaSilesia4, OUTPUT);
  //pinMode(CounterLEDBytom2, OUTPUT);
  pinMode(switchGOP2, INPUT_PULLUP);
  pinMode(switchJCOP, INPUT_PULLUP);
}
 
void loop()
{
  currentMillis = millis();
  worktime();
  blinks();
 
  if (digitalRead(switchGOP2) == LOW) {
    blinkCounterLEDRudaSilesia1 = 400;
    digitalWrite(CounterLEDRudaSilesia2, HIGH);
  } else {
    digitalWrite(coalMine4, LOW);
    digitalWrite(coalMine5, LOW);
    digitalWrite(CounterLEDRudaSilesia1, LOW);
    digitalWrite(CounterLEDRudaSilesia2, LOW);
  }

  if (digitalRead(switchJCOP) == LOW) {
    digitalWrite(CounterLEDBrzeszcze, HIGH);
    digitalWrite(CounterLEDJaworzno, HIGH);
    digitalWrite(CounterLEDLibiaz, HIGH);
  } else {
    digitalWrite(coalMine1, LOW);
    digitalWrite(coalMine2, LOW);
    digitalWrite(coalMine3, LOW);
    digitalWrite(CounterLEDBrzeszcze, LOW);
    digitalWrite(CounterLEDJaworzno, LOW);
    digitalWrite(CounterLEDLibiaz, LOW);
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
}

void blinks()
{
  if (currentMillis - worktimeCounterLEDRudaSilesia1 >= blinkCounterLEDRudaSilesia1) {
      worktimeCounterLEDRudaSilesia1 = currentMillis;
      stateCounterLEDRudaSilesia1 = !stateCounterLEDRudaSilesia1;
      digitalWrite(CounterLEDRudaSilesia1, stateCounterLEDRudaSilesia1);
  }
}
