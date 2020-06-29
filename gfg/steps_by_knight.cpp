#include <iostream>
#include <utility>
#include <queue>
#include <bitset>
#define maxBits 400
using namespace std;
typedef pair<int, int> ii;

/* BFS Level Order Traversal */

int minStepsByKnightToReachFromSrcToTarget(ii src, ii target, int n)
{
    if (src.first == target.first && src.second == target.second)
    {
        return 0;
    }
    queue<ii> q;
    bitset<maxBits> visited;
    q.push(src);
    q.push(ii(-1, -1));
    visited[(src.first * n) + src.second] = 1;
    ii curr, next;
    ii moves[4] = {ii(2, -1), ii(2, 1), ii(-2, 1), ii(-2, -1)};
    int levels = 1;
    while (!q.empty())
    {
        ii curr = q.front();
        q.pop();
        // cout << curr.first << " " << curr.second << "\n";
        for (int i = 0; i < 4; i++)
        {
            next = ii(curr.first + (moves[i].first), curr.second + (moves[i].second));
            // cout << next.first << " " << next.second << "\n";
            if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && visited[(next.first * n) + next.second] != 1)
            {
                if (next.first == target.first && next.second == target.second)
                {
                    return levels;
                }
                visited[(next.first * n) + next.second] = 1;
                q.push(next);
            }
            next = ii(curr.first + (moves[i].second), curr.second + (moves[i].first));
            // cout << next.first << " " << next.second << "\n";
            if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && visited[(next.first * n) + next.second] != 1)
            {
                if (next.first == target.first && next.second == target.second)
                {
                    return levels;
                }
                visited[(next.first * n) + next.second] = 1;
                q.push(next);
            }
        }
        // cout << q.front().first << " " << q.front().second << "\n";
        if (q.front().first == -1)
        {
            q.pop();
            levels += 1;
            q.push(ii(-1, -1));
        }
    }
}
int main()
{
    //code
    int tc, n, x, y;
    ii src, target;
    cin >> tc;

    while (tc--)
    {
        cin >> n;
        cin >> x >> y;
        src = ii(x - 1, y - 1);
        cin >> x >> y;
        target = ii(x - 1, y - 1);
        // cout << src.first << " " << src.second << "\n";
        // cout << target.first << " " << target.second << "\n";
        // cout << n << "\n";
        cout << minStepsByKnightToReachFromSrcToTarget(src, target, n) << "\n";
    }
    return 0;
}