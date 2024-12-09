data(USArrests)
getwd()
setwd("C:\\Users\\natha\\Documents\\GitHub\\4th-year-Polytech\\Machine Learning 2\\TD1")
# write.table(USArrests, "USArrests.csv", row.names=TRUE, sep="t",dec=",", na=" ")
str(USArrests)
resCAH = hclust(dist(USArrests), method = "ward.D2")
plot(resCAH)
K = 3
cl_cah = cuttree(resCAH, K)
