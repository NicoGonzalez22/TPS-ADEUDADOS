#include "BiblioGeneral.h"



float CargarFlotante(char mensaje[],char mensajeError[])
{
	float flotanteFinal;
	char flotante[TamNum];
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(flotante,mensaje);

		while(strlen(flotante)>TamNum)
		{
			PedirString(flotante,"Ingrese un numero flotante con un maximo de 9 digitos(sin incluir el punto): ");
		}
		while(ValidarFlotante(flotante)==0||ValidarFlotante(flotante)==2)
		{
			if(ValidarFlotante(flotante)==0)
			{
				PedirString(flotante,mensajeError);
			}else
			{
				PedirString(flotante,"Ingrese un numero flotante con '.', no con ',':  ");
			}
		}
		flotanteFinal=atof(flotante);
	}
	return flotanteFinal;
}

int ValidarFlotante(char flotante[])
{
	int i;
	int valido;
	int contadorPuntos;
	contadorPuntos=0;
	valido=1;
	i=0;
	while(flotante[i]!='\0'&&(valido==1))
	{
		if(isdigit(flotante[i])!=0||flotante[i]=='.')
		{
			valido=1;
		}else
		{
			valido=0;
		}
		if(flotante[i]==',')
		{
			valido=2;
		}
		if(flotante[i]=='.')
		{
			contadorPuntos++;
		}
		if(contadorPuntos>1)
		{
			valido=0;
		}

		i++;
	}
	return valido;
}

int CargarEntero(char mensaje[],char mensajeError[])
{
	char entero[TamNum];
	int enterofinal;

	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);
		while(strlen(entero)>TamNum)
		{
			PedirString(entero,"Ingrese un numero con un maximo de 10 digitos");
		}
		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		enterofinal=atoi(entero);
	}
	return enterofinal;
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

char PedirString(char cadena[],char mensaje[])
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",cadena);

	return *cadena;
}

void CargarNombreOApellido(char nombre[],char mensaje[],char mensajeError[])
{
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		*nombre=PedirString(nombre,mensaje);

		while(ValidarNombre(nombre)==0)
		{
			*nombre=PedirString(nombre,mensajeError);
		}
	}
}

int ValidarNombre(char nombre[])
{
	int valido;
	int i;
	i=0;
	valido=1;
	while(nombre[i]!='\0'&&(valido==1))
	{
		if(isalpha(nombre[i])!=0||nombre[i]=='ñ'||nombre[i]==' ')
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

int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max)
{
	char entero[TamNum];
	int enterofinal;

	if(mensaje!=NULL&&mensajeError!=NULL&&min<max)
	{
		PedirString(entero,mensaje);
		while(strlen(entero)>TamNum)
		{
			PedirString(entero,"Ingrese un numero con un maximo de 10 digitos");
		}
		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		enterofinal=atoi(entero);
		while(enterofinal<min||enterofinal>max)
		{
				PedirString(entero,mensaje);
				if(ValidarEntero(entero)==0)
				{
					PedirString(entero,mensajeError);
				}
				enterofinal=atoi(entero);
		}
	}
	return enterofinal;
}

