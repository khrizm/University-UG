/**
 * Programa que genera un patrón de letras 'A'
 * según el número ingresado por el usuario
 */
#include <stdio.h>

int main() {
    int numero, fila, columna;
    
    printf("Generador de patron de letras A\n");
    
    // Solicitar el número
    printf("Ingrese un numero positivo: ");
    scanf("%d", &numero);
    
    // Validar que el número sea positivo
    if (numero <= 0) {
        printf("Error: El numero debe ser positivo\n");
        return 1;
    }
    
    // Generar el patrón
    for (fila = 1; fila <= numero; fila++) {
        // Imprimir las letras A en cada fila
        for (columna = 1; columna <= fila; columna++) {
            printf("A");
        }
        
        // Salto de línea al final de cada fila
        printf("\n");
    }
    
    return 0;
}