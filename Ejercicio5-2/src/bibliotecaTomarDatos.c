/*
 * bibliotecaTomarDatos.c
 *
 *  Created on: 3 may. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTomarDatos.h"

int inicializarArrayEnteros(int array[],int len, int valorInicial){
	int i;
	if(array != NULL && len > 0){
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

	return retorno;
}

int mostrarArrayInt(int array[], int len) {
	int i;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printf("%d ", array[i]);
		}
	}
	return 0;
}



int mostrarNumerosIntPositivos(int array[], int len) {
	int i;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if(array[i] >= 0)
			{
				printf("%d ", array[i]);
			}
		}
	}
	return 0;
}

int mostrarNumerosIntPares(int array[], int len) {
	int i;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if(array[i] %2 == 0)
			{
				printf("%d ", array[i]);
			}
		}
	}
	return 0;
}

int mostrarNumerosIntEnPosicionesImpares(int array[], int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if(i %2 == 0)
			{
				printf("%d ", array[i]);
			}
		}
	}
	return 0;
}


int buscarIntEnArray(int array[], int len, int numeroABuscar)
{
    int indice = -1;

    if(array != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
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


int contarEnterosPositivosEnArray(int array[], int len, int* pContador)
{
    int retorno;
    int	auxContadorPositivos;

    auxContadorPositivos = 0;
    retorno = -1;

    if(array != NULL && len > 0 && pContador != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(array[i] >= 0)
            {
            	auxContadorPositivos++;
            }
    		*pContador = auxContadorPositivos;
    		retorno = 0;
        }
    }

    return retorno;
}

int contarEnterosNegativosEnArray(int array[], int len, int* pContador)
{
    int retorno;
    int	auxContadorNegativos;

    auxContadorNegativos = 0;
    retorno = -1;

    if(array != NULL && len > 0 && pContador != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(array[i] < 0)
            {
            	auxContadorNegativos++;
            }
    		*pContador = auxContadorNegativos;
    		retorno = 0;
        }
    }

    return retorno;
}

int contarEnterosParesEnArray(int array[], int len, int* pContador)
{
    int retorno;
    int	auxContadorPares;

    auxContadorPares = 0;
    retorno = -1;

    if(array != NULL && len > 0 && pContador != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(array[i] %2 == 0)
            {
            	auxContadorPares++;
            }
    		*pContador = auxContadorPares;
    		retorno = 0;
        }
    }

    return retorno;
}

int buscarMayorImparEnArray(int array[], int len, int* pMayorNumeroImpar)
{
    int retorno;
    int flag;
    int auxMayorNumero;

    flag = 0;
    retorno = -1;

    if(array != NULL && len > 0 && pMayorNumeroImpar != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(array[i] %2 != 0)
            {
            	if(auxMayorNumero < array[i] || flag == 0)
            	{
            		auxMayorNumero = array[i];
            		flag = 1;
            		*pMayorNumeroImpar = auxMayorNumero;
            		retorno = 0;
            	}

            }
        }
    }

    return retorno;
}

int getArrayInt(int array[], int len, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	int auxNumeroIngresado;
	int retorno;
	int i;
	retorno = -1;

	if (array != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		for (i = 0; i < len; i++)
		{
			do {
				printf("%s", mensaje);
				scanf("%d", &auxNumeroIngresado);
				if (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
					array[i] = auxNumeroIngresado;
					retorno = 0;
					break;
				} else {
					printf("%s", mensajeError);
					retorno = -1;
					maximoDeReintentos--;
				}

			} while (maximoDeReintentos > 0);

			if(maximoDeReintentos <= 0)
			{
				break;
			}
		}

	}

	return retorno;
}


