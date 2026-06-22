#include <stdio.h>
#include "clientes.h"
#include "validaciones.h"

#define ARCHIVO_CLIENTES "clientes.txt"

void registrarCliente() {
    FILE *archivo;
    Cliente c;

    archivo = fopen(ARCHIVO_CLIENTES, "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }

    printf("\n--- REGISTRO DE CLIENTE ---\n");

    c.codigo = leerEnteroPositivo("Codigo del cliente: ");

    printf("Nombre del cliente: ");
    leerTexto(c.nombre, 50);

    c.edad = leerEnteroPositivo("Edad: ");

    printf("Telefono: ");
    leerTexto(c.telefono, 20);

    fprintf(archivo, "%d;%s;%d;%s\n",
            c.codigo, c.nombre, c.edad, c.telefono);

    fclose(archivo);

    printf("\nCliente registrado correctamente.\n");
}

void mostrarClientes() {
    FILE *archivo;
    Cliente c;

    archivo = fopen(ARCHIVO_CLIENTES, "r");

    if (archivo == NULL) {
        printf("\nNo existen clientes registrados.\n");
        return;
    }

    printf("\n--- LISTA DE CLIENTES ---\n");

    while (fscanf(archivo, "%d;%49[^;];%d;%19[^\n]\n",
                  &c.codigo, c.nombre, &c.edad, c.telefono) == 4) {

        printf("\nCodigo: %d", c.codigo);
        printf("\nNombre: %s", c.nombre);
        printf("\nEdad: %d", c.edad);
        printf("\nTelefono: %s\n", c.telefono);
    }

    fclose(archivo);
}

int buscarClientePorCodigo(int codigo, Cliente *cliente) {
    FILE *archivo;
    Cliente c;

    archivo = fopen(ARCHIVO_CLIENTES, "r");

    if (archivo == NULL) {
        return 0;
    }

    while (fscanf(archivo, "%d;%49[^;];%d;%19[^\n]\n",
                  &c.codigo, c.nombre, &c.edad, c.telefono) == 4) {

        if (c.codigo == codigo) {
            *cliente = c;
            fclose(archivo);
            return 1;
        }
    }

    fclose(archivo);
    return 0;
}
