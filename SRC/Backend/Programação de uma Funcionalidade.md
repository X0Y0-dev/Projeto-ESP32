# Funcionalidade 
O código pode possuir milhares de features incríveis e funcionalidades diferentes, mas seu procedimento principal será sempre este que liga e desliga a bomba de água. Este procedimento faz uma checagem do que o sensor de umidade do solo está captando, armazenando este valor em uma variável vazia e, com base no valor guardado, ele verifica se deve ou não ligar a bomba de água. Assim, apenas ligando somente quando necessário e evitando desperdício de água.



## Código comentado:
```cpp
int rele = 32;
int valor = 0;
int segundos = 0;



//o Coração do Código. Procedimento que checa a umidade do solo e com está informação decide se vai manter desligado ou liga-ra a bomba de água.
//abre procedimento que não retorna nada com os parametros sensor e rele.
void checar(int Sensor, int rele) {

// a int valor recebe o valor dado pelo sensor e imprime o valor no serial.
    int valor = analogRead(Sensor);
    Serial.println("valor Sensor");
    Serial.println(valor);
    // se estiver menor a umidez do solo que tal quantia ele fará algo com isto.  (defult:1500)
    if (valor < 3500) {
        // se a terra estiver seca deixa o rele passar a energia e liga a bomba.
        digitalWrite(rele, LOW);
        Serial.println("Bomba de Água Ligada!");
    } else {
        // se ela não estiver seca então trava o relé e trava a bomba de agua.
        digitalWrite(rele, HIGH);
        Serial.println("Bomba de Água Desligada!");
    }
}

void setup() {
//configura cada pino e liga o serial.
    pinMode(Sensor, INPUT);
    pinMode(rele, OUTPUT);
    Serial.begin(115200);
//inicia o rele travado
    digitalWrite(rele, HIGH);
}

void loop() 
 {
   //chama o procedimento com o sensor e o rele para fazer a checagem do estado atual do solo.
    checar(Sensor, rele);
    // caso o rele libere energia, então segundos serão 0
     if (digitalRead(rele) != HIGH)
    {
      segundos = 0;
    }     //caso contrário, aumenta os segundos com delay de 1000 ms
    else if(digitalRead(rele) != LOW){
      segundos++;
    }
    delay(1000);
 }
 
