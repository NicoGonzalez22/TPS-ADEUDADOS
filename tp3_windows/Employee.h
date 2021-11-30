#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"
#include "biblotecaMia.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);

int employee_setId(Employee* this,int id);
int employee_setNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
void employee_delete(Employee* this);
int employee_getId(Employee* this,int* id);
int employee_getNombre(Employee* this,char* nombre);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getSueldo(Employee* this,int* sueldo);



/*----------------+AGREGADAS POR MI+-------------------------*/
int employee_CompareByName(void* empleadoUno, void* empleadoDos);
int employee_CompareById(void* empleadoUno, void* empleadoDos);
int employee_CompareBySueldo(void* empleadoUno, void* empleadoDos);
int employee_CompareByHoras(void* empleadoUno, void* empleadoDos);

int menu_MayorOMenor();
#endif // employee_H_INCLUDED
