#ifndef DOCENTE_H
#define DOCENTE_H
#include "asignatura.h"
typedef struct{
    int id;
    char nombre[50];
    char apellido[50];
    char contrasena[50];
    Asignatura asignaturas[3];
} Docente;


void menuDocente();
void crearDocente();
void actualizarDocente();
void mostrarDocente();
void eliminarDocente();
#endif