/*
 * bibliotecaUtn.c
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"

int ordenarArray(int pArray[], int len) {

	int retorno = -1;
	int i;
	int aux;
	int estaOrdenado;

	if (pArray != NULL && len > 0) {
		do {
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++) {
				if (pArray[i] > pArray[i + 1]) {

					aux = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = aux;
					estaOrdenado = 0;
				}
			}
		}while(estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int mostrarArrayChar(char array[], int len) {
	int i = 0;
		if (array != NULL && len > 0) {
			while (array[i] != '\0') {
				printf("%c", array[i]);
				i++;
			}
		}
		return 0;
}

int mostrarArrayInt(int array[], int len) {
	int i = 0;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printf("%d ", array[i]);
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

int buscarIntEnArray(int array[], int len, int numeroABuscar)
{
	int indice = -1;
	int i;

	if (array != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(array[i] == numeroABuscar)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}
