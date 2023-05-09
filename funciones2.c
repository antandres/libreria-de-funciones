
#include <stdio.h>

struct trabajador
{
    int cedula;
    char nombre[50];
    int departamento;
    int cargo;
    float sueldo;
    char f_ingreso[10];
};

//Función para mostrar por pantalla datos de un trabajador dado un registro con datos particulares
void escribirtrabajador(struct trabajador registro)
{
    printf("\nNombre: %s\n", registro.nombre);
    printf("Fecha de ingreso: %s\n", registro.f_ingreso);
    printf("C%cdula de identidad: %d\n", 130, registro.cedula);
    printf("Departamento: %d\n", registro.departamento);
    printf("Cargo: %d\n", registro.cargo);
    printf("Sueldo: %f\n\n", registro.sueldo);
}

//Función para revisar cual sueldo es menor en un vector de registros con datos de trabajadores
int menorsueldo(struct trabajador registro[], int dim)
{
    int i;
    float menor = registro[0].sueldo;
    int pos = 0; //Asume que el puesto 0 contiene el menor sueldo para hacer comparativas con los siguientes
    for (i = 1; i < dim; i++)
    {
        if(menor > registro[i].sueldo) //Si encuentra uno menor, se actualiza la posición y el menor sueldo
        {
            menor = registro[i].sueldo;
            pos = i;
        }
    } //Al final del ciclo, habrá recorrido todo el vector y comparado todos los sueldos
    return pos; //Finalmente, regresa como dato la posición del menor sueldo
}

//Función para revisar cual sueldo es mayor en un vector de registros con datos de trabajadores
int mayorsueldo(struct trabajador registro[], int dim)
{ //No hace falta explicar, funciona igual que la función menorsueldo pero encuentra el mayor de los sueldos
    int i;
    float mayor = registro[0].sueldo;
    int pos = 0;
    for (i = 1; i < dim; i++)
    {
        if(mayor < registro[i].sueldo)
        {
            mayor = registro[i].sueldo;
            pos = i;
        }
    }
    return pos;
}