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

#define CounterLEDRudaSilesia3 27 //D4
  #define coalMine6 7

#define CounterLEDRudaSilesia4 28 //C4
  #define coalMine7 8

#define CounterLEDMikolow 29 //C2
  #define coalMine8 11

#define CounterLEDGliwice 30 //C3
  #define coalMine9 12

#define CounterLEDZabrze 31 //A2
  #define coalMine10 44 //liquidation

#define CounterLEDLaziska 32 //A1
  #define coalMine11 13 

#define CounterLEDUnnamed 33 //B3
  #define coalMine12 5


//SWITCHES
#define switchGOP2 52
#define switchJCOP 50
 
int stateCoalMine1 = LOW;
int stateCoalMine2 = LOW;
int stateCoalMine3 = LOW;
int stateCoalMine4 = LOW;
int stateCoalMine5 = LOW;
int stateCoalMine6 = LOW;
int stateCoalMine7 = LOW;
int stateCoalMine8 = LOW;
int stateCoalMine9 = LOW;
int stateCoalMine10 = LOW;
int stateCoalMine11 = LOW;
int stateCoalMine12 = LOW;

int stateCounterLEDRudaSilesia1 = LOW;
unsigned long blinkCounterLEDRudaSilesia1 = 400;
unsigned long worktimeCounterLEDRudaSilesia1 = 0;

int stateCounterLEDZabrze = LOW;
unsigned long blinkCounterLEDZabrze = 50;
unsigned long worktimeCounterLEDZabrze = 0;

int stateCounterLEDUnnamed = LOW;
unsigned long blinkCounterLEDUnnamed = 50;
unsigned long worktimeCounterLEDUnnamed = 0;
 
unsigned long workCoalMine1 = 1000;
unsigned long workCoalMine2 = 200;
unsigned long workCoalMine3 = 300;
unsigned long workCoalMine4 = 300;
unsigned long workCoalMine5 = 300;
unsigned long workCoalMine6 = 300;
unsigned long workCoalMine7 = 300;
unsigned long workCoalMine8 = 300;
unsigned long workCoalMine9 = 300;
unsigned long workCoalMine10 = 300;
unsigned long workCoalMine11 = 300;
unsigned long workCoalMine12 = 300;
 
unsigned long currentMillis = 0;

unsigned long worktime1 = 0;
unsigned long worktime2 = 0;
unsigned long worktime3 = 0;
unsigned long worktime4 = 0;
unsigned long worktime5 = 0;
unsigned long worktime6 = 0;
unsigned long worktime7 = 0;
unsigned long worktime8 = 0;
unsigned long worktime9 = 0;
unsigned long worktime10 = 0;
unsigned long worktime11 = 0;
unsigned long worktime12 = 0;
 
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
  pinMode(coalMine7, OUTPUT);
  pinMode(coalMine8, OUTPUT);
  pinMode(coalMine9, OUTPUT);
  pinMode(coalMine10, OUTPUT);
  pinMode(coalMine11, OUTPUT);
  pinMode(coalMine12, OUTPUT);
  pinMode(CounterLEDBrzeszcze, OUTPUT);
  pinMode(CounterLEDJaworzno, OUTPUT);
  pinMode(CounterLEDLibiaz, OUTPUT);
  pinMode(CounterLEDRudaSilesia1, OUTPUT);
  pinMode(CounterLEDRudaSilesia2, OUTPUT);
  pinMode(CounterLEDRudaSilesia3, OUTPUT);
  pinMode(CounterLEDRudaSilesia4, OUTPUT);
  pinMode(CounterLEDMikolow, OUTPUT);
  pinMode(CounterLEDGliwice, OUTPUT);
  pinMode(CounterLEDZabrze, OUTPUT);
  pinMode(CounterLEDLaziska, OUTPUT);
  pinMode(CounterLEDUnnamed, OUTPUT);
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
    blinkCounterLEDZabrze = 60;
    blinkCounterLEDUnnamed = 2000;
    digitalWrite(CounterLEDRudaSilesia2, HIGH);
    digitalWrite(CounterLEDRudaSilesia3, HIGH);
    digitalWrite(CounterLEDRudaSilesia4, HIGH);
    digitalWrite(CounterLEDMikolow, HIGH);
    digitalWrite(CounterLEDGliwice, HIGH);
    digitalWrite(CounterLEDLaziska, HIGH);
  } else {
    digitalWrite(coalMine4, LOW);
    digitalWrite(coalMine5, LOW);
    digitalWrite(coalMine6, LOW);
    digitalWrite(coalMine7, LOW);
    digitalWrite(coalMine8, LOW);
    digitalWrite(coalMine9, LOW);
    digitalWrite(coalMine10, LOW);
    digitalWrite(coalMine11, LOW);
    digitalWrite(coalMine12, LOW);
    digitalWrite(CounterLEDRudaSilesia1, LOW);
    digitalWrite(CounterLEDRudaSilesia2, LOW);
    digitalWrite(CounterLEDRudaSilesia3, LOW);
    digitalWrite(CounterLEDRudaSilesia4, LOW);
    digitalWrite(CounterLEDMikolow, LOW);
    digitalWrite(CounterLEDGliwice, LOW);
    digitalWrite(CounterLEDLaziska, LOW);
    digitalWrite(CounterLEDUnnamed, LOW);
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

    if (currentMillis - worktime6 >= workCoalMine6) {
      worktime6 = currentMillis;
      stateCoalMine6 = !stateCoalMine6;
      digitalWrite(coalMine6, stateCoalMine6);
    }

    if (currentMillis - worktime7 >= workCoalMine7) {
      worktime7= currentMillis;
      stateCoalMine7 = !stateCoalMine7;
      digitalWrite(coalMine7, stateCoalMine7);
    }

    if (currentMillis - worktime8 >= workCoalMine8) {
      worktime8 = currentMillis;
      stateCoalMine8 = !stateCoalMine8;
      digitalWrite(coalMine8, stateCoalMine8);
    }

    if (currentMillis - worktime9 >= workCoalMine9) {
      worktime9= currentMillis;
      stateCoalMine9 = !stateCoalMine9;
      digitalWrite(coalMine9, stateCoalMine9);
    }

    if (currentMillis - worktime10 >= workCoalMine10) {
      worktime10= currentMillis;
      stateCoalMine10 = !stateCoalMine10;
      digitalWrite(coalMine10, stateCoalMine10);
    }

    if (currentMillis - worktime11 >= workCoalMine11) {
      worktime11= currentMillis;
      stateCoalMine11 = !stateCoalMine11;
      digitalWrite(coalMine11, stateCoalMine11);
    }

    if (currentMillis - worktime12 >= workCoalMine12) {
      worktime12= currentMillis;
      stateCoalMine12 = !stateCoalMine12;
      digitalWrite(coalMine12, stateCoalMine12);
    }
}

void blinks()
{
  if (currentMillis - worktimeCounterLEDRudaSilesia1 >= blinkCounterLEDRudaSilesia1) {
      worktimeCounterLEDRudaSilesia1 = currentMillis;
      stateCounterLEDRudaSilesia1 = !stateCounterLEDRudaSilesia1;
      digitalWrite(CounterLEDRudaSilesia1, stateCounterLEDRudaSilesia1);
  }

  if (currentMillis - worktimeCounterLEDZabrze >= blinkCounterLEDZabrze) {
      worktimeCounterLEDZabrze = currentMillis;
      stateCounterLEDZabrze = !stateCounterLEDZabrze;
      digitalWrite(CounterLEDZabrze, stateCounterLEDZabrze);
  }

  if (currentMillis - worktimeCounterLEDUnnamed >= blinkCounterLEDUnnamed) {
      worktimeCounterLEDUnnamed = currentMillis;
      stateCounterLEDUnnamed = !stateCounterLEDUnnamed;
      digitalWrite(CounterLEDUnnamed, stateCounterLEDUnnamed);
  }
}
