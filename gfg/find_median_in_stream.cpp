#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n, a, mins = 0, maxs = 1;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int> maxq;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (maxq.empty())
        {
            maxq.push(a);
            cout << a << "\n";
            continue;
        }
        if (a < maxq.top())
        {
            maxq.push(a);
        }
        else if (minq.empty() || a > minq.top())
        {
            minq.push(a);
        }
        else
        {
            maxq.size() > minq.size() ? minq.push(a) : maxq.push(a);
        }
        if (minq.empty() || maxq.size() > minq.size())
        {
            minq.push(maxq.top());
            maxq.pop();
        }
        else if (minq.size() > maxq.size())
        {
            maxq.push(minq.top());
            minq.pop();
        }
        if (i & 1)
        {
            cout << (maxq.top() + minq.top()) / 2;
        }
        else
        {
            cout << (maxq.size() > minq.size() ? maxq.top() : minq.top());
        }
        cout << "\n";
    }
    return 0;
}