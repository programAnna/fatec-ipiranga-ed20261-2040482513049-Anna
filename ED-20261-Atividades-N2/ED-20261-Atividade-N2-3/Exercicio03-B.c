#include <stdio.h>
#include <math.h>

int movimentos = 0;

void hanoi(int n,
           char origem,
           char destino,
           char auxiliar) {

    /* Caso base */
    if(n == 1) {

        movimentos++;

        return;
    }

    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    movimentos++;

    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}

int main() {

    printf("=====================================\n");
    printf(" n | Movimentos | Esperado (2^n - 1)\n");
    printf("=====================================\n");

    for(int n = 1; n <= 6; n++) {

        movimentos = 0;

        hanoi(n, 'A', 'C', 'B');

        int esperado = (int)pow(2, n) - 1;

        printf(" %d | %11d | %18d\n",
               n,
               movimentos,
               esperado);
    }

    printf("=====================================\n");

    return 0;
}
