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
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
} eVivienda;

#endif /* ESTRUCTURAVIVIENDA_H_ */

/// @brief Con esta funcion se pone el campo "isEmpty" en 1
///
/// @pre
/// @post
/// @param viviendas: La direccion de memorira de la primera posicion de un array de tipo "eVivienda"
/// @param len: Cuantos datos tiene el array de viviendas
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int inicializarViviendas(eVivienda* viviendas, int len);

/// @brief Con esta funcion se agrega una vivienda a un array de tipo "eVivienda"
///
/// @pre
/// @post
/// @param vivienda: La direccion de memorira de la primera posicion de un array de tipo
/// @param id: El id de la vivienda
/// @param calle: La calle de la vivienda
/// @param cantidadPersonas: La cantidad de personas que habitan la vivienda
/// @param cantidadHabitaciones: La cantidad de habitaciones de la vivienda
/// @param tipoVivienda: El tipo de vivienda:
/// @param legajoCensista
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int agregarVivienda(eVivienda* vivienda, int len, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);

/// @brief Con esta funcion se puede encontrar una vivienda mediante su id
///
/// @pre
/// @post
/// @param vivienda: La direccion de memorira de la primera posicion de un array de tipo "eVivienda"
/// @param len: Cuantos datos tiene el array de viviendas
/// @param id: El id de la vivienda a encontrar
/// @return int: El id de la vivienda en caso de que todo haya salido bien o -1 si hubo algun error
int encontrarViviendaPorId(eVivienda* vivienda, int len,int id);

/// @brief Con esta funcion se podra modificar la calle, cantidad de habitaciones, cantidad de inquilinos o el tipo de vivienda de una variable
/// de tipo "eVivienda"
///
/// @pre
/// @post
/// @param vivienda: La direccion de memoria de un array de tipo vivienda
/// @param posicionVivienda: La posicion segun el indice de la vivienda a modificar
/// @param opcion: La opcion a cambiar 1(calle), 2(cantidad de inquilinos), 3(cantidad de habitaciones) o 4(tipo de vivienda)
/// @param cantidadMinimaLetrasCalleNombre: Cantidad minima de letras que puede tener la calle
/// @param cantidadMaximaLetrasCalleNombre: Cantidad maxima de letras que puede tener la calle
/// @param cantidadMinimaPersonasPorCasa: Cantidad minima de personas por vivienda
/// @param cantidadMaximaPersonasPorCasa: Cantidad maxima de personas por vivienda
/// @param cantidadMinimaHabitaciones: Cantidad minima de habitaciones por vivienda
/// @param cantidadMaximaHabitaciones: Cantidad maxima de habitaciones por vivienda
/// @param minimaOpcionTipoVivienda: Minima opcion de tipo de vivienda
/// @param maximaOpcionTipoVivienda: Maxima opcion de tipo de vivienda
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int modificarViviendaPorId(eVivienda* vivienda, int posicionVivienda, int opcion, int cantidadMinimaLetrasCalleNombre,
		int cantidadMaximaLetrasCalleNombre, int cantidadMinimaPersonasPorCasa, int cantidadMaximaPersonasPorCasa, int cantidadMinimaHabitaciones,
		int cantidadMaximaHabitaciones, int minimaOpcionTipoVivienda, int maximaOpcionTipoVivienda);

/// @brief Con esta funcion se puede remover una vivienda segun su ID
///
/// @pre
/// @post
/// @param vivienda: La direccion de memorira de la primera posicion de un array de tipo "eVivienda"
/// @param len: Cuantos datos tiene el array de viviendas
/// @param id:El id de la vivienda a ser removida
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int removerVivienda(eVivienda* vivienda, int len, int id);

/// @brief Con esta funcion se ordenan las viviendas de manera ascende segun el nombre de la calle, diferencia mayuscula de minusculas y si tienen el mismo
/// nombre se tomara en cuenta la cantidad de inquilinos
///
/// @pre
/// @post
/// @param viviendas: La direccion de memorira de la primera posicion de un array de tipo "eVivienda"
/// @param len: Cuantos datos tiene el array de viviendas
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int ordenarViviendas(eVivienda* viviendas, int len);

/// @brief Con esta funcion se muestra un listado de la viviendas dadas de alta y sus caracteristicas
///
/// @pre
/// @post
/// @param viviendas: La direccion de memorira de la primera posicion de un array de tipo "eVivienda"
/// @param viviendasCensadas: La cantidad de viviendas censadas
/// @return int: Un 0 en caso de que todo haya salido bien o !=0 si hubo algun error
int mostrarViviendas(eVivienda* viviendas, int viviendasCensadas);
