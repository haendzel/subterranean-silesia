#define CounterLED1 22
#define CounterLED2 24
#define CounterLED3 25
#define CounterLED4 26

#define Switch1 23 //katowice
#define Switch 27 //


void setup() {
 {
  Serial.begin(115200);
  blinkStartMillis = millis();  
  fadeStartMillis = millis();
}
  pinMode(switchKatowice, INPUT_PULLUP); //Katowice urban area
    pinMode(CounterLED1, OUTPUT);
      pinMode(coalMine1, OUTPUT);
      
    pinMode(CounterLED2, OUTPUT);
      pinMode(coalMine2, OUTPUT);
      
    pinMode(CounterLED3, OUTPUT);
      pinMode(coalMine3, OUTPUT);
      
    pinMode(CounterLED4, OUTPUT);
      pinMode(coalMine4, OUTPUT); //liquidation
      
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
  
  currentMillis = millis();  //get the current time
  blink();
  fade();
  
  if(digitalRead(Switch1) == LOW) //jesli wlaczymy Katowice
  { 
    digitalWrite(CounterLED1, HIGH);
    digitalWrite(CounterLED2, HIGH);
    digitalWrite(CounterLED3, HIGH);
    digitalWrite(CounterLED4, HIGH);
  } else if (digitalRead(Switch1) == HIGH) {
    digitalWrite(CounterLED1, LOW);
    digitalWrite(CounterLED2, LOW);
    digitalWrite(CounterLED3, LOW);
    digitalWrite(CounterLED4, LOW);
  }
}
