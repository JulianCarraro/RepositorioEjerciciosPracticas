/*
 ============================================================================
 Name        : Sabado_Ejercicio5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "entidades.h"

int main(void) {

	User user[3] = {{1, "Julian"}, {2, "Marcelo"}, {3, "Zoe"}};
	Posteo posteo[3] = {{1000, "La vida es una", 1}, {1001, "Aguante River Plate", 2}, {1002, "Perdio Boca", 3}};
	Hashtag hashtag[3] = {{3000, "#VIVALAFRA"}, {3001, "#ELMASGRANDELEJOS"}, {3002, "#SIEMPRE"}};
	Relacion relacion[3] = {{3000, 1000}, {3001, 1001}, {3002, 1002}};

	return EXIT_SUCCESS;
}
