#include <stdio.h>
#include "ventas.h"
#include "clientes.h"
#include "vehiculos.h"
#include "validaciones.h"

#define ARCHIVO_VENTAS "ventas.txt"

void registrarVenta() {
    FILE *archivo;
    Venta venta;
    Cliente cliente;
    Vehiculo vehiculo;

    printf("\n--- REGISTRO DE VENTA ---\n");

    venta.codigoVenta = leerEnteroPositivo("Codigo de venta: ");
    venta.codigoCliente = leerEnteroPositivo("Codigo del cliente: ");
    venta.codigoVehiculo = leerEnteroPositivo("Codigo del vehiculo: ");

    if (!buscarClientePorCodigo(venta.codigoCliente, &cliente)) {
        printf("\nError: cliente no encontrado.\n");
        return;
    }

    if (!buscarVehiculoPorCodigo(venta.codigoVehiculo, &vehiculo)) {
        printf("\nError: vehiculo no encontrado o no disponible.\n");
        return;
    }

    venta.precioVenta = vehiculo.precio;

    archivo = fopen(ARCHIVO_VENTAS, "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de ventas.\n");
        return;
    }

    fprintf(archivo, "%d;%d;%d;%.2f\n",
            venta.codigoVenta,
            venta.codigoCliente,
            venta.codigoVehiculo,
            venta.precioVenta);

    fclose(archivo);

    vehiculo.disponible = 0;
    actualizarVehiculo(vehiculo);

    printf("\nVenta registrada correctamente.\n");
    printf("Cliente: %s\n", cliente.nombre);
    printf("Vehiculo: %s %s\n", vehiculo.marca, vehiculo.modelo);
    printf("Precio vendido: %.2f\n", venta.precioVenta);
}

void mostrarVentas() {
    FILE *archivo;
    Venta v;

    archivo = fopen(ARCHIVO_VENTAS, "r");

    if (archivo == NULL) {
        printf("\nNo existen ventas registradas.\n");
        return;
    }

    printf("\n--- LISTA DE VENTAS ---\n");

    while (fscanf(archivo, "%d;%d;%d;%f\n",
                  &v.codigoVenta,
                  &v.codigoCliente,
                  &v.codigoVehiculo,
                  &v.precioVenta) == 4) {

        printf("\nCodigo venta: %d", v.codigoVenta);
        printf("\nCodigo cliente: %d", v.codigoCliente);
        printf("\nCodigo vehiculo: %d", v.codigoVehiculo);
        printf("\nPrecio venta: %.2f\n", v.precioVenta);
    }

    fclose(archivo);
}
