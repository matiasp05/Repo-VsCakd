/*
 Desarrollar una función recursiva que imprima por pantalla un rectángulo a
partir de los valores de la base y la altura ingresados por teclado
*/

#include <stdio.h>

void imprimir_fila(int base){
    if(base==0){ //caso base.
        return;
    }
    printf("*");
    imprimir_fila(base-1); //llama recursivamente para terminar la fila
}

void imprimir_columna(int base, int altura){
    if(altura == 0){ //caso base
        return;
    }
    imprimir_fila(base); //llama para imprimir la fila
    printf("\n");
    imprimir_columna(base, altura-1); //llama recursivamente para imprimir una nueva fila
}

int main(void){
    int base, altura;

    printf("Ingrese base: ");
    scanf("%i", &base);

    printf("Ingrese altura: ");
    scanf("%i", &altura);

    imprimir_columna(base, altura);

    return 0;
}