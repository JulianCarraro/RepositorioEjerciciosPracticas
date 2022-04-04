/*
 ============================================================================
 Name        : EjercicioPruebaFunciones
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
*/

/* Pedir dos notas y mostrar el promedio
*/

#include <stdio.h>
#include <stdlib.h>

float calculaPromedioDeDosEnteros(int primerEntero,int segundoEntero);
int pedirDatoNumericoInt();

int main(void) {
	setbuf(stdout, NULL);
	int notaUno;
	int notaDos;
	float promedioDeNota;

	notaUno = pedirDatoNumericoInt();
	notaDos = pedirDatoNumericoInt();

	promedioDeNota = calculaPromedioDeDosEnteros(notaUno,notaDos);
	if(promedioDeNota <= 4){
		printf("Te fue mal");
	}else{
		printf("Tu promedio es: %.2f", promedioDeNota);
	}

	return 0;
}

float calculaPromedioDeDosEnteros(int primerEntero,int segundoEntero){
	float promedioEnteros;

	promedioEnteros = (primerEntero + segundoEntero) / (float)2;

	return promedioEnteros;
}

int pedirDatoNumericoInt(){
	int datoPedido;

	printf("Ingrese un numero: ");
	scanf("%d", &datoPedido);

	return datoPedido;
}
