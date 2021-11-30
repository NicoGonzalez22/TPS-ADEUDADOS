#include "Employee.h"

Employee* employee_new()
{
	Employee* empleado;
	empleado= (Employee*)malloc(sizeof(Employee));
	return empleado;
}
void employee_delete(Employee* this)
{
	free(this);
}

int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno=-1;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=0;
		printf("%d",retorno);
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=-1;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno=-1;
	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno=-1;
	if(this!=NULL&&sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* empleado;
	empleado=employee_new();
	empleado->id = atoi(idStr);
	strcpy(empleado->nombre,nombreStr);
	empleado->horasTrabajadas=atoi(horasTrabajadasStr);
	empleado->sueldo=atoi(sueldo);

	return empleado;
}
int employee_setId(Employee* this,int id)
{
	int retorno;
	retorno=-1;

	if(this!=NULL)
	{
	this->id=id;
	retorno=0;
	}

	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=-1;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno=-1;

	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno=-1;
	if(this!=NULL)
	{
	this->sueldo=sueldo;
	retorno=0;
	}
	return retorno;
}

int employee_CompareByName(void* empleadoUno, void* empleadoDos)
{
	Employee* empleadoA;
	empleadoA=employee_new();
	Employee* empleadoB;
	empleadoB=employee_new();
	int retorno;

	empleadoA=(Employee*)empleadoUno;
	empleadoB=(Employee*)empleadoDos;
	retorno=strcmp(empleadoA->nombre,empleadoB->nombre);

	return retorno;
}

int employee_CompareById(void* empleadoUno, void* empleadoDos)
{
	Employee* empleadoA;
	empleadoA=employee_new();
	Employee* empleadoB;
	empleadoB=employee_new();

	empleadoA=(Employee*) empleadoUno;
	empleadoB=(Employee*) empleadoDos;
	int comparacion;

	comparacion=0;
	if(empleadoA->id>empleadoB->id)
	{
		comparacion=1;
	}else
	{
		comparacion=-1;
	}
	return comparacion;
}

int employee_CompareBySueldo(void* empleadoUno, void* empleadoDos)
{
	Employee* empleadoA;
	empleadoA=employee_new();
	Employee* empleadoB;
	empleadoB=employee_new();

	empleadoA=(Employee*) empleadoUno;
	empleadoB=(Employee*) empleadoDos;
	int comparacion;
	comparacion=0;
	if(empleadoA->sueldo>empleadoB->sueldo)
	{
		comparacion=1;
	}else
	{
		comparacion=-1;
	}
	return comparacion;
}

int employee_CompareByHoras(void* empleadoUno, void* empleadoDos)
{
	Employee* empleadoA;
	empleadoA=employee_new();
	Employee* empleadoB;
	empleadoB=employee_new();

	empleadoA=(Employee*) empleadoUno;
	empleadoB=(Employee*) empleadoDos;
	int comparacion;
	comparacion=0;
	if(empleadoA->horasTrabajadas>empleadoB->horasTrabajadas)
	{
		comparacion=1;
	}else
	{
		comparacion=-1;
	}
	return comparacion;
}
int menu_MayorOMenor()
{
	int opcion;
	int mayOmen;

	printf("\n1-Ordenar por menor\n""2-Ordenar por mayor\n");
	opcion=CargarEnteroConMaxYMin("\nIngrese la opcion deseada", "\nIngrese nuevamente la opcion deseada", 1, 2);
	switch(opcion)
	{
	case 1:
		mayOmen=1;
		break;
	case 2:
		mayOmen=0;
		break;
	}
	return mayOmen;
}


