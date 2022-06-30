/*
 * eServicios.c
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */

#include "eServicios.h"
#include "LinkedList.h"
#include <string.h>


eServicios*eServicio_newServicio()
{
	eServicios* nuevoServicio=NULL;

	nuevoServicio=(eServicios*)malloc(sizeof(eServicios));

	return nuevoServicio;
}

eServicios* eServicio_newParametros(char* idStr,char* descripcionStr, char* tipostr, char* precioUnitarioStr, char* cantidadStr, char* totalStr)
{
	int idAux;
	int tipoAux;
	float precioAux;
	int cantidadAux;
	float totalAux;
	eServicios* servicio=NULL;

	servicio=eServicio_newServicio();


	if(idStr != NULL && descripcionStr != NULL && tipostr != NULL && precioUnitarioStr != NULL && cantidadStr != NULL && totalStr != NULL)
	{

		idAux=atoi(idStr);
		tipoAux=atoi(tipostr);
		precioAux=atof(precioUnitarioStr);
		cantidadAux=atoi(cantidadStr);
		totalAux=atof(totalStr);

		eServicio_setId(servicio, idAux);
		eServicio_setDescripcion(servicio, descripcionStr);
		eServicio_setTipo(servicio, tipoAux);
		eServicio_setPrecioUnitario(servicio, precioAux);
		eServicio_setCantidad(servicio, cantidadAux);
		eServicio_setTotal(servicio, totalAux);

	}
	else
	{
		eServicio_borrarServicio(servicio);

	}



	return servicio;
}


int eServicio_setId(eServicios* this,int id)
{
	int seCargo=-1;

	if(this != NULL && id >= 0)
	{
		this->idServicio=id;
		seCargo=0;
	}

	return seCargo;

}

int eServicio_getId(eServicios* this,int* id)
{
	int seCargo=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->idServicio;
		seCargo=0;
	}

	return seCargo;
}


int eServicio_setDescripcion(eServicios* this,char* descripcion)
{
	int seCargo=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		seCargo=0;
	}

	return seCargo;
}
int eServicio_getDescripcion(eServicios* this,char* descripcion)
{
	int seCargo=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		seCargo=0;
	}

	return seCargo;
}

int eServicio_setTipo(eServicios* this,int tipo)
{
	int seCargo=-1;

	if(this != NULL && tipo >= 0)
	{
		this->tipo=tipo;
		seCargo=0;
	}

	return seCargo;

}

int eServicio_getTipo(eServicios* this,int* tipo)
{
	int seCargo=-1;

	if(this != NULL && tipo != NULL)
	{
		*tipo=this->tipo;
		seCargo=0;
	}

	return seCargo;
}

int eServicio_setPrecioUnitario(eServicios* this,float precioUnitario)
{
	int seCargo=-1;

	if(this != NULL && precioUnitario > 0)
	{
		this->precioUnitario=precioUnitario;
		seCargo=0;
	}

	return seCargo;
}
int eServicio_getPrecioUnitario(eServicios* this,float* precioUnitario)
{
	int seCargo=-1;

	if(this != NULL && precioUnitario != NULL)
	{
		*precioUnitario=this->precioUnitario;
		seCargo=0;
	}

	return seCargo;
}

int eServicio_setCantidad(eServicios* this,int cantidad)
{
	int seCargo=-1;

	if(this != NULL && cantidad >= 0)
	{
		this->cantidad=cantidad;
		seCargo=0;
	}

	return seCargo;

}

int eServicio_getCantidad(eServicios* this,int* cantidad)
{
	int seCargo=-1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad=this->cantidad;
		seCargo=0;
	}

	return seCargo;
}


int eServicio_setTotal(eServicios* this,float total)
{
	int seCargo=-1;

	if(this != NULL && total > 0)
	{
		this->total=total;
		seCargo=0;
	}

	return seCargo;
}
int eServicio_getTotal(eServicios* this,float* total)
{
	int seCargo=-1;

	if(this != NULL && total != NULL)
	{
		*total=this->total;
		seCargo=0;
	}

	return seCargo;
}

void eServicio_imprimirServicio(eServicios* this)
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float total;


	if(this != NULL)
	{
		eServicio_getId(this, &id);
		eServicio_getDescripcion(this, descripcion);
		eServicio_getTipo(this, &tipo);
		eServicio_getPrecioUnitario(this, &precioUnitario);
		eServicio_getCantidad(this, &cantidad);
		eServicio_getTotal(this, &total);


		printf("%-5d %-15s %-20d %-20.2f %-15d %-20.2f \n", id, descripcion, tipo, precioUnitario, cantidad, total);

	}
}

int eServicio_sortByDescripcion(void* serviciosI, void* serviciosJ)
{
	int retorno;
	char descripcionI[100];
	char descripcionJ[100];

	eServicios* pServicioI;
	eServicios* pServicioJ;

	if(serviciosI != NULL && serviciosJ != NULL)
	{
		pServicioI=(eServicios*)serviciosI;
		pServicioJ=(eServicios*)serviciosJ;

		eServicio_getDescripcion(pServicioI, descripcionI);
		eServicio_getDescripcion(pServicioJ, descripcionJ);

		retorno=strcmp(descripcionI,descripcionJ);
		if(retorno < 0)
		{
			retorno=-1;
		}
		else
		{
			if(retorno> 0)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

void eServicio_borrarServicio(eServicios* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;

	}
}


int eServicio_filterByMayorista(void* eServicio)
{
	int retorno=-1;
	int mayoristaAux;
	eServicios* pServicio;

	if(eServicio != NULL)
	{
		pServicio = (eServicios*) eServicio;

		eServicio_getTipo(pServicio, &mayoristaAux);

		if(mayoristaAux == MAYORISTA)
		{
			retorno =0;
		}
	}
	return retorno;
}

int eServicio_filterByMinorista(void* eServicio)
{
	int retorno=-1;
	int minoristaAux;
	eServicios* pServicio;

	if(eServicio != NULL)
	{
		pServicio = (eServicios*) eServicio;

		eServicio_getTipo(pServicio, &minoristaAux);

		if(minoristaAux == MINORISTA)
		{
			retorno =0;
		}
	}
	return retorno;
}

int eServicio_filterByExportar(void* eServicio)
{
	int retorno=-1;
	int exportarAux;
	eServicios* pServicio;

	if(eServicio != NULL)
	{
		pServicio = (eServicios*) eServicio;

		eServicio_getTipo(pServicio, &exportarAux);

		if(exportarAux == EXPORTAR)
		{
			retorno =0;
		}
	}
	return retorno;
}

void eServicio_calcularPrecioTotal(void* eServicio)
{
	eServicios* pServicio;
	int cantidadAux;
	float totalAux;
	float precioAux;

	if(eServicio != NULL)
	{
		pServicio = ((eServicios*)eServicio);

		eServicio_getTotal(pServicio, &totalAux);
		eServicio_getCantidad(pServicio, &cantidadAux);
		eServicio_getPrecioUnitario(pServicio, &precioAux);

		totalAux = cantidadAux * precioAux;
	}

}
