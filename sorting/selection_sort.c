#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void selection_sort(int *A, int num_elements){
    int min, temp;
    for(int i=0; i<num_elements-1; ++i){
        min = i;
        for(int j=i+1; j<num_elements; ++j){
            if(A[j] < A[min]){
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
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
