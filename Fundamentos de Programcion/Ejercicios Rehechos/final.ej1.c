#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char titulo[30];
    int stock;
    int stock_min;
    float precio;
}Libro;

typedef struct{
    int codigo;
    char titulo[30];
    int libros_ofertar;
    float precio;
}Ofertas;

void generar_tabla(Ofertas oferta[100], int *ml){
    FILE *archivo = fopen("Stock.dat", "rb");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo.\n");
    }else{
        *ml=0;
        Libro libros[100];
        while(fread(&libros[*ml], sizeof(Libro), 1, archivo) == 1){
            (*ml)++;
        }

        if((*ml)==0){
            printf("No se encontraron registros en el archivo.\n");
        }else{
            printf("Se encontraron %i registros en el archivo.\n", *ml);
            int i, j=0;
            for(i=0;i<*ml;i++){
                if(libros[i].stock > libros[i].stock_min*2){
                    oferta[j].codigo = libros[i].codigo;
                    strcpy(oferta[j].titulo, libros[i].titulo);
                    oferta[j].libros_ofertar = (libros[i].stock - libros[i].stock_min)/2;
                    oferta[j].precio = (libros[i].precio/30) * 100;
                    j++;
                }
            }
        }
        fclose(archivo);
    }
}

void ordenar_tabla(Ofertas oferta[100], int ml){
    int i, j;
    Ofertas aux;

    for(i=0;i<ml;i++){
        for(j=0;j<ml-i;j++){
            if(strcmp(oferta[j].titulo, oferta[j+1].titulo) > 0){
                aux = oferta[j];
                oferta[j] = oferta[j+1];
                oferta[j+1] = aux;
            } 
        }
    }

}