#ifndef VENTAS_H
#define VENTAS_H

typedef struct {
    int codigoVenta;
    int codigoCliente;
    int codigoVehiculo;
    float precioVenta;
} Venta;

void registrarVenta();
void mostrarVentas();

#endif
