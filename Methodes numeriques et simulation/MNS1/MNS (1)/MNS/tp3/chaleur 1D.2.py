import matplotlib.pyplot as plt
import numpy as np



I = 5
N = 100
h = 1.0/I
T = 2
deltat = T/N

    
def f(x,t):
    return 50*np.exp(-50*(x-0.75)**2)


print(deltat/h**2)

#Euler explicite
x = np.arange(0,I+1)*h
t=np.arange(0,N)*deltat
Uold= 5*np.exp(-10*(x-0.5)**2)
Unew=np.zeros(I+1)



for k in range(0,N-1):
    Unew[0]=0
    Unew[I]=0
    for i in range(1,I):
        Unew[i] = Uold[i] + deltat*(f(x[i],t[k])+1/(h**2)*(Uold[i+1]-2*Uold[i]+Uold[i-1])+(1/h)*(Uold[i+1]-Uold[i-1]))
    Uold = Unew
    
    if k==0:
        fig, ax = plt.subplots()
        line, = plt.plot(x,Unew)
        ax.set_ylim(0,5)
    else :
        if(k%(int(N/3000)+1)==0):
            line.set_ydata(Unew)
            plt.xlabel(u'$x$', fontsize=26)
            plt.ylabel(u'$température$', fontsize=26, rotation=90)
            plt.title(u'Equation de la chaleur 1D. t='+"%1.2f"%(k*deltat), fontsize=52)
            plt.pause(0.5)
            
            
            
    
    