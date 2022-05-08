/*
 * llamado.c
 *
 *  Created on: 5 may. 2022
 *      Author: carra
 */

#include <stdio.h>
#include "llamado.h"
#include "asociado.h"

int inicializarLlamada(Llamada pArray[], int len) {
	int retorno = -1;
	if (pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pArray[i].isEmpty = 1;
		}
	}

	return retorno;
}

int nuevaLLamada(Llamada pArray[], int len) {
	int retorno = -1;
	int indexLibre;
	char auxNombre[256];
	char auxApellido[256];
	int auxEdad;
	int auxDni;
	int flag;

	flag = 0;

	if (pArray != NULL && len > 0) {

		indexLibre = buscarIndexPorIsEmpty(pArray, len);

		if (indexLibre != -1) {
			if(getChar(auxNombre, sizeof(auxNombre), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
					3)==0)
			{
				strncpy(pArray[indexLibre].nombre, auxNombre, sizeof(pArray[indexLibre].nombre));
				flag = 1;
			}
			if(flag == 1)
			{
				flag = 0;
				if(getChar(auxApellido, sizeof(auxApellido), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
						3)==0)
				{
					strncpy(pArray[indexLibre].apellido, auxApellido, sizeof(pArray[indexLibre].apellido));
					flag = 1;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxEdad, "Ingrese una edad: ", "ERROR. Ingreso una edad invalida\n\n",
						120, 0, 3)==0)
				{
					pArray[indexLibre].edad = auxEdad;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				if(getDni(&auxDni)==0)
				{
					pArray[indexLibre].dni = auxDni;
					flag = 1;
					retorno = 0;
				}
				pArray[indexLibre].idAsociado = incrementarId();
				pArray[indexLibre].isEmpty = 0;
				mostrarAsociado(pArray[indexLibre]);
			}
		}
	}

	return retorno;
}

