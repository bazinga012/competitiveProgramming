
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#define MAX_NODES = 5000;
typedef vector<list<int>> graph;
typedef bitset<5000> nodeBits;

using namespace std;

void dfs(graph &G, int s, nodeBits &visited)
{
    visited[s] = 1;
    list<int>::iterator v;
    for (v = G[s].begin(); v != G[s].end(); v++)
    {
        if (visited[*v] != 1)
        {
            dfs(G, *v, visited);
        }
    }
}

void bfs(graph &G, int s, nodeBits &visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    int u;
    list<int>::iterator v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (v = G[u].begin(); v != G[u].end(); v++)
        {
            if (visited[*v] != 1)
            {
                visited[*v] = 1;
                q.push(*v);
            }
        }
    }
}
bool isDAGAndPrintTopSort(graph &G, int s, nodeBits &visited, nodeBits &rT, stack<int> &sT)
{
    visited[s] = 1;
    rT[s] = 1;
    list<int>::iterator v;
    for (v = G[s].begin(); v != G[s].end(); v++)
    {
        if (visited[*v] != 1)
        {
            if (!isDAGAndPrintTopSort(G, *v, visited, rT, sT))
            {
                return false;
            }
        }
        if (rT[*v] == 1)
            return false;
    }
    rT[s] = 0;
    sT.push(s);
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    graph G;

    /* DFS + BFS */
    nodeBits visited;
    for (int i = 0; i < G.size(); i++)
    {
        if (visited[i] != 1)
        {
            //dfs(G, i, visited);
            bfs(G, i, visited);
        }
    }

    /* Topological Sort */
    nodeBits visited, rT;
    stack<int> sT;
    for (int i = 0; i < G.size(); i++)
    {
        if (!visited[i])
            if (!isDAGAndPrintTopSort(G, i, visited, rT, sT))
            {
                cout << 'NotADAG';
            }
    }

    return 0;
}
