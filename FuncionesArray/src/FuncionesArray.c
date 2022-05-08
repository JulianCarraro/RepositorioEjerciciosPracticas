/*
 ============================================================================
 Name        : FuncionesArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

//toma de datos
int pedirNumeros(int array[], int longitud);
//muesta
int mostrarNumeros(int array[], int longitud);
//suma
int sumarNumerosEnArray(int array[], int longitud, int* pAcumulador);

int main(void) {
	setbuf(stdout, NULL);

	int arraysNumeros [LEN];
	int acumulador=0;

	if(pedirNumeros(arraysNumeros, LEN)==0){
		if(mostrarNumeros(arraysNumeros, LEN)==0){
			if(sumarNumerosEnArray(arraysNumeros, LEN, &acumulador)==0){
				printf("La suma de los numeros es: %d\n", acumulador);
			}
		}
	}

	return EXIT_SUCCESS;
}

int pedirNumeros(int array[], int longitud){

	int retorno;
	retorno = -1;

	if(longitud > 0 && array!=NULL){
		for(int i = 0; i<longitud; i++){
			printf("Ingrese un numero");
			scanf("%d", &array[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int mostrarNumeros(int array[], int longitud){
	int retorno;
	retorno = -1;

	if(longitud > 0 && array!=NULL){
		for(int i = 0; i<longitud; i++){
				printf("%d\n", array[i]);
			}
		retorno = 0;
	}
	return retorno;
}

//suma
int sumarNumerosEnArray(int array[], int longitud, int* pAcumulador){
	int retorno;
	int acumuladorAuxiliar;

	retorno = -1;
	acumuladorAuxiliar = 0;

	if(longitud > 0 && array!=NULL && pAcumulador!=NULL){
		for(int i = 0; i<longitud; i++){
			acumuladorAuxiliar += array[i];
		}
		*pAcumulador = acumuladorAuxiliar;
		retorno = 0;
	}
	return retorno;
}


