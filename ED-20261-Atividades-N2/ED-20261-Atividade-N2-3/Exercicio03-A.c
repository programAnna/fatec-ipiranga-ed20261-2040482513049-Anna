RA: 2040482513049 - Anna Beatriz Louro da Silva

#include <stdio.h>

void hanoi(int n,
           char origem,
           char destino,
           char auxiliar) {

    /* Caso base */
    if(n == 1) {

        printf("Mover disco 1 de %c para %c\n",
               origem, destino);

        return;
    }

    /* Move n-1 para auxiliar */
    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    /* Move o maior disco */
    printf("Mover disco %d de %c para %c\n",
           n, origem, destino);

    /* Move n-1 para destino */
    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}

int main() {

    hanoi(3, 'A', 'C', 'B');

    return 0;
}
