/**
 * Programa para calcular las comisiones de vendedores
 * según el esquema de la empresa de productos avícolas.
 */
#include <stdio.h>

int main() {
    // Declaración de variables
    float promedioVentas, ventasVendedor, totalPagar, comision;
    const float sueldoBase = 400.0; // Sueldo base para todos los vendedores
    int numVendedor = 1;
    
    // Mensaje inicial
    printf("Calculo de comisiones para vendedores\n");
    
    // Solicitar el promedio general de ventas
    printf("Introduzca el promedio general de ventas de la empresa: $");
    scanf("%f", &promedioVentas);
    
    // Validar que el promedio sea positivo
    if (promedioVentas <= 0) {
        printf("Error: El promedio de ventas debe ser un valor positivo\n");
        return 1; // Salir con código de error
    }
    
    // Ciclo para procesar cada vendedor
    printf("Introduzca el total de ventas mensuales del vendedor %d (-1 para finalizar): $", numVendedor);
    scanf("%f", &ventasVendedor);
    
    while (ventasVendedor != -1) {
        // Validar que las ventas sean positivas o cero
        if (ventasVendedor < 0 && ventasVendedor != -1) {
            printf("Error: Las ventas deben ser un valor positivo o cero\n");
        } else {
            // Inicializar comisión
            comision = 0.0;
            
            // Calcular la comisión según la tabla (sin usar if)
            // Usamos operadores ternarios y lógicos para simular el comportamiento sin if
            
            // Caso 1: < promedio general de ventas (5%)
            comision += (ventasVendedor < promedioVentas) ? 0.05 * ventasVendedor : 0;
            
            // Caso 2: igual o mayor entre 0.01% y 5% del promedio (8%)
            comision += (ventasVendedor >= promedioVentas && ventasVendedor <= promedioVentas * 1.05) ? 
                         0.08 * ventasVendedor : 0;
            
            // Caso 3: mayor entre 5.01% y 20% del promedio (12%)
            comision += (ventasVendedor > promedioVentas * 1.05 && ventasVendedor <= promedioVentas * 1.2) ? 
                         0.12 * ventasVendedor : 0;
            
            // Caso 4: mayor entre 20.01% y 35% del promedio (15%)
            comision += (ventasVendedor > promedioVentas * 1.2 && ventasVendedor <= promedioVentas * 1.35) ? 
                         0.15 * ventasVendedor : 0;
            
            // Caso 5: mayor entre 35.01% y 50% del promedio (18%)
            comision += (ventasVendedor > promedioVentas * 1.35 && ventasVendedor <= promedioVentas * 1.5) ? 
                         0.18 * ventasVendedor : 0;
            
            // Caso 6: mayor que el 50% del promedio (20%)
            comision += (ventasVendedor > promedioVentas * 1.5) ? 0.2 * ventasVendedor : 0;
            
            // Calcular el total a pagar
            totalPagar = sueldoBase + comision;
            
            // Mostrar resultado
            printf("Total a cancelar: $%.2f\n", totalPagar);
            
            // Incrementar el número de vendedor
            numVendedor++;
        }
        
        // Solicitar datos del siguiente vendedor
        printf("Introduzca el total de ventas mensuales del vendedor %d (-1 para finalizar): $", numVendedor);
        scanf("%f", &ventasVendedor);
    }
    
    // Mensaje de despedida
    printf("¡Gracias por usar nuestro programa!\n");
    
    return 0;
}