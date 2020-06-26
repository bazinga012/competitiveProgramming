#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <bitset>
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
#define MAX_NODES 5000

using namespace std;

vi primMST(graph& G){
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    vi D, parent;  
    bitset<MAX_NODES> inMST;
    D[0] = 0; parent[0] = -1;    Q.push(ii(0, 0));
    int u, v, w, d;
    while(!Q.empty()){
        ii top = Q.top(); Q.pop();
        u = top.second(); d = top.first();
        inMST[u] = 1;
        if(d < D[u])
        for(int j=0; j < G[u].size(); j++){
            v = G[u][j].first(); w = G[u][j].second();
            if(inMST[v] == 0 && D[v] > w){
                D[v] = w; parent[v] = u; Q.push(ii(D[v], v));
            }
        }
    }
    return parent;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

