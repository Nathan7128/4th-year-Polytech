# Importation des librairies
import numpy as np
from numpy import linalg as la
import scipy.sparse as sp
from scipy.sparse.linalg import spsolve
import matplotlib.pyplot as plt

# Definition des fonctions
def u(x):
    return Text + 15*np.sin(np.pi*x)

def alpha(t):
    return Text

def beta(t):
    return Text


# Definiion des parametres
I = 100
N = 1000
h = 1.0/I
T = 36000
Text = 8
D = 2e-5
deltat = T/N
K = 100

# Schema Euler Implicite
x = np.arange(0,I+1)*h
t = np.arange(0,N)*deltat

a = 1/h + K
b = -1/h
Lambda = (deltat/h**2)*D
v = 10e-4

offsets = np.array([-1,0,1])
data = [-Lambda*np.ones(I+1), (1+2*Lambda)*np.ones(I+1), -Lambda*np.ones(I+1)]

A = sp.dia_matrix((data,offsets), shape=(I+1,I+1))
A = sp.csc_matrix(A)
A[0,0],A[0,1] = a,b
A[-1,-1],A[-1,-2] = a,b

Uold = u(x)
Unew = np.zeros(Uold.shape)

for k in range(N):
    b = np.zeros(I+1)
    b[0] = K*Text
    b[-1] = K*Text
    b[1:-1] += Uold[1:-1]

    Unew = spsolve(A,b)
    Uold = Unew.copy()
    
    if k==0:
        fig, ax = plt.subplots()
        line, = plt.plot(x,Unew) # x et Unew doivent etre de meme dimension
        ax.set_ylim(0.25)
    
    else:
        if (k%(int(N/3000)+1) == 0):
            line.set_ydata(Unew) # Unew doit avoir la meme dimension que precedement
            plt.xlabel(u'$x$', fontsize=24)
            plt.ylabel(u'$Temperature$', fontsize=26, rotation=90)
            plt.title(u'Equation de la chaleur 1D. t='+"%1.2f"%(k*deltat), fontsize=20)
            plt.pause(0.1)


print(f"N = {N} et h = {h}")
print(f"L'erreur est de : {la.norm(Unew-u(x,T),np.inf)}")