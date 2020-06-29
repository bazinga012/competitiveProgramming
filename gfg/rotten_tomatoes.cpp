#include <iostream>
#include <queue>
#include <bitset>
#define maxBits 10000
using namespace std;
typedef pair<int, int> ii;
int minStepsForRotting(int **arr, int r, int c)
{
    queue<ii> q;
    bitset<maxBits> visited;
    int toRot = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                toRot += 1;
                continue;
            }
            if (arr[i][j] == 2)
            {
                q.push(ii(i, j));
                visited[(i * c) + j] = 1;
            }
        }
    }
    if (toRot == 0)
        return 0;
    q.push(ii(-1, -1));
    ii curr, next;
    ii moves[4] = {ii(-1, 0), ii(1, 0), ii(0, -1), ii(0, 1)};
    int levels = 1;
    while (!q.empty())
    {
        ii curr = q.front();
        q.pop();
        //cout << curr.first << " " << curr.second << "\n";
        for (int i = 0; i < 4; i++)
        {
            next = ii(curr.first + (moves[i].first), curr.second + (moves[i].second));
            if (next.first >= 0 && next.first < r && next.second >= 0 && next.second < c && visited[(next.first * c) + next.second] != 1 && arr[next.first][next.second] == 1)
            {
                //cout << next.first << " " << next.second << " " << "\n";
                toRot--;
                if (toRot == 0)
                {
                    return levels;
                }
                arr[next.first][next.second] = 2;
                visited[(next.first * c) + next.second] = 1;
                q.push(next);
            }
        }
        if (q.front().first == -1)
        {
            q.pop();
            levels += 1;
            q.push(ii(-1, -1));
        }
    }
    if (toRot == 0)
    {
        return levels;
    }
    return -1;
}

int main()
{
    //code
    int tc, r, c;
    cin >> tc;
    while (tc--)
    {
        cin >> r >> c;
        int **arr = (int **)malloc(sizeof(int *) * r);
        for (int i = 0; i < r; i++)
        {
            arr[i] = (int *)malloc(sizeof(int) * c);
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << minStepsForRotting(arr, r, c) << "\n";
    }
    return 0;
}