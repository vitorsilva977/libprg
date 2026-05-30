//
// Created by aluno on 26/03/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} fila_t;

fila_t* criar_fila(int capacidade) {

    fila_t* fila = malloc (sizeof(fila_t));
    fila->elementos = malloc (sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}
void enfileirar_fila(fila_t* fila, int valor) {

    if (cheia_fila(fila))
        return;

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar_fila(fila_t* fila) {
    if (vazia_fila(fila))
        return -1;

    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;

    return valor;
}

int inicio_fila(fila_t* fila) {

    if (fila == NULL || vazia_fila(fila))
        return -1;

    return fila->elementos[fila->inicio];
}

int fim_fila(fila_t* fila) {

    if (vazia_fila(fila))
        return -1;

    int fim_corrigido = fila->fim - 1;
    if (fim_corrigido < 0)
        fim_corrigido = fila->capacidade - 1;

    return fila->elementos[fim_corrigido];
}

int vazia_fila(fila_t* fila) {
    return fila->tamanho == 0;
}

int tamanho_fila(fila_t* fila) {
    int tamanho_fila = fila->tamanho;
    return tamanho_fila;
}
int cheia_fila(fila_t* fila) {
    return fila->tamanho == fila->capacidade;
}

int destruir_fila(fila_t* fila) {

    if (fila == NULL)
        return 0;

    free(fila->elementos);
    free(fila);

    return 1;
}