/*
 * bibliotecaUtn.h
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int mostrarArrayChar(char array[], int len);

int ordenarArray(int pArray[], int len);

int mostrarArrayInt(int array[], int len);

int validarNumero(char cadena[]);

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int menuPrincipal(void);

int getArrayInt(int array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getNumero(int * pResultado);

int myGets(char* cadena, int len);

int borrarImpares(int cadena[], int len);

int mostrarNumeros(int array[], int len);

int ordenarArray(int pArray[], int len);

#endif /* BIBLIOTECAUTN_H_ */
