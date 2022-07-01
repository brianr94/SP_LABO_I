/*
 * parser.c
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */

#include "parser.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int parser_servicioFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	eServicios* servicio=NULL;
	char id[50];
	char descripcion[50];
	char tipo[50];
	char precio[50];
	char cantidad[50];
	char total[50];
	int cantidadLineas;

	int retorno=-1;

	if(pFile != NULL && pArrayListServicios != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, tipo, precio, cantidad, total);

		do
		{

			cantidadLineas=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, tipo, precio, cantidad, total);

			if(cantidadLineas==6)
			{
				servicio=eServicio_newParametros(id, descripcion, tipo, precio, cantidad, total);

				if(servicio != NULL)
				{
					ll_add(pArrayListServicios, servicio);
					retorno=0;
				}
			}
			else
			{
				break;
			}


		}while(!feof(pFile));

		fclose(pFile);

	}
    return retorno;
}
