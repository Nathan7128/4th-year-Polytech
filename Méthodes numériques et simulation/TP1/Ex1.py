import numpy as np
import time
from numpy import linalg as la

start_time = time.time()

# N = 100

for N in [100, 200, 500, 1000, 2000, 5000] :
    h = 1.0/N
    
    print(h)
    
    A = np.diag(np.zeros(N - 1) + 2, k = 0)
    A = A + np.diag(np.zeros(N - 2) - 1, k = -1)
    A = A + np.diag(np.zeros(N - 2) - 1, k = 1)
    A = A/(h**2)
    
    x = np.arange(1, N)
    
    b = (np.pi**2)*np.sin(x*np.pi)
    sol = np.sin(x*np.pi)
    y = la.solve(A, b)
    print(la.norm(y - sol, np.inf))
    print("elapsed time %f " %(time.time() - start_time))