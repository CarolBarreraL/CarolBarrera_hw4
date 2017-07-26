import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('datos.csv', delimiter=',')
filas = 500
columnas = 744


Mapa = np.zeros((filas, columnas))

for i in range(filas):
	for j in range(columnas):
		indice = i*columnas + j
		Mapa[i][j]= datos[indice]

plt.imshow(Mapa)
plt.show()
