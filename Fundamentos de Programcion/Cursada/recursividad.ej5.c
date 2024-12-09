/*
Desarrollar una función recursiva para obtener en mayor valor en un vector
de números enteros.
*/

#include <stdio.h>

int mayor_valor(int vector[], int tamanio){
    
    if(tamanio == 1){
        return vector[0];
    }    
    if(vector[0] > vector[tamanio-1]) {
        return mayor_valor(vector, tamanio-1);
    } else {
        return vector[tamanio-1];
    }
}

int main(void) {
    int vector[] = {3, 5, 7, 2, 8, 1, 9, 4};
    int n = sizeof(vector) / sizeof(vector[0]);

    int maximo = mayor_valor(vector, n);

    printf("El valor máximo en el vector es: %d\n", maximo);

    return 0;
}