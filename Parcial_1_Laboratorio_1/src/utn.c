/*
 * utn.c
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief Es una funcion auxiliar de la biblioteca, la cual permite
/// ingresar cualquier tipo de dato como cadena de caracteres y, en
/// caso de necesitarlo, reemplazar el \n por el \0
///
/// @param direccionCadena: Recibe la direccion de memoria de una cadena de caracteres
/// @param longitud: Recibe el tamanio en bytes de la cadena de caracteres
/// @return int: 0 si todo salio bien o !=0 si algo salio mal
int static myGets(char* direccionCadenaCaracteres, int longitud)
{
	int retorno;
	char bufferString[1024];

	retorno = -1;

	if(direccionCadenaCaracteres != NULL && longitud > 0)
	{
		retorno =1;
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(*(bufferString +strnlen(bufferString, sizeof(bufferString))-1) == '\n')
			{
				*(bufferString +strnlen(bufferString, sizeof(bufferString))-1) = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(direccionCadenaCaracteres, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @brief Es una funcion auxiliar de la biblioteca, la cual permite
/// verificar que la cadena de caracteres que recibio sea numerica de tipo int.
///
/// @pre
/// @post
/// @param cadenaDeCaracteres: Es la direccion de la cadena de caracteres a analizar
/// @return int: 0 si todo salio bien o !=0 si algo salio mal
int static verificarSerInt(char* cadenaDeCaracteres)
{
	int retorno;
	retorno = -1;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres != '0')
	{
		retorno=0;
		if(*cadenaDeCaracteres == '-' ||
				*cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}
		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				retorno =1;
				break;
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');
	}
	return retorno;
}

/// @brief Es una funcion auxiliar de la biblioteca, la cual
/// te permite ingresar un dato de tipo int
///
/// @pre
/// @post
/// @param direccionInt: Es la direccion en la que se desea almacenar un int en caso de que todo haya salido bien
/// @return int: 0 si todo salio bien o !=0 si algo salio mal
int static getInt(int* direccionInt)
{
	int retorno;
	char bufferInt[1024];

	retorno =-1;
	if(direccionInt !=NULL)
	{
		retorno =1;
		if(!(myGets(bufferInt, sizeof(bufferInt))) && !(verificarSerInt(bufferInt)))
		{
			*direccionInt = atoi(bufferInt);
			retorno =0;
		}
	}

	return retorno;
}

/// @brief Es una funcion auxiliar de la biblioteca, la cual permite
/// verificar que la cadena de caracteres que recibio sea numerica de tipo float.
///
/// @pre
/// @post
/// @param cadenaDeCaracteres: Es la direccion de la cadena de caracteres a analizar
/// @return int: 0 si todo salio bien o !=0 si algo salio mal
int static verificarSerFloat(char* cadenaDeCaracteres)
{
	int retorno;
	int contadorPuntos;

	retorno = -1;
	contadorPuntos =0;

	if(cadenaDeCaracteres != NULL)
	{
		retorno=0;
		if(*cadenaDeCaracteres == '-' || *cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}
		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				if(contadorPuntos <2 && *cadenaDeCaracteres== '.')
				{
				contadorPuntos++;
				}
				else
				{
					retorno =1;
					break;
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');

	}
	return retorno;
}

/// @brief Es una funcion auxiliar de la biblioteca, la cual
/// te permite ingresar un dato de tipo float
///
/// @pre
/// @post
/// @param direccionFloat: Es la direccion en la que se desea almacenar un float en caso de que todo haya salido bien
/// @return int: 0 si todo salio bien o !=0 si algo salio mal
int static getFloat(float* direccionFloat)
{
	int retorno;
	char bufferFloat[1024];

	retorno =-1;
	if(direccionFloat !=NULL)
	{
		retorno =1;
		if(!(myGets(bufferFloat, sizeof(bufferFloat))) && !(verificarSerFloat(bufferFloat)))
		{
			*direccionFloat = atof(bufferFloat);
			retorno =0;
		}
	}
	return retorno;
}

/// @brief Es una funcion auxiliar de la biblioteca, la cual permite
/// verificar se la cadena de caracteres recibida-
///
/// @pre
/// @post
/// @param cadenaDeCaracteres:
/// @return
int static verificarSerNombre(char* cadenaDeCaracteres)
{
	int retorno;

	retorno=-1;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres !=' ')
	{
		retorno =0;

		do{
			if(isspace(*cadenaDeCaracteres) == 0 &&
				isalpha(*cadenaDeCaracteres) == 0 &&
				*cadenaDeCaracteres != 'á' &&
				*cadenaDeCaracteres != 'é' &&
				*cadenaDeCaracteres != 'í' &&
				*cadenaDeCaracteres != 'ó' &&
				*cadenaDeCaracteres != 'ú' &&
				*cadenaDeCaracteres != 'Á' &&
				*cadenaDeCaracteres != 'É' &&
				*cadenaDeCaracteres != 'Í' &&
				*cadenaDeCaracteres != 'Ó' &&
				*cadenaDeCaracteres != 'Ú' &&
				*cadenaDeCaracteres != 'ñ' &&
				*cadenaDeCaracteres != 'Ñ')
			{
				retorno = 1;
				break;
			}

			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres != '\0');
	}
	return retorno;
}

/// @brief
///
/// @pre
/// @post
/// @param direccionPalabra
/// @return
int static getNombre(char* direccionPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int sizeBuffer;

	sizeBuffer = sizeof(bufferPalabra);

	retorno=-1;

	if(direccionPalabra !=NULL)
	{
		retorno=1;

		if(!(myGets(bufferPalabra, sizeBuffer)) && !(verificarSerNombre(bufferPalabra)))
		{
			retorno=0;
			strncpy(direccionPalabra, bufferPalabra, sizeBuffer);
		}
	}
	return retorno;
}

/// @brief
///
/// @pre
/// @post
/// @param cadenaAlfanumerica
/// @return
int static verificarSerCadenaAlfanumerica(char* cadenaAlfanumerica)
{
	int retorno;
	int banderaExistenciaNumero;
	int banderaExistenciaCaracter;

	banderaExistenciaNumero=0;
	banderaExistenciaCaracter=0;

	retorno=-1;

	if(cadenaAlfanumerica != NULL && *cadenaAlfanumerica !=' ')
	{
		do{
			if(isdigit(*cadenaAlfanumerica) != 0)
			{
				banderaExistenciaNumero =1;
			}
			else
			{
				if(isalpha(*cadenaAlfanumerica) != 0)
				{
					banderaExistenciaCaracter=1;
				}
				else
				{
					if(*cadenaAlfanumerica != 'á' &&
						*cadenaAlfanumerica != 'é' &&
						*cadenaAlfanumerica != 'í' &&
						*cadenaAlfanumerica != 'ó' &&
						*cadenaAlfanumerica != 'ú' &&
						*cadenaAlfanumerica != 'Á' &&
						*cadenaAlfanumerica != 'É' &&
						*cadenaAlfanumerica != 'Í' &&
						*cadenaAlfanumerica != 'Ó' &&
						*cadenaAlfanumerica != 'Ú' &&
						*cadenaAlfanumerica != 'ñ' &&
						*cadenaAlfanumerica != 'Ñ')
					{
						banderaExistenciaCaracter=1;
					}
					else
					{
						retorno = 1;
						break;
					}
				}
			}
			cadenaAlfanumerica++;
		}while(*cadenaAlfanumerica != '\0');
		if(banderaExistenciaCaracter && banderaExistenciaNumero && *cadenaAlfanumerica == '\0')
		{
			retorno =0;
		}
	}
	return retorno;
}

/// @brief
///
/// @pre
/// @post
/// @param cadenaAlfanumerica
/// @return
int static getCadenaAlfanumerica(char* cadenaAlfanumerica)
{
	int retorno;
	char bufferChar[1024];

	retorno =-1;

	if(cadenaAlfanumerica != NULL)
	{
		retorno=-1;
		if(!(myGets(bufferChar, sizeof(bufferChar))) && !(verificarSerCadenaAlfanumerica(bufferChar)))
		{
			retorno =0;
			strcpy(cadenaAlfanumerica, bufferChar);
		}
	}
	return retorno;
}

/// @brief
///
/// @pre
/// @post
/// @param direccionCaracter
/// @return
int static transformarMinusculaAMayuscula(char* direccionCaracter)
{
	int retorno;
	char caracter;

	retorno =-1;
	if(direccionCaracter !=NULL)
	{
		caracter = *direccionCaracter;
		retorno =0;
		*direccionCaracter = toupper(caracter);
	}
	return retorno;
}

int static transfomarAMayusculaPrimerLetraDeCadaPalabra(char* direccionPalabra)
{
	int retorno;
	int banderaEspacio;

	retorno=-1;
	banderaEspacio=0;

	if(direccionPalabra !=NULL)
	{
		transformarMinusculaAMayuscula(direccionPalabra);
		direccionPalabra++;

		while(*direccionPalabra !='\0')
		{
			if(isspace(*direccionPalabra))
			{
				banderaEspacio=1;
			}

			if(banderaEspacio && isalpha(*direccionPalabra))
			{
				transformarMinusculaAMayuscula(direccionPalabra);
				banderaEspacio=0;
			}

			direccionPalabra++;
		}
	}

	return retorno;
}

/*
int static getLetra(char* direccionCaracter)
{
	int retorno;
	char bufferLetra[1024];

	retorno=-1;

	if(direccionCaracter !=NULL)
	{
		retorno=1;
		if(!(myGets(bufferLetra,sizeof(bufferLetra)) && !(verificarSerLetra(bufferLetra))))
		{
			*direccionCaracter = *bufferLetra;
			retorno=0;
		}
	}
	return retorno;
}
*/
int utn_getIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno;
	int bufferInt;

	retorno=-1;

	if(direccionInt!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<=maximo)
	{
		retorno =1;

		printf("%s", mensaje);
		while(getInt(&bufferInt) || bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionInt = bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_getFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retorno;
	float bufferFloat;

	retorno=-1;

	if(direccionFloat!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<maximo)
	{
		retorno =1;

		printf("%s", mensaje);
		while(getFloat(&bufferFloat) || bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionFloat = bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_getIntEspecifico(int* direccionInt, char* mensaje, char* mensajeError, int numeroEspecifico)
{
	int retorno;
	int bufferInt;

	retorno=-1;

	if(direccionInt!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL)
	{
		retorno =1;

		printf("%s", mensaje);
		while(getInt(&bufferInt) || bufferInt != numeroEspecifico)
		{
			printf("%s", mensajeError);
		}
		*direccionInt = bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_getFloatEspecifico(float* direccionFloat, char* mensaje, char* mensajeError, float numeroEspecifico)
{
	int retorno;
	float bufferFloat;

	retorno=-1;

	if(direccionFloat!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL)
	{
		retorno =1;

		printf("%s", mensaje);
		while(getFloat(&bufferFloat) || bufferFloat != numeroEspecifico)
		{
			printf("%s", mensajeError);
		}
		*direccionFloat = bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_getNombreTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int tamanioBuffer;

	tamanioBuffer = sizeof(bufferPalabra);
	retorno =-1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > cantidadMinimaCaracteres &&
			longitudPalabra >0 &&
			cantidadMaximaCaracteres < longitudPalabra)
	{
		retorno =1;
		printf("%s", mensaje);
		while(getNombre(bufferPalabra) ||
				strnlen(bufferPalabra, tamanioBuffer) < cantidadMinimaCaracteres ||
				strnlen(bufferPalabra, tamanioBuffer) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		retorno =0;
		transfomarAMayusculaPrimerLetraDeCadaPalabra(bufferPalabra);
		strncpy(direccionPalabra, bufferPalabra, longitudPalabra);
	}
	return retorno;
}

int utn_getNombreTamanioEspecifico(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadCaracteres, int longitudPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int tamanioBuffer;

	tamanioBuffer = sizeof(bufferPalabra);
	retorno =-1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadCaracteres > 0 &&
			longitudPalabra >0 &&
			cantidadCaracteres < longitudPalabra)
	{
		retorno =1;
		printf("%s", mensaje);
		while(getNombre(bufferPalabra) ||
				strnlen(bufferPalabra, tamanioBuffer) != cantidadCaracteres)
		{
			printf("%s", mensajeError);
		}
		retorno =0;
		transfomarAMayusculaPrimerLetraDeCadaPalabra(bufferPalabra);
		strncpy(direccionPalabra, bufferPalabra, longitudPalabra);
	}
	return retorno;
}

int utn_getCadenaAlfanuericaTamanioLimitado(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int tamanioBuffer;

	tamanioBuffer = sizeof(bufferPalabra);
	retorno =-1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > cantidadMinimaCaracteres &&
			longitudPalabra >0 &&
			cantidadMaximaCaracteres < longitudPalabra)
	{
		retorno =1;
		printf("%s", mensaje);
		while(getCadenaAlfanumerica(bufferPalabra) ||
				strnlen(bufferPalabra, tamanioBuffer) < cantidadMinimaCaracteres ||
				strnlen(bufferPalabra, tamanioBuffer) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		retorno =0;
		strncpy(direccionPalabra, bufferPalabra, longitudPalabra);
	}
	return retorno;
}

int utn_getCadenaAlfanuericaTamanioEspecifico(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadCaracteres, int longitudPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int tamanioBuffer;

	tamanioBuffer = sizeof(bufferPalabra);
	retorno =-1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadCaracteres > 0 &&
			longitudPalabra >0 &&
			cantidadCaracteres < longitudPalabra)
	{
		retorno =1;
		printf("%s", mensaje);
		while(getCadenaAlfanumerica(bufferPalabra) ||
				strnlen(bufferPalabra, tamanioBuffer) != cantidadCaracteres)
		{
			printf("%s", mensajeError);
		}
		retorno =0;
		strncpy(direccionPalabra, bufferPalabra, longitudPalabra);
	}
	return retorno;
}

int utn_trasnformarCadenaAMayuscula(char* direccionCadena)
{
	int retorno;

	retorno=-1;

	if(direccionCadena!=NULL)
	{
		retorno= 0;
		do{
			if(isalpha(*direccionCadena) !=0 ||
					*direccionCadena == 'á' ||
					*direccionCadena == 'é' ||
					*direccionCadena == 'í' ||
					*direccionCadena == 'ó' ||
					*direccionCadena == 'ú' ||
					*direccionCadena == 'ñ')
			{
				transformarMinusculaAMayuscula(direccionCadena);
			}
			direccionCadena++;
		}while(*direccionCadena != '\0');
/*
		for(i=0;i<cantidadCaracteres;i++)
		{
			if(isalpha(direccionCadena[i]) !=0 || direccionCadena[i] == 'á' || direccionCadena[i] == 'é' || direccionCadena[i] == 'í' || direccionCadena[i] == 'ó' || direccionCadena[i] == 'ú' || direccionCadena[i] == 'ñ')
			{
				transformarMinusculaAMayuscula(&direccionCadena[i]);
			}
			retorno= 0;
		}*/
	}

	return retorno;
}

int utn_getLetraRango(char* direccionLetra, char* mensaje, char* mensajeError, char letraMinima, char letraMaxima)
{
	int retorno;
	char bufferLetra[1024];

	retorno=-1;

	if(direccionLetra!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			letraMinima<letraMaxima)
	{
		retorno =1;

		printf("%s", mensaje);
		while(getNombre(bufferLetra) || *bufferLetra < letraMinima || *bufferLetra > letraMaxima || strnlen(bufferLetra, sizeof(bufferLetra)) != 1)
		{
			printf("%s", mensajeError);
		}
		*direccionLetra = *bufferLetra;
		retorno=0;
	}
	return retorno;
}

