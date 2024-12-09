/*
Escribir un programa el cual reserve memoria dinámica para almacenar una
cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por
el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y
almacenarlos en la memoria previamente reservada. Mostrar luego todos los
valores ingresados. Liberar la memoria reservada al nalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_num(int *ptr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("Ingrese el numero %i: ", i+1);
        scanf("%i", &ptr[i]);
    }
}

void mostrar_num(int *ptr, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%i\t", ptr[i]);
    }
}

int main(void){
    int *ptr;
    int n;

    printf("Ingrese cuantos enteros desea ingresar: ");
    scanf("%i", &n);

    ptr = malloc(n * sizeof(int));

    if(ptr != NULL){
        printf("Espacio en memoria reservado correctamente.\n");

        ingresar_num(ptr, n);

        mostrar_num(ptr, n);

        free(ptr);
    }else{
        printf("No se ha podido reservar el espacio.\n");
    }
    return 0;
}