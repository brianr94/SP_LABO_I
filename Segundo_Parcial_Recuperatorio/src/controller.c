/*
 * controller.c
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */
#include "controller.h"
#include "eServicios.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_validaciones.h"
#include "utn_inputs.h"
#include "LinkedList.h"


/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicio)
{

	int retorno=-1;
	char file[50];
	int comparacion;
	int archivoEncotrado=-1;
	FILE* pFile;

	comparacion=strcmp(file,path);
	do
	{
		if(pedirCadena(file, "Ingrese el nombre de archivo a cargar: ", "Ingrese el nombre de achivo correctamente: ", 50)==0)
		{
			archivoEncotrado=0;
			break;
		}

	}while(comparacion != 0 && archivoEncotrado!=0);



	pFile= fopen(path,"r");

	if(path != NULL && pArrayListServicio != NULL)
	{
		retorno=parser_servicioFromText(pFile, pArrayListServicio);

	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicio)
{
	int retorno=1;
	int i;
	int length;
	int idAux;
	char descripcion[50];
	float precioAux;
	int tipoAux;
	int cantidadAux;
	float totalAux;


	eServicios* servicio;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayListServicio != NULL)
	{
		length=ll_len(pArrayListServicio);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio");
			for(i=0;i<length;i++)
			{
				servicio=ll_get(pArrayListServicio, i);

				if(servicio != NULL)
				{
					eServicio_getId(servicio, &idAux);
					eServicio_getDescripcion(servicio, descripcion);
					eServicio_getTipo(servicio, &tipoAux);
					eServicio_getPrecioUnitario(servicio,&precioAux);
					eServicio_getCantidad(servicio, &cantidadAux);
					eServicio_getTotal(servicio, &totalAux);

					fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",idAux,descripcion,tipoAux,precioAux,cantidadAux,totalAux);
				}
			}

			fclose(pFile);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}
		else
		{
			printf("\nError.Archivo no creado!!!\n");
		}

		retorno=0;
	}
    return retorno;
}


/** \brief Listar Servicios
 *
 * \param path char*
 * \param pArrayListServicio LinkedList*
 * \return int
 *
 */
int controller_ListServicios(LinkedList* pArrayListServicio)
{
	int retorno=-1;
	int i;
	int len;
	eServicios* servicio;

	if(pArrayListServicio != NULL)
	{
		len=ll_len(pArrayListServicio);
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s\n","ID", "Descripcion", "Tipo", "Precio Unitario", "Cantidad","Total Servicios");
		for(i=0;i<len;i++)
		{
			servicio=ll_get(pArrayListServicio, i);
			eServicio_imprimirServicio(servicio);
		}
		retorno=0;
	}

    return retorno;
}

int controller_listFilter(LinkedList* pArrayListServicio)
{
	int retorno=-1;
	int opcion;
	LinkedList* listaFiltrada = NULL;

	if(pArrayListServicio != NULL)
	{
		pedirNumeroEnteroValidado(&opcion, "----------------------------------\n"
											"1. Filtrar por tipo minorista\n"
											"2. Filtrar por tipo mayorista\n"
											"3. Filtrar por tipo exportar\n"
											"---------------------------------\n"
											"ingrese una opcion: ",
											"---------------------------------\n"
											"1. Filtrar por tipo minorista\n"
											"2. Filtrar por tipo mayorista\n"
											"3. Filtrar por tipo exportar\n", 1, 3);

		switch(opcion)
		{
			case 1:
				listaFiltrada=ll_filter(pArrayListServicio, eServicio_filterByMinorista);
				break;
			case 2:
				listaFiltrada=ll_filter(pArrayListServicio, eServicio_filterByMayorista);
				break;
			case 3:
				listaFiltrada=ll_filter(pArrayListServicio, eServicio_filterByExportar);
				break;
		}

		if(listaFiltrada != NULL)
		{
			controller_saveAsText("listaFiltrada.csv",listaFiltrada);
			printf("Lista filtrada por clase y guardada con exito.\n");
			retorno = 0;
		}
	}


	return retorno;
}

int Controller_SortByDescription(LinkedList* pArrayListServicio)
{
	int retorno=-1;


	if(pArrayListServicio != NULL)
	{
		retorno = ll_sort(pArrayListServicio, eServicio_sortByDescripcion,1);
	}

	return retorno;
}

int controller_totalPriceAssignment(LinkedList* pArrayListServicio)
{
	int retorno=-1;


	if(pArrayListServicio != NULL)
	{
		ll_map(pArrayListServicio, eServicio_calcularPrecioTotal);
		retorno = 0;
	}


	return retorno;
}
