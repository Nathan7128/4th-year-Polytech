# importation des bibliothèques
import numpy as np
import scipy.sparse as sp
import time
from scipy.sparse.linalg import spsolve
import matplotlib.pyplot as plt



# initialisation t0
t0 = time.time()



# Données
T_ext = 8

D = 2*(10**(-5))

T = 36000

K = 10**(-2)

I = 80
h = 1/I

N = 1000
d_t = T/N

lambd = (D*d_t)/(h**2)

x = np.arange(0,I+1)*h
y = np.arange(0,I+1)*h

a = 1/h + K
b = -1/h

def u0(x, y) :
    return T_ext + 15*np.sin(np.pi*x)

# Matrices
diag_D1 = [-lambd*np.ones(I + 1), (2*lambd + 1/2)*np.ones(I + 1), -lambd*np.ones(I + 1)]

off_set_D1 = [-1, 0, 1]

D1 = sp.dia_matrix((diag_D1,off_set_D1), shape=(I+1,I+1))
D1 = sp.csc_matrix(D1)
D1[0,0],D1[-1,-1],D1[0,1],D1[-1,-2] = 0,0,0,0

M = sp.eye(I+1,I+1)
M = sp.csc_matrix(M)
M[0,0],M[-1,-1] = 0,0

D = sp.kron(D1,M) + sp.kron(M,D1)

U_old = np.zeros((I + 1)**2)
U_new = np.zeros((I + 1)**2)

for i in range(I+1):
    for j in range(I+1):
        l = i+j*(I+1)
        if j==I:
            D[l,l] = a
            D[l,l-(I+1)] = b
        elif j==0:
            D[l,l] = a
            D[l,l+I+1] = b
        elif i==0:
            if((j<=0.8*I)and(j>=0.6*I)):
                D[l,l] = 1
            else:
                D[l,l] = a
                D[l,l+1] = b
        elif i==I:
            if((j<=0.8*I)and(j>=0.6*I)):
                D[l,l] = 1
            else:
                D[l,l] = a
                D[l,l-1] = b
        
                
for n in range (N) :
    b = np.zeros((I+1)**2)
    for i in range(I+1):
        for j in range(I+1):
            l = i+j*(I+1)
            if(((i==0)or(i==I))and((j<=0.8*I)and(j>=0.6*I))):
                b[l] = T_ext
            elif i==0 or i==I or j==0 or j==I:
                b[l] = T_ext*K
            else:
                b[l] = U_old[l]
            
            U_new = spsolve(D,b)
            U_old = U_new.copy()
        
        print(n)
    
    if n==0:
        fig = plt.figure(figsize=(8,6))
        im=plt.imshow(U_new.reshape(I+1,I+1),extent =[x.min(), x.max(), y.min(), y.max()])
        plt.title("Température")
        plt.colorbar()
        plt.xlabel(u"x", fontsize=26)
        plt.ylabel(u"y", fontsize=26, rotation=90)
        plt.pause(0.01)
    else:
        if (n%(int(N/300)+1) == 0):
            im.set_array(U_new.reshape(I+1,I+1))
            plt.title(u"Equation de la chaleur 2D. t="+" %1.2f" %(n*d_t), fontsize=52)
            plt.pause(0.01)



































