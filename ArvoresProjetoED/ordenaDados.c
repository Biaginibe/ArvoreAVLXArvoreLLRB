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

void ordenaMassaDados() {    
    FILE *massadados;
    massadados = fopen("massaDados.csv", "r");

    if(massadados == NULL){
        printf("Nao foi possivel abrir o arquivo massa de dados\n\n");
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

    massadados = fopen("massaDadosOrdenado.csv", "w");

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