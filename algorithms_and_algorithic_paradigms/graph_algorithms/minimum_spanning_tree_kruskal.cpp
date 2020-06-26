#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <bitset>
#include <climits>
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
struct graph
{
    vector<pair<int, ii>> edges; // pair<weight, ii(from_node, to_node)>
    int V, E;
};
using namespace std;

int find(int *parent, int n, int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, n, parent[i]);
    return parent[i];
}

void unify(int *parent, int *rank, int n, int x, int y)
{
    int xroot = find(parent, n, x);
    int yroot = find(parent, n, y);
    if (xroot == yroot)
    {
        return;
    }
    if (rank[xroot] < rank[yroot])
    {
        parent[xroot] = yroot;
        rank[yroot] += rank[xroot];
    }
    else
    {
        parent[yroot] = xroot;
        rank[xroot] += rank[yroot];
    }
}

int kruskalMST(graph &G)
{
    vi parent(G.V), rank(G.V);
    int u, v, setU, setV, mst_wt = 0;
    for (int i = 0; i < G.V; i++)
    {
        parent[i] = i;
    }
    sort(G.edges.begin(), G.edges.end());
    vector<pair<int, ii>>::iterator itr;
    for (itr = G.edges.begin(); itr != G.edges.end(); itr++)
    {
        u = (*itr).second.first, v = (*itr).second.second;
        setU = find(parent, G.V, u), setV = find(parent, G.V, v);
        if (setU != setV)
        {
            mst_wt = (*itr).first;
            unify(parent, rank, G.V, setU, setV);
        }
    }
    return mst_wt;
}