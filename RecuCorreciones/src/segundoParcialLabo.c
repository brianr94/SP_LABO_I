/*
 ============================================================================
 Name        : segundoParcialLabo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "eServicios.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"
#include "parser.h"


int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaServicios;
	LinkedList* listaFiltrada;
	int opcion;
	int flagCargaTexto;
	int flagGuardado;
	int flagCargaTotal;

	flagGuardado=0;
	flagCargaTexto=0;
	flagCargaTotal=0;

	listaServicios=ll_newLinkedList();
	listaFiltrada=ll_newLinkedList();

	do
	{

		pedirNumeroEnteroValidado(&opcion, "-----------------------\n"
											"1. Cargar Archivo\n"
											"2. Imprimir Lista\n"
											"3. Asignar Totales\n"
											"4. Filtrar por Tipo\n"
											"5. Mostrar servicios\n"
											"6. Guardar Servicios\n"
											"7. Filtrar por totales\n"
											"8. Aplicar descuentos a los totales(10%)\n"
											"9. Salir\n"
											"------------------------\n"
											"Ingrese una opcion: ",
											"------------------------\n"
											"1. Cargar Archivo\n"
											"2. Imprimir Lista\n"
											"3. Asignar Totales\n"
											"4. Filtrar por Tipo\n"
											"5. Mostrar servicios\n"
											"6. Guardar Servicios\n"
											"7. Filtrar por totales\n"
											"8. Aplicar descuentos a los totales(10%)\n"
											"9. Salir\n"
											"--------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 9);


		switch(opcion)
		{
			case 1:
				if(flagCargaTexto==0)
				{
					if(controller_validateLoadFromText("data.csv", listaServicios) != -1)
					{
						flagCargaTexto=1;
					}
				}
				else
				{
					printf("\El archivo ya fue cargado!!!\n");
				}
				break;
			case 2:
				if(flagCargaTexto==1)
				{
					controller_ListServicios(listaServicios);
				}
				else
				{
					printf("\nPrimero debe cargar el archivo para mostrar!!!\n");
				}
				break;
			case 3:
				if(flagCargaTexto==1)
				{
					if(controller_totalPriceAssignment(listaServicios)==0)
					{
						printf("\nSe asignaron los valores totales correctamente!!!!\n");
					}
					else
					{
						printf("\nError. No se asignaron los valores totales\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar el archivo!!!!\n");
				}

				break;
			case 4:
				if(flagCargaTexto==1)
				{
					controller_listFilter(listaServicios);
				}
				else
				{
					printf("\nPrimero debe cargar el archivo!!!!\n");
				}
				break;
			case 5:
				if(flagCargaTexto==1)
				{
					if(Controller_SortByDescription(listaServicios)==0)
					{
						printf("\nLista ordenada!!!\n");
						controller_ListServicios(listaServicios);
					}
					else
					{
						printf("\nEl Ordenamiento no se realizo correctamente\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar el archivo!!!!\n");
				}

				break;
			case 6:
				if(flagCargaTexto==1)
				{
					controller_saveAsText("data.csv", listaServicios);
					flagGuardado=1;
				}
				else
				{
					printf("\nPrimero debe cargar el archivo para guardarlo!!!\n");
				}
				break;
			case 7:
				if(flagCargaTexto==1)
				{
					controller_listFilterByTotal(listaServicios);
					flagCargaTotal=1;

				}
				else
				{
					printf("\nPrimero debe cargar el archivo!!!\n");
				}

				break;

			case 8:
				if(flagCargaTotal==1)
				{
					controller_TotalConDescuento(listaFiltrada, "listaFiltradaPorTotales.csv");
				}
				else
				{
					printf("\nPrimero debe realizar la opcion 7\n");
				}


				break;

			case 9:
				if(flagGuardado==1)
				{
					printf("\nEligio Salir del Programa!!!!\n");
				}
				else
				{
					printf("\nPrimero debe guardar el archivo para salir!!!!\n");
					opcion=0;
				}
		}

		if(opcion != 9)
		{
			system("pause");
		}

	}while(opcion != 9);




	return EXIT_SUCCESS;
}
