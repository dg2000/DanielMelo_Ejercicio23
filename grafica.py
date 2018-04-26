import numpy as np

import matplotlib.pyplot as plt



x = np.loadtxt("datos.txt")[:, 0]

original = np.loadtxt("datos.txt")[:, 1]

segunda = np.loadtxt("datos.txt")[:, 2]

tercera = np.loadtxt("datos.txt")[:, 3]

final = np.loadtxt("datos.txt")[:, 4]

tiempos = np.loadtxt("datos.txt")[:, 5]


plt.plot(x, original, label="original con t = " + str(tiempos[0]))
plt.plot(x, segunda, label="segunda con t = " + str(tiempos[1]))
plt.plot(x, tercera, label="tercera con t = " + str(tiempos[2]))
plt.plot(x, final, label="final con t = " + str(tiempos[3]))

plt.legend()

plt.savefig("onda.png")
