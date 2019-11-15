#define coalMine1 3
#define coalMine2 6
#define coalMine4 9
#define coalMine3 10

#define CounterLEDKatowice1 22
#define CounterLEDKatowice2 27
#define CounterLEDKatowice3 25
#define CounterLEDKatowice4 26
#define CounterLEDSosnowiec 24
#define CounterLEDPiekary 28
#define CounterLEDBytom1 29
#define CounterLEDBytom2 31

#define switchKatowice 23
#define switchGOP1 30
 
int stateCoalMine1 = LOW;
int stateCoalMine2 = LOW;
int stateCoalMine3 = LOW;
int stateCoalMine4 = LOW;
 
unsigned long workCoalMine1 = 500;
unsigned long workCoalMine2 = 100;
unsigned long workCoalMine3 = 400;
unsigned long workCoalMine4 = 700;
 
unsigned long currentMillis = 0;
unsigned long worktimeKatowice1 = 0;
unsigned long worktimeKatowice2 = 0;
unsigned long worktimeKatowice3 = 0;
unsigned long worktimeKatowice4 = 0;
 
void setup(){
  Serial.begin(9600);
  pinMode(coalMine1, OUTPUT);
  pinMode(coalMine2, OUTPUT);
  pinMode(coalMine3, OUTPUT);
  pinMode(coalMine4, OUTPUT);
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
 
void loop(){
  
  currentMillis = millis();
 
  if (digitalRead(switchKatowice) == LOW) {
    workCoalMine1 = 500;
    workCoalMine2 = 100;
    workCoalMine3 = 400;
    workCoalMine4 = 700;
    digitalWrite(CounterLEDKatowice1, HIGH);
    digitalWrite(CounterLEDKatowice2, HIGH);
    digitalWrite(CounterLEDKatowice3, HIGH);
    digitalWrite(CounterLEDKatowice4, HIGH);
  } else {
    digitalWrite(coalMine1, LOW);
    digitalWrite(coalMine2, LOW);
    digitalWrite(coalMine3, LOW);
    digitalWrite(coalMine4, LOW);
    digitalWrite(CounterLEDKatowice1, LOW);
    digitalWrite(CounterLEDKatowice2, LOW);
    digitalWrite(CounterLEDKatowice3, LOW);
    digitalWrite(CounterLEDKatowice4, LOW);
  }

  if (digitalRead(switchGOP1) == LOW) {
    digitalWrite(CounterLEDSosnowiec, HIGH);
    digitalWrite(CounterLEDPiekary, HIGH);
    digitalWrite(CounterLEDBytom1, HIGH);
    digitalWrite(CounterLEDBytom2, HIGH);
  } else {
    digitalWrite(CounterLEDSosnowiec, LOW);
    digitalWrite(CounterLEDPiekary, LOW);
    digitalWrite(CounterLEDBytom1, LOW);
    digitalWrite(CounterLEDBytom2, LOW);
  }
  
    if (currentMillis - worktimeKatowice1 >= workCoalMine1) {
      worktimeKatowice1 = currentMillis;
      stateCoalMine1 = !stateCoalMine1;
      digitalWrite(coalMine1, stateCoalMine1);
    }
   
    if (currentMillis - worktimeKatowice2 >= workCoalMine2) {
      worktimeKatowice2 = currentMillis;
      stateCoalMine2 = !stateCoalMine2;
      digitalWrite(coalMine2, stateCoalMine2);
    }
    if (currentMillis - worktimeKatowice3 >= workCoalMine3) {
      worktimeKatowice3 = currentMillis;
      stateCoalMine3 = !stateCoalMine3;
      digitalWrite(coalMine3, stateCoalMine3);
    }
}