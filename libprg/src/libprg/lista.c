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
