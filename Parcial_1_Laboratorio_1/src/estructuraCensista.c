/*
 * estructuraCensista.c
 *
 *  Created on: 25 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuraCensista.h"
#include "estructuraVivienda.h"

/*int mostrarCensistas(eCensista* censistas, int cantidadCensistas)
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
*/
int mostrarCensistasConCantidadDeViviendas(eCensista* censistas, int cantidadCensistas, eVivienda* viviendas, int viviendasCensadas)
{
	int retorno;
	char tipoDeVivienda[15];
	eCensista* limitePunteroCensistas;
	eVivienda* limitePunteroViviendas;
	eVivienda* punteroAViviendas;

	retorno = -1;

	if(censistas !=NULL && cantidadCensistas >0 && viviendas !=NULL && viviendasCensadas > 0)
	{
		limitePunteroCensistas= censistas +cantidadCensistas;
		limitePunteroViviendas= viviendas +viviendasCensadas;

		for(;censistas<limitePunteroCensistas;censistas++)
		{
			punteroAViviendas = viviendas;
			printf("\n__________________________________Censista__________________________________\n");
			printf("|%*s|%*s|%*s|%*s|\n",-6, "Legajo", -49, "Nombre", -4, "Edad", -12, "Telefono");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*d|%*s|%*d|%*s|\n", -6, censistas->legajoCensista, -49, censistas->nombre, -4, censistas->edad, -12, censistas->telefono);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("\n_________________________________Lista de Viviendas_______________________\n");
			printf("|%*s|%*s|%*s|%*s|%*s|\n",-5, "ID", -25, "Calle", -10, "Inquilinos", -12, "Habitaciones", -16, "Tipo de vivienda");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			for(;punteroAViviendas<limitePunteroViviendas;punteroAViviendas++)
			{
				if(punteroAViviendas->legajoCensista == censistas->legajoCensista)
				{
					if(punteroAViviendas->isEmpty == 0)
					{
						switch(punteroAViviendas->tipoVivienda)
						{
							case 1: strcpy(tipoDeVivienda,"Casa");
								break;

							case 2: strcpy(tipoDeVivienda,"Departamento");
								break;

							case 3: strcpy(tipoDeVivienda,"Casilla");
								break;

							default:	strcpy(tipoDeVivienda,"Rancho");
								break;
						}

						printf("|%*d|%*s|%*d|%*d|%*s|\n", -5, punteroAViviendas->id, -25, punteroAViviendas->calle, -10, punteroAViviendas->cantidadPersonas, -12, punteroAViviendas->cantidadHabitaciones, -16, tipoDeVivienda);
					}
					printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				}
			}
			printf("\n\n");
		}
		retorno=0;
	}
	return retorno;
}

int cencistaConMasViviendas(eCensista* censistas, int cantidadCensistas, int legajoCensista)
{
	int retorno;
	eCensista* limitePunteroCensista;
	limitePunteroCensista = censistas+ cantidadCensistas;

	retorno =1;

	if(censistas != NULL && cantidadCensistas > 0)
	{
		for(;censistas<limitePunteroCensista; censistas++)
		{
			if(censistas->legajoCensista == legajoCensista)
			{

			}
		}
	}

	return retorno;
}

