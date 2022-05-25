/*
 * estructuraVivienda.c
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estructuraVivienda.h"
#include "utn.h"

int inicializarViviendas(eVivienda* viviendas, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(viviendas !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			viviendas->isEmpty= 1;
			viviendas++;
		}
		retorno =0;
	}
	return retorno;
}

int agregarVivienda(eVivienda* vivienda, int len, int id, char* calle, int alturaCalle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista)
{
	int retorno;
	int i;

	retorno =-1;

	if(vivienda !=NULL && len > 0 && calle != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(vivienda->isEmpty == 1)
			{
				vivienda->id = id;
				strcpy(vivienda->calle, calle);
				vivienda->cantidadPersonas = cantidadPersonas;
				vivienda->cantidadHabitaciones= cantidadHabitaciones;
				vivienda->tipoVivienda= tipoVivienda;
				vivienda->legajoCensista=legajoCensista;
				vivienda->alturaCalle = alturaCalle;
				vivienda->isEmpty = 0;
				retorno =0;
				break;
			}
			vivienda++;
		}
	}
	return retorno;
}

int encontrarViviendaPorId(eVivienda* vivienda, int len,int id)
{
	int retorno;
	int i;

	retorno =-1;

	if(vivienda !=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(vivienda->isEmpty ==0)
			{
				if(vivienda->id == id)
				{
					retorno = i;
					break;
				}
			}
			vivienda++;
		}
	}
	return retorno;
}

int modificarViviendaPorId(eVivienda* vivienda, int posicionVivienda, int opcion, int cantidadMinimaLetrasCalleNombre,
		int cantidadMaximaLetrasCalleNombre,int alturaMinimaCalle, int alturaMaximaCalle, int cantidadMinimaPersonasPorCasa,
		int cantidadMaximaPersonasPorCasa, int cantidadMinimaHabitaciones, int cantidadMaximaHabitaciones, int minimaOpcionTipoVivienda,
		int maximaOpcionTipoVivienda)
{
	int retorno;
	int limiteCaracteres;

	retorno =-1;

	if(vivienda != NULL && posicionVivienda>-1)
	{
		vivienda += posicionVivienda;
		limiteCaracteres = 1+cantidadMaximaLetrasCalleNombre;
		retorno=0;
		switch(opcion)
		{
			case 1:
				utn_getNombreTamanioLimitado(vivienda->calle, "\nIngresa la calle de la vivienda: ", "Dato invalido. Ingresa la calle de la vivienda: ", cantidadMinimaLetrasCalleNombre, cantidadMaximaLetrasCalleNombre, limiteCaracteres);
				break;

			case 2:
				utn_getIntRango(&vivienda->alturaCalle, "\nIngresa la altura de la calle de la casa: ", "Dato invalido. Ingresa la altura de la calle de la vivienda: ", alturaMinimaCalle, alturaMaximaCalle);
				break;

			case 3:
				utn_getIntRango(&vivienda->cantidadPersonas, "\nIngrese la cantidad de personas que vivien en la casa: ", "Dato invalido. Ingrese la cantidad de personas que vivien en la casa: ", cantidadMinimaPersonasPorCasa, cantidadMaximaPersonasPorCasa);
				break;

			case 4:
				utn_getIntRango(&vivienda->cantidadHabitaciones, "\nIngrese la cantidad de habitaciones de la casa: ", "Dato invalido. Ingrese la cantidad de habitaciones de la casa: ", cantidadMinimaHabitaciones, cantidadMaximaHabitaciones);
				break;

			default:
				utn_getIntRango(&vivienda->tipoVivienda, "\nTipo de vivienda: \n1-Casa\n2-Departamento\n3-Casilla\n4-Rancho\nEscribir el numero correspondiente: ", "Dato invalido. Tipo de vivienda: \n1-Casa\n2-Departamento\n3-Casilla\n4-Rancho\nEscribir el numero correspondiente:  ", minimaOpcionTipoVivienda, maximaOpcionTipoVivienda);
				break;
			}
		}
	return retorno;
}

int removerVivienda(eVivienda* vivienda, int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(vivienda !=NULL && len > 0 && id>-1)
	{
		for(i=0;i<len;i++)
		{
			if(vivienda->id == id)
			{
				vivienda->isEmpty = 1;
				retorno =0;
				break;
			}
			vivienda++;
		}
	}
	return retorno;
}

int ordenarViviendas(eVivienda* viviendas, int len)
{
	int retorno;
	int flagSwap;
	int activarCambio;

	eVivienda* punteroVivienda;
	eVivienda* punteroAuxiliarVivienda;
	eVivienda* limiteDeDireccion;
	eVivienda baulVivienda;

	limiteDeDireccion = viviendas+len-1;
	activarCambio=0;

	retorno = -1;
	if(viviendas!= NULL && len >0)
	{
		do{
			punteroAuxiliarVivienda = viviendas;
			flagSwap = 0;
			for(punteroVivienda = viviendas; punteroVivienda < limiteDeDireccion; punteroVivienda++)
			{
				punteroAuxiliarVivienda++;
				if(strcmp(punteroVivienda->calle, punteroAuxiliarVivienda->calle) != 0 )
				{
					if(strcmp(punteroVivienda->calle, punteroAuxiliarVivienda->calle) == 1)
					{
						activarCambio =1;
					}
				}
				else
				{
					if(punteroVivienda->alturaCalle > punteroAuxiliarVivienda->alturaCalle)
					{
						activarCambio=1;
					}
				}

				if(activarCambio)
				{

					baulVivienda= *punteroAuxiliarVivienda;
					*punteroAuxiliarVivienda = *punteroVivienda;
					*punteroVivienda = baulVivienda;
					flagSwap=1;
					activarCambio =0;
				}
			}
			limiteDeDireccion--;
		}while(flagSwap);
	}
	return retorno;
}

int mostrarViviendas(eVivienda* viviendas, int viviendasCensadas)
{
	int retorno;
	char tipoDeVivienda[15];
	eVivienda* limitePunteroViviendas;

	retorno = -1;

	if(viviendas !=NULL && viviendasCensadas >-1)
	{
		limitePunteroViviendas= viviendas +viviendasCensadas;

		printf("\n_______________________________________Lista de Viviendas________________________________________\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-5, "ID", -25, "Calle", -6, "Altura", -10, "Inquilinos", -12, "Habitaciones", -16, "Tipo de vivienda", -15,"Legajo Censista");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		for(;viviendas<limitePunteroViviendas;viviendas++)
		{
			if(viviendas->isEmpty == 0)
			{
				switch(viviendas->tipoVivienda)
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

				printf("|%*d|%*s|%*d|%*d|%*d|%*s|%*d|\n", -5, viviendas->id, -25, viviendas->calle, -6, viviendas->alturaCalle, -10, viviendas->cantidadPersonas, -12, viviendas->cantidadHabitaciones, -16, tipoDeVivienda, -15, viviendas->legajoCensista);
			}
		}
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		retorno=0;
	}
	return retorno;
}
