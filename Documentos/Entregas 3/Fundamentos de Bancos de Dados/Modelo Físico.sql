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
