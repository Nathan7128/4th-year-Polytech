# import libraries
import numpy as np
import scipy.sparse as sp
import time
from scipy.sparse.linalg import spsolve
import matplotlib.pyplot as plt



# set t0
t0 = time.time()



# Data
T_ext = 8

D = 2*(10**(-5))

T = 36000

# def f(x, y, t) :
#     return np.zeros(np.shape(x))

# def g(x, y, t) :
#     return T_ext

def u0(x, y) :
    return T_ext + 15*np.sin(np.pi*x)*np.sin(np.pi*y)

I = 100

N = 1000

h = 1/I

d_t = T/N

sub_x = np.linspace(0, 1, I + 1)
sub_y = np.linspace(0, 1, I + 1)
sub_t = np.linspace(0, T, N + 1)

sub_xy = np.array([(x, y) for y in sub_y for x in sub_x])


bord_gauche = list(range(I + 1, (I + 1)*I, I + 1))
bord_droit = list(range(2*I + 1, (I + 1)*I, I + 1))
bord_bas = list(range(0, I + 1))
bord_haut = list(range(I*(I + 1), (I + 1)**2))

bords = bord_gauche + bord_droit + bord_bas + bord_haut

lambd = (D*d_t)/(h**2)

print("(d_t*D)/(h**2) = ", lambd)



# Matrix
diag_D1 = [-lambd*np.ones(I + 1), (2*lambd + 1/2)*np.ones(I + 1), -lambd*np.ones(I + 1)]

off_set_D1 = [-1, 0, 1]

D1 = sp.dia_matrix((diag_D1, off_set_D1), shape = (I + 1, I + 1))
D1 = sp.csc_matrix(D1)

D1[0, 0] = D1[-1, -1] = D1[0, 1] = D1[-1, -2] = 0


M = sp.dia_matrix((np.ones(I + 1), 0), shape = (I + 1, I + 1))
M = sp.csc_matrix(M)

M[0, 0] = M[-1, -1] = 0


D = sp.kron(D1, M) + sp.kron(M, D1)

D[bords, bords] = 1

U_old = u0(sub_xy[:, 0], sub_xy[:, 1])
U_new = np.zeros((I + 1)**2)



# Schéma d'Euler implicite
for n in range (N) :
    U_old[bords] = T_ext
    U_new = spsolve(D, U_old)
    U_old = U_new.copy()
    
    if n==0:
        fig = plt.figure(figsize=(8,6))
        im=plt.imshow(U_new.reshape(I+1,I+1),extent =[sub_x.min(), sub_x.max(), sub_y.min(), sub_y.max()])
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
        
        
        
        
        
        
        

