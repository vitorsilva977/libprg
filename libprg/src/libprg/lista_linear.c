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
} lista_t;

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

int buscar(lista_t *lista, int elementos) {
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



//busca_binario
// } else {
//     indice = busca_linear
// }
// busca_linear
//busca_binario

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
//combinar
//destruir


//TODO implementar buscar_linear e buscar_binario