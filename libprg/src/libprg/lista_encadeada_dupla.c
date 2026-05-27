//
// Created by aluno on 05/05/2026.
//

#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct nod {
    int dado;
    struct nod *proximo;
    struct nod *anterior;
}nod_t;
nod_t* criar_encadeada_dupla(nod_t** inicio, int dado) {

}

void inserir_inicio(nod_t **lista, int valor) {

    nod_t *novo = malloc(sizeof(nod_t));

    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = *lista;

    if (*lista != NULL) {
        (*lista)->anterior = novo;
    }

    *lista = novo;
}

bool remover_encadeada_dupla(nod_t** inicio, int dado) {
nod_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (atual->anterior == NULL) *inicio = atual->proximo;
            else {
                  atual->anterior->proximo = atual->proximo;
                 atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return true;
        }

        atual = atual->anterior;
    }
        return true;
}

void *destruir_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t *atual = *inicio;

    while (atual != NULL) {
        nod_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}
