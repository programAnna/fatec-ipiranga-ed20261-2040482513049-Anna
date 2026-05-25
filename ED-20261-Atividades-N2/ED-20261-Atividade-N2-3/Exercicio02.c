RA: 2040482513049 - Anna Beatriz Louro da Silva

#include <stdio.h>

void imprimirVetor(float *vet, int n) {

    printf("Notas:\n");

    for(int i = 0; i < n; i++) {
        printf("%.2f\n", *vet);
        vet++;
    }

    printf("-------------------\n");
}

float calcularMedia(float *vet, int n) {

    float soma = 0;

    for(int i = 0; i < n; i++) {
        soma += *vet;
        vet++;
    }

    return soma / n;
}

void encontrarExtremos(float *vet, int n,
                       float *maior, float *menor) {

    *maior = *vet;
    *menor = *vet;

    for(int i = 0; i < n; i++) {

        if(*vet > *maior) {
            *maior = *vet;
        }

        if(*vet < *menor) {
            *menor = *vet;
        }

        vet++;
    }
}

void normalizar(float *vet, int n) {

    float maior = *vet;

    float *ptr = vet;

    for(int i = 0; i < n; i++) {

        if(*ptr > maior) {
            maior = *ptr;
        }

        ptr++;
    }

    ptr = vet;

    for(int i = 0; i < n; i++) {

        *ptr = *ptr / maior;

        ptr++;
    }
}

int main() {

    float notas[] = {
        7.5f, 3.2f, 9.8f,
        6.0f, 5.5f, 8.1f
    };

    float maior, menor;

    imprimirVetor(notas, 6);

    printf("Media: %.2f\n",
           calcularMedia(notas, 6));

    encontrarExtremos(notas, 6,
                       &maior, &menor);

    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);

    normalizar(notas, 6);

    imprimirVetor(notas, 6);

    return 0;
}
