setwd("C://Users//natha//Documents//Git//4th-year-Polytech//Regression lineaire//Regression logistique//TP 1.1")
load("beetles.Rdata")
attach(beetles)

names(beetles)
head(beetles, 10)
summary(beetles)


# ----------------------------------------------------
# Etudes descriptives
# ----------------------------------------------------
# Pour avoir le taux de mortalité observé pour chaque observation
beetles$rate = beetles$death/beetles$n
beetles$rate
beetles$n
library(ggplot2)
# Graphique en aiguille
base = ggplot(beetles, aes(x = dose, y = rate))
base + geom_point() + geom_linerange(aes(ymin = 0, ymax = rate))

# histogramme des x (comment elles sont réparties)
ggplot(beetles, aes(x = dose)) + geom_histogram()


# ----------------------------------------------------
# modèle logistique (car les données sont groupées : nb de cas/effectif)
# ----------------------------------------------------
# !!Attention!!
# Il faut présenter les observations sous la forme (nb de "cas", nb de "non cas")

# création de la variable réponse y = (nb de "cas", nb de "non cas")
beetles$y = cbind(beetles$death, beetles$n-beetles$death)
beetles$y
attach(beetles)
model = glm(y ~ dose, family = binomial (link = logit))
# résultats
summary(model)
# Estimation des coeffs : les deux sont significativement différents de 0

# Récupérer les coeffs
param = coef(model)
param

# pour avoir les intervalles de confiance des parametres
confint(model, level = 0.95)

# Interpretation des parametres du modeles
# intercept = logit(p0) ou p0 est le taux de mortalité théorique avec dose = 0
p0 = exp(param[1])/(1 + exp(param[1]))
p0
# dose = log de l'OR correspondant à l'augmentation de +1 de la dose
OR = exp(param[2])
OR
























