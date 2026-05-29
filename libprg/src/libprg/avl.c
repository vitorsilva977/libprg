//
// Created by aluno on 28/05/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noavl {
    int dado;
    struct noavl *esquerda;
    struct noavl *direita;
    int altura;
} noavl_t;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura_avl(noavl_t *raiz) {
    if (raiz == NULL)
        return -1;

    return raiz->altura;
}

int fator_balanceamento_avl(noavl_t *raiz) {
    if (raiz == NULL)
        return 0;

    return altura_avl(raiz->esquerda) -
           altura_avl(raiz->direita);
}

noavl_t *criar_noavl(int dado) {
    noavl_t *novo = malloc(sizeof(noavl_t));

    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 0;

    return novo;
}


noavl_t *rotacao_direita(noavl_t *v) {
    noavl_t *u = v->esquerda;
    noavl_t *t2 = u->direita;

    u->direita = v;
    v->esquerda = t2;

    v->altura = 1 + max(
                    altura_avl(v->esquerda),
                    altura_avl(v->direita)
                );

    u->altura = 1 + max(
                    altura_avl(u->esquerda),
                    altura_avl(u->direita)
                );

    return u;
}

noavl_t *rotacao_esquerda(noavl_t *v) {
    noavl_t *u = v->direita;
    noavl_t *t2 = u->esquerda;

    u->esquerda = v;
    v->direita = t2;

    v->altura = 1 + max(
                    altura_avl(v->esquerda),
                    altura_avl(v->direita)
                );

    u->altura = 1 + max(
                    altura_avl(u->esquerda),
                    altura_avl(u->direita)
                );

    return u;
}

noavl_t *rotacao_dupla_esquerda(noavl_t *v) {
    v->direita = rotacao_direita(v->direita);

    return rotacao_esquerda(v);
}

noavl_t *rotacao_direita_dupla(noavl_t *v) {
    v->esquerda = rotacao_esquerda(v->esquerda);

    return rotacao_direita(v);
}


noavl_t *balancear(noavl_t *v) {
    int fb = fator_balanceamento_avl(v);


    if (fb > 1) {
        if (fator_balanceamento_avl(v->esquerda) >= 0)
            return rotacao_direita(v);

        else
            return rotacao_direita_dupla(v);
    }


    if (fb < -1) {
        if (fator_balanceamento_avl(v->direita) <= 0)
            return rotacao_esquerda(v);

        else
            return rotacao_dupla_esquerda(v);
    }

    return v;
}


noavl_t *adicionar_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL)
        return criar_noavl(dado);

    if (dado < raiz->dado)
        raiz->esquerda =
                adicionar_noavl(raiz->esquerda, dado);

    else if (dado > raiz->dado)
        raiz->direita =
                adicionar_noavl(raiz->direita, dado);

    else
        return raiz;

    raiz->altura = 1 + max(
                       altura_avl(raiz->esquerda),
                       altura_avl(raiz->direita)
                   );

    return balancear(raiz);
}

noavl_t *remover_noavl(noavl_t *raiz, int dado) {

    if (raiz == NULL)
        return NULL;

    if (dado < raiz->dado) {

        raiz->esquerda =
                remover_noavl(raiz->esquerda, dado);

    } else if (dado > raiz->dado) {

        raiz->direita =
                remover_noavl(raiz->direita, dado);

    } else {

        /* nó com 0 ou 1 filho */
        if (raiz->esquerda == NULL ||
            raiz->direita == NULL) {

            noavl_t *temp;

            if (raiz->esquerda != NULL)
                temp = raiz->esquerda;
            else
                temp = raiz->direita;

            /* sem filhos */
            if (temp == NULL) {

                temp = raiz;
                raiz = NULL;

            } else {

                *raiz = *temp;
            }

            free(temp);

            } else {

                /* nó com 2 filhos */

                noavl_t *temp = raiz->direita;

                while (temp->esquerda != NULL)
                    temp = temp->esquerda;

                raiz->dado = temp->dado;

                raiz->direita =
                        remover_noavl(
                                raiz->direita,
                                temp->dado
                        );
            }
    }

    if (raiz == NULL)
        return NULL;

    raiz->altura = 1 + max(
            altura_avl(raiz->esquerda),
            altura_avl(raiz->direita)
    );

    return balancear(raiz);
}