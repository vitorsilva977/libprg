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
        int menor = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge_sort(vetor, esquerda, m)
    }
}
int* merge(int* veitor, int esquerda,int meio, int direita)
//quicksort