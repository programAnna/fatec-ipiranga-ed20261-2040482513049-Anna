RA: 2040482513049 - Anna Beatriz Louro da Silva


int imprimirAncestral(No *raiz, int valor) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->dado == valor) {
        return 1;
    }

    if(imprimirAncestral(raiz->esq,valor)

       ||

       imprimirAncestral(
            raiz->dir,
            valor)) {

        printf("%d ", raiz->dado);

        return 1;
    }

    return 0;
}

void imprimirSubArvore(No *raiz) {

    if(raiz != NULL) {
        imprimirSubArvore(raiz->esq);

        printf("%d ", raiz->dado);

        imprimirSubArvore(raiz->dir);
    }
}


void imprimirDescendentes(No *raiz, int valor) {

    if(raiz == NULL) {
        printf("Valor nao encontrado");
        return;
    }

    if(raiz->dado == valor) {

        imprimirSubArvore(raiz->esq);

        imprimirSubArvore(raiz->dir);
        return;
    }

    if(valor < raiz->dado) {
        imprimirDescendentes( raiz->esq,valor);
    }

    /* Procura direita */
    else {
        imprimirDescendentes(raiz->dir, valor);
    }
}

int contarDescendentes(No *no) {

    if(no == NULL) {
        return 0;
    }

    return 1
           + contarDescendentes(no->esq)
           + contarDescendentes(no->dir);
}
