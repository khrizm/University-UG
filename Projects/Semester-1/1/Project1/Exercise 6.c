/**
 * Programa que verifica si tres valores pueden formar
 * un triángulo recto usando el teorema de Pitágoras
 */
#include <stdio.h>
#include <math.h>

int main() {
    float lado1, lado2, lado3;
    int esTrianguloRecto = 0;
    const float EPSILON = 0.000001; // Para comparación de números float
    
    printf("Verificacion de triangulo recto\n");
    
    // Solicitar los tres lados
    printf("Ingrese el primer lado: ");
    scanf("%f", &lado1);
    
    printf("Ingrese el segundo lado: ");
    scanf("%f", &lado2);
    
    printf("Ingrese el tercer lado: ");
    scanf("%f", &lado3);
    
    // Validar que los tres lados sean positivos
    if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        printf("Error: Todos los lados deben ser valores positivos\n");
        return 1;
    }
    
    // Verificar si forman un triángulo (desigualdad triangular)
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        // Verificar si es un triángulo recto usando el teorema de Pitágoras
        // Primero ordenamos los lados para identificar la hipotenusa (el lado más largo)
        if (lado1 >= lado2 && lado1 >= lado3) {
            // lado1 es la hipotenusa
            esTrianguloRecto = (fabs((lado2*lado2 + lado3*lado3) - lado1*lado1) < EPSILON);
        } else if (lado2 >= lado1 && lado2 >= lado3) {
            // lado2 es la hipotenusa
            esTrianguloRecto = (fabs((lado1*lado1 + lado3*lado3) - lado2*lado2) < EPSILON);
        } else {
            // lado3 es la hipotenusa
            esTrianguloRecto = (fabs((lado1*lado1 + lado2*lado2) - lado3*lado3) < EPSILON);
        }
        
        // Mostrar el resultado
        if (esTrianguloRecto) {
            printf("Los lados ingresados forman un triangulo recto\n");
        } else {
            printf("Los lados ingresados forman un triangulo, pero no es recto\n");
        }
    } else {
        printf("Los lados ingresados no pueden formar un triangulo\n");
    }
    
    return 0;
}