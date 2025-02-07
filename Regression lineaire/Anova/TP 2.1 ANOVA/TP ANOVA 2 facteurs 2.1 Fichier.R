setwd('C:\\Users\\natha\\Documents\\Programmation\\Git\\4th-year-Polytech\\Regression lineaire\\Anova\\TP 2.1 ANOVA')
getwd()

dir()
load("canard.Rdata")
attach(canard)

names(canard)
#poids = poids du foie du canard
# alim= choix de l'alimentation'dose de espece (qualitatif)
# espece = espece de canard
head(canard,15)
dim(canard)

summary(canard)
levels(alim)
levels(espece)
#permet de voir si c'est un plan complet �quilibr�.
table(alim,espece)

# pour voir le caract�re des variables
str(canard)
# ---------------------------
# Analyse descriptive
# ---------------------------

library(ggplot2)
ggplot(data=canard, aes(x=alim:espece,y=poids)) + 
  geom_boxplot()  # alpha= taux de transparence
ggplot(data=canard, aes(x=alim:espece,y=poids)) + 
  geom_boxplot(color="blue",fill="red",alpha=0.2)  # alpha= taux de transparence
# variante par espece
ggplot(canard, aes(x=alim,y=poids,fill=espece)) +
  geom_boxplot(color="blue",alpha=0.2)
# variante par violin (plus pr�cis qu boxplot)
ggplot(canard, aes(x=alim,y=poids,fill=espece)) +
  geom_violin(color="blue",alpha=0.2)
# boxplot avec les fonctions de base R
boxplot(poids~alim:espece,
        data = canard,
        xlab = "alimentation x esp�ce",
        ylab = "poids")

# ---------------------------
# mod�le d'ANOVA
# ---------------------------
model <- lm(poids ~ espece + alim + espece:alim)
# autre syntaxe equivalent model <- lm(poids ~ espece * alim)
summary(model)
levels(alim)
levels(espece)
# ---------------------------
# mod�le d'ANOVA
# ---------------------------

library(car)
model <- lm(poids ~ espece:alim + alim + espece)
# Attention : ne pas utiliser la commande anova()
# autre syntaxe equivalent model <- lm(poids ~ espece * alim)
Anova(model)
levels(alim)
levels(espece)
# ---------------------------
# Etude des r�sidus
# ---------------------------
# graphe des r�sidus
plot(model,1)

plot(jitter(model$fit),model$res,xlab="Fitted",ylab="Residuals",main="Jittered plot")
library(car)
# test de levene library(car)  Ho: "il n'y a pas h�t�roscedasticit� "
leveneTest(poids~espece*alim,data=canard)


# regardons la normalit� des r�sidus
plot(model,2)
library(car)
# qq plot
qqPlot(model, main="QQ Plot") #qq plot for studentized resid
# test de normalit� de Shapiro Wilks
# H0 : les r�sidus sont normaux
shapiro.test(residuals(model))

# ---------------------------
# test des effets principaux et de l'interaction
# ---------------------------
# R�gle : on commence toujours par regarder l'interaction.
# Si l'interaction est significative, on ne regarde pas les effets principaux
# Si l'interaction n'est pas significative, on peut regarder les effets principaux
# Ici l'interaction est significativei,i.e. il y a interaction entre les deux facteurs

# ------------------------------------------------
# �tude d�taill�e des effets, graphe d'interaction
# ------------------------------------------------

library(emmeans)
# graphe d'interaction
emmip(model, espece ~ alim) 
emmip(model, alim ~ espece)  # graphe permut�
# meilleure combinaison canard=gris et alimentation = 2

# emmeans des interactions  + comparaison par paires 
# emmeans(model, pairwise ~ espece:alim)

# meilleure combinaison canard=gris et alimentation = 2
# mais canard rouen et alimentation 3 n'est pas significativement diff�rent.

# --------------------------------------------------------
# effet global d'un facteur par niveau de l'autre facteur
# --------------------------------------------------------
# effet de espece en fonction de alim
joint_tests(model, by = "alim")
# effet de alim en fonction de espece
joint_tests(model, by = "espece")

# -------------------------
# Erreur � ne pas commettre
# -------------------------
# Si on n'avait pas mis d'interaction dans le mod�le :
modelFaux <- lm(poids ~ espece + alim)
# autre syntaxe equivalent model <- lm(poids ~ espece * alim)
emmip(modelFaux, espece ~ alim) 
# ici la meilleure combinaison est canard gris alim 3
# alors qu'on a vu que c'�tait gris, alim2


Anova(modelFaux)