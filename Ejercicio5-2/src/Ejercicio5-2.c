/*
 ============================================================================
 Name        : Ejercicio5-2.c
 Author      : Julian Carraro
 Division    : 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Ejercicio 5-2:Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 * Determinar:Cantidad de positivos y negativos.Sumatoria de los pares.
 * El mayor de los impares.Listado de los números ingresados.
 * Listado de los números pares.Listado de los números de las posiciones impares.
 * Se deberán utilizar funciones y arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTomarDatos.h"

#define LEN_NUMEROENTEROS 10

int main(void) {

	setbuf(stdout, NULL);

	int numeroEnteros[LEN_NUMEROENTEROS];
//	int i;
	int validacionRetorno;
	int numerosPositivos;
	int numerosNegativos;
	int numerosPares;
	int mayorNumeroImpar;

	inicializarArrayEnteros(numeroEnteros, LEN_NUMEROENTEROS, 0);

	validacionRetorno = getArrayInt(numeroEnteros, LEN_NUMEROENTEROS, "Ingrese un numero entero entre el -1000 y el 1000: ",
			"El numero es incorrecto:\n", 1000, -1000, 3);
//		for (i = 0; i < LEN_NUMEROENTEROS; i++)
//		{
//			validacionRetorno = getInt(&numeroEnteros[i], "Ingrese un numero entero entre el -1000 y el 1000: ",
//					"El numero es incorrecto:\n", 1000, -1000, 5);
//		}
		if(validacionRetorno == 0)
		{
			if(contarEnterosPositivosEnArray(numeroEnteros, LEN_NUMEROENTEROS, &numerosPositivos)==0)
			{
				printf("La cantidad de numeros positivos es: %d\n", numerosPositivos);
			}
			if(contarEnterosNegativosEnArray(numeroEnteros, LEN_NUMEROENTEROS, &numerosNegativos)==0)
			{
				printf("La cantidad de numeros negativos es: %d\n", numerosNegativos);
			}
			if(contarEnterosParesEnArray(numeroEnteros, LEN_NUMEROENTEROS, &numerosPares)==0)
			{
				printf("La cantidad de numeros pares es: %d\n", numerosPares);
			}
			if(buscarMayorImparEnArray(numeroEnteros, LEN_NUMEROENTEROS, &mayorNumeroImpar)==0)
			{
				printf("El mayor numero impar es: %d\n\n", mayorNumeroImpar);
			}
			else
			{
				printf("No se ingresaron numeros impares\n\n");
			}

			printf("NUMEROS INGRESADOS: \n");
			mostrarArrayInt(numeroEnteros, LEN_NUMEROENTEROS);
			printf("\n\n");

			printf("NUMEROS PARES INGRESADOS: \n");
			mostrarNumerosIntPares(numeroEnteros, LEN_NUMEROENTEROS);
			printf("\n\n");

			printf("NUMEROS EN POSICIONES IMPARES INGRESADOS: \n");
			mostrarNumerosIntEnPosicionesImpares(numeroEnteros, LEN_NUMEROENTEROS);
			printf("\n\n");
		}
		else
		{
			printf("Te quedaste sin intentos");
		}




	return EXIT_SUCCESS;
}

