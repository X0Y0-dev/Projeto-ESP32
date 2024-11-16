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
    else if (valor >= 1200 && valor < 3200) {
        resultado = "Solo Umido!";
    } 
    else if (valor >= 3200) {
        resultado = "Solo Molhado!";
    } 
    else if (valor > 3200 && valor < 4100) {
        resultado = "Solo Encharcado!";
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
