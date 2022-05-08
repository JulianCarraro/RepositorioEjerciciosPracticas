/*
 * bibliotecaFuncionesArray.c
 *
 *  Created on: 29 abr. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaFuncionesArray.h"

int getString (char mensaje[], char cadena[], int len){
	int retorno = -1;


	if(mensaje != NULL && cadena != NULL && len != 0){
		printf("%s", mensaje);
		fflush(stdin);
		if (fgets(cadena, len, stdin)){
			//cadena[strcspn(cadena, '\n')] = '\0';
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}


	return retorno;
}


int validarLetras(char cadena[])
{
	int retorno = 1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'A' || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}

	return retorno;
}

int inicializarMatrizchars(char array[][256], int len){
	int retorno  = -1;
	int i;

	if(array != NULL && len > 0){

		for(i=0; i<len; i++){
			//strcpy(array[i], "0");
			array[i][0] = '0';
		}
		retorno = 0;

	}

	return retorno;
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

int buscarEspacioLibreMatriz(char array[][256], int len, int * indexEncontrado){
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for(i=0; i<len; i++){
			if(array[i][0] == '0'){
				*indexEncontrado = i;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}

int mostrarArrayChar(char array[], int len) {
	int i = 0;
	if (array != NULL && len > 0) {
		while (array[i] != '\0') {
			printf("%c \n", array[i]);
			i++;
		}
	}
	return 0;
}




