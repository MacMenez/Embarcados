/*
Exemplo de Entrada Digital com Interrupção
Descrição: Realiza a leitura de uma entrada digital conectada a um LED
e inverte o estado do LED coreespondente.

Objetivo: Demosrar o uso da entrada digital como rotina de debounce
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
#define BUZZER 17 //Pino do buzzer

const int buttonPin = BOTAO_1;
const int pulseInputPin = BOTAO_2;
const int ledPin = LED_VERMELHO;
int ledstate = 0;
int pulseCont = 0;
unsigned long lastDebounceTime = 0;

void buttonInterrupt(){
  if(millis()-lastDebounceTime >= 100){
    ledstate = !ledstate;
    digitalWrite(ledPin, ledstate);
  }
  lastDebounceTime = millis();
}

void pulseInterrupt(){
  pulseCont++;
  Serial.println(pulseCont);
}

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pulseInputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(21, OUTPUT);

  attachInterrupt(buttonPin, buttonInterrupt, FALLING); //Pressiona o botão acende
  //attachInterrupt(buttonPin, buttonInterrupt, RISING); //Pressiona ao soltar o botão apaga
  //attachInterrupt(buttonPin, buttonInterrupt, CHANGE); //Pressiona o botão acende e ao soltar ele apaga
  attachInterrupt(pulseInputPin, pulseInterrupt, FALLING);
}

void loop() {
  digitalWrite(21, HIGH);
  delay(500);
  digitalWrite(21, LOW);
  delay(500);
}