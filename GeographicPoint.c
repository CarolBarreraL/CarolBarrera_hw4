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
	char filename[100]="map_data.txt";
	in = fopen(filename, "r");
	int *matriz = malloc(filas*cols*sizeof(int));
	for(i=0;i<filas*cols;i++)
	{
		fscanf(in, "%d\n", &matriz[i]);
	}
	fclose(in);
	double rInicial;
	
	srand(time(NULL));
	int Posx = rand()%(filas);
	int Posy = rand()%(cols);
	if(matriz[indice(Posx,Posy)]==0)
	{
		rInicial = radio(Posx, Posy, matriz);
		
	}
	
	int val = matriz[indice(Posx,Posy)];
	printf("%e,%d,%d, %d\n", rInicial,Posx, Posy, val);
	
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
					//if(matriz[indice(iPunto + iNuevo,jPunto + jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto+jNuevo)]== 0 && matriz[indice(iPunto + iNuevo,jPunto - jNuevo)]== 0){r = rint;}
					if(matriz[indice(iPunto,jPunto + jNuevo)]== 0 && matriz[indice(iPunto,jPunto -jNuevo)]== 0 && matriz[indice(iPunto - iNuevo,jPunto)]== 0 && matriz[indice(iPunto + iNuevo,jPunto)]== 0){r = rint;}
					
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
	int num = rand()%(filas/2 + 1)-filas/4;
	return num;
}

int Aleaj(void)
{
	int num = rand()%(cols/2 + 1)-cols/4;
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








