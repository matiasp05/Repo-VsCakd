/*
Reservar memoria para almacenar una palabra ingresada por el usuario, es
leída en una cadena auxiliar, luego copiada a memoria dinámica, recordando
que se requiere adicionar un carácter de n de cadena '\n'.
Ejemplo:
"hola mundo" + '\0' -> requiere espacio para 11 caracteres.
char* cadena_aux = "hola mundo";
char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 100

int main(void){
    char cadena_aux[MAX_TEXTO];
    char *cadena;

    printf("Ingrese cadena: ");
    fgets(cadena_aux, MAX_TEXTO, stdin);
    //Eliminar salto de linea sie sta presente.
    size_t largo = strlen(cadena_aux);
    if(largo>0 && cadena_aux[largo - 1] == '\n'){
        cadena_aux[largo-1] = '\0';
    }

    cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
    if(cadena==NULL){
        printf("No es posible reservar el espacio en memoria.\n");
    }else{
        printf("Espacio en memoria reservado exitosamente.\n");
        strcpy(cadena, cadena_aux);
        printf("La cadena copiada es: %s", cadena);
    }
    return 0;
}