#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char titulo[30];
    int stock_act;
    int stock_min;
    float precio;
} Libro;

typedef struct{
    int codigo;
    char titulo[30];
    int cant_libros;
    float precio;
} Oferta;

void generar_tabla(Oferta ofertas[], int *ml){
    FILE *archivo = fopen("Stock.dat", "rb");
    if(archivo==NULL){
        printf("No se puede abrir el archivo.\n");
    }else{
        int i = 0;
        Libro libros[100];
        while(fread(&libros[i], sizeof(Libro), 1, archivo) == 1){
            i++;
        }
        if(i>0){
            printf("Se encontraron %i registros en el archivo.\n", i+1);
            int j;
            *ml=0;
            for(j=0;j<(*ml);j++){
                if(libros[j].stock_act > libros[j].stock_min * 2){
                    ofertas[*ml].codigo = libros[j].codigo;
                    strcpy(ofertas[*ml].titulo, libros[j].titulo);
                    ofertas[*ml].cant_libros = (libros[j].stock_act - libros[j].stock_min) / 2;
                    ofertas[*ml].precio = (libros[j].precio * 70) / 100;
                    (*ml)++;
                }
            }
        }else{
            printf("No se encontraron registros en el archivo.\n");
        }
        fclose(archivo);
    }
}

void ordenar_tabla(Oferta ofertas[], int ml){
    int i, j;
    Oferta aux;
    for(i=0;i<ml;i++){
        for(j=0;j<ml-i;j++){
            if(strcmp(ofertas[j].titulo, ofertas[j+1].titulo) > 0){
                aux = ofertas[j];
                ofertas[j] = ofertas[j+1];
                ofertas[j+1] = aux;
            }
        }
    }
}