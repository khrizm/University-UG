#include <stdio.h>

/* Prototipos */
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main(void)
{
    double x, y;

    printf("Ingrese dos numeros (ej. 12.5  4): ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Entrada invalida.");
        return 1;
    }

    printf("\nResultados:\n");
    printf("  Suma           : %.4f\n", sumar(x, y));
    printf("  Resta          : %.4f\n", restar(x, y));
    printf("  Multiplicacion : %.4f\n", multiplicar(x, y));

    if (y != 0.0)
        printf("  Division       : %.4f\n", dividir(x, y));
    else
        puts("  Division       : Error (division entre cero).");

    return 0;
}

/* Definiciones */
double sumar(double a, double b)        { return a + b; }
double restar(double a, double b)       { return a - b; }
double multiplicar(double a, double b)  { return a * b; }
double dividir(double a, double b)      { return a / b; }
