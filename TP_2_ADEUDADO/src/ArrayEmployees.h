#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "BiblioGeneral.h"
#define EMPLEADOSmax 1000
#define CARGADO 1
#define VACIO 0

typedef struct
{
	int id;
	char name[TamName];
	char lastName[TamName];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/// @fn void CargarEmpleado(Employee[])
/// @brief Utiliza las funciones:
/// CargarNombreOApellido: para ingresar el nombre y apellido
/// CargarFlotante: para ingresar el salario
/// CargarEntero:Para ingresar el sector
/// addEmployee: Para asigar los datos pedidos en la primera posicion libre
/// @param empleados Estructura del empleado
void CargarEmpleado(Employee empleados[],int len,int id);

/// @fn int initEmployees(Employee[], int)
/// @brief  Inicializa en VACIO todas las posiciones del array de la estructura
/// empleados
///
/// @param empleados Estructura del empleado
/// @param len Cantidad maxima de empleados
/// @return Devuelve 0 si salio todo bien o -1 si hubo un error
int initEmployees(Employee empleados[],int len);

/// @fn int addEmployee(Employee[], int, int, char[], char[], float, int)
/// @brief Asigna los datos recibidos en los parametros en la primer posicion
/// libre (VACIO) en el array
///
/// @param empleados Estructura de empleados
/// @param len Cantidad maxima de empleados
/// @param id Punto de incio para buscar la posicion libre
/// @param name Nombre Del empleado
/// @param lastName Apellido del empleado
/// @param salary Salario del empleado
/// @param sector Sector del empleado
/// @return devuelve -1 si algun parametro esta vacio o 0 si salio todo bien
int addEmployee(Employee empleados[],int len,int id,char name[],char lastName[],float salary,int sector);

/// @fn int findEmployeeById(Employee[], int, int)
/// @brief Busca un empleado recibiendo como parametro su id
///
/// @param empleados Estructura de empleados
/// @param len Cantidad maxima de empleados
/// @param id id del empleado a buscar
/// @return 0 si se pudo encontrar el empleado o -1 si algun parametro esta vacio o no encontro el empleado
int findEmployeeById(Employee empleados[],int len,int id);

/// @fn int removeEmployee(Employee[], int, int)
/// @brief Recibe como parametro el id a borrar primero busca el empleado en el array
/// y luego la posicion en la que se encuentra
///
/// @param empleados Estructura de empleados
/// @param len Cantidad maxima de empleados
/// @param id id a borrar
/// @return devuelve 0 si se borro efectivamente o -1 si algun parametro esta vacio o hubo algun error
int removeEmployee(Employee empleados[],int len, int id);

/// @fn int sortEmployees(Employee[], int, int)
/// @brief Ordena los empleados segun el parametro order (1 ascendente- 0 descendente) y los ordena descendiente
/// o ascendiente segun el sector de cada empleado
/// Modifica las posiciones de un array auxiliar de empleados
/// Utiliza la funcion printEmployees para mostrar los empleados ordenados en columna
/// @param empleados Estructura de empleados
/// @param len Cantidad maxima de empleados
/// @param order modalidad de ordenamiento (1 ascendente- 0 descendente)
/// @return
int sortEmployees(Employee empleados[],int len,int order);

/// @fn int printEmployees(Employee[], int)
/// @brief Recibe como parametro la estructura Auxiliar de empleados para imprimirlos en columna
/// valida que la posicion en la que se encuentra el empleado este Cargada, de lo contrario no imprime
/// @param empleadosAux Estructura auxiliar de empleados
/// @param length Cantidad maxima de empleados
/// @return
int printEmployees(Employee empleadosAux[],int length);

/// @fn void ModificarEmpleado(Employee[], int)
/// @brief Recibe como parametro el id del empleado a modificar
/// Utiliza las funciones:
/// Pedir String: para modificar el nombre o apellido del empleado
/// Cargar flotante: para modificar el salario del empleado
/// Cargar entero: para modificar el sector del empleado
/// @param empleados Estructura de empleados
/// @param id id del empleado a modificar
void ModificarEmpleado(Employee empleados[]);


/// @fn void CalcularPromedioYTotal(Employee[], int)
/// @brief Recorre el array de empleados solo tomando en cuenta los empleados cargados.
/// Guarda el salario de cada uno de ellos y la cantidad de los que tomo el salario y con eso
/// calcula el salario y cuantos superaron el promedio de salarios
/// Cuando termina todas las cuentras imprime los datos obtenidos
/// @param empleados Estructura de empleados
/// @param len Cantidad maxima de empleados
void CalcularPromedioYTotal(Employee empleados[],int len);

/// @fn void InformarEmpleados(Employee[])
/// @brief Muestra el menu de opciones.
/// la opcion 1 te muestra la lista de empleados ordenados, dependiendo el orden elegido (ascendiente o descendiente)
/// y la opcion 2 te muestra los datos obtenidos con la funcion CalcularPromedioTotal
///
/// @param empleados
void InformarEmpleados(Employee empleados[]);

/// @fn int BuscarPrimerEspacioVacio(Employee[], int)
/// @brief Utiliza un for para buscar el primer espacio libre para asignar a un empleado
///
/// @param empleados Estructura empleados
/// @param len Cantidad maxima de empleados
/// @return Devuelve -1 si no pudo encontrar un espacio libre o devuelve el index para asignar al empleado
int BuscarPrimerEspacioVacio(Employee empleados[],int len);

/// @fn void OrdenarDescendiente(Employee[], int, int, int)
/// @brief Sweapea las estructuras de la pos 1 o pos 2 segun sus valores, lo ordena descendientemente
///
/// @param empleados Estructura de empleados
/// @param posUno Posicion Uno
/// @param posDos Posicicion siguiente a la posicion uno
/// @param len Cantidad maxima de empelados
void OrdenarDescendiente(Employee empleados[],int posUno,int posDos,int len);

/// @fn void OrdenarDescendiente(Employee[], int, int, int)
/// @brief Sweapea las estructuras de la pos 1 o pos 2 segun sus valores, lo ordena ascendientemente
///
/// @param empleados Estructura de empleados
/// @param posUno Posicion Uno
/// @param posDos Posicicion siguiente a la posicion uno
/// @param len Cantidad maxima de empelados
void OrdenarAscendiente(Employee empleados[],int posUno,int posDos,int len);

#endif /* ARRAYEMPLOYEES_H_ */
