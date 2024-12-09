/*
) Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y lo muestre invertido. No se puede utilizar vectores.
*/

#include <stdio.h>

void invertir_numero(int numero, int *invertido){
    if(numero == 0){
        return;
    }

    int digito = numero % 10; //agarro el ultimo numero.
    *invertido = *invertido *10 + digito;
    invertir_numero(numero/10, invertido);
}

int main(void){
    int numero, invertido = 0;
    printf("Ingrese numero entero para invertir: ");
    scanf("%i", &numero);

    invertir_numero(numero, &invertido);

    printf("Numero invertido: %i\n ", invertido);
    return 0;
}