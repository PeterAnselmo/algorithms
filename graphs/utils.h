#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <iostream>
#include <stdlib.h>
#include <set>
#include <list>
#include <algorithm>

#define MATRIX_SIZE 10
#define DEBUGGING false

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


class edge {
public:
    vertex *u;
    vertex *v;
    int weight;

    edge(vertex *new_u, vertex *new_v, int new_weight){
        u = new_u;
        v = new_v;
        weight = new_weight;
    }
};


//ie. a "forest" of "trees"
class vertex_disjoint_set {
private:
    list<list<vertex*>> _sets;

public:
    void make_set(vertex* v){
        list<vertex*> subset = {v};
        _sets.push_back(subset);
    }

    vertex* find_set(vertex *v){
        for(auto &set : _sets){
            for(const auto vert : set){
                if(vert == v){
                    if(DEBUGGING){
                        printf("Found %d in subset with head %d\n", v->index, set.front()->index);
                    }
                    return set.front();
                }
            }
        }
        printf("Error, tried to find set of un-made element\n");
        exit(1);
    }

    void vertex_union(vertex *u, vertex *v){
        //although we usually have found these subsets before calling 
        //this function in find_set, we find them again to be safe 
        //& to get a reference rather than a copy
        list<vertex*>* u_set;
        list<vertex*>* v_set;
        for(auto &set : _sets){
            for(const auto vert : set){
                if(vert == u){
                    u_set = &set;
                }
                if(vert == v){
                    v_set = &set;
                }
            }
        }
        if(DEBUGGING){
            printf("Merging set %d(%d elements) with set %d(%d elements)\n",
                    u_set->front()->index, (int)u_set->size(), v_set->front()->index, (int)v_set->size());
        }
        u_set->splice( u_set->begin(), *v_set);
        if(DEBUGGING){
            printf("New set %d formed with %d elements\n", u_set->front()->index, (int)u_set->size());
        }
        _sets.remove(*v_set);
    }

};

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

void populate_adj_list_w_edges(list<vertex*> &V, vector<edge> &E){

    int v1, v2, weight;
    bool v1_new, v2_new;

    //Read STDIN for three-number lines
    while(scanf("%d %d %d", &v1, &v2, &weight) == 3){
        if(DEBUGGING){
            printf("Read %d %d %d\n", v1, v2, weight);
        }

        v1_new = v2_new = true;

        vertex *vertex1 = NULL;
        vertex *vertex2 = NULL;
        for(const auto &v : V){
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
            V.push_back(vertex1);
        }
        if(v2_new){
            vertex2 = new vertex(v2);
            V.push_back(vertex2);
        }

        vertex1->adj.insert(vertex2);
        vertex2->adj.insert(vertex1);

        edge uv(vertex1, vertex2, weight);
        E.push_back(uv);
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

void print_edges(vector<edge> E){
    for(const auto &uv : E){
        printf("(%d %d) %d\n", uv.u->index, uv.v->index, uv.weight);
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
