import matplotlib.pyplot as plt
import numpy as np
from numpy import linalg as la
from scipy.sparse.linalg import spsolve
import scipy.sparse as sp


I = 5
N = 100
h = 1.0/I
T = 2
deltat = T/N
lamb = deltat/h**2
offsets = np.array([-1,0,1])

x = np.arange(0,I+1)*h
t=np.arange(0,N)*deltat

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

data2 = [np.ones(I+1)*(-lamb), (1+2*lamb)*np.ones(I+1), np.ones(I+1)*(-lamb)]
B = sp.dia_matrix((data2,offsets), shape=(I+1, I+1))
B = sp.csc_matrix(B)
B[0,0]=1
B[0,1]=0
B[I,I]=1
B[I,I-1]=0


b = np.zeros(I+1)


Uold= u0(x)
Unew=np.zeros(I+1)

for k in range(0,N-1):
    b[0] = alpha(t[k])
    b[I] = beta(t[k])
    
    for i in range(1,I):
        b[i]=deltat*f(x[i],t[k])
    b += Uold
    b[0] = alpha(t[k+1])
    b[I] = beta(t[k+1])
    Unew = spsolve(B,b) 
    Uold = Unew.copy()
    

    
    if (k%(N/10) == 0):
        plotlabel = "t = %1.2f" %(k*deltat)
        plt.plot(x, Unew, label=plotlabel, color=plt.get_cmap('copper')(float(k)/N))

plt.xlabel(u'$x$', fontsize=26)
plt.ylabel(u'$T$', fontsize=26, rotation=0)
plt.title(u'Equation de la chaleur en 1D')
plt.legend()

print(f"N = {N} et h = {h}")
print(f"L'erreur est de : {la.norm(Unew-u(x,T),np.inf)}")
            
