/*
 * utn.c
 *
 *  Created on: 7 abr. 2022
 *      Author: carra
 */

#include "bibliotecaUtn.h"
#include <stdio.h>


/// @brief --> suma 2 numeros
///
/// @param --> pNumeroIngresado Este parametro retorna el numero ingresado por puntero
/// @param --> mensaje Aca va el mensaje
/// @param --> mensajeError Aca va el mensaje erroneo
/// @param --> maximo En este parametro, indicamos el maximo numero entero que se puede ingresar
/// @param --> minimo En este parametro, indicamos el minimo numero entero que se puede ingresar
/// @param --> maximoDeReintentos
/// @return -->
int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}



