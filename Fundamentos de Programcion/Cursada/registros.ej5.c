/*
Dados dos 2 listados de inscripción de alumnos a 3 turnos de una misma
materia, se pide generar un listado único ordenado por número de alumno.
La estructura de los listados es: número de alumno (5 dígitos), apellido y
nombre, turno (1,2, 3). Puede ocurrir que un alumno se haya inscripto en
más de un turno por lo cual en el listado generado deben aparecer todos
los turnos en los que se inscribió en un único registro de alumno con
campo variable.
Los listados de entrada están ordenados por número de alumno. 
*/

#include <stdio.h>

#define MAX_NOMBRE 50
#define MAX_ALUMNOS 1000
#define MAX_TURNOS 3

typedef struct{
    int num_alumno;
    char apellido[MAX_NOMBRE];    
    char nombre[MAX_NOMBRE]; 
    int turnos[MAX_TURNOS];
    int n_turnos;
} Alumno;

void fusionar_listados(Alumno lista1[], int n1, Alumno lista2[], int n2, Alumno lista_final[], int *n_f){
    int i=0, j=0, k=0;

    //fusionar ambos listados mientras haya elementos en ambos.
    while(i < n1 && j < n2){
        if(lista1[i].num_alumno < lista2[j].num_alumno){
            //si el num de lista1 es menor, lo agregamos a la final
            lista_final[k] = lista1[i];
            i++;
            k++;
        } else if(lista1[i].num_alumno > lista2[j].num_alumno) {
            //si el num de lista2 es menor, lo agregamos a la final
            lista_final[k] = lista2[j];
            j++;
            k++;
        } else {
            //si son iguales, combinamos turnos.
            lista_final[k] = lista1[i];
            int n_turnos = lista_final[k].n_turnos;
            //Agregamos los turnos del alumno de la lista 2.
            for(int t=0; t< lista2[j].n_turnos; t++){
                lista_final[k].turnos[n_turnos] = lista2[j].turnos[t];
                n_turnos++;
            }
            lista_final[k].n_turnos = n_turnos;
            i++;
            j++;
            k++;
        }
    }

    //Agregar cualq elemento restante de lista 1 a la lista final.
    while(i<n1){
        lista_final[k] = lista1[i];
        i++;
        k++;
    }

    //Agregar cualq elemento restante de lista 2 a la lista final.
    while(j<n2){
        lista_final[k] = lista2[j];
        j++;
        k++;
    }    
    //actualizamos el tamaño final del listado fusionado
    *n_f = k;
}

void mostrar_listado(Alumno lista[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("Alumno: %i - %s, %s\n", lista[i].num_alumno, lista[i].apellido, lista[i].nombre);
        printf("Turnos: ");
        //Mostrar los turnos en los q esta inscrpto
        for(int j=0;j<lista[i].n_turnos;j++){
            printf("%i\t", lista[i].turnos[j]);
        }
        printf("\n");
    }
}

int main(void){
    //Datos precargados.
    Alumno lista1[MAX_ALUMNOS] = {
        {14523, "Portela", "Matias", {2}, 1},
        {25123, "Perez", "Angela", {1, 2}, 2},
        {54214, "Pazos", "Hector", {2}, 1}
    };
    int n_alum1 = 3;

    Alumno lista2[MAX_ALUMNOS] = {
        {14523, "Portela", "Matias", {1,3}, 2},
        {25135, "Portela", "Ailen", {1, 2, 3}, 3},
        {56423, "Baladron", "Alejandra", {2,3}, 2}
    };
    int n_alum2 = 3;

    //Array para almacenar el listado fusionado
    Alumno lista_final[MAX_ALUMNOS];
    int n_alum_f = 0;

    fusionar_listados(lista1, n_alum1, lista2, n_alum2, lista_final, &n_alum_f);

    printf("Listado fusionado:\n");
    mostrar_listado(lista_final, n_alum_f);

    return 0;
}