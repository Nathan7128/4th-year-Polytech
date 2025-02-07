setwd("C:\\Users\\natha\\Documents\\Git\\4th-year-Polytech\\Regression lineaire\\Regression logistique\\TP 2.1 Courbe ROC")
getwd()
dir()

library(gridExtra)# pour faire des graphiques multiples
load("intestin.Rdata")
attach(intestin)
names(intestin)
head(intestin,10)
summary(intestin,10)
# albumin : Score de quantit? d'albumine dans le corps.
# tp : score de quantit? totale de prot?ine dans le corps (albumine+globuline).
# totscore ? : score K-G.
# popind : pr?sence ou non d'occlusion intestinale.

# pr?valence (de la table) = nombre de cas sur le nombre total d'individus
cas=table(intestin$popind)
cas
prevalence=cas[2]/(cas[1]+cas[2])
prevalence



# -----------------------
# Analyse descriptive
# -----------------------
library(ggplot2)
library(GGally) # pour utiliser pairs am?lior?
ggpairs(data=intestin,columns=(1:3), aes(color=popind)) +
  ggtitle("Facteurs pr?dictifs de la maladie")
# On voit que "tp" et "alb" sont fortement corr?l?es

# -----------------------
# Mod?lisation
# -----------------------

# Mod?le logistique 
model <- glm(popind ~ alb + tp + totscore, family="binomial"(link="logit"))
summary(model)

# anova donnee des tests de type I
anova(model,test="Chisq")

# Test de type II
library(car)
Anova(model, type="2")

# inversion des deux premi?res variables 
modelbis <- glm(popind ~   tp + alb + totscore, family="binomial"(link="logit"))
anova(modelbis,test="Chisq")

library(MASS)
# selection de variable backward
#AIC
stepAIC(model, k=2,selection="backward")
# BIC : log(length(popind))= nombr d'individus dans la base
stepAIC(model, k=log(length(popind)),selection="backward")

# selection de variable forward
# il faut d?finir le mod?le de d?part , ici mod0
mod0 <- glm( popind ~ 1, family="binomial" (link=logit))
#AIC
modAICF <- stepAIC(mod0,scope=list(upper=model), k=2,selection="forward")
summary(modAICF)
# BIC
stepAIC(mod0,scope=list(upper=model), k=log(length(popind)),selection="forward")

 
# compl?ment
# Autre syntaxe avec poly() mais ne permet pas de faire du choix de mod?le.
modelplus <- glm(popind ~ poly(alb,tp,totscore, degree=2, raw=TRUE), family="binomial"(link="logit"))
summary(modelplus)
stepAIC(modelplus, k=2,selection="backward")
stepAIC(mod0, scope=list(upper=modelplus), k=2,selection="forward")
stepAIC(modelplus, k=log(length(popind)),selection="backward")
# fin du compl?ment


# On retient le mod?le avec alb et totscore
modfinal <- glm(popind ~ alb + totscore, family="binomial" (link=logit))

# analyse en type I
anova(modfinal, test="Chisq")
# analyse en type 2
Anova(modfinal, type=2)


# ----------------------
# Analyse pr?dictive par LOOCV
# ----------------------
library(ROCR) # pour construire des courbes ROC, PRC etc.

# initialisation du vecteur des predictions
score.cv <- rep(0,length(intestin$popind))
# Leave one out cross validation
# cr?ation d'un vecteur contenant les scores pr?dits.
for (i in 1:length(popind)){
  data.train=intestin[-i,]
  data.test=intestin[i,]
  mod <- glm(data=data.train,popind ~ alb + totscore, family="binomial" (link=logit))
  score.cv[i] <- predict(mod,data.test, type="response") 
}
score.cv
 
 
# transformation de popind en num?rique
# !! attention is.numric ne marche pas (rajoute +1 au vecteur)
# et je ne sais as pourquoi
as.numeric(popind)
# il vaut mieux faire  
popindnum <- as.numeric(levels(popind))[popind]
popindnum
# met ensemble les scores (pr?diction) 
# et la valeur r?elle de y (popind)
pred.test <- prediction(score.cv, labels=popindnum)
pred.test
class(pred.test)

?prediction
# Calcul de l'AUC
AUC <- attributes(performance(pred.test, "auc"))$y.values
AUC
AUC %>% unlist


# Calcul de l'AUCPR
AUCPR <- attributes(performance(pred.test, "aucpr"))$y.values
AUCPR
AUCPR %>% unlist



# Cr?ation de la courbe ROC
# calcule la performance 
# tpr=true positive rate  fpr=false positive  rate
# "tpr"="sens", "fpr"= 1-spec
perfROC.cv <- performance(pred.test, measure="tpr", x.measure="fpr") 
# our simplemnet 
perfROC.cv <- performance(pred.test, "tpr", "fpr") 



# courbe ROC
plot(perfROC.cv,window.size=50,col="red")
# affichage des cutoff (test.ce x=taille des caract?res)
plot(perfROC.cv, print.cutoffs.at=seq(0,1,by=0.1),text.cex=1.5,col="red")
  
# avec ggplot
sensibilite=perfROC.cv@y.values[[1]]
specificite=perfROC.cv@x.values[[1]]

ggplot(data = NULL, aes(x = specificite, y=sensibilite))+
  geom_line(color = "red", size = 1.5) +
  geom_abline(slope = 1, intercept = 0, linetype = "dashed", color = "grey") +
  labs(title = "Courbe ROC", x = "sensibilit?", y = "sp?cificit?") +
  theme_minimal()



# Evaluation du sur-apprentissage
# en comparant les courbes ROC obtenues par CV et par ajustement

score.appr <- predict(modfinal, type="response")
pred.appr <- prediction(score.appr, labels=popind)
perfROC.appr <- performance(pred.appr, "tpr", "fpr")
plot(perfROC.appr, col="blue", main="courbe ROC")
plot(perfROC.cv, col="red", add=TRUE)


# courbe PRC
# "prec"="tpr"
# "rec"="ppv"
# La courbe est invers?e : probl?me d'impl?mentation ?
perfPRC.cv <- performance(pred.test, measure="prec", x.measure="rec")
plot(perfPRC.cv, print.cutoffs.at=seq(0,1,by=0.1),text.cex=1.5,colorize=T)
plot(perfPRC.cv, col ="red")
?performance

  

# courbe Lift
# "prec"="tpr"
# "rec"="ppv"
perfLIFT.cv <- performance(pred.test, "lift", "rpp")
plot(perfLIFT.cv, print.cutoffs.at=seq(0,1,by=0.1),text.cex=1.5,colorize=T)
plot(perfLIFT.cv, col ="red")

sort(score.cv)

##########################
# A VOIR PLUS TARD   cv avec caret
library(caret) # pour faire de la validation crois?e

# pour sp?cifier la m?thode que l'on va utiliser dans train (ici du  One Leave-out CV)
train.control <- trainControl(method = "LOOCV")

# calcul des scores par CV (par d?faut avec glm c'est une r?gression logistique)
predmod <- train(popind ~alb+totscore , data=intestin, method="glm", trControl = train.control)

# calcule les scores sur l'?chantillon d'apprentissage et de test
scorecv <- predict(predmod, type="prob") # donne les probas de y=0 et y=1
scorecv[,1]<-NULL  # pour ne garder que la proba de Y=1
head(scorecv)


# met ensemble les scores (pr?diction) et la valeur r?elle de y
predtest <- prediction(scorecv, labels=popind)
# tpr=true positive rate  fpr=false positive  rate
 
# affichage des cutoff (test.ce x=taille des caract?res)
plot(perfcv, print.cutoffs.at=seq(0,1,by=0.1),text.cex=1.5,colorize=T)
plot(perfcv,window.size=50,colorize=F,add=TRUE)
 
 
 