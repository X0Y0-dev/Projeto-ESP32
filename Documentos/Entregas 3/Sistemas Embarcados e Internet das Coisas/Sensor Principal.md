## Esquematico da Montagem do Sistema Físico
<p align="center">
    <img src="https://github.com/user-attachments/assets/b7d44df1-4f6a-4868-afb9-3c32f1cb3ef6" alt="Imagem do computador" width="400" />
</p>

Neste esquema, temos a adição do relé e da bomba d'água. O comparador está conectado ao relé que, por sua vez, está conectado com a bomba d'água, fazendo com que o controlador acabe por regir as ações da bomba indiretamente. Assim que as informações do sensor saírem do controlador, o relé julgará se elas bate, com os parâmetros estabelecidos na programação ou não. Caso batam, o relé enviará um sinal para bomba d'água que, por sua vez, será ativa e efetivada na plantação. Caso contrário, caso a informação não seja pertinente, o relé não enviará sinal algum para a bomba d'água.<br>
Na imagem, vemos a bomba d'água recebendo energia negativa (cabo preto) e energia positiva de 5v (cabo vermelho) que, por sua vez, é conectado ao relé. Já o relé recebe energia positiva de 5v (cabo roxo), energia negativa (cabo preto) euqnato mantém-se conectado ao controlador (cabo vermelhor) e à sua porta 33, que serve tanto para leitura analógica quanto digital (Neste caso leitura digital).<br>

## Teste do Projeto com Arduino Uno
<p align="center">
    <img src="https://github.com/user-attachments/assets/7cbb9847-a3ea-4e5e-af9a-962c691d239a" alt="Imagem do computador" width="400" />

</p> 

Neste esperimento feito na FECAP, é possível ver o arduino sendo alumentado com o Powerbank AlphaGold 10000mAh, enquanto o Sensor de Umidade de Solo está na terra. Neste experimento, como houveram problemas técnicos no dia, tivemos que improvisar com um Arduino Uno, ou seja, o máximo passou de 4095 para 1023. Caso o sensor chegasse a um valor de 600 ou acima, o LED azul iria acender e, caso contrário, se o sensor chegasse a um valor de 599 ou abaixo, o LED permaneceria apagado. Como é observável na imagem, o valor obtido pelo sensor é igual ou acima de 600, visto que o LED azul está aceso.

## Esquematico Montagem Física ESP32
<p align="center">
    <img src="https://github.com/user-attachments/assets/b00b5cd8-870c-4a2a-9cd9-23631f02a7ca" alt="Imagem do computador" width="400" />
</p>

Aqui, vemos o mesmo procedimento feito usando o Arduino UNO na FECAP, porém, desta vez, usando um Arduino ESP32.
