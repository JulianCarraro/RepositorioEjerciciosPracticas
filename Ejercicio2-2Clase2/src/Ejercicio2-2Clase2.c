/*
 ============================================================================
 Name        : Ejercicio2-2_Clase2.c
 Author      : Julian Carraro
 Version     : 1E
 */

/*
 Ingresar 10 números enteros, distintos de cero.
 Mostrar:
 Cantidad de pares e impares.
 El menor número ingresado.
 De los pares el mayor número ingresado.Suma de los positivos.
 Producto de los negativos.
*/

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 10

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int i;
	int contadorNumerosPares;
	int contadorNumerosImpares;
	int mayorNumeroPar;
	int menorNumero;
	int acumuladorPositivos;
	int acumuladorNegativos;
	int contadorNegativos;

	contadorNumerosPares = 0;
	contadorNumerosImpares = 0;
	acumuladorPositivos = 0;
	acumuladorNegativos = 1;
	contadorNegativos = 0;

	for(i = 0; i < LIMITE; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &numero);

		while(numero == 0)
		{
			printf("ERROR. Ingrese un numero entero (que no sea 0): ");
			scanf("%d", &numero);
		}

		if(numero %2 == 0)
		{
			contadorNumerosPares++;
			if(numero > mayorNumeroPar || i == 0)
			{
				mayorNumeroPar = numero;
			}
		}
		else
		{
			contadorNumerosImpares++;
		}

		if(numero < menorNumero || i == 0)
		{
			menorNumero = numero;
		}

		if(numero > 0)
		{
			acumuladorPositivos += numero;
		}
		else
		{
			acumuladorNegativos *= numero;
			contadorNegativos++;
		}

	}

	if(contadorNegativos == 0)
	{
		acumuladorNegativos = 0;
	}

	printf("La cantidad de numeros pares es %d, y la cantidad de numeros impares es %d "
			"\nEl menor numero ingresado es %d \nEl mayor numero ingresado de los pares es %d "
			"\nLa suma de los positivos es %d, y el producto de los negativos es %d"
			, contadorNumerosPares, contadorNumerosImpares, menorNumero, mayorNumeroPar, acumuladorPositivos, acumuladorNegativos);

	return EXIT_SUCCESS;
}
