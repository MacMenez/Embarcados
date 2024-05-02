/*
Exemplo de leitura do DAC do ESP32
Descrição: Leitura do DAC do ESP32 e impressão o valor lido no osciloscópio

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

void setup() {}

void loop() {
  //Verificar no osciloscópio

  /*
    for (int i = 0; i < 255; i++) {
      dacWrite(17, i);
      delay(1);
    }
  */
  //dacWrite(17, 127);
  dacWrite(17, 63);
}