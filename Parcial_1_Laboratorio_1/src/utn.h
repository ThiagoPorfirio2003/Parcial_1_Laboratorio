/*
 * utn.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief Con esta funcion se puede ingresar un dato de tipo int que este entre otros 2 datos de este tipo (Tomandolos como valores validos),
/// ademas de mostrar un mensaje y un mensaje de error. Si el minimo y el maximo valen lo mismo entonces se tomara como unico valor correcto a
/// ese mismo. Una vez llegada a la parte de ingreso del dato no se podra salir hasta ingresar el dato pedido
///
/// @pre
/// @post
/// @param direccionInt: La posicion de memoria de una variable tipo int, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param minimo: El valor minimo que puede tener el dato de tipo int
/// @param maximo: El valor maximo que puede tener el dato de tipo int
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_getIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @brief Con esta funcion se puede ingresar un dato de tipo float que este entre otros 2 datos de este tipo (Tomandolos como valores validos),
/// ademas de mostrar un mensaje y un mensaje de error. Si el minimo y el maximo valen lo mismo entonces se tomara como unico valor correcto a
/// ese mismo. Una vez llegada a la parte de ingreso del dato no se podra salir hasta ingresar el dato pedido
/// @pre
/// @post
/// @param direccionFloat: La posicion de memoria de una variable tipo float, en la cual se almacenara el numero en caso de cumplir las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param minimo: El valor minimo que puede tener el dato de tipo float
/// @param maximo: El valor maximo que puede tener el dato de tipo float
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_getFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Con esta funcion se puede ingresar una cadena de caracteres que tenga determinada cantidad de caracteres, emitiendo un mensaje y uno de error,
/// ademas de validar que no haya un espacio al inicio, pero si entre palabras, y que solo haya letras. Una vez llegada a la parte de ingreso del dato no se podra
/// salir hasta ingresar el dato pedido
/// Cuenta al espacio como caracter
///Transforma en mayuscula la primera letra de cada nombre
/// En caso de que el minimo y el maximo sean igual, se tomara como unico valor correcto a alguno de esos dos
/// @pre
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en la cual se quiere almacenar la cadena de caracteres en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadMinimaCaracteres: Es la cantidad minima de caracteres que debe tener la cadena. No puede ser menor a 2
/// @param cantidadMaximaCaracteres: Es la cantidad maxima que debe tener la cadena cadena. Como mucho tiene que valor 1 menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_getNombreTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra);

/// @brief Con esta funcion solo se puede ingresar una cadena de caracteres que tenga determinada cantidad de caracteres y que sea alfanumerica,
/// emitiendo un mensaje y uno de error. Para verificar que sea alfanumerica debera tener almenos 1 caracter o numero
/// En caso de que el minimo y el maximo sean igual, se tomara como unico valor correcto a alguno de esos dos
///Una vez llegada a la parte de ingreso del dato no se podra salir hasta ingresar el dato pedido
///
/// @post
/// @param direccionPalabra: Es la direccion de memoria del vector de caracteres en el cual se quiere almacenar la cadena alfanumerica en caso de que se
/// cumplan todas las condiciones
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param cantidadMinimaCaracteres: Es la cantidad minima de caracteres que debe tener la cadena. No puede ser menor a 3
/// @param cantidadMaximaCaracteres: Es la cantidad maxima que debe tener la cadena cadena. Como mucho tiene que valor 1 menos que longitudPalabra
/// @param longitudPalabra: El tamanio, en bytes, de la variabla a la que apunta el puntero direccionPalabra
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_getCadenaAlfanuericaTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra);

/// @brief Con esta funcion se transforma el primer caracter de cada palabra, de una cadena de caracteres, en mayusculas
///
/// @pre
/// @post
/// @param direccionPalabra: Es la direccion de la cadena de caracteres a la cual se quiere transformar la primer letra de cada en mayuscula
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int transfomarAMayusculaPrimerLetraDeCadaPalabra(char* direccionPalabra);

/// @brief Recibe por referencia una cadena de caracteres para transformar sus caracteres en mayuscula, en caso de poder hacerse.
/// @param direccionCadena: Es la direccion de memoria de la cadena de caracteres a la cual se le quiere transformar sus minusculas en mayusculas
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_trasnformarCadenaAMayuscula(char* direccionCadena);

/// @brief Con esta funcion se solo se puede ingresar una letra que este entre determinado rango de estas, entrando en el rango el minimo y maximo,
/// ademas de hacer diferencia entre mayusculas y minusculas.
///En caso de que ambas letras sean iguales se tomara esa letra como unico valor correcto
/// Una vez llegada a la parte de ingreso del dato no se podra salir hasta ingresar el dato pedido
/// @pre
/// @post
/// @param direccionLetra: La direccion de memoria de la variable en donde se va almacenar la letra
/// @param mensaje: El mensaje que aparecere antes de ingresar el dato por primera vez.
/// @param mensajeError: El mensaje que aparece cuando se ingreso un dato incorrecto
/// @param letraMinima: Es la letra minima que se toma como valida
/// @param letraMaxima: Es la letra maxima que se toma como valida
/// @return int: Un 0 en caso de que se cumplan todas las direcciones o 1 si no lo hace
int utn_getLetraRango(char* direccionLetra, char* mensaje, char* mensajeError, char letraMinima, char letraMaxima);



#endif /* UTN_H_ */
