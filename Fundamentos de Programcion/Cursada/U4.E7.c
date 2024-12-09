/*
Dado un vector a de longitud n y un elemento p del mismo tipo que los elementos del vector, 
buscar p en el vector a y devolver la posicion que ocupa en el caso de encnontrarlo o una señal en caso contrario. 
Suponer que no hay repeticiones.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void leer_vector(int n, int v[]){
  for(int i=0; i<n; i++){
    printf("Ingrese el elemento %i del vector: ", i + 1);
    scanf("%d", &v[i]);
  }
  
}
int buscar_elemento(int n, int v[], int p){
  for(int i=0; i<n; i++){
    if(v[i] == p){
      return i;
    }
  return -1;
}


int main(){
    int n;

    printf("Ingresar la longitud del vector: ");
    scanf("%d", &n);
    if (n > MAX){
        printf("Longitud demasiado grande. Maximo permitido: %i.\n", MAX);
        return 1;
    }
    int v[MAX];
    leer_vector(n, v);
    int p;
    printf("Ingresar el elemento a buscar: ");
    scanf("%d", &p);
    
    int posicion = buscar_elemento(n, v, p);
    if (posicion == -1){
        printf("El elemento no fue encontrado. \n");
    } else {
        printf("La posicion del elemento es: %d.\n", posicion + 1);
    }
    return 0;
}