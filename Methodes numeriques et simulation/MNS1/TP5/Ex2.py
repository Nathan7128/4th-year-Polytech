# import libraries
import numpy as np
import scipy.sparse as sp
import time
from scipy.sparse.linalg import spsolve


# set t0
t0 = time.time()



# Solution
def u(x, y) :
    return np.sin(np.pi*x)*np.sin(np.pi*y)



# Data
def f(x, y) :
    return 2*(np.pi**2)*np.sin(np.pi*x)*np.sin(np.pi*y)

I = 100

h = 1/I



# Matrix
v = 1/(h**2)

diag_D1 = [-v*np.ones(I + 1), 2*v*np.ones(I + 1), -v*np.ones(I + 1)]

off_set_D1 = [-1, 0, 1]

D1 = sp.dia_matrix((diag_D1, off_set_D1), shape = (I + 1, I + 1))
D1 = sp.csc_matrix(D1)

D1[0, 0] = D1[-1, -1] = 1
D1[0, 1] = D1[-1, -2] = 0


M = sp.dia_matrix((np.ones(I + 1), 0), shape = (I + 1, I + 1))
M = sp.csc_matrix(M)

M[0, 0] = M[-1, -1] = 0


D = sp.kron(D1, M) + sp.kron(M, D1)

D[0, 0] = D[I, I] = D[-I - 1, -I - 1] = D[-1, -1] = 1


F = np.zeros((I + 1)**2)
G = np.zeros((I + 1)**2)
U_sol = np.zeros((I + 1)**2)

c = 1/h

for j in range(I + 1) :
    xj = j*h
    for i in range(I + 1) :
        xi = i*h
        
        U_sol[i + j*(I + 1)] = u(xi, xj)

        if j == 0 :
            D[i, j] += c
            D[i, j + I + 1] -= c
        elif j  == I :
            D[i, j] += c
            D[i, j - I - 1] -= c
        elif i == 0 :
            D[i, j] += c
            D[i + 1, j] -= c
        elif i == I :
            D[i, j] += c
            D[i - 1, j] -= c
        else :
            F[i + j*(I + 1)] = f(xi, xj)
            


# Show result
U = spsolve(D, F + G)
norme = np.linalg.norm(U - U_sol, np.inf)
print("Norme :", norme)



# print time spent
print("elapsed time %f " %(time.time() - t0))

