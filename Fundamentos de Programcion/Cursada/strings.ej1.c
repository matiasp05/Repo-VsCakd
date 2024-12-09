/*
Se tiene un listado de alumnos con Nombre y Apellido y numero de padron.
 Se pide cargar la informacion en las estructuras necesarias y calcular
 1- Validar que el nombre y apellido tenga la forma Nombre,Apellido
 2- Ingresar 2 letras y mostrar todos los nombres y apellidos comprendidos entra ambas
 3-Ingresar un apellido (solamente) y mostrar los alumnos con ese apellido
 	Variante resolver este ejercicio ordenando el vector.
 4- Ingresar un nombre y apellido y mostrar el padron corespondiente.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARACTER 50
#define MAX_ALUM 10


typedef char TNombreApellido[MAX_CHARACTER]; //Nombres
typedef TNombreApellido Listado[MAX_ALUM]; //Listado
typedef int TVector[MAX_ALUM]; //Padrones

void cargarDatos(Listado list){
    TNombreApellido string;
    bool terminado;
    int pos;
    
    terminado = false;
    pos = 0;
    do{
        printf("Ingrese el nombre y apellido del alumno con el siguiente formato:\n[NOMBRE],[APELLIDO]: ");
        fgets(string, MAX_CHARACTER, stdin);
        if(strstr(string, ",")!=NULL){
            strcpy(list[pos], string);
            pos++;
        }
    }while(!terminado);
    return;
}
