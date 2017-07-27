import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('map_data.txt', delimiter=' ')
Coord = np.genfromtxt('datos.csv', delimiter=',')

x = Coord[0]
y = Coord[1]
r = Coord[2]

fig = plt.figure()
ax= fig.add_subplot(111)
ax.imshow(datos)
ax.plot(x,y, 'o', ms = r*2, mec='b', mfc='none', mew=2)
ax.annotate('PuntoNemo', xy=(x,y), xytext =(x+100,y+50), arrowprops= dict(facecolor='black', shrinkB=r*1.2))
plt.savefig('PuntoNemo.pdf')
