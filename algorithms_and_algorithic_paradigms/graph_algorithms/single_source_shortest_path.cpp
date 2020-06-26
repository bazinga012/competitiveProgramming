#include <iostream>
#include <queue>
#include <vector>
#include <utility>
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;

using namespace std;
// https://stackoverflow.com/questions/19482317/bellman-ford-vs-dijkstra-under-what-circumstances-is-bellman-ford-better#:~:text=Bellman%2DFord%20algorithm%20is%20a,Algorithm%20can%20only%20handle%20positives.

/* 
a) Bellman-Ford and Dijkstra both are  single-source shortest path algorithms, 

b) The only difference between the two is that Bellman-Ford is also capable of handling 
negative weights whereas Dijkstra Algorithm can only handle positives.
This allows the Bellman–Ford algorithm to be applied to a wider class of inputs than Dijkstra.


c) Dijkstra is however generally considered better in the absence of negative weight edges, 
as a typical binary heap priority queue implementation has O((|E|+|V|)log|V|) time complexity 
[A Fibonacci heap priority queue gives O(|V|log|V| + |E|)], while the Bellman-Ford algorithm has O(|V||E|) complexity

 */

void Dijkstra(graph& G, int s, vi& D){
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    D[s] = 0;    Q.push(ii(0, s));
    int u, v, w, d;
    while(!Q.empty()){
        ii top = Q.top(); Q.pop();
        u = top.second(); d = top.first();
        if(d < D[u])
        for(int j=0; j < G[u].size(); j++){
            v = G[u][j].first(); w = G[u][j].second();
            if(D[v]> D[u] + w){
                D[v] = D[u] + w; Q.push(ii(D[v], v));
            }
        }
    }
}


int Bellmanford(graph& G, vi& D){ //source=0
    D[0] = 0; int v,d;
    for(int u=0;u<G.size();u++){
        for(int i=0; i<G[u].size();i++){
            d = G[u].first; v = G[u].second;
            if(D[v] > D[u] + d){ D[v] = D[u] + d;}
        }
     }
     for(int u=0;u<G.size();u++){
        for(int i=0; i<G[u].size();i++){
            d = G[u].first; v = G[u].second;
            if(D[v] > D[u] + d){cout<< “NegWgtCycle”; return -1;}
        }
     }
     return 0;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
