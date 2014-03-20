#include <iostream>
#include <limits.h>
#include <list>
#include <vector>
#include "utils.h"

void bellman_ford(list<vertex*> &V, vertex* s){

    //initialize single source
    for(auto v : V){
        v->dist = INT_MAX/2; // divide by 2 to give room for integer addition 
        v->parent = 0;
    }
    s->dist = 0;
    s->parent = 0;

    for(unsigned int i=0; i<V.size(); ++i){
        //two for loops next, but only O(E) complexity
        for(auto u : V){
            for(auto av : u->adj){
                //Relax the edge
                if(u->dist + av.weight < av.v->dist){
                    av.v->dist = u->dist + av.weight;
                    av.v->parent = u->index;
                }
            }
        }
    }
}

int main(){

    list<vertex*> V;
    vector<edge> E;

    populate_adj_list_w_edges(V, E);

    vertex* s = V.front();

    bellman_ford(V, s);

    printf("Distance from %d:\n", s->index);
    print_adj_list(V);

}
