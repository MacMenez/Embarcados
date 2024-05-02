/*
Exemplo de Saída Digital
Descrição: Liga e Desliga um LED a cada segundo.
Objetivo: Estudar saídas digitais

Autor: Davi C. Menez
*/
#define LED_VERMELHO 14 //const int ledPin = 14; //LED Vermelho
#define LED_VERDE 13 //const int ledPin = 13; //LED Verde
#define LED_AZUL 12 //const int ledPin = 12; //LED Azul

#define TEMPO 1000

const int ledPin = LED_VERMELHO;

void setup() {
  // put your setup code here, to run once:
  
  //pinMode(14, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(TEMPO);
  digitalWrite(ledPin, LOW);
  delay(TEMPO);
}
