#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[128];
	char nombre[128];
	char hrsTrabajadas[128];
	char sueldo[128];
	Employee* empleados;


	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,hrsTrabajadas,sueldo);
			empleados = employee_newParametros(id, nombre, hrsTrabajadas, sueldo);
			if(empleados!=NULL&&empleados->id!=0)
			{
				ll_add(pArrayListEmployee,empleados);
			}
		}
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado;
	int retornoFread;

	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{

		while(!feof(pFile))
		{
			auxEmpleado=employee_new();
			retornoFread=fread(auxEmpleado, sizeof(Employee), 1, pFile);

			if(auxEmpleado!=NULL&&retornoFread==1)
			{
				ll_add(pArrayListEmployee,auxEmpleado);
			}

		}
	}
    return 1;
}
