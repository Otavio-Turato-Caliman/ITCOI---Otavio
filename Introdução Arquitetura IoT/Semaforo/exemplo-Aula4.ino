void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);

  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);

  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(6, LOW);
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(7, HIGH);
    delay(300);
    digitalWrite(7, LOW);
    delay(300);
  }
  digitalWrite(8, LOW);
}
