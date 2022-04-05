/*
 ============================================================================
 Name        : Ejercicio3-1.c
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
 */
/* Crear una funci�n que permita determinar si un n�mero es par o no.
	La funci�n retorna 1 en caso afirmativo y 0 en caso contrario.
	Probar en el main.
 */

#include <stdio.h>
#include <stdlib.h>

int funcionParOImpar(int primerNumero);

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int respuesta;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	respuesta = funcionParOImpar(numero);

	printf("%d", respuesta);

	return 0;
}

int funcionParOImpar(int primerNumero)
{
	int respuesta = 0;

	if(primerNumero %2 == 0)
	{
		respuesta = 1;
	}

	return respuesta;
}
