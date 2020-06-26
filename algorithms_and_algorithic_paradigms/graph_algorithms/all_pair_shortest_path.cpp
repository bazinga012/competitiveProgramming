#include <iostream>
#include <queue>
#include <vector>
#include <utility>
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;

using namespace std;

void floydWAllPairShortestPath(graph G, vii &dist){
    int i, j, k;
    for (i = 0; i < G.size(); i++)
        for (j = 0; j < G[i].size(); j++)
            dist[i][j] = G[i][j];
    for (k = 0; k < G.size(); k++){
        for (i = 0; i < G.size(); i++){
            for (j = 0; j < G[i].size(); j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
} 

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
