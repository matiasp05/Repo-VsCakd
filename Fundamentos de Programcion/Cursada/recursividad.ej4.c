/*
Desarrollar un programa que calcule y muestre por pantalla la división de 2
números mediante restas sucesivas en forma recursiva. Ambos números deben
ser ingresados por el usuario
*/
#include <stdio.h>

int restas_sucesivas(int dividendo, int divisor){
    if(divisor>dividendo){
        return 0;
    } else {
        return 1 + restas_sucesivas(dividendo - divisor, divisor);
    }
}

int main(void){
    int dividendo, divisor;

    printf("Ingrese dividendo: ");
    scanf("%i", &dividendo);

    printf("Ingrese divisor: ");
    scanf("%i", &divisor);    

    int resultado = restas_sucesivas(dividendo, divisor);

    printf("El resultado de %i dividido por %i es: %i\n", dividendo, divisor, resultado);
    return 0;
}