/*
 * bibliotecaUtn.h
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_

//int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
//		int minimo, int maximoDeReintentos);

int mostrarArrayChar(char array[], int len);

int ordenarArray(int pArray[], int len);

int mostrarArrayInt(int array[], int len);

int validarNumero(char cadena[]);

//int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
//		int minimo, int maximoDeReintentos);
int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

//int getInt(int array, int len, char * mensaje, char * mensajeError, int maximo,
//		int minimo, int maximoReintentos);
//
//int getInt(int array, char * mensaje, char * mensajeError, int maximo,
//		int minimo, int maximoReintentos);

//int menuPrincipal(void);

int menuPrincipal(int * opcionMenu);

int getArrayInt(int array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getArrayChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getNumero(int * pResultado);

int myGets(char* cadena, int len);

int borrarImpares(int cadena[], int len);

int mostrarNumeros(int array[], int len);

int ordenarArray(int pArray[], int len);

int validarLetras(char cadena[]);

int validarDni(char cadena[]);

//int getDni(void);

int getDni(int * dni);

//int validarDni(int cadena[], int len);

#endif /* BIBLIOTECAUTN_H_ */
