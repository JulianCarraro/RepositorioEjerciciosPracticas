/*
 * bibliotecaTomarDatos.h
 *
 *  Created on: 3 may. 2022
 *      Author: carra
 */

#ifndef BIBLIOTECATOMARDATOS_H_
#define BIBLIOTECATOMARDATOS_H_

int inicializarArrayEnteros(int array[],int len, int valorInicial);

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int getArrayInt(int array[], int len, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int mostrarArrayInt(int array[], int len);

int contarEnterosPositivosEnArray(int array[], int len, int* pContador);

int mostrarNumerosIntPositivos(int array[], int len);

int mostrarNumerosIntPares(int array[], int len);

int mostrarNumerosIntEnPosicionesImpares(int array[], int len);

int contarEnterosNegativosEnArray(int array[], int len, int* pContador);

int contarEnterosParesEnArray(int array[], int len, int* pContador);

int buscarMayorImparEnArray(int array[], int len, int* pMayorNumeroImpar);


#endif /* BIBLIOTECATOMARDATOS_H_ */
