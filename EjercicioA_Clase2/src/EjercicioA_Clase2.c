/*
 ============================================================================
 Name        : EjercicioA_Clase2
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
*/

/*
Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números.
Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 -1 - 2
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	setbuf(stdout, NULL);

	int numero;
	int acumulador;
	int i;
	float promedio;

	acumulador = 0;

	for(i= 0; i < 5; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);

		acumulador += numero;
	}

	promedio = (float)acumulador / i;      //CASTEO PARA QUE TOME UN INT COMO FLOAT.   //Se pone el float asi (float)

	printf("El promedio de los numeros ingresados es: %.1f", promedio);

	return EXIT_SUCCESS;
}
