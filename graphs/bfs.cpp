#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <list>
#include <set>
#include "utils.h"

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

//G is list of vertices
//s is starting vertex
void bfs(list<vertex*> &G, vertex *s){

    for(auto u : G){
        u->color = 'w';
        u->dist = INT_MAX;
        u->parent = 0;
    }

    s->color = 'g';
    s->dist = 0;
    
    list<vertex*> Q;
    Q.push_back(s);

    while(!Q.empty()){
        vertex *u = Q.front();
        Q.pop_front();

        for(auto &v : u->adj){
            if(v->color == 'w'){
                v->color = 'g';
                if((u->dist + 1) < v->dist){
                    v->dist = u->dist + 1;
                    v->parent = u->index;
                }
                Q.push_back(v);
            }
        }
        u->color = 'b';
    }
}

int main(){
    list<vertex*> G;

    populate_adj_list(G);

    list<vertex*>::iterator pos = min_element(G.begin(), G.end());
    vertex *s = *pos;
    G.erase(pos);

    bfs(G, s);

    printf("From Vertex %d:\n", s->index);
    print_adj_list(G);

}
