

#ifndef BIBLOTECAMIA_C_
#define BIBLOTECAMIA_C_
#include "biblotecaMia.h"

char PedirString(char cadena[],char mensaje[])
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",cadena);
	return *cadena;
}

int ValidarString(char nombre[])
{
	int valido;
	int i;
	i=0;
	valido=1;
	while(nombre[i]!='\0'&&(valido==1))
	{
		if(isalpha(nombre[i])!=0||nombre[i]=='ñ')
		{
			valido=1;
		}else
		{
			valido=0;
		}
		i++;
	}
	return valido;
}

int CargarString(char nombre[],char mensaje[],char mensajeError[])
{
	int retorno=1;;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		*nombre=PedirString(nombre,mensaje);

		while(ValidarString(nombre)==0)
		{
			*nombre=PedirString(nombre,mensajeError);
		}
		retorno=0;
	}
	return retorno;
}

int CargarEnteroChar(char entero[],char mensaje[],char mensajeError[])
{
	int retorno=-1;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);

		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		 retorno=0;
	}
	return retorno;
}

int ValidarEntero(char numero[])
{
	int i=0;
	int valido;
	valido=1;
	while(numero[i]!='\0'&&(valido==1))
	{
		if(isdigit(numero[i])!=0)
		{
			valido=1;
		}else
		{
			valido=0;
		}

		i++;
	}
	return valido;
}
int CargarEntero(char mensaje[],char mensajeError[])
{
	char entero[50];
	int enteroFinal;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);
		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		 enteroFinal=atoi(entero);
	}
	return enteroFinal;
}

int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max)
{
	char entero[50];
	int enterofinal;
	int valido;
	valido=1;
	if(mensaje!=NULL&&mensajeError!=NULL&&min<max)
	{
		while(valido>0)
		{

			PedirString(entero,mensaje);
			while(ValidarEntero(entero)==0)
			{
				PedirString(entero,mensajeError);
			}
			enterofinal=atoi(entero);
			if(enterofinal<min||enterofinal>max)
			{
				valido=2;
			}else
			{
				valido=0;
			}
		}

	}
	return enterofinal;
}

#endif /* BIBLOTECAMIA_C_ */
