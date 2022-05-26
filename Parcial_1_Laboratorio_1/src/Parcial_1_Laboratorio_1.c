#include <stdio.h>
#include <stdlib.h>
#include "estructuraVivienda.h"
#include "estructuraCensista.h"
#include "utn.h"
#include "estructuraVivienda.h"

#define VIVIENDAS_A_CENSAR 5
#define CANTIDAD_CENSISTAS 3
#define CANTIDAD_MINIMA_CARACTERES_NOMBRE_CALLE 2
#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE_CALLE 24
#define CANTIDAD_MINIMA_PERSONAS_POR_VIVIENDA 1
#define CANTIDAD_MAXIMA_PERSONAS_POR_VIVIENDA 100
#define CANTIDAD_MINIMA_HABITACIONES 1
#define CANTIDAD_MAXIMA_HABITACIONES 100
#define OPCION_MINIMA_TIPO_DE_VIVIENDA 1
#define OPCION_MAXIMA_TIPO_DE_VIVIENDA 4
#define OPCION_MINIMA_LEGAJO 100
#define OPCION_MAXIMA_LEGAJO 102
#define ID_INICIAL 20000

int main(void) {
	setbuf(stdout,NULL);

	eCensista censistas[]={ {100, "Ana", 34,"1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"}};

	eVivienda viviendas[VIVIENDAS_A_CENSAR];

	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int banderaMantenerseEnElMenu;
	int contadorIdVivienda;
	int banderaOpcionModificarVivienda;
	int banderaOpcionBajaVivienda;
	int banderaOpcionListarViviendas;
	char opcionMenuPrincipal;
	int opcionSubMenu;
	int idViviendaAModificar;
	int posicionViviendaAModificar;
	char calle[25];
	int contadorViviendasCensadas;

	banderaMantenerseEnElMenu =1;
	contadorIdVivienda= ID_INICIAL;
	banderaOpcionModificarVivienda =0;
	banderaOpcionBajaVivienda =0;
	banderaOpcionListarViviendas =0;
	contadorViviendasCensadas =0;

	inicializarViviendas(viviendas, VIVIENDAS_A_CENSAR);

	do{
		if(banderaOpcionModificarVivienda)
		{
			printf("\n");
		}

		printf("---------------------OPCIONES-----------------------\n"
				"A. Alta vivienda.\n"
				"B. Modificar vivienda\n"
				"C. Baja vivienda\n"
				"D. Listar viviendas\n"
				"E. Listar censistas\n"
				"F. Salir del sistema\n\n");

		if(!(utn_getLetraRango(&opcionMenuPrincipal, "Elija la letra correspondiente a la opcion deseada: ", "El dato ingresado es invalido. Elija la letra correspondiente a la opcion deseada: ", 'A', 'F')))
		{
			switch(opcionMenuPrincipal)
			{
				case 'A':

					if(contadorViviendasCensadas < VIVIENDAS_A_CENSAR)
					{
						utn_getNombreTamanioLimitado(calle, "\nIngresa la calle de la vivienda: ", "Dato invalido. Ingresa la calle de la vivienda: ", CANTIDAD_MINIMA_CARACTERES_NOMBRE_CALLE, CANTIDAD_MAXIMA_CARACTERES_NOMBRE_CALLE, sizeof(calle));
						utn_getIntRango(&cantidadPersonas, "\nIngrese la cantidad de personas que vivien en la casa: ", "Dato invalido. Ingrese la cantidad de personas que vivien en la casa: ", CANTIDAD_MINIMA_PERSONAS_POR_VIVIENDA, CANTIDAD_MAXIMA_PERSONAS_POR_VIVIENDA);
						utn_getIntRango(&cantidadHabitaciones, "\nIngrese la cantidad de habitaciones de la casa: ", "Dato invalido. Ingrese la cantidad de habitaciones de la casa: ", CANTIDAD_MINIMA_HABITACIONES, CANTIDAD_MAXIMA_HABITACIONES);
						utn_getIntRango(&tipoVivienda, "\nTipo de vivienda: \n1-Casa\n2-Departamento\n3-Casilla\n4-Rancho\nEscribir el numero correspondiente: ", "Dato invalido. Escriba el numero correspondiente:  ", OPCION_MINIMA_TIPO_DE_VIVIENDA, OPCION_MAXIMA_TIPO_DE_VIVIENDA);
						utn_getIntRango(&legajoCensista, "\nIngrese el legajo del censista: ", "Dato invalido. Ingrese el legajo del censista: ", OPCION_MINIMA_LEGAJO, OPCION_MAXIMA_LEGAJO);

						agregarVivienda(viviendas, VIVIENDAS_A_CENSAR, contadorIdVivienda, calle, cantidadPersonas, cantidadHabitaciones, tipoVivienda, legajoCensista);

						banderaOpcionModificarVivienda =1;
						banderaOpcionBajaVivienda =1;
						banderaOpcionListarViviendas =1;
						contadorViviendasCensadas++;
						contadorIdVivienda++;
					}
					else
					{
						printf("\nNo hay espacio para ingresar otra vivienda, si hay asi desea continuar le recomendamos eliminar alguna\n");
					}
					break;

				case 'B':
					if(banderaOpcionModificarVivienda && contadorViviendasCensadas >0)
					{
						utn_getIntRango(&idViviendaAModificar, "\nIngrese el ID de la vivienda a modificar: ", "Dato invalido. Ingrese el ID de la vivienda a modificar: ", ID_INICIAL, contadorIdVivienda-1);
						posicionViviendaAModificar = encontrarViviendaPorId(viviendas, VIVIENDAS_A_CENSAR, idViviendaAModificar);
						if(posicionViviendaAModificar > -1)
						{
							printf("\nCaracterisitcas a modificar:\n "
									"1- Nombre de la calle\n"
									" 2- Cantidad de personas\n"
									" 3- Cantidad de habitaciones\n"
									" 4- Tipo de vivienda\n");
							utn_getIntRango(&opcionSubMenu, "Elija el numero correspondiente a la opcion deseada: ", "El dato ingresado es invalido. Elija el numero correspondiente a la opcion deseada: ", 1,4);
							modificarViviendaPorId(viviendas, posicionViviendaAModificar, opcionSubMenu, CANTIDAD_MINIMA_CARACTERES_NOMBRE_CALLE, CANTIDAD_MAXIMA_CARACTERES_NOMBRE_CALLE,
									CANTIDAD_MINIMA_PERSONAS_POR_VIVIENDA,CANTIDAD_MAXIMA_PERSONAS_POR_VIVIENDA, CANTIDAD_MINIMA_HABITACIONES, CANTIDAD_MAXIMA_HABITACIONES,
									OPCION_MINIMA_TIPO_DE_VIVIENDA, OPCION_MAXIMA_TIPO_DE_VIVIENDA);
						}
						else
						{
							printf("\nHa ocurrido un error. Lo mas probable es que la vivienda se haya eliminado del sistema\n");
						}
					}
					else
					{
						printf("\nPara acceder a esta opcion, previamente tenes que acceder a la opcion 'A' y tiene que haber almenos 1 vivienda cargada\n");
					}
					break;

				case 'C':
					if(banderaOpcionBajaVivienda && contadorViviendasCensadas > 0)
					{
						utn_getIntRango(&idViviendaAModificar, "\nIngrese el ID de la vivienda a dar de baja: ", "Dato invalido. Ingrese el ID de la vivienda a dar de baja: ", ID_INICIAL, contadorIdVivienda-1);
						if(!(removerVivienda(viviendas, VIVIENDAS_A_CENSAR, idViviendaAModificar)))
						{
							contadorViviendasCensadas--;
						}
						else
						{
							printf("Esa vivienda ya habia sido removida\n");
						}
					}
					else
					{
						printf("\nPara acceder a esta opcion, previamente tenes que acceder a la opcion 'A' y tiene que haber almenos 1 vivienda cargada\n");
					}
					break;

				case 'D':
					if(banderaOpcionListarViviendas && contadorViviendasCensadas >0)
					{
						ordenarViviendas(viviendas, VIVIENDAS_A_CENSAR);
						mostrarViviendas(viviendas, VIVIENDAS_A_CENSAR);
					}
					else
					{
						printf("\nPara acceder a esta opcion, previamente tenes que acceder a la opcion 'A' y tiene que haber almenos 1 vivienda cargada\n");
					}
					break;

				case 'E':
						mostrarCensistas(censistas, CANTIDAD_CENSISTAS);
					break;

				default:
					printf("\nGracias por usar nuestro sistema");
					banderaMantenerseEnElMenu=0;
					break;
			}
		}


	}while(banderaMantenerseEnElMenu);


	return EXIT_SUCCESS;
}
