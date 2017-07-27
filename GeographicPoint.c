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
	srand(time(NULL));
	int Posx = rand()%(filas+1);
	int Posy = rand()%(cols+1);

	int nuevax, nuevay;
	float alpha, rInicial, nuevoR;

	rInicial = radio(Posx, Posy, matriz);
	printf("%f\n", rInicial);
	for(i=0; i<pasos; i++)
	{
		nuevax = Posx + Aleai();
		if(nuevax<0){nuevax = filas + nuevax%filas;}
		else if(nuevax>filas){nuevax = nuevax%filas;}
		nuevay = Posy + Aleaj();
		if(nuevay<0){nuevay= cols + nuevay%cols;}
		else if(nuevay>cols){nuevay = nuevay%cols;}
		
	nuevoR = radio(nuevax, nuevay, matriz);
	printf("%f\n", nuevoR);
	alpha = nuevoR/rInicial;
		if(alpha>1)
		{
			Posx = nuevax; 
			Posy = nuevay; 
			rInicial=nuevoR;
		}
		else if(alpha<1)
		{
			float beta = rand()/RAND_MAX;
			if(beta<alpha)
			{
				Posx = nuevax; 
				Posy = nuevay; 
				rInicial=nuevoR;
			}
			else { Posx =  Posx; Posy = Posy; rInicial=rInicial;}
		}
	}
	printf("%d,%d,%f\n", Posx, Posy, rInicial);

	//Como asegurar que no es 1 el punto??????
	/*if(matriz[indice(Posx,Posy)]==1)
	{
		Posx = rand()%(filas);
		Posy = rand()%(cols);
		rInicial = radio(Posx, Posy, matriz);
		
	}*/
}

double radio(int iPunto, int jPunto, int *matriz)
{
	double r;
	double rint;
	int iNuevo;
	int jNuevo;
	double pare;
	double rMax =0.0;
	for(rint=1;rint<filas/2;rint++)
	{	
		for(iNuevo=0; iNuevo<rint; iNuevo++)
		{
			for(jNuevo=0; jNuevo<rint; jNuevo++)
			{	
				if(pow(iNuevo,2.0)+ pow(jNuevo,2.0)< pow(rint,2.0))		
				{
					if(matriz[indice(iPunto + iNuevo,jPunto + jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto+jNuevo)]== 0 && matriz[indice(iPunto + iNuevo,jPunto - jNuevo)]== 0  && matriz[indice(iPunto,jPunto + jNuevo)]== 0 && matriz[indice(iPunto,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto)]== 0 && matriz[indice(iPunto + iNuevo,jPunto)]== 0){r = rint;}
					else {pare = rMax; break;}
				}
			if(pare==rMax){break;}
			}
		if(pare==rMax){break;}
		}
	if(pare==rMax){break;}
	}
	return r;
}


int Aleai(void)
{
	//int num = rand()%(filas/3 + 1)-filas/6;
	int num = rand()%(filas/3);
	return num;
}

int Aleaj(void)
{
	//int num = rand()%(cols/5 + 1)-cols/10;
	int num = rand()%(cols/5);
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








