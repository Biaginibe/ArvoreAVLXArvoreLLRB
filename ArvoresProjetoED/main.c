#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"
#include "arvoreLLRB.h"
#include "ColetaDados.h"
int main(){

    int x;


    ArvAVL *raizAVL;
    ArvLLRB *raizLLRB;

    /*cria raizAVL*/
    raizAVL = cria_ArvAVL();
    /*cria raizLLRB*/
    raizLLRB = cria_ArvLLRB();

    coleta_dadosAVL(raizAVL);


    coleta_dadosLLRB(raizLLRB);

    /*inserindo dados AVL*/
    /*x = insere_ArvAVL(raizAVL, 100);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 140);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 160);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 130);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 150);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 110);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvAVL(raizAVL, 120);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    printf("\n");*/


    /*testa se ta vazia ARV AVL*/
    if(vazia_ArvAVL(raizAVL)){
        printf("A arvore esta vazia.");
    }else{
        printf("A arvore possui elementos.");
    }
    printf("\n\n");

    /*ver a altura AVL*/
    x = altura_ArvAVL(raizAVL);
    printf("Altura da arvore: %d", x);
    printf("\n\n");

    /*total de nós ARV AVL*/
    x= totalNO_ArvAVL(raizAVL);
    printf("Total de nos na arvore: %d", x);
    printf("\n\n");

    /*organizando em pré-ordem AVL*/
    /*printf("PRE ORDEM\n");
    preOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*organizando em ordem AVL*/
    printf("EM ORDEM\n");
    emOrdem_ArvAVL(raizAVL);
    printf("\n\n");

    /*organizando em pós-ordem AVL*/
    /*printf("POS ORDEM\n");
    posOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*removendo e exibindo arvore após remoção AVL*/
    /*printf("POS REMOCAO\n");
    x = remove_ArvAVL(raizAVL, 100);
    posOrdem_ArvAVL(raizAVL);
    printf("\n\n");*/

    /*INSERINDO ARVORE LLRB*/
    printf("AGORA ARV LLRB ");
    /*x = insere_ArvLLRB(raizLLRB, 150);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 110);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 100);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 130);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 120);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 140);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    x = insere_ArvLLRB(raizLLRB, 160);
    if(x){
        printf("Elemento inserido com sucesso!\n\n");
    }else{
        printf("Erro, não foi possivel inserir o elemento.\n\n");
    }
    printf("\n");
*/
    /*testa se ta vazia ARV LLRB*/
    if(vazia_ArvLLRB(raizLLRB)){
        printf("A arvore esta vazia.");
    }else{
        printf("A arvore possui elementos.");
    }
    printf("\n\n");

    /*ver a altura LLRB*/
    x = altura_ArvLLRB(raizLLRB);
    printf("Altura da arvore: %d", x);
    printf("\n\n");

    /*total de nós ARV LLRB*/
    x= totalNO_ArvLLRB(raizLLRB);
    printf("Total de nos na arvore: %d", x);
    printf("\n\n");

    /*organizando em pré-ordem AVL*/
    /*printf("PRE ORDEM\n");
    preOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*organizando em ordem LLRB*/
    printf("EM ORDEM\n");
    emOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");

    /*organizando em pós-ordem LLRB*/
    /*printf("POS ORDEM\n");
    posOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*removendo e exibindo arvore após remoção LLRB*/
    /*printf("POS REMOCAO\n");
    x = remove_ArvLLRB(raizLLRB, 100);
    posOrdem_ArvLLRB(raizLLRB);
    printf("\n\n");*/

    /*destroi a arvore AVL*/
    liberar_ArvAVL(raizAVL);
    /*destroi a arvore LLRB*/
    liberar_ArvLLRB(raizLLRB);
    return 0;
}
