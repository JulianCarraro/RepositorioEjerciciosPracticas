/*
 ============================================================================
 Name        : Ejercicio_1-2Sabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
	Ingresar 5 n�meros. Determinar cu�l es el m�ximo y el m�nimo e indicar en qu� orden
	fue ingresado.
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 6

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int i;
	int numeroMinimo;
	int numeroMaximo;

	for(i = 1; i < LIMITE; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);

		if(numero < numeroMinimo || i == 0)
		{
			numeroMinimo = numero;
		}
		if(numero > numeroMaximo || i == 0)
		{
			numeroMaximo = numero;
		}

		printf("El %d� numero ingresado es: %d \n", i, numero);

	}

	printf("El numero minimo ingresado es %d \ny el numero maximo ingresado es %d", numeroMinimo, numeroMaximo);

	return EXIT_SUCCESS;
}
