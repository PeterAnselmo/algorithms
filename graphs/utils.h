#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <iostream>
#include <stdlib.h>
#include <set>
#include <list>
#include <algorithm>

#define MATRIX_SIZE 10

using namespace std;

class vertex {
public:
    int index;
    char color;
    int dist;
    int parent;
    set<vertex*> adj;

    vertex(int new_index){
        index = new_index;
    }
};
/*
inline bool operator ==(const vertex &lhs, const vertex &rhs){ return lhs.index == rhs.index; }
inline bool operator <(const vertex &lhs, const vertex &rhs){ return lhs.index < rhs.index; }
inline bool operator <=(const vertex &lhs, const vertex &rhs){ return lhs.index <= rhs.index; }
inline bool operator >(const vertex &lhs, const vertex &rhs){ return lhs.index > rhs.index; }
inline bool operator >=(const vertex &lhs, const vertex &rhs){ return lhs.index >= rhs.index; }
*/

void populate_adj_list(list<vertex*> &G){

    int v1, v2;
    bool v1_new, v2_new;

    //Read STDIN for two-number lines
    while(scanf("%d %d", &v1, &v2) == 2){

        v1_new = v2_new = true;

        vertex *vertex1 = NULL;
        vertex *vertex2 = NULL;
        for(const auto &v : G){
            if(v->index == v1){
                vertex1 = v;
                v1_new = false;
            }
            if(v->index == v2){
                vertex2 = v;
                v2_new = false;
            }
        }
        if(v1_new){
            vertex1 = new vertex(v1);
            G.push_back(vertex1);
        }
        if(v2_new){
            vertex2 = new vertex(v2);
            G.push_back(vertex2);
        }

        vertex1->adj.insert(vertex2);
        vertex2->adj.insert(vertex1);
    }
}

void print_adj_list(list<vertex*> G){
    for(const auto &v : G){
        printf("Vertex %d| color:%c, distance:%d, parent:%d, adj:", v->index, v->color, v->dist, v->parent);
        for(const auto &u : v->adj){
            printf("%d,", u->index);
        }
        printf("\n");
    }
}

//reads STDIN for 3 elements per line:
//vertex1, vertex2, path_weigth (space separated)
//used them to populate an adjacency matrix
void populate_matrix(int **M, int *num_elements){
    for(int i=0; i<MATRIX_SIZE; ++i){
        M[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));
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


#endif
