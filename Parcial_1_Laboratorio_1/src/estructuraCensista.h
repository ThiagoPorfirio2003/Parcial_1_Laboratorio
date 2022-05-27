/*
 * estructuraCensista.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef ESTRUCTURACENSISTA_H_
#define ESTRUCTURACENSISTA_H_
#include "estructuraVivienda.h"

typedef struct{
	int legajoCensista;
	char nombre[50];
	int edad;
	char telefono[12];
} eCensista;


#endif /* ESTRUCTURACENSISTA_H_ */

/*
/// @brief Con esta funcion se muestran los censistas y sus datos
///
/// @pre
/// @post
/// @param censistas: La posicion de memoria del primer elemento de un array de tipo  "eCensita"
/// @param cantidadCensistas: La cantidad de censistas que existen
/// @return int: 0 si todo salio bien o 1 si algo salio mal
int mostrarCensistas(eCensista* censistas, int cantidadCensistas); */

int mostrarCensistasConCantidadDeViviendas(eCensista* censistas, int cantidadCensistas, eVivienda* viviendas, int viviendasCensadas);
