import matplotlib.pyplot as plt
import numpy as np
import time
from numpy import linalg as la
from scipy.sparse.linalg import spsolve
import scipy.sparse as sp

start_time = time.time()
N=50
h = 1.0/N
print("h",h)
offsets = np.array([-1,0,1])

alpha = int(input("entrez alpha : "))
beta =float(input("entrez beta : "))

def f(X):
    return np.pi**2*np.sin(np.pi*X)+2*np.pi*np.cos(np.pi*X)

data2 = [np.ones(N+1)*(-1/(h**2)-1/h), 2/(h**2)*np.ones(N+1), np.ones(N+1)*(-1/(h**2)+1/h)]
B = sp.dia_matrix((data2,offsets), shape=(N+1, N+1) )
b2=np.ones(N+1)
b2[0]=alpha
b2[N]=beta
b2[1:N]=f(x)

x2=np.arange(0,N+1)*h
sol2 =np.sin(x2*np.pi)
B = sp.csc_matrix(B)
B[0,0] =1 ; B[0,1]=0
B[N,N] =3/(2*h) ; B[N,N-1]=-4/(2*h); B[N,N-2]=-1/(2*h);
y1 = spsolve(B,b2)
print("error", la.norm(y1-sol2, np.inf))
print("elapsed time %f s" %(time.time()-start_time))



if(N<50):
    plt.plot(x,y,'bo')
plt.plot(x,sol)
plt.xlabel(u'$x$', fontsize=14)
plt.title(u'Solution u')
plt.show()