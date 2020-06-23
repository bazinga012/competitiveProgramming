// https://www.hackerrank.com/challenges/find-the-running-median/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d", &N);
    int a;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int a1, a2;
    // min_heap.push(INT_MAX);
    //max_heap.push(INT_MIN);
    float result;

    int i = 0;
    if (i == 0 && N >= 0)
    {
        scanf("%d", &a);
        result = (float)a;
        min_heap.push(a);
        printf("%.1f\n", result);
        i++;
    }
    if (i == 1 && N >= 1)
    {
        scanf("%d", &a);
        if (a > min_heap.top())
        {
            min_heap.push(a);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else
        {
            max_heap.push(a);
        }
        result = result + (float)a;
        printf("%.1f\n", result / 2);
        i++;
    }
    for (i = 2; i < N; i++)
    {
        scanf("%d", &a);

        if (a < max_heap.top())
        {
            max_heap.push(a);
        }
        else
        {
            min_heap.push(a);
        }

        a1 = min_heap.size();

        a2 = max_heap.size();

        if (a1 > a2 + 1)
        {
            a = min_heap.top();
            min_heap.pop();
            max_heap.push(a);
        }
        else if (a2 > a1 + 1)
        {
            a = max_heap.top();
            max_heap.pop();
            min_heap.push(a);
        }
        if (!(i & 1))
        {
            //pop from bigger size
            a = a1 > a2 ? min_heap.top() : max_heap.top();
            result = (float)a;
        }
        else
        {
            //avr of top elements
            result = (float)(min_heap.top() + max_heap.top()) / 2;
        }
        printf("%.1f\n", result);
    }
    return 0;
}
