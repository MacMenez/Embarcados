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

const int debounceTime = 50; //milissegundos
const int buttonPin = BOTAO_1; //Pino do botão 1
// const int ledPin = LED_VERMELHO; //Pino LED Vermelho
// const int ledPin = LED_VERDE; //Pino LED Vermelho
const int ledPin = LED_AZUL; //Pino LED Vermelho

unsigned long lastDebounceTime = 0;
int buttonState = HIGH; //Começa em HIGH por causa do PULLUP, se não for PULLUP inverte
int lastButtonState = HIGH; //Começa em HIGH por causa do PULLUP, se não for PULLUP inverte
int ledState = LOW;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  //Verifica se houve troca de valor
  if(reading != lastButtonState){
    lastDebounceTime = millis(); //Identifica o tempo em que a mudança ocorreu
  }

  if ((millis() - lastDebounceTime) > debounceTime){ //Verifica se passou 50 milissegundos
    if(reading != buttonState){
      buttonState = reading; //Atualiza o estado do botão com a leitura, informando se houve ou não o pressionamento do botão

      //Quando o botão for pressionado, inverte o valor do LED,ligado vira desligado e vice-versa
      if(buttonState == LOW){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        count++;
        Serial.println(count);
      }
    }
  }
  lastButtonState = reading;
}
