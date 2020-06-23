// https://www.hackerrank.com/challenges/largest-rectangle/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, max = 0;
    scanf("%d", &N);
    int h;
    char ch;
    int heights[N];
    int right[N];
    int left[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &h);
        heights[i] = h;
        scanf("%c", ch);
    }

    /*for(int i=0;i<N;i++){
        printf("%d\t",heights[i]);
    }*/

    //populate left
    left[0] = 1;
    right[N - 1] = 1;
    int k = 0;
    for (int i = 1; i < N; i++)
    {
        if (heights[i] > heights[i - 1])
        {
            left[i] = 1;
        }
        else
        {
            left[i] = left[i - 1] + 1;
            k = i - left[i - 1] - 1;
            //check number of elements greater than heights[i] in [0,k]
            while (k >= 0)
            {
                if (heights[k] < heights[i])
                    break;
                left[i]++;
                k--;
            }
        }
    }
    /*for(int i=0;i<N;i++){
        printf("%d\t",left[i]);
    }*/
    for (int i = N - 2; i >= 0; i--)
    {
        if (heights[i] > heights[i + 1])
        {
            right[i] = 1;
        }
        else
        {
            right[i] = right[i + 1] + 1;
            k = i + right[i + 1] + 1;
            //check number of elements greater than heights[i] in [0,k]
            while (k <= N - 1)
            {
                if (heights[k] < heights[i])
                    break;
                right[i]++;
                k++;
            }
        }
    }
    /*for(int i=0;i<N;i++){
        printf("%d\t",right[i]);
    }*/

    //populate right

    long long result = 1, product = 1;
    for (int i = 0; i < N; i++)
    {
        product = (long long)(heights[i] * (right[i] + left[i] - 1));
        result = result < product ? product : result;
    }
    printf("%lld", result);
    return 0;
}
