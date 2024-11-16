##
# Código Teste do Sensor
<br>Em um exame em que se esperava que o valor entregue pelo sensor fosse abaixo de 2800 e acima de 2900, a quantidade de vezes do ocorrido em 100 testes foi de 0 para 100. Já em um teste de precisão mais rígida, em que o valor abaixo de 2820 e acima de 2870 fossem considerados imprecisos, apenas ocorreram 9 em 100 casos.<br>
<br>O primeiro teste de precisão, menos rígido, obteve um resultado de precisão de 100%. Já o segundo teste, de precisão mais rígido, obteve um resultado de precisão de 99,91%.<br>
<br>Usando o seguinte código, é possivel fazer o mesmo teste de acurácia.<br>

```cpp
int Sensor = 33;
int valor = 0;
int resultado = 0;
int i = 0;


void setup() {
    pinMode(Sensor, INPUT);
    Serial.begin(9600);
void loop() {
  if (i < 100) {
    i++;
    valor = analogRead(Sensor);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(valor);
    resultado = resultado + valor;
    delay(10);
  }
  else if (i == 100)
  {
  Serial.print("total");
   Serial.print(": ");
   Serial.println(resultado);
   resultado = resultado / 100;
   Serial.print("média");
   Serial.print(": ");
   Serial.println(resultado);
   i++;
  }
}
