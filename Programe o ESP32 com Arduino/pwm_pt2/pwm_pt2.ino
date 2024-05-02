/*
Exemplo do uso do PWM com LEDC
Descrição: Demonstra o uso da função LEDC para controlar o brilho de um LED.


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

#define LEDC_CHANNEL 0
#define LEDC_FREQ 5000 //1000 = 1KHz
#define LEDC_RESOLUTION 12 //8 Bits é o padrão
#define PWM_MAX_VALUE 4095 //Moudou para 12, logo 2^12 - 1 = 4095 | 2^8 - 1 = 255

const int ledPin = LED_VERMELHO;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcSetup(LEDC_CHANNEL, LEDC_FREQ, LEDC_RESOLUTION);
  ledcAttachPin(ledPin, LEDC_CHANNEL);
}

void loop() {
  ledcWrite(LEDC_CHANNEL, brightness);

  brightness += fadeAmount;

  if (brightness <=0 || brightness >= PWM_MAX_VALUE) {
    fadeAmount =- fadeAmount;
  }
  delay(30);
}