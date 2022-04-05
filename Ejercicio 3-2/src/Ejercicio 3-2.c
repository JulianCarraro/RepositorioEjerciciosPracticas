/*
 ============================================================================
 Name        : Ejercicio3-2.c
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
 */
/*
 Crear una función que muestre por pantalla el número flotante que recibe como parámetro.
 */

#include <stdio.h>
#include <stdlib.h>

void mostrarNumeroFlotante(float numeroFlotante);

int main(void) {
	setbuf(stdout, NULL);

	float numero;

	printf("Ingrese un numero flotante: ");
	scanf("%f", &numero);

	mostrarNumeroFlotante(numero);

	return EXIT_SUCCESS;
}

void mostrarNumeroFlotante(float numeroFlotante)
{
	printf("El numero flotante es: %.2f", numeroFlotante);
}
