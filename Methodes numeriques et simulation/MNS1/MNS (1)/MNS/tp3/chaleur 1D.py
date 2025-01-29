import matplotlib.pyplot as plt
import numpy as np
from numpy import linalg as la

I = 100
N = 1000000
h = 1.0/I
T = 2
deltat = T/N

def u(x,t):
    return np.cos(x+t)*np.exp(x-t)
    
def f(x,t):
    return np.exp(x-t)*(np.sin(x+t)-np.cos(x+t))

def alpha(t):
    return u(0,t)


def beta(t):
    return u(1,t)

def u0(x):
    return u(x,0)

print(deltat/h**2)

#Euler explicite
x = np.arange(0,I+1)*h
t=np.arange(0,N)*deltat
Uold= u0(x)
Unew=np.zeros(I+1)

for k in range(1,N):
    Unew[0]=alpha(t[k])
    Unew[I]=beta(t[k])
    for i in range(1,I):
        Unew[i] = Uold[i] + deltat*(f(x[i],t[k-1])+1/(h**2)*(Uold[i+1]-2*Uold[i]+Uold[i-1]))
    Uold = Unew
    
    if(k%(N/10)==0):
        plotlabel = "t = %1.2f"%(k* deltat)
        plt.plot(x, Unew, label=plotlabel, color=plt.get_cmap('copper')(float(k)/N))
print("error", la.norm(Unew-u(x,T), np.inf))
      
plt.xlabel(u'$x$', fontsize=26)
plt.xlabel(u'$T$', fontsize=26, rotation=0)
plt.title(u'Equation de la chaleur 1D')
plt.legend()
plt.show()


    