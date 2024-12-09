/*
Se tienen los siguientes datos de los empleados de una empresa:
Apellido y Nombre (35 caracteres)
Fecha de Nacimiento (día, mes y año)
Fecha de Ingreso (día, mes y año)
Sueldo Básico
Se conoce la cantidad N de empleados y la fecha de procesamiento.
Se pide: Imprimir un listado con los apellidos y nombres de las personas
que cumplan años en el mes y calcular e informar una suma de regalo
equivalente al uno por mil del sueldo por cada año cumplido. 
*/

#include <stdio.h>
#define MAX_EMPLEADOS 100

typedef struct{
    char nombre[35];
    int dia_nacimiento;
    int mes_nacimiento;
    int anio_nacimiento;
    int dia_ingreso;
    int mes_ingreso;
    int anio_ingreso;
    float sueldo;
} Empleado;

// Función para imprimir los empleados que cumplen años en el mes actual y calcular su regalo
void procesar_empleados(Empleado empleados[], int n, int mes_actual, int anio_actual){
    int i;
    printf("Empleados que cumplen años en el mes %i: \n", mes_actual);
    for(i=0; i<n; i++){
        if (empleados[i].mes_nacimiento == mes_actual) {
            // Calcular los años cumplidos
            int anios_cumplidos = anio_actual - empleados[i].anio_nacimiento;
            // Calcular el regalo (1 por mil del sueldo por cada año cumplido)
            float regalo = (empleados[i].sueldo * anios_cumplidos) / 1000;

            printf("%s: %i anios. Regalo que le corresponde: %.2f.\n", empleados[i].nombre, anios_cumplidos, regalo);
        }
    }
}

int main(void){
    Empleado empleados[MAX_EMPLEADOS];
    int n, mes_actual, anio_actual;

    printf("Cantidad de empleados: ");
    scanf("%i", &n);

    for(int i=0; i<n; i++){
        printf("Empleado %i: \n", i+1);
        printf("Nombre:\n");
        scanf("%s",empleados[i].nombre);
        
        printf("Fecha de nacimiento(dd mm aaaa):\n");
        scanf("%i %i %i", &empleados[i].dia_nacimiento, &empleados[i].mes_nacimiento, &empleados[i].anio_nacimiento);
        
        printf("Fecha de ingreso(dd mm aaaa):\n");
        scanf("%i %i %i", &empleados[i].dia_ingreso, &empleados[i].mes_ingreso, &empleados[i].anio_ingreso);
        
        printf("Sueldo basico:\n");
        scanf("%f", &empleados[i].sueldo);
    }

    printf("Ingrese el mes actual: ");
    scanf("%i", &mes_actual);
    printf("Ingrese el anio actual: ");
    scanf("%i", &anio_actual);

    procesar_empleados(empleados, n, mes_actual, anio_actual);
    return 0;
}