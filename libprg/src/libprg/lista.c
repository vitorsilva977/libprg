//
// Created by vitor on 07/04/2026.
//
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct lista {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_t;

lista_t* criar_lista (int capacidade, bool ordenada) {
    lista_t* lista = (lista_t*) malloc(sizeof(lista_t));
    if (lista == NULL) return NULL;

    lista->elementos = (int*) malloc(sizeof(int) * capacidade);
    if (lista->elementos == NULL) {
        free (lista);
        return NULL;
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
    return lista;
}

void adicionar_a_lista(lista_t* lista, int valor) {
    if (lista->tamanho >= lista->capacidade) {
        int nova_capacidade = lista->capacidade * 2;

        int* temp = (int*) realloc(lista->elementos, sizeof(int) * nova_capacidade);
        if (temp == NULL) return; // falhou, não altera nada

        lista->elementos = temp;
        lista->capacidade = nova_capacidade;
    }

    if (lista->ordenada && lista->tamanho > 0) {
        int i = lista->tamanho - 1;
        while (i >= 0 && valor < lista->elementos[i]) {
            lista->elementos[i + 1] = lista->elementos[i];
            i--;
        }
        lista->elementos[i + 1] = valor;
    } else {
        lista->elementos[lista->tamanho] = valor;
    }

    lista->tamanho++;
}
