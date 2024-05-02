/*
Exemplo do uso do PWM com a função analogWrite
Descrição: Demonstra o uso da função analogWrite para controlar o brilho de um LED.


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

#define PWM_RESOLUTION 10 //Resolução padrão é 8 (visível no Osciloscópio)
#define PWM_MAX_VALUE 1023 //2^10 - 1 = 1023
#define PWM_FREQ 5000 //5KHz - controla a frequencia

const int ledPin = LED_VERMELHO; //Pino LED
int brightness = 0; //Valor de intensidade do brilho
int fadeAmount = 5; //Valor do incremento

void setup() {
  pinMode(ledPin, OUTPUT); //Define LED como saída
  analogWriteFrequency(PWM_FREQ);
  analogWriteResolution(PWM_RESOLUTION);
}

void loop() {
  //analogWrite(ledPin, 128); //128 = 50%
  //analogWrite(ledPin, 64);

  //Variar de 0% até 100% e de 100% até 0%
  analogWrite(ledPin, brightness);

  brightness = brightness + fadeAmount;

  if (brightness >= PWM_MAX_VALUE || brightness <= 0) {
    fadeAmount =- fadeAmount;
  }

  delay(30);
}