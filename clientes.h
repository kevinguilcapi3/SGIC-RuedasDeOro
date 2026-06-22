#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    int codigo;
    char nombre[50];
    int edad;
    char telefono[20];
} Cliente;

void registrarCliente();
void mostrarClientes();
int buscarClientePorCodigo(int codigo, Cliente *cliente);

#endif
