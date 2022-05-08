/*
 ============================================================================
 Name        : OrdenarMuchosArrays.c
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
#define CANTIDAD_ALUMNOS 2
#define LEN_NOMBRE 100

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);
int mostrarArrayChar(char array[], int len);
int ordenarArray(int pArray[], int len);
int mostrarArrayInt(int array[], int len);
int ordenarPorNotasPrimerParcial(char nombresDeAlumnos[][100],
		char apellidosDeAlumnos[][100], float notasPrimerParcial[],
		float notasSegundoParcial[], int legajos[], char genero[],
		int dniAlumnos[], int cantidadDeAlumnos);

int main(void) {
	setbuf(stdout, NULL);

//	int numeros[8];
//
//	mostrarArrayInt(numeros, 8);
//	printf("\n\n");
//	ordenarArray(numeros,8);
//	printf("\n\n");
//	mostrarArrayInt(numeros, 8);
//	printf("\n\n");

	char nombresDeAlumnos[CANTIDAD_ALUMNOS][LEN_NOMBRE] = { "Pepe", "Laura" };
	char apellidoDeAlumnos[CANTIDAD_ALUMNOS][LEN_NOMBRE] =
			{ "Bathory", "Acosta" };
	int legajos[CANTIDAD_ALUMNOS] = { 123, 234 };
	int dniAlumnos[CANTIDAD_ALUMNOS] = { 33745634, 23434567 };
	float notaPrimerParcial[CANTIDAD_ALUMNOS] = { 10, 9 };
	float notaSegundoParcial[CANTIDAD_ALUMNOS] = { 10, 10 };
	char genero[CANTIDAD_ALUMNOS] = { 'm', 'x' };

	mostrarArrayChar(genero, CANTIDAD_ALUMNOS);
	mostrarArrayInt(legajos, CANTIDAD_ALUMNOS);
	printf("\n\n");
	ordenarPorNotasPrimerParcial(nombresDeAlumnos, apellidoDeAlumnos,
			notaPrimerParcial, notaSegundoParcial, legajos, genero, dniAlumnos,
			2);
	printf("\n\n");
	mostrarArrayChar(genero, CANTIDAD_ALUMNOS);
	mostrarArrayInt(legajos, CANTIDAD_ALUMNOS);
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
				if (pArray[i] > pArray[i + 1]) {

					aux = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = aux;
					estaOrdenado = 0;
				}
			}
		} while (estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int ordenarPorNotasPrimerParcial(char nombresDeAlumnos[][100],
		char apellidosDeAlumnos[][100], float notasPrimerParcial[],
		float notasSegundoParcial[], int legajos[], char genero[],
		int dniAlumnos[], int cantidadDeAlumnos) {

	int retorno = -1;
	int i;
	int auxInt;
	char auxChar;
	char auxCadena[100];
	float auxFloat;

	int estaOrdenado;

	if (nombresDeAlumnos != NULL && apellidosDeAlumnos != NULL
			&& notasPrimerParcial != NULL && notasSegundoParcial != NULL
			&& legajos != NULL && genero != NULL && dniAlumnos != NULL
			&& cantidadDeAlumnos > 0) {
		do {
			estaOrdenado = 1;
			cantidadDeAlumnos--;
			for (i = 0; i < cantidadDeAlumnos; i++) {
				if (notasPrimerParcial[i] > notasPrimerParcial[i + 1]) {

					auxFloat = notasPrimerParcial[i];
					notasPrimerParcial[i] = notasPrimerParcial[i + 1];
					notasPrimerParcial[i + 1] = auxFloat;

					auxFloat = notasSegundoParcial[i];
					notasSegundoParcial[i] = notasSegundoParcial[i + 1];
					notasSegundoParcial[i + 1] = auxFloat;

					strcpy(auxCadena, nombresDeAlumnos[i]);
					strcpy(nombresDeAlumnos[i], nombresDeAlumnos[i + 1]);
					strcpy(nombresDeAlumnos[i + 1], auxCadena);

					strcpy(auxCadena, apellidosDeAlumnos[i]);
					strcpy(apellidosDeAlumnos[i], apellidosDeAlumnos[i + 1]);
					strcpy(apellidosDeAlumnos[i + 1], auxCadena);

					auxInt = legajos[i];
					legajos[i] = legajos[i + 1];
					legajos[i + 1] = auxInt;

					auxChar = genero[i];
					genero[i] = genero[i + 1];
					genero[i + 1] = auxChar;

					auxInt = dniAlumnos[i];
					dniAlumnos[i] = dniAlumnos[i + 1];
					dniAlumnos[i + 1] = auxInt;

					estaOrdenado = 0;
				}
			}
		} while (estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int mostrarArrayChar(char array[], int len) {
	int i = 0;
	if (array != NULL && len > 0) {
		while (array[i] != '\0') {
			printf("%c ", array[i]);
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

	return retorno;
}

