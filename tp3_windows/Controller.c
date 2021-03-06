#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "Employee.h"
//#include "parser.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
#define tamDefault 50

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r");
    if(pArchivo == NULL)
    {
        printf("\nError al leer el archivo\n");
    }
    else
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        printf("\nDatos cargados con Exito!\n");
    }
    fclose(pArchivo);
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
FILE* pArchivo;
    if((pArchivo = fopen(path,"rb")) == NULL)
    {
        printf("\nError al abrir el archivo\n");
    }
    else
    {
		parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
		printf("\nDatos cargados con Exito!\n");
    }
    	fclose(pArchivo);
    return 0;
}


int UltimoId(char* path,char* idEmpleado)
{
   int retorno=-1;
   FILE* id;
   id=fopen(path,"r");
   if(id!=NULL)
   {
	   retorno=0;
	   fseek(id,0L,SEEK_SET);
	   fscanf(id,"%4s ",idEmpleado);
	   fclose(id);
   }
   return retorno;
}

int GuardarUltimoId(char* path,int idEmpleado)
{
	FILE* id;
	int retorno=-1;
	id=fopen(path,"w");
	if(id!=NULL)
	{
		fseek(id,0L,SEEK_SET);
		fprintf(id,"%d",idEmpleado);
		fclose(id);
		retorno=0;
	}
	return retorno;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
   int retorno=-1;;
   char idEmpleado[50];
   char nombre[tamDefault];
   char horas[tamDefault];
   char sueldo[tamDefault];

  // FILE* data;
 /*  if((id=fopen("id.csv","r"))==NULL)
   {
	   if((id=fopen("id.csv","w"))==NULL)
	   {
		   printf("\nel archivo no pudo ser abierto");
	   }
	   data=fopen("data.csv","r");
	   fseek(data,0L,SEEK_END);
	   fseek(data,-21,SEEK_CUR);
	   fscanf(data,"%[^,],",idEmpleado);
	   fseek(data,0L,SEEK_SET);
	   fclose(data);
	   id=fopen("id.csv","w");
	   fprintf(id,"%s",idEmpleado);
	   fclose(id);
   }else
   {*/

  // }


   if(pArrayListEmployee!=NULL)
   {
	   if((CargarString(nombre, "\nIngrese el nombre del empleado/a: ", "\nERROR !, Ingrese nuevamente el nombre del empleado/a: "))==0)
	   {

		   if((CargarEnteroChar(horas,"\nIngrese las horas trabajadas por el empleado/a: ", "\nERROR !, Ingrese nuevamente las horas trabajadas por el empleado/a: "))==0)
		   {
			   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	  // Abro archivo para saber el ultimo ID
			   if((CargarEnteroChar(sueldo,"\nIngrese el sueldo del empleado/a: ", "\nERROR! Ingrese el sueldo del empleado/a: "))==0&&(UltimoId("UltimoId.csv",idEmpleado))==0)
			   {
				   empleado=employee_newParametros(idEmpleado, nombre, horas, sueldo);
				   empleado->id++;
				   printf("El id del nuevo empleado es: %d\n",empleado->id);
				   ll_add(pArrayListEmployee, empleado);
				   //Guardo en el archivo el ultimo ID
				   GuardarUltimoId("UltimoId.csv",empleado->id);

				   retorno=0;
			   }
		   }
	   }

   }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	empleado=employee_new();
	int i=0;
	int id;
	int opcion;
	int index;

	id=CargarEntero("\nIngrese el id del empleado que desea modificar: ", "\nERROR! Ingrese nuevamente el id del empleado que desea modificar: ");

	empleado=ll_get(pArrayListEmployee,i);
	while(empleado->id!=id)
	{
		empleado=ll_get(pArrayListEmployee,i);
		i++;
	}

	do
	{
		printf("\n1-Mostrar lista de empleados\n"
				"2-Modificar Nombre \n"
				"3-Modificar Horas \n"
				"4-Modificar sueldo \n"
				"5-Salir\n");
		opcion=CargarEnteroConMaxYMin("\nIngrese la opcion que desee: ","\nERROR! Ingrese nuevamente la opcion deseada: ", 1, 5);
		switch(opcion)
		{
		case 1:
			controller_ListEmployee(pArrayListEmployee);
		break;
		case 2:
			CargarString(empleado->nombre, "\nIngrese el nombre del empleado: ","\nIngrese nuevamente el nombre del empleado: ");
			break;
		case 3:
			empleado->horasTrabajadas=CargarEntero("\nIngrese las horas del empleado: ", "\nIngrese nuevamente las horas del empleado: ");

			break;
		case 4:
			empleado->sueldo=CargarEntero("\nIngrese el sueldo del empleado: ", "\nIngrese nuevamente el sueldo del empleado: ");
			break;
		}
	}while(opcion>0&&opcion<5);
	index=ll_indexOf(pArrayListEmployee, empleado);
	ll_set(pArrayListEmployee,index, empleado);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int opcion;
	int id;
	int i=0;
	int retorno=-1;
	int index;
	int cant;
	cant = ll_len(pArrayListEmployee);
	do
	{
		printf("\n1-Mostrar lista de empleados\n"
				"2-Eliminar empleado\n"
				"3-Salir");
		opcion=CargarEnteroConMaxYMin("\nIngrese la opcion deseada: ", "\nERROR! Ingrese nuevamente la opcion deseada: ", 1, 3);

		switch(opcion)
		{
			case 1:
					controller_ListEmployee(pArrayListEmployee);
					break;
			case 2:
					if(pArrayListEmployee!=NULL)
					{
						id=CargarEntero("\nIngrese el id del cliente que desee eliminar: ", "\nERROR! Ingrese nuevamente el id del cliente que desee eliminar: ");
						empleado=ll_get(pArrayListEmployee, i);
						for(;i<cant;i++)
						{
							empleado=ll_get(pArrayListEmployee, i);
							if(empleado->id==id)
							{
								break;
							}
						}
						i=0;
						index=ll_indexOf(pArrayListEmployee, empleado);
						ll_remove(pArrayListEmployee, index);
					    retorno=0;
					}
					break;
		}
	}while(opcion>0&&opcion<3);

	return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* empleado;
    for (i=0;i<cant;i++)
    {
    	empleado = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%5d %15s %15d %15d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int MayorOMenor;
	int opcion;
	int retorno=1;
	do
	{
		printf("1-Ordenar por id\n"
				"2-Ordenar por nombre \n"
				"3-Ordenar por horas trabajadas \n"
				"4-Ordenar por sueldo\n"
				"5-salir");
		opcion=CargarEnteroConMaxYMin("\nIngrese la opcion deseada", "\nERROR! Ingrese nuevamente la opcion deseada", 1, 5);
		switch(opcion){
		case 1:
			MayorOMenor=menu_MayorOMenor();
			ll_sort(pArrayListEmployee, employee_CompareById, MayorOMenor);
			controller_ListEmployee(pArrayListEmployee);
			retorno=0;
			break;
		case 2:
			MayorOMenor=menu_MayorOMenor();
			ll_sort(pArrayListEmployee, employee_CompareByName, MayorOMenor);
			controller_ListEmployee(pArrayListEmployee);
			retorno=0;
			break;
		case 3:
			MayorOMenor=menu_MayorOMenor();
			ll_sort(pArrayListEmployee, employee_CompareByHoras, MayorOMenor);
			controller_ListEmployee(pArrayListEmployee);
			retorno=0;
			break;
		case 4:
			MayorOMenor=menu_MayorOMenor();
			ll_sort(pArrayListEmployee, employee_CompareBySueldo, MayorOMenor);
			controller_ListEmployee(pArrayListEmployee);
			retorno=0;
			break;
		}
	}while(opcion>0&&opcion<5);
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len;
    Employee* empleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"w");
    if (pArchivo == NULL)
    {
        pArchivo = fopen(path,"w");
    }
    if (len>0)
    {
        for (int i=0;i<len;i++)
        {
        empleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        }
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmpleado=NULL;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"wb");
    if (pArchivo != NULL&&pArrayListEmployee!=NULL)
    {
    	for(int i=0;i<len;i++){
        auxEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
        fwrite(auxEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    fclose(pArchivo);
    return 1;
}
