#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct no_arvore {
    int dado;
    no_arvore_t *esquerda;
    no_arvore_t *direita;
} no_arvore_t;

no_arvore_t *criar_no_arvore(int dado) {
    no_arvore_t *no = malloc(sizeof(no_arvore_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

no_arvore_t *adicionar_no_arvore(no_arvore_t *raiz, int dado) {

    if (raiz == NULL) {
        return criar_no_arvore(dado);
    }


    if (raiz->dado < dado) {
        raiz->direita = adicionar_no_arvore(raiz->direita, dado);
    }
    if (raiz->dado > dado) {
        raiz->esquerda = adicionar_no_arvore(raiz->esquerda, dado);
    }

    return raiz;
}

//remover
//destruir
