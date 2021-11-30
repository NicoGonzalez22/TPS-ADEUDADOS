#ifndef BIBLIOGENERAL_H_
#define BIBLIOGENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TamName 51
#define TamNum 10
/// @fn float CargarFlotante(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el flotante con la funcion ValidarFlotante
/// y si sale todo bien utiliza la funcion atof para convertir la cadena en
/// flotante
///
/// @param mensaje Mensaje que muestra al pedir el flotante
/// @param mensajeError Mensaje que muestra cuando hay algun error
/// @return Retorna el flotante
float CargarFlotante(char mensaje[],char mensajeError[]);

/// @fn int ValidarFlotante(char[])
/// @brief Recibe como parametro una cadena de caracteres
/// y valida con la funcion isdigit si son digitos, tambien da como valido
/// los puntos.
///
/// @param flotante Cadena de caracteres que recibe
/// @return Devuelve 1 si el numero es flotante, 0 si hay algun error o 2 si hay comas (,)
int ValidarFlotante(char flotante[]);

/// @fn int CargarEntero(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el entero con la funcion ValidarEntero
/// y si sale todo bien utiliza la funcion atoi para convertir la cadena en
/// entero
/// @param mensaje Mensaje que muestra al pedir el entero
/// @param mensajeError Mensaje que muestra al haber algun error
/// @return Devuelve el entero
int CargarEntero(char mensaje[],char mensajeError[]);

/// @fn int ValidarEntero(char[])
/// @brief Recibe como parametro una cadena de caracteres
/// y valida con la funcion isdigit si son digitos
///
/// @param numero Cadena de caracteres que recibe
/// @return Devuelve 1 si efectivamente es un numero entero o 0 si hay algun error
int ValidarEntero(char numero[]);

/// @fn char PedirString(char[], char[])
/// @brief Pide una cadena de carecteres
///
/// @param cadena Donde se almacena la cadena de carecteres
/// @param mensaje Mensaje que muestra al pedir la cadena de carecteres
/// @return devuelve la cadena de caracteres
char PedirString(char cadena[],char mensaje[]);

/// @fn void CargarNombreOApellido(char[], char[], char[])
/// @brief 	Se pide que ingrese el nombre o el apellido, utiliza la funcion ValidarNombre para
/// validar que sean solo caracteres
///
/// @param nombre Cadena de caractereces que recibe
/// @param mensaje Mensaje que muestra al pedir el nombre
/// @param mensajeError Mensaje que muestra cuando hay algun error en el nombre ingresado
void CargarNombreOApellido(char nombre[],char mensaje[],char mensajeError[]);
/// @fn int ValidarNombre(char[])
/// @brief Recibe una cadena de caracteres y utiliza la funcion isalpha para validar que los caracteres sean
/// alfabetos
///
/// @param nombre Cadena que recibe la funcion
/// @return Devuelve 1 si toda la cadena son alfabetos o 0 si almenos un caracter no lo es
int ValidarNombre(char nombre[]);

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

#endif /* BIBLIOGENERAL_H_ */
