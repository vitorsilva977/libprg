#include <stdbool.h>
#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
/*  === PILHA ===*/
typedef struct pilha pilha_t;
pilha_t *criar_pilha(int capacidade);
int empilhar_pilha(pilha_t *pilha, int valor);
int desempilhar_pilha(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);
int vazia_pilha(pilha_t *pilha);
int destruir_pilha(pilha_t *pilha);

/* == FILA == */
typedef struct fila fila_t;
fila_t *criar_fila(int capacidade);
void enfileirar_fila(fila_t *fila, int valo);
int desenfileirar_fila(fila_t *fila);
int inicio_fila(fila_t *fila);
int fim_fila(fila_t *fila);
int vazia_fila(fila_t *fila);
int tamanho_fila(fila_t *fila);
int cheia_fila(fila_t *fila);
int destruir_fila(fila_t *fila);

// /* == LISTA  == */
typedef struct lista lista_t;
lista_t *criar_lista(bool ordenada);
bool inserir(lista_t *lista, int elementos);
int remover(lista_t *lista);
int busca_linear(lista_t *lista, int elementos);
int alterar(lista_t *lista, int elementoAntigo, int elementoNovo);
int ordenar(lista_t *lista);
int busca_binaria(lista_t *lista, int elemento);
lista_t *combinar(lista_t *a, lista_t *b);
int obter_elemento(lista_t *lista, int indice);
int primeiro_elemento(lista_t *lista);
int tamanho_lista(lista_t *lista);
void destruir(lista_t *lista);

/*   == LISTA_ENCADEADA == */
typedef struct no no_t;
typedef struct lista_encadeada lista_encadeada_t;
no_t *criar_no(int dado);
lista_encadeada_t *criar_lista_encadeada(bool ordenada);
void inserir_encadeada(lista_encadeada_t *lista, int dado);
bool remover_encadeada(lista_encadeada_t *lista, int dado);
int tamanho_encadeada(lista_encadeada_t *lista);
int primeiro_encadeada(lista_encadeada_t *lista);
no_t *buscar_encadeada(lista_encadeada_t *lista, int dado);

void imprimir_encadeada(lista_encadeada_t *lista);
void destruir_encadeada(lista_encadeada_t *lista);


/* == LISTA_ENCADEADA_DUPLA == */
typedef struct nod nod_t;
void inserir_inicio(nod_t **lista, int valor);
bool remover_encadeada_dupla(nod_t **inicio, int dado);
void *destruir_encadeada_dupla(nod_t **inicio, int dado);

/*  == ALGORITMOS DE ORDENAÇÃO == */
int *bubble_sort(int *vetor, int tamanho);
int *selection_sort(int *vetor, int tamanho);
int *insertion_sort(int *vetor, int tamanho);
int *merge_sort(int *vetor, int esquerda, int direita);
int *merge(int *veitor, int esquerda, int meio, int direita);
int particiona(int *vetor, int inicio, int fim);
int *quicksort(int *vetor, int inicio, int fim);

/*   == TABELA DE DISPERÇÃO ==   */
typedef struct noh noh_t;
typedef struct dicionario dicionario_t;
dicionario_t *criar_dicionario(int m);
int inserir_hash(dicionario_t *d, char *chave, int valor);
int buscar_hash(dicionario_t *d, char *chave);
void imprimir_hash(dicionario_t *d);
void remover_hash(dicionario_t *d, char *chave);
void liberar_dicionario(dicionario_t *d);

/*  == ARVORE == */
typedef struct no_arvore no_arvore_t;
no_arvore_t *criar_no_arvore(int dado);
no_arvore_t *adicionar_no_arvore(no_arvore_t *raiz, int dado);
no_arvore_t *remover_arvore(no_arvore_t *raiz, int valor);
no_arvore_t *menor_no(no_arvore_t *no);
void travessia_pre_ordem(no_arvore_t *raiz);
void travessia_emordem(no_arvore_t *raiz);
void travessia_posordem(no_arvore_t *raiz);

/* == ARVORE AVL == */
typedef  struct noavl noavl_t;
noavl_t *criar_noavl(int dado);
int altura_avl(noavl_t * raiz);
int fator_balanceamento_avl(noavl_t * raiz);
noavl_t* remover_noavl(noavl_t *raiz, int dado);
noavl_t* adicionar_noavl(noavl_t *raiz, int dado);
noavl_t* rotacao_esquerda(noavl_t* v);
noavl_t* rotacao_direita(noavl_t* v);
noavl_t* rotacao_dupla_esquerda(noavl_t* v);
noavl_t* rotacao_direita_dupla(noavl_t* v);
noavl_t* balancear(noavl_t* v);


#endif
