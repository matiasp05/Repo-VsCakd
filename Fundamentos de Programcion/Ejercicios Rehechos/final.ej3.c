/*
Desarrollar una función recursiva en lenguaje C que reciba un arreglo y su máximo lógico,
 y devuelva la suma de los elementos que están en las posiciones pares del arreglo.
*/
#define MF 20
typedef int t_vec[MF];

int suma_vector(t_vec vector, int ml){
   if(ml-1<0){
    return 0;
   }

   if(ml-1%2==0){
    return vector[ml-1] + suma_vector(vector, ml-1);
   }else{
    return suma_vector(vector, ml-1);
   }
}

int main(void){
    t_vec vector = {2, 3, 1, 4, 7, 2};
    int ml = 6;

    int suma = suma_vector(vector, ml);

    printf("La suma da: %i", suma);
    return 0;
}