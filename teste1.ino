// X e Y vao ser ligados a portas analogicas.

// Selecionando o pino de entrada do joystick em relação ao eixo Y, é o A0.
int pinInputY = 0;

// Selecionando o pino de entrada do joystick em relação ao eixo X, é o A1.
int pinInputX = 1;

// Os valores superiores e inferiores de X e Y forem escolhidos analizando os resultados do Serial.println(); 
// Os leds indicaram para onde X e Y estaram apertados. Ha 4 leds, um para cada direcao, dois para X, esqueda e direita e dois para Y, cima e baixo.
int ledYCima = 9;          // Para valores de Y menores do que 200 esse led acende, a mesma ideia se aplica aos outros.
int ledYBaixo = 12;         // Y >= 700.
int ledXEsquerda = 10;     // X <= 200.
int ledXDireita = 11;      // X >= 500.

void setup() {
  // Para verificar os valores de X e Y pelo serial olhando no PC, o serial ser setado.
  Serial.begin(9600);
  
  // Setando os pinos
  pinMode(ledYCima, OUTPUT);
  pinMode(ledYBaixo, OUTPUT);
  pinMode(ledXEsquerda, OUTPUT);
  pinMode(ledXDireita, OUTPUT);
}

void loop() {
  // Lendo os valores de X e Y.
  int valY = analogRead(pinInputY);
  int valX = analogRead(pinInputX);
  
  if(valY <= 200) {
     digitalWrite(ledYCima, HIGH);
     digitalWrite(ledYBaixo, LOW);
  }  else  {
    digitalWrite(ledYCima, LOW);
  }
  
  if(valY >= 700) {
     digitalWrite(ledYBaixo, HIGH);
     digitalWrite(ledYCima, LOW);
  }  else  {
    digitalWrite(ledYBaixo, LOW);
  }
  
  
  if(valX <= 200) {
     digitalWrite(ledXEsquerda, HIGH);
     digitalWrite(ledXDireita, LOW); 
  }  else  {
    digitalWrite(ledXEsquerda, LOW);
  }
  
  if(valX >= 500) {
     digitalWrite(ledXDireita, HIGH);
     digitalWrite(ledXEsquerda, LOW);
  }  else  {
    digitalWrite(ledXDireita, LOW);
  }
  
  Serial.print("O valor de Y eh: ");
  Serial.println(valY);
  Serial.print("O valor de X eh: ");
  Serial.println(valX);
  delay(50);
}