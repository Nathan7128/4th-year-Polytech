# Import libraries
import numpy as np
from scipy.sparse.linalg import spsolve
from scipy.sparse import dia_matrix, csc_matrix



# Solution
def u(x, t) :
    return np.sin(2*np.pi*t) + np.cos(x)



# Data
T_ext = 8

def f(x, t) :
    return 0

def u0(x) :
    return T_ext + 15*np.sin(np.pi*x)

def alpha(t) :
    return T_ext

def beta(t) :
    return T_ext

I = 100

N = 1000

K = 2*(10**(-5))

T = 36000

d_t = T/N

h = 1/I

lambd = (h**2)/(K*d_t)

print("(d_t*K)/(h**2) = ", 1/lambd)



# Matrix
sub_x = np.linspace(0, 1, I + 1)

sub_t = np.linspace(0, T, N + 1)

data = [-1*np.ones(I + 1), (2 + lambd)*np.ones(I + 1), -1*np.ones(I + 1)]

offsets = [-1, 0, 1]

A = dia_matrix((data, offsets), shape = (I + 1, I + 1))

A = csc_matrix(A)

A[0, 0], A[0, 1] = 1, 0
A[-1, -1], A[-1, -2] = 1, 0

A = A/lambd



# Implicit Euler scheme implementation
U_old = u0(sub_x)
U_new = np.zeros(I + 1)

for k in range (1, N + 1) :
    F = f(sub_x, sub_t[k])
    F[0] = alpha(sub_t[k])/(lambd*d_t)
    F[-1] = beta(sub_t[k])/(lambd*d_t)
    
    U_new = spsolve(A, U_old + d_t*F)
    U_old = U_new.copy()
    U_old[0] = 0
    U_old[-1] = 0
    
    if k == 0 :
        fig, ax = plt.subplots()
        line, = plt.plot(x, U_new)
        ax.set_ylim(0, 25)
        
    else :
        if (k%(int(N/3000) + 1) == 0) :
            line.set_ydata(U_new)
            plt.xlabel(u"$x$", fontsize = 26)
            plt.ylabel(u"Température", fontsize = 26, rotation = 90)
            plt.title(u"Equation de la chaleur 1D. t="+' ')
    
# return error and visualization
print("Erreur : ", np.linalg.norm(u(sub_x, T) - U_new, np.inf))

























