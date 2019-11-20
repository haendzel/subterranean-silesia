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

#define CounterLEDJastrzebie3 31 //D1
  #define coalMine7 10

#define CounterLEDJastrzebie4 30 //E1
  #define coalMine8 11

#define CounterLEDRadlin 24 //E2
  #define coalMine9 12

#define CounterLEDKnurow 33 //F1
  #define coalMine10 45

#define CounterLEDOrmontowice 26 //F2
  #define coalMine11 46


//SWITCHES
#define switchROW 50
#define switchBOP 48
 
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

int stateCounterLEDJastrzebie2 = LOW;
unsigned long blinkCounterLEDJastrzebie2= 400;
unsigned long worktimeCounterLEDJastrzebie2 = 0;
 
unsigned long workCoalMine1 = 1000;
unsigned long workCoalMine2 = 1000;
unsigned long workCoalMine3 = 1000;
unsigned long workCoalMine4 = 1000;
unsigned long workCoalMine5 = 1000;
unsigned long workCoalMine6 = 1000;
unsigned long workCoalMine7 = 300;
unsigned long workCoalMine8 = 300;
unsigned long workCoalMine9 = 300;
unsigned long workCoalMine10 = 300;
unsigned long workCoalMine11 = 300;
 
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
 
void setup()
{
  Serial.begin(115200);

  Serial.write("Hush! Do you hear it? Something work undeground in Silesia."); 

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
  pinMode(CounterLEDCzechowiceDziedzice, OUTPUT);
  pinMode(CounterLEDRybnik1, OUTPUT);
  pinMode(CounterLEDRybnik2, OUTPUT);
  pinMode(CounterLEDPruszowice, OUTPUT);
  pinMode(CounterLEDJastrzebie1, OUTPUT);
  pinMode(CounterLEDJastrzebie2, OUTPUT);
  pinMode(CounterLEDJastrzebie3, OUTPUT);
  pinMode(CounterLEDJastrzebie4, OUTPUT);
  pinMode(CounterLEDRadlin, OUTPUT);
  pinMode(CounterLEDKnurow, OUTPUT);
  pinMode(CounterLEDOrmontowice, OUTPUT);
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
    digitalWrite(CounterLEDJastrzebie3, HIGH);
    digitalWrite(CounterLEDJastrzebie4, HIGH);
    digitalWrite(CounterLEDRadlin, HIGH);
    digitalWrite(CounterLEDKnurow, HIGH);
    digitalWrite(CounterLEDOrmontowice, HIGH);
  } else {
    digitalWrite(coalMine2, LOW);
    digitalWrite(coalMine3, LOW);
    digitalWrite(coalMine4, LOW);
    digitalWrite(coalMine5, LOW);
    digitalWrite(coalMine6, LOW);
    digitalWrite(coalMine7, LOW);
    digitalWrite(coalMine8, LOW);
    digitalWrite(coalMine9, LOW);
    digitalWrite(coalMine10, LOW);
    digitalWrite(CounterLEDJastrzebie1, LOW);
    digitalWrite(CounterLEDJastrzebie2, LOW);
    digitalWrite(CounterLEDJastrzebie3, LOW);
    digitalWrite(CounterLEDJastrzebie4, LOW);
    digitalWrite(CounterLEDRybnik1, LOW);
    digitalWrite(CounterLEDRybnik2, LOW);
    digitalWrite(CounterLEDPruszowice, LOW);
    digitalWrite(CounterLEDRadlin, LOW);
    digitalWrite(CounterLEDKnurow, LOW);
    digitalWrite(CounterLEDOrmontowice, LOW);
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

    if (currentMillis - worktime7 >= workCoalMine7) {
      worktime7 = currentMillis;
      stateCoalMine7 = !stateCoalMine7;
      digitalWrite(coalMine7, stateCoalMine7);
    }

    if (currentMillis - worktime8 >= workCoalMine8) {
      worktime8 = currentMillis;
      stateCoalMine8 = !stateCoalMine8;
      digitalWrite(coalMine8, stateCoalMine8);
    }

    if (currentMillis - worktime9 >= workCoalMine9) {
      worktime9 = currentMillis;
      stateCoalMine9 = !stateCoalMine9;
      digitalWrite(coalMine9, stateCoalMine9);
    }

    if (currentMillis - worktime10 >= workCoalMine10) {
      worktime10 = currentMillis;
      stateCoalMine10 = !stateCoalMine10;
      digitalWrite(coalMine10, stateCoalMine10);
    }

    if (currentMillis - worktime11 >= workCoalMine11) {
      worktime11 = currentMillis;
      stateCoalMine11 = !stateCoalMine11;
      digitalWrite(coalMine11, stateCoalMine11);
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
