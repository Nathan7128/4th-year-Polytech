set serveroutput on;
Drop table Employe;
Drop table Service;

-- Création de Service 

create table Service(
  NumServ number(4) primary key,
  Intitule varchar(20)
);

-- Création de Empoloye 
create table Employe(
  NumEmp number(4) primary key,
  Nom varchar(20),
  Prenom varchar(20),
  NumServ number(4), 
  constraint FK1_Employe foreign key(NumServ) references Service(NumServ)
);

-- Insertion 
DECLARE
  i NUMBER(4);
BEGIN
  FOR i IN 1..10 LOOP
    insert into Service
    values (i,'Service'||i);
  END LOOP;
  FOR i IN 1..30 LOOP
    insert into Employe
    values (i,'Nom'||i,'Prenom'||i,dbms_random.value(1,10));
  END LOOP;
END;
/

-- Ajout colonne NbEmp
ALTER TABLE Service
ADD NbEmp NUMBER(4);

-- Mise à jour du nombre d'Employe 
CREATE PROCEDURE MAJ_NBEMP IS
  CURSOR liste_services IS SELECT * FROM Service;
  ligne liste_services%ROWTYPE;
  nb_employes number(4);
BEGIN
  FOR ligne IN liste_services LOOP
    select count(NumEmp) into nb_employes 
    from Employe 
    where NumServ = ligne.NumServ;
    update Service 
    set NbEmp = nb_employes
    where NumServ = ligne.NumServ;
  END LOOP;
END;
/

-- Execution de la procédure
BEGIN
  MAJ_NBEMP;
END;
/

-- Trigger 1
CREATE TRIGGER TrigNbEmpl
  AFTER INSERT ON Employe
  FOR EACH ROW
BEGIN
  update Service
  set NbEmp = NbEmp + 1
  where NumServ = :NEW.NumServ;
END; 
/

--Test
INSERT INTO Employe 
VALUES (61,'Nom31','Prenom31',1);


-- Trigger 2
CREATE TRIGGER TrigNbEmpl2
  AFTER DELETE ON Employe
  FOR EACH ROW
BEGIN
  update Service
  set NbEmp = NbEmp - 1
  where NumServ = :OLD.NumServ;
END; 
/

-- Comment le tester ? 


-- Triger 3
CREATE OR REPLACE TRIGGER TrigNbEmplInf10
  BEFORE INSERT ON Employe
  FOR EACH ROW
DECLARE
  Service_Plein EXCEPTION;
  nombre_employes NUMBER(4);
BEGIN
  select NbEmp into nombre_employes
  from Service
  where NumServ = :NEW.NumServ; 
  if (nombre_employes >= 10) then
    raise Service_Plein;      
  end if;       
EXCEPTION
  WHEN Service_Plein 
    THEN DBMS_OUTPUT.PUT_LINE('Service plein !!');  
END;
/

--Test
CREATE OR REPLACE PROCEDURE AJOUT_EMP IS
  i number(4);
BEGIN
  FOR i IN 32..41 LOOP
    insert into Employe
    values (i,'Nom'||i,'Prenom'||i, 1);
  END LOOP;
END;
/


BEGIN
  AJOUT_EMP;
END;
/



