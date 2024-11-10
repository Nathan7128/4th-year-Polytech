-- Création des tables
CREATE TABLE Serie (
    IdS NUMBER(5) CONSTRAINT p_key_IdS PRIMARY KEY,
    NomS VARCHAR2(50),
    NbSaison NUMBER(2),
    EpSaison NUMBER(3),
    Debut NUMBER(4) CONSTRAINT debut_not_null NOT NULL,
    Fin NUMBER(4) 
);

CREATE TABLE Acteur (
    IdAct NUMBER(5) CONSTRAINT p_key_IdAct PRIMARY KEY,
    NomAct VARCHAR2(50) CONSTRAINT NomAct_not_null NOT NULL,
    PrenomAct VARCHAR2(50) CONSTRAINT PrenomAct_not_null NOT NULL,
    Nationalite VARCHAR2(20),
    Age NUMBER(3) CONSTRAINT age_sup18 CHECK (Age > 18)
);

CREATE TABLE Joue (
    IdAct NUMBER(5),
    IdS NUMBER(5),
    NomRole VARCHAR2(50),
    PrenomRole VARCHAR2(50),
    CONSTRAINT f_key_IdAct_Joue FOREIGN KEY (IdAct) REFERENCES Acteur(IdAct),
    CONSTRAINT f_key_IdS_Joue FOREIGN KEY (IdS) REFERENCES Serie(IdS),
    CONSTRAINT p_key_Joue PRIMARY KEY (IdAct, IdS, NomRole, PrenomRole)
);

-- Insertion n-uplets
INSERT INTO Serie VALUES
(1, 'Game of Thrones', 8, 10, 2011, 2019),
(2, 'Vampire Diaries', 8, 22, 2009, 2017),
(3, 'Casa de Papel', 2, 23, 2011, NULL);

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
(5, 1, 'TARGARYAN', 'Daenerys');

-- 1) Insérer le n-uplet (3, Harington, Kit, Britannique, 34) dans Acteur. Que se passe-t-il ? Pourquoi ?
INSERT INTO Acteur VALUES
(3, 'Harington', 'Kit', 'Britannique', 34);

-- 2) Insérer le n-uplet (3, 4, Cooper, Sheldon) dans Joue. Que se passe-t-il ? Pourquoi ?
INSERT INTO Joue VALUES
(3, 4, 'Cooper', 'Sheldon');

-- 3) Insérer l’acteur (6, Armitage, Liam, 13) dont on ne connaît pas la nationalité, dans la table
-- Acteur. Que se passe-t-il ? Pourquoi ?
INSERT INTO Acteur VALUES
(6, 'Armitage', 'Liam', NULL, 13);

-- 4) On souhaite anticiper la diffusion de « Obi-Wan Kenobi ». Insérer cette série avec l’identifiant 4.
-- Que se passe-t-il ? Pourquoi ?
INSERT INTO Serie(IdS, NomS) VALUES
(4,'Obi-Wan Kenobi');

-- 5) L’acteur Paul Wesley n’est pas italien, mais polonais. Rectifier les données de la base en
-- conséquence.
UPDATE Acteur
SET Nationalite = 'Polonais'
WHERE IdAct = 2;

-- 6) Emilia Clark a décidé de stopper sa carrière. Supprimer cette actrice. Que se passe-t-il ?
-- Pourquoi ?
DELETE FROM Acteur
WHERE IdAct = 5;

-- 7) Modifier les contraintes d’intégrité définies sur la table Joue pour obtenir la suppression des
-- rôles d’un acteur lorsque celui-ci est supprimé de la table Acteur. Supprimer à nouveau l’acteur
-- 5 et vérifier la suppression de ses rôles. Réinsérer cet acteur et ses rôles associés.
ALTER TABLE Joue
DROP CONSTRAINT f_key_IdAct_Joue;

ALTER TABLE Joue
ADD CONSTRAINT f_key_IdAct_Joue FOREIGN KEY (IdAct) REFERENCES Acteur(IdAct) ON DELETE CASCADE;

DELETE FROM Acteur
WHERE IdAct = 5;

ROLLBACK;

-- 8) La série 1 est de genre Fantastique. Faites les modifications nécessaires pour ajouter cette
-- information. Que se passe-t-il pour les autres séries ?
ALTER TABLE Serie
ADD Genre VARCHAR2(50);

UPDATE Serie
SET Genre = ('Fantastique')
WHERE IdS = 1;

-- 9) Modifier le champ nationalité de la table Acteur pour ne conserver que les 3 premières lettres.
-- On souhaite conserver l’information (réduite) pour les acteurs déjà enregistrés. Vérifier la
-- modification du type.


-- 10) Créer la vue VampireDiaries contenant tous les personnages de la série et leurs acteurs
-- respectifs.
--  Vérifier que la vue a bien été créée.
--  Afficher son contenu.


-- 11) Insérer le n-uplet (3, 2, Salvatore, Damon) dans Joue.


-- 12) Afin d’optimiser les temps de réponses, créer un index sur le nom des acteurs.


-- 13) Créer un index similaire pour la vue VampireDiaries. Que se passe-t-il ? Pourquoi ?


-- 14) Insérer les 3 acteurs (10, Harington, Kit, Bri, 32), (11, Brake, Richard, Bri, 54) et (12, Morgan,
-- Joseph, Bri, 38). Vérifier que tout s’est bien passé. Annuler la dernière transaction et vérifier
-- de nouveau.


-- 15) Sans changer l’utilisation de la commande insert, modifier les instructions de la commande 13
-- pour que les acteurs ne disparaissent si on annule la dernière transaction.


-- 16) Faites les changements nécessaires pour que la colonne « Fin » soit désormais de type date.


-- 17) Supprimer l’actrice « Corbero » et vérifier que tout s’est bien passé.


-- 18) En utilisant les tables adéquates du catalogue Oracle, retrouver toutes les contraintes qui ont
-- été définies sur la table Série.


-- 19) De quelles tables êtes-vous propriétaire ?


-- 20) Supprimer la table Joue. Reste-t-il des n-uplets ? La vue VampireDiaries existe-t-elle toujours ?
-- Vérifier toutes vos affirmations.


-- 21) Vider la table Acteur et vérifier que tout s’est bien passé. L’index existe-t-il toujours ?


-- 22) Supprimer la table Acteur. Vérifier que tout s’est bien passé. L’index existe-t-il toujours ?


-- 23) Supprimer la table Série.


-- 24) Créer et remplir à nouveau les trois tables (reprendre la réponse aux 2 premières questions).
-- Créer à nouveau l’index (q12). Quelles sont les contraintes sur la table Acteur et sur la table
-- Joue ? Supprimer la table Acteur, sans supprimer au préalable la table Joue. Qu’en est-il des
-- contraintes et de l’index ?