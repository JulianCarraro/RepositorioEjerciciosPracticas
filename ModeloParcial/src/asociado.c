/*
 * asociado.c
 *
 *  Created on: 5 may. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaUtn.h"
#include "asociado.h"
#include "llamado.h"

int incrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

int inicializarAsociado(Asociado pArray[], int len) {
	int retorno = -1;
	if (pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pArray[i].isEmpty = 1;
		}
	}

	return retorno;

}

int cargarAsociado(Asociado pArray[], int len) {
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

int buscarIndexPorIsEmpty(Asociado pArray[], int len)
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

void mostrarAsociado(Asociado unAsociado)
{
	if(unAsociado.isEmpty == 0)
	{
		printf("\nID DEL ASOCIADO: %d\n DNI: %d\n NOMBRE: %s\n APELLIDO: %s\n EDAD: %d\n",
				unAsociado.idAsociado, unAsociado.dni, unAsociado.nombre, unAsociado.apellido, unAsociado.edad);
	}
}

int listarAsociado(Asociado pArray[], int len)
{
	int retorno = -1;

	if(pArray != NULL && len >0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarAsociado(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int buscarIndexPorId(Asociado listaAsociados[], int len, int id) {
	int retorno = -1;
	if (listaAsociados != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (listaAsociados[i].idAsociado == id && listaAsociados[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int modificarAsociado(Asociado listaAsociados[], int len, int idAsociado)
{
	int retorno = -1;
	int index;
	char auxNombre[256];
	char auxApellido[256];
	int flag;

	flag = 0;

	if (listaAsociados != NULL && len > 0 && idAsociado > 0)
	{
        index = buscarIndexPorId(listaAsociados, len, idAsociado);

    	if (index != -1)
    	{
            mostrarAsociado(listaAsociados[index]);

			if(getChar(auxNombre, sizeof(auxNombre), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
					3)==0)
			{
				strncpy(listaAsociados[index].nombre, auxNombre, sizeof(listaAsociados[index].nombre));
				flag = 1;
			}
			if(flag == 1)
			{
				if(getChar(auxApellido, sizeof(auxApellido), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
						3)==0)
				{
					strncpy(listaAsociados[index].apellido, auxApellido, sizeof(listaAsociados[index].apellido));
					retorno = 0;
				}
			}
	    }
    	else
    	{
    		printf("No hay asociado con ese ID\n");
    		system("pause");
    	}
	}
	return retorno;
}

int bajaAsociado(Asociado listaAsociados[], int len, int idAsociado) {
	int retorno = -1;
	int index;
	if (listaAsociados != NULL && len > 0 && idAsociado > 0) {

		index = buscarIndexPorId(listaAsociados, len, idAsociado);

		if (index != -1)
		{
			mostrarAsociado(listaAsociados[index]);
			listaAsociados[index].isEmpty = 1;
			retorno = 0;
		}
    	else
    	{
    		printf("No hay asociado con ese ID\n");
    		system("pause");
    	}
	}

	return retorno;
}


