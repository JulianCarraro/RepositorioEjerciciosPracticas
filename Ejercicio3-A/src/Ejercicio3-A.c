/*
 ============================================================================
 Name        : Ejercicio3-A.c
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
 */

/*
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
 */

#include <stdio.h>
#include <stdlib.h>

float realizarDescuento (int primerNumero, float descuento);

int main(void) {
	setbuf(stdout, NULL);

	int numero1;
	float resultadoConDescuento;
	float descuento;

	descuento = 0.95;

	printf("Ingrese un numero entre 10 y 100: ");
	scanf("%d", &numero1);

	while(numero1 < 10 || numero1 > 100)
	{
		printf("ERROR. Ingrese un numero entre 10 y 100: ");
		scanf("%d", &numero1);
	}

	resultadoConDescuento = realizarDescuento(numero1,descuento);

	printf("El resultado con el descuento es %f", resultadoConDescuento);

	return EXIT_SUCCESS;
}


float realizarDescuento(int primerNumero, float descuento)
{
	float numeroConDescuento;

	numeroConDescuento = primerNumero * descuento;

	return numeroConDescuento;
}




