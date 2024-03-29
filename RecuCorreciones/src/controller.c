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


/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto) validadando la entrada del nombre del archivo.
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_validateLoadFromText(char* path , LinkedList* pArrayListServicio)
{

	int retorno=-1;
	char file[51];
	FILE* pFile;

	pedirCadena(file, "Ingrese el archivo a cargar(incluir el formato en el nombre .csv): ", "Error. Ingrese nuevamente el nombre del archivo: ", 51);

	if(strcmp(path,file) != 0)
	{
		printf("\nArchivo ingresado no existe!!!!. Ingrese nuevamente\n");
	}
	else
	{
		printf("\nArchivo encontrado!!!\n");

		pFile= fopen(path,"r");

		if(path != NULL && pArrayListServicio != NULL)
		{
			retorno=parser_servicioFromText(pFile, pArrayListServicio);
		}

	}

    return retorno;
}

/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_cargaDeArhivoTexto(char* path , LinkedList* pArrayListServicio)
{
	int retorno=1;
	FILE* pFile;

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
	int (*pFuncion)(void* elemento);

	pFuncion=NULL;

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
				pFuncion=eServicio_filterByMinorista;
				retorno=0;
				break;
			case 2:
				pFuncion=eServicio_filterByMayorista;
				retorno=0;
				break;
			case 3:
				pFuncion=eServicio_filterByExportar;
				retorno=0;
				break;
		}

		listaFiltrada=ll_filter(pArrayListServicio, pFuncion);


		if(listaFiltrada != NULL)
		{
			controller_saveAsText("listaFiltrada.csv",listaFiltrada);
			printf("Lista filtrada por clase y guardada con exito.\n");
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

int controller_listFilterByTotal(LinkedList* pArrayListServicio)
{
	int retorno=-1;
	LinkedList* listaFiltrada = NULL;

		if(pArrayListServicio != NULL)
		{
			listaFiltrada=ll_filter(pArrayListServicio, eServicio_buscarTotalMayor);


			if(listaFiltrada != NULL)
			{
				controller_saveAsText("listaFiltradaPorTotales.csv",listaFiltrada);
				printf("Lista filtrada por clase y guardada con exito.\n");
			}


		}

	return retorno;
}

int controller_TotalConDescuento(LinkedList* pArrayListServicio, char* path)
{
	int retorno=-1;
	LinkedList* listaFiltrada;

	if(pArrayListServicio != NULL)
	{

		if(controller_cargaDeArhivoTexto(path, pArrayListServicio) != -1)
		{
			listaFiltrada=ll_map(pArrayListServicio, eServicio_totalConDescuento);
		}


		if(listaFiltrada != NULL)
		{
			controller_saveAsText("listaConDescuento.csv", pArrayListServicio);
			retorno=0;
		}

	}

	return retorno;
}
