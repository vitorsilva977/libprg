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


//inserir
remover(lista_t* lista, int alvo) {
    int indice = buscar(lista, alvo);


}
//buscar simples  if (lista->ordenada) {
// indice = busca_binario
// } else {
//     indice = busca_linear
// }
// busca_linear
//busca_binario
//alterar
//ordenar
//combinar
//destruir


//TODO implementar buscar_linear e buscar_binario