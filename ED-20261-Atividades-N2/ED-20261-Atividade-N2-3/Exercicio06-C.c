RA: 2040482513049 - Anna Beatriz Louro da Silva


#include <stdio.h>
#include <stdlib.h>

/* ========================= */
/* ESTRUTURA DO NO */
/* ========================= */

typedef struct No {

    int dado;

    struct No *esq;
    struct No *dir;

} No;

/* ========================= */
/* PROTOTIPOS */
/* ========================= */

No* inserir(No *raiz, int valor);

No* buscarNo(No *raiz, int valor);

int alturaNo(No *no);

int profundidadeNo(No *raiz,
                   int valor,
                   int prof);

int grauNo(No *no);

int imprimirAncestral(No *raiz,
                      int valor);

void imprimirSubArvore(No *raiz);

void imprimirDescendentes(No *raiz,
                          int valor);

int contarDescendentes(No *no);

void relatorioNo(No *raiz,
                 int valor);

void liberarArvore(No *raiz);

/* ========================= */
/* INSERIR */
/* ========================= */

No* inserir(No *raiz, int valor) {

    if(raiz == NULL) {

        No *novo = malloc(sizeof(No));

        novo->dado = valor;

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(valor < raiz->dado) {

        raiz->esq =
            inserir(raiz->esq,
                     valor);
    }

    else {

        raiz->dir =
            inserir(raiz->dir,
                     valor);
    }

    return raiz;
}

/* ========================= */
/* BUSCAR NO */
/* ========================= */

No* buscarNo(No *raiz, int valor) {

    if(raiz == NULL) {
        return NULL;
    }

    if(raiz->dado == valor) {
        return raiz;
    }

    if(valor < raiz->dado) {

        return buscarNo(
            raiz->esq,
            valor
        );
    }

    return buscarNo(
        raiz->dir,
        valor
    );
}

/* ========================= */
/* ALTURA */
/* ========================= */

int alturaNo(No *no) {

    if(no == NULL) {
        return -1;
    }

    int alturaEsq =
        alturaNo(no->esq);

    int alturaDir =
        alturaNo(no->dir);

    if(alturaEsq > alturaDir) {

        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

/* ========================= */
/* PROFUNDIDADE */
/* ========================= */

int profundidadeNo(No *raiz,
                   int valor,
                   int prof) {

    if(raiz == NULL) {
        return -1;
    }

    if(raiz->dado == valor) {
        return prof;
    }

    if(valor < raiz->dado) {

        return profundidadeNo(
            raiz->esq,
            valor,
            prof + 1
        );
    }

    return profundidadeNo(
        raiz->dir,
        valor,
        prof + 1
    );
}

/* ========================= */
/* GRAU */
/* ========================= */

int grauNo(No *no) {

    int grau = 0;

    if(no->esq != NULL) {
        grau++;
    }

    if(no->dir != NULL) {
        grau++;
    }

    return grau;
}

/* ========================= */
/* ANCESTRAIS */
/* ========================= */

int imprimirAncestral(No *raiz,
                      int valor) {

    if(raiz == NULL) {
        return 0;
    }

    if(raiz->dado == valor) {
        return 1;
    }

    if(imprimirAncestral(
            raiz->esq,
            valor)

       ||

       imprimirAncestral(
            raiz->dir,
            valor)) {

        printf("%d ",
               raiz->dado);

        return 1;
    }

    return 0;
}

/* ========================= */
/* IMPRIMIR SUBARVORE */
/* ========================= */

void imprimirSubArvore(No *raiz) {

    if(raiz != NULL) {

        imprimirSubArvore(
            raiz->esq);

        printf("%d ",
               raiz->dado);

        imprimirSubArvore(
            raiz->dir);
    }
}

/* ========================= */
/* DESCENDENTES */
/* ========================= */

void imprimirDescendentes(No *raiz,
                          int valor) {

    No *no =
        buscarNo(raiz,
                 valor);

    if(no == NULL) {

        printf("Valor nao encontrado");

        return;
    }

    imprimirSubArvore(no->esq);

    imprimirSubArvore(no->dir);
}

/* ========================= */
/* CONTAR DESCENDENTES */
/* ========================= */

int contarDescendentes(No *no) {

    if(no == NULL) {
        return 0;
    }

    return 1
           + contarDescendentes(no->esq)
           + contarDescendentes(no->dir);
}

/* ========================= */
/* RELATORIO */
/* ========================= */

void relatorioNo(No *raiz,
                 int valor) {

    No *no =
        buscarNo(raiz,
                 valor);

    if(no == NULL) {

        printf("\nValor %d nao encontrado.\n",
               valor);

        return;
    }

    printf("\n+--------------------------------+\n");

    printf("| RELATORIO DO NO: %-12d |\n",
           valor);

    printf("+--------------------------------+\n");

    printf("| Profundidade : %-14d |\n",
           profundidadeNo(
               raiz,
               valor,
               0));

    printf("| Altura       : %-14d |\n",
           alturaNo(no));

    printf("| Grau         : %-14d |\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(
        raiz,
        valor);

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(
        raiz,
        valor);

    printf("\n");

    printf("| Qtd Descend. : %-14d |\n",
           contarDescendentes(no) - 1);

    printf("+--------------------------------+\n");
}

/* ========================= */
/* LIBERAR MEMORIA */
/* ========================= */

void liberarArvore(No *raiz) {

    if(raiz != NULL) {

        liberarArvore(
            raiz->esq);

        liberarArvore(
            raiz->dir);

        free(raiz);
    }
}

/* ========================= */
/* MAIN */
/* ========================= */

int main() {

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    No *raiz = NULL;

    /* Inserindo valores */

    for(int i = 0; i < 11; i++) {

        raiz = inserir(
            raiz,
            valores[i]
        );
    }

    /* ========================= */
    /* PARTE C */
    /* TESTE SISTEMATICO */
    /* ========================= */

    printf("\n====================================\n");
    printf("TESTE SISTEMATICO\n");
    printf("====================================\n");

    /* Raiz */
    relatorioNo(raiz, 50);

    /* No intermediario */
    relatorioNo(raiz, 30);

    /* Folha */
    relatorioNo(raiz, 10);

    /* Outro no intermediario */
    relatorioNo(raiz, 70);

    /* ========================= */
    /* LIBERAR MEMORIA */
    /* ========================= */

    liberarArvore(raiz);

    return 0;
}
