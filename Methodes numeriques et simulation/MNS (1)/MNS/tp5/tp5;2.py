import numpy as np
import scipy.sparse as sp
from scipy.sparse.linalg import spsolve
from numpy import linalg 
import scipy.linalg
offsets = np.array([-1, 0, 1])
I = 3
h = 1.0/I


def f(x, y):
    return 2*np.pi**2*np.sin(np.pi*x)*np.sin(np.pi*y)


def g(x, y):
    return 0


def u(x, y):
    return np.sin(np.pi*x)*np.sin(np.pi*y)


data1 = [np.ones(I+1)*(-1/(h**2)), np.ones(I+1)*(2/(h**2)), np.ones(I+1)*(-1/(h**2))]
D1 = sp.dia_matrix((data1, offsets), shape=(I+1, I+1))
D1 = sp.csc_matrix(D1)

a=1/h
D1[0, 0] = 1
D1[I, I] = 1
D1[0, 1] = 0
D1[I, I - 1] = 0

M = sp.eye(I+1, I+1)
M = sp.csc_matrix(M)
M[0, 0] = 0
M[I, I] = 0

D = sp.kron(D1, M)+sp.kron(M, D1)
D = sp.csc_matrix(D)
D[0, 0] = 1
D[I, I] = 1
D[-1, -1] = 1
D[I*(I+1), I*(I+1)] = 1

for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        # bord droit
        if i==I:
            D[l,l] = a
            D[l,l-1] = a
        # bord haut
        elif j==I:
            D[l,l] = a
            D[l,l-(I+1)] = a
        # bord gauche
        elif i==0:
            D[l,l] = a
            D[l,l+1] = a
        # bord bas
        elif j==0:
            D[l,l] = a
            D[l,l+I+1] = a

D_dense = D.toarray() 
print("Matrice D1 (dense) :")
print(D_dense)
print("Shape de D1 :", D.shape)

x = np.arange(0,I+1)*h
y = np.arange(0,I+1)*h
B = np.zeros((I+1)**2)

for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        if i==0 or i==I or j==0 or j==I:
            B[l] = g(x[i],y[j])
        else:
            B[l] = f(x[i],y[j])

Usolve = spsolve(D,B)

U = np.zeros((I+1)**2)
for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        U[l] = u(x[i],y[j])

print(f"L'erreur est de : {la.norm(Usolve-U,np.inf)}")


from scipy.sparse.linalg import inv

# Compute the inverse of D (note: this is not recommended for large matrices)
D_inv = inv(D)

# Convert to dense format for display (if the matrix is small enough)
D_inv_dense = D_inv.toarray()
print("Matrice inverse de D (dense) :")
print(D_inv_dense)
