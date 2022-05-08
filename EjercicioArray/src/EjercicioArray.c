/*
 ============================================================================
 Name        : EjercicioArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY_NUMEROS 3

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);
int inicializarArrayEnteros(int array[],int len, int valorInicial);

int main(void) {
	setbuf(stdout, NULL);

	int arrayEdades[LEN_ARRAY_NUMEROS];
	int validacionRetorno;
	int i;

	inicializarArrayEnteros(arrayEdades,LEN_ARRAY_NUMEROS,0);

	for (i = 0; i < 3; i++) {
		validacionRetorno = getInt(&arrayEdades[i], "Ingrese la edad entre 18 y 99:\n",
				"La edad es incorrecta:\n", 99, 18, 2);
		if (validacionRetorno == -1) {
			printf("La edad no fue ingresada bien\n");
		}
	}

	for (i = 0; i < LEN_ARRAY_NUMEROS; i++) {
			printf("El valor del array en %d es %d: \n", i, arrayEdades[i]);
	}
}

int inicializarArrayEnteros(int array[],int len, int valorInicial){
	int i;
	if(len > 0){
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

