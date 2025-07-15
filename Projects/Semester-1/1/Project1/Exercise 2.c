/**
 * Programa para calcular el consumo de gasolina
 * en kilómetros por litro para varias tanqueadas
 */
#include <stdio.h>

int main() {
    float litros, kilometros, kmPorLitro, totalKmPorLitro, promedioGeneral;
    int contadorTanqueadas;
    
    // Inicialización de variables
    totalKmPorLitro = 0.0;
    contadorTanqueadas = 0;
    
    printf("Calculo de consumo de gasolina\n");
    
    // Ciclo para ingresar datos
    printf("Introduzca los litros utilizados (-1 para terminar): ");
    scanf("%f", &litros);
    
    while (litros != -1) {
        // Validar que los litros sean positivos
        if (litros <= 0) {
            printf("Error: Los litros deben ser un valor positivo\n");
        } else {
            // Solicitar kilómetros recorridos
            printf("Introduzca los kilometros conducidos: ");
            scanf("%f", &kilometros);
            
            // Validar que los kilómetros sean positivos
            if (kilometros <= 0) {
                printf("Error: Los kilometros deben ser un valor positivo\n");
            } else {
                // Calcular kilómetros por litro para esta tanqueada
                kmPorLitro = kilometros / litros;
                
                // Mostrar resultado para esta tanqueada
                printf("Los kilometros por litros de esta tanqueada fueron %f\n", kmPorLitro);
                
                // Acumular para el promedio general
                totalKmPorLitro += kmPorLitro;
                contadorTanqueadas++;
            }
        }
        
        // Solicitar la siguiente entrada
        printf("Introduzca los litros utilizados (-1 para terminar): ");
        scanf("%f", &litros);
    }
    
    // Verificar si se ingresaron datos
    if (contadorTanqueadas > 0) {
        // Calcular y mostrar el promedio general
        promedioGeneral = totalKmPorLitro / contadorTanqueadas;
        printf("El promedio general de Kilometros/litro fue %f\n", promedioGeneral);
    } else {
        printf("No se ingresaron datos validos\n");
    }
    
    return 0;
}