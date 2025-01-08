setwd("C://Users//natha//Documents//Git//4th-year-Polytech//Regression lineaire//Anova//TP 2.1 ANOVA")
load("canard.Rdata")
attach(canard)

names(canard)
head(canard, 15)
dim(canard)

summary(canard)
levels(alim)
levels(espece)

str(canard)

# --------------------------------
# ANALYSE DESCRIPTIVE
# --------------------------------

library(ggplot2)
ggplot(data = canard, aes(x = alim:espece, y = poids)) +
  geom_boxplot(color = "blue", fill = "red", alpha = 0.2)

# Variante par espèce
ggplot(data = canard, aes(x = alim, y = poids, fill = espece)) +
  geom_boxplot(color = "blue", fill = "red", alpha = 0.2)

# Variante par violin
ggplot(data = canard, aes(x = alim, y = poids, fill = espece)) +
  geom_violin(color = "blue", fill = "red", alpha = 0.2)

# Boxplot avec les fonctions de base de R
boxplot(poids~alim:espece, data = canard, xlab = "alimentation x espece",
        ylab = "poids")


# 1)
# Variable quali : alim et espece
# Variable quanti : poids

# 2)
# Il faut donc effectuer une analyse de la variance à 2 facteurs

# 3)
table(canard$alim, canard$espece)
# Complet équilibré car même effectifs pour chaque combinaison des facteurs alim et espèce

# 4) On peut donc utiliser un modèle avec interaction car le plan est complet
model = lm(poids ~ alim + espece + espece:alim, canard)
summary(model)

library(car)
Anova(model, type = 2)
# Interaction (alim:espece) significative
# Espece non significative => en moyenne sur les observations, les especes sont équivalentes
# Interaction => les deux variables ont une influence sur la réponse
# Il faut composer avec ces deux variables simultanément


# --------------------------------
# ETUDES DES RESIDUS
# --------------------------------

# graphe des résidus
plot(model, 1)
# les résidus ne sont pas extrêment écartés, il n'y a pas de valeur extreme a
# part peut etre l'individu 32

plot(jitter(model$fit), model$res, xlab = "fitted", ylab = "residuals",
     main = "Jittered plot")

# test de levene library(car) Ho : "il y'a pas d'heteroscedasticité"
                            # Ho : "Il y'a homoscédasticité"
# On étudie si la variance dépend des valeurs prédites
# On fait l'hypothèse que la variance des y est la meme quelque soit les y
leveneTest(poids~espece*alim, canard)
# pvalue = 0.68, on considère que l'hypothèse homogénéité des variances
# est raisonnable

# Regardons la normalité des résidus
plot(model, 2)
# avec qqplot
qqPlot(model, main = "QQ plot")

# test de normalité de Shapiro Wilks
# Ho : les résidus sont normaux
shapiro.test(residuals(model))


# -----------------------------------------------------------
# TEST DES EFFETS PRINCIPAUX ET DE L'INTERACTION
# -----------------------------------------------------------
# On étudie quels sont les niveaux qui influent le + la réponse
# Regle : on commence toujours par regarder l'interaction
library(emmeans)
# graphe d'interaction
# La seule chose qui nous intéresse est d'étudier les points du graphe
# et non la différences entre les niveaux
emmip(model, espece ~ alim)
# On voit que le meilleur rendement sera pour le niveau 2 avec l'espece gris
# En fonction de l'alimentation, ce ne sera pas la même espèce de canard qui sera préférée
# C'est la conséquence de l'interaction
# On ne peut pas comparer les facteurs especes sans regarder l'alimentation
emmip(model, alim ~ espece)

# On s'intéresse maintenant à savoir si pour une alimentation donnée, les canards sont équivalents
# si pvalue significative (inférieure au niveau du test par exemple 0.05), alors les écarts
# entre les espèces est significative pour l'alimentation en question
joint_tests(model, by = "alim")
# Et effet de alim en fonction de espece
# si pvalue significative (inférieure au niveau du test par exemple 0.05), alors les écarts
# entre les alimentations est significative pour l'espece en question
joint_tests(model, by = "espece")
# Pour Mulard, pvalue = 0.02 alors l'effet est significatif mais avec un léger doute car
# pas très faible

# emmeans des interactions + comparaison par pair
em = emmeans(model, ~ espece:alim)
em
# La commande pairs permet de comparer les interactions entre elles
pairs(em)
# On s'intéresse aux 2 meilleurs rendements : Gris-alim2 et Rouen-alim3
# pvalue élevée : il n'y a pas de différence significative



# -----------------------------------------------------------
# ERREUR A NE PAS COMMETTRE
# -----------------------------------------------------------
# Si on avait pas mit d'interaction dans le modèle :
modelFaux = lm(poids ~ espece + alim)
Anova(modelFaux, type = 2)
# Les deux pvalues sont élevées : il n'y a pas d'effet significatif pour les deux facteurs

emmip(modelFaux, espece ~ alim)
# Ici la meilleure combinaison est gris alim 3
# Pourtant on a vu que c'était gris alim 2

emmip(modelFaux, alim ~ espece)

