RA: 2040482513049 - Anna Beatriz Louro da Silva

#include <stdio.h>

int chamadas = 0;

int buscaBinaria(int *vet,
                 int inicio,
                 int fim,
                 int alvo) {

    chamadas++;

    /* Caso base */
    if(inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    /* Encontrou */
    if(vet[meio] == alvo) {
        return meio;
    }

    /* Busca esquerda */
    if(alvo < vet[meio]) {

        return buscaBinaria(vet,
                            inicio,
                            meio - 1,
                            alvo);
    }

    /* Busca direita */
    return buscaBinaria(vet,
                        meio + 1,
                        fim,
                        alvo);
}

int main() {

    int dados[] = {
        2, 5, 8, 12, 16,
        23, 38, 45, 72, 91
    };

    int tamanho = 10;

    int valores[] = {23, 50, 2};

    printf("====================================\n");
    printf("Valor | Resultado | Chamadas\n");
    printf("====================================\n");

    for(int i = 0; i < 3; i++) {

        chamadas = 0;

        int resultado = buscaBinaria(dados,
                                     0,
                                     tamanho - 1,
                                     valores[i]);

        printf("%5d | %9d | %9d\n",
               valores[i],
               resultado,
               chamadas);
    }

    return 0;
}
