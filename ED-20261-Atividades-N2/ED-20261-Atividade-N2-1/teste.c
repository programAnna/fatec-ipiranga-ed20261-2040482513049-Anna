//entregar um .c e um pdf - infografico//

#include <stdio.h>
#include <stdlib.h>
#include "minhalib.h"

typedef struct No {
    int conteudo;
    No*esq;
    No* dir;
} No;

void criarArvore(No **pRaiz)
{
    *pRaiz = null; // quando criar a árvore o valor da raiz eh nulo
}

void insercao(No **pRaiz, int num)
{
    if(*pRaiz == null)
    {
        *pRaiz = (noh *) malloc(sizeof (noh));
        (*pRaiz)->esq = null;
        (*pRaiz)->dir = null;
        (*pRaiz)->num=num2; //passa o endereco da raiz p o valor
    }
    else{   //se a raiz n for nula, vai identificar p qual lado o valor vai
        if(num2<((*pRaiz)->num))
        {
            insercao(&((*pRaiz)->esq), num2);
        }
        else{
            insercao(&((*pRaiz)->dir), num2);            }
        }
    }
}
