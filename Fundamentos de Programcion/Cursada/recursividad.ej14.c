#include <stdio.h>

// Función recursiva para imprimir una línea del rectángulo
void imprimir_linea(int base) {
    // Caso base: si base es 0, no imprimir nada
    if (base <= 0) {
        return;
    }

    // Imprimir un carácter '*' para representar un píxel del rectángulo
    printf("*");

    // Llamada recursiva para imprimir el siguiente carácter
    imprimir_linea(base - 1);
}

// Función recursiva para imprimir el rectángulo
void imprimir_rectangulo(int base, int altura) {
    // Caso base: si altura es 0, terminar la impresión
    if (altura <= 0) {
        return;
    }

    // Imprimir una línea del rectángulo
    imprimir_linea(base);

    // Imprimir un salto de línea después de una línea completa
    printf("\n");

    // Llamada recursiva para imprimir las siguientes líneas
    imprimir_rectangulo(base, altura - 1);
}

int main(void) {
    int base, altura;

    // Solicitar al usuario los valores de base y altura
    printf("Ingrese la base del rectángulo: ");
    scanf("%d", &base);
    printf("Ingrese la altura del rectángulo: ");
    scanf("%d", &altura);

    // Imprimir el rectángulo
    printf("Rectángulo:\n");
    imprimir_rectangulo(base, altura);

    return 0;
}