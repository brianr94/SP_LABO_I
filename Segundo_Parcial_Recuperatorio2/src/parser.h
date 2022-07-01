/*
 * parser.h
 *
 *  Created on: 23 jun. 2022
 *      Author: brian
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_
#include "eServicios.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int parser_servicioFromText(FILE* pFile , LinkedList* pArrayListServicios);

#endif /* SRC_PARSER_H_ */
