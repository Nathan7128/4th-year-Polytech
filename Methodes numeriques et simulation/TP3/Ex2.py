# import libraries
import matplotlib.pyplot as plt
import numpy as np



# Data
def f(x, t) :
    return 50*np.exp(-50*(x - 0.75)**2)

def u0(x) :
    return 5*np.exp(-10*(x - 0.5)**2)

T = 2
K = 1
I = 100
N = 50000
h = 1/I
d_t = 2/N
print("(d_t*K)/(h**2) = ", (d_t*K)/(h**2))

sub_x = np.linspace(0, 1, I + 1)
sub_t = np.linspace(0, T, N + 1)



# Explicit Euler scheme implementation
u_old = u0(sub_x)
u_new = np.zeros(I + 1)

for k in range(0, N) :
    u_new[1:-1] = u_old[1:-1] + d_t*(f(sub_x[1:-1], sub_t[k]) + (u_old[2:] - 2*u_old[1:-1] + u_old[:-2])/(h**2))
    u_old = u_new.copy()
    
    if k == 0 :
        fig, ax = plt.subplots()
        line, = plt.plot(sub_x, u_new)
        ax.set_ylim(0, 5)
    else :
        if (k%(int(N/3000) + 1) == 0) :
            line.set_ydata(u_new)
            plt.xlabel(u"$x$", fontsize = 26)
            plt.ylabel(u"$Température$", fontsize = 26, rotation = 90)
            plt.title(u'Equation de la chaleur 1D. t = '+" %1.2f" %(k*d_t), fontsize = 52)
            plt.pause(0.01)











