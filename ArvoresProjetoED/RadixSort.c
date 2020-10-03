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

void radixsort(funcionario *v, int len, int maior) {
    int i;
    funcionario *b;
    int exp = 1;

    b = (funcionario *)calloc(len, sizeof(funcionario));

    for (i = 0; i < len; i++) {
        if (v[i].codigo > maior)
            maior = v[i].codigo;
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < len; i++)
            bucket[(v[i].codigo / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = len - 1; i >= 0; i--)
            b[--bucket[(v[i].codigo / exp) % 10]] = v[i];
        for (i = 0; i < len; i++)
            v[i] = b[i];
        exp *= 10;
    }
    free(b);
}

// void radixsort(int *v, int len) {
//     int i;
//     int *b;
//     int maior = v[0];
//     int exp = 1;

//     b = (int *)calloc(len, sizeof(int));

//     for (i = 0; i < len; i++) {
//         if (v[i] > maior)
//     	    maior = v[i];
//     }

//     while (maior/exp > 0) {
//         int bucket[10] = { 0 };
//     	for (i = 0; i < len; i++)
//     	    bucket[(v[i] / exp) % 10]++;
//     	for (i = 1; i < 10; i++)
//     	    bucket[i] += bucket[i - 1];
//     	for (i = len - 1; i >= 0; i--)
//     	    b[--bucket[(v[i] / exp) % 10]] = v[i];
//     	for (i = 0; i < len; i++)
//     	    v[i] = b[i];
//     	exp *= 10;
//     }
//     free(b);
// }
