/*
 ============================================================================
 Name        : Ejercicio7-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 Ejercicio 7-4: Hacer un programa para ingresar hasta 100 nombres. Debe contar con el siguiente menú:
1- Ingresar nuevo nombre (no se aceptan nombres repetidos, informar si ocurre)
2- listar todos
3- Ordenar alfabeticamente
4- Borrar nombre. Se ingresa el nombre y si se encuentra, se elimina.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaFuncionesArray.h"

#define CANTIDAD_NOMBRES 5
#define LEN_NOMBRE 256

int main(void) {

	setbuf(stdout, NULL);

	char nombres[CANTIDAD_NOMBRES][LEN_NOMBRE];
	char nombreIngresado[LEN_NOMBRE];
	int opcionMenu;
	int validacionRetorno;
	int index;
	int i;

	index = 0;

	inicializarMatrizchars(nombres, CANTIDAD_NOMBRES);

	do
	{
		system("cls");
		printf("**********************MENU PRINCIPAL**********************\n");
		printf("1- Ingresar nuevo nombre\n");
		printf("2- listar todos\n");
		printf("3- Ordenar alfabeticamente\n");
		printf("4- Borrar nombre.\n");
		printf("5- Salir\n");

		validacionRetorno = getInt(&opcionMenu, "Ingrese una opcion: ", "Error. La opcion no es correcta", 5, 1, 5);

		if(validacionRetorno == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					if(buscarEspacioLibreMatriz(nombres, CANTIDAD_NOMBRES, &index)==0 &&
							getString("Ingrese un nombre\n", nombreIngresado, LEN_NOMBRE) == 0){
						strcpy(nombres[index], nombreIngresado);
					}
					break;
				case 2:
					for(i=0; i<CANTIDAD_NOMBRES; i++)
					{
						mostrarArrayChar(nombres[i], CANTIDAD_NOMBRES);
					}
					system("pause");
					break;
			}

		}

	}while(opcionMenu != 5);


	return EXIT_SUCCESS;
}

