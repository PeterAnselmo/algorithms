#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void selection_sort(int *A, int num_elements){
    int j, x;
    for(int i=1; i<num_elements-1; ++i){
        j = i;
        x = A[j];
        while(j > 0 && x < A[j-1]){
            A[j] = A[j-1];
            --j;
        }
        A[j] = x;
    }
}


int main(){
    int *A = malloc(ARRAY_SIZE * sizeof(int));
    int num_elements = 0;
    int array_size = ARRAY_SIZE;

    populate_array(A, &num_elements, array_size);

    selection_sort(A, num_elements);

    print_array(A, num_elements);
}
