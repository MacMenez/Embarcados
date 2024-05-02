/*
Exemplo de Entrada Digital 2
Descrição: Ao realizar uma leitura o debounce será feito, ou seja, o valor será invertido.
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

const int buttonPin = BOTAO_1; //Pino do botão 1
const int ledPin = LED_VERMELHO; //Pino LED Vermelho

int count;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(100); //O atraso fica preso no código, não funciona para bounce
    count++;
    Serial.println(count);

    while (digitalRead(buttonPin) == LOW);
  }
}
