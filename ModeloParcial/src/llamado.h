/*
 * llamado.h
 *
 *  Created on: 5 may. 2022
 *      Author: carra
 */

#ifndef LLAMADO_H_
#define LLAMADO_H_

typedef struct {
    int idLlamada;
    int estado;
	int motivo;
	int idAsociado; // FK
    int idAmbulancia;
	float tiempoInsumido;
	int isEmpty;
} Llamada;

int inicializarLlamada(Llamada pArray[], int len);


#endif /* LLAMADO_H_ */
