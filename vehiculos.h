#ifndef VEHICULOS_H
#define VEHICULOS_H

typedef struct {
    int codigo;
    char marca[30];
    char modelo[30];
    char tipo[30];
    char estado[20];
    int anio;
    float precio;
    int disponible;
} Vehiculo;

void registrarVehiculo();
void mostrarVehiculos();
void buscarVehiculo();
void casoRuben();
int buscarVehiculoPorCodigo(int codigo, Vehiculo *vehiculo);
void actualizarVehiculo(Vehiculo vehiculoActualizado);

#endif
