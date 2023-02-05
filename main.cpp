int i;
int hit;
int pins[18][2] = {{3,22},{4,23},{5,24},{6,25},{7,26},{8,27},{9,28},{10,29},{11,30},{12,31},{13,32},{41,33},{42,34},{43,35},{44,36},{45,37},{46,38},{47,39}};
int output = 48;
int size = 18;

void setup() {
  for (i = 0; i < size; i++){
    pinMode(pins[i][0], INPUT_PULLUP);
    pinMode(pins[i][1], OUTPUT);
    digitalWrite(pins[i][1], HIGH);
  }
  pinMode(output, OUTPUT);
  digitalWrite(output, HIGH);
  randomSeed(analogRead(0));
  hit = random(size);
}

void loop() {
  if (digitalRead(pins[hit][0]) == LOW) {
    digitalWrite(pins[hit][1], LOW);
    digitalWrite(output, LOW);
    while(1){
      for (i = 0; i < size; i++){
        digitalWrite(pins[i][1], HIGH);
      }
      delay(250);
      for (i = 0; i < size; i++){
         digitalWrite(pins[i][1], LOW);
      }
      delay(250);
    }
  }
  else{
      for (i = 0; i < size; i++){
        if (digitalRead(pins[i][0]) == LOW){
          digitalWrite(pins[i][1], LOW);
        }
      }
  }
}
