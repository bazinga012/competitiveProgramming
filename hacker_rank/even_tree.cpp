// https://www.hackerrank.com/challenges/even-tree/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int tN; //total nodes including v
    vector<int> children;
};

int DFS_populate_tN(node *graph, int s)
{
    //if(graph[s])
    int size = 1;
    for (int i = 0; i < graph[s].children.size(); i++)
    {
        size += DFS_populate_tN(graph, graph[s].children[i]);
    }
    graph[s].tN = size;
    return size;
}

int BFS_for_max_edge(node *graph, int s)
{

    int count = 0;
    for (int i = 0; i < graph[s].children.size(); i++)
    {
        if (graph[graph[s].children[i]].tN & 1)
        {
            //continue;
        }
        else
        {
            count++;
        }
        count += BFS_for_max_edge(graph, graph[s].children[i]);
    }
    return count;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    scanf("%d%d", &n, &m);
    //cin>>n>>m;
    node graph[100];
    int a1, a2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a1);
        scanf("%d", &a2);
        if (a1 > a2)
        {
            graph[a2 - 1].children.push_back(a1 - 1);
        }
        else
        {
            graph[a1 - 1].children.push_back(a2 - 1);
        }
    }
    //DFS to populate tN
    DFS_populate_tN(graph, 0);
    printf("%d", BFS_for_max_edge(graph, 0));

    return 0;
}
