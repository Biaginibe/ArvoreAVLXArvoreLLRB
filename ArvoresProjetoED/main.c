#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "arvoreAVL.h"
#include "arvoreLLRB.h"
#include "RadixSort.h"

void chamaAVLDesordenada();
void chamaAVLOrdenada();
void chamaLLRBDesordenada();
void chamaLLRBOrdenada();
double ftempoAntes();
double ftempoDepois();
void ordenaMassaDados();

int main(){

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

    /*ArvAVL *raizAVL, AVLordenada[15000];
    ArvLLRB *raizLLRB, LLRBordenada[15000];

    //cria raizAVL
    raizAVL = cria_ArvAVL();
    //cria raizLLRB
    raizLLRB = cria_ArvLLRB();

    coleta_dadosAVL(raizAVL);


    coleta_dadosLLRB(raizLLRB);*/


    /*inserindo dados AVL*/
    /*x = insere_ArvAVL(raizAVL, 100);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 140);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 160);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 130);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 150);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 110);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 120);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    printf("\n");*/


    /*testa se ta vazia ARV AVL*/
    // if(vazia_ArvAVL(raizAVL)){
    //     printf("A arvore esta vazia.");
    // }else{
    //     printf("A arvore possui elementos.");
    // }
    // printf("\n\n");

    // /*ver a altura AVL*/
    // x = altura_ArvAVL(raizAVL);
    // printf("Altura da arvore: %d", x);
    // printf("\n\n");

    // /*total de n�s ARV AVL*/
    // x= totalNO_ArvAVL(raizAVL);
    // printf("Total de nos na arvore: %d", x);
    // printf("\n\n");

    /*organizando em pr�-ordem AVL*/
    /*printf("PRE ORDEM\n");
    preOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*organizando em ordem AVL*/
    // printf("EM ORDEM\n");
    // emOrdem_ArvAVL(raizAVL);
    // printf("\n\n");

    /*organizando em p�s-ordem AVL*/
    /*printf("POS ORDEM\n");
    posOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*removendo e exibindo arvore ap�s remo��o AVL*/
    /*printf("POS REMOCAO\n");
    x = remove_ArvAVL(raizAVL, 100);
    posOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*INSERINDO ARVORE LLRB*/
    // printf("AGORA ARV LLRB ");
    /*x = insere_ArvLLRB(raizLLRB, 150);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 110);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 100);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 130);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 120);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 140);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 160);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, n�o foi possivel inserir o elemento.\n\n");
    }
    printf("\n");
*/
    /*testa se ta vazia ARV LLRB*/
    // if(vazia_ArvLLRB(raizLLRB)){
    //     printf("A arvore esta vazia.");
    // }else{
    //     printf("A arvore possui elementos.");
    // }
    // printf("\n\n");

    // /*ver a altura LLRB*/
    // x = altura_ArvLLRB(raizLLRB);
    // printf("Altura da arvore: %d", x);
    // printf("\n\n");

    // /*total de n�s ARV LLRB*/
    // x= totalNO_ArvLLRB(raizLLRB);
    // printf("Total de nos na arvore: %d", x);
    // printf("\n\n");

    /*organizando em pr�-ordem AVL*/
    /*printf("PRE ORDEM\n");
    preOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*organizando em ordem LLRB*/
    // printf("EM ORDEM\n");
    // emOrdem_ArvLLRB(raizLLRB);
    // printf("\n\n");

    /*organizando em p�s-ordem LLRB*/
    /*printf("POS ORDEM\n");
    posOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*removendo e exibindo arvore ap�s remo��o LLRB*/
    /*printf("POS REMOCAO\n");
    x = remove_ArvLLRB(raizLLRB, 100);
    posOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*destroi a arvore AVL*/
    // liberar_ArvAVL(raizAVL);
    /*destroi a arvore LLRB*/
    // liberar_ArvLLRB(raizLLRB);
}

void chamaAVLDesordenada() {
    printf("Chamando funcao para dados desordenados...\n");
    ArvAVL *raizAVL;

    double tempoAntes = ftempoAntes();

    raizAVL = cria_ArvAVL();
    coleta_dadosAVL(raizAVL, 0);

    double tempoDepois = ftempoDepois();

    liberar_ArvAVL(raizAVL);

    printf("Tempo de alocação de items desordenados na Arvore AVL: %2.f", tempoDepois - tempoAntes);
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

    printf("Tempo de alocação de items ordenados na Arvore AVL: %2.f", tempoDepois - tempoAntes);
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
    return;

    printf("Tempo de alocação de items desordenados na Arvore LLRB: %2.f", tempoDepois - tempoAntes);
}

void chamaLLRBOrdenada() {
    printf("Chamando funcao para dados ordenados...\n");

    //ordenaMassaDados();

    ArvLLRB *raizLLRB, LLRBordenada[15000];

    double tempoAntes = ftempoAntes();

    raizLLRB = cria_ArvLLRB();
    coleta_dadosLLRB(raizLLRB, 1);

    double tempoDepois = ftempoDepois();

    liberar_ArvLLRB(raizLLRB);

    printf("Tempo de alocação de items ordenados na Arvore LLRB: %2.f", tempoDepois - tempoAntes);
    return;
}

double ftempoAntes(){
    struct timeval Tempo_antes; /*tv de timeval*/
    gettimeofday(&Tempo_antes, NULL);
    return (Tempo_antes.tv_sec + Tempo_antes.tv_usec/1000000.0);
}

double ftempoDepois(){
    struct timeval Tempo_depois; /*tv de timeval*/
    gettimeofday(&Tempo_depois, NULL);
    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0);
}
