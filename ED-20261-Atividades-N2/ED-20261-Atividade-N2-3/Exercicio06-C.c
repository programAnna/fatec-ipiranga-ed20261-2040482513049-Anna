RA: 2040482513049 - Anna Beatriz Louro da Silva


#include <stdio.h>
#include <stdlib.h>

void relatorioNo(No *raiz, int valor) {

    No *no = buscarNo(raiz, valor);

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
           profundidadeNo(raiz,
                           valor,
                           0));

    printf("| Altura       : %-14d |\n",
           alturaNo(no));

    printf("| Grau         : %-14d |\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(raiz,
                      valor);

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(raiz,
                         valor);

    printf("\n");

    printf("| Qtd Descend. : %-14d |\n",
           contarDescendentes(no) - 1);

    printf("+--------------------------------+\n");
}

int main() {

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    No *raiz = NULL;

    /* Inserindo na ABB */

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
