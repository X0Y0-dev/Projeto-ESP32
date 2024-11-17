# Código Completo! Projeto Irrigação!

Aqui temos o código completo para o projeto. Nossa tacada final!Esse código funciona com base na biblioteca WiFi e WebServer, que permitem que possamos abrir e configurar conexão de wifi, ip e servidores, assim, possibilitando também a troca de informações entre eles.<br>
<br>Utilizamos uma mistura de código CPP e JSON disfarçado na parte da entrega de arquivos pelo servidor, facilitando a leitura do servidor Cliente com o ESP32.<br>
<br>Sabendo da maleabilidade do projeto, é necessário a fragmentação do código para que possamos possibilitar e facilitar a modificação e implementação de ajustes visando o futuro do nosso código e visando a facilidade de compreensão daqueles que futuramente possam ver e mexer no código.<br>
<br>A partir do momento em que as funções e procedimentos estão devidamente separados e posicionados no projeto, ele se torna um grande quebra-cabeça.<br>


```cpp
#include <WiFi.h>
#include <WebServer.h>

// definir senha e nome do wifi que o ESP32 vai se conectar.
const char* ssid = "Nome do Wifi Super Moderno"; 
const char* password = "Senha de wifi super segura"; 

// pinos e valores necessários
int Sensor = 33;
int rele = 32;
int valor = 0;
int segundos = 0;

WebServer server(80); // cria um servidor na porta 80

// procedimento para checar a umidade da terra e ativar bomba ou não se necessário
void checar(int Sensor, int rele) {
    int valor = analogRead(Sensor);
    Serial.println("valor Sensor");
    Serial.println(valor);
    // se estiver menor a umidez do solo que tal quantia defult:1500
    if (valor < 3500) {
        // se a terra estiver seca
        digitalWrite(rele, LOW);
        Serial.println("Bomba de Água Ligada!");
    } else {
        // se ela não estiver seca
        digitalWrite(rele, HIGH);
        Serial.println("Bomba de Água Desligada!");
    }
}

//função que devolve uma string escrita com a situação atual do solo do sensor.
String Solo(int Sensor) {
    int valor = analogRead(Sensor);
    String resultado;
//diz qual a condição do solo
    if (valor < 600) {
        resultado = "Solo Seco!!!";
    } 
    else if (valor >= 600 && valor < 1200) {
        resultado = "Solo Ressecado!";
    } 
    else if (valor >= 1200 && valor < 2800) {
        resultado = "Solo Umido!!";
    } 
    else if (valor >=2800 && valor < 3300) {
        resultado = "Solo Molhado!!!";
    } 
    else if (valor >= 3300 && valor <= 4100) {
        resultado = "Solo Encharcado!!!!";
    }
//retorna valor de resultado
    return resultado;
}

//aqui é onde iniciaremos nosso servidor e indicaremos oque faz cada pino.
void setup() {
    pinMode(Sensor, INPUT);
    pinMode(rele, OUTPUT);
    Serial.begin(115200);
//inicia o rele travado
    digitalWrite(rele, HIGH);
    
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

void loop() 
 {
    checar(Sensor, rele);
    // caso o rele libere energia, então segundos serão 0
     if (digitalRead(rele) != HIGH)
    {
      segundos = 0;
    }     //caso contrário, aumenta os segundos com delay de 1000 ms
    else if(digitalRead(rele) != LOW){
      segundos++;
    }
    server.handleClient(); // mantem o servidor atualizado e aberto.
    delay(1000);

 }
```
<br><br>
## Segundo Servidor! HTML em ação!
Aqui temos o segundo servidor que, por meio de HTML, configura o servidor para que cada informação chegue em seu devido lugar.<br>
<br>Por meio de um script e do Fetch, fazemos a troca de informações entre servidores, possibilitando o acesso à informação entregue pelo ESP32 em tempo real.<br>


```html
<!DOCTYPE html> //utilizando a versão mais atualizada do HTML
<html lang="pt"> //configuração de acessibilidade, apenas define a pagina como PT
//á parte da cabeça do html, a que pensa e faz, mas não é mostrada.
<head>
    <meta charset="UTF-8"> // declarando tipo de texto
    <meta name="viewport" content="width=device-width, initial-scale=1.0">  // conf do texto do site.
    <title>Monitor de Umidade do Solo</title> //auto explicativo :D

//aqui temos onde faremos script para definir oque acontecera por tras da interface do site.
 <script>
        const ip = '192.168.0.50'; // IP entregue pelo seu ESP32

// aqui temos uma função que pegara buscara do site definido pelo código informações de id especificas para poder entregar em lugares especificos tambem.
        function obterDados() {

//requisição de um servidor a outro.
            fetch(`http://${ip}/dados`) // Chama a nova rota que retorna todos os dados
                .then(response => response.json()) // processa a resposta como JSON que é o arquivo entregue pelo ESP32.
                .then(data => {
/* aqui ele irá fazer um GET para pegar dados e colocalos em seu devido lugar, no caso fazer um GET no arquivo JSON da Umidade, Solo e segundos e entregalos em seus devidos lugares por id */
                    document.getElementById("umidade").innerText = "Umidade do Solo: " + data.umidade;
                    document.getElementById("Solo").innerText = "Condição atual do Solo: " + data.solo;
                    document.getElementById("Segundos").innerText = "Tempo desde a última vez ligada a bomba: " + data.segundos + " Segundos.";
                })
//parte da função fetch que e caso de erro ele escreve ao console um erro.
                .catch(error => {
                    console.error('Erro:', error);
                });
        }

        // atualiza os dados a cada 2 segundos
        setInterval(obterDados, 2000);
    </script>
</head>

//aqui é oque você vê na interface de usuário
<body>
//definindo os textos.
    <h1>Monitor de Umidade do Solo</h1>
//é de suma importância indicar o ID de cada linha para que entregue os dados em seus devidos lugares.
    <p id="umidade">Umidade do Solo: Carregando...</p>
    <p id="Segundos">Ligado última vez:</p>
    <p id="Solo">Condição do Solo:</p>
</body>
</html>
```
