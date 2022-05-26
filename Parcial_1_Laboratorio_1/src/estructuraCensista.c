/*
 * estructuraCensista.c
 *
 *  Created on: 25 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include "estructuraCensista.h"

int mostrarCensistas(eCensista* censistas, int cantidadCensistas)
{
	int retorno;
	eCensista* limitePunteroCensistas;

	retorno = -1;

	if(censistas !=NULL && cantidadCensistas >-1)
	{
		limitePunteroCensistas= censistas +cantidadCensistas;

		printf("\n_____________________________Lista de Censistas_____________________________\n");
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
