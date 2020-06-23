// https://www.hackerrank.com/challenges/coin-change/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long coin_change(int *arr, int N, int C)
{
    long long table[N + 1][C];
    for (int j = 0; j < C; j++)
    {
        table[0][j] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i - arr[j] >= 0)
            {
                table[i][j] = table[i - arr[j]][j];
                if (j > 0)
                {
                    table[i][j] += table[i][j - 1];
                }
            }
            else
            {
                if (j > 0)
                {
                    table[i][j] = table[i][j - 1];
                }
                else
                {
                    table[i][j] = 0;
                }
            }
        }
    }
    return table[N][C - 1];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, C;
    cin >> N;
    cin >> C;
    int arr[C];
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    cout << coin_change(arr, N, C);

    return 0;
}
