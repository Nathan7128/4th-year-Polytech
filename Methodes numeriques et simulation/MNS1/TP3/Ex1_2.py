# import libraries
import matplotlib.pyplot as plt
import numpy as np



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

T = 2
K = 1
I = 100
N = 50000
h = 1/I
d_t = 2/N
print("(d_t*K)/(h**2) = ", (d_t*K)/(h**2))

sub_x = np.linspace(0, 1, I+1)
sub_t = np.linspace(0, T, N + 1)



# Explicit Euler scheme implementation
u_old = u0(sub_x)
u_new = np.zeros(I+1)

for k in range(0, N) :
    u_new[1:-1] = u_old[1:-1] + d_t*(f(sub_x[1:-1], sub_t[k]) + (u_old[2:] - 2*u_old[1:-1] + u_old[:-2])/(h**2))
    u_new[0] = alpha(sub_t[k + 1])
    u_new[-1] = beta(sub_t[k + 1])
    u_old = u_new.copy()
    
    if (k%(N/10) == 0) :
        plotlabel = "t = %1.2f" %(k*d_t)
        plt.plot(sub_x, u_new, label = plotlabel, color = plt.get_cmap("copper")(float(k)/N))



# return error and visualization
print("Erreur : ", np.linalg.norm(u(sub_x, T) - u_new, np.inf))

plt.xlabel(u"$x$", fontsize = 26)
plt.ylabel(u"$T$", fontsize = 26, rotation = 0)
plt.title(u"Equation de la chaleur 1D")
plt.legend()
plt.savefig("1D heat visualization.png")
plt.show()













