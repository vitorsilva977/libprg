#include <stdlib.h>
#include <string.h>
#include <libprg/libprg.h>

typedef struct noh {
    char *chave;
    int valor;
    noh_t *proximo;
} noh_t;

typedef struct dicionario {
    int tamanho;
    noh_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d;
    if (m < 1) return NULL;

    d = malloc(sizeof(dicionario_t));
    d->vetor = malloc(sizeof(noh_t *) * m);
    d->tamanho = m;

    return d;
}

int hash(char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; ++i) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

int inserir_hash(dicionario_t *d, char *chave, int valor) {
    int indice = hash(chave, d->tamanho);
    noh_t *no = malloc(sizeof(noh_t));
    if (no == NULL) return 1;


    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return 1;
    }

    no->valor = valor;

    no->proximo = NULL;

    d->vetor[indice] = no;
    return 0;
}

int buscar_hash(dicionario_t *d, char *chave) {

    int indice = hash(chave, d->tamanho);

    noh_t *atual = d->vetor[indice];

    while (atual != NULL) {

        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }

        atual = atual->proximo;
    }

    return -1;
}


void remover_hash(dicionario_t *d, char *chave) {

    int indice = hash(chave, d->tamanho);

    noh_t *atual = d->vetor[indice];
    noh_t *anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->chave, chave) == 0) {

            if (anterior == NULL) {
                d->vetor[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual->chave);
            free(atual);

            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}

void liberar_dicionario(dicionario_t *d) {

    for (int i = 0; i < d->tamanho; i++) {

        noh_t *atual = d->vetor[i];

        while (atual != NULL) {

            noh_t *temp = atual;

            atual = atual->proximo;

            free(temp->chave);
            free(temp);
        }
    }

    free(d->vetor);
    free(d);
}