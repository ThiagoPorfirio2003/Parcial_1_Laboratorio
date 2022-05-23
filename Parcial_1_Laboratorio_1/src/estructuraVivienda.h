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
	char calle[26];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
} eVivienda;

#endif /* ESTRUCTURAVIVIENDA_H_ */
