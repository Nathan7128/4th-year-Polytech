setwd('C:\\Users\\natha\\Documents\\Programmation\\Git\\4th-year-Polytech\\Regression lineaire\\Anova\\TP 1.1 ANOVA')
getwd()
dir()

#chargement des donn?es
load('cholesterol.Rdata')
dim(cholesterol)
# visualisation du d?but de la table
head(cholesterol,50)
names(cholesterol)
attach(cholesterol)
# summary permet entre autre de v?rifier qulles variables sont d?clar?es quali ou quanti
summary(cholesterol)
is.factor(trt)
is.factor(response)
is.numeric(response)
# regardons les effectifs par niveau de trt
table(trt)
table(response)
# approche descriptive (data viz)
library(ggplot2)

ggplot(data=cholesterol, aes(y=response, x=trt))+
  geom_boxplot() 

ggplot(cholesterol, aes(y=response, x=trt,colour=trt ,fill=trt))+
  geom_boxplot(alpha=0.5)+ # alpha pour le niveau de transparence 
  geom_point(alpha=0.1)+ # pour visualiser les points
  
  ggplot(cholesterol, aes(y=response, x=trt,colour=trt ,fill=trt))+
  geom_violin(alpha=0.5)+ # alpha pour le niveau de transparence 
  geom_jitter(width=0.25) # pour d?caler l?g?rement les points superpos?s

# ---------------------------
# mod?lisation
# --------------------------
# ANOVA ? un facteur
model <- lm(response ~ trt)
summary(model)

names(model)

# test global du facteur traitement
# attention ? ne pas oublier la majuscule sur dans Anova(...)
# anova(...) existe ausi mais est ? d?conseiller car fait des tests de type I uniquement
library(car)
Anova(model)

# graphe des r?sidus
# avec plot
plot(model,1)
# avec ggplot
base <- ggplot(model, aes(x=fitted(model), y=residuals(model)))
base + geom_point()+geom_smooth()
# avec jitter
base + geom_jitter(width=0.3)

# normalit? des r?sidus
# commande de base
plot(model,2)
# avec ggplot2
ggplot(model)  + 
  geom_qq(aes(sample=scale(residuals(model))))+
  geom_abline(intercept=0, slope=1, color="blue")

# avec la librairie car (donne les r?sidus studentis?s)
library(car)
# qq plot
qqPlot(model, main="QQ Plot") #qq plot for studentized residuals
# test de normalit? de Shapiro Wilks
shapiro.test(residuals(model))

# homog?n?it? des variances
# graphe des r?sidus standardis?s avec plot
plot(model,3)
# et avec gglpot
ggplot(model, aes(x=fitted(model), y=rstandard(model))) + geom_point() 
# test de levene (le plus courant)
library(car)
leveneTest(residuals(model) ~ trt)
# test de fligner-Killeen (test non param?trique robuste ? la non-normalit?)
fligner.test(residuals(model) ~ trt)
#  test de Bartlet (tr?s sensible ? la non-normalit?)
bartlett.test(residuals(model) ~ trt)


# analyse des emmeans
library(emmeans)
effets <- emmeans(model, specs= "trt")
effets
summary(model)

# comparaison des traitements
pairs(effets)
# pour pr?senter les r?sultats sous forme de tableau
# En haut : p values
# sur la diagonale : emmeans
# en bas, differences de emmeans
pwpm(effets)
# graphique des comparaisons
plot(effets, comparisons = TRUE)

# redefinition de la modalit? de r?ference
# Comparaison avec le placebo drugE
# on commence par regarder les niveaux de "trt"
levels(cholesterol$trt)
# la modalit? de r?f?rence est le 1er niveau: 1time
# modification du niveau de r?ference
cholesterol$trt <- relevel(cholesterol$trt, ref="drugE")
# v?rification : le nouveau nivau de r?f?rence apparait en premier
levels(cholesterol$trt)
model2=lm(response ~ trt, data=cholesterol)
# ici les r?sultats sont chang?s var on n'a pas la m?me modalit? de r?f?rence
summary(model2)
# bien s?r, pour les emmeans, cela ne change rien.
emmeans(model, spec="trt")

# test de Dunnett
library(multcomp)
# test d'inf?riorit? de la r?ponse : alternative="less" au lieu de bilat?ral
comp_temoin <- glht(model2, linfct=mcp(trt="Dunnett"), alternative="less")
summary(comp_temoin)
plot(comp_temoin)
par(mar=c(4,7,3,3))
plot(comp_temoin)

