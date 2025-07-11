#include <stdio.h>

#define N 10

struct Empleado {
    char nombre[50];
    char cargo[50];
    char seguro[20];
    float salario;
};

int main() {
    struct Empleado empleados[N];
    int i;
    float sumaSalarios = 0;

    printf("Ingrese los datos de los empleados:\n");
    for (i = 0; i < N; i++) {
        printf("\nEmpleado %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", empleados[i].nombre);
        printf("Cargo: ");
        scanf(" %[^\n]", empleados[i].cargo);
        printf("Número de Seguro Social: ");
        scanf(" %[^\n]", empleados[i].seguro);
        printf("Salario: ");
        scanf("%f", &empleados[i].salario);

        sumaSalarios += empleados[i].salario;
    }

    printf("\n--- Promedio de salarios ---\n");
    printf("Promedio: $%.2f\n", sumaSalarios / N);

    return 0;
}
