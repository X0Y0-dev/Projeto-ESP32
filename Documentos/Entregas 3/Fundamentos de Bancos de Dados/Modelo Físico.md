## Modelo Lógico
Primeiramente, para podermos entender o Modelo Físico do Banco de Dados do nosso projeto, precisamos entender o que acontece entre ele e o Modelo Conceitual:
<p align="center">
    <img src="https://github.com/user-attachments/assets/c08c30e8-aee9-4a71-991a-eb06a30fa05b" alt="Imagem do computador" width="400" />
</p>

No Modelo Lógico, temos a configuração dos atributos, atribuindo valores a eles para serem interpretados corretamente na passagem para o Modelo Físico:

<br>° ***Sensor_Umidade***:</br>
  - [Primary Key] ID_Sensor (**INT**);
  - Localizacao (**VARCHAR(255)**);
  - Limite_Inferior (**FLOAT**);
  - Limite_Superior(**FLOAT**).

<br>° ***Medicao***:</br>
  - [Primary Key] ID_Medicao (**INT**)/
  - Data_Hora (**TIMESTAMP**);
  - Valor (FLOAT);
  - [Foreign Key] fk_Sensor_Umidade_ID_Sensor (**INT**).

<br>° ***Acao***:</br>
  - Data_Hora (**TIMESTAMP**);
  - Descricao (**VARCHAR(255)**);
  - [Primary Key] ID_Acao (**INT**);
  - [Foreign Key] fk_Sensor_Umidade_ID_Sensor (**INT**);
  - [Foreign Key] fk_Medicao_ID_Medicao (**INT**).

<br>° ***Bomba_Agua***:</br>
  - [Primary Key] ID_Atuador (**INT**);
  - Localizacao (**VARCJAR(255)***);
  - Estado (**BOOLEAN**);
  - [Foreign Key] fk_Acao_ID_Acao (**INT**).

## Modelo Físico
Após configurar o Modelo Lógico, finalmente, com base no tipo de atributos e relações que as entidades tem, é possível criar o Model Físico:
```SQL
/* Lógico_1: */

CREATE TABLE Sensor_Umidade (
    ID_Sensor INT PRIMARY KEY,
    Localizacao VARCHAR(255),
    Limite_Inferior FLOAT,
    Limite_Superior FLOAT
);

CREATE TABLE Medicao (
    ID_Medicao INT PRIMARY KEY,
    Data_Hora TIMESTAMP,
    Valor FLOAT,
    fk_Sensor_Umidade_ID_Sensor INT
);

CREATE TABLE Bomba_Agua (
    ID_Atuador INT PRIMARY KEY,
    Localizacao VARCHAR(255),
    Estado BOOLEAN,
    fk_Acao_ID_Acao INT
);

CREATE TABLE Acao (
    Data_Hora TIMESTAMP,
    Descricao VARCHAR(255),
    ID_Acao INT PRIMARY KEY,
    fk_Sensor_Umidade_ID_Sensor INT,
    fk_Medicao_ID_Medicao INT
);
 
ALTER TABLE Medicao ADD CONSTRAINT FK_Medicao_2
    FOREIGN KEY (fk_Sensor_Umidade_ID_Sensor)
    REFERENCES Sensor_Umidade (ID_Sensor)
    ON DELETE CASCADE;
 
ALTER TABLE Bomba_Agua ADD CONSTRAINT FK_Bomba_Agua_2
    FOREIGN KEY (fk_Acao_ID_Acao)
    REFERENCES Acao (ID_Acao)
    ON DELETE CASCADE;
 
ALTER TABLE Acao ADD CONSTRAINT FK_Acao_2
    FOREIGN KEY (fk_Sensor_Umidade_ID_Sensor)
    REFERENCES Sensor_Umidade (ID_Sensor)
    ON DELETE CASCADE;
 
ALTER TABLE Acao ADD CONSTRAINT FK_Acao_3
    FOREIGN KEY (fk_Medicao_ID_Medicao)
    REFERENCES Medicao (ID_Medicao)
    ON DELETE CASCADE;
```
