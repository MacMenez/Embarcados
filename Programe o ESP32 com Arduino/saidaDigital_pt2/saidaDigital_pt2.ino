/*
Exemplo de Saída Digital
Descrição: Liga e Desliga um LED a cada segundo.
Objetivo: Estudar saídas digitais

Autor: Davi C. Menez
*/
#define LED_VERMELHO 14 //const int ledPin = 14; //LED Vermelho
#define LED_VERDE 13 //const int ledPin = 13; //LED Verde
#define LED_AZUL 12 //const int ledPin = 12; //LED Azul

#define TEMPO 1000 //Tempo de delay

//Define o GPIO conectado no LED
const int ledPin[] = {LED_VERMELHO, LED_VERDE, LED_AZUL}; //Troque para o número do seu pino GPIO

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++){
    pinMode(ledPin[i], OUTPUT); //Configura o pino como saída
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++){
    digitalWrite(ledPin[i], HIGH); //Desliga o LED
    delay(TEMPO); //Espera 1 segundo
    digitalWrite(ledPin[i], LOW); //Desliga o LED
  }
  
}
