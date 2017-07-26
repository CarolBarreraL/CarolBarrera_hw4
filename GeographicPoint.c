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
	int oceano = 0;
	int tierra = 1;
	char filename[100]="map_data.txt";
	in = fopen(filename, "r");
	int *matriz = malloc(filas*cols*sizeof(int));
	for(i=0;i<filas*cols;i++)
	{
		fscanf(in, "%d\n", &matriz[i]);
	}
	fclose(in);
	
}

/*double radio(int puntoAl, int i, int j)
{
	
}*/


int Aleai(void)
{
	int num = rand()%(filas + 1);
	return num;
}

int Aleaj(void)
{
	int num = rand()%(cols + 1);
	return num;
}

int indice(int i, int j)
{	
	int num;
	num = i*cols + j;	
	return num;
}








