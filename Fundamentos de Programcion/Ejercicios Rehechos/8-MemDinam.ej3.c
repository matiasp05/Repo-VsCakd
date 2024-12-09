/*
Asumiendo que ya existe un puntero que apuntan a un bloque de memoria
previamente reservada con malloc de tamaño (n * int), redimensionar dicha
memoria a un tamaño de (2 * n *int)
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
    printf("\n");
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
        
        ptr= realloc(ptr, 2 * n * sizeof(int));
        if(ptr != NULL){
            int i;
            for(i = n;i< n*2;i++){
                printf("Ingrese el numero %i: ", i+1);
                scanf("%i", &ptr[i]);
            }
            mostrar_num(ptr, n*2);
        }
        free(ptr);
    }else{
        printf("No se ha podido reservar el espacio.\n");
    }
    return 0;
}