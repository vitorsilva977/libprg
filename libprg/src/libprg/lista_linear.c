//
// Created by vitor on 07/04/2026.
//
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

#define CAPACIDADE_INICIAL 10

typedef struct lista {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_t *criar_lista(bool ordenada) {
    lista_t *lista = malloc(sizeof(lista_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}


bool inserir(lista_t *lista, int elementos) {
    if (lista->tamanho == lista->capacidade) {
        return false;
    }
    lista->elementos[lista->tamanho] = elementos;
    lista->tamanho = lista->tamanho + 1;
    return true;
}

int remover(lista_t *lista) {
    if (lista->tamanho == 0) {
        return false;
    }
    lista->tamanho = lista->tamanho - 1;
    return true;
}
int primeiro_elemento(lista_t *lista) {

    if (lista == NULL || lista->tamanho == 0)
        return -1;

    return lista->elementos[0];
}

int tamanho_lista(lista_t *lista) {

    if (lista == NULL)
        return 0;

    return lista->tamanho;
}
int busca_linear(lista_t *lista, int elementos) {
    if (lista->ordenada) {
        for (int i = 0; i < lista->tamanho; i++) {
            if (lista->elementos[i] == elementos) {
                return i;
            }
            if (lista->elementos[i] > elementos) {
                return -1;
            }
        }
    } else {
        for (int i = 0; i < lista->tamanho; i++) {
            if (lista->elementos[i] == elementos) {
                return i;
            }
        }
    }
    return -1;
}

int busca_binaria(lista_t *lista, int elemento) {
    if (lista == NULL || lista->tamanho == 0) {
        return -1;
    }

    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == elemento) {
            return meio;
        }

        if (lista->elementos[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int alterar(lista_t *lista, int elementoAntigo, int elementoNovo) {
    if (lista->ordenada) {
        for (int i = 0; i < lista->tamanho; i++) {
            if (lista->elementos[i] == elementoAntigo) {
                lista->elementos[i] = elementoNovo;
                return true;
            }

            if (lista->elementos[i] > elementoAntigo) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < lista->tamanho; i++) {
            if (lista->elementos[i] == elementoAntigo) {
                lista->elementos[i] = elementoNovo;
                return true;
            }
        }
    }

    return false;
}

int ordenar(lista_t *lista) {
    for (int i = 0; i < lista->tamanho - 1; i++) {
        for (int j = 0; j < lista->tamanho - i - 1; j++) {
            if (lista->elementos[j] > lista->elementos[j + 1]) {
                int aux = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j + 1];
                lista->elementos[j + 1] = aux;
            }
        }
    }
    return 1;
}

int obter_elemento(lista_t *lista, int indice) {

    if (lista == NULL)
        return -1;

    if (indice < 0 || indice >= lista->tamanho)
        return -1;

    return lista->elementos[indice];
}

lista_t *combinar(lista_t *a, lista_t *b) {
    lista_t *nova = malloc(sizeof(lista_t));

    nova->tamanho = a->tamanho + b->tamanho;
    nova->capacidade = nova->tamanho;
    nova->ordenada = a->ordenada && b->ordenada;

    nova->elementos = malloc(sizeof(int) * nova->capacidade);

    int k = 0;

    for (int i = 0; i < a->tamanho; i++) {
        nova->elementos[k++] = a->elementos[i];
    }


    for (int i = 0; i < b->tamanho; i++) {
        nova->elementos[k++] = b->elementos[i];
    }

    return nova;
}

void destruir(lista_t *lista) {
    if (lista == NULL) return;

    free(lista->elementos);
    free(lista);
}
