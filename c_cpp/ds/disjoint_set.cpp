#include <iostream>
#include <utility>
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
using namespace std;
/* https://www.youtube.com/watch?v=wU6udHRIkcc */

int find(int *parent, int n, int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, n, parent[i]);
    return parent[i];
}

void unify(int *parent, int *rank, int n, int x, int y)
{
    /* Also, size (in place of height) of trees can also be used as rank. 
    Using size as rank also yields worst case time complexity as O(Logn) */
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

int main()
{
    int n;
    cin >> n;
    int parent[n];
    int rank[n];
    graph G;
    memset(parent, -1, sizeof(int) * n);
    memset(rank, 1, sizeof(int) * n);

    return 0;
}
