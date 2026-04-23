#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
/*  === PILHA ===*/
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar_pilha(pilha_t* pilha, int valor);
int desempilhar_pilha(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);
int vazia_pilha(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);

/* == FILA == */
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar_fila(fila_t* fila, int valo);
int desenfileirar_fila(fila_t* fila);
int inicio_fila(fila_t* fila);
int fim_fila(fila_t* fila);
int vazia_fila(fila_t* fila);
int tamanho_fila(fila_t* fila);
int cheia_fila(fila_t* fila);
int destruir_fila(fila_t* fila);

// /* == LISTA  == */
// typedef struct lista lista_t;
// lista_t* criar_lista (bool ordenada);


#endif
