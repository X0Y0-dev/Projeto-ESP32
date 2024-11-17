![Cliente Server](https://github.com/user-attachments/assets/a0a90b4c-0b4f-4db0-a9f2-f93c666f4534)
![ESPInfo](https://github.com/user-attachments/assets/03c93420-122f-4402-b613-58d5823e2017)

# Trocando arquivos.

<br> Os servidores estão comunicando entre si. O servidor Cliete esta requisitando com sucesso as informações gravadas no servidor do ESP32, Informações estás sendo.<br>
- valor menino pelo sensor
- Função de verificação do estado do solo
- Seguntos deis da ultima vez que a bomba d'agua foi ligada.

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

## Cliente Server Atualizando.


![Config arquivo HTML](https://github.com/user-attachments/assets/5832fedc-ac2e-4c6a-9c0b-278d17a36c08)

<br> O Servidor Cliente esta por meio das configurações da imagem, requisitando arquivos do Servidor ESP32 e retornando um Sucesso sempre que a requisição deu certo. <br>


![Imagens Arquivos HTML](https://github.com/user-attachments/assets/bf2341da-f2ac-4ffa-843b-f8728eb2ec0f)
<br> O servidor está requerindo as informações do sensor, do estado do solo e Segundos com sucesso sem dar nenhum erro de volta.<br>
