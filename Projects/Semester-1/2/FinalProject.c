#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FAMILIAS 100
#define MAX_NOMBRE 50
#define MAX_CEDULA 15

typedef struct {
    char cedula[MAX_CEDULA];
    char nombre[MAX_NOMBRE];
    int totalNinos;
    int regalosEntregados;
} Familia;

Familia familias[MAX_FAMILIAS];
int totalFamilias = 0;

// Limpia el buffer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Ingreso de datos de familias
void ingresarFamilias() {
    char continuar;
    do {
        if (totalFamilias >= MAX_FAMILIAS) {
            printf("No se pueden ingresar más familias.\n");
            return;
        }

        printf("\nIngrese cédula del representante: ");
        fgets(familias[totalFamilias].cedula, MAX_CEDULA, stdin);
        strtok(familias[totalFamilias].cedula, "\n");

        printf("Ingrese nombre del representante: ");
        fgets(familias[totalFamilias].nombre, MAX_NOMBRE, stdin);
        strtok(familias[totalFamilias].nombre, "\n");

        printf("Ingrese número de niños: ");
        scanf("%d", &familias[totalFamilias].totalNinos);
        limpiarBuffer();

        familias[totalFamilias].regalosEntregados = 0;
        totalFamilias++;

        printf("¿Desea ingresar otra familia? (s/n): ");
        scanf(" %c", &continuar);
        limpiarBuffer();

    } while (continuar == 's' || continuar == 'S');
}

// Buscar familia por cédula
int buscarFamiliaPorCedula(char *cedula) {
    int i;
    for (i = 0; i < totalFamilias; i++) {
        if (strcmp(familias[i].cedula, cedula) == 0) {
            return i;
        }
    }
    return -1;
}

// Entregar regalo a niño de familia específica
void entregarRegalo() {
    char cedula[MAX_CEDULA];
    char continuar;
    int indice;

    do {
        printf("\nIngrese cédula del representante: ");
        fgets(cedula, MAX_CEDULA, stdin);
        strtok(cedula, "\n");

        indice = buscarFamiliaPorCedula(cedula);
        if (indice == -1) {
            printf("Familia no encontrada.\n");
        } else {
            if (familias[indice].regalosEntregados < familias[indice].totalNinos) {
                familias[indice].regalosEntregados++;
                printf("Regalo entregado a un niño de la familia %s.\n", familias[indice].nombre);
            } else {
                printf("Todos los niños de esta familia ya recibieron su regalo.\n");
            }
        }

        printf("¿Desea registrar otra entrega? (s/n): ");
        scanf(" %c", &continuar);
        limpiarBuffer();

    } while (continuar == 's' || continuar == 'S');
}

// Reporte de regalos faltantes por familia
void reporteFaltantes() {
    int i, faltantes;

    printf("\n--- Reporte de Regalos FALTANTES ---\n");
    for (i = 0; i < totalFamilias; i++) {
        faltantes = familias[i].totalNinos - familias[i].regalosEntregados;
        printf("Cédula: %s | Nombre: %s | Faltan: %d regalos\n",
               familias[i].cedula,
               familias[i].nombre,
               faltantes);
    }
}

// Reporte de regalos entregados por familia
void reporteEntregados() {
    int i;

    printf("\n--- Reporte de Regalos ENTREGADOS ---\n");
    for (i = 0; i < totalFamilias; i++) {
        printf("Cédula: %s | Nombre: %s | Entregados: %d regalos\n",
               familias[i].cedula,
               familias[i].nombre,
               familias[i].regalosEntregados);
    }
}

// Menú principal del sistema
void menu() {
    int opcion;

do {
        printf("\n====== MENÚ PRINCIPAL ======\n");
        printf("1. Ingreso de datos del representante\n");
        printf("2. Entrega de regalo a un niño\n");
        printf("3. Reporte de regalos faltantes por familia\n");
        printf("4. Reporte de regalos entregados por familia\n");
        printf("5. Salir del programa\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                ingresarFamilias();
                break;
            case 2:
                entregarRegalo();
                break;
            case 3:
                reporteFaltantes();
                break;
            case 4:
                reporteEntregados();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 5);       
}

// Punto de entrada
int main() {
    menu();
    return 0;
}
