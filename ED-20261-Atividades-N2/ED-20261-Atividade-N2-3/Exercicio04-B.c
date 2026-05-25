RA: 2040482513049 - Anna Beatriz Louro da Silva


#include <stdio.h>

int chamadas = 0;

long long potenciaRapida(long long base,
                         int exp) {

    chamadas++;

    /* Caso base */
    if(exp == 0) {
        return 1;
    }

    /* Expoente par */
    if(exp % 2 == 0) {

        long long metade =
            potenciaRapida(base, exp / 2);

        return metade * metade;
    }

    /* Expoente ímpar */
    return base *
           potenciaRapida(base, exp - 1);
}

int main() {

    printf("=====================================\n");
    printf(" Base | Exp | Resultado | Chamadas\n");
    printf("=====================================\n");

    long long resultado;

    chamadas = 0;
    resultado = potenciaRapida(2, 10);
    printf(" %4d | %3d | %9lld | %9d\n",
           2, 10, resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(3, 7);
    printf(" %4d | %3d | %9lld | %9d\n",
           3, 7, resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(5, 0);
    printf(" %4d | %3d | %9lld | %9d\n",
           5, 0, resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(7, 12);
    printf(" %4d | %3d | %9lld | %9d\n",
           7, 12, resultado, chamadas);

    return 0;
}
