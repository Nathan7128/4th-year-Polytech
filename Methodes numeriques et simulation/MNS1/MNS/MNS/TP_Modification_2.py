# Arthur Magnier
# Yoan Charpentier

import numpy as np
import scipy.sparse as sp
import matplotlib.pyplot as plt
from scipy.sparse.linalg import spsolve

# Definition des fonctions
def u0(x,y):
    return Text + 15*np.sin(np.pi*x)

# Definition de la fonction vitesse
def v(x,y):
    #return np.exp(-(10-20*y)**2)/1000,0                    # Deplacement horizontal
    ex = np.exp(-(3.6-(4*x-2)**2-(4*y-2)**2)**2)/100       # Rotation dans le sens trigo
    return (y-0.5)*ex,-(x-0.5)*ex

# Definiion des parametres
I = 100
N = 1000
h = 1.0/I
T = 7200
Text = 8
D = 2e-5
deltat = T/N
K = 1e-2

a = 1/h + K     # Coeff a mettre dans la diagonale de D pour les conditions aux limites
b = -1/h        # Coeff a mettre juste avant ou juste apres la diagonale dans D pour conditions aux limites

lambda_ = (deltat*D)/h**2   # Coeff sur la diagonale de D1 pour le produit de Kronecker

epsilon = 1e-6  # Permet de tester les inegalites entre int et float

# Maillage
x = np.arange(0,(I+1))*h
y = np.arange(0,(I+1))*h

# Pour remplir les 3 diagonales de la matrice D1 pour le produit de Kronecker
offsets = np.array([-1,0,1])
data = [-lambda_*np.ones(I+1), (2*lambda_+1/2)*np.ones(I+1), -lambda_*np.ones(I+1)]

D1 = sp.dia_matrix((data,offsets), shape=(I+1,I+1))
D1 = sp.csc_matrix(D1)
D1[0,0],D1[-1,-1],D1[0,1],D1[-1,-2] = 0,0,0,0

M = sp.eye(I+1,I+1)
M = sp.csc_matrix(M)
M[0,0],M[-1,-1] = 0,0

D = sp.kron(D1,M) + sp.kron(M,D1)   # Produit de Kronecker

# Boucle pour l'ajout des vitesses v1 et v2 dans la matrice D
for i in range(1,I):
    for j in range(1,I):
        l = i+j*(I+1)
        V1,V2 = v(x[i],y[j])
        D[l,l-1] += -deltat/(2*h)*V1
        D[l,l+1] += deltat/(2*h)*V1
        D[l,l-(I+1)] += -deltat/(2*h)*V2
        D[l,l+I+1] += deltat/(2*h)*V2
        

# Boucle pour remplir la matrice D pour les conditions aux limites
for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        # Bord droit
        if i==I:
            # Gamma 1
            if 0.4*I<j-epsilon and j<0.6*I-epsilon:
                D[l,:] = 0
                D[l,l] = 1
            # Gamma 2
            else:
                D[l,l] = a
                D[l,l-1] = b
        # Bord gauche
        elif i==0:
            # Gamma 1
            if 0.4*I<j-epsilon and j<0.6*I-epsilon:
                D[l,:] = 0
                D[l,l] = 1
            # Gamma 2
            else:
                D[l,l] = a
                D[l,l+1] = b
        # Bord haut
        elif j==I:
            D[l,l] = a
            D[l,l-(I+1)] = b

        # Bord bas
        elif j==0:
            D[l,l] = a
            D[l,l+I+1] = b

# Remplissage du vecteur U au temps initial
Uold = np.zeros((I+1)**2)
for i in range(I+1):
    for j in range(I+1):
        Uold[i+(I+1)*j] = u0(x[i],y[j])

# Boucle sur le temps
Unew = np.zeros(Uold.shape)
for k in range(N):
    B = np.zeros((I+1)**2)  # Membre de gauche
    for i in range(I+1):
        for j in range(I+1):
            l = i+j*(I+1)
            # Bord Gamma 1
            if (0.4*I<j-epsilon and j<0.6*I-epsilon) and (i==I or i==0):
                B[l] = Text
            # Bord Gamma 2
            elif (j==0) or (j==I) or ((i==0) or (i==I) and (0.6*I<j-epsilon or j<0.4*I-epsilon)):
                B[l] = K*Text
            # Partout ailleurs
            else:
                B[l] = Uold[l]
    
    Unew = spsolve(D,B)
    
    Uold = Unew.copy()
    
    print(Unew.reshape(I+1,I+1).min(),Unew.reshape(I+1,I+1).mean(),Unew.reshape(I+1,I+1).max())
    
    # Affichage pour voir l'evolution
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


