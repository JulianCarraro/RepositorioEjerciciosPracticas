/*
 * passenger.h
 *
 *  Created on: 8 may. 2022
 *      Author: Julian
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
} Passenger;

int initPassengers(Passenger * list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

int buscarIndexPorIsEmpty(Passenger pArray[], int len);

void mostrarPassenger(Passenger unPassenger);

int incrementarId();

int modifyPassenger(Passenger list[], int len, int idPassenger);

int buscarIndexPorId(Passenger list[], int len, int id);

#endif /* PASSENGER_H_ */


