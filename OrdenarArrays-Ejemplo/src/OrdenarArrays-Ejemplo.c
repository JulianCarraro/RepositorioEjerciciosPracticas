#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUtn.h"

#define LEN_ARRAY_NUMEROS 5

int main(void) {
	setbuf(stdout, NULL);

	int numeros[8] = { 34, 21, 3, 4, 0, 98, 12, 65 };
	int indice;

	mostrarArrayInt(numeros, 8);
	printf("\n\n");
	ordenarArray(numeros,8);
	printf("\n\n");
	mostrarArrayInt(numeros, 8);
	printf("\n\n");

    indice = buscarIntEnArray(numeros, 8, 12);
	printf("\n\n");

	if(indice != -1)
	{
	    printf("Tu numero estaba en la posicion %d \n",indice+1);
	}
	else
    {
        printf("Tu numero no estaba en el array \n");
    }
}





