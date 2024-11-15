import numpy as np

a = np.array(np.arange(16)).reshape((4, 4))
print(a[[1, 2, 3], [1, 2, 3]])
print(a)