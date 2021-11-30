#include "ArrayEmployees.h"


int BuscarPrimerEspacioVacio(Employee empleados[],int len)
{
	int retorno;
	retorno=-1;
	if(empleados!=NULL&&len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(empleados[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
return retorno;
}

int findEmployeeById(Employee empleados[],int len,int id)
{
	int retorno;
	 retorno=-1;
	if(empleados!=NULL&&len>0&&id>0)
	{
		for(int i=0;i<len;i++)
		{
			if(empleados[i].id==id&&empleados[i].isEmpty==CARGADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


void CargarEmpleado(Employee empleados[],int len,int id)
{
	char name[TamName];
	char lastname[TamName];
	int salary;
	int sector;
	if(empleados!=NULL)
	{
		CargarNombreOApellido(name,"Ingrese su nombre: ","¡Error! Ingrese nuevamente su nombre: ");
		CargarNombreOApellido(lastname,"Ingrese su Apellido: ","¡Error! Ingrese nuevamente su Apellido: ");
		salary=CargarFlotante("Ingrese su salario: ","¡Error! salario no valido,ingreselo nuevamente: ");
		sector=CargarEntero("Ingrese su sector: ","¡Error! sector no valido, ingreselo nuevamente: ");
		addEmployee(empleados,EMPLEADOSmax,id,name,lastname,salary,sector);
	}else
	{
		printf("No se ha podido cargar el empleado.\n");
	}

}


int initEmployees(Employee empleados[],int len)
{
	int retorno;
	if(empleados!=NULL&&len>0)
	{
		for(int i=0;i<=len;i++)
		{
			empleados[i].isEmpty=VACIO;
			empleados[i].salary=VACIO;
			empleados[i].sector=VACIO;
			retorno=0;
		}
	}else
	{
		retorno=-1;
	}
	return retorno;
}

int addEmployee(Employee empleados[],int len,int id,char name[],char lastName[],float salary,int sector)
{
	int retorno;
	int index;
	retorno=-1;
	if(empleados!=NULL&&len>0&&id>0&&name!=NULL&&lastName!=NULL&&salary>0&&sector>0)
	{
		index=BuscarPrimerEspacioVacio(empleados, len);
		if(index!=-1)
		{
			empleados[index].id=id;
			strcpy(empleados[index].name,name);
			strcpy(empleados[index].lastName,lastName);
			empleados[index].salary=salary;
			empleados[index].sector=sector;
			empleados[index].isEmpty=CARGADO;
			printf("Su id es: %d\n",empleados[index].id);
			retorno=0;
		}else
		{
			printf("Ya no queda espacio disponible para un empleado nuevo");
		}
	}
	return retorno;
}

int removeEmployee(Employee empleados[],int len, int id)
{
	int retorno;
	int index;
	retorno=-1;
	if(empleados!=NULL&&id>0&&len>0)
	{
		index=findEmployeeById(empleados, len, id);
		while(index==-1)
		{
			id=CargarEntero("El id ingresado no pertenece a ningun empleado, ingresar nuevamente el id: ","¡Error! Ingrese nuevamente el id: ");
			index=findEmployeeById(empleados, len, id);
		}
		empleados[index].isEmpty=VACIO;
		retorno=0;
	}
	return retorno;
}

int sortEmployees(Employee empleados[],int len,int order)
{
	int retorno;
	retorno=-1;
	for(int j=0;j<len;j++)
	{
		if(empleados[j].isEmpty==CARGADO)
		{
			for(int k=j+1;k<len;k++)
			{
				if(empleados[k].isEmpty==CARGADO)
				{
					if(order==1)
					{
						OrdenarAscendiente(empleados,j,k,len);
					}else
					{
						if(order==0)
						{
							OrdenarDescendiente(empleados,j,k, len);
						}
					}
				}
			}
		}

	}
	printEmployees(empleados,len);
	return retorno;
}
void OrdenarDescendiente(Employee empleados[],int posUno,int posDos,int len)
{
	Employee empleadosAux;
	if(strcmp(empleados[posUno].lastName,empleados[posDos].lastName)<0||(strcmp(empleados[posUno].lastName,empleados[posDos].lastName)==0&&empleados[posUno].sector<empleados[posDos].sector))
	{
		empleadosAux=empleados[posUno];
		empleados[posUno]=empleados[posDos];
		empleados[posDos]=empleadosAux;
	}

}

void OrdenarAscendiente(Employee empleados[],int posUno,int posDos,int len)
{
	Employee empleadosAux;
	if(strcmp(empleados[posUno].lastName,empleados[posDos].lastName)>0||(strcmp(empleados[posUno].lastName,empleados[posDos].lastName)==0&&empleados[posUno].sector>empleados[posDos].sector))
	{
		empleadosAux=empleados[posUno];
		empleados[posUno]=empleados[posDos];
		empleados[posDos]=empleadosAux;
	}
}

int printEmployees(Employee empleados[],int length)
{
	int retorno;
	retorno=-1;
	printf("|ID |       APELLIDO |   NOMBRE     |   SALARIO      |SECTOR|\n");
	if(empleados!=NULL&&length>0)
	{
		for(int i=0;i<=length;i++)
		{
			if(empleados[i].isEmpty==CARGADO)
			{
				printf("|%2d |%15s |%13s |%15.2f |%4d  |\n",empleados[i].id,empleados[i].lastName,empleados[i].name,empleados[i].salary,empleados[i].sector);
				retorno=0;
			}
		}
	}
	return retorno;
}
void ModificarEmpleado(Employee empleados[])
{
	int opcion;
	int id;
	int index;
	if(empleados!=NULL)
	{
		printEmployees(empleados,EMPLEADOSmax);
		id=CargarEntero("Ingrese el id del empleado a modificar: \n", "ERROR! Ingrese nuevamente el id del empleado a modificar: \n");
		index=findEmployeeById(empleados,EMPLEADOSmax,id);
		while(index==-1)
		{
			id=CargarEntero("El id que ingreso no pertenece a ningun empleado ingresar nuevamente: \n", "ERROR! Ingrese nuevamente el id del empleado a modificar: \n");
			index=findEmployeeById(empleados,EMPLEADOSmax,id);
		}
				do
				{
					printf("--------------------------\n"
							"1-Modificar Nombre       |\n"
							"2-Modificar Apellido     |\n"
							"3-Modificar Salario      |\n"
							"4-Modificar Sector       |\n"
							"5-Salir                  |\n"
							"--------------------------\n");
					opcion=CargarEntero("Ingrese la opcion: ","¡Error!Ingrese la opcion nuevamente: ");
					switch(opcion)
					{
						 case 1:
							 PedirString(empleados[index].name,"Ingrese el nombre: ");
						break;
						 case 2:
							 PedirString(empleados[index].lastName,"Ingrese su Apellido: ");
						break;
						 case 3:
							 empleados[index].salary=CargarFlotante("Ingrese el salario: ","¡Error! Ingrese nuevamente el salario");
						break;
						 case 4:
							 empleados[index].sector=CargarEntero("Ingrese el sector","¡Error!Ingrese nuevamente el sector");
						break;
					}
				}while(opcion>0&&opcion<5);
	}
}



void CalcularPromedioYTotal(Employee empleados[],int len)
{
	int cantEmpleados;
	int totalSalarios;
	int promedioTotal;
	int cantEmpleadosSobreElPromedio;
	totalSalarios=0;
	cantEmpleados=0;
	cantEmpleadosSobreElPromedio=0;
	for(int i=0;i<len;i++)
	{
		if(empleados[i].isEmpty==CARGADO)
		{
			cantEmpleados++;
			totalSalarios=totalSalarios+empleados[i].salary;
		}
	}
	promedioTotal=totalSalarios/cantEmpleados;
	for(int j=0;j<len;j++)
	{
		if(empleados[j].isEmpty==CARGADO&&empleados[j].salary>promedioTotal)
		{
			cantEmpleadosSobreElPromedio++;
		}
	}

	printf(" El total de los salario es: %d \n El promedio de los salarios es: %d \n La cantidad de empleado que superan el promedio es: %d\n",totalSalarios,promedioTotal,cantEmpleadosSobreElPromedio);
}

void InformarEmpleados(Employee empleados[])
{
	int opcion;
	int opcionCase1;
	do
	{
	printf("1-Listado Empleados ordenados\n"
			"2-Total,Promedio de salarios y cantidad de empleados que superan el promedio\n3-Salir\n");
			opcion=CargarEntero("Ingrese la opcion que desee: ","¡Error! Ingrese una opcion valida");
	switch(opcion)
	{
	case 1:
		opcionCase1=CargarEnteroConMaxYMin("1-Listado ascendente \n0-Listado descendente\nIngrese opcion: ","¡Error!Ingrese una opcion valida",0,1);
		sortEmployees(empleados, EMPLEADOSmax,opcionCase1);
		break;
	case 2:
		CalcularPromedioYTotal(empleados,EMPLEADOSmax);
		break;

	}
	}while(opcion>0&&opcion<3);



}
