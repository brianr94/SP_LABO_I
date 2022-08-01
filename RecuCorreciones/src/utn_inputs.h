/*
 * utn_Libreria.h
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @fn int pedirCadenaValidada(char*, char*, char*, int)
/// @brief solicita una cadena de caracteres y verifica que la cadena no exceda el maximo definido, si contiene numeros o contiene signos.
///
/// @param cadena puntero a cadena de caracteres
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param maxTam tamanio para verificar el maximo de la cadena de caracteres
/// @return retorna 0 si esta fue correcta la cadena de caracteres, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCadenaValidada(char* cadena,char* mensaje,char* mensajeError,int maxTam);

/// @fn int pedirNumero(int*, char*, char*, int, int)
/// @brief solicita un numero al usuario y verifica que este entre un minimo y maximo definido
///
/// @param numero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max);

/// @fn int pedirCadenaAlfaNumerica(char*, char*, char*, int)
/// @brief se solicita al usuario el ingreso de una cadena alfanumerica y se valida que no contenga espacios,que no exceda un tamaño mayor establecido.
///
/// @param cadena cadena puntero a cadena de caracteres.
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param tamMax tamaño maximo a validar
/// @return retorna 0 si la validacion es correcta, sino -1 si hubo error en el tamaño o puntero a NULL.
int pedirCadenaAlfaNumerica(char* cadena,char* mensaje,char* mensajeError,int tamMax);

/// @fn int pedirNumeroFlotante(float*, char*, char*, int, int)
/// @brief se solicita un numero flotante al usuario  y verifica que este entre un minimo y maximo definido
///
/// @param numero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumeroFlotanteConRango(float* numero, char* mensaje,char* mensajeError,int min,int max);

/// @fn int pedirNumeroFlotante(float*, char*, char*)
/// @brief se solicita un numer flotante al usuario y verifica que no contenga espacios y letras
///
/// @param numero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.s
int pedirNumeroFlotante(float* numero, char* mensaje, char* mensajeError);

/// @fn int pedirNumeroEnteroValidado(int*, char*, char*, int, int)
/// @brief solicita un numero al usuario y verifica que este entre un minimo y maximo definido
///
/// @param pNumero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumeroEnteroValidado(int* pNumero, char* mensaje, char* mensajeError, int min, int max);

/// @fn int pedirCadena(char*, char*, char*, int)
/// @brief solicita una cadena de caracteres y verifica que la cadena no exceda el maximo definido
///
/// @param cadena puntero a cadena de caracteres
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param tamMax tamanio maximo a verificar en la cadena de caracteres
/// @return retorna 0 si esta fue correcta la cadena de caracteres, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int tamMax);

/// @fn int pedirCaracter(char*, char*)
/// @brief solicita un caracter al usuario
///
/// @param caracter puntero a caracter
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @return retorna 0 si el caracter fue correctamente ingresado, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCaracter(char* caracter, char* mensaje);

/// @fn int verificarConfirmacion(char*)
/// @brief solicita el caracter 's' y valida el caracter ingresado
///
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @return retorna 0 si la validacion del caracter es correcta, en caso contario retorna -1 si hubo error puntero a NULL.
int verificarConfirmacion(char* mensaje);


/// @fn int calcularDivision(float, float, float*)
/// @brief Recibe los operandos A y B, calcula la division y retorna 1 en caso de que la division fue resuelta,
/// y en caso contrario retorna 0 si no fue resuelto,
///
/// @param numeroA Operando A para realizar la division.
/// @param numeroB Operando B para realizar la division.
/// @param refDivision referencia para pasar el resultado en caso de que el retorno sea 1.
/// @return retorna 1 si la divison fue resuelta y pasa por referencia el resultado y caso contrario retorna 0 sino fue resuelta, por ser 0 el divisor.
int calcularDivision(float numeroA, float numeroB, float* refDivision);


/// @fn int pedirCadenaCompuesta(char*, char*, char*, int, int)
/// @brief se solicita al usuario una cadena de caracteres validando que no haya numeros, espacios en el primer lugar, o exceda el tamaño maximo definido y signos.
///
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param cadena puntero a cadena de caracteres
/// @param tamCadena tamaño maximo de la cadena
/// @param reintentos cantidad de reintentos que se le da al usuario para ingresar el dato
/// @return retorna 0 si la cadena es correcta, sino retorna -1 si la cadena es erronea o se termina los intentos.
int pedirCadenaCompuesta(char* mensaje, char* mensajeError, char* cadena, int tamCadena, int reintentos);

/// @fn int pedirNumeroValidado(int*, char*, char*)
/// @brief
///
/// @param numero
/// @param mensaje
/// @param mensajeError
/// @return
int pedirNumeroValidado(int* numero,char* mensaje,char* mensajeError);

#endif /* UTN_INPUTS_H_ */
