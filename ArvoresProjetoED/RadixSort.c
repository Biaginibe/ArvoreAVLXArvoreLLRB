#include <stdio.h>
#include <stdlib.h>
#include "RadixSort.h"



void radixsort(int *v, int len) {
    int i;
    int *b;
    int maior = v[0];
    int exp = 1;

    b = (int *)calloc(len, sizeof(int));

    for (i = 0; i < len; i++) {
        if (v[i] > maior)
    	    maior = v[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < len; i++)
    	    bucket[(v[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = len - 1; i >= 0; i--)
    	    b[--bucket[(v[i] / exp) % 10]] = v[i];
    	for (i = 0; i < len; i++)
    	    v[i] = b[i];
    	exp *= 10;
    }
    free(b);
}
