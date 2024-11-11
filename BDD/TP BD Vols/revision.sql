-- Partie 1 : Creation de base de donnees :    
-- Creer les tables correspondantes en prenant en compte les contraintes d’integrite suivantes :
-- Cles primaires, cles etrangeres, tous les attributs doivent etre renseignes, a l’exception 
-- de localisation et capacite. 

-- Remplir les differentes tables avec les n-uplets donnes dans le sujet

-- Partie 2 : Interrogation de base de donnees :    
-- Formuler en SQL les interrogations suivantes

-- REQ 1 : Donner toutes les informations sur les pilotes. 
SELECT *
FROM PILOTE;

-- REQ 2 : Donner le nom et l’adresse des pilotes.
SELECT PLNOM, VILLE
FROM PILOTE;

-- REQ 3 : Selectionner l’identificateur et le nom de chaque pilote.
SELECT PLNUM, PLNOM
FROM PILOTE;

-- REQ 4 : Quelles sont les villes de depart des differents vols.
SELECT VILLEDEP
FROM VOL;

-- REQ 5 : Selectionner les noms des pilotes habitant Paris.
SELECT PLNOM
FROM PILOTE
WHERE VILLE = 'PARIS';

-- REQ 6 : Selectionner les noms des pilotes gagnant plus de 25000 €.
SELECT PLNOM
FROM PILOTE
WHERE SALAIRE > 25000;

-- REQ 7 : Quels sont les noms des pilotes dont l’adresse est inconnue ?
SELECT PLNOM
FROM PILOTE
WHERE VILLE IS NOT NULL;

-- REQ 8 : Selectionner les avions de nom A310, A320, A330, A340.
SELECT *
FROM AVION
WHERE AVNOM = 'A310'
OR AVNOM = 'A320'
OR AVNOM = 'A330'
OR AVNOM = 'A340';

-- REQ 9 : Quels sont les noms des pilotes gagnant entre 20000 et 25000€ ?
SELECT PLNOM
FROM PILOTE
WHERE SALAIRE >= 20000
AND SALAIRE <= 25000;

-- REQ 10 : Quelles sont les capacites des avions de type Airbus ?
SELECT CAPACITE
FROM AVION
WHERE AVNOM LIKE 'A%';

-- REQ 11 : Quels sont les noms des avions differents de A310, A320, A330, A340 ?
SELECT CAPACITE
FROM AVION
WHERE AVNOM NOT LIKE 'A%';

-- REQ 12 : Quels sont les vols au depart de Nice desservant Paris ?
SELECT *
FROM VOL
WHERE VILLEDEP = 'NICE'
AND VILLEARR = 'PARIS';

-- REQ 13 : Quels sont les vols au depart d’une ville et dont l’heure d’arrivee est inferieure 
-- a une certaine heure (a saisir par l’utilisateur) ?
SELECT *
FROM VOL
WHERE VILLEDEP = &Ville
AND HEUREARR < TO_DATE(&HeureARR, 'HH24:MI');

-- REQ 14 : Quel est le salaire moyen des pilotes parisiens ?
SELECT AVG(SALAIRE)
FROM PILOTE
WHERE VILLE = 'PARIS';

-- REQ 15 : Trouver le nombre de vols au depart de Paris.
SELECT COUNT(*)
FROM VOL
WHERE VILLEDEP = 'PARIS';

-- Création de la vue de la jointure entre les 3 tables
CREATE VIEW join_pl_av_vol AS
SELECT P.PLNUM, P.PLNOM, P.PLPRENOM, P.VILLE, P.SALAIRE, A.AVNUM, A.AVNOM, A.CAPACITE, A.LOCALISATION, V.VOLNUM, V.VILLEDEP,
       V.VILLEARR, V.HEUREARR, V.HEUREDEP
FROM PILOTE P JOIN (AVION A JOIN VOL V ON A.AVNUM = V.AVNUM)
ON P.PLNUM = V.PLNUM;

-- REQ 16 : Trouver le nom des pilotes effectuant des vols au depart de Paris sur des Airbus.
SELECT PLNOM
FROM join_pl_av_vol
WHERE VILLEDEP = 'PARIS'
AND AVNOM LIKE 'A%';

-- REQ 17 : Quels sont les avions localises dans la meme ville que l’avion numero 3 ?
SELECT *
FROM AVION
WHERE LOCALISATION = (SELECT LOCALISATION
                      FROM AVION
                      WHERE AVNUM = 3);

-- REQ 18 : Quels sont les pilotes dont le salaire est plus eleve que le salaire moyen des pilotes ?
SELECT *
FROM PILOTE
WHERE SALAIRE > (SELECT AVG(SALAIRE)
                 FROM PILOTE);

-- REQ 19 : Quels sont les noms des pilotes en service au depart de Paris ?
SELECT PLNOM
FROM PILOTE P
WHERE EXISTS (SELECT *
              FROM VOL V
              WHERE P.PLNUM = V.PLNUM
              AND VILLEDEP = 'PARIS');

-- REQ 20 : Quels sont les noms des pilotes niçois qui gagnent plus que tous les pilotes parisiens ?
SELECT PLNOM
FROM PILOTE
WHERE SALAIRE > ALL (SELECT SALAIRE
                     FROM PILOTE
                     WHERE VILLE = 'PARIS');

-- REQ 21 : Donner le nom des pilotes niçois qui gagnent plus qu’au moins un pilote parisien.
SELECT PLNOM
FROM PILOTE
WHERE SALAIRE > ANY (SELECT SALAIRE
                     FROM PILOTE
                     WHERE VILLE = 'PARIS');

-- REQ 22 : Rechercher les pilotes ayant meme adresse et meme salaire que Miranda.
SELECT *
FROM PILOTE
WHERE VILLE = (SELECT VILLE
               FROM PILOTE
               WHERE PLNOM = 'MIRANDA')
AND SALAIRE = (SELECT SALAIRE
               FROM PILOTE
               WHERE PLNOM = 'MIRANDA')
AND PLNOM != 'MIRANDA';

-- REQ 23 : Donner la liste des pilotes parisiens par ordre de salaire decroissant puis par ordre alphabetique des noms.
SELECT *
FROM PILOTE
WHERE VILLE = 'PARIS'
ORDER BY SALAIRE DESC,
         PLNOM;

-- REQ 24 : Quel est le nombre de vols effectues par chacun des pilotes ?
SELECT PLNUM, COUNT(*)
FROM VOL
GROUP BY PLNUM;

-- REQ 25 : Trouver le nombre de vols par pilote et par avion.
SELECT PLNUM, AVNUM, COUNT(*)
FROM VOL
GROUP BY PLNUM, AVNUM;

-- REQ 26 : 
-- a-	Donner le nombre de vols par pilote seulement s’il est superieur a 5.
-- b-	Donner le nom des pilotes effectuant au moins 5 vols.
SELECT PLNUM, COUNT(*)
FROM VOL
GROUP BY PLNUM
HAVING COUNT(*) > 5;

SELECT PLNOM
FROM join_pl_av_vol
GROUP BY PLNUM, PLNOM
HAVING COUNT(*) > 5;

-- REQ 27 : Quels sont les noms des avions de capacite superieure a 250 ou localises a Paris ?
SELECT AVNOM
FROM AVION
WHERE CAPACITE > 250
OR LOCALISATION = 'PARIS';

--REQ 28 : 
-- a-	Quels sont les numeros des pilotes pilotant les avions 2 et 4 ?
-- b-	Quels sont les numeros des pilotes pilotant les avions 2 ou 4 ?
SELECT J1.PLNOM
FROM join_pl_av_vol J1 JOIN join_pl_av_vol J2
ON J1.PLNUM = J2.PLNUM
WHERE J1.AVNUM = 2
AND J2.AVNUM = 4;

SELECT PLNOM
FROM join_pl_av_vol
WHERE AVNUM = 2
OR AVNUM = 4;

-- REQ 29 : Quels sont les numeros des pilotes pilotant l’avion 2 mais jamais le 4 ?
SELECT PLNUM
FROM join_pl_av_vol
WHERE AVNUM = 2
MINUS
SELECT PLNUM
FROM join_pl_av_vol
WHERE AVNUM = 4;

-- REQ 30 :
-- a-	Quels sont les numeros des pilotes qui pilotent tous les avions de la compagnie ?
-- b-	Quels sont les numeros des pilotes qui pilotent tous les avions de type A310 ?
SELECT PLNUM
FROM join_pl_av_vol
GROUP BY PLNUM
HAVING COUNT(DISTINCT AVNUM) = (SELECT COUNT(*)
                   FROM AVION);

SELECT PLNUM
FROM join_pl_av_vol
WHERE AVNOM = 'A310'
GROUP BY PLNUM
HAVING COUNT(DISTINCT AVNUM) = (SELECT COUNT(*)
                                FROM AVION
                                WHERE AVNOM = 'A310');

-- REQ 31 : Lister les noms et numeros des avions autres que ceux de type Boeing, qui sont conduits par tous les pilotes
-- ayant un salaire superieur au salaire des pilotes clermontois.
SELECT AVNOM, AVNUM
FROM join_pl_av_vol
WHERE PLNUM IN (SELECT PLNUM
                FROM PILOTE
                WHERE SALAIRE > ALL (SELECT SALAIRE
                                     FROM PILOTE
                                     WHERE VILLE = 'CLERMONT'))
AND AVNOM NOT LIKE 'B%'
GROUP BY AVNOM, AVNUM
HAVING COUNT(DISTINCT PLNUM) = (SELECT COUNT(*)
                                FROM PILOTE
                                WHERE SALAIRE > ALL (SELECT SALAIRE
                                                    FROM PILOTE
                                                    WHERE VILLE = 'CLERMONT'));

-- REQ 32 : Lister les paires de numeros de pilote (paires inverses et identiques supprimees).
SELECT COUNT(*)
FROM PILOTE P1, PILOTE P2
WHERE P1.PLNUM < P2.PLNUM;