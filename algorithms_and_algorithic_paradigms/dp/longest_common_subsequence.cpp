#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int longest_common_subsequence(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (m + 1));
    }
    memset(&dp[0][0], 0, sizeof(int) * (n + 1) * (m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    int output = dp[n][m];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return output;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int result = longest_common_subsequence(s1, s2);

        cout << result << "\n";
    }

    return 0;
}
