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
			fflush(stdin);
			if(getNumero(&auxNumeroIngresado) == 1 && auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			}
			else {
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
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

int getChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos) {

	char auxChar[256];
	int retorno;
//	int i;
	retorno = -1;

	if (array != NULL && mensaje != NULL && mensajeError != NULL &&
			len > 0 && maximoReintentos >= 0) {
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				if(myGets(auxChar,sizeof(auxChar))==0 && validarLetras(auxChar)==1)
				{
//					strncpy(auxChar, array, sizeof(auxChar));
					strncpy(array, auxChar, len);
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

int menuPrincipal(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("*******************MENU PRINCIPAL*******************\n\n");
	printf("1. ALTA DEL ASOCIADO \n");
	printf("2. MODIFICAR DATOS DEL ASOCIADO \n");
	printf("3. BAJA DEL ASOCIADO \n");
	printf("4. NUEVA LLAMADA \n");
	printf("5. ASIGNAR AMBULANCIA\n");
	printf("6. INFORMAR \n");
	printf("7. SALIR \n");

	if(getInt(&auxOpcion, "Ingrese una opcion: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			7, 1, 5)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}

	system("cls");

	return retorno;

}

int validarLetras(char cadena[])
{
	int retorno=0;
	int len = strlen(cadena);

	if(cadena!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]>='a' && cadena[i]<='z'))
			{
				retorno=1;
			}
			else
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int getDni(int * dni)
{
	int auxDni;
	int retorno = -1;

	if(getInt(&auxDni, "Ingrese su DNI: ", "ERROR. Ingresaste un DNI incorrecto.\n\n",
			100000000, 999999, 3)==0)
	{
		*dni = auxDni;
		retorno = 0;
	}

	return retorno;
}
