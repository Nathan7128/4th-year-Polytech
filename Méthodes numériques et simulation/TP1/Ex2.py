import numpy as np
from numpy import linalg as la
import scipy.sparse as sp
from scipy.sparse.linalg import spsolve
import time

start_time = time.time()

N = 100

for N in [100, 200, 500, 1000, 2000, 5000, 1000000] :
    h = 1.0/N
    
    print(h)
    
    offsets = np.array([-1, 0, 1])
    
    data = [-np.ones(N - 1), 2*np.ones(N - 1), -np.ones(N - 1)]
    A = sp.dia_matrix((data, offsets), shape = (N - 1, N - 1))
    A = A/(h**2)
    
    x = np.arange(1, N)*h
    b = (np.pi**2)*np.sin(x*np.pi)
    sol = np.sin(x*np.pi)
    y = spsolve(A, b)
    
    print(la.norm(y - sol, np.inf))
    print("elapsed time %f " %(time.time() - start_time))