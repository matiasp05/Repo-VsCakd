#include <stdio.h>
#include <stdbool.h>


// Estructura
typedef struct  { 
	float real;
	float imaginaria;
} T_Complejo;


/***************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : variable de tipo COMPLEJO creado en el modulo invocante
  post: asinga los valores recibidos por parametro a T_Complejo

  real : float a asignar a la parte real del complejo que retorna
  imag : float a asignar a la parte imaginaria del complejo que retorna
*/
T_Complejo cargar(float real, float imag) {
    T_Complejo C;
    C.real = real;
    C.imaginaria = imag;
    return C;
}

/*--------------------------*/

/*
  pre : variable de tipo COMPLEJO creado en el modulo invocante
  post: retorna la parte real del complejo que retorna del numero complejo recibido 
*/
float real(T_Complejo C) {
    return C.real;
}

/*--------------------------*/

float imag(T_Complejo C) {
    return C.imaginaria;
}

T_Complejo sumar(T_Complejo A, T_Complejo B) {
    T_Complejo resultado;
    resultado.real = A.real + B.real;
    resultado.imaginaria = A.imaginaria + B.imaginaria;
    return resultado;
}

T_Complejo multiplicar(T_Complejo A, T_Complejo B) {
    T_Complejo resultado;
    resultado.real = A.real * B.real - A.imaginaria * B.imaginaria;
    resultado.imaginaria = A.real * B.imaginaria + A.imaginaria * B.real;
    return resultado;
}

bool igual(T_Complejo A, T_Complejo B) {
    return A.real == B.real && A.imaginaria == B.imaginaria;
}

// funciones auxiliares
void mostrar(T_Complejo C) {
    printf("Numero Complejo: %.2f + %.2fi\n", C.real, C.imaginaria);
}
  
int main() 
{ 
    T_Complejo A,B,C,D;
    float real, imag;

 	printf("**Introduzca el primer numero COMPLEJO\n");
	printf("Parte real:\n");
	scanf("%f",&real);
	printf("Parte Imaginaria:\n");
	scanf("%f",&imag);
	A = cargar(real,imag);

  	printf("**Introduzca el segundo numero COMPLEJO\n");
	printf("Parte real:\n");
	scanf("%f",&real);
	printf("Parte Imaginaria:\n");
	scanf("%f",&imag);
	B = cargar(real,imag);
    
    mostrar (sumar(A,B));
    mostrar (multiplicar(A,B));
    
    if (igual(sumar(A,B),multiplicar(A,B))){
        printf("\nLa suma y multiplicación de los numeros complejos son iguales:\n");
    } else { 
	    printf("\nLa suma y multiplicación de los numeros complejos NO son iguales\n");
    } 
 	
    return 0;
}








