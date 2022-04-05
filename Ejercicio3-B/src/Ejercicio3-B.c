/*
 ============================================================================
 Name        : Ejercicio3-B.c
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
 */
/*
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla
 */

#include <stdio.h>
#include <stdlib.h>

int realizarOperacion(int primerNumero, int segundoNumero, char tipoDeOperacion);

int main(void) {
	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	char operacion;
	int resultadoOperacion;

	printf("Ingrese un numero (entre el 10 y el 100): ");
	scanf("%d", &numeroUno);

	while(numeroUno < 10 || numeroUno > 100)
	{
		printf("ERROR. Ingrese un numero (entre el 10 y el 100): ");
		scanf("%d", &numeroUno);
	}

	printf("Ingrese un numero (entre el 10 y el 100): ");
	scanf("%d", &numeroDos);

	while(numeroDos < 10 || numeroDos > 100)
	{
		printf("ERROR. Ingrese un numero (entre el 10 y el 100): ");
		scanf("%d", &numeroDos);
	}

	printf("Ingrese el tipo de operacion: ('r'-restar o 's'-sumar): ");
	fflush(stdin);
	scanf("%c", &operacion);

	while(operacion != 's' && operacion != 'r')
	{
		printf("Ingrese el tipo de operacion: ('r'-restar o 's'-sumar): ");
		fflush(stdin);
		scanf("%c", &operacion);
	}

	resultadoOperacion = realizarOperacion(numeroUno, numeroDos, operacion);

	printf("El resultado de la operacion es: %d", resultadoOperacion);

	return EXIT_SUCCESS;
}

int realizarOperacion(int primerNumero, int segundoNumero, char tipoDeOperacion)
{
	int resultadoOperacion;

	if(tipoDeOperacion == 'r')
	{
		resultadoOperacion = primerNumero - segundoNumero;
	}
	else
	{
		resultadoOperacion = primerNumero + segundoNumero;
	}

	return resultadoOperacion;

}

