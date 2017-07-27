import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('map_data.txt', delimiter=' ')
Coord = np.genfromtxt('datos.csv', delimiter=' ')

y = Coord[0]
x = Coord[1]
r = Coord[2]
print x,y,r

fig = plt.figure()
ax= fig.add_subplot(111)
ax.imshow(datos)
ax.plot(x,y, 'o', color='r')
circulo = plt.Circle((x,y), r, color='r', fill=False)
ax.annotate('Punto Nemo', xy=(x,y), xytext =(146,486), arrowprops= dict(facecolor='black'))
ax.add_artist(circulo)
plt.show()
plt.savefig('PuntoNemo.pdf')
