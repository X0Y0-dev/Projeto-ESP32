## COMO NOSSO PROJETO APENAS USA 1 SENSOR (SENSOR DE UMIDADE DE ÁGUA), AS ENTREGAS 3 E 4 SÃO IDÊNTICAS
# Código Teste do Sensor
<br>Em um exame em que se esperava que o valor entregue pelo sensor fosse abaixo de 2800 e acima de 2900, a quantidade de vezes do ocorrido em 100 testes foi de 0 para 100. Já em um teste de precisão mais rígida, em que o valor abaixo de 2820 e acima de 2870 fossem considerados imprecisos, apenas ocorreram 9 em 100 casos.<br>
<br>O primeiro teste de precisão, menos rígido, obteve um resultado de precisão de 100%. Já o segundo teste, de precisão mais rígido, obteve um resultado de precisão de 99,91%.<br>
<br>Usando o seguinte código, é possivel fazer o mesmo teste de acurácia.<br>

```cpp
//Declaração dos elementos a serem utilizados neste programa
int Sensor = 33;
int valor = 0;
int resultado = 0;
int i = 0;

void setup() {
    pinMode(Sensor, INPUT); //Sensor emitirá uma resposta
    Serial.begin(9600);
}

void loop() {
//Caso o valor hipotétio "i" for abaixo de 100, o código se repitirá até que tal afirmação se prove o contrário
  if (i < 100) {
    i++; //Valor hipotético de "i" será somado com ele mesmo a cada início de loop
    valor = analogRead(Sensor); //Função "valor" é igual à leitura digital do sensor
    Serial.print(i);
    Serial.print(": ");
    Serial.println(valor);
    resultado = resultado + valor; //Soma de valores fornecidos pelas tentativas do sensor
    delay(10);
  } else if (i == 100) { //Caso a primeira afirmação se prove falsa, haverá uma verificação de valor hipotético "i" para saber se ele é igual a 100
    Serial.print("Total:");
    Serial.println(resultado);
    resultado = resultado / 100; //Fazendo a conta para calcular a acurácia
    Serial.print("Média: ");
    Serial.println(resultado);
    i++;
  }
}
