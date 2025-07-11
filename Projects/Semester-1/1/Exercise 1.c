/**
 * Programa que encuentra el mayor número entre varios números enteros
 * ingresados por el usuario hasta que ingrese 0.
 */
#include <stdio.h>

int main() {
    int numero, mayor;
    int primerNumero = 1; // Flag para controlar el primer número válido
    
    printf("Este programa encuentra el mayor numero entre varios numeros enteros\n");
    printf("Ingrese numeros enteros (0 para terminar)\n");
    
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    // Si el primer número es 0, no hay números válidos
    if (numero == 0) {
        printf("No ingreso ningun numero valido\n");
        return 0;
    }
    
    // El primer número es el mayor hasta ahora
    mayor = numero;
    
    // Ciclo para leer los siguientes números
    while (numero != 0) {
        printf("Ingrese un numero (0 para terminar): ");
        scanf("%d", &numero);
        
        // Verificar si el número actual es mayor que el mayor encontrado
        if (numero > mayor && numero != 0) {
            mayor = numero;
        }
    }
    
    // Mostrar el resultado
    printf("El mayor numero ingresado es: %d\n", mayor);
    
    return 0;
}