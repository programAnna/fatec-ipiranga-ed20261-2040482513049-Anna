RA: 2040482513049 - Anna Beatriz Louro da Silva

#include <stdio.h>
#include <math.h>

int movimentos = 0;

void hanoi(int n,
           char origem,
           char destino,
           char auxiliar,
           int nivel) {

    /* Caso base */
    if(n == 1) {

        /* Indentação da profundidade */
        for(int i = 0; i < nivel * 2; i++) {
            printf(" ");
        }

        printf("Mover disco 1 de %c para %c\n",
               origem, destino);

        movimentos++;

        return;
    }

    /* PASSO 1:
       Move n-1 para auxiliar */
    hanoi(n - 1,
          origem,
          auxiliar,
          destino,
          nivel + 1);

    /* Indentação */
    for(int i = 0; i < nivel * 2; i++) {
        printf(" ");
    }

    /* PASSO 2:
       Move o maior disco */
    printf("Mover disco %d de %c para %c\n",
           n, origem, destino);

    movimentos++;

    /* PASSO 3:
       Move n-1 para destino */
    hanoi(n - 1,
          auxiliar,
          destino,
          origem,
          nivel + 1);
}

int main() {

    printf("=====================================\n");
    printf(" n | Movimentos | Esperado (2^n - 1)\n");
    printf("=====================================\n");

    for(int n = 1; n <= 6; n++) {

        movimentos = 0;

        printf("\n===== Hanoi com n = %d =====\n\n", n);

        hanoi(n, 'A', 'C', 'B', 0);

        int esperado = (int)pow(2, n) - 1;

        printf("\n-------------------------------------\n");

        printf(" %d | %11d | %18d\n",
               n,
               movimentos,
               esperado);

        printf("-------------------------------------\n\n");
    }

    return 0;
}
