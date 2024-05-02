/*
Exemplo de Entrada Digital
Descrição: Liga e Desliga um LEDs através dos botões disponíveis
Objetivo: Estudar entradas digitais

Autor: Davi C. Menez
*/

//Mapa dos Pinos
#define LED_VERMELHO 14 //LED Vermelho
#define LED_VERDE 13 //LED Verde
#define LED_AZUL 12 //LED Azul
#define BOTAO_1 7 //Pino de conexão do botão 1
#define BOTAO_2 6 //Pino de conexão do botão 2
#define BOTAO_3 5 //Pino de conexão do botão 3
#define BOTAO_4 4 //Pino de conexão do botão 4
#define BOTAO_5 3 //Pino de conexão do botão 5
#define BOTAO_6 2 //Pino de conexão do botão 6

void setup() {
  Serial.begin(9600);
  //pinMode(BOTAO_1, INPUT);
  pinMode(BOTAO_1, INPUT_PULLUP);
  pinMode(BOTAO_2, INPUT_PULLUP);
  pinMode(BOTAO_3, INPUT_PULLUP);
  pinMode(BOTAO_4, INPUT_PULLUP);
  pinMode(BOTAO_5, INPUT_PULLUP);
  pinMode(BOTAO_6, INPUT_PULLUP);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void loop() {
  if(digitalRead(BOTAO_1) == LOW){
    digitalWrite(LED_VERMELHO, HIGH);
    Serial.println("Botão Vermelho Pressionado!");
  }else if(digitalRead(BOTAO_2) == LOW){
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("Botão Verde Pressionado!");
  }else if(digitalRead(BOTAO_3) == LOW){
    digitalWrite(LED_AZUL, HIGH);
    Serial.println("Botão Azul Pressionado!");
  }else if(digitalRead(BOTAO_4) == LOW){
    Serial.println("Botão 4 Pressionado!");
  }else if(digitalRead(BOTAO_5) == LOW){
    Serial.println("Botão 5 Pressionado!");
  }else if(digitalRead(BOTAO_6) == LOW){
    Serial.println("Botão 6 Pressionado!");
  }else{
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);

    Serial.println("Botão Solto!");
  }
  delay(200);
}
