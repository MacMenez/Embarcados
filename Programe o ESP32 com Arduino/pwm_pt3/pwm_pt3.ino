/*
Exemplo do uso do PWM com RGB
Descrição: Demonstra o uso da função PWM para gerar cores em RGB.


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

//Define números do GPIO para os LEDs RGB
const int redPin = LED_VERMELHO;
const int greenPin = LED_VERDE;
const int bluePin = LED_AZUL;

void setup() {
  pinMode(redPin, OUTPUT); //Configura o pino do LED vermelho como saída
  pinMode(greenPin, OUTPUT); //Configura o pino do LED verde como saída
  pinMode(bluePin, OUTPUT); //Configura o pino do LED azul como saída
}

void loop() {
  //Referência dos Códigos de Cores: https://www.rapidtables.com/web/color/RGB_Color.html
  setColor(255,0,0); //Vermelho
  delay(1000);

  setColor(0,255,0); //Verde
  delay(1000);

  setColor(0,0,255); //Azul
  delay(1000);

  setColor(255,255,0); //Amarelo
  delay(1000);

  setColor(0,255,255); //Ciano
  delay(1000);

  setColor(255,0,255); //Magenta
  delay(1000);

  setColor(128,0,128); //Roxo
  delay(1000);

  setColor(255,165,0); //Laranja
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue){
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}