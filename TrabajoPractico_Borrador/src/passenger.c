/*
 * passenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaUtn.h"
#include "passenger.h"

int initPassengers(Passenger * list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
	}

	return retorno;

}

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = -1;
	int indexLibre;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[10];
	int flag;

	if (list != NULL && len > 0)
	{
		indexLibre = buscarIndexPorIsEmpty(list, len);
		if (indexLibre != -1)
		{
			if(getChar(auxName, sizeof(auxName), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
					3)==0)
			{
				strncpy(list[indexLibre].name, auxName, sizeof(list[indexLibre].name));
				flag = 1;
			}
		}
		if(flag == 1)
		{
			flag = 0;
			if(getChar(auxLastName, sizeof(auxLastName), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
					3)==0)
			{
				strncpy(list[indexLibre].lastName, auxLastName, sizeof(list[indexLibre].lastName));
				flag = 1;
			}
		}
		if(flag == 1)
		{
			flag = 0;
			if(getFloat(&auxPrice, "Ingrese el precio del vuelo: ", "ERROR. Ingreso un precio invalido\n\n",
					1500000, 0, 3)==0)
			{
				list[indexLibre].price = auxPrice;
				flag = 1;
			}

		}
		if(flag == 1)
		{
			if(getInt(&auxTypePassenger, "1. Primera Clase \n2. Clase Business\n3. Clase Economica Premium\n4. Clase Economica\n"
					"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n\n",
					3, 1, 3)==0)
			{
				list[indexLibre].typePassenger = auxTypePassenger;
				flag = 1;
			}
		}
		if(flag == 1)
		{
			if(getCodeChar(auxFlyCode, sizeof(auxFlyCode), "Ingrese el codigo de vuelo: ", "ERROR. Ingreso un codigo de vuelo invalido\n\n" , 3)==0)
			{
				strncpy(list[indexLibre].flycode, auxFlyCode, sizeof(list[indexLibre].flycode));
				retorno = 0;

			}
		}
		list[indexLibre].id = incrementarId();
		list[indexLibre].isEmpty = 0;
		mostrarPassenger(list[indexLibre]);

	}


	return retorno;
}

int buscarIndexPorIsEmpty(Passenger pArray[], int len)
{
	int retorno = -1;

		if(pArray != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(pArray[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

int incrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

void mostrarPassenger(Passenger unPassenger)
{
	if(unPassenger.isEmpty == 0)
	{
		printf("\nID DEL PASAJERO: %d\n NOMBRE: %s\n APELLIDO: %s\n PRECIO DEL VUELO: %.2f\n TIPO DE PASAJERO: %d\n CODIGO DE VUELO: %s\n",
				unPassenger.id, unPassenger.name, unPassenger.lastName, unPassenger.price, unPassenger.typePassenger, unPassenger.flycode);
	}
}

int modifyPassenger(Passenger list[], int len, int idPassenger)
{
	int retorno = -1;
	int index;
	int opcionMenu;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[10];

	if (list != NULL && len > 0 && idPassenger > 0)
	{
        index = buscarIndexPorId(list, len, idPassenger);

    	if (index != -1)
    	{
            mostrarPassenger(list[index]);

			do{
				if(menuModificaciones(&opcionMenu)==0)
				{
					switch(opcionMenu)
					{
						case 1:
							if(getChar(auxName, sizeof(auxName), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
									3)==0)
							{
								strncpy(list[index].name, auxName, sizeof(list[index].name));
								retorno = 0;
							}
							else
							{
								retorno = -1;
							}
							break;
						case 2:
							if(getChar(auxLastName, sizeof(auxLastName), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
									3)==0)
							{
								strncpy(list[index].lastName, auxLastName, sizeof(list[index].lastName));
								retorno = 0;
							}
							else
							{
								retorno = -1;
							}
							break;
						case 3:
							if(getFloat(&auxPrice, "Ingrese el precio del vuelo: ", "ERROR. Ingreso un precio invalido\n\n",
									1500000, 0, 3)==0)
							{
								list[index].price = auxPrice;
								retorno = 0;
							}
							else
							{
								retorno = -1;
							}
							break;
						case 4:
							if(getInt(&auxTypePassenger, "1. Primera Clase \n2. Clase Business\n3. Clase Economica Premium\n4. Clase Economica\n"
									"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n\n",
									3, 1, 3)==0)
							{
								list[index].typePassenger = auxTypePassenger;
								retorno = 0;
							}
							else
							{
								retorno = -1;
							}
							break;
						case 5:
							if(getCodeChar(auxFlyCode, sizeof(auxFlyCode), "Ingrese el codigo de vuelo: ", "ERROR. Ingreso un codigo de vuelo invalido\n\n" , 3)==0)
							{
								strncpy(list[index].flycode, auxFlyCode, sizeof(list[index].flycode));
								retorno = 0;
							}
							else
							{
								retorno = -1;
							}
							break;
						case 6:
							break;
					}
				}

			}while(opcionMenu != 6);




	    }
    	else
    	{
    		printf("No hay asociado con ese ID\n");
    		system("pause");
    	}
	}
	return retorno;
}

int buscarIndexPorId(Passenger list[], int len, int id) {
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
