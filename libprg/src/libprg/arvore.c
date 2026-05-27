#include <stdio.h>
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

no_arvore_t *remover_arvore(no_arvore_t *raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->dado)
        raiz->esquerda = remover_arvore(raiz->esquerda, valor);

    else if (valor > raiz->dado)
        raiz->direita = remover_arvore(raiz->direita, valor);

    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        if (raiz->esquerda == NULL) {
            no_arvore_t *temp = raiz->direita;
            free(raiz);
            return temp;
        }

        if (raiz->direita == NULL) {
            no_arvore_t *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        no_arvore_t *temp = menor_no(raiz->direita);

        raiz->dado = temp->dado;

        raiz->direita = remover_arvore(raiz->direita, temp->dado);
    }

    return raiz;
}

no_arvore_t *menor_no(no_arvore_t *no) {
    no_arvore_t *atual = no;

    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

void destruir_arvore(no_arvore_t *raiz) {
    if (raiz == NULL) return;
    destruir_arvore(raiz->esquerda);
    destruir_arvore(raiz->direita);
    free(raiz);
}

void travessia_pre_ordem(no_arvore_t *raiz) {

    if (raiz == NULL)
        return;

    printf("%d ", raiz->dado);
    travessia_pre_ordem(raiz->esquerda);
    travessia_pre_ordem(raiz->direita);
}

void travessia_emordem(no_arvore_t *raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem(raiz->direita);
    }
}

void travessia_posordem(no_arvore_t *raiz) {
    if (raiz == NULL)
        return;

    travessia_posordem(raiz->esquerda);
    travessia_posordem(raiz->direita);
    printf("%d ", raiz->dado);
}
