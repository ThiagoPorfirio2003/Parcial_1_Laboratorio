/*
 * utn.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief Con esta funcion se puede ingresar un dato de tipo int que este entre otros 2 datos de este tipo (Tomandolos como valores validos),
/// ademas de mostrar un mensaje y un mensaje de error
///
/// @pre
/// @post
/// @param direccionInt: La posicion de memoria de una variable tipo int, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param minimo: El valor minimo que puede tener el dato de tipo int
/// @param maximo: El valor maximo que puede tener el dato de tipo int
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @brief Con esta funcion se puede ingresar un dato de tipo float que este entre otros 2 datos de este tipo (Tomandolos como valores validos),
/// ademas de mostrar un mensaje y un mensaje de error
/// @pre
/// @post
/// @param direccionFloat: La posicion de memoria de una variable tipo float, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param minimo: El valor minimo que puede tener el dato de tipo float
/// @param maximo: El valor maximo que puede tener el dato de tipo float
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Esta funcion tiene el fin de que solo se pueda ingresar un dato de tipo int que sea igual a otro del mismo tipo,
/// ademas de mostrar un mensaje y un mensaje de error.
/// @pre
/// @post
/// @param direccionInt: La posicion de memoria de una variable tipo int, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param numeroEspecifico: Es el numero en especifico que hay que ingresar para que todo resulte bien, de tipo int.
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getIntEspecifico(int* direccionInt, char* mensaje, char* mensajeError, int numeroEspecifico);

/// @brief Esta funcion tiene el fin de que solo se pueda ingresar un dato de tipo int que sea igual a otro del mismo tipo,
/// ademas de mostrar un mensaje y un mensaje de error.
/// @pre
/// @post
/// @param direccionFloat: La posicion de memoria de una variable tipo float, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param numeroEspecifico: Es el numero en especifico que hay que ingresar para que todo resulte bien, de tipo float.
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getFloatEspecifico(float* direccionFloat, char* mensaje, char* mensajeError, float numeroEspecifico);

/// @brief Con esta funcion se puede ingresar una cadena de caracteres que tenga determinada cantidad de caracteres, emitiendo un mensaje y uno de error,
/// ademas de validar que no haya un espacio al inicio, pero si entre palabras, y que solo haya letras. Cuenta al espacio como caracter
///
/// @pre
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en la cual se quiere almacenar la cadena de caracteres en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadMinimaCaracteres: Es la cantidad minima de caracteres que debe tener la cadena
/// @param cantidadMaximaCaracteres: Es la cantidad maxima que debe tener la cadena cadena. Como mucho tiene que valor 1 menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getNombreTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra);

/// @brief Con esta funcion se puede ingresar una cadena de caracteres que tenga una cantidad especifcia de caracteres, emitiendo un mensaje y uno de error,
/// ademas de validar que no haya un espacio al inicio, pero si entre palabras, y que solo haya letras y espacios entre los nombre.
/// Cuenta al espacio como caracter
/// @pre
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en la cual se quiere almacenar la cadena de caracteres en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadCaracteres: Es la cantidad especifica de caracteres que se debe ingresar para que no haya un error. Como mucho tiene que valor 1
/// menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getNombreTamanioEspecifico(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadCaracteres, int longitudPalabra);

/// @brief Con esta funcion solo se puede ingresar una cadena de caracteres que tenga determinada cantidad de caracteres y que sea alfanumerica,
/// emitiendo un mensaje y uno de error.
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en el cual se quiere almacenar la cadena alfanumerica en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadMinimaCaracteres: Es la cantidad minima de caracteres que debe tener la cadena
/// @param cantidadMaximaCaracteres: Es la cantidad maxima que debe tener la cadena cadena. Como mucho tiene que valor 1 menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getCadenaAlfanuericaTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra);

/// @brief Con esta funcion solo se puede ingresar una cadena de caracteres que tenga una cantidad especifica de caracteres y que sea alfanumerica,
/// emitiendo un mensaje y uno de error.
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en el cual se quiere almacenar la cadena alfanumerica en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadCaracteres: Es la cantidad de caracteres especifica que debe tener la cadena de caracteres que sera almacenada en la direccion de
/// memoria que apunta el puntero direccionPalabra. Como mucho tiene que valor 1 menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones.
int utn_getCadenaAlfanuericaTamanioEspecifico(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadCaracteres, int longitudPalabra);

/// @brief Recibe por referencia una cadena de caracteres para transformar sus caracteres en mayuscula, en caso de poder hacerse.
/// @param direccionCadena: Es la direccion de memoria de la cadena de caracteres a la cual se le quiere transformar sus minusculas en mayusculas
/// @return int: Un 0 si todo salio bien o !=0 si algo salio mal
int utn_trasnformarCadenaAMayuscula(char* direccionCadena);

/// @brief
///
/// @pre
/// @post
/// @param direccionLetra
/// @param mensaje
/// @param mensajeError
/// @param letraMinima
/// @param letraMaxima
/// @return
int utn_getLetraRango(char* direccionLetra, char* mensaje, char* mensajeError, char letraMinima, char letraMaxima);

#endif /* UTN_H_ */
