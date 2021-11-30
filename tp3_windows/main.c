#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();
    int contCargaArchivos=0;


    int opcion;
    do{
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n"
    			"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3. Alta de empleado\n"
    			"4. Modificar datos de empleado \n"
    			"5. Baja de empleado \n"
    			"6. Listar empleados\n"
    			"7. Ordenar empleados\n"
    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    			"10. Salir\n");

    	opcion=CargarEnteroConMaxYMin("\nIngrese la opcion que desee: ", "\nERROR! Ingrese nuevamente la opcion que desee: ", 1, 10);


    	switch(opcion)
    	{
    	case 1:
    		if(contCargaArchivos==0)
    		{
     		controller_loadFromText("data.csv",listaEmpleados);
     		contCargaArchivos++;
    		}else
    		{
    			printf("Ya se han cargado los archivos\n");
    		}

    		break;
    	case 2:
    		if(contCargaArchivos==0)
    		{
				if((fopen("dataBin.bin","r"))!=NULL)
				{
					controller_loadFromBinary("dataBin.bin",listaEmpleados);
					contCargaArchivos++;
				}else
				{
					printf("Primero se debe guardar datos en el archivo dataBin\n");
				}
    		}else
    		{
    			printf("Ya se han cargado los archivos\n");
    		}
    		break;
    	case 3:
    		if(contCargaArchivos>0)
    		{
     		controller_addEmployee(listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 4:
    		if(contCargaArchivos>0)
    		{
    		controller_editEmployee(listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 5:
    		if(contCargaArchivos>0)
    		{
    		controller_removeEmployee(listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 6:
    		if(contCargaArchivos>0)
    		{
    		controller_ListEmployee(listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 7:
    		if(contCargaArchivos>0)
    		{
    		controller_sortEmployee(listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 8:
    		if(contCargaArchivos>0)
    		{
    		controller_saveAsText("data.csv",listaEmpleados);
    		controller_saveAsBinary("dataBin.bin" ,listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 9:
    		if(contCargaArchivos>0)
    		{
    		controller_saveAsText("data.csv",listaEmpleados);
     		controller_saveAsBinary("dataBin.bin" ,listaEmpleados);
    		}else
    		{
    			printf("Primero debe cargar los archivos\n");
    		}
    		break;
    	case 10:
    		ll_deleteLinkedList(listaEmpleados);
    		break;
    	}
    }while(opcion>0&&opcion<10);

    return 0;
}

