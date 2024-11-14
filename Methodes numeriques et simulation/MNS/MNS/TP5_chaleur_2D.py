import numpy as np
import scipy.sparse as sp
from numpy import linalg as la
from scipy.sparse.linalg import spsolve

def f(x,y):
    return 2*np.pi**2*np.sin(np.pi*x)*np.sin(np.pi*y)

def g(x,y):
    return 0

def u(x,y):
    return np.sin(np.pi*x)*np.sin(np.pi*y)

I = 2
h = 1/I

offsets = np.array([-1,0,1])
data = [-1*np.ones(I+1), 2*np.ones(I+1), -1*np.ones(I+1)]

D1 = (1/h**2)*sp.dia_matrix((data,offsets), shape=(I+1,I+1))
D1 = sp.csc_matrix(D1)
D1[0,0],D1[-1,-1],D1[0,1],D1[-1,-2] = 0,0,0,0

M = sp.eye(I+1,I+1)
M = sp.csc_matrix(M)
M[0,0],M[-1,-1] = 0,0

D = sp.kron(D1,M) + sp.kron(M,D1)
print(D)

B = np.zeros((I+1)**2)

x = np.arange(0,I+1)*h
y = np.arange(0,I+1)*h

for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        if i==0 or i==I or j==0 or j==I:
            D[l,l] = 1
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