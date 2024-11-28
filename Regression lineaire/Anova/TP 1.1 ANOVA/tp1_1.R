setwd("C:\\Users\\natha\\Documents\\GitHub\\4th-year-Polytech\\Regression lineaire\\Anova\\TP 1.1 ANOVA")

load("cholesterol.Rdata")
dim(cholesterol)

# visualisation au début de la table
head(cholesterol, 50)
names(cholesterol)
attach(cholesterol)

summary(cholesterol)
is.factor(trt)
is.factor(response)
is.numeric((response))

# regardons les effectifs par niveau de traitement