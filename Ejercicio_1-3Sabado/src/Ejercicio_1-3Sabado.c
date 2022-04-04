/*
 ============================================================================
 Name        : Ejercicio_1-3Sabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)

 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char respuesta;
	int legajo;
	char tipoCursada;
	int cantidadDeMaterias;
	char sexo;
	int notaPromedio;
	int edad;
	int contadorFemenino;
	int acumuladorNotaFemenino;
	int contadorMasculino;
	int acumuladorNotaMasculino;
	int acumuladorNotaNoBinario;
	int contadorNoBinario;
	int mejorNotaPromedioFem;
	int flagFemenino;
	int legajoMejorPromedioFem;
	int MasJovenMasculino;
	int flagJovenMasculino;
	int legajoJovenMasculinoLibre;
	int maximoDeMaterias;
	int flagMaximoMaterias;
	int edadDelQueMasCursa;
	int legajoDelQueMasCursa;
	float promedioFemenino;
	float promedioMasculino;
	float promedioNoBinario;

	respuesta = 's';
	contadorFemenino = 0;
	acumuladorNotaFemenino = 0;
	contadorMasculino = 0;
	acumuladorNotaMasculino = 0;
	contadorNoBinario = 0;
	acumuladorNotaNoBinario = 0;
	flagFemenino = 1;
	flagJovenMasculino = 1;
	flagMaximoMaterias = 1;

	while(respuesta == 's')
	{
		printf("Ingrese el Legajo: ");
		scanf("%d", &legajo);

		printf("Ingrese el tipo de cursada ('l': libre - 'p': presencial – 'r': remota): ");
		fflush(stdin);
		scanf("%c", &tipoCursada);

		while(tipoCursada != 'l' && tipoCursada != 'p' && tipoCursada != 'r')
		{
			printf("ERROR. Ingrese el tipo de cursada ('l': libre - 'p': presencial – 'r': remota): ");
			fflush(stdin);
			scanf("%c", &tipoCursada);
		}

		printf("Ingrese la cantidad de materias (mas de cero y menos de 8): ");
		scanf("%d", &cantidadDeMaterias);

		while(cantidadDeMaterias <= 0 || cantidadDeMaterias > 8)
		{
			printf("ERROR. Ingrese la cantidad de materias (mas de cero y menos de 8): ");
			scanf("%d", &cantidadDeMaterias);
		}

		printf("Ingrese el sexo: ('f'femenino, 'm'masculino, 'o'no binario): ");
		fflush(stdin);
		scanf("%c", &sexo);

		while(sexo != 'f' && sexo != 'm' && sexo != 'o')
		{
			printf("ERROR. Ingrese el sexo: ('f'femenino, 'm'masculino, 'o'no binario): ");
			fflush(stdin);
			scanf("%c", &sexo);
		}

		printf("Ingrese la nota promedio (entre 0 y 10): ");
		scanf("%d", &notaPromedio);

		while(notaPromedio < 0 || notaPromedio > 10)
		{
			printf("ERROR. Ingrese una nota promedio valida (entre 0 y 10): ");
			scanf("%d", &notaPromedio);
		}

		printf("Ingrese su edad: ");
		scanf("%d", &edad);

		while(edad < 0)
		{
			printf("ERROR. Ingrese una edad valida: ");
			scanf("%d", &edad);
		}

		switch(sexo)
		{
			case 'f':
				contadorFemenino++;
				acumuladorNotaFemenino += notaPromedio;
				if(notaPromedio > mejorNotaPromedioFem || flagFemenino == 1)
				{
					mejorNotaPromedioFem = notaPromedio;
					legajoMejorPromedioFem = legajo;
					flagFemenino = 0;
				}
			break;
			case 'm':
				contadorMasculino++;
				acumuladorNotaMasculino += notaPromedio;
				if(tipoCursada == 'l')
				{
					if(edad < MasJovenMasculino || flagJovenMasculino == 1)
					{
						MasJovenMasculino = edad;
						legajoJovenMasculinoLibre = legajo;
						flagJovenMasculino = 0;
					}
				}
			break;
			case 'o':
				contadorMasculino++;
				acumuladorNotaNoBinario += notaPromedio;
			break;
		}

		if(cantidadDeMaterias > maximoDeMaterias || flagMaximoMaterias == 1)
		{
			maximoDeMaterias = cantidadDeMaterias;
			edadDelQueMasCursa = edad;
			legajoDelQueMasCursa = legajo;
			flagMaximoMaterias = 0;
		}


		respuesta = printf("Quiere ingresar otro dato? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);

	}

	if(contadorFemenino > 0)
	{
		printf("El legajo del mejor promedio femenino es %d \n", legajoMejorPromedioFem);
		promedioFemenino = (float)acumuladorNotaFemenino / contadorFemenino;
	}
	else
	{
		printf("No hay alumnos del sexo femenino \n");
		promedioFemenino = 0;
	}

	if(contadorMasculino > 0)
	{
		promedioMasculino = (float)acumuladorNotaMasculino / contadorMasculino;
		if(flagJovenMasculino == 0)
		{
			printf("El legajo del mas joven de los alumnos masculinos entre los que dan libre es %d \n", legajoJovenMasculinoLibre);
		}
		else
		{
			printf("No hay alumnos del sexo masculino que den libre \n");
		}
	}
	else
	{
		printf("No hay alumnos del sexo masculino \n");
		promedioMasculino = 0;
	}

	if(contadorNoBinario > 0)
	{
		promedioNoBinario = (float)acumuladorNotaNoBinario / contadorNoBinario;
	}
	else
	{
		promedioNoBinario = 0;
	}

	printf("El promedio de nota del sexo Femenino es %.2f \n", promedioFemenino);
	printf("El promedio de nota del sexo Masculino es %.2f \n", promedioMasculino);
	printf("El promedio de nota del sexo No Binario es %.2f \n", promedioNoBinario);
	printf("La edad del que cursa mas materias es %d, y el legajo es %d \n", edadDelQueMasCursa, legajoDelQueMasCursa);

	return EXIT_SUCCESS;
}
