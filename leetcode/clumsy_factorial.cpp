// https://leetcode.com/problems/clumsy-factorial/

class Solution
{
public:
    int clumsyR(int n)
    {
        if (n == 4)
            return -5;
        if (n == 3)
            return -6;
        if (n <= 2)
            return -n;
        return -((n) * (n - 1) / (n - 2)) + (n - 3) + clumsyR(n - 4);
    }
    int clumsy(int N)
    {
        if (N == 4)
            return 7;
        if (N == 3)
            return 6;
        if (N <= 2)
            return N;
        return N * (N - 1) / (N - 2) + (N - 3) + clumsyR(N - 4);
    }
};