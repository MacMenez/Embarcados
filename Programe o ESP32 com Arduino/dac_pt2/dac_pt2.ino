/*
Exemplo geração de senoide com DAC
Descrição: Exemplo exibe como usar o DAC para gerar uma onda senoidal

Autor: Davi C. Menez
*/

int Sine[256]; //Vetor para senoide
float Period = (2*PI)/256;
float angle_rad;

void setup() {
  for (int i = 0; i < 256; i++) {
    angle_rad = i * Period; //Para cada ponto calcula o ângulo em radianos
    Sine[i] = (sin(angle_rad)*127) + 128; //Matemática para calcular a senoide
  }
}

void loop() {
  for (int i = 0; i < 256; i++) {
    dacWrite(17, Sine[i]);
  }
}