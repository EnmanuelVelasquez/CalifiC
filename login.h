#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <stdlib.h>
//#include "admin.h"

void saludoBienvenida();
int loginAdmin(char *usuario, char *contrasena);
void manejarLogin();


void saludoBienvenida(){
    printf("\n-----Bienvenido a CalifiC-----\n");
}

void manejarLogin() { 
    char usuario[50]; 
    char contrasena[50]; 
    int tipoUsuario; 

    printf("Ingrese su usuario:\n"); 
    scanf("%s", usuario); 
    printf("Ingrese su contraseña:\n"); 
    scanf("%s", contrasena); 

    tipoUsuario = loginAdmin(usuario, contrasena);

    if (tipoUsuario == 1) { 
        printf("Bienvenido Administrador\n"); 
        menuPrincipalAdmin(); 
        } else { 
        printf("Usuario o contraseña incorrectos\n"); 
    }
}

// Función para verificar si un usuario es administrador
int esAdmin(char *usuario, char *contrasena) {
    // Validación de entrada
    if (usuario == NULL || contrasena == NULL) {
        printf("Usuario o contraseña no pueden ser nulos\n");
        return 0; // Entrada inválida
    }

    FILE *fp = fopen("data/admin.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos: %s\n", strerror(errno)); // Mensaje de error mejorado
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char tipo[10], id[10], nombre[50], password[50];
        sscanf(line, "Tipo:%[^;];ID:%[^;];Nombre:%[^;];Password:%[^;];", tipo, id, nombre, password);
        
        // Asegúrate de que la contraseña se lea correctamente
        nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea
        password[strcspn(password, "\n")] = 0; // Eliminar salto de línea
        
        if (strcmp(nombre, usuario) == 0 && strcmp(password, contrasena) == 0) {
            fclose(fp);
            return 1; // Admin encontrado
        }
    }
    fclose(fp);
    
    return 0; // Admin no encontrado
}

// Implementación de la función de login para administradores
int loginAdmin(char *usuario, char *contrasena) {
    if (esAdmin(usuario, contrasena)) {
        return 1; // Administrador
    } else {

        return 0; // Usuario no encontrado
    }
}


void cerrarSesion() {
    printf("Cerrando sesion...\n");
    Sleep(2000);
    saludoBienvenida();
    // Aquí puedes agregar cualquier limpieza adicional si es necesario
    manejarLogin();
}
#endif // LOGIN_H
