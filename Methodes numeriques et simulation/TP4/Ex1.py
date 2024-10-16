# Import libraries
import numpy as np
from scipy.sparse.linalg import spsolve
from scipy.sparse import dia_matrix, csc_matrix
import matplotlib.pyplot as plt



# Solution
def u(x, t) :
    return np.sin(2*np.pi*t) + np.cos(x)



# Data
def f(x, t) :
    return 2*np.pi*np.cos(2*np.pi*t) + np.cos(x)

def u0(x) :
    return np.cos(x)

def alpha(t) :
    return np.sin(2*np.pi*t) + 1

def beta(t) :
    return np.sin(2*np.pi*t) + np.cos(1)

I = 5

N = 100

K = 1

T = 2

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

for k in range (N) :
    F = f(sub_x, sub_t[k + 1])
    F[0] = alpha(sub_t[k + 1])/(lambd*d_t)
    F[-1] = beta(sub_t[k + 1])/(lambd*d_t)
    
    U_new = spsolve(A, U_old + d_t*F)
    U_old = U_new.copy()
    U_old[0] = 0
    U_old[-1] = 0
    
    if (k%(N/10) == 0) :
        plotlabel = "t = %1.2f" %(k*d_t)
        plt.plot(sub_x, U_new, label = plotlabel, color = plt.get_cmap("copper")(float(k)/N))

    

# return error and visualization
print("Erreur : ", np.linalg.norm(u(sub_x, T) - U_new, np.inf))

plt.xlabel(u"$x$", fontsize = 26)
plt.ylabel(u"$T$", fontsize = 26, rotation = 0)
plt.title(u"Equation de la chaleur 1D")
plt.legend()
plt.savefig("1D heat visualization.png")
plt.show()


























