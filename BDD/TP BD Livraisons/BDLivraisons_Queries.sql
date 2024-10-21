-- Sujet TP : Base de données LIVRAISONS (SELECT)



-- 1.  Donner les catégories attribuées aux clients (enlever les doubles).


-- 2.  Donner les noms des clients de catégorie ‘A’.


-- 3.  Donner le nombre de produits existants.


-- 4.  Donner le nombre de produits différents vendus au client 1.


-- 5.  Donner les numéros de clients auxquels le produit 6 a été livré avec une quantité supérieure à 2.


-- 6.  Donner le prix le plus élevé des produits.


-- 7.  Donner le numéro et le libellé du produit le plus cher.


-- 8.  Quels sont les noms des clients commençant par ‘Du’ ?


-- 9.  Quels sont les numéros des clients qui ont été livrés de l’un au moins des produits
--     pris parmi les produits numéro 6 et 33 ?


-- 10. Quels sont les numéros des clients qui ont été livrés des produits de numéro 1 et 6 ?


-- 11. Quels sont les noms et catégories des clients livrés ?


-- 12. Quels sont les produits bon marché (prix inférieur à 30 euros) qui ont été livrés à
--     des clients de la catégorie ‘A’ ?


-- 13. Quels sont les libellés des produits qui n’ont été livrés 
--     qu’à des clients nommés ‘Haddock’ ?


-- 14. Quels sont les libellés des produits qui ont été livrés au client numéro 3 et au client numéro 5 ?


-- 15. Donner le numéro des clients qui ont commandé au moins deux produits différents 
--     (utiliser une auto-jointure).


-- 16. Donner le numéro des clients qui ont commandé au moins deux produits
--     différents mais en même quantité (utiliser une auto-jointure).


-- 17. Donner le libellé des produits qui ont été livrés au moins une fois (utiliser ‘EXISTS’).


-- 18. Donner le libellé des produits qui n’ont pas été livrés (utiliser ‘EXISTS’).


-- 19. Donner pour chaque produit livré, le nombre de fois où il a été livré 
--     (renommer la colonne en Nbre de Livraisons).


-- 20. Quels sont les numéros des clients auxquels on a livré tous les produits ?


-- 21. Quels sont les clients qui ont été livrés de tous les produits coûtant moins 
--     de 30 euros (numéro et nom) ?


-- 22. Donner la quantité moyenne livrée pour les produits faisant l’objet de plus de 2
--     livraisons. Trier les données par ordre décroissant de numéro de produits.


-- 23. Donner le nom du produit qui a été le plus livré et le nombre de livraisons
--     correspondant.


-- 24. Donner le chiffre d’affaire par produit.


-- 25. Pour chaque client (existant dans la table CLIENTS), donner son numéro et son
--     nom, et pour ceux qui ont été livrés, la liste des produits livrés et en quelle
--     quantité. S’il n’y a aucun produit livré à un client, il faudrait quand même afficher
--     le numéro et le nom du client (les autres attributs seront à NULL).


-- 26. Donner les produits intervenant dans la fabrication du produit 40, avec leur
--     niveau dans la hiérarchie et la quantité correspondante.