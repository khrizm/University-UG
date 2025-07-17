#include <stdio.h>
#include <math.h> 

#define AREA_POR_CAJA 2.26

int calcularCantidadCajas(double metrosCuadrados) {
    return (int)ceil(metrosCuadrados / AREA_POR_CAJA);
}

double calcularCostoTotal(int cantidadCajas, double costoPorCaja) {
    return cantidadCajas * costoPorCaja;
}

int main() {
    double metrosCuadrados, costoCaja;
    int cantidadCajas;
    double costoTotal;
    
    do {
        printf("Ingrese la cantidad de metros cuadrados a cubrir: ");
        scanf("%lf", &metrosCuadrados);
        if (metrosCuadrados <= 0) {
            printf("Cantidad inválida. Intente de nuevo.\n");
        }
    } while (metrosCuadrados <= 0);
    
    do {
        printf("Ingrese el costo por caja de cerámica: ");
        scanf("%lf", &costoCaja);
        if (costoCaja <= 0) {
            printf("Precio inválido. Ingrese el precio de nuevo.\n");
        }
    } while (costoCaja <= 0);
    

    cantidadCajas = calcularCantidadCajas(metrosCuadrados);
    costoTotal = calcularCostoTotal(cantidadCajas, costoCaja);

    printf("\nCantidad de cajas necesarias: %d\n", cantidadCajas);
    printf("Costo total: %.2f\n", costoTotal);

    return 0;
}