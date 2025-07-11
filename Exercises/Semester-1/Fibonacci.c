#include <stdio.h>

void fibonacci(int n);

int main(void)
{
    int n;

    printf("Ingrese la cantidad de terminos de Fibonacci que desea: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Entrada invalida. Debe ser un entero positivo.");
        return 1;
    }

    printf("Sucesion de Fibonacci (primeros %d terminos):\n", n);
    fibonacci(n);

    return 0;
}

/* Genera e imprime la sucesión de Fibonacci hasta n términos */
void fibonacci(int n)
{
    int i;
    long a = 0;  /* F(0) = 0   (no se imprime) */
    long b = 1;  /* F(1) = 1 */
    long temp;

    for (i = 1; i <= n; ++i) {
        printf("%ld", b);
        if (i != n) printf(", ");

        /* Calcula siguiente término */
        temp = b;
        b = a + b; /* F(i)   */
        a = temp;  /* F(i-1) */
    }
    putchar('\n');
}
