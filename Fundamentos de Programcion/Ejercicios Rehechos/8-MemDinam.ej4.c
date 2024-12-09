/*
Escribir un programa el cual reserve memoria dinámica para almacenar una
cantidad n de struct del tipo t_alumno (ver anexo). El usuario debe ingresar la
cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y
almacenarlos en la memoria previamente reservada. Mostrar luego todos los
datos de todos los alumnos. Liberar la memoria reservada al nalizar el
programa.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

t_alumno* crear_alumnos(int n){
    t_alumno *alumnos = NULL;
    alumnos = malloc(n * sizeof(t_alumno));

    if(alumnos == NULL){
        return NULL;
    }
    return alumnos;
}

void ingresar_datos(t_alumno *alumnos){
    printf("Ingresar el padron: ");
    scanf("%i", &alumnos->padron);

    printf("Ingresar el nombre: ");
    scanf("%s", &alumnos->nombre);

    printf("Ingresar el apellido: ");
    scanf("%s", &alumnos->apellido);
}

void imprimir_datos(t_alumno *alumnos){
    printf("Numero de padron: %i\n", alumnos->padron);
    printf("Nombre: %s\n", alumnos->nombre);
    printf("Apellido: %s\n", alumnos->apellido);
}

int main(void){
    int i, n;

    printf("Ingrese cantidad de alumnos: ");
    scanf("%i", &n);

    t_alumno* alumnos = crear_alumnos(n);
    if(alumnos==NULL){
        printf("No se ha podido reservar el espacio en memoria.\n");
    }else{
        printf("Espacio en memoria reservado exitosamente.\n");
        
        for(i=0;i<n;i++){
            printf("Ingrese datos del alumno %i.\n", i+1);
            ingresar_datos(&alumnos[i]);
        }
        for(i=0;i<n;i++){
            printf("\nDatos alumno %i.\n", i+1);
            imprimir_datos(&alumnos[i]);
        }
        free(alumnos);
    }
    return 0;
}