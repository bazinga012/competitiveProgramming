#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <bitset>
#include <climits>
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
#define MAX_NODES 5000
using namespace std;

bool bfsPath(graph &G, int s, int t, vi &parent)
{
    bitset<MAX_NODES> visited;
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    int u;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            if (G[u][i] > 0 && !visited[i])
            {
                Q.push(i);
                visited[i] = 1;
                parent[i] = u;
                if (i == t)
                    return true;
            }
        }
    }
    return false;
}

int fordFulkMaxFlow(graph &G, int s, int t)
{
    graph resdG;
    vi parent;
    int max_flow, flow, u, v;
    for (int i = 0; i < G.size(); i++)
        for (int j = 0; j < G.size(); j++)
            resdG[i][j] = G[i][j];
    while (bfsPath(resdG, s, t, &parent))
    {
        flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            flow = flow > resdG[u][v] ? resdG[u][v] : flow;
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            resdG[u][v] -= flow;
            resdG[v][u] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
