
![ESP32](https://github.com/user-attachments/assets/1bd1d923-cc3a-49d5-869f-6020a2fab011)

# Trocando arquivos.

Por meio do código, O servidor entrega por JSON as informações de:
•	valor do sensor
•	Função de verificação do estado do solo
•	Seguntos deis da ultima vez que a bomba d'agua foi ligada.
Que estão sendo entregues para o Servidor com o dominio IP/dados. (192.168.0.50/dados)

# Código

```cpp
#include <WiFi.h>
#include <WebServer.h>

// definir senha e nome do wifi que o ESP32 vai se conectar.
const char* ssid = "**********"; 
const char* password = "************";

WebServer server(80); // cria um servidor na porta 80
// conectar ao Wi-Fi
    WiFi.begin(ssid, password);
//diz que está conectando no serial e enquanto não estiver em situação de conectado, ele escreverá pontos até conectar.
    Serial.print("Conectando-se ao WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
//quand estiver conectado, pula uma linha, e escreve o IP do Servidor criado pelo ESP32 que será usado depois
    Serial.println("\nConectado ao WiFi!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());


 // configura um servidor com o nome ip/dados para envio de informações.
    server.on("/dados", []() {
//configuração de entrega de informações para o servidor
        valor = analogRead(Sensor); // Atualiza o valor do sensor
        String umidade = String(valor);
        String solo = Solo(Sensor);

//cria uma string escrita da maneira correta em que um arquivo .JASON é escrito.
        String resultado = "{\"umidade\":" + umidade + ", \"solo\":\"" + solo + "\", \"segundos\":" + String(segundos) + "}";
        // utiliza o protocolo de permissão de troca de informações entre site chamado  Cross-Origin Resource Sharing (CORS)
// ele permite que o site html possa puxar informações do site criado pelo esp, Como foi colocado um "*" no parametro, ele permitira que qualquer um possa puxar as informações do ESP32.
        server.sendHeader("Access-Control-Allow-Origin", "*");
/*aqui ele enviará para o servidor com um código de confirmação 200, que para o HTML significa OK. Caso de erro de retorno do sinal ele retornara um 404, oque não é um ok.
tambem envia um arquivo chamado "application/json" com as informações de resultado para o servidor, tal arquivo será no futuro puxado pelo HTML.    */
        server.send(200, "application/json", resultado);
    });

    // inicia o servidor
    server.begin();
}
```


# Server Cliente Atualizando.
 
![HTML Server](https://github.com/user-attachments/assets/013383a3-9099-4e5f-8f96-f1735d7e27be)

O Servidor Cliente esta por meio das configurações da imagem, requisitando arquivos do Servidor ESP32 e retornando um Sucesso sempre que a requisição deu certo.
 
O servidor está requerendo as informações do sensor, do estado do solo e Segundos com sucesso sem dar nenhum erro de volta.
<br> <br>

```HTML
<!DOCTYPE html>
<html lang="pt">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Monitor de Umidade do Solo</title>
    <script>
        const ip = '192.168.0.50'; // Substitua pelo IP do seu ESP32

        function obterDados() {
            fetch(`http://${ip}/dados`) // Chama a nova rota que retorna todos os dados
                .then(response => response.json()) // Processa a resposta como JSON
                .then(data => {
                    document.getElementById("umidade").innerText = "Umidade do Solo: " + data.umidade;
                    document.getElementById("Solo").innerText = "Condição atual do Solo: " + data.solo;
                    document.getElementById("Segundos").innerText = "Tempo desde a última vez ligada a bomba: " + data.segundos + " Segundos.";
                })
                .catch(error => {
                    console.error('Erro:', error);
                });
        }

        // Atualiza os dados a cada 2 segundos
        setInterval(obterDados, 2000);
    </script>
</head>
<body>
    <h1>Monitor de Umidade do Solo</h1>
    <p id="umidade">Umidade do Solo: Carregando...</p>
    <p id="Segundos">Ligado última vez:</p>
    <p id="Solo">Condição do Solo:</p>
</body>
</html>

```
