//Dado un numero entero, mostrar la suma de sus digitos individuales
#include <stdio.h>

int suma_por_digito (int numero){

    if(numero==0)
        return 0;
    else
    return (numero%10)+suma_por_digito(numero/10);
   }

int main(){
    int numero,suma;

    printf("Ingrese su numero:");
    scanf("%d",&numero);
    
    suma=suma_por_digito(numero);

    printf("La suma de los digitos de sus numeros es: %d",suma);
    
    return 0;
}