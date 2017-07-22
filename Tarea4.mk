PuntoNemo.pdf: Plots.py
	python Plots.py

datos.csv: GeographicPoint.c a.out
	cc GeographicPoint.c -lm
	./a.out
