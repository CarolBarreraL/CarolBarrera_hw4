
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define filas 500
#define cols 744

int indice(int i, int j);
int Aleai(void);
int Aleaj(void);
double radio(int iPunto, int jPunto, int *matriz);

int main(void)
{
	FILE *in;
	int i;
	int pasos = 1000;
	char filename[100]="map_data.txt";
	in = fopen(filename, "r");
	int *matriz = malloc(filas*cols*sizeof(int));
	for(i=0;i<filas*cols;i++)
	{
		fscanf(in, "%d\n", &matriz[i]);
	}
	fclose(in);
	
	//Posiciones Aleatorias
	srand(1);
	int Posx = Aleai();
	int Posy = Aleaj();

	int nuevax, nuevay;
	float alpha, rInicial, nuevoR, beta;
	int MaxX, MaxY;
	float MaxR;	
	rInicial = radio(Posx, Posy, matriz);
	MaxX = Posx;
	MaxY = Posy;
	MaxR = rInicial;
	for(i=0; i<pasos; i++)
	{	
			
		nuevax = Posx + Aleai();
		if(nuevax<0){nuevax = filas + nuevax%filas;}
		else if(nuevax>filas){nuevax = nuevax%filas;}
		nuevay = Posy + Aleaj();
		if(nuevay<0){nuevay= cols + nuevay%cols;}
		else if(nuevay>cols){nuevay = nuevay%cols;}
	nuevoR = radio(nuevax, nuevay, matriz);

	alpha = nuevoR/rInicial;
		if(alpha>1.0)
		{
			Posx = nuevax; 
			Posy = nuevay; 
			rInicial=radio(Posx, Posy, matriz);
			
		}
		else
		{
			beta = drand48();
			if(beta<alpha)
			{
				Posx = nuevax; 
				Posy = nuevay; 
				rInicial=radio(Posx, Posy, matriz);
			
			}
			else if(beta>alpha)
			{
				Posx = Posx; 
				Posy = Posy; 
				rInicial=radio(Posx, Posy, matriz);
			
			}
		}
	if(rInicial>MaxR)
		{
			MaxX = nuevax;
			MaxY = nuevay;
			MaxR = rInicial;
		}
		
	}

	FILE *dat;
	char data[100]="datos.csv";
	dat = fopen(data, "w");
	fprintf(dat, "%d %d %f\n", MaxX, MaxY, MaxR);
	fclose(dat);
	
	char mensaje[100] = "Las coordenadas del punto mas alejado son: ";
	printf("%s %d, %d\n", mensaje, MaxX, MaxY);


	return 0;
}

double radio(int iPunto, int jPunto, int *matriz)
{
	double r;
	double rint;
	int iNuevo;
	int jNuevo;
	double pare;
	for(rint=1;rint<filas/2;rint++)
	{	
		for(iNuevo=0; iNuevo<rint; iNuevo++)
		{
			for(jNuevo=0; jNuevo<rint; jNuevo++)
			{	
				if(pow(iNuevo,2.0)+ pow(jNuevo,2.0)< pow(rint,2.0))		
				{
					if(matriz[indice(iPunto + iNuevo,jPunto + jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto+jNuevo)]== 0 && matriz[indice(iPunto + iNuevo,jPunto - jNuevo)]== 0 && matriz[indice(iPunto,jPunto + jNuevo)]== 0 && matriz[indice(iPunto,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto)]== 0 && matriz[indice(iPunto + iNuevo,jPunto)]== 0 ){r = rint;}
					else {r = rint; pare = r; break;}
				}
			if(pare==r){break;}
			}
		if(pare==r){break;}
		}
	if(pare==r){break;}
	}
	return r;
}


int Aleai(void)
{
	int num = rand()%(filas/2 + 1)-filas/4;
	//int num = rand()%(filas+1);
	return num;
}

int Aleaj(void)
{
	int num = rand()%(cols/4 + 1)-cols/8;
	//int num = rand()%(cols+1);
	return num;
}

int indice(int i, int j)
{	
	int num;

	if(i<0){i = filas + i%filas;}
	else if(i>filas){i = i%filas;}
	if(j<0){j= cols + j%cols;}
	else if(j>cols){j = j%cols;}
	num = i*cols + j;	
	return num;
}

double lat(int i)
{
	double lat;
	if(i< filas/2){lat = -90 + i; }
}








