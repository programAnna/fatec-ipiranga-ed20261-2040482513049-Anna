RA: 2040482513049 - Anna Beatriz Louro da Silva

#include <stdio.h>

void trocar(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {

    int x = 10;
    int y = 20;

    // printar antes da troca
    printf("Vendo antes da troca:\n");
    printf("Endereco de x: %p\n", &x);
    printf("Valor de x: %d\n", x);

    printf("Endereco de y: %p\n", &y);
    printf("Valor de y: %d\n\n", y);

    // fazendo a troca - chamando o procedimento
    trocar(&x, &y);

    // depois da troca
    printf("Vendo depois da troca:\n");
    printf("Endereco de x: %p\n", &x);
    printf("Valor de x: %d\n", x);

    printf("Endereco de y: %p\n", &y);
    printf("Valor de y: %d\n", y);

    return 0;
}
