/*
Escribir una función llamada "crear _estructura_dinamica" que reciba un arreglo unidimensional de elementos enteros ya cargado, y su respectivo máximo lógico. La función debe devolver un puntero a una estructura dinámica que contenga los elementos del arreglo recibido y utilice sólo el espacio de memora necesario.
Escribir un main que:
a. Invoque a la función utilizando como arreglo la siguiente declaración:
, int vector[100] = (48, 23, 2, 5, 187;
b. Haga una llamada a la función mostrar_estructura_dinamica a la que se le debe pasar la estructura y le correspondiente cantidad de elementos a mostrar. No tenés que desarrollar esta función, sólo utilizarla adecuadamente. Sólo se puede invocar esta función si el puntero no es nulo.
*/
#include <stdio.h>
#include <stdlib.h>

int* crear_estructura_dinamica(int vector[], int ml){
    int i;
    int *ptr=NULL;
    if(ptr!=NULL){
        for(i=0;i<ml;i++){
            ptr[i] = vector[i];
        }
    } else {
        return NULL;
    }
    return ptr;
}

int main(void){
    int vector[100]= {48, 23, 2 , 5, 187};
    int ml=5;
    int *ptr;

    ptr = crear_estructura_dinamica(vector, ml);
    if(ptr!=NULL){
        mostrar_estructura_dinamica(ptr, ml);
        free(ptr);
    }
    return 0;
}