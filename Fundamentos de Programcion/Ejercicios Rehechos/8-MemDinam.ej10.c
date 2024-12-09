/*
 Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
ingresadas por el usuario. Crear una estructura de datos dinámica de dos
dimensiones que permita almacenar esta información. Mostrar toda la
información de la estructura luego de haber sido cargada. Liberar toda la
memoria al nalizar el programa.
typedef char* t_palabra;
typedef t_palabra* t_vec;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARAC 100

typedef char* t_palabra;
typedef t_palabra* t_vec;

void leer_palabras(t_palabra *palabras, int n){
    int i;
    char temp[MAX_CARAC];

    for(i=0;i<n;i++){
        printf("Ingrese la palabra %i: ",i+1);
        fgets(temp, MAX_CARAC, stdin);

        //eliminar el salto de linea si es que esta
        size_t largo = strlen(temp);
        if(temp[largo-1] == '\n'){
            temp[largo-1] = '\0';
        }

        palabras[i] = malloc(largo * sizeof(char) + 1);
        if(palabras[i] == NULL){
            printf("No se ha podido reservar el espacio en memoria.\n");
        }else{
            printf("Espacio en memoria %i reservado exitosamente.\n", i+1);
            strcpy(palabras[i], temp);
        }
    }
}

int main(void){
    int n;
    
    t_palabra *palabras;

    printf("Ingrese la cantidad de palabras: ");
    scanf("%i", &n);
    getchar();

    leer_palabras(palabras, n);

    int i;
    for(i=0;i<n;i++){
        printf("Palabra %i: %s\n", i+1, palabras[i]);
        printf("\n");
        
        if(palabras[i]!= NULL){
            free(palabras[i]);
        }
    }
    return 0;
}