/*
Escribir un programa el cual reserve memoria dinámica para almacenar un
número entero (int), le solicite al usuario el ingreso de un número y se asigna
dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla
Liberar la memoria reservada al nalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr = NULL;

    ptr = malloc(sizeof(int));

    if(ptr != NULL){
        printf("Espacio en memoria reservado exitosamente.\n");
        printf("Ingrese un numero entero: ");
        scanf("%i", &ptr);
        free(ptr);
    }

    return 0;
}