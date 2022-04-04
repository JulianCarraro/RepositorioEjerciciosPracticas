/*
 ============================================================================
 Name        : Ejercicio2-3.c
 Author      : Julian Carraro
 Version     : 1E
 ============================================================================
*/
/*
 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
 de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
 */

#include <stdio.h>
#include <stdlib.h>

#define DESCUENTO 0.75

int main(void) {
	setbuf(stdout, NULL);

	int numeroCliente;
	char estadoCivil;
	int edad;
	float temperatura;
	char sexo;
	int precioPorPasajero;
	int contadorViudosMayores;
	int flagSolteraMasJoven;
	int edadMujerMasJoven;
	char respuesta;
	int numeroClienteMujerMasJoven;
	int precioTotalSinDescuento;
	int contadorPasajeros;
	int contadorMayoresSesenta;
	int contadorMenoresSesenta;
	float precioTotalConDescuento;

	precioPorPasajero = 600;
	contadorViudosMayores = 0;
	flagSolteraMasJoven = 0;
	respuesta = 's';
	contadorPasajeros = 0;
	contadorMayoresSesenta = 0;
	contadorMenoresSesenta = 0;

	while(respuesta == 's')
	{
		contadorPasajeros++;

		printf("Ingrese numero de cliente: ");
		scanf("%d", &numeroCliente);

		printf("Ingrese el estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);

		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
		{
			printf("ERROR. Ingrese el estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}

		printf("Ingrese la edad: (solo mayores de edad, más de 17): ");
		scanf("%d", &edad);

		while(edad < 18)
		{
			printf("ERROR. Ingrese la edad: (solo mayores de edad, más de 17): ");
			scanf("%d", &edad);
		}

		printf("Ingrese la temperatura corporal: ");
		scanf("%f", &temperatura);

		while(temperatura < 32 || temperatura > 47)
		{
			printf("ERROR. Ingrese una temperatura corporal valida: ");
			scanf("%f", &temperatura);
		}

		printf("Ingrese el sexo ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
		fflush(stdin);
		scanf("%c", &sexo);

		while(sexo != 'f' && sexo != 'm' && sexo != 'o')
		{
			printf("ERROR. Ingrese el sexo ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
			fflush(stdin);
			scanf("%c", &sexo);
		}

		if(edad > 60)
		{
			contadorMayoresSesenta++;
			if(estadoCivil == 'v')
			{
				contadorViudosMayores++;
			}
		}
		else
		{
			contadorMenoresSesenta++;
		}

		if(sexo == 'f' && estadoCivil == 's')
		{
			if(edad < edadMujerMasJoven || flagSolteraMasJoven == 0)
			{
				edadMujerMasJoven = edad;
				numeroClienteMujerMasJoven = numeroCliente;
				flagSolteraMasJoven = 1;
			}
		}

		respuesta = printf("Quiere ingresar otro dato? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);

	}

	precioTotalSinDescuento = precioPorPasajero * contadorPasajeros;

	printf("Hay %d personas con estado viudo de mas de 60 años \n", contadorViudosMayores);

	if(flagSolteraMasJoven == 1)
	{
		printf("El numero de cliente de la mujer soltera mas joven es %d y su edad es %d \n" , numeroClienteMujerMasJoven,
				edadMujerMasJoven);
	}
	else
	{
		printf("No hay mujeres solteras \n");
	}

	printf("El viaje total sin descuento es $%d \n", precioTotalSinDescuento);

	if(contadorMayoresSesenta > contadorMenoresSesenta)
	{
		precioTotalConDescuento = precioTotalSinDescuento * DESCUENTO;
		printf("Al haber mas pasajeros tienen mas de 60 años, el precio final del viaje sera $%.2f", precioTotalConDescuento);
	}

	return EXIT_SUCCESS;
}
