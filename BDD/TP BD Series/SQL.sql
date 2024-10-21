-- Set display

COLUMN ATT1 FORMAT 99.99 
COLUMN ATT2 FORMAT A8 
SET PAGESIZE 100
SHOW PAGESIZE
SET LINESIZE 200
SHOW LINESIZE

-- Create tables

CREATE TABLE Serie (
    IdS number(4) CONSTRAINT p_key_IdS PRIMARY KEY,
    NomS varchar2(20) not null,
    NbSaison number(2),
    EpSaison number(3),
    Debut number(4) not null,
    Fin number(4)
);

CREATE TABLE Joue (
    IdAct number(4),
    IdS number(4),
    NomRole varchar2(20),
    PrenomRole varchar2(20),
    CONSTRAINT f_key_IdS foreign key (IdS) REFERENCES Serie,
    CONSTRAINT p_key_IdAct_IdS_NomRole_PrenomRole primary key (IdAct, IdS, NomRole, PrenomRole)
);

CREATE TABLE Acteur (
    IdAct number(4),
    NomAct varchar2(20) not null,
    PrenomAct varchar2(20) not null,
    Nationalite varchar2(20),
    Age number(3),
    CONSTRAINT p_key_IdAct primary key (IdAct)
);

ALTER TABLE Joue
ADD CONSTRAINT f_key_IdAct foreign key (IdAct) REFERENCES Acteur;

ALTER TABLE Acteur
ADD CONSTRAINT AgeMin CHECK(Age >= 18) ;

INSERT INTO Serie Values
(1, 'Game of Thrones', 8, 10, 2011, 2019),
(2, 'Vampire Diaries', 8, 22, 2009, 2017),
(3, 'Casa de Papel', 2, 23, 2017, NULL) ;

INSERT INTO Acteur VALUES
(1, 'DOBREV', 'Nina', 'Canadien', 32),
(2, 'WESLEY', 'Paul', 'Italien', 39),
(3, 'SOMERHALDER', 'Ian', 'Americain', 42),
(4, 'CORBERO', 'Ursula', 'Espagnol', 32),
(5, 'CLARKE', 'Emilia', 'Britannique', 35);

INSERT INTO Joue VALUES
(1, 2, 'GILBERT', 'Elena'),
(1, 2, 'PIERCE', 'Catherine'),
(2, 2, 'SALVATORE', 'Stefan'),
(4, 3, 'OLIVEIRA', 'Silene'),
(5, 1, 'TARGARYAN', 'Daenerys') ;

-- 1
INSERT INTO Acteur VALUES (3, 'Harington', 'Kit', 'Britannique', 34) ;
-- Impossible car clé primaire deja utilisée

-- 2
INSERT INTO Joue VALUES (3, 4, 'Cooper', 'Sheldon') ;
-- Erreur car la série d'id 4 n'a pas été inséré

-- 3
INSERT INTO Acteur(IdAct, NomAct, PrenomAct, Age) VALUES (6, 'Armitage', 'Liam', 13) ;
-- Impossible car age < 18

-- 4
INSERT INTO Serie(IdS, NomS) VALUES (4, 'Obi-Wan Kenobi') ;
-- Impossible car contrainte NOT NULL pour Debut

-- 5
UPDATE Acteur
SET Nationalite = 'Italien'
WHERE PrenomAct = 'Paul' AND NomAct = 'WESLEY' ;

-- 6
DELETE FROM Acteur
WHERE IdAct = 5 ;
-- Impossible car son IdAct est référencé dans la table Joue

-- 7
ALTER TABLE Joue
DROP CONSTRAINT f_key_IdAct ;

ALTER TABLE Joue
ADD CONSTRAINT f_key_IdAct FOREIGN KEY (IdAct) REFERENCES Acteur ON DELETE CASCADE ;

DELETE FROM Acteur
WHERE IdAct = 5 ;

SELECT * FROM Joue ;

INSERT INTO Acteur VALUES
(5, 'CLARKE', 'Emilia', 'Britannique', 35);

INSERT INTO Joue VALUES
(5, 1, 'TARGARYAN', 'Daenerys') ;

-- 8
ALTER TABLE Serie
ADD (Genre VARCHAR2(15)) ;

UPDATE Serie
SET Genre = 'Fantastique'
WHERE IdS = 1;
-- Le genre des autres séries est NULL

-- 9
UPDATE Acteur
SET Nationalite = SUBSTR(Nationalite, 0, 3) ;

ALTER TABLE Acteur
MODIFY (Nationalite VARCHAR2(3)) ;

-- 10
CREATE VIEW VampireDiaries AS
SELECT NomAct, PrenomAct, NomRole, PrenomRole
FROM Acteur A JOIN (
    SELECT *
    FROM Joue J JOIN Serie S ON J.IdS = S.IdS
    WHERE S.IdS = 2
) J ON A.IdAct = J.IdAct ;

-- 11
INSERT INTO Joue VALUES (3, 2, 'Salvatore', 'Damon') ;

-- 12
CREATE INDEX Index_nom ON Acteur(NomAct) ;

-- 13
CREATE INDEX Index_nom2 ON VampireDiaries(NomAct) ;

-- 14
INSERT INTO Acteur VALUES
(10, 'Harington', 'Kit', 'Bri', 32),
(11, 'Brake', 'Richard', 'Bri', 54),
(12, 'Morgan', 'Joseph', 'Bri', 38) ;

rollback ;

-- 16

-- ALTER TABLE Serie
-- ADD (Fin2 DATE) ;

-- UPDATE Serie
-- SET Fin2 = TO_DATE(Fin, 'YYYY') ;

-- 17
DELETE FROM Acteur
WHERE IdAct = 4 ;

-- 18
SELECT *
FROM all_constraints
WHERE table_name = 'SERIE' ;

-- 19
SELECT owner, table_name FROM all_tables
WHERE owner = 'ETU' ;

-- 20
DROP TABLE Joue ;

SELECT * FROM VampireDiaries ;

-- 21
DELETE FROM Acteur ;

SELECT index_name, column_name 
FROM user_ind_columns 
WHERE table_name = 'ACTEUR';

-- 22
DROP TABLE Acteur ;

SELECT index_name, column_name 
FROM user_ind_columns ;

-- 23
DROP TABLE Serie ;