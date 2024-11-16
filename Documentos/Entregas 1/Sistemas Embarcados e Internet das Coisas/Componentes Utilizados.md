Para o projeto Irrigação Inteligente, foi-se utilizada uma vasta coletânea de componentes, processadores, sensores e entre diversos outros componentes dos mais diversos tipos. Eles são:

## Arduino ESP32 Dev Module
<p align="center">
    <img src="https://github.com/user-attachments/assets/85c3c59a-681a-471f-b569-a107951b4a8f" alt="Imagem do computador" width="400" />
</p>
<br>O Arduino ESP32 é a peça cruial do nosso projeto. O Arduino em si é um minicomputador que pode ser usado para realizar diversas funções, como captar dados de sensores e processar e enviar dados para um sistema remoto. Já o módulo ESP32 se consiste em um módulo com acessibilidade para Wi-Fi e Bluetooth, permitindo a criação de servidores e acesso à informação à uma distância considerável.</br>
<br>Com ele, fomos capazes de criar um servidor web que pode controlar o projeto à distância e receber os dasdos analisados e coletados. Não apenas isso, como também o ESP32 é o portador da maioria e, por consequência, da parte mais importante do código do projeto, e sem ele, nada seria possível. Para o projeto, optamos pelo modelo Arduino ESP32 Dev Module justamente pelo seu preço acessível e seu formato mais compacto e mais bem elaborado, ajudando no processo de montagem do projeto.</br>

## Sensor de Umidade de Solo HL-69
<p align="center">
    <img src="https://github.com/user-attachments/assets/9edca1ac-6f7f-494d-bd00-3b2cf6896b68" alt="Imagem do computador" width="400" />
</p>

<br>Assim como o Arduino ESP32, o Sensor de Umidade de Solo é umas das princiapais partes do nosso projeto. O Sensor de Umidade de Solo serve para ler o nível de umidade do solo em que se encontra, que pode variar de 0 a 4095, onde cada valor diferente envia um valor diferente para o Arduino, onde é possível ser em um Monitor Serial.</br>
<br>Ele é responsável pos captar informações da terra como, por exemplo, se a terra em que se situa está demasiada úmida ou seca e, assim que a informação for coletada, ele a enviará para o ESP32 para que possa sewr analisada, lida e processada, dando continuidade ao restante do código.</br>
<br>Neste caso, optamos pelo modelo HL-69 pelo seu tamanho compacto e minimalista, compatibilidade com a placa Arduino e preço acessível. Tais carácteristicas fizeram com que ele fosse compatível com o que mais visamos neste projeto: a adaptabilidade.</br>

## Mini Bomba D'água Submersível 3.3v/5v
<p align="center">
    <img src="https://github.com/user-attachments/assets/c8af74db-1fde-4780-bf2e-be1aeb594748" alt="Imagem do computador" width="400" />
</p>
<br>Assim que a os dados do solo forém recebidos e analisados pelo ESP32, dependendo de seu valor, a bomba d'água será ativada. Caso o solo esteja úmido, molhado, encharcado, ou se foi regado a pouco tempo, a bomba permanecerá em estado de inatividade. Entretanto, caso faça muito tempo desde que o solo foi regado, e caso sua leitura mostre que ele eestá seco, a bomba será ativada, bombeando água para regar a plantação.</br>
<br>Assim  como o Sensor de Umidade de Solo HL-69, a Mini Bomba D'água Submersível 3.3v/5v também possui um tamanho compacto e minimalista, compatibilidade com a placa Arduino e preço acessível, ou seja, em outras palavras, adaptável.</br>

## Mangueira Cristal Pvc 4mm
<p align="center">
    <img src="https://github.com/user-attachments/assets/e198536a-1221-44ab-92b0-ec53812c4309" alt="Imagem do computador" width="400" />
</p>
<br>Utilizada em conjunto com a Bomba D'água, a mangueira é responsável por transportar a água absorvida e bombeada pela bomba até o seu destino final: a plantação.</br>

## LM393 Comparator Module - ADIY
<p align="center">
    <img src="https://github.com/user-attachments/assets/dc461c33-31b0-481c-b3eb-3c9b35e6f155" alt="Imagem do computador" width="400" />
</p>
<br>O LM393 Comparator Module - ADIY é um comparador de tensão de precisão. Ele é amplamente usado em sistemas que envolvem líquidos, alarmes, temperatura e luz, justamente pelo nível de precisão de leitura que ele fornece.</br>
<br>Quando acoplado ao Sensor de Umidade de Solo, serve para regular um certo valor de tensão. No contexto deste projeto, um certo nível de umidade do solo. Ele é quem é responsável por enviar sinais do Sensor de Umidade de Solo para a placa Arduino caso o solo esteja demasiado seco.</br>

## Relé FL-3FF-S-Z 5VDC
<p align="center">
    <img src="https://github.com/user-attachments/assets/d0ba1fbf-03c2-4227-84c9-c3cd0637a9ad" alt="Imagem do computador" width="400" />
</p>
<br>Um relé é é uma ferramenta versátil para controle de dispositivos elétricos de alta potência a partir de circuitos de baixa potência. Sua capacidade de isolar circuitos e comutar cargas torna-o ideal para uma ampla gama de aplicações em automação e controle.</br>
<br>Em nosso projeto, assim que o valor enviado pelo Comparador for lido pelo Arduino, caso seja um valor útil, um sinal será enviado ao relé que, por instância, irá ativar a bomba d'água, irrigando a plantação.</br>

## Protoboard (preferência Long)
<p align="center">
    <img src="https://github.com/user-attachments/assets/d3afbb1f-89f1-43a8-ada4-6b58dc6cc173" alt="Imagem do computador" width="400" />
</p>
<br>A Protoboard é onde todo o projeto foi organizado. Ela é uma ferramenta utilizada para a montagem de circuitos eletrônicos de forma temporária. Ela permite que você conecte componentes eletrônicos sem a necessidade de soldagem, facilitando o processo de prototipagem e testes.</br>

## Jumpers MxF e Jumpers MxM
<p align="center">
    <img src="https://github.com/user-attachments/assets/5ae64ae8-1214-45f6-a710-e4c14b4f09f2" alt="Imagem do computador" width="400" />
</p>
<br>Os jumpers, em conjunto com a Protoboard, servem para alimentar algum componente que está sendo utilizado no momento, seja com uma carga positiva ou negativa.</br>

## PowerBank AlphaGold 10000 mAh
<p align="center">
    <img src="https://github.com/user-attachments/assets/1362ab9e-e12d-41e0-ab52-6ce23a2b9a10" alt="Imagem do computador" width="400" />
</p>
<br>O PowerBank AlphaGold é meio pelo qual todo o projeto será energizado. É extremamente resistente e duradouro, podendo durar cerca de 20 horar com um celular e, aproximadamente, 200 horar alimentando o projeto devido ao baixo nível de consumo. Devido aos seus cabos já acoplados, sendo eles C, Mini-C, Lightining e BTE-29, a compatibilidade com o projeto é facilitada, juntamente dada à sua portabilidade. Além do mais, possui entradas USB, USB-C e C para recarga e carga de outros dispositivos, sendo uma real bateria, alimentando mais de um item ao mesmo tempo.</br>
