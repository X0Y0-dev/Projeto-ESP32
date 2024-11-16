<h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/f3190e24-ea81-416e-bf35-23342fa26526" alt="Imagem do computador" width="400" />
</p>
</h1>

No esquemático base do projeto, foi adicionado unicamente o Sensor de Umidade de Solo. Neste caso, o sensor será responsável por coletar dados do solo em que se encontre e enviar para o Arduino ESP32 por meio do comparador, que será responsável por filtrar quais dados são uteis ou não com base nas especificações do cósigo. Após a leitura e analise de informações, os dados serão exibidos no Monitor Serial, que podem ser de 0 (terra extremamente seca) ou 4095 (terra estremamente molhada).
Neste cenário, o Sensor de Umidade de Solo está conectado à entrada D34, uma porta tanto analógica quanto digital (neste caso, uma entrada analógica), e será através desta porta em que poderemos declará-lo em nosso código. O sensor está acoplado a um M393 Comparator Module - ADIY pelos pinos de energia positiva e negativa. No comparador, o pino OUT (cabo marrom) está se conectando à porta do arduino. O pino VCC (cabo vermelho) está sendo alimentado com 3.3v de energia positiva, e o pino GND (cabo preto) está sendo alimentado com energia negativa.

## Código do Sensor
```CPP
int Sensor = 32;

void checar(int Sensor)
{
    int valor = analogRead(Sensor);
    Serial.print("valor Sensor");
    Serial.print(": ");
    Serial.println(valor);
}


void setup() {
    pinMode(Sensor, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    Serial.println(valor);
    checar(Sensor);
    delay(1000);
}
```
