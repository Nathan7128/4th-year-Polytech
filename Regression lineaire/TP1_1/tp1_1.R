setwd("C:\\Users\\natha\\Documents\\GitHub\\4th-year-Polytech\\Regression lineaire\\TP1")
getwd()
dir()

load("stat500.Rdata")
names(stat500)
head(stat500, 10)

stat500$midterm
# permet de définir par défaut la table stat500
attach(stat500)

midterm

# examen univarié de la table
summary(stat500)
hist(midterm)
hist(final, col = "blue")

# même chose avec ggplot
library(ggplot2)
ggplot(data = stat500, aes(x = midterm)) + geom_histogram(color = "blue", fill = "red", bins = 20)

# examen bivarié de la table
plot(stat500)
# avec GGally (utilise ggplot2)
library(GGally)
ggpairs(stat500)



# ----------------
# GRAPHIQUE DES DONNÉES
# ----------------
plot(final~midterm, data = stat500)
# meme chose avec ggplot
base = ggplot(data = stat500, aes(x = midterm, y = final))
base + geom_point(color = "blue")

# en affichant le numero des individus plutot que des points
base + geom_text(aes(label = row.names(stat500)), size = 2, color = "red")



# ----------------
# REGRESSION LINEAIRE
# ----------------
model = lm(data = stat500, final~midterm)
summary(model)

# intervalle de confiance des coeffs
confint(model)
confint(model, level = 0.9)



# ----------------
# ETUDE DES RESIDUS
# ----------------
# graph des residus (par defaut)
plot(model, 1)

# avec la library car
library(car)
residualPlot(model)

# avec ggplot (beaucoup mieux)
ggplot(data = NULL, aes(x = fitted(model), y = residuals(model))) + xlab("y prédit") +
  ylab("résidus") + geom_abline(slope = 0, intercept = 0, color = "red") + geom_point(color = "blue")



# ----------------
# Normalité des résidus
# ----------------
# analyse visuelle, QQ plot
plot(model, 2)
# qq-plot avec ggplot
# la fonction scale permet de centrer réduire les données
ggplot(model) + geom_qq(aes(sample = scale(residuals(model))), color = "blue") +
  geom_abline(intercept = 0, slope = 1)
# avec la library car
qqPlot(model, main = "QQ plot")



# ----------------
# nuage de points avec la droite de regression
# ----------------
ggplot(data = stat500, aes(x = midterm, y = final)) + geom_point(size = 0.7) +
  geom_smooth(method = lm, level = 0.95)



# ----------------
# Intervalle de prediction
# ----------------
# intervalle de prediction de la note finale pour midterm
newdata = data.frame(midterm = c(10, 20, 22))
newdata

predict(model, newdata, interval = "confidence", level = 0.9)
# intervalle d'estimation de la moyenne de prediction
pred = predict(model, newdata, interval = "confidence", level = 0.9)
pred
# on rajoute les individus à prédire
cbind(midterm = newdata$midterm, pred)

# intervalle de prédiction
pred = predict(model, newdata, interval = "predict", level = 0.9)
cbind(midterm = newdata$midterm, pred)










