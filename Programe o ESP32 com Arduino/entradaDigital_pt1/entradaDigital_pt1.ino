/*
Exemplo de Entrada Digital
Descrição: Liga e Desliga um LED através de um botão
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
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  if(digitalRead(BOTAO_1) == LOW){
    digitalWrite(LED_VERMELHO, HIGH);
    Serial.println("Botão Pressionado!");
  }else{
    digitalWrite(LED_VERMELHO, LOW);
    Serial.println("Botão Solto!");
  }
  delay(200);
}
