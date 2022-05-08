/*
 ============================================================================
 Name        : Ejercicio_Menu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Se deben hacer los ejercicios en orden. Al ingresar a cada punto de menú se debe indicar dónde estoy y al apretar una tecla salir del mismo.
 es decir que cada opción no tiene funcionalidad extra. En cualquier caso informar que está sucediendo: Ejemplo: "Primero se debe loguear".

 A- Hacer el menú de un programa con las siguientes opciones: 1. Loguearse, 2. Comprar, 3. Ver mis compras,
 4. Vender, 5. Salir
 B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
 C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar al menos una vez
 D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga: 1. Vender 2. Hacer factura 3. Volver atrás
 E- A lo anterior sumarle que haya compras para poder vender. (Si compré una vez y vendí una vez no puedo ingresar a vender).
 F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca

 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionesDelMenu;
	int validacionRetorno;
	char nombreDeLogueo;
	int flagMenu;
	int comprar;
	int vender;
	int ventaDeProducto;
	int contadorAutos;
	int contadorCamionetas;
	int contadorMotos;

	flagMenu = 0;
	contadorAutos = 0;
	contadorCamionetas = 0;
	contadorMotos = 0;

	do {
		printf("\nMENU PRINCIPAL \n\n");
		printf("1) Loguearse\n");
		printf("2) Comprar\n");
		printf("3) Ver mis compras\n");
		printf("4) Vender\n");
		printf("5) Salir\n");

		validacionRetorno = getInt(&opcionesDelMenu, "Ingrese una opcion: ",
				"La opcion es incorrecta\n", 5, 1, 1);

		if(validacionRetorno == 0) {
			if(opcionesDelMenu == 1 || flagMenu == 1 || opcionesDelMenu == 5) {
				switch (opcionesDelMenu) {
				case 1:
					if (flagMenu == 0) {
						printf("Ingrese el nombre de su cuenta: ");
						scanf("%s", &nombreDeLogueo);
						flagMenu = 1;
					} else {
						printf("Ya esta logueado\n");
					}
					break;
				case 2:
					do {
						printf("\nMENU DE COMPRAS \n\n");
						printf("1) Auto\n");
						printf("2) Camioneta\n");
						printf("3) Moto\n");
						printf("4) Salir\n");

						validacionRetorno = getInt(&comprar,
								"Que quiere comprar? \n",
								"La opcion es incorrecta\n\n", 4, 1, 5);
						if (validacionRetorno == 0) {
							switch (comprar) {
							case 1:
								printf("Se ha sumado un auto al carrito\n");
								contadorAutos++;
								break;
							case 2:
								printf("Se ha sumado una camioneta al carrito\n");
								contadorCamionetas++;
								break;
							case 3:
								printf("Se ha sumado una moto al carrito\n");
								contadorMotos++;
								break;
							case 4:
								break;
							}
						}
					} while (comprar != 4);

					break;
				case 3:
					if (contadorAutos > 0 || contadorCamionetas > 0
							|| contadorMotos > 0) {
						printf("\nMIS COMPRAS\n\n");
						printf("Autos %d\n", contadorAutos);
						printf("Camionetas %d\n", contadorCamionetas);
						printf("Motos %d\n", contadorMotos);
						system("pause");
					} else {
						printf("No tiene nada comprado\n");
					}
					break;
				case 4:
					if (contadorAutos > 0 || contadorCamionetas > 0
							|| contadorMotos > 0) {
						do {
							printf("\nVENTAS\n\n");
							printf("1) Vender\n");
							printf("2) Hacer facturas\n");
							printf("3) Volver atras\n");

							validacionRetorno = getInt(&vender,
									"Elije una opcion? ",
									"La opcion es incorrecta", 3, 1, 5);
							if (validacionRetorno == 0) {
								switch (vender) {
								case 1:
									do {
										printf("\n1) Auto\n");
										printf("2) Camioneta\n");
										printf("3) Moto\n");
										printf("4) Salir\n");

										validacionRetorno = getInt(
												&ventaDeProducto,
												"Que desea vender? ",
												"La opcion es incorrecta ", 4,
												1, 5);

										switch (ventaDeProducto) {
										case 1:
											if(contadorAutos > 0)
											{
												printf("Se ha vendido un auto\n\n");
												contadorAutos--;
											}
											else
											{
												printf("No tiene ningun auto\n\n");
											}
											break;
										case 2:
											if(contadorCamionetas > 0)
											{
												printf("Se ha vendido una camioneta\n\n");
												contadorCamionetas--;
											}
											else
											{
												printf("No tiene ninguna camioneta\n\n");
											}
											break;
										case 3:
											if(contadorMotos > 0)
											{
												printf("Se ha vendido una moto\n\n");
												contadorMotos--;
											}
											else
											{
												printf("No tiene ninguna moto\n\n");
											}
											break;
										case 4:
											break;
										}
									} while (ventaDeProducto != 4);

									break;
								case 2:
									printf(
											"Hemos finalizado de hacer su factura\n");
									break;
								case 3:
									break;
								}
							}
						} while (vender != 3);

					}
					else
					{
						printf("No ha comprado ningun producto \n");
					}
					break;
				}

			} else {
				printf("Primero debe loguearse\n");
			}

		}
	} while (opcionesDelMenu != 5);

	return 0;
}
