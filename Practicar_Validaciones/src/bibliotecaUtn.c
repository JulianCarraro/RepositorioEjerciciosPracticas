/*
 * bibliotecaUtn.c
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUtn.h"

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
			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
			maximoDeReintentos--;
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

int getArrayInt(int array[], int len, char * mensaje, char * mensajeError,int maximoReintentos) {

	int auxNumeroIngresado;
	int retorno;
	int i;
	retorno = -1;

	if (array != NULL && mensaje != NULL && mensajeError != NULL &&
			len > 0 && maximoReintentos >= 0) {
		for(i = 0; i < len; i++)
		{
			do
			{
				printf("%s", mensaje);
				if(getNumero(&auxNumeroIngresado) == 1)
				{
					array[i] = auxNumeroIngresado;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					retorno = -1;
					maximoReintentos--;
				}
			}while(maximoReintentos > 0);

			if(maximoReintentos <= 0)
			{
				break;
			}
		}
	}

	return retorno;
}

int validarNumero(char * cadena)
{
	int retorno;
	int i;

	i = 0;
	retorno = 1;

	if(cadena != NULL)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}


	return retorno;
}


int getNumero(int * pResultado)
{
	int retorno;
	char auxNumero[256];
	retorno = 0;

	fflush(stdin);
	if(pResultado != NULL)
	{
		if(myGets(auxNumero,sizeof(auxNumero))==0 && validarNumero(auxNumero)==1)
		{
			retorno = 1;
			*pResultado = atoi(auxNumero);
		}
	}

	return retorno;
}


int myGets(char* cadena, int len)
{
	int retorno;

	retorno = 1;

	if(cadena != NULL && len > 0 && fgets(cadena,len,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int borrarImpares(int cadena[], int len)
{
	int retorno;
	int i;

	retorno = 0;

	if(cadena != NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
			if(cadena[i] %2 != 0)
			{
				cadena[i] = 0;
			}
			retorno = 1;
		}
	}

	return retorno;
}

int mostrarNumeros(int array[], int len){
	int retorno;
	retorno = -1;

	if(len > 0 && array!=NULL){
		for(int i = 0; i<len; i++){
				printf("%d\n", array[i]);
			}
		retorno = 0;
	}
	return retorno;
}

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
				if (pArray[i] < pArray[i + 1]) {
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

int getDni(int pArray[], int len)
{
	int retorno;
	int i;
	int auxDni;

	retorno = 0;

	if(pArray != NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
//			getInt(&auxDni, "Ingrese su DNI", "Datos no validos", int maximo,
//					int minimo, int maximoDeReintentos)
			if(getArrayInt(pArray, len, "Ingrese su DNI", "Datos no validos", 5)==0)
			{
				if(pArray[i] < 9)
				{
					retorno = 1;
					break;
				}
				else
				{
					retorno = 0;
					break;
				}
			}

		}
	}

	return retorno;
}

