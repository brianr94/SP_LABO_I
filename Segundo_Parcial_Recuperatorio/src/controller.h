/*
 * controller.h
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_saveAsText(char* path , LinkedList* pArrayListServicio);
int controller_ListServicios(LinkedList* pArrayListServicio);

int controller_listFilter(LinkedList* pArrayListServicio);
int Controller_SortByDescription(LinkedList* pArrayListServicio);
int controller_totalPriceAssignment(LinkedList* pArrayListServicio);

int controller_loadFromText(char* path , LinkedList* pArrayListServicio);

#endif /* CONTROLLER_H_ */
