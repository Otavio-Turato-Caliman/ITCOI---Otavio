const int led1 = 4;
const int led2 = 5;
const int echoPin = 2;
const int trigPin = 3;
const int buzzerPin = 6;
//Distancia limite
const int nThreeshold = 30;
//Armazenar a duracao da propagacao
unsigned long nDuration;
//Armazenar a distancia calculada
float nDistance;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  //Garante que o TRIG comece desligado
  digitalWrite(trigPin, LOW);
  
  Serial.begin(9600);
  Serial.println("Iniciando detector ultrassonico...");
}

void loop()
{
  //1.Envio de Pulso Ultrassonico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //2.Medicao do Tempo de Retorno
  nDuration = pulseIn(echoPin, HIGH, 30000);
  //3.Verificacao da Leitura
  if (nDuration == 0){
      digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    
    Serial.println("Sem leitura valida.");
    delay(200);
    return;
  }
  //4.Calculo da Distancia
  nDistance = nDuration * 0.0343 / 2;
  //5.Exibicao da Distancia
  Serial.println("Distancia: ");
  Serial.println(nDistance, 1);
  Serial.println(" cm");
  //6.Verificar se a Distancia menor que 30cm
  if (nDistance < nThreeshold)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzerPin, 2000);
    delay(400);
    noTone(buzzerPin);
  }
  //7.Distancia for igual ou maior 30cm
  else
  {
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(300);
  }
}
