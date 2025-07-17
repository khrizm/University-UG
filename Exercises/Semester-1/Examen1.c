#include <stdio.h>

#define MAX_PC 100

typedef struct {
    char serie[20];
    char marca[20];
    int anio;
} Computadora;

int main() {
    char codigoLote[20];
    int cantidad, i;

    printf("Ingrese el código del lote: ");
    scanf("%s", codigoLote);

    do {
        printf("Ingrese la cantidad de computadoras (máximo %d): ", MAX_PC);
        scanf("%d", &cantidad);
        if (cantidad > MAX_PC || cantidad <= 0) {
            printf("Cantidad inválida. Intente de nuevo.\n");
        }
    } while (cantidad > MAX_PC || cantidad <= 0);

    Computadora computadoras[MAX_PC];

    for (i = 0; i < cantidad; i++) {
        printf("\nComputadora #%d\n", i + 1);
        printf("Ingrese número de serie: ");
        scanf("%s", computadoras[i].serie);
        printf("Ingrese marca: ");
        scanf("%s", computadoras[i].marca);
        printf("Ingrese año de fabricación: ");
        scanf("%d", &computadoras[i].anio);
    }


    printf("\nCódigo de lote: %s\n", codigoLote);
    printf("Cantidad de computadoras: %d\n", cantidad);
    printf("\n| %-4s | %-15s | %-10s | %-4s |\n", "N°", "Serie", "Marca", "Año");
    for (i = 0; i < cantidad; i++) {
        printf("| %-4d | %-15s | %-10s | %-4d |\n",
               i + 1,
               computadoras[i].serie,
               computadoras[i].marca,
               computadoras[i].anio);
    }

    return 0;
}
