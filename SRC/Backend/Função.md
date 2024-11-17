# Função usada no projeto
Uma das funções utilizadas no projeto é a função de checagem do estádo do solo, puxando o parametro sensor e usando do valor entregue por ele para checar qual tipo de resposta o programa deve da com base neste.

## Código Comentado

```cpp
//função que devolve uma string escrita com a situação atual do solo do sensor usando o parametro sensor.
String Solo(int Sensor) {
//cria uma int que apenas funciona dentro do código
    int valor = analogRead(Sensor);
    String resultado;
//diz qual a condição do solo com base no valor dado.
// se for < 600 p solo é seco.
    if (valor < 600) {
        resultado = "Solo Seco!!!";
    }
// se for >= 600 e < 1200 o solo é Ressecado
    else if (valor >= 600 && valor < 1200) {
        resultado = "Solo Ressecado!";
    }
// se for  >= 1200 e < 2800 o solo é Umido
    else if (valor >= 1200 && valor < 2800) {
        resultado = "Solo Umido!";
    }
// se for  >= 2800 e < 3300 o solo é molhado
    else if (valor >=2800 && valor <=3300) {
        resultado = "Solo Molhado!";
    }
// se for  > 3300 e < 4100 o solo é encharcado.
    else if (valor > 3300 && valor < 4100) {
        resultado = "Solo Encharcado!";
    }
//retorna valor de resultado que foi impresso anteriormente.
    return resultado;
}
