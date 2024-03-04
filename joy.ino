#define JOY_PIN_VRX 4  // пин A4
#define JOY_PIN_VRY 5  // пин A5
#define JOY_PIN_SW 12  // пин D12

// "мёртвая зона" джойстика
#define JOY_DEADZONE 25 // 511 +/- 25

int joyMiddleX;
int joyMiddleY;

void setup() {
  Serial.begin(9600);

  pinMode(JOY_PIN_VRX, INPUT);
  pinMode(JOY_PIN_VRY, INPUT);
  pinMode(JOY_PIN_SW, INPUT_PULLUP);

  // калибруем ноль джойстика при запуске
  // у китайских он бывает диапазоне 400-600
  joyMiddleX = analogRead(JOY_PIN_VRX);
  joyMiddleY = analogRead(JOY_PIN_VRY);
}

void loop() {
  Serial.print("X middle = ");
  Serial.print(joyMiddleX);
  Serial.print("\t");

  Serial.print("Y middle = ");
  Serial.print(joyMiddleY);
  Serial.print("\t");  

  Serial.print("x = ");
  Serial.print(analogRead(JOY_PIN_VRX));
  Serial.print("\t");  

  Serial.print("y = ");
  Serial.print(analogRead(JOY_PIN_VRY));
  Serial.print("\t");      

  if (!digitalRead(JOY_PIN_SW))
    Serial.print("Button: YES");
  else
    Serial.print("Button: NO");

  Serial.print("\n");
}
