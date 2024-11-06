setwd("C:/Users/natha/Documents/GitHub/4th-year-Polytech/Regression lineaire/TP1_2")

load("gala.Rdata")
dim(gala)
names(gala)
head(gala, 10)
summary(gala)



# ----------------
# analyse descriptive bivariée
# ----------------
cor(gala)

# analyse graphique 2 à 2
pairs(gala)
# autre syntaxe
plot(gala)

# avec la librairie GGally
library(GGally)
ggpairs(gala)



# ----------------
# modelisation par regression lineraire multiple
# ----------------
model = lm(Species ~ Area + Elevation + Nearest + Scruz + Adjacent, data = gala)
summary(model)
names(model)
model$coefficients
# analyse des résidus brutes
plot(model, 1)
# avec ggplot
base = ggplot(data = model, aes(x = model$fitted.values, y = model$residuals)) +
  xlab("y ajusté") + ylab("résidus")
base + geom_point(color = "blue") + geom_hline(yintercept = 0, color = "red")
# meme chose avec le numéro des individus et le lissage local
base + geom_smooth() + geom_text(aes(label = row.names(gala)), size = 2)











