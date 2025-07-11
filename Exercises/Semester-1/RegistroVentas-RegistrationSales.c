#include <stdio.h>

#define N 5  

int main() {
    float ventas2022[N], ventas2023[N];
    float suma2022 = 0, suma2023 = 0;
    int i, mayores120_2022 = 0, mayores300_2023 = 0;
    float comisiones2022 = 0, comisiones2023 = 0;

    printf("Ingrese las ventas del año 2022:\n");
    for (i = 0; i < N; i++) {
        printf("Venta %d: $", i + 1);
        scanf("%f", &ventas2022[i]);
        suma2022 += ventas2022[i];
        if (ventas2022[i] > 120) {
            mayores120_2022++;
        }
        comisiones2022 += ventas2022[i] * 0.08;
    }

    // Ingreso de ventas 2023
    printf("\nIngrese las ventas del año 2023:\n");
    for (i = 0; i < N; i++) {
        printf("Venta %d: $", i + 1);
        scanf("%f", &ventas2023[i]);
        suma2023 += ventas2023[i];
        if (ventas2023[i] > 300) {
            mayores300_2023++;
        }
        comisiones2023 += ventas2023[i] * 0.11;
    }

    printf("\n--- Resultados ---\n");
    printf("Promedio ventas 2022: $%.2f\n", suma2022 / N);
    printf("Promedio ventas 2023: $%.2f\n", suma2023 / N);
    printf("Ventas mayores a $120 en 2022: %d\n", mayores120_2022);
    printf("Ventas mayores a $300 en 2023: %d\n", mayores300_2023);
    printf("Total comisiones 2022 (8%%): $%.2f\n", comisiones2022);
    printf("Total comisiones 2023 (11%%): $%.2f\n", comisiones2023);

    return 0;
}
