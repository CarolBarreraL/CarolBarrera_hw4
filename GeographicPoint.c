#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define filas 500
#define cols 744

int indice(int i, int j);
void Alea(void);

int main(void)
{
	FILE *in;
	int i;
	int oceano = 1;
	int tierra = 0;
	char filename[100]="map_data.txt";
	in = fopen(filename, "r");
	int *matriz = malloc(filas*cols*sizeof(int));
	for(i=0;i<filas*cols;i++)
	{
		fscanf(in, "%d\n", &matriz[i]);
	}
	fclose(in);
	
}

/*Youtube, programacion ATS(video 47), genera un numero aleatorio*/
void Alea(void)
{
	int num;
	srand(time(NULL));
	num = rand()%(filas*cols + 1);
	printf("%d\n", num);
}


int indice(int i, int j)
{	
	int num;
	num = i*cols + j;	
	return num;
}








