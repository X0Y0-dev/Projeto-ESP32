# Diagrama Funcionamento do Sistema.

## PowerBanK

<p align="center">
    <img src="https://github.com/user-attachments/assets/7493dc4a-1b89-4c55-8a3d-a7ae3d29cea0" alt="Imagem do computador" width="800" />
</p>
<br> O PowerBank ou outra fonte de energia deve energizar o ESP32 com 5V.<br>


## Sensor de Umidade. Ligue!

<p align="center">
    <img src="https://github.com/user-attachments/assets/be04140d-9e5a-4c85-8b87-e5f651b6486d" alt="Imagem do computador" width="800" />
</p>

Com o ESP energizado, ele fornecerá energia ao Sensor de umidade de solo e a partir disto, o sensor de umidade retornará valores pela porta 33 usando este código.
```cpp

int Sensor = 33;
int valor = 0;

void checar(int Sensor, int rele) {
    int valor = analogRead(Sensor);
    Serial.println("valor Sensor");
    Serial.println(valor);
}

void setup() {
    pinMode(Sensor, INPUT);
    Serial.begin(9600);
}

void loop() 
 {
    checar(Sensor, rele);
    delay(1000);
 }


```
<br><br>
## Conexão relé
<p align="center">
    <img src="https://github.com/user-attachments/assets/8a58f42c-e201-44e1-acd0-bbdc816d0e03" alt="Imagem do computador" width="900" />
</p>

<br>O ESP32 fornece 3.3 V para o Relé operar e tambem oferece 5V para o a saída do relé.<br>
<br>Com base nos dados do Sensor de umidade de solo, o Esp32 decidira de deve permitir a passagem de energia do relé ou se deve barrar a passagem de energia pela porta 32 usando este código<br>

```cpp
int Sensor = 33;
int valor = 0;
int rele = 32;

void checar(int Sensor, int rele) {
    int valor = analogRead(Sensor);
    Serial.println("valor Sensor");
    Serial.println(valor);
    // se estiver menor a umidez do solo que tal quantia defult:1500
    if (valor < 3500) {
        // se a terra estiver seca
        digitalWrite(rele, LOW);
        Serial.println("Permitir passagem");
    } else {
        // se ela não estiver seca
        digitalWrite(rele, HIGH);
        Serial.println("Barrar passagem");
    }
}

void loop() 
 {
    checar(Sensor, rele);
    delay(1000);
 }


```
## Ligar Bomba!

![completo](https://github.com/user-attachments/assets/e7d06e68-cde2-4d0a-8932-7a195a178bc4)

<br>o relé é a parte crucial para que possamos decidir quando manter a bomba D'água ligada e quando devemos manter desligado.

<br>O ESP32 em base nos valores recebidos pelo Sensor de umidade com a programação, decide se o Relé deve permitir a passagem de 5V para a bomba d'agua ou não. 
<br>Enquanto estiver permitindo a passagem de energia, estará entregando água, caso contrario, a bomba estará desligada.
<br><br>

```cpp

int Sensor = 33;
int valor = 0;
int rele = 32;

void checar(int Sensor, int rele) {
    int valor = analogRead(Sensor);
    Serial.println("valor Sensor");
    Serial.println(valor);
    // se estiver menor a umidez do solo que tal quantia defult:1500
    if (valor < 3500) {
        // se a terra estiver seca
        digitalWrite(rele, LOW);
        Serial.println("Desligar Bomba d'água");
    } else {
        // se ela não estiver seca
        digitalWrite(rele, HIGH);
        Serial.println("Desligar Bomba d'água");
    }
}

void loop() 
 {
    checar(Sensor, rele);
    delay(1000);
 }

```
