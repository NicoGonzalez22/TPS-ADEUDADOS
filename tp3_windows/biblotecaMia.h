/*
 * biblotecaMia.h
 *
 *  Created on: 20 nov 2021
 *      Author: Usuario
 */

#ifndef BIBLOTECAMIA_H_
#define BIBLOTECAMIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @fn char PedirString(char[], char[])
/// @brief Pide una cadena de carecteres
///
/// @param cadena Donde se almacena la cadena de carecteres
/// @param mensaje Mensaje que muestra al pedir la cadena de carecteres
/// @return devuelve la cadena de caracteres
char PedirString(char cadena[],char mensaje[]);
/// @fn int ValidarNombre(char[])
/// @brief Recibe una cadena de caracteres y utiliza la funcion isalpha para validar que los caracteres sean
/// alfabetos
///
/// @param nombre Cadena que recibe la funcion
/// @return Devuelve 1 si toda la cadena son alfabetos o 0 si almenos un caracter no lo es
int ValidarString(char nombre[]);
/// @fn void CargarString(char[], char[], char[])
/// @brief 	Se pide que ingrese el string, utiliza la funcion ValidarString para
/// validar que sean solo caracteres
///
/// @param nombre Cadena de caractereces que recibe
/// @param mensaje Mensaje que muestra al pedir el string
/// @param mensajeError Mensaje que muestra cuando hay algun error en el string ingresado
/// @return retorna 0 si salio todo bien 1 si hubo error
int CargarString(char nombre[],char mensaje[],char mensajeError[]);
/// @fn int CargarEntero(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el entero con la funcion ValidarEntero
/// y si sale todo bien utiliza la funcion atoi para convertir la cadena en
/// entero
/// @param mensaje Mensaje que muestra al pedir el entero
/// @param mensajeError Mensaje que muestra al haber algun error
/// @return Devuelve 1 si salio mal 0 si salio bien
int CargarEnteroChar(char entero[],char mensaje[],char mensajeError[]);
/// @fn int ValidarEntero(char[])
/// @brief Recibe como parametro una cadena de caracteres
/// y valida con la funcion isdigit si son digitos
///
/// @param numero Cadena de caracteres que recibe
/// @return Devuelve 1 si efectivamente es un numero entero o 0 si hay algun error
int ValidarEntero(char numero[]);
/// @fn int CargarEntero(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el entero con la funcion ValidarEntero
/// y si sale todo bien utiliza la funcion atoi para convertir la cadena en
/// entero
/// @param mensaje Mensaje que muestra al pedir el entero
/// @param mensajeError Mensaje que muestra al haber algun error
/// @return Devuelve el entero
int CargarEntero(char mensaje[],char mensajeError[]);
/// @fn int CargarEnteroConMaxYMin(char[], char[], int, int)
/// @brief Pide el ingreso de un numero entero validando un maximo y un minimo,tambien utiliza la funcion
/// ValidarEntero para corroborar que sean numeros los ingresados
///
/// @param mensaje Mensaje que muestra cuando pide el entero
/// @param mensajeError Mensaje que muestra cuando el entero contiene algun error
/// @param min Numero minimo a ingresar
/// @param max Numero maximo a ingresar
/// @return Devuelve el numero entero
int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max);


int ValidarCargaDeArchivos(int cont);


#endif /* BIBLOTECAMIA_H_ */
