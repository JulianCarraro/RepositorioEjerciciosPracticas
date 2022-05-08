/*
 ============================================================================
 Name        : ModeloParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "asociado.h"
#include "llamado.h"

#define LEN_ASOCIADOS 5
#define LEN_LLAMADA 5

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int auxId;
	int idIngresado;
	int flag = 0;
	Asociado asociados[LEN_ASOCIADOS];
	Llamada llamado[LEN_LLAMADA];
    inicializarAsociado(asociados, LEN_ASOCIADOS);
    inicializarLlamada(llamado, LEN_LLAMADA);

	do
	{
//		system("cls");
		if(menuPrincipal(&opcionMenu)==0)
		{
			switch(opcionMenu)
			{
				case 1:
					printf("ALTA DEL ASOCIADO\n\n");
					if(cargarAsociado(asociados, LEN_ASOCIADOS)==0)
					{
						printf("\n　　　CARGA EXISTOSA!!!!!!!\n");
						flag = 1;
					}
//					system("pause");
					break;
				case 2:
					if(flag == 1)
					{
						printf("MODIFICAR DATOS DEL ASOCIADO\n");
						listarAsociado(asociados, LEN_ASOCIADOS);
						if(getInt(&auxId, "Ingrese el id del asociado que desea modificar: ",
								"Error, el id no es valido", 10000,
								1000, 3)==0)
						{
							idIngresado = auxId;
						}
						if(modificarAsociado(asociados, LEN_ASOCIADOS, idIngresado) == 0)
						{
							listarAsociado(asociados, LEN_ASOCIADOS);
							system("pause");
						}
					}
					else
					{
						printf("Debe ingresar un asociado antes de avanzar\n\n");
					}
					break;
				case 3:
					if(flag == 1)
					{
						printf("BAJA DEL ASOCIADO\n");
						listarAsociado(asociados, LEN_ASOCIADOS);
						if(getInt(&auxId, "Ingrese el id del asociado que desea dar de baja: ",
								"Error, el id no es valido", 10000,
								1000, 3)==0)
						{
							idIngresado = auxId;
						}
						if(bajaAsociado(asociados, LEN_ASOCIADOS, idIngresado) == 0)
						{
							listarAsociado(asociados, LEN_ASOCIADOS);
							printf("\n　　　BAJA EXISTOSA!!!!!!!\n");
							system("pause");
						}
					}
					else
					{
						printf("Debe ingresar un asociado antes de avanzar\n\n");
					}
					break;
				case 4:
					printf("NUEVA LLAMADA\n");

			}
		}
		else
		{
			printf("Hasta luego");
			break;
		}

	}while(opcionMenu != 7);

	return EXIT_SUCCESS;
}
