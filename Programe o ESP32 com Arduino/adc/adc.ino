/*
Exemplo de leitura do ADC do ESP32
Descrição: Leitura do ADC do ESP32 e impressão o valor lido no monitor serial


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

void setup() {
  Serial.begin(115200); //Inicia a Serial para impressão dos valores lidos
  analogReadResolution(12); //Configurando a faixa de 12 bits
  //analogSetAttenuation(adc_attenuation_t::ADC_2_5db);
}

void loop() {
  int analogValue = analogRead(2);
  int analogVolts = analogReadMilliVolts(2);

  //Imprime os valores de leitura
  Serial.printf("ADC Valor Analógico: %d\n", analogValue);
  Serial.printf("ADC Valor em Milivolts: %d\n", analogVolts);

  delay(100);
}