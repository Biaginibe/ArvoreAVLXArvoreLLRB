#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "arvoreAVL.h"
#include "arvoreLLRB.h"
#include "RadixSort.h"
#include "ordenaDados.h"

void chamaAVLDesordenada();
void chamaAVLOrdenada();
void chamaLLRBDesordenada();
void chamaLLRBOrdenada();
double ftempoAntes();
double ftempoDepois();
void ordenaMassaDados();

int main() {

    int x;

    double tempoAntes, tempoDepois;
    int opcaoEscolhida = 0;

    printf("Escolha uma das opções a seguir: \n");
    printf("1) Tempo para Arvore AVL desordenada\n");
    printf("2) Tempo para Arvore AVL ordenada\n");
    printf("3) Tempo para Arvore LLRB desordenada\n");
    printf("4) Tempo para Arvore LLRB ordenada\n");
    printf("5) Sair\n");

    printf("Opcao: ");
    scanf("%d", &opcaoEscolhida);

    while (opcaoEscolhida == 0) {
        scanf("%d", &opcaoEscolhida);
    }

    if (opcaoEscolhida == 1) {
        chamaAVLDesordenada();
    }

    if (opcaoEscolhida == 2) {
        chamaAVLOrdenada();
    }

    if (opcaoEscolhida == 3) {
        chamaLLRBDesordenada();
    }

    if (opcaoEscolhida == 4) {
        chamaLLRBOrdenada();
    }

    return 0;
}

void chamaAVLDesordenada() {
    printf("Chamando funcao para dados desordenados...\n");
    ArvAVL *raizAVL;

    double tempoAntes = ftempoAntes();

    raizAVL = cria_ArvAVL();
    coleta_dadosAVL(raizAVL, 0);

    double tempoDepois = ftempoDepois();

    liberar_ArvAVL(raizAVL);

    printf("Tempo de alocacao de items desordenados na Arvore AVL: %f microssegundos", tempoDepois - tempoAntes);
    return;
}
void chamaAVLOrdenada() {
    printf("Chamando funcao para dados ordenados...\n");

    ordenaMassaDados();

    ArvAVL *raizAVL;

    double tempoAntes = ftempoAntes();

    raizAVL = cria_ArvAVL();
    coleta_dadosAVL(raizAVL, 1);

    double tempoDepois = ftempoDepois();

    liberar_ArvAVL(raizAVL);

    printf("Tempo de alocacao de items ordenados na Arvore AVL: %f microssegundos", tempoDepois - tempoAntes);
    return;
}

void chamaLLRBDesordenada() {
    printf("Chamando funcao para dados desordenados...\n");
    ArvLLRB *raizLLRB;

    double tempoAntes = ftempoAntes();

    raizLLRB = cria_ArvLLRB();
    coleta_dadosLLRB(raizLLRB, 0);

    double tempoDepois = ftempoDepois();

    liberar_ArvLLRB(raizLLRB);

    printf("Tempo de alocacao de items desordenados na Arvore LLRB: %f microssegundos", tempoDepois - tempoAntes);
}

void chamaLLRBOrdenada() {
    printf("Chamando funcao para dados ordenados...\n");

    ordenaMassaDados();

    ArvLLRB *raizLLRB;

    double tempoAntes = ftempoAntes();

    raizLLRB = cria_ArvLLRB();
    coleta_dadosLLRB(raizLLRB, 0);

    double tempoDepois = ftempoDepois();

    liberar_ArvLLRB(raizLLRB);

    printf("Tempo de alocacao de items ordenados na Arvore LLRB: %f microssegundos", tempoDepois - tempoAntes);
    return;
}

double ftempoAntes(){
    struct timeval Tempo_antes; /*tv de timeval*/
    gettimeofday(&Tempo_antes, NULL);
    return (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}

double ftempoDepois(){
    struct timeval Tempo_depois; /*tv de timeval*/
    gettimeofday(&Tempo_depois, NULL);
    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0);
}
