#include <stdio.h>
#include <string.h>
#include "validaciones.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void leerTexto(char texto[], int tam) {
    fgets(texto, tam, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

int leerEnteroPositivo(char mensaje[]) {
    int valor;

    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        limpiarBuffer();

        if (valor <= 0) {
            printf("Error: ingrese un numero positivo.\n");
        }
    } while (valor <= 0);

    return valor;
}

float leerFloatPositivo(char mensaje[]) {
    float valor;

    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        limpiarBuffer();

        if (valor <= 0) {
            printf("Error: ingrese un valor positivo.\n");
        }
    } while (valor <= 0);

    return valor;
}
