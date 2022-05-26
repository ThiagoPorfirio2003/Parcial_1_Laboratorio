/*
 * estructuraVivienda.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef ESTRUCTURAVIVIENDA_H_
#define ESTRUCTURAVIVIENDA_H_

typedef struct{
	int id;
	char calle[25];
//	int alturaCalle;
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
} eVivienda;

#endif /* ESTRUCTURAVIVIENDA_H_ */

int inicializarViviendas(eVivienda* viviendas, int len);

int agregarVivienda(eVivienda* vivienda, int len, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);

int encontrarViviendaPorId(eVivienda* vivienda, int len,int id);


int modificarViviendaPorId(eVivienda* vivienda, int posicionVivienda, int opcion, int cantidadMinimaLetrasCalleNombre,
		int cantidadMaximaLetrasCalleNombre, int cantidadMinimaPersonasPorCasa, int cantidadMaximaPersonasPorCasa, int cantidadMinimaHabitaciones,
		int cantidadMaximaHabitaciones, int minimaOpcionTipoVivienda, int maximaOpcionTipoVivienda);

int removerVivienda(eVivienda* vivienda, int len, int id);

int ordenarViviendas(eVivienda* viviendas, int len);

int mostrarViviendas(eVivienda* viviendas, int viviendasCensadas);
