#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void swap(int *A, int pos1, int pos2){
    int temp = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = temp;
}

void merge_sort(int *A, int start, int end){
    //trivial case - 1 element is sorted
    if(start >= end){
        return;
    }

    //compute midpoint & sizes, +1 for 0-based left
    int mid = (start + end) / 2;
    int lsize = mid-start+1;
    int rsize = end-mid;

    //recursively merge each half (inclusive)
    merge_sort(A, start, mid);
    merge_sort(A, mid+1, end);

    //create new copies of each half
    int *left = malloc(lsize * sizeof(int));
    int *right = malloc(rsize * sizeof(int));
    memcpy(&left[0], &A[start], lsize*sizeof(int));
    memcpy(&right[0], &A[mid+1], rsize*sizeof(int));

    //merge. O(n) time, keep taking smallest from each half
    int i, j, pos;
    i = j = 0;
    pos = start;
    while(pos <= end){
        if((i < lsize && left[i] <= right[j]) || (j == rsize)){
            A[pos] = left[i];
            ++i;
        } else {
            A[pos] = right[j];
            ++j;
        }
        ++pos;
    }

    return;
}

int main(){

    int *A = malloc(ARRAY_SIZE * sizeof(int*));
    int num_elements =0;

    populate_array(A, &num_elements, ARRAY_SIZE);

    merge_sort(A, 0, num_elements-1);

    print_array(A, num_elements);

}
