**COMO NOSSO PROJETO APENAS USA 1 SENSOR (SENSOR DE UMIDADE DE ÁGUA), AS ENTREGAS 1 E 2 SÃO IDÊNTICAS**
<h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/a6a7fd0e-1ed6-4535-9329-196669aa2cb7" alt="Imagem do computador" width="800" />
</p>
</h1>

<br>Na tabela da verdade, temos os seguintes elementos:</br>
- Entrada do Sensor;
- Estado do Solo;
- Bomba D'água;
- Descrição.

<br>Para entendermos a tabela, vamos seguir uma lógica:</br>
- A Bomba D'água só liga quando o solo está seco;
- Caso o solo esteja irrigado, a Bomba D'água não se ativará.

<br>Tendo isso em mente, podemos assumir que:</br>
- Caso o sinal emitido pelo sensor seja "0" (Negativo), o solo está seco, a Bomba D'água será ativada e aparecerá a seguinte mensagem no Monitor Serial: "O solo está seco, ativar irrigação";
- Caso o sinal emitido pelo sensor seja "1" (Positivo), o solo está irrigado, a Bomba D'água permanecerá inativa e aparecerá a seguinte mensagem no Monitor Serial: "O solo está úmido, desativar a irrigação".
