#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include "utils.h"

using namespace std;

void prim(list<vertex*> &V, vector<edge> &E, list<vertex> &MST, vertex *r){
    for(const auto &u : V){
        u->parent = 0;
    }

    MST.push_back(r);
    while(MST.size() < V.size()){
        edge lowest;
        for(const auto &u : MST){
            for(const auto &v : u.adj){

        





}

int main(){
    list<vertex*> V;
    vector<edge> E;
    list<vertex*> MST;

    populate_adj_list_w_edges(V, E);

    vertex *r = V.front();
    V.pop_front();
    prim(V, E, MST, r);

    print_adj_list(V);

    //print_matrix(M, num_elements);

}
