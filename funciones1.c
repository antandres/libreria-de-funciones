#include <stdio.h>
struct registro
{
    //Los datos pueden ser cualquier tipo, en este caso hay un entero, un real y un caracter. Pueden ser más
    int dato1;
    float dato2;
    char dato3;
};
//Es importante haber definido el struct <nombre> antes

//Recolecta y desplazamiento de casillas
void guardarcasilla(struct registro vector[], int indice, int *dimension, int *a1, float *a2, char *a3)
{
    /* vector es el vector a considerar, indice es el puesto donde se tomarán los valores, *dimension es la
    dirección de la variable dimension, que es lo que su nombre indica; *a# son las direcciones de las
    variables donde se almacenarán los datos que se tomen del registro. Por cada dato a tomar se requiere
    un nuevo *a# */

    //Toma de datos y asignación en sus variables
    *a1 = vector[indice].dato1;
    *a2 = vector[indice].dato2;
    *a3 = vector[indice].dato3;

    //Se mueven los datos posteriores un espacio hacia atrás
    int i;
    for(i=indice; i<*dimension; i++)
   {
        vector[i].dato1 = vector[i+1].dato1;
        vector[i].dato2 = vector[i+1].dato2;
        vector[i].dato3 = vector[i+1].dato3;
   }

   //Se nulifican los valores en el último puesto. Puede ponerse lo que haga falta
   vector[*dimension].dato1 = 0;
   vector[*dimension].dato2 = 0;
   vector[*dimension].dato3 = ' ';

   //Reducción de la dimensión por uno
   *dimension = *dimension - 1;
}

/* A la hora de llamar el procedimiento, es importante añadir el & en las variables que pasan por referencia
(no incluyendo al vector), por ejemplo:
guardarcasilla(vector, 5, &dimension, &a1, &a2, &a3); */


//Verificación de fecha de nacimiento (Año en consideración: 2023)
void verificacionfecha(int *dd, int *mm, int *yy)
{
    int year, mes, dia;
    do
    {
    printf("Ingrese su a%co de nacimiento (1902 a 2023)\n", 164);
    scanf("%d", &year);
    } while(year < 1901 || year > 2023);    //Verificación de año
    do
    {
        printf("Ingrese su mes de nacimiento (1 a 12)\n");
        scanf("%d", &mes);
    } while(mes < 1 || mes > 12);    //Verificación de mes
    if((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12))
    {
        do
        {
            printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 31)\n", 161);
            scanf("%d", &dia);
        } while(dia < 1 || dia > 31);   //Verificación de día para meses de 31 días
    }
    else
    {
        if((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11))
        {
            do
            {
                printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 30)\n", 161);
                scanf("%d", &dia);
            } while(dia < 1 || dia > 30);   //Verificación de día para meses de 30 días
        }
        else
        {
            if((mes == 2)&&(year % 4 == 0))
            {
            do
            {
                printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 29)\n", 161);
                scanf("%d", &dia);
            } while(dia < 1 || dia > 29);   //Verificación de día para febrero en años bisiestos
            }
            else
            {
                do
                {
                    printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 28)\n", 161);
                    scanf("%d", &dia);
                } while(dia < 1 || dia > 28);   //Verificación de día para febrero en años no bisiestos
            }
        }
    }

    //Transferencia de las fechas a las variables auxiliares
    *dd = dia;
    *mm = mes;
    *yy = year;
}

/* A la hora de llamar este procedimiento, se debe colocar un & en las variables que pasan por referencia,
por ejemplo:
verificacionfecha(&d, &m, &a); */