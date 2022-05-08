/*
 ============================================================================
 Name        : OtroEjemploConArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_ARRAY_NUMEROS 5

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);
int inicializarArrayEnteros(int array[], int len, int valorInicial);

int main(void) {
	setbuf(stdout, NULL);

	int arrayEdades[LEN_ARRAY_NUMEROS];
	int validacionRetorno;
	char quiereSeguir;
	int i;
	int numeroIngresado;
	int posicionEnArray;

	inicializarArrayEnteros(arrayEdades, LEN_ARRAY_NUMEROS, 0);

	do {
		validacionRetorno = getInt(&posicionEnArray,
				"Ingrese el lugar donde quiere guardar el dato entre 1 y 5:\n",
				"No existe\n", 5, 1, 2);
		if(validacionRetorno == 0)
		{
			if(arrayEdades[posicionEnArray - 1] == 0)
			{
				validacionRetorno = getInt(&numeroIngresado, "Ingrese numero entre 1 y 10:\n",
				"Fuera de rango el numero\n", 10, 1, 2);
				if(validacionRetorno == 0)
				{
					arrayEdades[posicionEnArray - 1] = numeroIngresado;
				}
				else
				{
					printf("No se pudo guardar \n");
				}
			}
			else
			{
				printf("Ya se ingreso un dato en este lugar \n");
			}
		}


		for (i = 0; i < LEN_ARRAY_NUMEROS; i++) {
			printf("El valor del array en %d es %d: \n", i, arrayEdades[i]);
		}

		printf("Quiere ingresar otro dato?  s/n\n");
		fflush(stdin);
		scanf("%c", &quiereSeguir);

	} while (quiereSeguir == 's');
}

int inicializarArrayEnteros(int array[], int len, int valorInicial) {
	int i;
	if (len > 0) {
		for (i = 0; i < len; i++) {
			array[i] = valorInicial;
		}
	}
	return 0;
}

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			if (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
			maximoDeReintentos--;
		} while (maximoDeReintentos > 0);
	}

	if(retorno == -1)
	{
		printf("Te quedaste sin intentos\n");
	}

	return retorno;
}
