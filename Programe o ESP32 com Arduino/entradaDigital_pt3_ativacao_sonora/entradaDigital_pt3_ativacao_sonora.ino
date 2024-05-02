/*
Exemplo de Entrada Digital 2
Descrição: Ao realizar uma leitura o debounce será feito, ou seja, o valor será invertido. Será utilizado 3 botões.
Objetivo: Demosntrar o uso de entrada digital com rotina de debounce

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

const int debounceTime = 50; //milissegundos

const int buttonPin [] = {BOTAO_1, BOTAO_2, BOTAO_3}; //Pinos do Botão 1, Botão 2, Botão 3
const int ledPin[] = {LED_VERMELHO, LED_VERDE, LED_AZUL}; //Pinos LEDs Vermelho, Verde, Azul

unsigned long  debounceDelay = 50; //Atraso para evitar o efeito debounce
unsigned long lastDebounceTime[] = {0, 0, 0}; //Último tempo para cada botão


int buttonState[] = {HIGH, HIGH, HIGH}; //Estado atual de cada botão
int lastButtonState[] = {HIGH, HIGH, HIGH}; //Último estado de cada botão
int ledState[] = {LOW, LOW, LOW}; //Estado atual de cada LED


void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < sizeof(buttonPin) / sizeof(buttonPin[0]); i++) {
    pinMode(buttonPin[i], INPUT_PULLUP); //Configura os botões como entrada
    pinMode(ledPin[i], OUTPUT); //Configura os LEDs como saída
  }
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  for(int i = 0; i < sizeof(buttonPin) / sizeof(buttonPin[0]); i++){ //Para cada botão
    int reading = digitalRead(buttonPin[i]); //Lê o estado do botão

    if(reading != lastButtonState[i]){ //Verifica se houve troca de valor
      lastDebounceTime[i] = millis(); //Atualiza o tempo de debounce
    }

    if ((millis() - lastDebounceTime[i]) > debounceTime){ //Verifica se o tempo de debounce passou
      if(reading != buttonState[i]){ //Verifica se o estado do botão mudou
        buttonState[i] = reading; //Atualiza o estado do botão com a leitura, informando se houve ou não o pressionamento do botão

        if(buttonState[i] == LOW){ //Verifica se o botão foi pressionado
          beep();
          ledState[i] = !ledState[i]; //inverte o valor do LED,ligado vira desligado e vice-versa
          digitalWrite(ledPin[i], ledState[i]); //Atualiza o estado do LED
        }
      }
    }
    lastButtonState[i] = reading; //Atualiza o último estado do botão
  }
}


void beep(){
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}