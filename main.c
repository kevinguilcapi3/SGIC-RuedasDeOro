#include <stdio.h>
#include "vehiculos.h"
#include "clientes.h"
#include "ventas.h"
#include "validaciones.h"

int main() {
    int opcion;

    do {
        printf("\n=====================================\n");
        printf(" SISTEMA SGIC - RUEDAS DE ORO\n");
        printf("=====================================\n");
        printf("1. Registrar vehiculo\n");
        printf("2. Mostrar vehiculos\n");
        printf("3. Buscar vehiculo por preferencias\n");
        printf("4. Registrar cliente\n");
        printf("5. Mostrar clientes\n");
        printf("6. Registrar venta\n");
        printf("7. Mostrar ventas\n");
        printf("8. Caso de prueba Ruben\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                registrarVehiculo();
                break;
            case 2:
                mostrarVehiculos();
                break;
            case 3:
                buscarVehiculo();
                break;
            case 4:
                registrarCliente();
                break;
            case 5:
                mostrarClientes();
                break;
            case 6:
                registrarVenta();
                break;
            case 7:
                mostrarVentas();
                break;
            case 8:
                casoRuben();
                break;
            case 0:
                printf("\nSaliendo del sistema...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}
