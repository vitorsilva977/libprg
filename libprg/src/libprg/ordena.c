#include "libprg/libprg.h"

int* bubble_sort(int* vetor, int tamanho) {
    int aux = 0;
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
return vetor;
}


//insertion_sort
//selection_sort
int* merge_sort(int* vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge_sort(vetor, esquerda, meio);
    }
}
int* merge(int* vetor, int esquerda, int meio, int direita) {

    int aux[direita - esquerda + 1];

    int i = esquerda;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= direita) {

        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i = i + 1;

        } else {
            aux[k] = vetor[j];
            j = j + 1;
        }

        k = k + 1;
    }

    while (i <= meio) {
        aux[k] = vetor[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= direita) {
        aux[k] = vetor[j];
        j = j + 1;
        k = k + 1;
    }

    for (i = esquerda; i <= direita; i++) {
        vetor[i] = aux[i - esquerda];
    }

    return vetor;
}
#include <stdio.h>
#include <stdio.h>

void troca_posicao(int *i, int *i1);

int* quicksort(int* vetor, int inicio, int fim) {

    int pivo;

    if (inicio < fim) {

        pivo = particiona(vetor, inicio, fim);

        quicksort(vetor, inicio, pivo - 1);

        quicksort(vetor, pivo + 1, fim);
    }

    return vetor;
}

int particiona(int* vetor, int inicio, int fim) {

    int pivo;
    int j;

    pivo = vetor[fim];

    int i = inicio - 1;

    for (j = inicio; j <= fim - 1; j++) {

        if (vetor[j] <= pivo) {

            i = i + 1;

            troca_posicao(&vetor[i], &vetor[j]);
        }
    }

    i = i + 1;

    troca_posicao(&vetor[i], &vetor[fim]);

    return i;
}

void troca_posicao(int *i, int *i1) {

    int aux;

    aux = *i;
    *i = *i1;
    *i1 = aux;
}
