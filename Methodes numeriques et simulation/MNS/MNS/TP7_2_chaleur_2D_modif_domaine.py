import numpy as np
import scipy.sparse as sp
import matplotlib.pyplot as plt
from scipy.sparse.linalg import spsolve

# Definition des fonctions
def u0(x,y):
    return Text + 15*np.sin(np.pi*x)*np.sin(np.pi*y)

def alpha(t):
    return Text

def beta(t):
    return Text

# Definiion des parametres
I = 30
N = 1000
h = 1.0/I
T = 36000
Text = 8
D = 2e-5
deltat = T/N
K = 100

a = 1/h + K
b = -1/h

lambda_ = (deltat*D)/h**2

epsilon = 1e-6

def egal(a,b):
    return abs(a-b)<epsilon

# Schema Euler Implicite
x = np.arange(0,(I+1))*h
y = np.arange(0,(I+1))*h
t = np.arange(0,N)*deltat

offsets = np.array([-1,0,1])
data = [-lambda_*np.ones(I+1), (2*lambda_+1/2)*np.ones(I+1), -lambda_*np.ones(I+1)]

D1 = sp.dia_matrix((data,offsets), shape=(I+1,I+1))
D1 = sp.csc_matrix(D1)
D1[0,0],D1[-1,-1],D1[0,1],D1[-1,-2] = 0,0,0,0

M = sp.eye(I+1,I+1)
M = sp.csc_matrix(M)
M[0,0],M[-1,-1] = 0,0

D = sp.kron(D1,M) + sp.kron(M,D1)

for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        # bord droit
        if i==I or (egal(i,0.3*I) and j<0.5*I-epsilon):
            D[l,l] = a
            D[l,l-1] = b
        # bord haut
        elif j==I:
            D[l,l] = a
            D[l,l-(I+1)] = b
        # bord gauche
        elif i==0 or (egal(i,0.7*I) and j<0.5*I-epsilon):
            D[l,l] = a
            D[l,l+1] = b
        # bord bas
        elif (j==0 and i<0.3*I-epsilon) or (egal(j,0.5*I) and i<0.7*I-epsilon and 0.3*I<i-epsilon) or (j==0 and 0.7*I<i-epsilon):
            D[l,l] = a
            D[l,l+I+1] = b
        elif (j<0.5*I-epsilon) and (i<0.7*I-epsilon and 0.3*I<i-epsilon):
            D[l,:] = 0
            D[l,l] = 1


Uold = np.zeros((I+1)**2)
for i in range(I+1):
    for j in range(I+1):
        l = i + j*(I+1)
        if (j<0.5*I-epsilon) and (i<0.7*I-epsilon and 0.3*I<i-epsilon):
            Uold[l] = Text    
        else:
            Uold[l] = u0(x[i],y[j])

Unew = np.zeros(Uold.shape)
for k in range(N):
    B = np.zeros((I+1)**2)
    for i in range(I+1):
        for j in range(I+1):
            l = i+j*(I+1)
            if (i==I or (egal(i,0.3*I) and j<0.5*I-epsilon)) or (j==I) or (i==0 or (egal(i,0.7*I) and j<0.5*I-epsilon)) or ((j==0 and i<0.3*I-epsilon) or (egal(j,0.5*I) and i<0.7*I-epsilon and 0.3*I<i-epsilon) or (j==0 and 0.7*I<i-epsilon)):
                B[l] = K*Text
            elif (j<0.5*I-epsilon) and (i<0.7*I-epsilon and 0.3*I<i-epsilon):
                B[l] = Text
            else:
                B[l] = Uold[l]
    
    Unew = spsolve(D,B)
    
    Uold = Unew.copy()
    
    print(Unew.reshape(I+1,I+1).min(),Unew.reshape(I+1,I+1).mean(),Unew.reshape(I+1,I+1).max())
    
    if k==0:
        fig = plt.figure(figsize=(8,6))
        im = plt.imshow(Unew.reshape(I+1,I+1), extent = [x.min(), x.max(), y.min(), y.max()])
        plt.title("Température")
        plt.colorbar()
        plt.xlabel(u'x', fontsize=26)
        plt.ylabel(u'y', fontsize=26, rotation=90)
        plt.pause(0.01)
    else:
        if (k%(int(N/300)+1) == 0):
            im.set_array(Unew.reshape(I+1,I+1))
            plt.title(u'Equation de la chaleur 2D. t='+" %1.2f" %(k*deltat), fontsize=52)
            plt.pause(0.01)


