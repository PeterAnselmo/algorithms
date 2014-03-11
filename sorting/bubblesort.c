#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define ARRAY_SIZE 100

void bubble_sort(int *A, int num_elements){
    int tmp;
    for(int i=0; i<num_elements-1; ++i){
        for(int j=i+1; j<num_elements; ++j){
            if(A[i]>A[j]){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

int main(){
    int* A = malloc(ARRAY_SIZE * sizeof(int));
    int num_elements = 0;
    populate_array(A, &num_elements, ARRAY_SIZE);

    bubble_sort(A, num_elements);

    print_array(A, num_elements);
}

