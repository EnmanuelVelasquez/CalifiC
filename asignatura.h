#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "docente.h"
#include "estudiante.h"

typedef struct {
    char nombre[50];
    float calificaciones[6];
} Asignatura;

void crearAsignatura();
void actualizarAsignatura();
void mostrarAsignatura();
void eliminarAsignatura();

#endif