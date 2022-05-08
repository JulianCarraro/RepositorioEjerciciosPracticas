/*
 ============================================================================
 Name        : Ejercicio5-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 */

#include <stdio.h>
#include <stdlib.h>
int inicializarArrayEnteros(int array[],int len, int valorInicial);

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int mostrarArrayInt(int array[], int len);

#define LEN_NUMEROS 5

int main(void) {

	setbuf(stdout, NULL);

	int numero[LEN_NUMEROS];
	int i;
	int acumuladorSumatoria;

	acumuladorSumatoria = 0;

	inicializarArrayEnteros(numero, LEN_NUMEROS, 0);

	for (i = 0; i < 5; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &numero[i]);

		acumuladorSumatoria += numero[i];
	}

	mostrarArrayInt(numero, LEN_NUMEROS);

	printf("\n\nLa sumatoria total es %d: ", numero[i]);

	return EXIT_SUCCESS;
}

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
	int i = 0;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printf("%d ", array[i]);
		}
	}
	return 0;
}
