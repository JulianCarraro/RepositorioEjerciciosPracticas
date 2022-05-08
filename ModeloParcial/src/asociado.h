/*
 * asociado.h
 *
 *  Created on: 5 may. 2022
 *      Author: carra
 */

#ifndef ASOCIADO_H_
#define ASOCIADO_H_

typedef struct {
    int idAsociado; // PK
    int dni;
    char nombre[125];
	char apellido [125];
	int edad;
	int isEmpty;
} Asociado;

int inicializarAsociado(Asociado pArray[], int len);
int buscarIndexPorIsEmpty(Asociado pArray[], int len);
int cargarAsociado(Asociado pArray[], int len);
int listarAsociado(Asociado pArray[], int len);
void mostrarAsociado(Asociado unAsociado);
int modificarAsociado(Asociado listaAsociados[], int len, int idAsociado);
int buscarIndexPorId(Asociado listaAsociados[], int len, int id);
int bajaAsociado(Asociado listaAsociados[], int len, int idAsociado);

#endif /* ASOCIADO_H_ */
