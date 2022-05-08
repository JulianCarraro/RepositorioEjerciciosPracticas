/*
 ============================================================================
 Name        : Ejercicio7-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 7-3: Realizar un programa que le pida 5 números enteros al usuario y los almacene en un array.
 * Crear una función borrar Impares que reciba el array y reemplace los números impares por cero.
 * Ordenar el array según el criterio seleccionado por el usuario: ascendente o descendente.
 * El menú debe ser:
1. Ingresar números
2. Borrar impares
3. Mostrar
4. Ordenar
5. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUtn.h"

#define LEN_NUMEROS 5

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int numeros[LEN_NUMEROS];
	int flagIngresoNumeros;

	flagIngresoNumeros = 0;

	do
	{
		opcionMenu = menuPrincipal();

		if(flagIngresoNumeros == 1 || opcionMenu == 1 || opcionMenu == 5)
		{
			switch(opcionMenu)
			{
				case 1:
					printf("\n***********INGRESAR NUMEROS***********\n\n");

					getArrayInt(numeros, LEN_NUMEROS, "Ingrese un numero: ", "No ingresaste un numero valido\n", 3);
					flagIngresoNumeros = 1;
					break;
				case 2:
					borrarImpares(numeros, LEN_NUMEROS);
					break;
				case 3:
					mostrarNumeros(numeros, LEN_NUMEROS);
					break;
				case 4:
					ordenarArray(numeros, LEN_NUMEROS);
					break;
				case 5:
					break;
			}
		}
		else
		{
			printf("Debes ingresar numeros antes de continuar\n\n");
			system("pause");
		}

	}while(opcionMenu != 5);

	printf("Hasta luego");

	return EXIT_SUCCESS;
}

int menuPrincipal(void)
{
	int opcionMenu;

	printf("\n*******************MENU PRINCIPAL*******************\n\n");
	printf("1. Ingresar numeros\n");
	printf("2. Borrar impares\n");
	printf("3. Mostrar\n");
	printf("4. Ordenar\n");
	printf("5. Salir\n");

	getInt(&opcionMenu, "Ingrese una opcion: ", "\nERROR. Ingresaste una opcion incorrecta.\n",
			5, 1, 3);

	return opcionMenu;

}



