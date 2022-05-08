/*
 * bibliotecaFuncionesArray.h
 *
 *  Created on: 29 abr. 2022
 *      Author: carra
 */

#ifndef BIBLIOTECAFUNCIONESARRAY_H_
#define BIBLIOTECAFUNCIONESARRAY_H_

int getString (char mensaje[], char cadena[], int len);

int validarLetras(char cadena[]);

int inicializarMatrizchars(char array[][256], int len);

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int buscarEspacioLibreMatriz(char array[][256], int len, int * indexEncontrado);

int mostrarArrayChar(char array[], int len);

#endif /* BIBLIOTECAFUNCIONESARRAY_H_ */
