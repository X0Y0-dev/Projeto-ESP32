## Modelo Conceitual
<p align="center">
    <img src="https://github.com/user-attachments/assets/601c10d4-1f9a-403f-a6b8-9ef1866be01e" alt="Imagem do computador" width="400" />
</p>

## Entidades e Atributos
No modelo conceitual de Banco de Dados apresentado temos as seguintes entidades:

<br>° ***Sensor_Umidade***, com os seguintes atributos:</br>
- **ID_Sensor** (Identificador);
- Localizacao (Onde se encontra o sensor);
- Limite_Inferior (Valor abaixo do qual o solo é considerado seco);
- Limite_Superior (Valor acima do qual o solo é considerado encharcado);

<br>° ***Medicao***, com os seguintes atributos:</br>
- **ID_MEdicao** (Identificador);
- Data_Hora (Data e hora da leitura);
- Valor (Leitura da umidade do solo);

<br>° ***Acao***, com os seguintes atributos:</br>
- **ID_Acao** (Identificador);
- Data_Hora (Data e hora da ação);
- Descricao (E.X.: "Bomba ligada devido a solo seco");

<br>° ***Bomba_Agua***, com os seguintes atributos:</br>
- **ID_Atuador** (Identificador);
- Estado (Ligado/Desligado);
- Localização (Onde a bomba se encontra).

## Relações
1. ***Sensor_Umidade <-> Medicao***:
   - 1,1 para Sensor (Um sensor sempre pode realizar medições, e não se podr existir um sensor sem medições registradas);
   - 0,N para Medicao (Uma medição só existe se houver um sensor associado, mas um sensor pode não ter medições registradas).

2. ***Sensor_Umidade <-> Acao***:
   - 1,1 para Sensor (Cada ação no sistema sempre estará associada a um, e **apenas** um, sensor);
   - 0,N para Acao (Um sensor pode não ter ações associadas, ou seja, a ação depende de um evento gerado por uma medição, mas não é garantido que sempre haverá uma ação associada).

3. ***Bomba_Agua <-> Acao***:
   - 1,1 para Atuador (Uma ação **sempre** depende de um, e **exclusivamente** um, atuador);
   - 0,N para Acao (Um atuador pode ter zero ou múltiplas ações associadas.).

4. ***Medicao <-> Acao***:
   - 1,1 para Medicao (Cada ação sempre se baseia em uma, e **exclusivamente uma**, medição);
   - 0,N para Acao (Uma medição pode não gerar nenhuma ação se a condição não for atendida, ou pode gerar várias).
