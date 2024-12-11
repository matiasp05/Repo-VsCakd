#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MF 20

typedef int Vector[MF];

int suma_vector(Vector vec, int ml){
    if((ml-1) < 0){
        return 0;
    }

    if((ml-1)%2 == 0){
        return vec[(ml-1)] + suma_vector(vec, ml-1);
    }else{
        return suma_vector(vec, ml-1);
    }
}