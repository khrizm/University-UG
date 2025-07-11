/**
 * Programa que genera un árbol de asteriscos
 * según el número ingresado por el usuario
 */
#include <stdio.h>

int main() {
    int numero, fila, columna, espacios;
    
    printf("Generador de arbol de asteriscos\n");
    
    // Solicitar el número
    printf("Ingrese un numero positivo: ");
    scanf("%d", &numero);
    
    // Validar que el número sea positivo
    if (numero <= 0) {
        printf("Error: El numero debe ser positivo\n");
        return 1;
    }
    
    // Generar el árbol
    for (fila = 1; fila <= numero; fila++) {
        // Imprimir espacios en blanco
        for (espacios = 1; espacios <= numero - fila; espacios++) {
            printf(" ");
        }
        
        // Imprimir asteriscos
        for (columna = 1; columna <= 2 * fila - 1; columna++) {
            printf("*");
        }
        
        // Salto de línea al final de cada fila
        printf("\n");
    }
    
    return 0;
}