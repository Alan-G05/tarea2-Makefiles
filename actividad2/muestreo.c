#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "procesamiento.h"
#include "archivos.h"
#include "defs.h"

//#define MUESTRAS 512

//void genera_datos ( float datos[] );
//void guarda_datos ( float datos[] );

//float w1 = -0.4;
//float w2 = -0.2;
//float w3 = 0.1;
//float b = 0.2;

int main()
{
	srand(time(NULL));
	float datos[MUESTRAS];

	genera_datos( datos );
	guarda_datos( datos );

	return 0;
}

/*
void genera_datos ( float datos[] )
{

	//float f = 1000, fs = 45000;
	//register int n;

	//for( n = 0; n < MUESTRAS; n++ )
	//{
	//	datos[n] = sinf(2*n*M_PI*f/fs);
	//}


	float x1, x2, x3, res;
	register int n;

	for( n = 0; n < MUESTRAS; n++ )
	{
		x1 = (float)rand() / (float)RAND_MAX;
		x2 = (float)rand() / (float)RAND_MAX;
		x3 = (float)rand() / (float)RAND_MAX;

		res = (w1*x1) + (w2*x2) + (w3*x3) + b;

		//printf("%f - %f - %f", x1, x2, x3);

		if(res >= 0)
			res = 1.0;
		else
			res = 0.0;

		datos[n] = res;
	}

}

void guarda_datos ( float datos[] )
{
	FILE *ap_arch;
	register int n;

	ap_arch = fopen("seno.dat", "w");
	if( !ap_arch )
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}

	for( n = 0; n < MUESTRAS; n++ )
	{
		fprintf(ap_arch, "%f \n", datos[n]);
	}

	fclose(ap_arch);
}
*/
