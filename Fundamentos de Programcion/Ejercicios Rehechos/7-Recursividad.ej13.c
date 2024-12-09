/*
 Desarrollar una función recursiva que compruebe si un número es binario.
Un número binario está formado únicamente por ceros y unos
*/

#include <stdio.h>
#include <stdbool.h>

bool num_bin(int num){
    if(num == 1 || num == 0){
        return true;
    } 

    if(num%10 != 0 && num%10 != 1){
        return false;
    }

    return num_bin(num/10);
}

int main(void){
    int num;

    printf("Ingrese el numero binario: ");
    scanf("%i", &num);

    if(num_bin(num) == true){
        printf("El numero es binario.\n");
    }else{
        printf("El numero no es binario.\n");
    }
    return 0;
}