import matplotlib.pyplot as plt
import numpy as np
from numpy import linalg as la
from scipy.sparse.linalg import spsolve
import scipy.sparse as sp


I = 100
N = 1000
h = 1.0/I
T = 36000
Text = 8
K = 2*10.0**(-5)
deltat = T/N
lamb = deltat/h**2
offsets = np.array([-1,0,1])

x = np.arange(0,I+1)*h
t=np.arange(0,N)*deltat

def u(x,t):
    return Text + 15*np.sin(np.pi*x)
    

def alpha(t):
    return Text


def beta(t):
    return Text

def u0(x):
    return Text + 15*np.sin(np.pi*x)

data2 = [np.ones(I+1)*(-K*lamb), (1+2*lamb*K)*np.ones(I+1), np.ones(I+1)*(-lamb*K)]
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
    b=b*0
    b += Uold
    b[0] = alpha(t[k+1])
    b[I] = beta(t[k+1])
    Unew = spsolve(B,b) 
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
            plt.pause(0.01)



            
