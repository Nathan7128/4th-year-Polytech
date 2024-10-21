## Lancement du Docker Oracle 

----------------

__Pré-requis :__ 
+ Récupérer l'image Docker:
```
	docker pull container-registry.oracle.com/database/free:latest
```
----------------

__Lancer la commande :__
``` 
docker run -d --name oracle -e ORACLE_PWD=admin -e ORACLE_PDB=IMDS4A -v .\Ressources:/opt/oracle/scripts/startup -v .\Ressources:/opt/oracle/scripts/setup container-registry.oracle.com/database/free:latest
```

----------------
__Connexion__
``` 
docker exec -ti oracle sqlplus etu/imds4A@0.0.0.0:1521/IMDS4A

```


docker run -d --name test container-registry.oracle.com/database/free:latest