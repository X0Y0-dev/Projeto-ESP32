# Diagrama Funcionamento do Sistema.

## PowerBanK
<br> O PowerBank ou outra fonte de energia deve energizar o ESP32 com 5V.<br>
<br><br>
![Power Bank para ESP32](https://github.com/user-attachments/assets/7493dc4a-1b89-4c55-8a3d-a7ae3d29cea0)
<br> <br>
<br> <br>
## Sensor de Umidade. Ligue!
![ESP para sensor](https://github.com/user-attachments/assets/be04140d-9e5a-4c85-8b87-e5f651b6486d)

## Conexão relé
<br><br>
<br>O ESP32 fornece 3.3V para o sensor de umidade, fazendo com que ele comece a operar e fornecer o valor para o ESP32.
<br><br>
![ESP para Relé](https://github.com/user-attachments/assets/8a58f42c-e201-44e1-acd0-bbdc816d0e03)
<br><br>
<br><br>
<br>o relé é a parte crucial para que possamos decidir quando manter a bomba D'água ligada e quando devemos manter desligado.
<br>O ESP fornece 3,3V para que o Relé possa funcionar e 5V na entrada central da frente do Rele para que ele possa distribuir 5V para o lugar designado.
<br>O ESP32 em base nos valores recebidos pelo Sensor de umidade com a programação, decide se o Relé deve permitir a passagem de 5V ou não. 
<br><br>
![completo](https://github.com/user-attachments/assets/e7d06e68-cde2-4d0a-8932-7a195a178bc4)
