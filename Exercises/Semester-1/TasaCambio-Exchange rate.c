#include <stdio.h>
#define USD_A_EUR 0.92      /* 1 USD ˜ 0.92 EUR  */
#define USD_A_COP 3950.0    /* 1 USD ˜ 3 950 COP */

void convertir_monto(double montoUSD, double *eur, double *cop);

int main(void)
{
    double monto1, monto2, monto3;
    double eur, cop;

    puts("Ingrese tres cantidades en Dolares (ej. 10 25.5 100):");
    if (scanf("%lf %lf %lf", &monto1, &monto2, &monto3) != 3) {
        puts("Entrada invalida.");
        return 1;
    }

    puts("\nConversiones:");
    convertir_monto(monto1, &eur, &cop);
    printf("  %.2f USD = %.2f EUR | %.2f COP\n", monto1, eur, cop);

    convertir_monto(monto2, &eur, &cop);
    printf("  %.2f USD = %.2f EUR | %.2f COP\n", monto2, eur, cop);

    convertir_monto(monto3, &eur, &cop);
    printf("  %.2f USD = %.2f EUR | %.2f COP\n", monto3, eur, cop);

    return 0;
}

void convertir_monto(double montoUSD, double *eur, double *cop)
{
    *eur = montoUSD * USD_A_EUR;
    *cop = montoUSD * USD_A_COP;
}
