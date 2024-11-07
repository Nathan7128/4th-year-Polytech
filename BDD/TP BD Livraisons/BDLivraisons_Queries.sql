-- Sujet TP : Base de données LIVRAISONS (SELECT)



-- 1.  Donner les catégories attribuées aux clients (enlever les doubles).
SELECT DISTINCT Classe
FROM CategoriesClt;

-- 2.  Donner les noms des clients de catégorie ‘A’.
SELECT nomclt
FROM clients
WHERE categorie = 'A';

-- 3.  Donner le nombre de produits existants.
SELECT COUNT(*)
FROM produits;

-- 4.  Donner le nombre de produits différents vendus au client 1.
SELECT COUNT(DISTINCT numproduit)
FROM livraisons
WHERE numclt = 1;

-- 5.  Donner les numéros de clients auxquels le produit 6 a été livré avec une quantité supérieure à 2.
SELECT numclt
FROM livraisons
WHERE numproduit = 6
GROUP BY numclt
HAVING MAX(quantite) > 2;

-- 6.  Donner le prix le plus élevé des produits.
SELECT MAX(prixbrut)
FROM produits ;

-- 7.  Donner le numéro et le libellé du produit le plus cher.
SELECT numproduit, libelle
FROM produits
WHERE prixbrut = (SELECT MAX(prixbrut) FROM produits) ;

-- 8.  Quels sont les noms des clients commençant par ‘Du’ ?
SELECT nomclt
FROM clients
WHERE nomclt LIKE 'Du%' ;

-- 9.  Quels sont les numéros des clients qui ont été livrés de l’un au moins des produits
--     pris parmi les produits numéro 6 et 33 ?
SELECT DISTINCT numclt
FROM livraisons
WHERE numproduit = 6 OR numproduit = 33;

-- 10. Quels sont les numéros des clients qui ont été livrés des produits de numéro 1 et 6 ?
SELECT numclt
FROM livraisons
WHERE numproduit = 1
INTERSECT
SELECT numclt
FROM livraisons
WHERE numproduit = 6;

-- 11. Quels sont les noms et catégories des clients livrés ?
SELECT DISTINCT C.nomclt, C.categorie
FROM clients C JOIN livraisons L
ON C.numclt = L.numclt ;


-- 12. Quels sont les produits bon marché (prix inférieur à 30 euros) qui ont été livrés à
--     des clients de la catégorie ‘A’ ?
SELECT P.numproduit, P.libelle, P.prixbrut
FROM produits P JOIN
    (SELECT * 
    FROM livraisons L JOIN clients C
    ON L.numclt = C.NumClt
    WHERE C.categorie = 'A') CL
ON P.numproduit = CL.numproduit
WHERE P.prixbrut < 30;

-- 13. Quels sont les libellés des produits qui n’ont été livrés 
--     qu’à des clients nommés ‘Haddock’ ?
SELECT libelle
FROM produits P JOIN
    (SELECT L.numproduit
    FROM clients C JOIN livraisons L
    ON C.numclt = L.numclt
    WHERE C.nomclt = 'Haddock'
    GROUP BY L.numproduit
    HAVING COUNT(DISTINCT L.numclt) = 1) CL
ON P.numproduit = CL.numproduit ;

-- 14. Quels sont les libellés des produits qui ont été livrés au client numéro 3 et au client numéro 5 ?
SELECT Libelle
FROM produits P JOIN 
    (SELECT numproduit
    FROM livraisons
    WHERE numclt = 3
    INTERSECT
    SELECT numproduit
    FROM livraisons
    WHERE numclt = 1) L
ON P.numproduit = L.numproduit ;

-- 15. Donner le numéro des clients qui ont commandé au moins deux produits différents 
--     (utiliser une auto-jointure).
SELECT DISTINCT L1.numclt
FROM livraisons L1 JOIN livraisons L2
ON L1.numclt = L2.numclt
WHERE L1.numproduit != L2.numproduit ;

-- 16. Donner le numéro des clients qui ont commandé au moins deux produits
--     différents mais en même quantité (utiliser une auto-jointure).
SELECT DISTINCT L1.numclt
FROM livraisons L1 JOIN livraisons L2
ON L1.numclt = L2.numclt
WHERE L1.numproduit != L2.numproduit AND L1.quantite = L2.quantite ;

-- 17. Donner le libellé des produits qui ont été livrés au moins une fois (utiliser ‘EXISTS’).
SELECT libelle
FROM produits P
WHERE EXISTS (SELECT *
    FROM livraisons L
    WHERE P.numproduit = L.numproduit
    GROUP BY L.numproduit
    HAVING COUNT(*) >= 2) ;

-- 18. Donner le libellé des produits qui n’ont pas été livrés (utiliser ‘EXISTS’).
SELECT libelle
FROM produits P
MINUS
(SELECT libelle
FROM produits P
WHERE EXISTS (SELECT *
              FROM livraisons L
              WHERE P.numproduit = L.numproduit)) ;

-- 19. Donner pour chaque produit livré, le nombre de fois où il a été livré 
--     (renommer la colonne en Nbre de Livraisons).
SELECT numproduit, COUNT(*) "Nbre de Livraisons"
FROM livraisons
GROUP BY numproduit ;

-- 20. Quels sont les numéros des clients auxquels on a livré tous les produits ?
SELECT numclt 
FROM livraisons 
GROUP BY numclt 
HAVING COUNT(DISTINCT numproduit) = (SELECT COUNT(*)
                                     FROM produits) ;

-- 21. Quels sont les clients qui ont été livrés de tous les produits coûtant moins 
--     de 30 euros (numéro et nom) ?
SELECT C.numclt, C.nomclt
FROM clients C JOIN
    (SELECT L.numclt
    FROM livraisons L
    WHERE L.numproduit IN (SELECT numproduit
                           FROM produits P1
                           WHERE P1.prixbrut < 30)
    GROUP BY L.numclt 
    HAVING COUNT(DISTINCT L.numproduit) = (SELECT COUNT(*)
                                            FROM produits P2
                                            WHERE P2.prixbrut < 30)) PL
ON C.numclt = PL.numclt;

-- 22. Donner la quantité moyenne livrée pour les produits faisant l’objet de plus de 2
--     livraisons. Trier les données par ordre décroissant de numéro de produits.
SELECT numproduit, AVG(quantite)
FROM livraisons
GROUP BY numproduit
HAVING COUNT(*) > 2
ORDER BY numproduit DESC;

-- 23. Donner le nom du produit qui a été le plus livré et le nombre de livraisons
--     correspondant.
SELECT P.libelle, L.countliv
FROM produits P JOIN (SELECT numproduit, COUNT(*) countliv
                      FROM livraisons
                      GROUP BY numproduit
                      HAVING COUNT(*) = (SELECT
                                         MAX(COUNT(*))
                                         FROM livraisons
                                         GROUP BY numproduit)) L
ON P.numproduit = L.numproduit;

-- 24. Donner le chiffre d’affaire par produit.
SELECT P.numproduit, L.sommeqt * P.prixbrut
FROM produits P JOIN (SELECT numproduit, SUM(quantite) sommeqt
                      FROM livraisons
                      GROUP BY numproduit) L
ON P.numproduit = L.numproduit;

-- 25. Pour chaque client (existant dans la table CLIENTS), donner son numéro et son
--     nom, et pour ceux qui ont été livrés, la liste des produits livrés et en quelle
--     quantité. S’il n’y a aucun produit livré à un client, il faudrait quand même afficher
--     le numéro et le nom du client (les autres attributs seront à NULL).
SELECT C.numclt, C.nomCLT, L.numproduit, L.quantite
FROM clients C LEFT JOIN livraisons L
ON C.numclt = L.numclt;

-- 26. Donner les produits intervenant dans la fabrication du produit 40, avec leur
--     niveau dans la hiérarchie et la quantité correspondante.