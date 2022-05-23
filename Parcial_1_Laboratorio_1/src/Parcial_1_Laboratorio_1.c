/*
 ============================================================================
 Name        : Parcial_1_Laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 A. ALTA VIVENDA
B. MODIFICAR VIVIENDA: Se ingresará el idVivienda, permitiendo en un submenú modificar:
● la calle
● la cantidad de las personas
● la cantidad de habitaciones
● el tipo de vivienda
C. BAJA VIVIENDA: Se ingresará el idVivienda y se realizará una baja lógica.
D. LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
 de calle por cantidad de personas.
E. LISTAR CENSISTAS

 //Censista ({100, Ana, 34, 1203-2345}, {101, Juan, 24, 4301-54678}, {102, Sol, 47, 5902-37487} )
 */

#include <stdio.h>
#include <stdlib.h>
#include "estructuraVivienda.h"
#include "estructuraCensista.h"
#define VIVIENDAS_A_CENSAR 15






int main(void) {
	setbuf(stdout,NULL);

	int id;
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int banderaMantenerseEnElMenu;
	int chequeoErrorMenuPrincipal;
	char calle[26];
	char opcionMenuPrincipal;

	banderaMantenerseEnElMenu =1;


	eVivienda viviendas[VIVIENDAS_A_CENSAR];
	eCensista censistas[]={ {100, "Ana", 34,1203-2345},
			{101, "Juan", 24, 4301-54678},
			{102, "Sol", 47, 5902-37487}};

	do{

		printf("---------------------OPCIONES-----------------------\n"
				"A. Alta vivienda.\n"
				"B. Modificar vivienda\n"
				"C. Baja vivienda\n"
				"D. Listar viviendas\n"
				"E. Listar censistas\n\n");

		if(1)
		{
			switch(opcionMenuPrincipal)
			{
				case 'A':
					break;

				case 'B':
					break;

				case 'C':
					break;

				case 'D':
					break;

				case 'E':
					break;

				default: banderaMantenerseEnElMenu=0;
					break;
			}
		}


	}while(banderaMantenerseEnElMenu);


	return EXIT_SUCCESS;
}
