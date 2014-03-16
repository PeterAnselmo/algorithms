#include <iostream>
#include <list>
#include <algorithm>
#include "utils.h"

using namespace std;

void kruskal(list<vertex*> &V, vector<edge> &E, vector<edge> &MST){

    vertex_disjoint_set forest;
    for(const auto &v : V){
        forest.make_set(v);
    }

    sort(E.begin(), E.end(), [](edge e1, edge e2){ return e1.weight < e2.weight; });
    for(const auto &uv : E){
        if(forest.find_set(uv.u) != forest.find_set(uv.v)){
            MST.push_back(uv);
            forest.vertex_union(uv.u, uv.v);
        }
    }
}


int main(){
    list<vertex*> V;
    vector<edge> E;
    vector<edge> MST;

    populate_adj_list_w_edges(V, E);

    kruskal(V, E, MST);

    printf("Edges in MST:\n");
    print_edges(MST);

}
