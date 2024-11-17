# Servidores e sua performace.

##  Servidor ESP32.
![zgdasrgsdf](https://github.com/user-attachments/assets/3c186b10-8c93-400d-98e1-bb540c931d18)
<br>O ESP32 cria um servidor com o IP/dados da porta 80 que é uma porta default do HTML, usando a rede WiFi previamente conectada no código.<br>
<br>A partir disto o ESP32 começara a enviar as informações do Sensor e outras funções em formato JSON para o server buscando um OK como resposta do Servidor ao ESP em caso de sucesso.<br>

## Performace.
![asfaewedqawd](https://github.com/user-attachments/assets/34fb1c54-f8ab-4f09-ad7c-fa7142e677ad)
<br>O servidor está recebendo as informações com um delay abaixo de 1 SEG oque não causa nenhum tipo de problema para leitura futuras por meio de outros server, pois, está definido para ele atualizar a cada 1 seg o servidor.<br>

<br><br>
<br><br>
## Servidor Cliente

![badfhasdfsrg](https://github.com/user-attachments/assets/b0083713-319f-42b4-8b3e-49c6523a4644)
Servidor cliente feito com HTML que busca as informações em JSON do Dóminio IP/dados que é o servidor criado pelo ESP32.
Com sucesso, o Servidor Cliente atualiza a cada 2 Segundos, buscando novas informações do Servidor do ESP32.

## Performace HTML

![asdafasfafa](https://github.com/user-attachments/assets/35b179ed-5409-4fcd-9c78-f27d6dd1f396)
O delay da entrega das informações não alteram ou prejudicam o entendimento do cliente, pois, a atualização aparece no tempo corredo do requerimento do servidor html para o servidor ESP32.
O delay do Servidor ESP32 + O delay do Servidor Cliente não superam a taxa de atualização os servidores, oque mantem os servidores fluidos e sem erros.



