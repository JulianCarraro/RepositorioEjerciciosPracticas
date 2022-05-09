/*
 ============================================================================
 Name        : TrabajoPractico_Borrador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "passenger.h"

#define LEN_PASSENGER 2000
#define LEN_NAME 51
#define LEN_LASTNAME 51
#define LEN_FLYCODE 10

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int id = 0;
	char name[LEN_NAME];
	char lastName[LEN_LASTNAME];
	float price = 0;
	int typePassenger = 0;
	char flyCode[LEN_FLYCODE];
	Passenger passenger[LEN_PASSENGER];

	initPassengers(passenger, LEN_PASSENGER);

	do
	{
		if(menuPrincipal(&opcionMenu)==0)
		{
			switch(opcionMenu)
			{
				case 1:
					printf("ALTAS\n\n");
					if(addPassenger(passenger, LEN_PASSENGER, id, name,
							lastName, price, typePassenger, flyCode)==0)
					{
						printf("¡¡¡¡¡CARGA EXITOSA!!!!!\n\n");
//						system("pause");
					}
					break;
				case 2:
					printf("MODIFICAR\n\n");
			}
		}

	}while(opcionMenu != 5);


	return EXIT_SUCCESS;
}

