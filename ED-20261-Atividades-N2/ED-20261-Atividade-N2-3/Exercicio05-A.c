RA: 2040482513049 - Anna Beatriz Louro da Silva


#include <stdio.h>

typedef struct No {

    int dado;

    struct No *esq;
    struct No *dir;

} No;

No* inserir(No *raiz, int valor) {

    // Criando novo no 
    if(raiz == NULL) {

        No *novo = malloc(sizeof(No));

        novo->dado = valor;

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    // esquerda
    if(valor < raiz->dado) {

        raiz->esq =
            inserir(raiz->esq, valor);
    }

    // direita
    else {

        raiz->dir =
            inserir(raiz->dir, valor);
    }

    return raiz;
}
