#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"


struct NO{
    Func info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL *cria_ArvAVL(){
    ArvAVL *raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL){
            *raiz = NULL;
    }

    return raiz;

}

void coleta_dados(ArvAVL *raiz){
    /*------------------------------------------------------*/
    FILE *massadados;
    massadados = fopen("massaDados.csv", "r");
    if(massadados == NULL){
        printf("Nao foi possivel abrir o arquivo massa de dados\n\n");
        exit(0);
    }

    char texto[300];
    Func funcionario;

    while(fgets(texto, 300, massadados)){
        funcionario.codigo = atoi(strtok(texto, ";"));
        strcpy(funcionario.nome, strtok(NULL, ";"));
        funcionario.idade = atoi(strtok(NULL, ";"));
        strcpy(funcionario.empresa, strtok(NULL, ";"));
        strcpy(funcionario.depto, strtok(NULL, ";"));
        funcionario.salario = atof(strtok(NULL, "\n"));

        insere_ArvAVL(raiz, funcionario);
    /*------------------------------------------------------*/
    }

    fclose(massadados);


}
void liberar_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

int vazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

/*FUN��ES DA ARVORE AVL*/

int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->alt;
    }
}

int fatorBalanceamento_NO(struct NO *no){
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

int maior(int x, int y){
    if(x > y){
        return(x);
    }else{
        return(y);
    }
}

void rotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt =maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt + 1);
    *raiz = no;
}

void rotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt =maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt + 1);
    (*raiz) = no;
}

void rotacaoLR(ArvAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, Func funcionario){
    printf("valor.codigo: %s\n", funcionario.codigo);
    printf("valor.nome: %s\n", funcionario.nome);
    printf("valor.idade: %s\n", funcionario.idade);
    printf("valor.empresa: %s\n", funcionario.empresa);
    printf("valor.depto: %s\n", funcionario.depto);
    printf("valor.salario: %s\n", funcionario.salario);

    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));

        if(novo == NULL){
            printf("N� NOVO VAZIO\n");
            return 0;
        }
        novo->info = funcionario;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(funcionario.codigo < atual->info.codigo){
        if((res = insere_ArvAVL(&(atual->esq), funcionario)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(funcionario.codigo < (*raiz)->esq->info.codigo){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(funcionario.codigo > atual->info.codigo){

            if((res = insere_ArvAVL(&(atual->dir), funcionario)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info.codigo < funcionario.codigo){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;

    return res;

}

struct NO *procuramenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
    if(*raiz == NULL){
        return 0;
    }
    int res;
    if(valor < (*raiz)->info.codigo){
        if((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->dir->esq) <= alt_no((*raiz)->dir->dir)){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->info.codigo < valor){
        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->info.codigo == valor){
        if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL){
            struct NO *no_velho = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        }else{
            struct NO *temp = procuramenor((*raiz)->dir);
            (*raiz)->info.codigo = temp->info.codigo;
            remove_ArvAVL((*raiz)->dir, (*raiz)->info.codigo);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
        }
        return 1;
    }
    if(*raiz != NULL){
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    }
    return res;
}


/*---------------------*/

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        // printf("%d\n", (*raiz)->info.codigo);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        // printf("%d\n", (*raiz)->info.codigo);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info.codigo);
        printf("%d\n", (*raiz)->info.nome);
        printf("%d\n", (*raiz)->info.idade);
        printf("%d\n", (*raiz)->info.empresa);
        printf("%d\n", (*raiz)->info.depto);
        printf("%d\n", (*raiz)->info.salario);
    }
}

