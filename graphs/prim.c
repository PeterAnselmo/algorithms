#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10

//reads STDIN for 3 elements per line:
//vertex1, vertex2, path_weigth (space separated)
//used them to populate an adjacency matrix
void populate_matrix(int **M, int *num_elements){
    for(int i=0; i<MATRIX_SIZE; ++i){
        M[i] = malloc(MATRIX_SIZE * sizeof(int));
        if(M[i] == NULL){
            printf("Mem Allocation Error.\n");
            exit(1);
        }
        for(int j=0; j<MATRIX_SIZE; ++j){
            M[i][j] = 0;
        }
    }

    int v1, v2, weight;
    while(scanf("%d %d %d", &v1, &v2, &weight) == 3){
        if(v1 > *num_elements){
            *num_elements = v1;
        }
        if(v2 > *num_elements){
            *num_elements = v2;
        }
        M[v1][v2] = weight;
        M[v2][v1] = weight;
    }
}

void print_matrix(int **M, const int num_elements){
    for(int i=0; i<=num_elements; ++i){
        for(int j=0; j<=num_elements; ++j){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **M = malloc(MATRIX_SIZE * sizeof(int*));
    int num_elements = 9;

    populate_matrix(M, &num_elements);

    print_matrix(M, num_elements);

}
