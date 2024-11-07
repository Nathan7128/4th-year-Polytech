  

-- Partie 1 : Creation de base de donnees :    
-- Creer les tables correspondantes en prenant en compte les contraintes d’integrite suivantes :
-- Cles primaires, cles etrangeres, tous les attributs doivent etre renseignes, a l’exception 
-- de localisation et capacite. 

-- Remplir les differentes tables avec les n-uplets donnes dans le sujet

-- Partie 2 : Interrogation de base de donnees :    
-- Formuler en SQL les interrogations suivantes

-- REQ 1 : Donner toutes les informations sur les pilotes. 
SELECT *
FROM pilote;

-- REQ 2 : Donner le nom et l’adresse des pilotes.
SELECT plnom, ville
FROM pilote;

-- REQ 3 : Selectionner l’identificateur et le nom de chaque pilote.
SELECT plnum, plnom
FROM pilote;

-- REQ 4 : Quelles sont les villes de depart des differents vols.
SELECT DISTINCT localisation
FROM avion;

-- REQ 5 : Selectionner les noms des pilotes habitant Paris.
SELECT plnom
FROM pilote
WHERE ville = 'PARIS';

-- REQ 6 : Selectionner les noms des pilotes gagnant plus de 25000 €.
SELECT plnom
FROM pilote
WHERE salaire > 25000;

-- REQ 7 : Quels sont les noms des pilotes dont l’adresse est inconnue ?
SELECT plnom
FROM pilote
WHERE ville IS NULL;

-- REQ 8 : Selectionner les avions de nom A310, A320, A330, A340.
SELECT *
FROM avion
WHERE avnom = 'A310' OR avnom = 'A320' OR avnom = 'A330' OR avnom = 'A340';

-- REQ 9 : Quels sont les noms des pilotes gagnant entre 20000 et 25000€ ?
SELECT plnom
FROM pilote
WHERE salaire > 20000 AND salaire < 25000;

-- REQ 10 : Quelles sont les capacites des avions de type Airbus ?
SELECT capacite
FROM avion
WHERE avnom LIKE 'A%';

-- REQ 11 : Quels sont les noms des avions differents de A310, A320, A330, A340 ?
SELECT avnom
FROM avion
WHERE avnom != 'A310' AND avnom != 'A320' AND avnom != 'A330' AND avnom != 'A340';

-- REQ 12 : Quels sont les vols au depart de Nice desservant Paris ?
SELECT *
FROM vol
WHERE villedep = 'NICE' AND villearr = 'PARIS';

-- REQ 13 : Quels sont les vols au depart d’une ville et dont l’heure d’arrivee est inferieure 
-- a une certaine heure (a saisir par l’utilisateur) ?
SELECT *
FROM vol
WHERE villedep = &Ville AND HEUREARR < TO_DATE(&Heure, 'HH24:MI');

-- REQ 14 : Quel est le salaire moyen des pilotes parisiens ?
SELECT AVG(salaire)
FROM pilote
WHERE ville = 'PARIS';

-- REQ 15 : Trouver le nombre de vols au depart de Paris.
SELECT COUNT(*)
FROM vol
WHERE villedep = 'PARIS';

-- REQ 16 : Trouver le nom des pilotes effectuant des vols au depart de Paris sur des Airbus.
SELECT plnom
FROM vol V JOIN 

-- REQ 17 : Quels sont les avions localises dans la meme ville que l’avion numero 3 ?


-- REQ 18 : Quels sont les pilotes dont le salaire est plus eleve que le salaire moyen des pilotes ?


-- REQ 19 : Quels sont les noms des pilotes en service au depart de Paris ?


-- REQ 20 : Quels sont les noms des pilotes niçois qui gagnent plus que tous les pilotes parisiens ?


-- REQ 21 : Donner le nom des pilotes niçois qui gagnent plus qu’au moins un pilote parisien.


-- REQ 22 : Rechercher les pilotes ayant meme adresse et meme salaire que Miranda.


-- REQ 23 : Donner la liste des pilotes parisiens par ordre de salaire decroissant puis par ordre alphabetique des noms.


-- REQ 24 : Quel est le nombre de vols effectues par chacun des pilotes ?


-- REQ 25 : Trouver le nombre de vols par pilote et par avion.


-- REQ 26 : 
-- a-	Donner le nombre de vols par pilote seulement s’il est superieur a 5.
-- b-	Donner le nom des pilotes effectuant au moins 5 vols.


-- REQ 27 : Quels sont les noms des avions de capacite superieure a 250 ou localises a Paris ?


--REQ 28 : 
-- a-	Quels sont les numeros des pilotes pilotant les avions 2 et 4 ?
-- b-	Quels sont les numeros des pilotes pilotant les avions 2 ou 4 ?


-- REQ 29 : Quels sont les numeros des pilotes pilotant l’avion 2 mais jamais le 4 ?


-- REQ 30 :
-- a-	Quels sont les numeros des pilotes qui pilotent tous les avions de la compagnie ?
-- b-	Quels sont les numeros des pilotes qui pilotent tous les avions de type A310 ?


-- REQ 31 : Lister les noms et numeros des avions autres que ceux de type Boeing, qui sont conduits par tous les pilotes ayant un salaire superieur au salaire des pilotes clermontois.


-- REQ 32 : Lister les paires de numeros de pilote (paires inverses et identiques supprimees).

