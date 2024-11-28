# Etude sur les tortues des iles Galapagos
# variables
# Species : Nombre d'especes de tortues trouve dans l'ile
# Endemics : nombre d'especes endemiques (ne se trouvant que sur l'ile
# Elevation : elevation maximale de l'ile en metre
# Nearest : distance de l'ile la plus proche
# Scruz : distance a l'ile de Santa Cruz en km
# Adjacent : The area of the adjacent island (km2)
# Area : surfacede l'ile.
setwd("C:\\Users\\natha\\Documents\\GitHub\\4th-year-Polytech\\Regression lineaire\\TP1")
getwd()
load("gala.Rdata") 
dim(gala)
names(gala)
summary(gala)
head(gala,10)

# ----------------------------------------------
# Analyse descriptive Variable par variable (analyse univariee)
# ----------------------------------------------
ggplot(data=gala,aes(x=Species))+
  geom_histogram(color="blue", fill="red",bins=20)

ggplot(data=gala,aes(x=Endemics))+
  geom_histogram(color="blue", fill="red",bins=20)

ggplot(data=gala,aes(x=Adjacent))+
  geom_histogram(color="blue", fill="red",bins=20)

ggplot(data=gala,aes(x=Species))+
  geom_boxplot(color="blue", fill="red")

# -------------------------
# Analyse descriptive bivariee
# -------------------------
# etude des correlations
cor(gala)



# analyse graphiques deux a deux.
pairs(gala)
# autre syntaxe
plot(gala)

# avec la librairie GGally (li�e � ggplot)
library(GGally)
ggpairs(gala)
# ------------------------------
# Modelisation par regression lineaire multiple
# ------------------------------

model <- lm(Species ~ Area + Elevation + Nearest + Scruz + Adjacent, data=gala)
summary(model)
names(model)
model$coefficients
# ANALYSE DES RESIDUS BRUTS
plot(model,1)
# avec ggplot
base <- ggplot(data=model,aes(x=model$fitted.values, y=model$residuals))+
  xlab("y ajuste")+
  ylab("residus")

base+ geom_point(color="blue")+
  geom_hline(yintercept=0,color="red")

# meme chose avec  le numero des individus et lissage local 
base+ geom_smooth()+
  geom_text(aes(label=row.names(gala)), size=2)
# On remarque qu'il n'y a pas de tendance claire
# Residus standardises
plot(model,3)

# Residus studentises
# avec ggplot
base <- ggplot(data=NULL, aes(x=model$fitted.values, y=rstudent(model)))
base + geom_point()
base+geom_text(aes(label=row.names(datares)), size=2)

# QQPLOT pour verifier graphiquement la nomalite des residus
# avec la commande de base
plot(model,2)
# avec la library car
library(car)
qqPlot(model, main="QQ Plot") #qq plot for studentized residuals




# Choix du meilleur modele  par selection de variables.
library(MASS)
# k=2 car c'est le AIC
resAIC=stepAIC(model, k=2,direction="backward")
summary(resAIC)


# procedure Forward
#  il faut definir le modele initial, 
# ici on prend le modele sans variables
modelinitial <- lm(Species ~ 1 , data=gala)
resAICf=stepAIC( modelinitial, Species ~ Area + Elevation + Nearest + Scruz + Adjacent, k=2, direction="forward")
summary(resAICf)

# BIC
resBIC=stepAIC(model,k=log(nrow(gala)),direction="backward")
summary(resBIC)

# Retenons le modele avec uniquement les deux variables  Elevation et Adjacent
# et testons s'ils sont differents

# D'abord, on definit le sous-modele qu'on veut tester
model0<-lm(Species~Elevation+Adjacent, data=gala)
summary(model0)

# On teste si le modele avec uniquement les deux variables ajuste aussi bien qu'avec toutes les variables
# Ensuite on fait le test de Fisher de comparaison de modeles
anova(model0,model)
# La p-value n'est pas significative, on peut donc valider le sous-modele
# comme etant aussi explicatif que le grand modele




# suppression des obs Santa Cruz Pinta et Isabela
supp <- c("SantaCruz", "Pinta", "Isabela")
# selection des obs autres que ces trois
select <-!(row.names(gala) %in% supp)
select
gala2 <- gala[select,]
attach(gala2)
dim(gala)
dim(gala2)

model2=lm(Species ~ Elevation+Adjacent, data=gala2)
summary(model2)
coef(model2)
coefficients(model2)





# predire Species sachant Elevation=50 et Adjacent=100
# ou Elevation = 100 et Adjacent= 200
# creation de la nouvelle table contenant les valeus a predires
newdata <- data.frame(Elevation=c(50,100), Adjacent=c(100,200))
newdata
predict(model2, newdata)
# intervalle de prediction
predict(model2, newdata, interval="predict", level=0.90)


# intervalle de prediction
predict(model2, newdata, interval="confidence", level=0.90)




















