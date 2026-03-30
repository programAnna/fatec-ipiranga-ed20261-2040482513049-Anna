#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// criando a estrutura da pilha HP12c: X, Y, Z e T
typedef struct {
    float X;
    float Y;
    float Z;
    float T;
} PilhaHP;

void inicializar(PilhaHP *p) {
    p->X = p->Y = p->Z = p->T = 0;
}

// Void para imprimir o estado da pilha
void imprimir(PilhaHP *p) {
    printf("\n--- PILHA ---\n");
    printf("T: %.2f\n", p->T);
    printf("Z: %.2f\n", p->Z);
    printf("Y: %.2f\n", p->Y);
    printf("X: %.2f\n", p->X);
    printf("-------------\n");
}

// Void para inserir número no estilo HP12c
void pushNumero(PilhaHP *p, float valor) {
    p->T = p->Z;
    p->Z = p->Y;
    p->Y = p->X;
    p->X = valor;
}

void soma(PilhaHP *p) {
    p->X = p->Y + p->X;
    p->Y = p->Z;
    p->Z = p->T;
}

void subtracao(PilhaHP *p) {
    p->X = p->Y - p->X;
    p->Y = p->Z;
    p->Z = p->T;
}

void multiplicacao(PilhaHP *p) {
    p->X = p->Y * p->X;
    p->Y = p->Z;
    p->Z = p->T;
}

void divisao(PilhaHP *p) {
    if (p->X == 0) {
        printf("Erro: Divisao por zero!\n");
        exit(1);
    }
    p->X = p->Y / p->X;
    p->Y = p->Z;
    p->Z = p->T;
}

int main() {
    PilhaHP p;
    inicializar(&p);

    char expressao[100];

    printf("Digite a expressao matematica no estilo RPN:\n");
    fgets(expressao, sizeof(expressao), stdin);

    char *token = strtok(expressao, " \n");

    while (token != NULL) {
        printf("\nEntrada: %s\n", token);

        if (ehNumero(token)) {
            float valor = atof(token);
            pushNumero(&p, valor);
        } else {
            if (strcmp(token, "+") == 0) {
                soma(&p);
            } else if (strcmp(token, "-") == 0) {
                subtracao(&p);
            } else if (strcmp(token, "*") == 0) {
                multiplicacao(&p);
            } else if (strcmp(token, "/") == 0) {
                divisao(&p);
            } else {
                printf("Erro: operador invalido (%s)\n", token);
                return 1;
            }
        }

        imprimir(&p);
        token = strtok(NULL, " \n");
    }

    printf("\nResultado final: %.2f\n", p.X);

    return 0;
}
