#include <stdio.h>
#include <stdlib.h>
#include "arvoreLLRB.h"

#define RED 1
#define BLACK 0


struct informacao{
    int codigo;
    char nome[100];
    int idade;
    char empresa[30];
    char depto[30];
    float salario;
};

struct NO{
    struct informacao info;
    int cor;
    struct NO *esq;
    struct NO *dir;
};

ArvLLRB *cria_ArvLLRB(){
    ArvLLRB *raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(*raiz != NULL){
            *raiz = NULL;
    }
    return raiz;
}


void liberar_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}


int vazia_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
    int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

int consulta_arvLLRB(ArvLLRB *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info.codigo){
            return 1;
        }
        if(valor>atual->info.codigo){
            atual=atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

/*FUNÇÕES DA ARVORE LLRB*/

int cor(struct NO *H){
    if(H == NULL){
        return BLACK;
    }else{
        return H->cor;
    }
}

void trocaCor(struct NO *H){
    H->cor = !H->cor;
    if(H->esq != NULL){
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL){
        H->dir->cor = !H->dir->cor;
    }
}

struct NO *rotacionaEsquerda(struct NO *A){
    struct NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *rotacionaDireita(struct NO *A){
    struct NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *move2EsqRED(struct NO *H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO *move2DirRED(struct NO *H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO *balancear(struct NO *H){
    if(cor(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED){
        rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    return H;
}

struct NO *insereNO(struct NO *H, int valor, int *resp){
    if( H == NULL){
            struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
           *resp = 0;
           return NULL;
        }
        novo->info.codigo = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    if(valor == H->info.codigo){
        *resp = 0;
    }else{
        if(valor < H->info.codigo){
            H->esq = insereNO(H->esq, valor, resp);
        }else{
            H->dir = insereNO(H->dir, valor, resp);
        }
    }
    if(cor(H->dir) == RED && cor(H->esq) == BLACK){
        H = rotacionaEsquerda(H);
    }
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    return H;
}

int insere_ArvLLRB(ArvLLRB *raiz, int valor){
    int resp;
    *raiz = insereNO(*raiz, valor, &resp);
    if((*raiz) != NULL){
        (*raiz)->cor = BLACK;
    }
    return resp;
}

struct NO *procuraMenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO *removeMenor(struct NO *H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
        H = move2EsqRED(H);
    }
    H->esq = removeMenor(H->esq);
    return balancear(H);
}

struct NO *removeNO(struct NO *H, int valor){
    if(valor < H->info.codigo){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
            H = move2EsqRED(H);
        }
        H->esq = removeNO(H->esq, valor);
    }else{
        if(cor(H->esq) == RED){
            H = rotacionaDireita(H);
        }
        if(valor == H->info.codigo && (H->dir == NULL)){
            free(H);
            return NULL;
        }
        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK){
            H = move2DirRED(H);
        }
        if(valor == H->info.codigo){
            struct NO *x = procuraMenor(H->dir);
            H->info.codigo = x->info.codigo;
            H->dir = removeMenor(H->dir);
        }else{
            H->dir = removeNO(H->dir, valor);
        }
    }
    return balancear(H);
}

int remove_ArvLLRB(ArvLLRB *raiz, int valor){
    if(consulta_arvLLRB(raiz, valor)){
        struct NO *H = *raiz;
        *raiz = removeNO(H, valor);
        if(*raiz != NULL){
            (*raiz)->cor = BLACK;
        }
        return 1;
    }else{
        return 0;
    }
}




/*---------------------*/

void preOrdem_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info.codigo);
        preOrdem_ArvLLRB(&((*raiz)->esq));
        preOrdem_ArvLLRB(&((*raiz)->dir));
    }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvLLRB(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info.codigo);
        emOrdem_ArvLLRB(&((*raiz)->dir));
    }
}

void posOrdem_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq));
        posOrdem_ArvLLRB(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info.codigo);
    }
}


