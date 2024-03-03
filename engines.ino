/*
  Vitaliy Polyakov (C), polyakov.vs@mail.ru, 2024.

  Программа управления двумя двигателями.

  Пины, на которых можно запустить ШИМ сигнал (PWM) стандартными
  средствами Arduino Nan: D11, D10, D9, D6, D5, D3.

*/

// левый двигатель (MOTOR A)
#define ENGINE_LEFT_IN 2    // IN1, пин D2 (отвечает за направление: вперед - 0, назад - 1)
#define ENGINE_LEFT_PWM 3   // IN2, пин D3 (отвечает за скорость вращения: ШИМ (PWM) - 0...255)

// правый двигатель (MOTOR B)
#define ENGINE_RIGHT_IN 4   // IN3, пин D4 (отвечает за направление: вперед - 0, назад - 1)
#define ENGINE_RIGHT_PWM 5  // IN4, пин D5 (отвечает за скорость вращения: ШИМ (PWM) - 0...255)

void setup() {
  Serial.begin(9600);

  // левый двигатель
  pinMode(ENGINE_LEFT_IN, OUTPUT);    // режим работы пина, выход
  pinMode(ENGINE_LEFT_PWM, OUTPUT);   // режим работы пина, выход
  // правый двигатель
  pinMode(ENGINE_RIGHT_IN, OUTPUT);   // режим работы пина, выход
  pinMode(ENGINE_RIGHT_PWM, OUTPUT);  // режим работы пина, выход      
}

void loop() {
  // скорость вращения двигателей
  int lSpeed = 1023; // значение 512 (50% от диапазона 0...1023)
  int rSpeed = 1023; // значение 512 (50% от диапазона 0...1023)

  // направление вращения
  int lDirection = 0;
  int rDirection = 0;

  // преобразование значения из диапазона 0...1023 в диапазон 0...255
  lSpeed = map(lSpeed, 0, 1023, 0, 255);
  rSpeed = map(rSpeed, 0, 1023, 0, 255);

  Serial.print("lSpeed = ");
  Serial.print(lSpeed);
  Serial.print("\t");

  Serial.print("rSpeed = ");
  Serial.print(rSpeed);
  Serial.print("\n");

  // включение левого двигателя
  digitalWrite(ENGINE_LEFT_IN, lDirection);
  analogWrite(ENGINE_LEFT_PWM, lSpeed);

  // включение правого двигателя
  digitalWrite(ENGINE_RIGHT_IN, rDirection);
  analogWrite(ENGINE_RIGHT_PWM, rSpeed);  
}