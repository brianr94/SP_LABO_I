/*
 * eServicios.h
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */

#ifndef SRC_ESERVICIOS_H_
#define SRC_ESERVICIOS_H_

#include <stdlib.h>
#include <stdio.h>


typedef struct
{
	int idServicio;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float total;

}eServicios;



eServicios*eServicio_newServicio();
eServicios* eServicio_newParametros(char* idStr,char* descripcionStr, char* tipostr, char* precioUnitarioStr, char* cantidadStr, char* totalStr);

int eServicio_setId(eServicios* this,int id);
int eServicio_getId(eServicios* this,int* id);

int eServicio_setDescripcion(eServicios* this,char* descripcion);
int eServicio_getDescripcion(eServicios* this,char* descripcion);

int eServicio_setTipo(eServicios* this,int tipo);
int eServicio_getTipo(eServicios* this,int* tipo);

int eServicio_setPrecioUnitario(eServicios* this,float precioUnitario);
int eServicio_getPrecioUnitario(eServicios* this,float* precioUnitario);

int eServicio_setCantidad(eServicios* this,int cantidad);
int eServicio_getCantidad(eServicios* this,int* cantidad);

int eServicio_setTotal(eServicios* this,float total);
int eServicio_getTotal(eServicios* this,float* total);

void eServicio_imprimirServicio(eServicios* this);
int eServicio_sortByDescripcion(void* serviciosI, void* serviciosJ);
void eServicio_calcularPrecioTotal(void* eServicio);
int eServicio_buscarTotalMayor(void* eServicio);
void eServicio_totalConDescuento(void* eServicio);

int eServicio_filterByMinorista(void* eServicio);
int eServicio_filterByMayorista(void* eServicio);
int eServicio_filterByExportar(void* eServicio);



void eServicio_borrarServicio(eServicios* this);

#endif /* SRC_ESERVICIOS_H_ */
