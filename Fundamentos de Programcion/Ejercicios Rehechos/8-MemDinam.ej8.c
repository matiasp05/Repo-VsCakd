/*
Implementar una función que retorna un puntero a un vector de n valores de
tipo int, todos inicializados en cero, el cual apunta a un bloque de memoria
dinámica, respetando la siguiente declaración. En caso de no poder reservar la
memoria, retornar NULL.
*/

#include <stdio.h>
#include <stdlib.h>

int* crear_vector_inicializado(int n){
    int *vector = calloc(n, sizeof(int));

    if(vector==NULL){
        return NULL;
    } 
    return vector;
}

int main(void){
    int i, n;

    printf("Ingresar la cant de numeros a inicializar: ");
    scanf("%i", &n);

    int* vector = crear_vector_inicializado(n);

    if(vector == NULL){
        printf("No se pudo reservar el espacio en memoria.\n");
    }else{
        printf("El espacio en memoria se reservo exitosamente.\n");
        for(i=0;i<n;i++){
            printf("%i\t", vector[i]);
        }
        free(vector);
    }
    return 0;
}