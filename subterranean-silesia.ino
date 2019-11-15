#define Counter_LED_Katowice1 22
#define Counter_LED_Katowice2 23
#define Counter_LED_Katowice3 27
#define Counter_LED_Katowice4 26

#define switchKatowice 23
#define switchGOP1 27



void setup() {

  Serial.begin(115200);

  pinMode(switchKatowice, INPUT_PULLUP); //Katowice urban area
    pinMode(CounterLED1, OUTPUT);
      pinMode(coalMine1, OUTPUT);
      
    pinMode(CounterLED2, OUTPUT);
      pinMode(coalMine2, OUTPUT);
      
    pinMode(CounterLED3, OUTPUT);
      pinMode(coalMine3, OUTPUT);
      
    pinMode(CounterLED4, OUTPUT);
      pinMode(coalMine4, OUTPUT); //liquidation coal mine
      
  pinMode(switchGOP1, INPUT_PULLUP); //GOP first part (Upper Silesia Industrial Region I)
    pinMode(CounterLED5, OUTPUT);
      pinMode(coalMine5, OUTPUT);
      
    pinMode(CounterLED6, OUTPUT);
      pinMode(coalMine5, OUTPUT);
      
    pinMode(CounterLED7, OUTPUT);
      pinMode(coalMine7, OUTPUT);
      
  pinMode(switchGOP2, INPUT_PULLUP); // GOP second part (Upper Silesia Industrial Region II)
  pinMode(switchJCOP, INPUT_PULLUP); //Jaworzno-Chrzanow Industrial Region
  pinMode(switchROW, INPUT_PULLUP); // Rybnik Coal Area
  pinMode(switchBOP, INPUT_PULLUP); // Bielsko Industrial Region
}

void loop() {
  
  if(digitalRead(switchKatowice) == LOW) 
  { 
    digitalWrite(Counter_LED_Katowice1, HIGH);
    digitalWrite(Counter_LED_Katowice2, HIGH);
    digitalWrite(Counter_LED_Katowice3, HIGH);
    digitalWrite(Counter_LED_Katowice4, HIGH);
  } else if (digitalRead(switchKatowice) == HIGH) {
    digitalWrite(Counter_LED_Katowice1, LOW);
    digitalWrite(Counter_LED_Katowice2, LOW);
    digitalWrite(Counter_LED_Katowice3, LOW);
    digitalWrite(Counter_LED_Katowice4, LOW);
  }
}
