import numpy as np

import matplotlib.pyplot as plt



x = np.loadtxt("datos.txt")[:, 0]

original = np.loadtxt("datos.txt")[:, 1]

segunda = np.loadtxt("datos.txt")[:, 2]

tercera = np.loadtxt("datos.txt")[:, 3]

final = np.loadtxt("datos.txt")[:, 4]


plt.plot(x, original, label="original")
plt.plot(x, segunda, label="segunda")
plt.plot(x, tercera, label="tercera")
plt.plot(x, final, label="final")

plt.legend()

plt.savefig("onda.png")
