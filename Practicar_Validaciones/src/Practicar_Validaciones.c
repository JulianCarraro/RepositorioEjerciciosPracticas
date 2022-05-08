/*
 ============================================================================
 Name        : Practicar_Validaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"

#define LEN_DNI 8

int getDni(int pArray[], int len);

int main(void) {

	int dni[LEN_DNI];

	getDni(dni, LEN_DNI);

	return EXIT_SUCCESS;
}


