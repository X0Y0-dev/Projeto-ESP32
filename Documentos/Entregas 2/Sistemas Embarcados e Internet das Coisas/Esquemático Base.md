![Esquematico_base](https://github.com/user-attachments/assets/f3190e24-ea81-416e-bf35-23342fa26526)

```CPP
int Sensor = 33;

void checar(int Sensor)
{
    int valor = analogRead(Sensor);
    Serial.print("valor Sensor");
    Serial.print(": ");
    Serial.println(valor);
}


void setup() {
    pinMode(Sensor, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    checar(Sensor);
    delay(1000);
}
```
