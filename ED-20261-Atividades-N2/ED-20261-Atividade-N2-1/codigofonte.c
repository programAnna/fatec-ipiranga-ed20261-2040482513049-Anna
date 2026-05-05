#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }

    printf("DIAGNÓSTICO GERAL\n\n");

    printf("Raiz: %d\n\n", raiz->valor);

    printf("Nós Internos:\n");
    imprimir_nos_internos(raiz);

    printf("Nós Folha:\n");
    imprimir_folhas(raiz);

    printf("Nós por Nível:\n");
    imprimir_niveis(raiz, 0);

    printf("\n DIAGNÓSTICO ESPECÍFICO (valorBusca = %d) \n\n", valorBusca);

    No* alvo = raiz;

    while (alvo != NULL && alvo->valor != valorBusca) {
        if (valorBusca < alvo->valor)
            alvo = alvo->esq;
        else
            alvo = alvo->dir;
    }

    if (alvo == NULL) {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
        return;
    }

    int grau = 0;
    if (alvo->esq != NULL) grau++;
    if (alvo->dir != NULL) grau++;

    printf("Grau: %d filho(s)\n", grau);
    printf("Altura: %d\n", calcular_altura(alvo));
    printf("Profundidade: %d\n", calcular_profundidade(raiz, valorBusca, 0));

    printf("\nAncestrais:\n");
    imprimir_ancestrais(raiz, valorBusca);

    printf("\nDescendentes:\n");
    if (alvo->esq == NULL && alvo->dir == NULL)
        printf("(nenhum — é um nó folha)\n");
    else
        imprimir_descendentes(alvo);

    printf("\n SUB-ÁRVORE COM RAIZ EM %d \n\n", valorBusca);
    imprimir_niveis(alvo, 0);
}

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    if (raiz == NULL) return;

    printf("Nível %d: %d\n", nivel_atual, raiz->valor);

    imprimir_niveis(raiz->esq, nivel_atual + 1);
    imprimir_niveis(raiz->dir, nivel_atual + 1);
}

int calcular_altura(No* no) {
    if (no == NULL) return -1;

    int alturaEsq = calcular_altura(no->esq);
    int alturaDir = calcular_altura(no->dir);

    if (alturaEsq > alturaDir)
        return alturaEsq + 1;
    else
        return alturaDir + 1;
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL) return -1;

    if (raiz->valor == valor)
        return profundidade_atual;

    if (valor < raiz->valor)
        return calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    else
        return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL) return;

    if (raiz->valor == valor) return;

    printf("%d ", raiz->valor);

    if (valor < raiz->valor)
        imprimir_ancestrais(raiz->esq, valor);
    else
        imprimir_ancestrais(raiz->dir, valor);
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;

    if (no->esq != NULL) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if (no->dir != NULL) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}
