/*
 * utn_validaciones.c
 *
 *  Created on: 26 may. 2022
 *      Author: brian
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#include <ctype.h>
#include <string.h>



int esNumero(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			if(isdigit(cadena[i])==0 && cadena[i]!='.' && cadena[0]!='+' && cadena[0]!='-')
			{
				retorno=0;
				break;
			}

		}

	}
	return retorno;
}

int validarSignos(char* cadena)
{
	int i;
	int tamanioCadena;
	int retorno=-1;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);
		cadenaEnMinuscula(cadena);

		for(i=0;i<tamanioCadena;i++)
		{

			if(cadena[i] < 97 || cadena[i] > 122)
			{

				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int validarEspacio(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	tamanioCadena=strlen(cadena);

	for(i=0;i<tamanioCadena;i++)
	{
		if(cadena[i] == ' ' || cadena[i] == '\t' || cadena[i] == '\v')
		{
			retorno=0;
			break;
		}

	}
	return retorno;
}

int primerLetraMayuscula(char* cadena)
{
	int retorno=-1;
	int tamanioCadena;
	int i;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			if(i==0)
			{
				cadena[i]=toupper(cadena[i]);
			}
			if(cadena[i]==' ')
			{
				cadena[i+1]=toupper(cadena[i+1]);
			}
		}

		retorno=0;
	}

	return retorno;
}

int cadenaEnMinuscula(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	if(cadena!=NULL)
	{

		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			cadena[i]=tolower(cadena[i]);
		}

		retorno=0;
	}
	return retorno;
}

int cadenaEnMayuscula(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	if(cadena!=NULL)
	{

		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			cadena[i]=toupper(cadena[i]);
		}

		retorno=0;
	}
	return retorno;
}

int validarLetrasYNumeros(char* cadena)
{
	int i;
	int retorno=-1;
	int tamanioCadena;

	if(cadena != NULL)
	{
		tamanioCadena= strlen(cadena);

		for(i=0; i<tamanioCadena; i++)
		{
			if((isalpha(cadena[i]) == 0 ) && (isdigit(cadena[i]) == 0))
			{
						retorno = 0;
						break;
					}
			}
	}

	return retorno;
}

int validarLetras(char* cadena)
{
	int i;
	int retorno;


	retorno=1;

	if(cadena != NULL)
	{
		for(i=0; i<strlen(cadena); i++)
		{
					if((cadena[i] != ' ') && (isalpha(cadena[i]) == 0 ))
					{
						retorno = 0;
						break;
					}
					if(cadena[i] == ' ' && i == 0)
					{
						retorno= 0;
						break;
					}
			}

	}
	return retorno;
}

int validarCadenaTamanio(char* cadena, int tamCadena)
{
	int retorno;
	char auxCadena[1000];

	retorno=0;

	if (cadena != NULL && tamCadena > 0 )
	{
		if (fgets(auxCadena, sizeof(auxCadena), stdin) != NULL)
		{
			if(auxCadena[strnlen(auxCadena, sizeof(auxCadena)) - 1] == '\n')
			{
				auxCadena[strnlen(auxCadena, sizeof(auxCadena)) - 1] = '\0';
			}
			if (strlen(auxCadena)+1 <= tamCadena && strlen(auxCadena)>0)
			{
				strncpy(cadena, auxCadena, tamCadena);
				retorno = 1;
			}
		}
	}

	return retorno;
}
