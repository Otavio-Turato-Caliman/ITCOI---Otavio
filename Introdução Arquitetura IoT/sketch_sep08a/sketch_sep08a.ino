int led = 7;
int botaoLiga = 8;
int botaoDesl = 10;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botaoLiga, INPUT_PULLUP);
  pinMode(botaoDesl, INPUT_PULLUP);
  digitalWrite(led, LOW); 
}
void loop() {
  int valorLiga = digitalRead(botaoLiga);
  int valorDesl = digitalRead(botaoDesl);
  if (valorLiga == LOW) {
    digitalWrite(led, HIGH);
  }
  if (valorDesl == LOW) {
    digitalWrite(led, LOW);
  }
}
