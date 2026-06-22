#include <stdio.h>
#include <string.h>
#include "vehiculos.h"
#include "validaciones.h"

#define ARCHIVO_VEHICULOS "vehiculos.txt"

void registrarVehiculo() {
    FILE *archivo;
    Vehiculo v;

    archivo = fopen(ARCHIVO_VEHICULOS, "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de vehiculos.\n");
        return;
    }

    printf("\n--- REGISTRO DE VEHICULO ---\n");

    v.codigo = leerEnteroPositivo("Codigo del vehiculo: ");

    printf("Marca: ");
    leerTexto(v.marca, 30);

    printf("Modelo: ");
    leerTexto(v.modelo, 30);

    printf("Tipo de vehiculo: ");
    leerTexto(v.tipo, 30);

    printf("Estado Nuevo/Usado: ");
    leerTexto(v.estado, 20);

    v.anio = leerEnteroPositivo("Anio: ");
    v.precio = leerFloatPositivo("Precio: ");
    v.disponible = 1;

    fprintf(archivo, "%d;%s;%s;%s;%s;%d;%.2f;%d\n",
            v.codigo, v.marca, v.modelo, v.tipo,
            v.estado, v.anio, v.precio, v.disponible);

    fclose(archivo);

    printf("\nVehiculo registrado correctamente.\n");
}

void mostrarVehiculos() {
    FILE *archivo;
    Vehiculo v;

    archivo = fopen(ARCHIVO_VEHICULOS, "r");

    if (archivo == NULL) {
        printf("\nNo existen vehiculos registrados.\n");
        return;
    }

    printf("\n--- LISTA DE VEHICULOS ---\n");

    while (fscanf(archivo, "%d;%29[^;];%29[^;];%29[^;];%19[^;];%d;%f;%d\n",
                  &v.codigo, v.marca, v.modelo, v.tipo,
                  v.estado, &v.anio, &v.precio, &v.disponible) == 8) {

        printf("\nCodigo: %d", v.codigo);
        printf("\nMarca: %s", v.marca);
        printf("\nModelo: %s", v.modelo);
        printf("\nTipo: %s", v.tipo);
        printf("\nEstado: %s", v.estado);
        printf("\nAnio: %d", v.anio);
        printf("\nPrecio: %.2f", v.precio);
        printf("\nDisponible: %s\n", v.disponible == 1 ? "Si" : "No");
    }

    fclose(archivo);
}

void buscarVehiculo() {
    FILE *archivo;
    Vehiculo v;
    char marca[30], tipo[30], estado[20];
    float precioMax;
    int encontrado = 0;

    archivo = fopen(ARCHIVO_VEHICULOS, "r");

    if (archivo == NULL) {
        printf("\nNo existen vehiculos registrados.\n");
        return;
    }

    printf("\n--- BUSQUEDA DE VEHICULO ---\n");

    printf("Marca buscada: ");
    leerTexto(marca, 30);

    printf("Tipo buscado: ");
    leerTexto(tipo, 30);

    printf("Estado buscado Nuevo/Usado: ");
    leerTexto(estado, 20);

    precioMax = leerFloatPositivo("Presupuesto maximo: ");

    printf("\n--- RESULTADOS DE BUSQUEDA ---\n");

    while (fscanf(archivo, "%d;%29[^;];%29[^;];%29[^;];%19[^;];%d;%f;%d\n",
                  &v.codigo, v.marca, v.modelo, v.tipo,
                  v.estado, &v.anio, &v.precio, &v.disponible) == 8) {

        if (v.disponible == 1 &&
            strcmp(v.marca, marca) == 0 &&
            strcmp(v.tipo, tipo) == 0 &&
            strcmp(v.estado, estado) == 0 &&
            v.precio <= precioMax) {

            printf("\nCodigo: %d", v.codigo);
            printf("\nMarca: %s", v.marca);
            printf("\nModelo: %s", v.modelo);
            printf("\nTipo: %s", v.tipo);
            printf("\nEstado: %s", v.estado);
            printf("\nAnio: %d", v.anio);
            printf("\nPrecio: %.2f\n", v.precio);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo se encontraron vehiculos con esas preferencias.\n");
    }

    fclose(archivo);
}

void casoRuben() {
    FILE *archivo;
    Vehiculo v;
    int encontrado = 0;

    archivo = fopen(ARCHIVO_VEHICULOS, "r");

    if (archivo == NULL) {
        printf("\nNo existen vehiculos registrados.\n");
        return;
    }

    printf("\n--- CASO DE PRUEBA RUBEN ---\n");
    printf("Ruben busca una camioneta Chevrolet usada con presupuesto maximo de $14000.\n");

    while (fscanf(archivo, "%d;%29[^;];%29[^;];%29[^;];%19[^;];%d;%f;%d\n",
                  &v.codigo, v.marca, v.modelo, v.tipo,
                  v.estado, &v.anio, &v.precio, &v.disponible) == 8) {

        if (v.disponible == 1 &&
            strcmp(v.marca, "Chevrolet") == 0 &&
            strcmp(v.tipo, "Camioneta") == 0 &&
            strcmp(v.estado, "Usado") == 0 &&
            v.precio <= 14000) {

            printf("\nVehiculo encontrado:");
            printf("\nCodigo: %d", v.codigo);
            printf("\nMarca: %s", v.marca);
            printf("\nModelo: %s", v.modelo);
            printf("\nPrecio: %.2f\n", v.precio);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo hay camionetas Chevrolet usadas dentro del presupuesto de Ruben.\n");
    }

    fclose(archivo);
}

int buscarVehiculoPorCodigo(int codigo, Vehiculo *vehiculo) {
    FILE *archivo;
    Vehiculo v;

    archivo = fopen(ARCHIVO_VEHICULOS, "r");

    if (archivo == NULL) {
        return 0;
    }

    while (fscanf(archivo, "%d;%29[^;];%29[^;];%29[^;];%19[^;];%d;%f;%d\n",
                  &v.codigo, v.marca, v.modelo, v.tipo,
                  v.estado, &v.anio, &v.precio, &v.disponible) == 8) {

        if (v.codigo == codigo && v.disponible == 1) {
            *vehiculo = v;
            fclose(archivo);
            return 1;
        }
    }

    fclose(archivo);
    return 0;
}

void actualizarVehiculo(Vehiculo vehiculoActualizado) {
    FILE *archivo, *temporal;
    Vehiculo v;

    archivo = fopen(ARCHIVO_VEHICULOS, "r");
    temporal = fopen("temp.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error al actualizar vehiculo.\n");
        return;
    }

    while (fscanf(archivo, "%d;%29[^;];%29[^;];%29[^;];%19[^;];%d;%f;%d\n",
                  &v.codigo, v.marca, v.modelo, v.tipo,
                  v.estado, &v.anio, &v.precio, &v.disponible) == 8) {

        if (v.codigo == vehiculoActualizado.codigo) {
            v = vehiculoActualizado;
        }

        fprintf(temporal, "%d;%s;%s;%s;%s;%d;%.2f;%d\n",
                v.codigo, v.marca, v.modelo, v.tipo,
                v.estado, v.anio, v.precio, v.disponible);
    }

    fclose(archivo);
    fclose(temporal);

    remove(ARCHIVO_VEHICULOS);
    rename("temp.txt", ARCHIVO_VEHICULOS);
}
