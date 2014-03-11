#ifndef ALGO_UTILS_H
#define ALGO_UTILS_H

#include <stdio.h>
#include <stdlib.h>

//read in space-separated array of numbers from STDIN
void populate_array(int *A, int *num_elements, int size){
    int num;
    while(scanf("%d", &num) == 1 ){
        if(*num_elements > size){
            size *= 2;
            A = realloc(A, size * sizeof(int));
        }
        A[*num_elements] = num;
        *num_elements += 1;
    }
}

void print_array(int *A, int num_elements){
    for(int i=0; i<num_elements; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
}


#endif
