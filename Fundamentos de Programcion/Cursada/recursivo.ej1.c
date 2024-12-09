/*
Implementar una funcion que permita dividir dos numeros enteros por restas sucesivas.
Matias Nahuel Portela. 111468.
*/

#include <stdio.h>

//Función iterativa para dividir dos números enteros por restas sucesivas
int dividir_por_restas_iterativo(int dividendo, int divisor) {
    int cociente = 0;
    while (dividendo >= divisor) {
        dividendo -= divisor;
        cociente++;
    }
    return cociente;
}

//Función recursiva para dividir dos números enteros por restas sucesivas
int dividir_por_restas_recursivo(int dividendo, int divisor) {
    if (dividendo < divisor) {
        return 0;
    }
    return 1 + dividir_por_restas_recursivo(dividendo - divisor, divisor);
}

int main(void){
    int dividendo, divisor, resultado;
    
    printf("Ingrese el dividendo: ");
    scanf("%i", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%i", &divisor);

    //Verificar que el divisor no sea cero para evitar división por cero
    if (divisor == 0) {
        printf("Error: El divisor no puede ser cero.\n");
        return 1;
    }

    resultado = dividir_por_restas_iterativo(dividendo, divisor);
    printf("El resultado iterativo de %i dividido por %i es: %i\n", dividendo, divisor, resultado);

    resultado = dividir_por_restas_recursivo(dividendo, divisor);
    printf("El resultado recursivo de %i dividido por %i es: %i\n", dividendo, divisor, resultado);
}