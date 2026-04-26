#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void genera_datos ( float datos[] )
{
	float w1 = -0.4;
	float w2 = -0.2;
	float w3 = 0.1;
	float b = 0.2;

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
