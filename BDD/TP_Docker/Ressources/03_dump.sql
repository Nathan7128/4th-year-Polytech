set termout off;

Declare
   c int;

BEGIN
   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'ZONE' ;
   IF c = 1  	 THEN 
	Execute immediate 'DROP TABLE ZONE CASCADE CONSTRAINTS';
   END IF;
   
   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'PROVIENT' ;
   IF c = 1     THEN 
   Execute immediate 'DROP TABLE PROVIENT CASCADE CONSTRAINTS';
   END IF;

   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'ESTPLUSGRAND' ;
   IF c = 1     THEN 
   Execute immediate 'DROP TABLE ESTPLUSGRAND CASCADE CONSTRAINTS';
   END IF;

   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'ANIMAL' ;
   IF c = 1     THEN 
   Execute immediate 'DROP TABLE ANIMAL CASCADE CONSTRAINTS';
   END IF;

   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'POISSON' ;
   IF c = 1  	 THEN 
	Execute immediate 'DROP TABLE POISSON CASCADE CONSTRAINTS';
   END IF;

   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'MAMMIFERE' ;
   IF c = 1  	 THEN 
	Execute immediate 'DROP TABLE MAMMIFERE CASCADE CONSTRAINTS';
   END IF;




END ;
/

define choix = &1;

host if [ 2 -eq &choix ]; then imp etu/imds4A@0.0.0.0:1521/IMDS4A file='/opt/oracle/scripts/setup/Base.dmp' fromuser=etugmm touser=etu; fi 

set termout on;
set serveroutput on;
Declare 
  c int;

Begin 
   Select  count(*) into c
   From User_Catalog 
   Where Table_Name = 'PUBLIE' ;
   IF c = 1  	 THEN 
      DBMS_OUTPUT.PUT_LINE('---------------------------');
      DBMS_OUTPUT.PUT_LINE('Base prête à être interogée');
      DBMS_OUTPUT.PUT_LINE('---------------------------');
   Else 
      DBMS_OUTPUT.PUT_LINE('-----------------------');
      DBMS_OUTPUT.PUT_LINE('Base prête à être créée');
      DBMS_OUTPUT.PUT_LINE('-----------------------');    
   End IF;
End;
/

