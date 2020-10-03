#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"
#include "RadixSort.h"

struct informacao{
    int codigo;
    char nome[100];
    int idade;
    char empresa[30];
    char depto[30];
    float salario;
};

struct NO{
    funcionario info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL *cria_ArvAVL(){
    ArvAVL *raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(*raiz != NULL){
            *raiz = NULL;
    }
    return raiz;
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

int insere_ArvAVL(ArvAVL *raiz, funcionario inf){

    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));

        if(novo == NULL){
            printf("N� NOVO VAZIO\n");
            return 0;
        }

        novo->info = inf;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(inf.codigo < atual->info.codigo){
        if((res = insere_ArvAVL(&(atual->esq), inf)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(inf.codigo < (*raiz)->esq->info.codigo){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(inf.codigo > atual->info.codigo){
            if((res = insere_ArvAVL(&(atual->dir), inf)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info.codigo < inf.codigo){
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
        printf("%d\n", (*raiz)->info.codigo);
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
        printf("%d\n", (*raiz)->info.codigo);
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
    }
}

void coleta_dadosAVL(ArvAVL *raiz){
    printf("entrando na coleta!");
    /*------------------------------------------------------*/
    FILE *massadados;
    massadados = fopen("massaDados.csv", "r");

    if(massadados == NULL){
        printf("N�o foi possivel abrir o arquivo massa de dados\n\n");
        exit(0);
    }

    funcionario info;
    char texto[100];

    printf("inserindo na arvore\n");
    /*struct NO no;*/
    while(fgets(texto, 100, massadados)){
		 info.codigo = atoi(strtok(texto, ";"));
		 strcpy(info.nome, strtok(NULL, ";"));
		 info.idade = atoi(strtok(NULL, ";"));
		 strcpy(info.empresa, strtok(NULL, ";"));
		 strcpy(info.depto, strtok(NULL, ";"));
		 info.salario = atof(strtok(NULL, "\n"));
		 insere_ArvAVL(raiz, info);
    }
    /*------------------------------------------------------*/
    fclose(massadados);
}

void ordenaMassaDados() {
    printf("Ordenando massa de dados\n");  
    
    FILE *massadados;
    massadados = fopen("massaDados.csv", "r");

    if(massadados == NULL){
        printf("N�o foi possivel abrir o arquivo massa de dados\n\n");
        exit(0);
    }
    
    funcionario func; 
    funcionario *ordenado;
    int i = 0;
    int maior = 0;

    ordenado = (funcionario*) malloc(15000 * sizeof(funcionario));

    char texto[100];

    while(fgets(texto, 100, massadados)){
		func.codigo = atoi(strtok(texto, ";"));
        if (func.codigo > maior)
            maior = func.codigo;
		strcpy(func.nome, strtok(NULL, ";"));
		func.idade = atoi(strtok(NULL, ";"));
		strcpy(func.empresa, strtok(NULL, ";"));
		strcpy(func.depto, strtok(NULL, ";"));
	    func.salario = atof(strtok(NULL, "\n"));

        ordenado[i] = func;


        i++;
    }

    radixsort(ordenado, 15000, maior);
    fclose(massadados);

    printf("abrindo arq novamente\n");
    massadados = fopen("massaDados.csv", "w");

    for (i = 0; i < 15000; i++) {
        fprintf(massadados, "%d;",ordenado[i].codigo);
        fprintf(massadados, "%s;",ordenado[i].nome);
        fprintf(massadados, "%d;",ordenado[i].idade);
        fprintf(massadados, "%s;",ordenado[i].empresa);
        fprintf(massadados, "%s;",ordenado[i].depto);
        fprintf(massadados, "%.2f\n", ordenado[i].salario);
    }

    fclose(massadados);
}