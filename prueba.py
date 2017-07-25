import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('map_data.txt', delimiter=' ')

print np.shape(datos), len(datos[0])

plt.imshow(datos)
plt.show()
