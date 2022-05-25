/*
 * estructuraCensista.c
 *
 *  Created on: 25 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estructuraVivienda.h"
#include "utn.h"
#include "estructuraCensista.h"

/*
typedef struct{
	int legajoCensista;
	char nombre[50];
	int edad;
	char telefono[12];
} eCensista;
*/
int mostrarCensistas(eCensista* censistas, int cantidadCensistas)
{
	int retorno;
	eCensista* limitePunteroCensistas;

	retorno = -1;

	if(censistas !=NULL && cantidadCensistas >-1)
	{
		limitePunteroCensistas= censistas +cantidadCensistas;

		printf("\n_____________________________Lista de Censistas____________________________\n");
		printf("|%*s|%*s|%*s|%*s|\n",-6, "Legajo", -49, "Nombre", -4, "Edad", -12, "Telefono");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		for(;censistas<limitePunteroCensistas;censistas++)
		{
				printf("|%*d|%*s|%*d|%*s|\n", -6, censistas->legajoCensista, -49, censistas->nombre, -4, censistas->edad, -12, censistas->telefono);
		}
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		retorno=0;
	}
	return retorno;
}
