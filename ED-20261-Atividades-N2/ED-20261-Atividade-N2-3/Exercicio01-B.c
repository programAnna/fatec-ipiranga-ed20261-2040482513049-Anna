#include <stdio.h>

int main() {

    int v[] = {10, 20, 30, 40, 50};

    // Criando ponteiro para percorrer o vetor
    int *p;
    // printar  valor e endereço
    printf("Elementos e enderecos do vetor:\n");
    for(p = v; p < v + 5; p++) {
        // *p acessa o valor armazenado no endereco apontado por p
        // p representa o endereco atual
        printf("Valor: %d | Endereco: %p\n", *p, p);
    }
    // Soma dos elementos
    int soma = 0;
    for(p = v; p < v + 5; p++) {

        // *p pega o valor apontado por p
        soma += *p;
    }

    printf("\nSoma dos elementos: %d\n", soma);

    // Inverter vetor in-place
    // inicio aponta para o primeiro elemento
    int *inicio = v;
    // fim aponta para o ultimo elemento
    int *fim = v + 4;

    int temp;
    while(inicio < fim) {
        // Guarda o valor apontado por inicio
        temp = *inicio;
        // Copia o valor do fim para o inicio
        *inicio = *fim;
        // Coloca o valor antigo do inicio no fim
        *fim = temp;
        // Avanca para o proximo elemento
        inicio++;
        fim--;
    }

    // Mostrar vetor invertido
    printf("\nVetor invertido:\n");
    for(p = v; p < v + 5; p++) {
        // *p acessa o valor apontado por p
        printf("%d ", *p);
    }
