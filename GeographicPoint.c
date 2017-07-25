#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define filas 500
#define cols 744

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
