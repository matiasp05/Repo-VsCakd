/*
 Se tienen datos de empleados de una empresa según la siguiente
estructura:
Apellido, Nombre.
Legajo
Dirección: Calle, N°, Localidad, Provincia, Código Postal.
Fecha de Nacimiento: Día, Mes, Año.
Fecha de Ingreso: Día, Mes, Año.
Se pide hacer un programa que almacene los datos de todos los
empleados en una tabla en memoria y que permita obtener un listado
ordenado por pantalla según distintos ítems, como, por ejemplo, por
Apellido y Nombre, por número de legajo, por edad, por antigüedad, por
localidad.
Utilizar un esquema tipo menú. 
*/

#include <stdio.h>
#include <string.h>
#define MAX_EMPLEADOS 50

typedef struct{
    char calle[50];
    int numero;
    char localidad[30];
    char provincia[50];
    int codigo_postal;
} Direccion;

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct{
    char apellido[30];
    char nombre[20];
    int legajo;
    Direccion direccion;
    Fecha fecha_nacimiento;
    Fecha fecha_ingreso;
} Empleado;

void leer_empleados(Empleado empleados[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Empleado %i.\n", i + 1);

        printf("Ingrese Apellido: ");
        fgets(empleados[i].apellido, 30, stdin);
        

        printf("Ingrese Nombre: ");
        fgets(empleados[i].nombre, 20, stdin);
        

        printf("Ingrese numero de legajo: ");
        scanf("%i", &empleados[i].legajo);
        getchar();

        printf("Ingrese:\n");

        printf("Direccion - Calle: ");
        fgets(empleados[i].direccion.calle, 50, stdin);
        

        printf("Direccion - Numero: ");
        scanf("%i", &empleados[i].direccion.numero);
        getchar();

        printf("Direccion - Localidad: ");
        fgets(empleados[i].direccion.localidad, 30, stdin);
        

        printf("Direccion - Provincia: ");
        fgets(empleados[i].direccion.provincia, 50, stdin);
        

        printf("Direccion - Codigo Postal: ");
        scanf("%i", &empleados[i].direccion.codigo_postal);
        getchar();

        printf("Fecha de nacimiento (DD MM AAAA): ");
        scanf("%i %i %i", &empleados[i].fecha_nacimiento.dia, &empleados[i].fecha_nacimiento.mes, &empleados[i].fecha_nacimiento.anio);
        getchar();

        printf("Fecha de ingreso (DD MM AAAA): ");
        scanf("%i %i %i", &empleados[i].fecha_ingreso.dia, &empleados[i].fecha_ingreso.mes, &empleados[i].fecha_ingreso.anio);
        getchar();

        }
}


void mostrar_empleados(Empleado empleados[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("Apellido y nombre: %s, %s\n", empleados[i].apellido, empleados[i].nombre);
        printf("Legajo: %i\n", empleados[i].legajo);
        printf("Direccion: %s, %i, %s, %s, %i.\n", empleados[i].direccion.calle, empleados[i].direccion.numero, empleados[i].direccion.localidad, empleados[i].direccion.provincia, empleados[i].direccion.codigo_postal);
        printf("Fecha de nacimiento: %i/%i/%i.\n", empleados[i].fecha_nacimiento.dia, empleados[i].fecha_nacimiento.mes, empleados[i].fecha_nacimiento.anio);
        printf("Fecha de ingreso: %i/%i/%i.\n\n", empleados[i].fecha_ingreso.dia, empleados[i].fecha_ingreso.mes, empleados[i].fecha_ingreso.anio);
    }
}

void ordenar_por_apellido_nombre(Empleado empleados[], int n) {
    Empleado temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(empleados[j].apellido, empleados[j + 1].apellido) > 0 || 
               (strcmp(empleados[j].apellido, empleados[j + 1].apellido) == 0 && strcmp(empleados[j].nombre, empleados[j + 1].nombre) > 0)) {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }
}

void ordenar_por_legajo(Empleado empleados[], int n){
    Empleado temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (empleados[j].legajo > empleados[j + 1].legajo) {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }
}

int calcular_edad(Fecha fecha_nacimiento, Fecha fecha_actual){
    int edad = fecha_actual.anio - fecha_nacimiento.anio;
    if (fecha_actual.mes < fecha_nacimiento.mes || 
        (fecha_actual.mes == fecha_nacimiento.mes && fecha_actual.dia < fecha_nacimiento.dia)) {
        edad--;
    }
    return edad;
}

void ordenar_por_edad(Empleado empleados[], int n, Fecha fecha_actual){
    Empleado temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int edad1 = calcular_edad(empleados[j].fecha_nacimiento, fecha_actual);
            int edad2 = calcular_edad(empleados[j+1].fecha_nacimiento, fecha_actual);
            if (edad1 > edad2) {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }
}
int calcular_antiguedad(Fecha fecha_ingreso, Fecha fecha_actual) {
    int antiguedad = fecha_actual.anio - fecha_ingreso.anio;
    if (fecha_actual.mes < fecha_ingreso.mes || 
        (fecha_actual.mes == fecha_ingreso.mes && fecha_actual.dia < fecha_ingreso.dia)) {
        antiguedad--;
    }
    return antiguedad;
}

void ordenar_por_antiguedad(Empleado empleados[], int n, Fecha fecha_actual) {
    Empleado temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int antiguedad1 = calcular_antiguedad(empleados[j].fecha_ingreso, fecha_actual);
            int antiguedad2 = calcular_antiguedad(empleados[j + 1].fecha_ingreso, fecha_actual);
            if (antiguedad1 > antiguedad2) {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }
}

void ordenar_por_localidad(Empleado empleados[], int n){
    Empleado temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(empleados[j].direccion.localidad, empleados[j + 1].direccion.localidad) > 0) {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }
}


int main(void){
    Empleado empleados[MAX_EMPLEADOS];
    Fecha fecha_actual;
    int n = 0;
    int opcion = -1;

    printf("Cantidad de empleados: ");
    scanf("%i", &n);   

    leer_empleados(empleados, n);

    while(opcion != 0){
        printf("--- Menu de Opciones. ---\n");
        printf("¿De que manera quiere ordenar a los empleados?.\n");
        printf("1. Por Apellido, Nombre.\n");
        printf("2. Por numero de legajo.\n");
        printf("3. Por edad.\n");
        printf("4. Por antiguedad.\n");
        printf("5. Por localidad.\n");
        printf("0. Salir.\n");
        printf("------------------------\n");
    }

    if(opcion == 1){
        ordenar_por_apellido_nombre(empleados, n);
        mostrar_empleados(empleados, n);
    }else if(opcion == 2){
        ordenar_por_legajo(empleados, n);
        mostrar_empleados(empleados, n);
    }else if(opcion == 3){
        printf("Ingrese la fecha actual (DD MM AAAA): ");
        scanf("%i %i %i", &fecha_actual.dia, &fecha_actual.mes, &fecha_actual.anio);
        ordenar_por_edad(empleados, n, fecha_actual);
        mostrar_empleados(empleados, n);
    }else if(opcion == 4){
        printf("Ingrese la fecha actual (DD MM AAAA): ");
        scanf("%i %i %i", &fecha_actual.dia, &fecha_actual.mes, &fecha_actual.anio);
        ordenar_por_antiguedad(empleados, n, fecha_actual);
        mostrar_empleados(empleados, n);
    }else if(opcion == 5){
        ordenar_por_localidad(empleados, n);
        mostrar_empleados(empleados, n);
    }else{
        printf("Saliendo..\n");
    }

    return 0;
}