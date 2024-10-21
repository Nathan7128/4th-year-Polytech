-- Définition du moteur de base de données
SET default_storage_engine=InnoDB;

-- Création de la base de données
DROP DATABASE IF EXISTS BDLivraisons;
CREATE DATABASE BDLivraisons;
USE BDLivraisons;

CREATE TABLE CategoriesClt(
  Classe CHAR(1) PRIMARY KEY,
  Reduction INT(2) NOT NULL);

CREATE TABLE Clients(
  NumClt INT(5) PRIMARY KEY,
  NomClt VARCHAR(20)  NOT NULL,
  Categorie CHAR(1) NULL REFERENCES CategoriesClt(Classe));

CREATE TABLE Produits(
  NumProduit INT(5) PRIMARY KEY,
  Libelle VARCHAR(20),
  PrixBrut INT(5));

CREATE TABLE Livraisons(
  NumProduit INT(5) REFERENCES Produits(NumProduit),
  NumClt INT(5) REFERENCES Clients(NumClt),
  Quantite INT(6) NOT NULL,
  PRIMARY KEY(NumProduit, NumClt));

CREATE TABLE Composition(
  NumProCompose INT(5) REFERENCES Produits(NumProduit),
  NumProComposant INT(5) REFERENCES Produits(NumProduit),
  Quantite FLOAT(6,2) NOT NULL,
  PRIMARY KEY(NumProCompose, NumProComposant));

INSERT INTO Categoriesclt VALUES ('B', 10);
INSERT INTO Categoriesclt VALUES ('A', 20);
INSERT INTO Categoriesclt VALUES ('C', 12);
INSERT INTO Categoriesclt VALUES ('E',  5);

INSERT INTO Clients VALUES (1, 'Tintin', 'B');
INSERT INTO Clients VALUES (2, 'Dupond', 'E');
INSERT INTO Clients VALUES (3, 'Dupont', 'E');
INSERT INTO Clients VALUES (4, 'Haddock', 'B');
INSERT INTO Clients VALUES (5, 'Tournesol', 'B');
INSERT INTO Clients VALUES (6, 'Milou', NULL);
INSERT INTO Clients VALUES (7, 'Dupont', 'A');
INSERT INTO Clients VALUES (1715, 'Muller', 'E');
INSERT INTO Clients VALUES (1718, 'Toto', 'B');
INSERT INTO Clients VALUES (1723, 'Girard', 'B');
INSERT INTO Clients VALUES (1716, 'girard', 'B');
INSERT INTO Clients VALUES (1725, 'Girard', 'B');
INSERT INTO Clients VALUES (1724, 'Girard', 'B');
INSERT INTO Clients VALUES (17211, 'Girard', 'A');
INSERT INTO Clients VALUES (1726, 'Nathalie', 'B');
INSERT INTO Clients VALUES (1717, 'Alfred', 'A');
INSERT INTO Clients VALUES (1721, 'Girard', 'B');
INSERT INTO Clients VALUES (1730, 'Pedrono', 'C');
INSERT INTO Clients VALUES (1720, 'Rastapopoulos', 'C');

INSERT INTO Produits VALUES (1, 'Foie', 150);
INSERT INTO Produits VALUES (6, 'Cacahuetes', 25);
INSERT INTO Produits VALUES (18, 'Cacahuettes', 35);
INSERT INTO Produits VALUES (23, 'Cage', 350);
INSERT INTO Produits VALUES (33, 'Peinture', 250);
INSERT INTO Produits VALUES (40, 'Tarte aux pommes', 45);
INSERT INTO Produits VALUES (41, 'Pate', 18);
INSERT INTO Produits VALUES (42, 'Pomme', 2);
INSERT INTO Produits VALUES (43, 'Farine', 2);
INSERT INTO Produits VALUES (44, 'Oeuf', 1);
INSERT INTO Produits VALUES (45, 'Sucre', 10);
INSERT INTO Produits VALUES (46, 'Compote', 12);

INSERT INTO Livraisons VALUES (1, 1, 500);
INSERT INTO Livraisons VALUES (6, 1, 2);
INSERT INTO Livraisons VALUES (6, 5, 10);
INSERT INTO Livraisons VALUES (6, 4, 1);
INSERT INTO Livraisons VALUES (18, 2, 25);
INSERT INTO Livraisons VALUES (23, 4, 1);
INSERT INTO Livraisons VALUES (33, 2, 5);
INSERT INTO Livraisons VALUES (33, 3, 5);
INSERT INTO Livraisons VALUES (23, 7, 2);
INSERT INTO Livraisons VALUES (1, 4, 250);
INSERT INTO Livraisons VALUES (18, 4, 3);
INSERT INTO Livraisons VALUES (33, 4, 55);
INSERT INTO Livraisons VALUES (6, 2, 1);
INSERT INTO Livraisons VALUES (6, 3, 2);
INSERT INTO Livraisons VALUES (6, 7, 3);
INSERT INTO Livraisons VALUES (40, 4, 100);
INSERT INTO Livraisons VALUES (41, 4, 10);
INSERT INTO Livraisons VALUES (42, 4, 25);
INSERT INTO Livraisons VALUES (43, 4, 35);
INSERT INTO Livraisons VALUES (44, 4, 5);
INSERT INTO Livraisons VALUES (45, 4, 13);
INSERT INTO Livraisons VALUES (46, 4, 14);

INSERT INTO Composition VALUES (40, 41, 1);
INSERT INTO Composition VALUES (40, 42, 5);
INSERT INTO Composition VALUES (40, 46, 1);
INSERT INTO Composition VALUES (40, 45, 0.10);
INSERT INTO Composition VALUES (41, 43, 1);
INSERT INTO Composition VALUES (41, 44, 2);
INSERT INTO Composition VALUES (41, 45, 0.25);

COMMIT;

SELECT *
FROM CategoriesClt;

SELECT *
FROM Clients;

SELECT *
FROM Produits;

SELECT *
FROM Livraisons;

SELECT *
FROM Composition;
