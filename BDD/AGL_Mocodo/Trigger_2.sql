set serveroutput on;
Drop table Test;
Drop table Inspecteur;
Drop table Vin;

-- Création de la base 
CREATE TABLE VIN(
  VNUM NUMBER(2,0) CONSTRAINT PK_VIN PRIMARY KEY,
  VNOM VARCHAR2(30) CONSTRAINT VNOM_NOTNULL NOT NULL,
  CEPAGE VARCHAR2(30));

CREATE TABLE INSPECTEUR(
  INUM NUMBER(2,0) CONSTRAINT PK_INSPECTEUR PRIMARY KEY,
  INOM VARCHAR2(30) CONSTRAINT INOM_NOTNULL NOT NULL);

CREATE TABLE TEST(
  VNUM NUMBER(2,0),
  INUM NUMBER(2,0),
  NOTE NUMBER(2,0) CONSTRAINT NOTE_NOTNULL NOT NULL,
  TDATE DATE,
  CONSTRAINT PK_TEST PRIMARY KEY(VNUM, INUM),
  CONSTRAINT FKVNUM_TEST FOREIGN KEY(VNUM) REFERENCES VIN(VNUM),
  CONSTRAINT FKINUM_TEST FOREIGN KEY(INUM) REFERENCES INSPECTEUR(INUM));


-- Remplissage des tables 

INSERT INTO VIN VALUES(1,'Cave de Macon','Chardonnay');
INSERT INTO VIN VALUES(2,'Merlot','Cabernet Sauvignon');
INSERT INTO VIN VALUES(3,'Pinot Noir','Pinot Noir');

INSERT INTO INSPECTEUR VALUES(1,'Magouille');
INSERT INTO INSPECTEUR VALUES(2,'Intransigeant');
INSERT INTO INSPECTEUR VALUES(3,'Sympa');
INSERT INTO INSPECTEUR VALUES(4,'Cool');

-- Que fait ce trigger ? 
CREATE OR REPLACE TRIGGER VerifCepage
BEFORE INSERT OR UPDATE OF CEPAGE ON VIN FOR EACH ROW
BEGIN
  IF :NEW.CEPAGE = 'Pinot' THEN :NEW.CEPAGE := 'Pinot Noir';
  END IF;
END VerifCepage;
/

-- Insérer le tuple (5, 'Cotes de la Charité', 'Pinot') dans la table VIN.
-- Que se passe-t-il ? Pourquoi ?

-- Modifier le tuple pour mettre Pinot.
-- Vérifier votre modification. 

-- Que fait ce trigger ? 
CREATE OR REPLACE TRIGGER VerifChardonnay
BEFORE INSERT OR UPDATE ON TEST FOR EACH ROW
DECLARE
      V_CEPAGE VARCHAR2(30);
      V_INOM VARCHAR2(30);
BEGIN
  SELECT CEPAGE INTO V_CEPAGE
  FROM VIN
  WHERE VNUM=:NEW.VNUM;
  IF V_CEPAGE='Chardonnay' THEN
    SELECT INOM INTO V_INOM
    FROM INSPECTEUR
    WHERE INUM=:NEW.INUM;
    IF (V_INOM!='Cool' AND V_INOM!='Sympa') THEN
      RAISE_APPLICATION_ERROR(-20000,'Seuls les inspecteurs Cool et Sympa peuvent attribuer une note aux vins Chardonnay.');
    END IF;
  END IF;
END VerifChardonnay;
/

-- Insérer le tuple (1, 2, 8, 15/04/2009) dans la table TEST.
-- Que se passe-t-il ? Pourquoi ?

-- Insérer le tuple (1, 3, 6, 20/04/2009) dans la table TEST.
-- Que se passe-t-il ? Pourquoi ?

-- Nous avons fait une erreur, en fait c'était l'inspecteur 2 qui avait mis la note. 
-- Corriger. Que se passe-t-il ? Pourquoi ?


