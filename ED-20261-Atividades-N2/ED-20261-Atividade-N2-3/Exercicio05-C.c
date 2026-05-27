RA: 2040482513049 - Anna Beatriz Louro da Silva


#include <stdio.h>
#include <stdlib.h>

/*

                50
              /    \
            30      70
           /  \    /  \
         20   40  60   80
        / \     \    \
      10  25    45   65

*/

/* ========================= */
/* ESTRUTURA DO NO */
/* ========================= */

typedef struct No {

    int dado;

    struct No *esq;
    struct No *dir;

} No;

/* ========================= */
/* INSERIR NA ARVORE */
/* ========================= */

No* inserir(No *raiz, int valor) {

    /* Cria novo no */
    if(raiz == NULL) {

        No *novo = malloc(sizeof(No));

        novo->dado = valor;

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    /* Esquerda */
    if(valor < raiz->dado) {

        raiz->esq =
            inserir(raiz->esq, valor);
    }

    /* Direita */
    else {

        raiz->dir =
            inserir(raiz->dir, valor);
    }

    return raiz;
}

/* ========================= */
/* ALTURA DO NO */
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

    /* Procura esquerda */
    if(valor < raiz->dado) {

        return profundidadeNo(
            raiz->esq,
            valor,
            prof + 1
        );
    }

    /* Procura direita */
    return profundidadeNo(
        raiz->dir,
        valor,
        prof + 1
    );
}

/* ========================= */
/* GRAU DO NO */
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
/* IMPRIMIR GRAUS */
/* ========================= */

void imprimirGraus(No *raiz) {

    if(raiz != NULL) {

        imprimirGraus(raiz->esq);

        printf("No %d -> grau %d\n",
               raiz->dado,
               grauNo(raiz));

        imprimirGraus(raiz->dir);
    }
}

/* ========================= */
/* IMPRIMIR ARVORE */
/* ========================= */

void imprimirArvore(No *raiz,
                    int nivel) {

    if(raiz != NULL) {

        /* Direita */
        imprimirArvore(
            raiz->dir,
            nivel + 1
        );

        /* Espacos */
        for(int i = 0; i < nivel; i++) {
            printf("    ");
        }

        /* Valor */
        printf("%d\n",
               raiz->dado);

        /* Esquerda */
        imprimirArvore(
            raiz->esq,
            nivel + 1
        );
    }
}

/* ========================= */
/* LIBERAR MEMORIA */
/* ========================= */

void liberarArvore(No *raiz) {

    if(raiz != NULL) {

        liberarArvore(raiz->esq);

        liberarArvore(raiz->dir);

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

    printf("====================================\n");
    printf("CONSULTAS ESTRUTURAIS\n");
    printf("====================================\n");

    /* ========================= */
    /* ALTURA */
    /* ========================= */

    printf("\nALTURA DOS NOS:\n");

    printf("Altura do no 50: %d\n",
           alturaNo(raiz));

    printf("Altura do no 30: %d\n",
           alturaNo(raiz->esq));

    printf("Altura do no 70: %d\n",
           alturaNo(raiz->dir));

    printf("Altura do no 20: %d\n",
           alturaNo(raiz->esq->esq));

    printf("Altura do no 10: %d\n",
           alturaNo(raiz->esq->esq->esq));

    /* ========================= */
    /* PROFUNDIDADE */
    /* ========================= */

    printf("\nPROFUNDIDADE DOS NOS:\n");

    printf("Profundidade do no 50: %d\n",
           profundidadeNo(raiz,
                           50,
                           0));

    printf("Profundidade do no 30: %d\n",
           profundidadeNo(raiz,
                           30,
                           0));

    printf("Profundidade do no 70: %d\n",
           profundidadeNo(raiz,
                           70,
                           0));

    printf("Profundidade do no 45: %d\n",
           profundidadeNo(raiz,
                           45,
                           0));

    printf("Profundidade do no 10: %d\n",
           profundidadeNo(raiz,
                           10,
                           0));

    /* ========================= */
    /* GRAU */
    /* ========================= */

    printf("\nGRAU DOS NOS:\n");

    imprimirGraus(raiz);

    /* ========================= */
    /* ALTURA TOTAL */
    /* ========================= */

    printf("\nALTURA TOTAL DA ARVORE: %d\n",
           alturaNo(raiz));

    /* ========================= */
    /* ARVORE FORMATADA */
    /* ========================= */

    printf("\n====================================\n");
    printf("ARVORE FORMATADA\n");
    printf("====================================\n\n");

    imprimirArvore(raiz, 0);

    /* ========================= */
    /* LIBERAR MEMORIA */
    /* ========================= */

    liberarArvore(raiz);

    return 0;
}
