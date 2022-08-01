/*
 * utn_Libreria.c
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#include "utn_inputs.h"
#include "utn_validaciones.h"

int pedirCadenaValidada(char* cadena,char* mensaje,char* mensajeError,int maxTam)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && maxTam>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadenaAux);

		while(strlen(cadenaAux)>maxTam || esNumero(cadenaAux)==-1 || validarSignos(cadenaAux)==0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",cadenaAux);
		}

		cadenaEnMinuscula(cadenaAux);
		primerLetraMayuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}

int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max)
{
	int retorno=-1;
	char numeroAux[51];
	int numeroEnteroAux;


	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroAux);
		numeroEnteroAux=atoi(numeroAux);


		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || (numeroEnteroAux>max||numeroEnteroAux<min))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
			numeroEnteroAux=atoi(numeroAux);
		}

		*numero=atoi(numeroAux);
		retorno=0;

	}

	return retorno;
}

int pedirNumeroFlotanteConRango(float* numero, char* mensaje,char* mensajeError,int min,int max)
{
	int retorno=-1;
	char numeroAux[51];
	float numeroFlotAux;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroAux);
		numeroFlotAux=atof(numeroAux);

		while((!esNumero(numeroAux) && !validarEspacio(numeroAux)) || (numeroFlotAux<min ||numeroFlotAux>max))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
			numeroFlotAux=atof(numeroAux);
		}

		*numero=atof(numeroAux);
		retorno=0;
	}

	return retorno;
}

int pedirNumeroFlotante(float* numero, char* mensaje, char* mensajeError)
{
	int retorno=-1;
	char numeroAux[51];
	float numeroFlotAux;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroAux);
		numeroFlotAux=atof(numeroAux);


		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || numeroFlotAux< 0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
			numeroFlotAux=atof(numeroAux);
		}

		*numero=atof(numeroAux);
		retorno=0;
	}

	return retorno;
}

int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int tamMax)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && tamMax>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadenaAux);

		while(strlen(cadenaAux)>tamMax)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",cadenaAux);
		}
		cadenaEnMinuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}

int pedirCadenaAlfaNumerica(char* cadena,char* mensaje,char* mensajeError,int tamMax)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && tamMax>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadenaAux);

		while((strlen(cadenaAux)>tamMax || !validarEspacio(cadenaAux) || !validarSignos(cadenaAux)) && validarLetrasYNumeros(cadenaAux)==0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",cadenaAux);
		}
		cadenaEnMayuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}



int pedirNumeroEnteroValidado(int* pNumero, char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;
	int retorno=-1;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	*pNumero=numeroIngresado;
	retorno=0;

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}

int calcularDivision(float numeroA, float numeroB, float* refDivision)
{
	int resultado;
	float totalDivision;

	if(numeroB==0)
	{
		resultado= 0;
	}
	else
	{
		totalDivision= numeroA / numeroB;
		resultado= 1;
	}
	*refDivision = totalDivision;

	return resultado;
}

int pedirCadenaCompuesta(char* mensaje, char* mensajeError, char* cadena, int tamCadena, int reintentos)
{
	int retorno;

	retorno=0;

	do {

		printf("%s", mensaje);
		fflush(stdin);

		if (mensaje!= NULL && mensajeError!= NULL && cadena !=NULL && tamCadena > 0)
		{
			if (validarCadenaTamanio(cadena, tamCadena) == 1 && validarLetras(cadena) == 1)
			{
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				reintentos--;
			}

		}

	}while(reintentos > 0);

	if(reintentos==0)
	{
		printf("\n\nTe quedaste sin intentos, ingresa nuevamente !!!\n\n");
	}

	return retorno;
}

int pedirNumeroValidado(int* numero,char* mensaje,char* mensajeError)
{
	int retorno=-1;
	char numeroAux[51];


	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroAux);


		while(!esNumero(numeroAux) && !validarEspacio(numeroAux))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
		}

		*numero=atoi(numeroAux);
		retorno=0;

	}

	return retorno;
}
