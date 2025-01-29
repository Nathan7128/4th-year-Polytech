import numpy as np
from numpy import linalg as la
import scipy.sparse as sp
from scipy.sparse.linalg import spsolve
import time

start_time = time.time()

N = 100

def f(x) :
    return (np.pi**2)*np.sin(np.pi*x)

h = 1.0/N

print(h)

offsets = np.array([-1, 0, 1])

data = [-np.ones(N - 1), 2*np.ones(N - 1), -np.ones(N - 1)]
A = sp.dia_matrix((data, offsets), shape = (N - 1, N - 1))
A = A/(h**2)

x = np.arange(0, N + 1)*h

b = (f(x[:-2]) + 10*f(x[1:-1]) + f(x[2:]))/12
sol = np.sin(x[1:-1]*np.pi)
y = spsolve(A, b)

print(la.norm(y - sol, np.inf))
print("elapsed time %f " %(time.time() - start_time))