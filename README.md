# 黒ひげ危機一髪

電子回路設計の授業で作りました。

## 使用した部品

| 名称 | 備考 |
| ------------- | ------------- |
| 自己保持ソレノイド  | CD07300240  |
| タクトスイッチ  | 赤、緑、黄  |
| LED  | 赤、緑、黄  |
| 抵抗  | 240Ω  |

## 回路図

<a href="https://github.com/rikumomo0407/kurohige//raw/main/circuit.png">
  <img width="100%" src="https://github.com/rikumomo0407/kurohige//raw/main/circuit.png" />
</a>

<a href="https://github.com/rikumomo0407/kurohige//raw/main/circuit.png">
  <img width="20%" src="https://github.com/rikumomo0407/kurohige//raw/main/image.png" />
</a>

*上の素子は自己保持ソレノイドを表している。また、抵抗はすべて240[Ω]。

## プログラム

```
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
```

## 動作原理

<a href="https://github.com/rikumomo0407/kurohige//raw/main/flowchart.png">
  <img width="100%" src="https://github.com/rikumomo0407/kurohige//raw/main/flowchart.png" />
</a>

## 動作結果

・下の写真のようにブレッドボード上に作成したところ、正常に動作した。また自己保持ソレノイドの到着が間に合わなかったためLEDライトで代用した。一番上の黄のLEDライトが光ったときソレノイドが黒ひげ人形を飛ばしたことを示している。白いタクトスイッチはリセット用のスイッチでArduinoのリセットピンにつなげている。

<a href="https://github.com/rikumomo0407/kurohige//raw/main/picture.png">
  <img width="100%" src="https://github.com/rikumomo0407/kurohige//raw/main/picture.png" />
</a>
