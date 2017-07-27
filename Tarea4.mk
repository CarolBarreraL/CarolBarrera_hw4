PuntoNemo.pdf: datos.csv Plots.py
	python Plots.py

datos.csv: a.out
	./a.out

a.out: GeographicPoint.c
	cc GeographicPoint.c -lm
