import numpy as np
from scipy.sparse.linalg import spsolve
from scipy.sparse import dia_matrix, csc_matrix


# Solution
def u(x) :
    return np.exp(3*x)


# Données
liste_N = 10*2**(np.arange(5))
liste_norme = []

for N in liste_N :
    h = 1.0/N
    
    def f(x) :
        return -3*np.exp(3*x)
    
    l = -(1/h**2 + 1/h)
    d = 2/h**2
    v = -1/h**2 + 1/h
    
    a = 1
    b = 3*np.exp(3)
    
    
    # Matrices méthode 1
    data = [l*np.ones(N - 1), d*np.ones(N - 1), v*np.ones(N - 1)]
    
    offsets = [-1, 0, 1]
    
    A = dia_matrix((data, offsets), shape = (N - 1, N - 1))
    
    A = csc_matrix(A)
    
    A[-1, -1] = 1/h**2 + 1/h
    
    x = np.arange(1, N)/N
    
    F = f(x)
    
    G = np.zeros(N - 1)
    G[0] = -l*a
    G[-1] = b/h - b
    
    
    # Résolution du système
    U = spsolve(A, F + G)
    
    
    
    # Matrices méthode 2
    # data = [l*np.ones(N + 1), d*np.ones(N + 1), v*np.ones(N + 1)]
    
    # offsets = [-1, 0, 1]
    
    # A = dia_matrix((data, offsets), shape = (N + 1, N + 1))
    
    # A = csc_matrix(A)
    # A[[0, -1], [0, -1]] = 1
    # A[[0, -1], [1, -2]] = 0
    
    # x = np.linspace(0, 1, N + 1)
    
    # F = f(x)
    # F[0] = a
    # F[-1] = b
    
    
    # # Résolution du système
    # U = spsolve(A, F)
    
    
    
    
    # Affichage résultats
    norme = np.linalg.norm(U - u(x), np.inf)
    liste_norme.append(norme)
    print("Norme :", norme)
    if len(liste_norme) > 1 :
        print(liste_norme[-2]/liste_norme[-1], "\n")
