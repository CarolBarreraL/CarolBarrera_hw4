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
double radio(int i, int j);

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
	
	
}

double radio(int iPunto, int jPunto)
{
	double r;
	int rint;
	int iNuevo;
	int jNuevo;
	for(rint=1;rint<filas/2;rint++)
	{	
		for(iNuevo=iPunto+1; iNuevo<rint; iNuevo++)
		{
		for(jNuevo=jPunto+1; jNuevo<rint; jNuevo++)
		{
			if(matriz[indice(iNuevo,jNuevo)]==0||)		
			r = pow(iPunto-iNuevo,2.0)+pow(jPunto - jNuevo,2.0);
		
		}
		}
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
	if(i<0){i = filas - i%filas;}
	else if(i>filas){i = i%filas;}
	if(j<0){j= cols - i%cols;}
	else if(j>cols){j = j%cols;}
	num = i*cols + j;	
	return num;
}








