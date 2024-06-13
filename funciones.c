#include<stdio.h>
#include"funciones.h"
#include <string.h>

void imprimirAlumnos(char alumnos[][2][20],double notas[][3]){
    printf("Nombre\t\tApellido\t\tNota 1\t\tNota 2\t\tNota 3\t\tPromedio\n");
    for (int i = 0; i < 6 ; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2])/3;

        printf("%s\t\t%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
        if (promedio >=6 ) {
            printf("\tEstudiante Aprobado\n");
        } else {
            printf("\tEstudiante Reprobado\n");
        }
    }
}

void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]) {
    char buscaApellido[20];
    int noExiste = 1;
    
    printf("Ingrese el apellido: ");
    scanf("%s", buscaApellido);
    
      printf("Apellido\t\tNota 1\t\tNota 2\t\tNota 3\t\tPromedio\n");
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], buscaApellido) == 0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
              printf("%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t", alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
            if (promedio >= 6) {
                printf("Estudiante Aprobado\n");
            } else {
                printf("Estudiante Reprobado\n");
            }
            noExiste = 0;
        }
    }
    if (noExiste) {
        printf("El alumno no existe\n");
    }
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]) {
    char buscarApellido[20], buscarNombre[20];
    double nuevaNota1, nuevaNota2, nuevaNota3;
    int encontrado = 0;
    
    imprimirAlumnos(alumnos, notas);
    
    printf("\nIngrese el apellido del alumno que desea editar: ");
    scanf("%s", buscarApellido);
    
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], buscarApellido) == 0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
            printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%.2lf", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
            if (promedio >= 6.0) {
                printf("\tEstudiante Aprobado\n");
            } else {
                printf("\tEstudiante Reprobado\n");
            }
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("El alumno no existe\n");
        return;
    }
    
    printf("\nConfirme el alumno por su nombre: ");
    scanf("%s", buscarNombre);
    
    for (int j = 0; j < 6; j++) {
        if (strcmp(alumnos[j][0], buscarNombre) == 0) {
            printf("Ingrese la nueva nota 1: ");
            scanf("%lf", &nuevaNota1);
            printf("Ingrese la nueva nota 2: ");
            scanf("%lf", &nuevaNota2);
            printf("Ingrese la nueva nota 3: ");
            scanf("%lf", &nuevaNota3);
            notas[j][0] = nuevaNota1;
            notas[j][1] = nuevaNota2;
            notas[j][2] = nuevaNota3;
            imprimirAlumnos(alumnos, notas);
            return;
        }
    }
    printf("Alumno no encontrado\n");
}
