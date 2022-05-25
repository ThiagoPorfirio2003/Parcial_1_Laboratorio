/*
 * estructuraCensista.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef ESTRUCTURACENSISTA_H_
#define ESTRUCTURACENSISTA_H_

typedef struct{
	int legajoCensista;
	char nombre[50];
	int edad;
	char telefono[12];
} eCensista;


#endif /* ESTRUCTURACENSISTA_H_ */
int mostrarCensistas(eCensista* censistas, int cantidadCensistas);
