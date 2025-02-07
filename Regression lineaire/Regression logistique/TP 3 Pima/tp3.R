setwd("C:\\Users\\natha\\Documents\\Git\\4th-year-Polytech\\Regression lineaire\\Regression logistique\\TP 3 Pima")
getwd()
dir()

load("pima.Rdata")

names(pima)
head(pima, 10)
summary(pima)
pima$test = as.factor(pima$test)
summary(pima)
str(pima)

# Prévalence
a = table(pima$test)
a
prevalence = a[2]/(sum(a))
prevalence

# Variable age
summary(pima$age)
hist(pima$age)

# Nettoyage des données
pima$diastolic[pima$diastolic == 0] = NA
pima$glucose[pima$glucose == 0] = NA
pima$triceps[pima$triceps == 0] = NA
pima$insulin[pima$insulin == 0] = NA
pima$bmi[pima$bmi == 0] = NA


summary(pima)

# Premier modèle de Reg Log
result = glm(test ~ diastolic + glucose + triceps + insulin + bmi + diabetes,
             family = binomial (link = logit), data = pima)

summary(result)

# On décide d'enlever "insuline"
result = glm(test ~ diastolic + glucose + triceps + bmi + diabetes,
             family = binomial (link = logit), data = pima)
summary(result)

# Corrélation entre les variables
library(ggplot2)
library(GGally)
ggpairs(data = pima, columns = (1:8), aes(color = test))

# Sélection de variables avec le critère AIC

library(MASS)

result = glm(test ~ diastolic + glucose + triceps + insulin + bmi + diabetes,
             family = binomial (link = logit), data = pima)

resAIC = stepAIC(result, direction = "backward", trace = TRUE)

# Retirer les lignes avec des valeurs NA manquantes
pima2 = na.omit(pima)

result2 = glm(test ~ diastolic + glucose + triceps + insulin + bmi + diabetes,
             family = binomial (link = logit), data = pima2)

resAIC = stepAIC(result2, direction = "backward", trace = TRUE)

summary(resAIC)

# On créé une nouvelle table avec les variables gardées afin de supprimer les valeurs NA
# uniquement pour ces variables

pima3 = pima[, c(2, 6, 7, 9)]
head(pima3)
pima4 = na.omit(pima3)

result3 = glm(formula = test ~ glucose + bmi + diabetes, family = binomial(link = logit), 
              data = pima4)
summary(result3)

# Graphe des résidus
plot(result3, 3)

# Odd ratios
OR = exp(result3$coef)
OR

# Intervalle de confiance
IC = confint(result3, level = 0.95)
IC






















